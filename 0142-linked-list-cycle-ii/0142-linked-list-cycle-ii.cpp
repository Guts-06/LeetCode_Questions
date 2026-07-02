class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        // Phase 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {  // cycle found
                
                // Phase 2: find cycle entry
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;  // cycle start node
            }
        }

        return nullptr; // no cycle
    }
};
