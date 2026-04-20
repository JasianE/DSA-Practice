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
    int max(int val1, int val2) {
        return val1 > val2 ? val1 : val2;
    }
    int maxDepth(TreeNode* root) {

        // DFS solution

        if(root == nullptr){
            return 0;
        }

        // BFS solution
        queue<TreeNode*> q;


        q.push(root);
        int level = 0;
        while(q.size() != 0){
            int currentSize = q.size();
            
            for(int i{0}; i < currentSize; i++){
                TreeNode * n = q.front();
                q.pop();
                if(n->left != nullptr){
                    q.push(n->left);
                }
                if(n->right != nullptr){
                    q.push(n->right);
                }
                
            }
            level++;
        }
        return level;
    }
};
