#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
	public : 
		void addEdge(vector<int> adj[], int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		void display(vector<int> adj[], int n){
			for(int i=0; i<=n; i++){
				for(int j=0; j<adj[i].size(); j++){
					cout<<adj[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void bfs(vector<int> adj[], int n){
			vector<int>bfs;
			int vis[n+1] = {0};
			vis[1] = 1;
			queue<int>Q;
			Q.push(1);
			
			while(!Q.empty()){
				int node = Q.front();
				Q.pop();
				bfs.push_back(node);
				
				for(int it=0; it<adj[node].size(); it++){
					if(!vis[it]){
						vis[it] = 1;
						Q.push(it);
					}
				}
			}
			for(int i=0; i<bfs.size(); i++){
				cout<<bfs[i]<<" ";
			}
		}
		
};

int main(){
	int n,m;
	cin>>n>>m;
	Solution s;
	vector<int> adj[n+1];
	s.addEdge(adj,1,2);
	s.addEdge(adj,1,3);
	s.addEdge(adj,2,6);
	s.addEdge(adj,2,7);
	s.addEdge(adj,7,8);
	s.addEdge(adj,8,9);
	s.addEdge(adj,9,4);
	s.addEdge(adj,4,3);
	s.addEdge(adj,3,5);
	
//	s.display(adj, n);
	
	s.bfs(adj, n);
	
	
	return 0;
}
