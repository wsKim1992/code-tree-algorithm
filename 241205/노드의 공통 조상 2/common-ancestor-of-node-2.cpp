#include <iostream>
#include <vector>

#define MAX_N 50000
#define MAX_H 16

using namespace std;

int n,q;
vector<int> edges[MAX_N+1];
bool visited[MAX_N+1];
int depth[MAX_N+1];

int parent[MAX_H][MAX_N];

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

int LCA(int x,int y){
    if(depth[x]<depth[y]){
        return LCA(y,x);
    }
    int a=x;int b=y;
    for(int i=MAX_H;i>=0;i--){
        if(depth[a]-depth[b]>=(1<<i)){
            a=parent[i][a];
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
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    depth[1]=0;
    visited[1]=true;
    DFS(1);
    cin>>q;
    for(int i=1;i<MAX_H;i++){
        for(int j=1;j<=n;j++){
            parent[i][j]=parent[i-1][parent[i-1][j]];
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
        
    }
    return 0;
}