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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return nullptr;
        ListNode*temp=head;
        int total=0;
        while(temp!=nullptr){
            total++;
            temp=temp->next;
        }
        if(n==total){
            ListNode*temp3=head;
            head=head->next;
            delete temp3;
            return head;

        }
        ListNode*temp2=head;
        ListNode*prev=nullptr;
        int cnt=0;
        while(temp2!=nullptr){
            cnt++;
            if(cnt==(total-n+1)){
                prev->next=prev->next->next;
                delete temp2;
                break;
            }
            prev=temp2;
            temp2=temp2->next;
        }
        return head;
    }
};