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

    void dfs(TreeNode* node, int* num_good, int* path_max){
        bool addValue = true;
        
        int newPathMax = *path_max;
        if(node->val >= *path_max){
            (newPathMax) = node->val;
            (*num_good)++;
        }

        if(node->right){
            dfs(node->right, num_good, &newPathMax);
        }
        if(node->left){
            dfs(node->left, num_good, &newPathMax);
        }

    }
    int goodNodes(TreeNode* root) {
        // DFS
        // but pass in the arr that of nums that came before it each time?
        // brute force approach:
        /*
        Use DFS, but pass in the array of elements that came before it
        each time, check if any of the values in the array are larger
        than the current one, if they are, then do not add to number
        of good nodes, 
        O(n) pretty much runtime
        O(n^2) memory
        */
        int num_good = 1;
        int path_max = root->val;

        if(root->left){
            dfs(root->left, &num_good, &path_max);
        } 
        if(root->right){
            dfs(root->right, &num_good, &path_max);
        }

        return num_good;
    }
};
