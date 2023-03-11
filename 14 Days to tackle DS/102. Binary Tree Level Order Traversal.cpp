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
//bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        queue<TreeNode*>levels;
        levels.push(root);
        vector<vector<int>> res;
        while(!levels.empty()){
            vector<int> group;
            int size = levels.size();
            for(int i = 0; i< size;++i){
                int a = levels.front()->val;
                group.push_back(a);
                if(levels.front()->left)levels.push(levels.front()->left);
                if(levels.front()->right)levels.push(levels.front()->right);
                levels.pop();
            }
            res.push_back(group);
            root = levels.front();
        }
        return res;
        
    }
};
