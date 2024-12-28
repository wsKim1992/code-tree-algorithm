#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define MAX_N 100
#define MAX_ALPHA 26
using namespace std;

unordered_map<char,int> char_to_num;
char num_to_char[MAX_ALPHA+1];
int n;
queue<int>q;
vector<int>edges[MAX_ALPHA+1];
string words[MAX_N+1];
int inDegree[MAX_ALPHA+1];
vector<char>ans;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>words[i];
    }
    int N=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<words[i].length();j++){
            char x = words[i][j];
            if(!char_to_num[x]){
                char_to_num[x]=++N;
                num_to_char[N]=x;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<min(words[i].length(),words[i+1].length());j++){
            char x=words[i][j];char y = words[i+1][j];
            if(x!=y){
                edges[char_to_num[x]].push_back(char_to_num[y]);
                inDegree[char_to_num[y]]++;
                break;
            }
        }
    }
    int numOfChars = char_to_num.size();
    int cnt=0;
    bool isInf=false;
    for(int i=1;i<=N;i++){
        if(!inDegree[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        if(q.size()>1){
            isInf=true;
            break;
        }
        q.pop();
        cnt+=1;
        ans.push_back(num_to_char[x]);
        for(int i=0;i<(int)edges[x].size();i++){
            int y = edges[x][i];
            inDegree[y]--;
            if(!inDegree[y]){
                q.push(y);
            }
        }
    }
    if(isInf){
        cout<<"inf"<<endl;
        return 0;
    }
    if(ans.size()!=char_to_num.size()){
        cout<<-1<<endl;
        return 0;
    }
    for(auto iter = ans.begin();iter!=ans.end();iter++){
        cout<<(*iter);
    }
    return 0;
}