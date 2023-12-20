#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    
    for(auto it : adj[node]){
        if(!vis[it]){
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

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAdj(vector<int>adj[], int n){
    for(int i=1; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n = 8;
    int m = 8;
    vector<int> adj[n+1];

    addEdge(adj,1,2);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,3,7);
    addEdge(adj,4,8);

    printAdj(adj, n);
    depthFirstSearch(adj, n);
    // printAdj(adj,n);

    return 0;
}