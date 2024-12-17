#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <limits.h>
#define MAX_N 100000
using namespace std;

int n,m;
int a,b;
vector<tuple<long,int,int>>edges;
vector<pair<int,long>>newEdges[MAX_N+1];
int uf[MAX_N+1];

int find(int x){
    if(x==uf[x])return x;
    return uf[x]=find(uf[x]);
}

void Union(int x,int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[rootX]=rootY;
}
bool cmp(tuple<long,int,int> a, tuple<long,int,int> b){
    return get<0>(a)>get<0>(b);
}

bool visited[MAX_N+1];

long ans=INT_MAX;

void DFS(int x,int goal,long minVal){
    if(x==goal){ans = min(ans,minVal);return ;}

    for(int i=0;i<newEdges[x].size();i++){
        long cost;int y;
        tie(y,cost)=newEdges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        DFS(y,goal,min(minVal,cost));
    }
}

int main() {
    cin>>n>>m;
    cin>>a>>b;
    for(int i=1;i<=n;i++){
        uf[i]=i;
    }
    for(int i=0;i<m;i++){
        long cost;int x,y;
        cin>>x>>y>>cost;
        edges.push_back(make_tuple(cost,x,y));
    }
    sort(edges.begin(),edges.end(),cmp);
    for(int i=0;i<(int)edges.size();i++){
        long cost;int x,y;
        tie(cost,x,y)=edges[i];
        if(find(x)!=find(y)){
            Union(x,y);
            newEdges[x].push_back(make_pair(y,cost));
            newEdges[y].push_back(make_pair(x,cost));
        }
    }
    visited[b]=true;
    DFS(b,a,INT_MAX);
    cout<<ans<<endl;
    return 0;
}