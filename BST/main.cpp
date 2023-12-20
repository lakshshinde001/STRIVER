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
			for(int i=1; i<n; i++){
				cout<<"Adjacent nodes of "<<i<<"->";
				for(int j=0; j<adj[i].size(); j++){
					cout<<adj[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void bfs(vector<int> adj[], int n){
			queue<int>q;
			vector<int> bfs;
			int vis[n]={0};
			vis[1] = 1;
			q.push(1);
			
			while(!q.empty()){
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				
				for(int it: adj[node]){
					if(!vis[it]){
						vis[it] = 1;
						q.push(it);
					}
				}			
			}
			for(int i=0; i<bfs.size(); i++){
				cout<<bfs[i]<<" ";
			}
		}
		void dfs(int node, vector<int> adj[], int vis[], vector<int>&ls){
			vis[node] = 1;
			ls.push_back(node);
			
			for(int it: adj[node]){
				if(!vis[it]){
					vis[it] = 1;
					dfs(it, adj, vis, ls);
				}
			}
		}
		void depthFirstSearch(vector<int> adj[], int n){
			int vis[n+1] = {0};
			int start = 1;
			vector<int> ls;
			dfs(start, adj, vis, ls);
			
			for(int i=0; i<ls.size(); i++){
				cout<<ls[i]<<" ";
			}
		}
};

int main(){
	int n = 5;
	int m = 6;
	vector<int> adj[n+1];
	graph g;
	g.addEdge(adj, 1,2);
	g.addEdge(adj, 1,3);
	g.addEdge(adj, 2,4);
	g.addEdge(adj, 3,4);
	g.addEdge(adj, 3,5);
	g.addEdge(adj, 4,5);
	g.display(adj,n);
//	g.bfs(adj,n );
	g.depthFirstSearch(adj, n);
	return 0;
}
