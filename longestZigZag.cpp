class Solution {
public:
    int total = 0;

    void dfs(TreeNode* node, int length, int direction) {
        if (!node) return;

        total = max(total, length);

        if (direction == 0) { 
            // came from left → must go right to continue
            dfs(node->right, length + 1, 1);
            dfs(node->left, 1, 0); // restart
        } else {
            // came from right → must go left
            dfs(node->left, length + 1, 0);
            dfs(node->right, 1, 1); // restart
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;

        dfs(root->left, 1, 0);
        dfs(root->right, 1, 1);

        return total;
    }
};
