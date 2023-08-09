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
//classic dfs
class Solution {
public:
    bool dfs(TreeNode* root, int targetSum,int sum){
        if(!root)return false;
        sum += root->val;
        //path sum must be the whole path, if statement also checks for whether current leaf is not a parent.
        if(sum == targetSum && !root->left&&!root->right) return true;
        return dfs(root->left,targetSum,sum) || dfs(root->right,targetSum,sum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum,0);
        
    }
};
