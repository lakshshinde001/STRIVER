#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph{
	public : 
		void addEdge(vector<int> adj[], int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		void display(vector<int> adj[], int n){
			for(int i=1; i<=n; i++){
				cout<<i<<" : ";
				for(int j=0; j<adj[i].size(); j++){
					cout<<adj[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void BFS(vector<int> adj[], int n){
			int vis[n] = {0};
			vis[1] = 1;
			queue<int> bfs;
			bfs.push(1);
			vector<int> ans;
			
			while(!bfs.empty()){
				int node = bfs.front();
				bfs.pop();
				ans.push_back(node);
				for( auto it : adj[node]){
					if(!vis[it]){
						vis[it] = 1;
						bfs.push(it);
					}
				}
			}
			for(int i=0; i<ans.size(); i++){
				cout<<ans[i]<<" ";
			}
		}
};

int main(){
	int n = 5; 
	int m = 7;
	
	vector<int> adj[n+1];
	graph g;
	g.addEdge(adj, 1,2);
	g.addEdge(adj, 1,3);
	g.addEdge(adj, 2,4);
	g.addEdge(adj, 2,3);
	g.addEdge(adj, 3,5);
	g.addEdge(adj, 2,5);
	g.addEdge(adj, 4,5);
	
	g.display(adj, n);
	g.BFS(adj,n);
	
	
	return 0;
}