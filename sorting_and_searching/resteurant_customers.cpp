#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define pb push_back
 
 
// resteurant problem (solved)
void solve(){
	ll n;cin >> n;
	vector<pair<int,int>>v;
	pair<int,int> p;
 
	for(int i=0;i<n;i++){
		int a,b;cin >> a >> b;
		v.pb({a,1});
		v.pb({b,0});
	}
	sort(v.begin(),v.end());
	int ans=0,curr=0;
 
 
	for(auto a : v){
		if(a.S == 1){++curr;}
		else{--curr;}
		ans = max(ans,curr);
	}
 
	cout << ans << endl;
 
}
 
 
int main(){
	solve();
	return 0;
}
