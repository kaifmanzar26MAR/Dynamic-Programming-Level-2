#include<bits/stdc++.h>
using namespace std;
class Mydata{
    public:
    int i;//current index
    int s;//size of jump allowed
    int j;//jums possible
    string psf;//our ans string
    

    Mydata(int i,int s,int j, string psf){
        this->i=i;
        this->s=s;
        this->j=j;
        this->psf=psf;
    }
    
};
int main(){
    int n;
    cin>>n;
    vector<int> jumps;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        jumps.push_back(x);
    }
    vector<int> dp(n,0);
    for(int i=n-2;i>=0;i--){
        int steps=jumps[i];
        int maxi=INT_MAX;
        for(int j=1;j<=steps && i+j<n;j++){
            if(dp[i+j]!=INT_MAX && dp[i+j]<maxi){
                maxi=dp[i+j];
            }
        }
        if(maxi==INT_MAX){
            dp[i]=maxi;
        }else{
            dp[i]=maxi+1; 
        }
        
    }
    
    //Bfs part

    queue<Mydata*> q;
    Mydata* st=new Mydata(0,jumps[0],dp[0],to_string(0)+"");
    q.push(st);
    while(!q.empty()){
        Mydata* rem=q.front();
        q.pop();
        if(rem->j==0){
            cout<<rem->psf<<endl;
        }
        for(int j=1;j<=rem->s && rem->i+j<n;j++){
            int ci=rem->i +j;
            if(dp[ci]!=INT_MAX && dp[ci]==rem->j-1){
                q.push(new Mydata(ci,jumps[ci],dp[ci],rem->psf+"->"+to_string(ci)));
            }
        }
    }


return 0;
}

// 10
// 3 3 0 2 1 2 4 2 0 0