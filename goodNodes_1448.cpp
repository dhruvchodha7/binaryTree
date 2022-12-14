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
    int goodNodes(TreeNode* root, int max = INT_MIN) {
        if(root==NULL) return 0;
        int count = 0;
        
        if(root->val >= max){
            count++;
            max = root->val;
        }
        
        count += goodNodes(root->left, max);
        count += goodNodes(root->right, max);
        
        return count;
        
    }
};