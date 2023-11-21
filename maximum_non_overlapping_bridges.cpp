#include<bits/stdc++.h>
using namespace std;
class Cord{
    public:
        int north;
        int south;
        Cord(int north,int south){
            this->north=north;
            this->south=south;
        }
};
bool comp(Cord* a,Cord* b){
    // if north is equal in test case
    if(a->north != b->north){
        return a->north<b->north;
    }else{
        return a->south<b->south;
    }

    // if north is not equal in test case
    // return a->north<b->north;
}
int main(){
    int n;
    cin>>n;
    vector<Cord*> v;
    for(int i=0;i<n;i++){
        int north;
        int south;
        cin>>north;
        cin>>south;

        Cord* obj=new Cord(north,south);
        v.push_back(obj);
    }
    sort(v.begin(),v.end(),comp);
    // for(Cord* e:v){
    //     cout<<e->north<<" "<<e->south<<endl;
    // }
    vector<int> dp(n,0);
    int omax=0;
    for(int i=0;i<n;i++){
        int maxi=0;
        for(int j=0;j<i;j++){
            if(v[j]->south<=v[i]->south){
                maxi=max(maxi,dp[j]);
            }
        }
        dp[i]=maxi+1;
        omax=max(omax,dp[i]);
    }
    cout<<omax;
return 0;
}

// 10
// 10 20
// 2 7
// 8 15
// 17 3
// 21 40
// 50 4
// 41 57
// 60 80
// 80 90
// 1 30
// op 7