/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> address;
        ListNode* i = head;
        while (i != NULL) {
            if (address.count(i)) {
                return true;
            }
            address.insert(i);
            i = i->next;
        }
        return false;
    }
};