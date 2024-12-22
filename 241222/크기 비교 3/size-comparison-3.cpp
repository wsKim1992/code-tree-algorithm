#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#define MAX_N 32000
using namespace std;

int n,m;
vector<int>temp;
vector<int>graph[MAX_N+1];
bool visited[MAX_N+1];
priority_queue<int>q;
int inDegree[MAX_N+1];

int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        inDegree[y]++;
    }
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            temp.push_back(i);
        }
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<(int)temp.size();i++){
        q.push(-temp[i]);
    }
    while(!q.empty()){
        int x = q.top();
        q.pop();
        x=-x;
        cout<<x<<" ";
        for(int i=0;i<(int)graph[x].size();i++){
            int y = graph[x][i];
            inDegree[y]-=1;
            if(!inDegree[y]){
                q.push(-y);
            }
        }
    }
    return 0;
}