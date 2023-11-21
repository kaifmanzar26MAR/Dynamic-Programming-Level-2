#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter value edges or vertices of the shape greater or equal 2 "<<endl;
    cin>>n;
    n=n-2;
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int l=i-1;
        int r=0;
        while(l>=0){
            dp[i]+=dp[r]*dp[l];
            r++;
            l--;
        }
    }
    cout<<dp[n];

return 0;
}

// 5
// op: 5

// 6
// op: 14