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

    ListNode* reverseKGroup(ListNode* head, int k) {
        int i=0;
        ListNode* temp1 = head;
        int count = 0;
        while (temp1 != nullptr && count < k) {
            temp1 = temp1->next;
            count++;
        }
        if(count<k) return head;
        if(k==1) return head;

        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* front;

        while(i<k&&temp!=nullptr){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
            i++;
        }
        if(front!=nullptr) head->next = reverseKGroup(front, k);
        return prev;
    }
};