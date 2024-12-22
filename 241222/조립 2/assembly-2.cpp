#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX_N 100000

using namespace std;

int n,m,nodes;
vector<int>graph[MAX_N+1];
queue<int>q;
priority_queue<int>ans;
int inDegree[MAX_N+1];
bool isHaveAlready[MAX_N+1];
int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,k;
        cin>>x>>k;
        while(k--){
            int y;
            cin>>y;
            graph[y].push_back(x);
            inDegree[x]++;
        }
    }
    cin>>nodes;
    for(int i=0;i<nodes;i++){
        int y;
        cin>>y;
        ans.push(-y);
        q.push(y);
        isHaveAlready[y]=true;
    }
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int i=0;i<(int)graph[x].size();i++){
            int y = graph[x][i];
            if(isHaveAlready[y])continue;
            inDegree[y]--;
            if(inDegree[y]==0){
                q.push(y);
                ans.push(-y);
            }
        }
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<-ans.top()<<" ";
        ans.pop();
    }
    return 0;
}