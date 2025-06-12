#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define ll long long
#define endl "\n"
#define vl vector<ll>
 
 
void solve(){
    ll n,m,ans=0;
    cin >> n >> m;
    // cout << n << "   " << m << endl;
    vl coins(n,0);
    vl dp(m+1,INT_MAX);
    for(ll i=0;i<n;i++){
        cin >> coins[i];
    }
    dp[0] = 0;
 
    for(ll i=0;i<=m;i++){
        for(ll j=0;j<n;j++){
            if((i-coins[j]) >=0){
                // cout << i << "--" <<  dp[i] << endl;
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
 
    if(dp[m]==INT_MAX){
        cout << -1 << endl;
        return;
    }
    cout << dp[m] << endl;
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
