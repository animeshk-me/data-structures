// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> return_vec;
	    vector<int> color(V, 0);
	    vector<int> dist(V, (int)INFINITY);
	    vector<int> parent(V, -1);
	    queue<int> Q;
	    color[0] = 1;
	    dist[0] = 0;
	    parent[0] = -1;
	    Q.push(0);
	    while(!Q.empty()) {
	        int curr_node = Q.front();
	        Q.pop();
	        color[curr_node] = 2;
	        return_vec.push_back(curr_node);
	        for(int neighbour : adj[curr_node]) {
	            if(color[neighbour] == 0) {
	                Q.push(neighbour);
	                color[neighbour] = 1;
	                parent[neighbour] = curr_node;
	                dist[neighbour] = dist[parent[neighbour]] + 1;
	            }
	        }
	    }
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
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends