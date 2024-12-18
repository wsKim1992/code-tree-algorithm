#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int n,m;
vector<int>edges[MAX_N+1];
queue<int>q;
int inDegree[MAX_N+1];


int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        inDegree[y]+=1;
    }
    int root =0;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            root=i;
            break;
        }
    }
    q.push(root);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<(int)edges[x].size();i++){
            int y = edges[x][i];
            inDegree[y]-=1;
            if(inDegree[y]==0){
                q.push(y);
            }
        }
    }
    cout<<endl;
    return 0;
}