#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_N 10000
using namespace std;

int n;
vector<int>graph[MAX_N+1];
int inDegree[MAX_N+1];
int dist[MAX_N+1];
queue<int>q;
int num[MAX_N+1];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>num[i]>>k;
        while(k--){
            int y;
            cin>>y;
            graph[y].push_back(i);
            inDegree[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            dist[i]=num[i];
            q.push(i);
        }
    }
    int ans=0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<(int)graph[x].size();i++){
            int y = graph[x][i];
            dist[y] = max(dist[y],dist[x]+num[y]);
            inDegree[y]-=1;
            if(inDegree[y]==0){
                q.push(y);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dist[i]);
    }
    cout<<ans<<endl;
    return 0;
}