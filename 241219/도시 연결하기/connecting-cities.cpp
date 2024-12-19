#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#define MAX_N 50
using namespace std;
int n, m;
priority_queue<pair<int,int>>pq;
vector<pair<int,int>>edges[(MAX_N+1)*(MAX_N+1)];
bool visited[(MAX_N+1)*(MAX_N+1)];
int dist[(MAX_N+1)*(MAX_N+1)];
int M[MAX_N+1][MAX_N+1];

int main() {
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>M[i][j];
        }
    }
    int startPoint =-1;
    for(int i=0;i<n;i++){
        int prev=-1;int w=0;
        for(int j =0;j<m;j++){
            if(M[i][j]==0){
                if(prev!=-1){
                    w+=1;
                }
            }else if(M[i][j]==1){
                int now = m*i+j;
                if(prev!=-1){
                    edges[prev].push_back(make_pair(w,now));
                    edges[now].push_back(make_pair(w,prev));
                }
                if(startPoint==-1){
                    startPoint=now;
                }
                prev=now;
                w=0;
            }
        }
    }
    for(int i=0;i<m;i++){
        int prev=-1;int w=-1;
        for(int j=0;j<n;j++){
            if(M[j][i]==0){
                if(prev!=-1){
                    w+=1;
                }
            }else if(M[j][i]==1){
                int now = m*j+i;
                if(prev!=-1){
                    edges[prev].push_back(make_pair(w,now));
                    edges[now].push_back(make_pair(w,prev));
                }
                if(startPoint==-1){
                    startPoint=now;
                }
                prev=now;
                w=0;
            }
        }
    }
    for(int i=0;i<(MAX_N+1)*(MAX_N+1);i++){
        dist[i]=(int)1e9;
    }
    if(startPoint!=-1){
        pq.push(make_pair(-0,startPoint));
        dist[startPoint]=0;
        while(!pq.empty()){
            int cost,x;
            tie(cost,x)=pq.top();
            pq.pop();
            if(visited[x])continue;
            visited[x]=true;
            cost=-cost;
            ans+=cost;
            for(int i=0;i<(int)edges[x].size();i++){
                int y,cost1; 
                tie(cost1,y)= edges[x][i];
                if(dist[y]>cost1){
                    dist[y]=cost1;
                    pq.push(make_pair(-cost1,y));
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}