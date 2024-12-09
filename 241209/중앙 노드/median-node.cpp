#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX, INT_MIN

#define MAX_N 100000
using namespace std;

vector<int>edges[MAX_N+1];
int n,r;
int d[2][MAX_N+1];
bool visited[MAX_N+1];
int c=-1;
int leafNode = -1;
void getCenter(int x,int subtractChildrenSize){
    if(edges[x].size()-subtractChildrenSize>=2){c=x;return;}
    bool isLeaf = true;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        getCenter(y,1);
        isLeaf=false;
        if(c!=-1)return;
    }
    if(isLeaf==true){
        leafNode=x;
        return;
    }
}

void dfs(int x){
    int maxVal=INT_MIN;
    int minVal=INT_MAX;
    bool isLeaf= true;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        isLeaf=false;
        dfs(y);
        maxVal=max(maxVal,d[1][y]);
        minVal=min(min(minVal,d[1][y]),d[0][y]);
    }
    if(isLeaf){
        d[1][x]=1;
        d[0][x]=d[1][x];

    }else{
        d[0][x]=minVal+1;
        d[1][x]=maxVal+1;
    }
}

int main() {
    cin>>n>>r;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    visited[r]=true;
    getCenter(r,0);
    if(c==-1)c=leafNode;
    for(int i =0 ;i<=n;i++){
        visited[i]=false;
    }
    if(c!=-1){
        visited[c]=true;
        dfs(c);
        cout<<d[1][c]-d[0][c]<<endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}