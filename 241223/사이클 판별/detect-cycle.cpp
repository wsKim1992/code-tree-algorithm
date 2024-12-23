#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int n,m;
vector<int>graph[MAX_N+1];
queue<int>q;
int inDegree[MAX_N+1];

int main() {
    int cnt = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        inDegree[y]+=1;
    }
    for(int i=1;i<=n;i++){
        if(!inDegree[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cnt+=1;
        for(int i=0;i<(int)graph[x].size();i++){
            int y = graph[x][i];
            inDegree[y]-=1;
            if(!inDegree[y]){
                q.push(y);
            }
        }
    }
    if(cnt!=n){cout<<"Exists"<<endl;}
    else{cout<<"Not Exists"<<endl;}
    return 0;
}