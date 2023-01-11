/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//BFS method: add each level into a queue, do a for loop to remove all the nodes in the queue
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> levels;
        levels.push(root);
        while(!levels.empty()){
            int size = levels.size(); // we need this to establish a fixed size for each level
            for(int i = 0;i<size;i++){
                Node* current = levels.front(); //front means front of the queue
                levels.pop();
                //reaches the end of the level
                if(i == size -1) current->next = nullptr;
                else current->next = levels.front();
                if(current->left) levels.push(current->left); // we add the node's left and right after each loop
                if(current->right) levels.push(current->right);
            }
        }
        return root;      
    }
};

//DFS solution: reach the last level and popback
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
         //connects left node to right node 
        if(root->left) root->left->next = root-> right;
        else return root;
      //connects right node to the other parent's left node
        if(root->right){
            if(root->next) root->right->next = root->next->left;
            else root->right->next = nullptr;
        }
        connect(root->left);
        connect(root->right); // need to connect right so that all right leaves are connected 
        //at the final stack, all nodes are mapped, return final root
        return root;
        
    }
};
