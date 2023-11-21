#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
        int i;
        int j;
        string psf;

        Pair(int i,int j,string psf){
            this->i=i;
            this->j=j;
            this->psf=psf;
        }
};
int main(){
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cin>>target;

    vector<vector<int>> dp(n+1,vector<int>(target+1,false));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(j==0){
                dp[i][j]=true;
            }else if(i==0){
                dp[i][j]==false;
            }else{
                if(dp[i-1][j]){
                    dp[i][j]=true;
                }else if(j>=arr[i-1] && dp[i-1][j-arr[i-1]]){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }
            }
        }
    }
    cout<<dp[n][target]<<endl;

    queue<Pair*> q;
    q.push(new Pair(n,target,""));
    vector<string> ans;
    while(!q.empty()){
        Pair* rem=q.front();
        q.pop();
        if(rem->i==0 || rem->j==0){
            ans.push_back(rem->psf);
            continue;
        }
        bool exc=dp[rem->i-1][rem->j];
        if(exc){
            q.push(new Pair(rem->i-1,rem->j,rem->psf));
        }
        if(rem->j>=arr[rem->i-1]){
            bool inc=dp[rem->i-1][rem->j-arr[rem->i-1]];
            if(inc){
                q.push(new Pair(rem->i-1,rem->j-arr[rem->i-1],to_string(rem->i-1) +" "+ rem->psf ));
            }
        }
    }

    for(string i:ans){
        cout<<i<<endl;
    }
return 0;
}
// 5
// 4 2 7 1 3
// 10