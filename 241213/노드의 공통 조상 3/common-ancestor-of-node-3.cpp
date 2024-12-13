#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 50000
#define MAX_H 16

using namespace std;

int parents[MAX_H+1][MAX_N+1];
bool visited[MAX_N+1];
int depth[MAX_N+1];
vector<int>edges[MAX_N+1];
int n,q;

void dfs(int x){
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        depth[y]=depth[x]+1;
        parents[0][y]=x;
        dfs(y);
    }
}

int LCA(int x,int y){
    if(depth[x]>depth[y]){
        return LCA(y,x);
    }
    for(int h=MAX_H;h>=0;h--){
        if(depth[y]-depth[x]>=(1<<h)){
            y=parents[h][y];
        }
    }
    if(x==y)return x;
    if(parents[0][x]!=parents[0][y]){
        for(int h=MAX_H;h>=0;h--){
            if(parents[h][x]!=parents[h][y]){
                x=parents[h][x];
                y=parents[h][y];
            }
        }
    }
    
    return parents[0][x];
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
    dfs(1);
    for(int h=1;h<=MAX_H;h++){
        for(int i=1;i<=MAX_N;i++){
            parents[h][i]=parents[h-1][parents[h-1][i]];
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y,z;
        cin>>x>>y>>z;
        int firstLCA=LCA(x,y);
        int ans = LCA(firstLCA,z);
        cout<<ans<<endl;
    }

    return 0;
}