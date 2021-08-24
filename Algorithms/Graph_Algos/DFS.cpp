// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>DFSOfGraph(int V, vector<int> adj[])
	{
	    vector<int> return_vec;
	    vector<int> color(V, 0);
	    vector<int> parent(V, -1);
		int curr_node;
		int prev_node = -1;
	    stack<int> S;
	    color[0] = 1;
	    parent[0] = -1;
	    S.push(0);
		while(!S.empty()) {
			curr_node = S.top();
			while(color[curr_node] != 1) {
				S.pop();
				curr_node = S.top();
			}
			S.pop();
			return_vec.push_back(curr_node);
			color[curr_node] = 2;
			parent[curr_node] = prev_node;
			prev_node = curr_node;
			for(int neighbour : adj[curr_node]) {
				if(color[neighbour] == 0) {
					S.push(neighbour);
					color[neighbour] = 1;
				}
			}
		}
		for(auto it : parent) cout << it << " ";
	    return return_vec;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.DFSOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends