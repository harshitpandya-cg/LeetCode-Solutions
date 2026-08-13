class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while (head!=nullptr) {
            ListNode* temp = head->next;
            int greater = 0;
            while(temp != nullptr){
                if (temp->val > head->val){
                    greater = temp->val;
                    break;
                }
                temp = temp->next;
            }
            ans.push_back(greater);
            head = head->next;
        }
        return ans;
    }
};