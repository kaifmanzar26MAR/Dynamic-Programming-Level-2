//given the number of pairs of points to make chord
//you have to return the all possible ways to draw non intersecting chord through the point

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n=n/2;  //becuse out outpuct is equal to n/2 of the catlane
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        int inside=i-1;
        int outside=0;

        while(inside>=0){
            dp[i]+=dp[outside]*dp[inside];

            inside--;
            outside++;
        }
    }
    cout<<dp[n];
return 0;
}
//8
//op: 14