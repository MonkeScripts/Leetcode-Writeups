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
//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!(left && right)) return false;
        if(left->val != right->val) return false;
        //check left->left, right->right and left->right and right->left
        return helper(left->left,right->right) && helper(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};
