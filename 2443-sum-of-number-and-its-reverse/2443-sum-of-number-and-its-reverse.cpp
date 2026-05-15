class Solution {
public:
    int reverseNum(int n){
        int rev = 0;
        while(n>0){
            int digit = n%10;
            rev = rev*10 + digit;
            n /= 10;
        }
        return rev;
    }
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++) {
            if (i + reverseNum(i) == num) {
                return true;
            }
        }
        return false;
    }
};