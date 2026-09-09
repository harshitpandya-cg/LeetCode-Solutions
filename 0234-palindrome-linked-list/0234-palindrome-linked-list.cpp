class Solution {
public:
    bool isPalindrome(ListNode* head) {

        vector<int> nums;

        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            if (nums[left] != nums[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};