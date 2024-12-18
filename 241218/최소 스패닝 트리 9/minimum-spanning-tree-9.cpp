#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

#define MAX_N 100000
using namespace std;

int n,m;
priority_queue<pair<int,int>>pq;
vector<pair<int,int>>graph[MAX_N+1];
bool visited[MAX_N+1];
int dist[MAX_N+1];

int main() {
    int ans =0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(w,y));
        graph[y].push_back(make_pair(w,x));
    }
    for(int i=1;i<=n;i++){
        dist[i]=(int)1e9;
    }
    dist[1]=0;
    pq.push(make_pair(-0,1));
    while(!pq.empty()){
        int w,x;
        tie(w,x)=pq.top();
        pq.pop();
        if(visited[x])continue;
        visited[x]=true;
        w=-w;
        ans+=w;
        for(int i=0;i<(int)graph[x].size();i++){
            int y,len;
            tie(len,y)=graph[x][i];
            if(dist[y]>len){
                dist[y]=len;
                pq.push(make_pair(-len,y));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}