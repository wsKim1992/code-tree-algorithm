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
int dist[MAX_N+1];
int last_node;
int a,b;
int ans;

void dfs(int idx,int ignore_idx){
    for(int i=0;i<edge[idx].size();i++){
        int node,w;
        tie(node,w) = edge[idx][i];
        if(visited[node])continue;
        visited[node]=true;
        dist[node] = dist[idx]+w;
        if(dist[node]>max_dist && node!=ignore_idx){
            max_dist=dist[node];
            last_node = node;
        }
        dfs(node,ignore_idx);
    }
    return ;
}

int main() {
    cin>>n;

    for(int i=1;i<n;i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        edge[x].push_back({y,dis});
        edge[y].push_back({x,dis});
    }
    visited[1]=true;
    dfs(1,-1);
    a=last_node;
    
    max_dist=-1;
    last_node=-1;
    for(int i=1;i<=n;i++){
        visited[i]=false;
        dist[i]=0;
    }
    visited[a]=true;
    dfs(a,-1);
    b=last_node;
    ans = max(ans,max_dist);

    max_dist=-1;
    last_node=-1;
    for(int i=1;i<=n;i++){
        visited[i]=false;
        dist[i]=0;
    }
    visited[a]=true;
    dfs(a,b);    
    ans = max(ans,max_dist);

    max_dist=-1;
    last_node=-1;
    for(int i=1;i<=n;i++){
        visited[i]=false;
        dist[i]=0;
    }
    visited[b]=true;
    dfs(b,a);    
    ans = max(ans,max_dist);

    cout<<ans<<endl;

    return 0;
}