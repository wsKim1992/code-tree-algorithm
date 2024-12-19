#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#define MAX_N 300
using namespace std;

int n;
priority_queue<pair<int,int>>pq;
bool visited[MAX_N+1];
vector<pair<int,int>>graph[MAX_N+1];
int dist[MAX_N+1];

int main() {
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        graph[0].push_back(make_pair(w,i));
    }
    for(int i=1;i<=n;i++){
        dist[i]=(int)1e9;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            if(i!=j){
                graph[i].push_back(make_pair(w,j));
                graph[j].push_back(make_pair(w,i));
            }
        }
    }
    dist[0]=0;
    pq.push(make_pair(-0,0));
    
    while(!pq.empty()){
        int w,x;
        tie(w,x) = pq.top();
        pq.pop();
        if(visited[x])continue;
        visited[x]=true;
        ans+=(-w);
        for(int i=0;i<(int)graph[x].size();i++){
            int w1,y;
            tie(w1,y) = graph[x][i];
            if(dist[y]>w1){
                dist[y]=w1;
                pq.push(make_pair(-w1,y));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}