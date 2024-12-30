#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 200000
using namespace std;


int main() {
    int A[MAX_N];
    string temp;
    string input_str="";
    cin>>temp;
    for(int i=0;i<(int)temp.size();i++){
        input_str+="#";
        input_str+=temp[i];
    }
    input_str+="#";
    int n = (int)input_str.size();
    int r = -1;int p = -1;
    for(int i=0;i<n;i++){
        if(r<i){
            A[i]=0;
        }else{
            int ii = 2*p-i;
            A[i]=min(A[ii],r-i);
        }
        while(i-A[i]-1>=0&&i+A[i]+1<n&&input_str[i-A[i]-1]==input_str[i+A[i]+1]){
            A[i]++;
        }
        if(i+A[i]>r){
            r=i+A[i];
            p=i;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans,2*A[i]+1);
    }
    cout<<ans/2;

    return 0;
}