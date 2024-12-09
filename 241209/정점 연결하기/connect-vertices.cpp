#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 100000
using namespace std;

int uf[MAX_N+1];
int n;

int find (int x){
    if(x==uf[x])return x;
    return uf[x]=find(uf[x]);
}

void uni(int x,int y){
    int yRoot = find(y);
    int xRoot = find(x);
    uf[yRoot]=xRoot;
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        uf[i]=i;
    }
    for(int i=0,j=0;i<n-2;i++){
        int x,y;
        cin>>x>>y;
        uni(x,y);
    }
    for(int i=2;i<=n;i++){
        int I = find(i);
        if(I!=find(1)){
            cout<<1<<" "<<I<<endl;
            break;
        }
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}