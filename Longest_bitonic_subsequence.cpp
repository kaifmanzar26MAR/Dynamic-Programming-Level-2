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
    vector<int> incLIS(n,0);
    int ans=0;
    for(int i=0;i<n;i++){
        int maxi=0;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]){
                maxi=max(maxi,incLIS[j]);
            }
        }
        incLIS[i]=maxi+1;
        ans=max(incLIS[i],ans);
    }

    vector<int> decLIS(n,0);
    for(int i=n-1;i>=0;i--){
        int maxi=0;
        for(int j=n-1;j>i;j--){
            if(v[j]<=v[i])
                maxi=max(maxi,decLIS[j]);
        }
        decLIS[i]=maxi+1;
    }
    for(int i:incLIS){
        cout<<i<<" ";
    }cout<<endl;
    for(int i:decLIS){
        cout<<i<<" ";
    }cout<<endl;

    int omax=0;
    for(int i=0;i<n;i++){
        if(incLIS[i]+decLIS[i]-1>omax) omax=incLIS[i]+decLIS[i]-1;
    }
    cout<<omax;

return 0;
}

// 10
// 10 22 9 33 21 50 41 60 80 1
// 1 2 1 3 2 4 4 5 6 1
// 3 3 2 3 2 3 2 2 2 1
// op 7