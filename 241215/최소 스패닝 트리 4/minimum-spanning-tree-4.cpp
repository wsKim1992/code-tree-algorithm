#include <iostream>
#include <algorithm>
#include <tuple>
#define MAX_N 10000
#define MAX_M 100000
using namespace std;

int n,m;

tuple<int,int,int>edges[MAX_M+1];
int uf[MAX_N+1];
char type[MAX_N+1];

int find(int x){
    if(uf[x]==x)return x;
    return uf[x]=find(uf[x]);
}

void uni(int x,int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[rootX]=rootY;
}

int main() {
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>type[i];
        uf[i]=i;
    }
    for(int i =0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges[i]=make_tuple(z,x,y);
    }
    int ans=0;
    int numOfEdges = 0;
    sort(edges+1,edges+m+1);
    for(int i=0;i<m;i++){
        int x,y,cost;
        tie(cost,x,y)=edges[i];
        if(type[x]==type[y])continue;
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            uni(x,y);
            ans+=cost;
            numOfEdges+=1;
        }
    }
    bool isAllConnected=true;
    for(int i=2;i<=n;i++){
        int x = find(1);
        int y = find(i);
        if(x!=y){isAllConnected=false;}
    }
    if(isAllConnected){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}