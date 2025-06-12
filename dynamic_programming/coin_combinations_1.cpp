#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define ll long long
#define endl "\n"
#define vl vector<ll>
#define mod 1000000007
 
 
ll find_ans(vl &coins,vl &dp,ll n,ll total,ll sum){
    // cout << total << "---" << sum << endl;
    if(sum > total){return 0;}
    if(sum == total){return 1;}
    if(dp[sum] != -1){
        // cout << sum << "->" << dp[sum]  << endl;
        return dp[sum];
    }
 
    int ans = 0;
    for(ll i=0;i<n;i++){
        ll t = find_ans(coins,dp,n,total,sum+coins[i]) % mod;
        ans = (ans+t) % mod;
    }
    // cout << sum << "->" << dp[sum]  << endl;
    return dp[sum]=ans;
}
 
 
void solve(){
    ll n,m,ans=0;
    cin >> n >> m;
    // cout << n << "   " << m << endl;
    vl coins(n,0);
    vl dp(m+1,-1);
    for(ll i=0;i<n;i++){
        cin >> coins[i];
    }
    // dp[0] = 1;
 
    cout << find_ans(coins,dp,n,m,0) << endl;
}
 
 
int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    } 
    return 0;
}