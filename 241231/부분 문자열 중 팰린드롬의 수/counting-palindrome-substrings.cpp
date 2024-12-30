#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 200000
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
    int ans = 0;

    for(int i=0;i<n;i++){
        if(r<i){A[i]=0;}
        else{
            int ii = 2*p-i;
            A[i]=min(r-i,A[ii]);
            ans+=(A[i]/2);
        }
        while(i-A[i]-1>=0&&i+A[i]+1<n&&input_str[i-A[i]-1]==input_str[i+A[i]+1]){
            A[i]++;
            ans+=1;
        }
        if(r<i+A[i]){
            r=A[i]+i;
            p=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}