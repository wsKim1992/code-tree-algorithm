#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#define MAX_N 100000

using namespace std;

int n,m,k;
vector<tuple<int,int,int>>edges;
int uf[MAX_N+1];
int num[MAX_N+1];
bool visited[MAX_N+1];
int numOfCluster=0;

int find(int x){
    if(x==uf[x])return uf[x];
    return uf[x]=find(uf[x]);
}

void Union(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[rootX]=rootY;
}

int main() {
    int ans =0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        uf[i]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(find(x)!=find(y)){
            Union(x,y);
            //visited[x][y]=true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+i;j<=n;j++){
            int rootX = find(i);
            int rootY = find(j);
            if(rootX!=rootY){
                if(!visited[rootX]){
                    visited[rootX]=true;
                    numOfCluster+=1;
                }
                if(!visited[rootY]){
                    visited[rootY]=true;
                    numOfCluster+=1;
                }
                edges.push_back(make_tuple(num[i]+num[j],i,j));
            }
        }
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<(int)edges.size();i++){
        int cost,x,y;
        tie(cost,x,y)=edges[i];
        if(find(x)!=find(y)&&numOfCluster-1>0){
            Union(x,y);
            numOfCluster-=1;
            ans+=cost;
        }
    }
    if(ans<=k){cout<<ans<<endl;}
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}