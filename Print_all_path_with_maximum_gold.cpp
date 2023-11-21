#include<bits/stdc++.h>
using namespace std;
class Pair{
public:
    int i;
    int j;
    string psf;
    Pair(string psf,int i,int j){
        this->i=i;
        this->j=j;
        this->psf=psf;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }

    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j==m-1){
                dp[i][j]=matrix[i][j];
            }else if(i==0){ 
                dp[i][j]=matrix[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }else if(i==n-1){
                dp[i][j]=matrix[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }else{
                dp[i][j]=matrix[i][j]+max(dp[i][j+1],max(dp[i-1][j+1],dp[i+1][j+1]));
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<dp.size();i++){
        maxi=max(maxi,dp[i][0]);
    }
    cout<<maxi<<endl;
    queue<Pair*> q;
    for(int i=0;i<n;i++){
        if(dp[i][0]==maxi)
            q.push(new Pair(to_string(i)+" ",i,0));//pair contain path_so_far, i,j
    }
    vector<string> ans;
    while(!q.empty()){
        Pair* rem=q.front();
        q.pop();
        if(rem->j==m-1){
            ans.push_back(rem->psf);
        }else if(rem->i==0){
            int m=max(dp[rem->i][rem->j+1],dp[rem->i+1][rem->j+1]);
            if(m==dp[rem->i][rem->j+1]){
                q.push(new Pair(rem->psf+" d2",rem->i,rem->j+1));
            }
            if(m==dp[rem->i+1][rem->j+1]){
                q.push(new Pair(rem->psf+" d3",rem->i+1,rem->j+1));
            }
        }else if(rem->i==n-1){
            int m=max(dp[rem->i][rem->j+1],dp[rem->i-1][rem->j+1]);
            
            if(m==dp[rem->i-1][rem->j+1]){
                q.push(new Pair(rem->psf+" d1",rem->i-1,rem->j+1));
            }
            if(m==dp[rem->i][rem->j+1]){
                q.push(new Pair(rem->psf+" d2",rem->i,rem->j+1));
            }
        }else{
            int m=max(dp[rem->i][rem->j+1],max(dp[rem->i-1][rem->j+1],dp[rem->i+1][rem->j+1]));
            
            if(m==dp[rem->i-1][rem->j+1]){
                q.push(new Pair(rem->psf+" d1",rem->i-1,rem->j+1));
            }
            if(m==dp[rem->i][rem->j+1]){
                q.push(new Pair(rem->psf+" d2",rem->i,rem->j+1));
            }
            if(m==dp[rem->i+1][rem->j+1]){
                q.push(new Pair(rem->psf+" d3",rem->i+1,rem->j+1));
            }
        }
        
    }
    for(string i :ans){
        cout<<i<<endl;
    }
    
return 0;
}

// 6 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1
// op:
// 33
// 4  d3 d1 d2 d3 d1

// 4 4
// 3 2 3 1
// 2 4 6 0
// 5 0 1 3
// 9 1 5 1
// op:
// 18
// 2  d1 d2 d3
// 3  d1 d1 d3
// 3  d2 d2 d1