#include<bits/stdc++.h>
using namespace std;
class Envelope{
    public:
        int w;
        int h;

        Envelope(int w,int h){
            this->w=w;
            this->h=h;
        }
};
bool comp(Envelope* a,Envelope* b){
    return a->w<b->w;
}
int main(){
    int n;
    cin>>n;
    vector<Envelope*> v;
    for(int i=0;i<n;i++){
        int x;
        int y;
        cin>>x>>y;
        Envelope* obj=new Envelope(x,y);
        v.push_back(obj);
    }
    sort(v.begin(),v.end(),comp);

    // for(Envelope* e:v){
    //     cout<<e->w<<" "<<e->h<<endl;
    // }

    int omax=0;
    vector<int> dp(n,0);

    for(int i=0;i<n;i++){
        int maxi=0;
        for(int j=0;j<i;j++){
            if(v[j]->h <v[i]->h && v[j]->w<v[i]->w){
                maxi=max(maxi,dp[j]);
            }
        }
        dp[i]=maxi+1;
        omax=max(omax,dp[i]);
    }
    cout<<omax;
return 0;
}

// 11
// 17 5
// 26 10
// 25 24
// 48 84
// 63 72
// 42 86
// 9 55
// 4 70
// 21 45
// 68 76
// 50 51
// op 5