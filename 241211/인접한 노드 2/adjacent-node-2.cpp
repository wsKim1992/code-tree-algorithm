#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 10000
using namespace std;

vector<int>edges[MAX_N+1];
bool visited[MAX_N+1];
vector<int>q1;
vector<int>q2;

int n;
int num[MAX_N+1];
int dist[2][MAX_N+1];

void DFS(int x,bool flag){
    dist[0][x]=0;
    dist[1][x]=num[x];
    if(flag){q1.push_back(x);}
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        DFS(y,!flag);
        if(flag&&dist[1][y]>dist[0][y]){
            q2.push_back(y);
        }
        dist[0][x]+=max(dist[1][y],dist[0][y]);
        dist[1][x]+=dist[0][y];
    }
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    visited[1]=true;
    DFS(1,true);
    cout<<max(dist[1][1],dist[0][1])<<endl;
    if(dist[1][1]>dist[0][1]){
        sort(q1.begin(),q1.end());
        for (auto iter = q1.begin(); iter != q1.end(); iter++) {		
            cout << *iter << " ";
        }
    }else{
        sort(q2.begin(),q2.end());
        for (auto iter = q2.begin(); iter != q2.end(); iter++) {		
            cout << *iter << " ";
        }
    }
    return 0;
}