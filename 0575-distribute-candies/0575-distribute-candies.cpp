class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());
        int differentTypes = st.size();
        int canEat = candyType.size() / 2;
        return min(differentTypes, canEat);
    }
};