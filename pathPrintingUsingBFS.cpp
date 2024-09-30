#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int lvl[1005];
int parent[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    lvl[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int child: v[par]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                lvl[child] = lvl[par]+1;
                parent[child] = par;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(lvl, -1, sizeof(lvl));
    memset(parent, -1, sizeof(parent));

    int src, des;
    cout<<"Enter Source and Destination: ";  
    cin>>src>>des;
    bfs(src);

    vector<int> path;
    int x = des;
    while(x != -1){
        path.push_back(x); 
        x = parent[x];
    }

    reverse(path.begin(), path.end());
    for(int i: path){
        cout<<i<<" ";
    }

return 0;
}