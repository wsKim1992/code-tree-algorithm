#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int n,m;
queue<int>q;
int inDegree[MAX_N+1];
vector<int>edges[MAX_N+1];

int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        inDegree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!inDegree[i]){
            q.push(i);
        }
    }
    int ans=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        ans+=1; 
        for(int i=0;i<(int)edges[x].size();i++){
            int y = edges[x][i];
            inDegree[y]-=1;
            if(inDegree[y]==0){
                q.push(y);
            }
        }
    }
    if(ans==n)cout<<"Consistent"<<endl;
    else cout<<"Inconsistent"<<endl;
    return 0;
}