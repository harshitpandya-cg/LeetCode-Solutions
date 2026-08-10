class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* greater = new ListNode(0);

        ListNode* p1 = less;
        ListNode* p2 = greater;

        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }

            head = head->next;
        }

        p2->next = nullptr;
        p1->next = greater->next;

        return less->next;
    }
};