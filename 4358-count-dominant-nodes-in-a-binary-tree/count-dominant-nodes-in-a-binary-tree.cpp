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
    int count;
    int dfs(TreeNode* root){
        if(root == NULL) return INT_MIN;

        int left=dfs(root->left);
        int right=dfs(root->right);

        if((root->val >= left) && (root->val >= right))
          count++;

        return max(left,max(right,root->val));

    }
    int countDominantNodes(TreeNode* root) {
        count=0;
        dfs(root);
        return count;
    }
};