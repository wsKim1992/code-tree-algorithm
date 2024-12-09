#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 100000

using namespace std;

int uf[MAX_N+1];
int numOfLines[MAX_N+1];
int n,m;

int find(int x){
    if(uf[x]==x)return x;
    return uf[x]=find(uf[x]);
}

void uni(int x, int y){
    int xRoot = find(x);
    int yRoot = find(y);
    uf[xRoot]=yRoot;
    if(xRoot!=yRoot){
        numOfLines[yRoot]+=numOfLines[xRoot];
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        uf[i]=i;
        numOfLines[i]=1;
    }
    for(int i=0;i<m;i++){
        char order;
        cin>>order;
        if(order=='x'){
            int x,y;
            cin>>x>>y;
            uni(x,y);
        }else if(order=='y'){
            int x;
            cin>>x;
            cout<<numOfLines[find(x)]<<endl;
        }
    }
    return 0;
}