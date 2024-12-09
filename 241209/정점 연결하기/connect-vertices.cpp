#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 100000
using namespace std;

int uf[MAX_N+1];
bool visited[MAX_N+1];
int edges[2];
int n;

int find (int x){
    if(x==uf[x])return x;
    return uf[x]=find(uf[x]);
}

int uni(int x,int y){
    if(y<x)return uni(y,x);
    int yRoot = find(y);
    int xRoot = find(x);
    return yRoot>xRoot?uf[yRoot]=xRoot:uf[xRoot]=yRoot;
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        uf[i]=i;
        visited[i]=false;
    }
    for(int i=0,j=0;i<n-2;i++){
        int x,y;
        cin>>x>>y;
        int result = uni(x,y);
        if(!visited[result]){
            visited[result]=true;
            edges[j++]=result;
        }else{
            continue;
        }
    }
    cout<<edges[0]<<" "<<edges[1]<<endl;

    // 여기에 코드를 작성해주세요.
    return 0;
}