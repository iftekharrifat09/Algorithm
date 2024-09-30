#include<bits/stdc++.h>
using namespace std;

int knapSack(int n, int weight[], int value[], int w){
    if(n<0 || w==0) return 0;
    
    if(weight[n]<=w){
        int op1 = knapSack(n-1, weight, value, w-weight[n]) + weight[n];
        int op2 = knapSack(n-1, weight, value, w);
        return max(op1, op2);
    }else{
        int op2 = knapSack(n-1, weight, value, w);
        return op2;
    }
}
int main(){

    int n;
    cin>>n;
    int weight[n], value[n];
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }
    for(int i=0; i<n; i++){
        cin>>value[i];
    }

    int W;
    cin>>W;
    cout<<knapSack(n-1, weight, value, W);
return 0;
}