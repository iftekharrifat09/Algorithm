#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v[1005];
int dis[1005];
void dijkastra(int src){
    queue<pair<int,int>> q;
    q.push({src, 0});
    dis[src] = 0; 

    while(!q.empty()){
        pair<int,int> parent = q.front();
        q.pop();
        int parentNode = parent.first;
        int parentCost = parent.second;
        for(pair<int,int> child: v[parentNode]){
            int childNode = child.first;
            int childCost = child.second;
            if(parentCost + childCost < dis[childNode]){
                dis[childNode] = parentCost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}
int main(){

    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;
    }

    dijkastra(0);

    for(int i=0; i<n; i++){
        cout<<dis[i]<<endl;
    }

return 0;
}