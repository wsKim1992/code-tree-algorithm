#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 30000

using namespace std;

vector<int>edges[MAX_N+1];
bool visited[MAX_N+1];
int dist[2][MAX_N+1];
int n;
int num[MAX_N+1];
int ans = 0;
void DFS(int x){
    dist[0][x]=0;
    dist[1][x]=num[x];
    int biggestBranch=0;
    int restBranch=0;
    int localMaxVal = -1001;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        DFS(y);
        dist[0][x]=max(dist[0][y],dist[1][y]);
        if(biggestBranch<dist[1][y]){
            restBranch=biggestBranch;
            biggestBranch=dist[1][y];
        }else{
            restBranch=dist[1][y];
        }
    }
    dist[1][x]+=biggestBranch;
    localMaxVal=max(dist[1][x],dist[0][x]);
    localMaxVal=max(localMaxVal,restBranch+dist[1][x]);
    ans=max(localMaxVal,ans);
}

int main() {
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    visited[1]=true;
    DFS(1);
    cout<<ans<<endl;
    return 0;
}