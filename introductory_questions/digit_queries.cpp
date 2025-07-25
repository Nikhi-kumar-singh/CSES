#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;  // Multiply result by 'a' if b is odd
        }
        a *= a;        // Square 'a' for the next iteration
        b >>= 1;       // Divide b by 2
    }
    return res;
}
 
 
 
 
vector<ll> log10(ll t){
	ll n = 1,i=1,res = 0;
	vector<ll>v(2,0);
	while(res + 9*n*i < t){
		res += 9*n*i;
		n *= 10;
		i++;
	}
	v[0] = i-1;
	v[1] = t - res;
	return v;
}
 
 
 
void solve(ll t){
	vector<ll> v = log10(t);
	if(v[1]==0){
		cout << 9 << endl;
	}
	else{
		ll a = pow(10,v[0]);
		ll b = a + (v[1]-1)/(v[0]+1);
		// cout << "a : " << a << "\t\t" << v[0] << "\t" << v [1] << "\t" ;
		// cout << "b : " << b << "\t\t";
		ll c = v[1] % (v[0]+1);
		if(c==0){
			cout << b%10 << endl;
		}else{
			b /= 10;
			for(ll i=v[0];i>c;i--){
				b/=10;
			}
			cout << b%10 << endl;
		}
	}
}
 
 
 
int main(){
	int n ;
	cin >> n;
	vector<ll> v(n,0);
 
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
 
	for(int i=0;i<n;i++){
		solve(v[i]);
	}
}
