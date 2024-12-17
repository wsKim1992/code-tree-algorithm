#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>
#include<utility>
#include <vector>
#include <iomanip>

#define MAX_N 200

using namespace std;

int n,m;
vector<pair<int,int>>node[MAX_N+1];
vector<tuple<double,int,int>>edges;
int uf[MAX_N+1];
bool occupied[MAX_N+1][MAX_N+1];
int find(int x){
    if(x==uf[x])return x;
    return uf[x]=find(uf[x]);
}

void Union(int x,int y){
    int rootX = find(x);
    int rootY = find(y);
    uf[rootX]=rootY;
}

int main() {
    cin>>n>>m;
    double ans =0.00;
    int edgeCount=0;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        node[i].push_back(make_pair(x,y));
    }
    for(int i =1;i<=n;i++){
        uf[i]=i;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        occupied[a][b]=true;
        Union(a,b);
    }
    for(int i=1;i<=n;i++){
        int x1,y1;
        tie(x1,y1)=node[i][0];
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(occupied[j][i]||occupied[i][j])continue;
            occupied[i][j]=true;
            int x2,y2;
            tie(x2,y2) = node[j][0];
            double cost = sqrt((long long)(x1-x2)*(x1-x2)+(long long)(y1-y2)*(y1-y2));
            edges.push_back(make_tuple(cost,i,j));
        }
    }
    
    sort(edges.begin(),edges.end());
    for(int i=0;i<(int)edges.size();i++){
        double cost;
        int x,y;
        tie(cost,x,y)=edges[i];
        if(find(x)!=find(y)){
            Union(x,y);
            ans+=cost;
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<ans<<endl;
    return 0;
}