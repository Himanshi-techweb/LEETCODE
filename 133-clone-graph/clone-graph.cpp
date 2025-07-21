/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> check;
    void dfs(Node* node,Node* clone_node){
        if(node==NULL)return;
        for(auto it:node->neighbors){
            if(check.find(it)==check.end()){
                Node* clone=new Node(it->val);
                check[it]=clone;
                (clone_node->neighbors).push_back(clone);
                dfs(it,clone);
            }
            else{
                (clone_node->neighbors).push_back(check[it]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        check.clear();
        Node* clone_node=new Node(node->val);
        check[node]=clone_node;
        dfs(node,clone_node);
        return clone_node;
    }
};