#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX, INT_MIN

#define MAX_N 100000
using namespace std;

vector<int>edges[MAX_N+1];
int n,r;
int d[MAX_N+1];
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
    d[x]=1;
    for(int i=0;i<(int)edges[x].size();i++){
        int y = edges[x][i];
        if(visited[y])continue;
        visited[y]=true;
        dfs(y);
        d[x]+=d[y];
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
    //FindMidNode(r);
    if(c==-1)c=leafNode;
    for(int i =0 ;i<=n;i++){
        visited[i]=false;
    }
    if(c!=-1){
        visited[c]=true;
        dfs(c);
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        for(int i =0 ;i<edges[c].size();i++){
            maxVal=max(maxVal,d[edges[c][i]]);
            minVal=min(minVal,d[edges[c][i]]);
        }
        cout<<maxVal-minVal<<endl;
    }
    return 0;
}