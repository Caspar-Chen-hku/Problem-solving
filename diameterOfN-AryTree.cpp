/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    unordered_map<Node* , vector<Node*>> adj;
    void tree2graph(Node* root) {
        if (!root) return ;
        for (auto child: root->children) {
            adj[root].push_back(child);
            adj[child].push_back(root);
            tree2graph(child);
        } 
    }
    
    int maxDepth;
    Node* endNode;
    void dfs(unordered_map<Node*, vector<Node*>>& adj, Node* root, Node* parent, int depth) {
        if (depth > maxDepth) {
            maxDepth = depth;
            endNode = root;
        }
        for (auto child: adj[root])  {
            if (child == parent) continue;
            dfs(adj, child, root, depth+1);
        }
    }
    
    int diameter(Node* root) {
        if (!root) return 0;
        tree2graph(root);
        maxDepth = -1;
        Node* parent = NULL;
        dfs(adj,root, parent,0);
        maxDepth = -1;
        dfs(adj, endNode, parent, 0);
        return maxDepth;
    }
};