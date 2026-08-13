class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> arr;

        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(arr.size(), 0);
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            while (!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};