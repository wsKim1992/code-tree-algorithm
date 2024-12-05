#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

vector<int>edge[MAX_N+1];
bool visited[MAX_N+1];
int d[MAX_N+1];
int qArr[MAX_N+1];

void DFS(int x){
    d[x]=0;
    for(int i =0;i<(int) edge[x].size();i++){
        int y = edge[x][i];
        if(visited[y])continue;
        visited[y]=true;
        DFS(y);
        d[x]=d[x]+d[y];
    }
    d[x]=d[x]+1;
}

int main() {
    int n,r,q;
    cin>>n>>r>>q;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);        
    }
    visited[r]=true;
    DFS(r);
    for(int i =0 ;i<q;i++){
        int goal;
        cin>>goal;
        cout<<d[goal]<<endl;
    }
    return 0;
}