#include<iostream>
#include<vector>
using namespace std;

class disjointSet{

    vector<int>rank, parent;

    public : 
        disjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i=1; i<=n; i++){
                parent[i] = i;
            }
        }

        int findPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);

            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

int main()
{
    int V = 5;
    disjointSet D(V);

    D.unionByRank(1,2);
    D.unionByRank(2,3);
    D.unionByRank(4,5);
    D.unionByRank(6,7);
    D.unionByRank(5,6);

    if(D.findPar(1) ==  D.findPar(7)){
        cout<<"\nSame ";
    }else{
        cout<<"\nNot Same";
    }


    return 0;
}