#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>
#define MAX_N 200000

using namespace std;

long ans=0;
vector<pair<long,int>>graph[MAX_N+1];
int dist[MAX_N+1];
bool visited[MAX_N+1];
map<pair<int,int>,bool>occupied;
priority_queue<pair<long,int>>pq;
int n,m,k;

int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        long w;
        cin>>w;
        graph[0].push_back(make_pair(w,i));
        dist[i]=(int)1e9;
    }
    dist[0]=(int)1e9;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(make_pair((long)1e9,y));
        graph[y].push_back(make_pair((long)1e9,x));
        occupied[{x,y}]=true;
        occupied[{y,x}]=true;
    }

    for(int i=1;i<=n;i++){
        if(i+1<=n){
            if(occupied[{i,i+1}]&&occupied[{i+1,i}])continue;
            graph[i].push_back(make_pair(0,i+1));
            graph[i+1].push_back(make_pair(0,i));
        }else{
            if(occupied[{i,1}]&&occupied[{1,i}])continue;
            graph[i].push_back(make_pair(0,1));
            graph[1].push_back(make_pair(0,i));
        }
    }
    dist[0]=0;
    pq.push(make_pair(-0,0));
    while(!pq.empty()){
        long w;int x;
        tie(w,x)=pq.top();
        pq.pop();
        if(visited[x])continue;
        visited[x]=true;
        w=-w;
        ans+=w;
        for(int i=0;i<(int)graph[x].size();i++){
            int y;long cost;
            tie(cost,y) = graph[x][i];
            if(dist[y]>cost){
                dist[y]=cost;
                pq.push(make_pair(-cost,y));
            }
        }
    }
    if(k>=ans)cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}