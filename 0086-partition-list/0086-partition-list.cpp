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
    ListNode* partition(ListNode* head, int x) {
        ListNode*temp=head;
        ListNode *lesshead=new ListNode();
        ListNode *greathead=new ListNode();

        ListNode * less=lesshead;
        ListNode * great=greathead;

        while(temp!=NULL){
            if(temp->val < x){
                less->next=temp;
                less=less->next;
            }
            else{
                great->next=temp;
                great=great->next;
            }
            temp=temp->next;
        }

        less->next=greathead->next;
        great->next=nullptr;

        return lesshead->next;
    }
};