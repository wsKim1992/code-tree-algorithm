#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<math.h>
#define MAX_N 100000
using namespace std;

int n,m;
vector<int>edges[MAX_N+1];
queue<int>q;
long dist[MAX_N+1];
int inDegree[MAX_N+1];

int main() {
    cin>>n>>m;
    long ans = 0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        inDegree[y]++;
    }
    dist[1]=1;
    q.push(1);
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int i=0;i<(int)edges[x].size();i++){
            int y = edges[x][i];
            dist[y]+=dist[x];
            inDegree[y]-=1;
            if(!inDegree[y]){
                q.push(y);
            }
        }
    }
    ans = dist[n];
    long operends = pow(10,9)+7;
    cout<<ans%operends<<endl;
    return 0;
}