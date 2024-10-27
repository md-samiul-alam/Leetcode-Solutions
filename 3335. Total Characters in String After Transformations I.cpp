class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int count[30];
        int MOD = 1000000007;
        memset(count, 0, sizeof(count));
        for(int i=0; i<s.size(); ++i) {
            ++count[s[i] - 'a'];
        }
        while(t--) {
            for(int i=26; i>0; --i) {
                count[i] = count[i-1];
            }
            count[0] = count[26];
            count[1] = (count[1] + count[26]) % MOD;
        }
        int length=0;
        for(int i=0; i<26; ++i) {
            length = (length+count[i]) % MOD;
        }
        
        return length;
    }
};
