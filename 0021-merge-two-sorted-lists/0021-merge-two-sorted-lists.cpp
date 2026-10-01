class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* k;
        ListNode* selected;
        ListNode* unselected;

        if (list1->val <= list2->val) {
            k = list1->next;
            selected = list1;
            unselected = list2;
        }
        else {
            k = list2->next;
            selected = list2;
            unselected = list1;
        }

        ListNode* head = selected;

        while (k != NULL && unselected != NULL) {
            
            if (k->val <= unselected->val) {
                selected->next = k;
                k = k->next;
            }
            else {
                selected->next = unselected;
                unselected = unselected->next;
            }

            selected = selected->next;
        }

        if (k != NULL)
            selected->next = k;
        else
            selected->next = unselected;

        return head;
    }
};