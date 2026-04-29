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

    void dfs(TreeNode* node, int* num_good, vector<int> seen){
        bool addValue = true;
        vector<int> newSeen;
        for(int i{0}; i < seen.size(); i++){
            newSeen.push_back(seen[i]);
            if(seen[i] > node->val){
                addValue = false;
            }
        }
        newSeen.push_back(node->val);

        if(addValue){
            (*num_good)++;

        }

        if(node->right){
            dfs(node->right, num_good, newSeen);
        }
        if(node->left){
            dfs(node->left, num_good, newSeen);
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
        O(n^2) pretty much runtime
        O(n^2) memory
        */
        int num_good = 1;
        vector<int> seen;
        seen.push_back(root->val);
        if(root->left){
            dfs(root->left, &num_good, seen);
        } 
        if(root->right){
            dfs(root->right, &num_good, seen);
        }

        return num_good;
    }
};
