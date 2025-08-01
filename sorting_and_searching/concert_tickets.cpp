#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long int 
#define rep(i,n) for(ll i=0;i<n;i++)
typedef vector<int> vi;
typedef vector<vi> vii;
 
 
 
// concert tickets
void solve(){
	ll n,m,x;cin >> n >> m;
	multiset<int>s;
	rep(i,n) {
		cin >> x;
		s.insert(x);
	}
 
	rep(i,m){
		cin >> x;
		if(s.empty()){
			cout << -1 << endl;
			continue;
		}
		auto it = s.upper_bound(x);
		if(it == s.begin()){
			cout << -1 << endl;
		}else{
			cout <<  *(--it) << endl;
			s.erase(it);
		}
	}
}
 
 
 
int main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}
