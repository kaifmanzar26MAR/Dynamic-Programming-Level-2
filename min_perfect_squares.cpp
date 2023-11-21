//min number of numbers in which you can represent a number
// ex:- 9 can be represented as 3^2 =1
// ex:- 10 can be represented as 1^2 + 3^2 =2
// ex:- 7 can be represented as 1^2 + 1^2 + 1^2 + 2^2 =4

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int mini=INT_MAX;
        for(int j=1;j*j<=i;j++){
            mini=min(mini,dp[i-(j*j)]);
        }
        dp[i]=mini+1;
    }
    cout<<dp[n];
return 0;
}