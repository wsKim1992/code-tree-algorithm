#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#define MAX_N 100000
using namespace std;

int n,m1,m2;
vector<int>graph[MAX_N+1];
int inDegree[MAX_N+1];
queue<int>q;

int main() {
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        inDegree[y]+=1;
    }
    for(int i=1;i<=m2;i++){
        int x,y;
        cin>>x>>y;
    }
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cnt+=1;
        for(int i=0;i<(int)graph[x].size();i++){
            int y = graph[x][i];
            inDegree[y]-=1;
            if(inDegree[y]==0){
                q.push(y);
            }
        }
    }
    if(cnt==n){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}