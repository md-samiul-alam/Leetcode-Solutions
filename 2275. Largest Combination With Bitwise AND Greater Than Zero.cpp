class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int maxCount = 0;
        for(int i=0; i<24; ++i) {
            int bitM = 1 << i;
            int tempCount = 0;
            for(int j=0; j<n; ++j) {
                if(candidates[j] & bitM) {
                    ++tempCount;
                }
            }
            maxCount = max(maxCount, tempCount);
        }
        return maxCount;
    }
};
