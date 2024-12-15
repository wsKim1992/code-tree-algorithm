#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX_N 10000

using namespace std;

int n,m;
vector<pair<pair<int,int>,int>>edges;
int uf[MAX_N+1];

int find(int x){
    if(uf[x]==x)return x;
    return uf[x]=find(uf[x]);
}

void uni(int x,int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[x]=y;
}

bool edgeCompare(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
    return a.second<b.second;
}

int main() {
    int ans = 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        uf[i]=i;
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        pair<int,int>p=make_pair(x,y);
        edges.push_back(make_pair(p,z));
    }
    sort(edges.begin(),edges.end(),edgeCompare);
    for(auto iter=edges.begin();iter!=edges.end();iter++ ){
        pair<int,int>edge = (*iter).first;
        int w = (*iter).second;
        int rootX = find(edge.first);
        int rootY = find(edge.second);
        if(rootX!=rootY){
            uni(edge.first,edge.second);
            ans+=w;
        }
    }
    cout<<ans<<endl;
    return 0;
}