#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
 
#define ll long long
#define vi vector<int>
#define vl vector<long long>
 
void solve(){
    int n,m;
    cin >> n >> m;
    vl nums(n,0);
    vl dp(n+1,0);
 
    for(int i=1;i<=n;i++){
        cin >> nums[i];
 
        if(i==0){
            dp[i] = nums[i];
        }else{
            dp[i] = dp[i-1] + nums[i];
        }
    }
 
    for(int i=0;i<m;i++){
        ll l,r;
        cin >> l >> r;
 
        if(l==0){
            cout << dp[r] << endl;
        }else{
            cout << dp[r]-dp[l-1] << endl;
        }
    }
}
 
 
int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
