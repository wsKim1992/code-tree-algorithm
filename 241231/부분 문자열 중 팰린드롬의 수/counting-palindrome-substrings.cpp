#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 200001
using namespace std;

int main() {
    string temp;
    string input_str="";    
    cin>>temp;
    for(int i=0;i<(int)temp.size();i++){
        input_str+="#";
        input_str+=temp[i];
    }
    input_str+="#";
    int n = (int)input_str.size();
    int A[MAX_N];int r=-1;int p=-1;
    long long ans = 0;

    for(int i=0;i<n;i++){
        if(r<i){A[i]=0;}
        else{
            int ii = 2*p-i;
            A[i]=min(r-i,A[ii]);
        }
        while(i-A[i]-1>=0&&i+A[i]+1<n&&input_str[i-A[i]-1]==input_str[i+A[i]+1]){
            A[i]++;
        }
        if(r<i+A[i]){
            r=A[i]+i;
            p=i;
        }
    }
    for(int i=0;i<n;i++){
        int max_len = 2*A[i]+1;
        int l = max_len/2;
        ans+=(l+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}