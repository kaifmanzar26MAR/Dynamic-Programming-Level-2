#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> dp(n,0);
    int ans=0;
    for(int i=0;i<n;i++){
        int maxi=0;
        for(int j=0;j<i;j++){
            if(v[j]<=v[i]){
                if(maxi==0){
                    maxi=dp[j];
                }else if(dp[j]>maxi){
                    maxi=dp[j];
                }
            }
        }
        if(maxi==0){
            dp[i]=v[i];
        }else{
            dp[i]=maxi+v[i];
        }
        ans=max(dp[i],ans);
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    cout<<ans;
return 0;
}
// 10
// 10 22 9 33 21 50 41 60 80 1
// op=6