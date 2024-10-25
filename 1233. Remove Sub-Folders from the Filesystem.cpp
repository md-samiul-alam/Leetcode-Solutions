class Solution {
public:
    bool isSubstring(string a, string b) {
        a.push_back('/');
        b.push_back('/');
        size_t index = b.find(a);
        if(index != 0) return false;
        return b.find(a) != string::npos;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1, j=0; i<folder.size(); ++i) {
            if(!isSubstring(ans[j], folder[i])) {
                ++j;
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
