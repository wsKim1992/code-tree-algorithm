#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX_N 501

using namespace std;

int n;
vector<pair<int,int>>graph[MAX_N+1];
int dist[MAX_N+1];
bool visited[MAX_N+1];
priority_queue<tuple<int,int,int>>pq;
int M[MAX_N+1][MAX_N+1];
int main() {
    cin>>n;
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
    dist[1]=0;
    pq.push(make_tuple(-0,1,MAX_N));
    while(!pq.empty()){
        int w,x,y;
        tie(w,x,y)=pq.top();
        pq.pop();
        if(visited[x])continue;
        visited[x]=true;
        w=-w;
        if(y!=MAX_N){
            y=-y;
            if(x<=y)cout<<x<<" "<<y<<" ";
            else cout<<y<<" "<<x<<" ";
            cout<<w<<endl;
        }
        for(int i=0;i<(int)graph[x].size();i++){
            int w1,y;
            tie(w1,y)=graph[x][i];
            if(dist[y]>w1){
                dist[y]=w1;
                pq.push(make_tuple(-w1,y,-x));
            }
        }
    }
    return 0;
}