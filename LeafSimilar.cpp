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

 // O(n) runtime, no nested loops
 // O(n) space, were creating new arrays each time
class Solution {
public:
    void dfs(TreeNode* root, vector<int>* array){
        if(root->left != nullptr ){
            dfs(root->left, array);
        } 
        if(root->right != nullptr){
            dfs(root->right, array);
        }
        if(root->left == nullptr && root->right == nullptr){
            array->push_back(root->val);
        }
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Leafs;
        vector<int> root2Leafs;

        dfs(root1, &root1Leafs);
        dfs(root2, &root2Leafs);
        
        if(root1Leafs.size() != root2Leafs.size()){
            return false; 
        }
        for(int i{0}; i < root1Leafs.size(); i++){
            if(root1Leafs[i] != root2Leafs[i]){
                return false;
            }
        }
        return true;
    }
};
