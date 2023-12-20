#include<bits/stdc++.h>
using namespace std;

void explainPair(){
    //simple pair
    pair<int, int> p;
    p.first = 2;
    p.second = 5;
    cout<<p.first<<" "<<p.second<<endl;

    // nested pair
    pair<int, pair<int,int>> p1 = {2,{2,3}};

    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second;

    // array of pair

    pair<int,int> arr[] = {{1,2}, {2,3}, {4,5}};

    cout<<arr[0].second<<endl;
    cout<<arr[0].first<<endl;
    cout<<arr[2].first<<endl;
    cout<<arr[1].first<<endl;

    for(int i=0; i<3; i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }  
}

void explainVector(){
    vector<int>v1;

    v1.push_back(1);
    v1.emplace_back(2);
    v1.emplace_back(3);
    
    vector<pair<int,int>> pairr;
    pairr.push_back({2,1});
    pairr.emplace_back(4,2);
    pairr.emplace_back(6,3);
    pairr.emplace_back(8,4);

    for(int i=0; i<pairr.size(); i++){
        cout<<pairr[i].first<<" "<<pairr[i].second<<endl;
    }

    vector<int> v4(15,100);
    vector<int> v5(v4);     //copy of v4

    for(int i=0; i<v5.size(); i++){
        cout<<v5[i]<<" ";
    }

    vector<int> v6 = {1,2,3,4,5};
    // cout<<v6.at(4);

    vector<int> :: iterator it = v6.begin();
    cout<<*it;
    it += 1;
    cout<<*it;
    it += 2;
    cout<<*it;

    
    
}

int main()
{
    explainVector();
    return 0;
}