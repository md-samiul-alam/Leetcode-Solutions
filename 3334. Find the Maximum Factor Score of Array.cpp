class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
    
        if(n==1) {
            return nums[0] * nums[0];
        }
    
        long long initialLcm = nums[0];
        long long initialGcd = nums[0];
        for (int i = 1; i < n; ++i) {
            initialLcm = lcm(initialLcm, nums[i]);
            initialGcd = gcd(initialGcd, nums[i]);
        }
        long long initialScore = initialLcm * initialGcd;
    
        long long maxScore = initialScore;
    
        // Consider removing each element
        for (int i = 0; i < n; ++i) {
            if (n == 1) return 0;
    
            long long newLcm = 1;
            long long newGcd = 0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    newLcm = lcm(newLcm, nums[j]);
                    newGcd = (newGcd == 0) ? nums[j] : gcd(newGcd, nums[j]);
                }
            }
            long long newScore = newLcm * newGcd;
    
            maxScore = max(maxScore, newScore);
        }
    
        return maxScore;
    }
};
