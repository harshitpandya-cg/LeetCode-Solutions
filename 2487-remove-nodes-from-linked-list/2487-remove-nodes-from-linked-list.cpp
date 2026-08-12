class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        head->next = removeNodes(head->next);
        if (head->next->val > head->val) {
            return head->next;
        }
        return head;
    }
};