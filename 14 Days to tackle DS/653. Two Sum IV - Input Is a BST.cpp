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
//add the target - node values to an unordered set
//traverse through the to find the pair
class Solution {
public:
    unordered_set<int> hash;
    bool findTarget(TreeNode* root, int k) {
        //base case
        if(!root) return false;
        if(hash.find(root->val)!=hash.end())return true;
        // recursive case
        hash.insert(k - root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
