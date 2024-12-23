#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#define MAX_N 1000
using namespace std;

vector<int>edges[MAX_N+1];
int d[MAX_N+1];
int n,m;
int inDegree[MAX_N+1];
queue<int>q;
int num[MAX_N+1];

int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        inDegree[y]+=1;
    }
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
            d[i]=1;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<(int)edges[x].size();i++){
            int y = edges[x][i];
            if(d[y]<d[x]){
                d[y]=d[x];
                num[y]=1;
            }else if(d[y]==d[x]){
                num[y]+=1;
            }
            inDegree[y]-=1;
            if(inDegree[y]==0){
                d[y]=num[y]>=2?d[y]+1:d[y];
                q.push(y);
            }
        }
    }  
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,d[i]);
    }
    cout<<ans<<endl;
    return 0;
}