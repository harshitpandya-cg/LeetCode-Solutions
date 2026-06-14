class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        for(char c : s)
            cnt[c - 'a']++;
        int vowel = 0, consonant = 0;
        for(int i = 0;i<26;i++){
            char ch = 'a' + i;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u')
            vowel = max(vowel, cnt[i]);
            else
            consonant = max(consonant, cnt[i]);
        }
        return vowel + consonant;
    }
};