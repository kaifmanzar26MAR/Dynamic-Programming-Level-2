#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
        int l;//lenght
        int i;//index
        int val;
        string psf;

        Pair(int l,int i,int val,string psf){
            this->l=l;
            this->i=i;
            this->val=val;
            this->psf=psf;
        }
};
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
            if(v[j]<v[i]){
                maxi=max(maxi,dp[j]);
            }
        }
        dp[i]=maxi+1;
        ans=max(dp[i],ans);
    }
    for(int i:dp) cout<<i<<" ";
    cout<<endl;
     queue<Pair*> q;
        for(int i=0;i<dp.size();i++){
            if(ans==dp[i]){
                q.push(new Pair(ans,i,v[i],to_string(v[i])+" "));
            }
        }
        

        int ct=0;

        while(!q.empty()){
            Pair* rem=q.front();
            q.pop();

            if(rem->l==1){
                ct++;
                cout<<rem->psf<<endl;
            }

            for(int j=0;j<rem->i;j++){
                if(dp[j]==rem->l-1 && v[j]<=rem->val){
                    q.push(new Pair(dp[j],j,v[j],to_string(v[j])+"->"+rem->psf));
                }
            }
        }
        cout<<ct;
return 0;
}
// 10
// 10 22 9 33 21 50 41 60 80 1
// op=2

// working fine but not accepted in leetcode