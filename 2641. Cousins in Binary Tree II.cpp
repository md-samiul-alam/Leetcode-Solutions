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
    int levelSum[100005];

    void dfs(TreeNode* root, int lv) {
        levelSum[lv] += root->val;
        if(root->left) {
            dfs(root->left, lv + 1);
        }
        if(root->right) {
            dfs(root->right, lv + 1);
        }
    }

    

    void dfs2(TreeNode* root, int lv) {
        int leftVal = (root->left ? root->left->val : 0);
        int rightVal = (root->right ? root->right->val : 0);
        if(root->left) {
            root->left->val = levelSum[lv+1] - root->left->val - rightVal;
            dfs2(root->left, lv+1);
        }
        if(root->right) {
            root->right->val = levelSum[lv+1] - root->right->val - leftVal;
            dfs2(root->right, lv+1);
        }
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        memset(levelSum, 0, sizeof(levelSum));

        dfs(root, 0);
        
        root->val = 0;

        dfs2(root, 0);
        return root;
    }
};
