#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
vector<pair<int,int>> edge[MAX_N+1];
bool visited[MAX_N+1];
int max_dist;
int last_node;
int a,b;
int ans;

void dfs(int idx,int ignore_idx,int accmVal){
    bool isLeaf = true;
    for(int i=0;i<edge[idx].size();i++){
        int node,w;
        tie(node,w) = edge[idx][i];
        if(visited[node])continue;
        visited[node]=true;
        dfs(node,ignore_idx,accmVal+w);
        if(isLeaf)isLeaf=false;
    }
    if(isLeaf){
        if(max_dist<accmVal&&ignore_idx!=idx){
            max_dist=accmVal;
            last_node=idx;
        }
    }
    return ;
}

int main() {
    cin>>n;

    for(int i=1;i<=n;i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        edge[x].push_back({y,dis});
        edge[y].push_back({x,dis});
    }
    visited[1]=true;
    dfs(1,-1,0);
    a=last_node;
    ans = max(ans,max_dist);
    
    max_dist=-1;
    last_node=-1;
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    visited[1]=true;
    dfs(1,a,0);
    b=last_node;
    ans = max(ans,max_dist);

    max_dist=-1;
    last_node=-1;
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    visited[b]=true;
    dfs(b,a,0);    
    ans = max(ans,max_dist);

    cout<<ans<<endl;

    return 0;
}