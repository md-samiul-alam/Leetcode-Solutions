/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static bool cmp(long long a, long long b) {
        return a > b;
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        map<TreeNode*, int>mp;
        mp[root] = 0;
        long long maxLevel = 0;
        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            if(f->left) {
                q.push(f->left);
                mp[f->left] = mp[f] + 1;
                maxLevel = mp[f] + 1;
            }
            
            if(f->right) {
                q.push(f->right);
                mp[f->right] = mp[f] + 1;
                maxLevel = mp[f] + 1;
            }
        }
        vector<long long>levelSum(maxLevel+1, 0);
        for (const auto& [key, value]: mp) {
            levelSum[value] += key->val;
        }

        sort(levelSum.begin(), levelSum.end(), cmp);

        if(k<=maxLevel+1) {
            return levelSum[k-1];
        }
        return -1;
    }
};
