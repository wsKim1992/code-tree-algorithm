#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX_N 10000
#define MAX_M 100000
using namespace std;
int n,m;
vector<tuple<int,int,int>>edges;
int uf[MAX_N+1];

int find(int x){
    if(x==uf[x])return x;
    return uf[x]=find(uf[x]);
}

void Union(int x,int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[rootX]=rootY;
}

int main() {
    int ans =0;
    int maxVal=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,cost;
        cin>>x>>y>>cost;
        edges.push_back(make_tuple(cost,x,y));
    }
    for(int i=1;i<=n;i++){
        uf[i]=i;
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<(int)edges.size();i++){
        int cost,x,y;
        tie(cost,x,y)=edges[i];
        if(find(x)!=find(y)){
            Union(x,y);
            ans+=cost;
            maxVal=max(maxVal,cost);
        }
    }
    cout<<ans-maxVal<<endl;
    return 0;
}