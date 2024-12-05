#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000

using namespace std;

int parents[MAX_N+1];
vector<int>edges[MAX_N+1];
int d[MAX_N+1];
int n;
int m;
int root=-1;
void DFS(int x){
    if(parents[x]!=-1){
        d[x]+=d[parents[x]];
    }
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        DFS(y);
    }
}

int main() {
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        cin>>parents[i];
        d[i]=0;
        if(parents[i]!=-1){
            edges[parents[i]].push_back(i);
        }
        if(parents[i]==-1){
            root=i;
        }
    }
    for(int i =0;i<m;i++){
        int c,w;
        cin>>c>>w;
        d[c]+=w;
    }
    DFS(root);
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}