#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int n,m;
int uf[MAX_N+1];
int ans=0;

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
    for(int i=1;i<=n;i++){
        uf[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        int rootX = find(x);
        int rootY = find(y);
        if(rootX!=rootY){
            uni(x,y);
        }else{
            if(ans==0){
                ans=i;
            }
        }
    }
    if(ans==0)cout<<"happy"<<endl;
    else cout<<ans<<endl;
    return 0;
}