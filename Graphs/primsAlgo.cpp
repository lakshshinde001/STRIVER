#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void printAdj(vector<pair<int, int>> adj[], int n) {
        for (int i = 0; i < n-1; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << "(" << adj[i][j].first << "," << adj[i][j].second << ") ";
            }
            cout << endl;
        }
    }

    int spanningTree(int n, vector<pair<int, int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int> vis(n,0);
        pq.push({0,0});
        int sum = 0; 

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if(vis[node] == 1) continue;

            vis[node] = 1;
            sum += wt;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edw = it.second;
                if(!vis[adjNode]){
                    pq.push({edw, adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {
    int n = 5;
    vector<pair<int, int>> adj[n+1];
    Solution solution;
    solution.addEdge(adj, 0, 1, 2);
    solution.addEdge(adj, 0, 3, 6);
    solution.addEdge(adj, 3, 1, 8);
    solution.addEdge(adj, 1, 2, 3);
    solution.addEdge(adj, 1, 4, 5);
    solution.addEdge(adj, 4, 2, 7);

    solution.printAdj(adj, n + 1);

   int sum =  solution.spanningTree(n, adj);
   cout<<"\nSum : "<<sum;

    return 0;
}
