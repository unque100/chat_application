#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,q;
    cin>>n>>q;

    vector<vector<int>> Adj(n+1);
    
    int i=1,V,U;
    while(i<=n){
        cin>>V>>U;
        Adj[U].push_back(V);
        Adj[V].push_back(U);
        i++;
    }

    vector<int> high(q);
    
    for(auto &c:high) cin>>c;

    vector<int> parent(n+1, -1);
    queue<int>qq;
    qq.push(1);

    int res = 1;
   
    while(!qq.empty()){
        int size = qq.size();
        q -= size;

        if(q >= 0){
            res += size;

            for(int i=0; i<size; i++){
                int u = qq.front();
                qq.pop();

                for(auto v : Adj[u]){
                    if(v!=parent[u]){
                        qq.push(v);
                        parent[v] = u;
                    }
                }
            }
            continue;
        }
        break;
    }

    cout<<res-1;
    }
    return 0;
}