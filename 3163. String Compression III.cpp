class Solution {
public:
    string compressedString(string word) {
        int charCount[26];
        memset(charCount, 0, sizeof(charCount));

        string ans;
        for(int i=0; i<word.size(); ++i) {
            char alpha = word[i];
            int count = 0;
            for(int j=i; j<word.size(); ++j) {
                if(alpha == word[j]) {
                    i = j;
                    ++count;
                }
                else {
                    break;
                }

                if(count == 9) {
                    break;
                }
            }
            ans.push_back(count + '0');
            ans.push_back(alpha);
        }
        return ans;
    }
};
