#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#define MAX_N 999
using namespace std;

int n;
char inputs[MAX_N+1];
vector<int>edges[MAX_N+1];
int inDegree[MAX_N+1];
void printAnswer(bool reverse){
    priority_queue<int>pq;
    int ans[MAX_N+1];
    for(int i = 1; i <= n; i++)
        inDegree[i] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < (int) edges[i].size(); j++)
            inDegree[edges[i][j]]++;
    
    for(int i = 1; i <= n; i++)
        if(!inDegree[i]) {
            pq.push(reverse ? i : -i);
        }
    int cnt=1;
    while(!pq.empty()){
        int x = reverse?pq.top():-pq.top();
        pq.pop();
        ans[x]=cnt++;
        for(int i=0;i<(int)edges[x].size();i++){
            int y = edges[x][i];
            inDegree[y]--;
            if(!inDegree[y]){
                pq.push(reverse?y:-y);
            }
        }
    }
    cout.fill('0');
    for(int i=1;i<=n;i++){
        cout<<setw(3)<<ans[i];
    }
    cout<<endl;
}

int main() {
    cin>>n;
    for(int i=1;i<n;i++){
        char input;
        cin>>input;
        if(input=='<'){
            edges[i].push_back(i+1);
        }else if(input=='>'){
            edges[i+1].push_back(i);
        }
    }
    printAnswer(false);
    printAnswer(true);
    return 0;
}