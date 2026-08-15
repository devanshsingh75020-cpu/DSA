class Solution {
public:
    void makeGraph(TreeNode* root,unordered_map<TreeNode*, vector<TreeNode*>>& adj,TreeNode*& startNode,int start) {

        if (root == NULL) return;

        if (root->val == start)
            startNode = root;

        // Left child
        if (root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);

            makeGraph(root->left, adj, startNode, start);
        }

        // Right child
        if (root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);

            makeGraph(root->right, adj, startNode, start);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        TreeNode* startNode = NULL;

        // Convert tree → undirected graph
        makeGraph(root, adj, startNode, start);

        // BFS from start
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(startNode);
        visited.insert(startNode);

        int time = -1;

        while (!q.empty()) {
            int sz = q.size();
            time++;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                for (TreeNode* neighbor : adj[node]) {

                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }
        return time;
    }
};