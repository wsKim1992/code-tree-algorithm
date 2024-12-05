#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000
#define MAX_H 17

using namespace std;

int n,q;
vector<int>edges[MAX_N+1];
bool visited[MAX_N+1];
int parent[MAX_H][MAX_N+1];
int depth[MAX_N+1];

void DFS(int x){
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        depth[y]=depth[x]+1;
        parent[0][y]=x;
        DFS(y);
    }
}

int LCA(int a,int b){
    if(depth[a]>depth[b])return LCA(b,a);
    for(int h = MAX_H;h>=0;h--){
        if(depth[b]-depth[a]>=(1<<h)){
            b=parent[h][b];
        }
    }
    if(a==b)return a;
    for(int h=MAX_H;h>=0;h--){
        if(parent[h][a]!=parent[h][b]){
            a=parent[h][a];
            b=parent[h][b];
        }
    }
    return parent[0][a];
}

int main() {
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    visited[1]=true;
    depth[1]=0;
    DFS(1);
    for(int h =1;h<=MAX_H;h++){
        for(int i=1;i<=n;i++){
            parent[h][i]=parent[h-1][parent[h-1][i]];
        }
    }

    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    return 0;
}