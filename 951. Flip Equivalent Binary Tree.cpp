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
    bool ans=true;
    bool nodeEq(TreeNode* root1, TreeNode* root2) {
        if((root1 == NULL) && (root2 == NULL)) {
            return true;
        }
        else if((root1 == NULL) && (root2 != NULL)) {
            return false;
        }
        else if((root1 != NULL) && (root2 == NULL)) {
            return false;
        }
        else if((root1 != NULL) && (root2 != NULL)) {
            return (root1->val == root2->val);
        }
        return false;
    }

    void dfs(TreeNode* root1, TreeNode* root2) {
        if(!nodeEq(root1, root2)) {
            ans = false;
            return;
        }
        if((root1 == NULL) && (root2 == NULL)) {
            return;
        }
        if((root1 == NULL) && (root2 != NULL)) {
            ans = false;
            return;
        }
        if((root1 == NULL) && (root2 != NULL)) {
            ans = false;
            return;
        }
        else if((root1 != NULL) && (root2 == NULL)) {
            ans = false;
            return;
        }

        if(nodeEq(root1->left, root2->left) && nodeEq(root1->right, root2->right)){
            dfs(root1->left, root2->left);
            dfs(root1->right, root2->right);
        }
        else if(nodeEq(root1->left, root2->right) && nodeEq(root1->right, root2->left)) {
            dfs(root1->left, root2->right);
            dfs(root1->right, root2->left);
        }
        else {
            ans = false;
            return;
        }
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        dfs(root1, root2);
        return ans;
    }
};
