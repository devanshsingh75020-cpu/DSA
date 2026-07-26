class Solution {
public:

    int ans;

    pair<int,int> find(TreeNode* root) {

        if(root == NULL) {
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            return {0,1};
        }

        pair<int,int> left = find(root->left);

        pair<int,int> right = find(root->right);

        // if any child needs camera
        if(left.second || right.second) {

            ans++;

            // {hasCamera, needsCamera}
            return {1,0};
        }

        // if any child has camera
        else if(left.first == 1 || right.first == 1) {

            return {0,0};
        }

        // leaf node -> needs camera
        return {0,1};
    }

    int minCameraCover(TreeNode* root) {

        ans = 0;

        pair<int,int> res = find(root);

        // root still needs camera
        if(res.second) {
            ans++;
        }

        return ans;
    }
};