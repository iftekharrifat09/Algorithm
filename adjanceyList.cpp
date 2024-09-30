#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int j=0; j<n; j++){
        for(int i:adj[j]){
            cout<<i<<" ";
        }
        cout<<endl;
    }

return 0;
}