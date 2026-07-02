/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* front ;
        while(temp!=nullptr){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* CopyLL(ListNode* head){
        ListNode* head1 = new ListNode(head->val);
        ListNode* temp=head1;
        ListNode* temp1=head->next;
        while(temp1!=nullptr){
            temp->next= new ListNode(temp1->val);
            temp1=temp1->next;
            temp=temp->next;
        }
        return head1;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* copy=CopyLL(head);
        ListNode* reverseHead=Reverse(copy);
        ListNode* temp1 = head;
        ListNode* temp2 = reverseHead;

        while(temp1 != nullptr){
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};