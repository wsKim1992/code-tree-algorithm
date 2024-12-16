#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define MAX_N 100000

using namespace std;

int n,m;
vector<tuple<int,int,int>>edges;
int uf1[MAX_N+1];
int uf2[MAX_N+1];

int find(int x,int uf[]){
    if(uf[x]==x)return x;
    return uf[x]=find(uf[x],uf);
}

void Union(int x,int y,int uf[]){
    int rootX = find(x,uf);
    int rootY = find(y,uf);
    uf[rootX]=rootY;
}

int main() {
    cin>>n>>m;
    int ans1=0;
    int ans2=0;
    for(int i=0;i<m;i++){
        int x,y,cost;
        cin>>x>>y>>cost;
        edges.push_back(make_tuple(cost,x,y));
    }
    for(int i=1;i<=n;i++){
        uf1[i]=i;
        uf2[i]=i;
    }
    sort(edges.begin(),edges.end());
    int edgeSize = (int)edges.size();
    for(int i=0;i<edgeSize;i++){
        int x1,y1,cost1;
        int x2,y2,cost2;
        tie(cost1,x1,y1)=edges[i];
        tie(cost2,x2,y2)=edges[edgeSize-i-1];

        if(find(x1,uf1)!=find(y1,uf1)){
            Union(x1,y1,uf1);
            if(cost1==0){
                ans1+=1;
            }
        }
        if(find(x2,uf2)!=find(y2,uf2)){
            Union(x2,y2,uf2);
            if(cost2==0){
                ans2+=1;
            }
        }
    }
    cout<<ans1*ans1-ans2*ans2<<endl;
    return 0;
}