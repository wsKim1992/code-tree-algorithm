#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_NM 300

using namespace std;

int n,m;
int uf[MAX_NM*MAX_NM+1];

int find(int x){
    if(uf[x]==x){return x;}
    return uf[x]=find(uf[x]);
}

void uni(int x,int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[rootX]=rootY;
}

int main() {
    int ans = 0;
    int cnt=0;
    cin>>n>>m;
    tuple<int,int,int> edges[(MAX_NM+1)*(MAX_NM+1)];
    for(int i=1;i<=n;i++){
        int buffer = (i-1)*m;
        for(int j=1;j<=m-1;j++){
            int w;
            cin>>w;
            int first = buffer+j;
            int second = first+1;
            edges[cnt++]=make_tuple(w,first,second);
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1 ;j<=m;j++){
            int w; 
            cin>>w;
            int first = ((i-1)*m)+j;
            int second = (i*m)+j;
            edges[cnt++]=make_tuple(w,first,second);
        }
    }
    sort(edges,edges+n*m+1);
    for(int i=1;i<=n*m;i++){
        uf[i]=i;
    }
    for(int i=0;i<cnt;i++){
        int cost,x,y;
        tie(cost,x,y)=edges[i];
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            uni(x,y);
            ans+=cost;
        }
    }
    cout<<ans<<endl;
    return 0;
}