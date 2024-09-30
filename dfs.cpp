#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];

void dfs(int src){
    vis[src] = true;
    cout<<src<<endl;

    for(int child: v[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
int main(){

    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int src;
    cin>>src;
    dfs(src);

return 0;
}