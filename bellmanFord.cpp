#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src, dest, weight;
    Edge(int src, int dest, int weight){
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

int dis[1005];
int main(){

    int n,e;
    cin>>n>>e;
    vector<Edge> edgeList;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        edgeList.push_back(Edge(a,b,c));
    }

    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;
    }

    for(int i=0; i<=n-1; i++){
        
        for(Edge ed: edgeList){
        if(dis[ed.src]< INT_MAX && dis[ed.src]+dis[ed.weight]<dis[ed.dest]){
            dis[ed.dest] = dis[ed.src]+ed.weight;
        }
    }
    }

return 0;
}