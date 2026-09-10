class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* left_prev = dummy;
        ListNode* curr = head;
        
        // 1. Advance to the start of the reversal zone
        int count = 1;
        while (count < left) {
            left_prev = curr;
            curr = curr->next;
            count++;
        }

        // 2. Standard iterative reversal using a while loop
        ListNode* prev = nullptr;
        ListNode* next_node = nullptr;
        
        while (count <= right) {
            next_node = curr->next;
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev forward
            curr = next_node;  // Move curr forward
            count++;
        }

        // 3. Reconnect the reversed sub-list back into the main list
        left_prev->next->next = curr; // Connect the new tail to the rest of the list
        left_prev->next = prev;       // Connect the outer left part to the new head

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};