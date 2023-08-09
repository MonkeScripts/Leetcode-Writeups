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
    //inorder traversal + hash the node values and then run a linear check on them
    vector<int>result;
    void inorder(TreeNode*root){
        if(!root) return;
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i = 0; i<result.size()-1;++i){
            int j = i +1;
            if(result[i] >= result[j]) return false;
        }
        return true;
    }
};
