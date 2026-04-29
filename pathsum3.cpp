class Solution {
public:
    int dfs(TreeNode* root, long currSum, int targetSum, unordered_map<long, int>& prefix) {
        if (!root) return 0;

        currSum += root->val;

        int count = prefix[currSum - targetSum];

        prefix[currSum]++;

        count += dfs(root->left, currSum, targetSum, prefix);
        count += dfs(root->right, currSum, targetSum, prefix);

        prefix[currSum]--; 

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefix;
        prefix[0] = 1; 

        return dfs(root, 0, targetSum, prefix);
    }
};
