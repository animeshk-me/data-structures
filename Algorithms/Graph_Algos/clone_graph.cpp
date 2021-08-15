/*
LINK: https://leetcode.com/problems/clone-graph/submissions/

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

*/


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
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        Node* return_node = new Node(node->val, {});
        queue<Node*> Q;
        unordered_map<Node*, Node*> copy_nodes;
        set<int> visited;
        set<int> started;
        Q.push(node);
        copy_nodes.insert({node, return_node});
        started.insert(node->val);
        while(!(Q.empty())) {
            Node* temp_node = Q.front();
            Node* copy_node = copy_nodes[temp_node];
            Q.pop();
            visited.insert(temp_node->val);
            for(Node* neighbor : temp_node->neighbors) {
                int val = neighbor->val;
                if(copy_nodes.count(neighbor) == 0)    
                    copy_nodes[neighbor] = new Node(val, {});
                Node* clone_neigh_node = copy_nodes[neighbor];
                if(find(copy_node->neighbors.begin(), copy_node->neighbors.end(), clone_neigh_node) == copy_node->neighbors.end()){
                    copy_node->neighbors.push_back(clone_neigh_node);
                    clone_neigh_node->neighbors.push_back(copy_node);
                }
                if(visited.count(val) + started.count(val) == 0) {
                    Q.push(neighbor);
                    started.insert(val);
                }
            }
        }
        return return_node;        
    }
};