#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000

using namespace std;


int uf[MAX_N+1];
int qarr[MAX_N+1];
int n=0;
int m=0;
int k=0;
bool ans = true;
int find(int x){
    if(uf[x]==x){return x;}
    return uf[x]=find(uf[x]);
}

void uni(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    uf[rootA]=rootB;
}

int main() {
    cin>>n>>m>>k;
    for(int i =1;i<=n;i++){
        uf[i]=i;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        uni(x,y);
    }
    for(int j=0;j<k;j++){
        cin>>qarr[j];
    }
    for(int i=0;i<k;i++){
        if(i+1<k){
            ans = ans && (find(qarr[i])==find(qarr[i+1]));
        }
    }
    cout<<(int)ans<<endl;
    // 여기에 코드를 작성해주세요.
    return 0;
}