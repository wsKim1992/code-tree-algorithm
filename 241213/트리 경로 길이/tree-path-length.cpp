#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000
#define MAX_H 16
using namespace std;

vector<int>edges[MAX_N+1];
bool visited[MAX_N+1];
int depth[MAX_N+1];
int parent[MAX_H+1][MAX_N+1];
int n,q;

void DFS(int x){
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        parent[0][y]=x;
        depth[y]=depth[x]+1;
        DFS(y);
    }
}

int LCA(int x, int y){
    int ans=0;
    if(depth[x]>depth[y]){
        return LCA(y,x);
    }
    for(int h=MAX_H;h>=0;h--){
        if(depth[y]-depth[x]>=(1<<h)){
            y=parent[h][y];
            ans+=(1<<h);
        }
    }
    if(x==y)return ans+1;
    for(int h=MAX_H;h>=0;h--){
        if(parent[h][x]!=parent[h][y]){
            x=parent[h][x];
            y=parent[h][y];
            ans+=2*(1<<h);
        }
    }

    return ans+3;
}

int main() {
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    visited[1]=true;
    depth[1]=0;
    parent[0][1]=0;
    DFS(1);
    for(int h=1;h<=MAX_H;h++){
        for(int i=1;i<=n;i++){
            parent[h][i]=parent[h-1][parent[h-1][i]];
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        int ans = LCA(x,y);
        cout<<ans<<endl;
    }
    return 0;
}