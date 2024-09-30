#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int lvl[1005];
bool vis[1005];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    lvl[src] = 0;
    while(!q.empty()){
        int par = q.front();
        cout<<par<<" "<<endl;
        q.pop();
        for(int child: adj[par]){
            if(!vis[child]){
                vis[child] = true;
                q.push(child);
                lvl[child] = lvl[par]+1;
            }
        }
    }
}
int main(){

    int n,e;
    cout<<"Enter Node and Edge: ";
    cin>>n>>e;
    
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(lvl, -1, sizeof(lvl));
    int src;
    cout<<"Enter Source: ";
    cin>>src;
    bfs(src);


    for(int i=0; i<n; i++){
        cout<<i<<" "<<lvl[i]<<endl;
    }

return 0;
}