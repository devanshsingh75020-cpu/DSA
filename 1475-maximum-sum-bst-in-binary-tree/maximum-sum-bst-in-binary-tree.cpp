  class Solution {
public:
    int maxSum = 0;

    vector<int> solve(TreeNode* root) {
        // {min, max, sum, isBST}

        if(root == NULL) {
            return {INT_MAX, INT_MIN, 0, 1};
        }

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        // Check BST condition
        if(left[3] == 1 && right[3] == 1 &&
           root->val > left[1] && root->val < right[0]) {

            int currSum = left[2] + right[2] + root->val;

            maxSum = max(maxSum, currSum);

            vector<int> res(4);
            res[0] = min(root->val, left[0]);   // min
            res[1] = max(root->val, right[1]);  // max
            res[2] = currSum;                   // sum
            res[3] = 1;                         // isBST

            return res;
        }

        // Not a BST
        return {INT_MIN, INT_MAX, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};