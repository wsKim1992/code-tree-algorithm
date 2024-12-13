#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000

using namespace std;

int n,m;
int uf[MAX_N+1];
bool visited[MAX_N+1];
int find(int x){
    if(uf[x]==x)return x;
    return uf[x]=find(uf[x]);
}

void uni(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[rootX]=rootY;
}

int main() {
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++){
        uf[i]=i;
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        int rootX = find(x);
        int rootY=find(y);
        if(rootX==rootY){
            ans+=1;
        }else{
            uni(x,y);
        }
    }
    for(int i=1;i<=n;i++){
        int root = find(i);
        if(!visited[root]){
            visited[root]=true;
            ans+=1;
        }
    }
    cout<<ans-1<<endl;

    return 0;
}