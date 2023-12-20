#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void bfs(vector<int> adj[], int n){
    vector<int> bfs;
    int vis[n+1] = {0};
    vis[6] = 1;
    queue<int> Q;
    Q.push(6);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        bfs.emplace_back(node);

        for(auto it : adj[node]){
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
    cout<<"Enter vertices and edges : ";
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];
    addEdge(adj, 1,2);
    addEdge(adj, 1,6);
    addEdge(adj, 2,3);
    addEdge(adj, 2,4);
    addEdge(adj, 4,5);
    addEdge(adj, 5,8);
    addEdge(adj, 8,7);
    addEdge(adj, 7,6);
    addEdge(adj, 6,9);
    addEdge(adj, 2,1);
    // printAdj(adj, n);

    bfs(adj, n);
    

    return 0;
}