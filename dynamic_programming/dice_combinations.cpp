#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
 
ll solve(vector<ll>& dp,ll s);
void print_vec(vector<ll>& dp);
 
int main(){
	ll n = 0;
	cin >> n;
	vector<ll> dp(n+1,-1);
	dp[0] = 1;
	ll ans = solve(dp,n);
	//print_vec(dp);
	cout << ans << endl;
 
	return 0;
}
 
 
 
ll solve(vector<ll>& dp,ll s){
	if(s < 0){return 0;}
	if(s==0){return 1;}
 
	if(dp[s] != -1){return dp[s];}
 
	ll ans = 0;
	for(ll i=1;i<=6;i++){
		ans += solve(dp,s-i);
	}
	return dp[s] = ans % mod;
}
 
 
void print_vec(vector<ll>& dp){
	for(ll i=0;i < dp.size();i++){
		cout << i << " : " << dp[i] << endl;
	}
}
