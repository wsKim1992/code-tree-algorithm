#include <iostream>
#include <tuple>
#include <algorithm>

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
        cin >> type[i];
    }
    
    for(int i =0;i<m;i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        edges[i]=make_tuple(cost,x,y);
    }
    int ans=0;
    sort(edges,edges+m);

    for(int i = 1;i<=n;i++){
        uf[i]=i;
    }

    for(int i=0;i<m;i++){
        int x, y, cost;
        tie(cost,x,y)=edges[i];
        if(type[x]==type[y])continue;
        if(find(x)!=find(y)){
            ans+=cost;
            uni(x,y);
        }
    }
    bool isAllConnected=true;
    for(int i=2;i<=n;i++){
        int x = find(1);
        int y = find(i);
        if(x!=y){isAllConnected=false;}
    }
    if(isAllConnected){
        cout<<ans;
    }else{
        cout<<-1;
    }
    return 0;
}