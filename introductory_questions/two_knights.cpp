#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve(){
    ll n; 
    cin >> n;
    ll i=4;
 
    if(n>=1){cout << 0 << endl;}
    if(n>=2){cout << 6 << endl;}
    if(n>=3){cout << 28 << endl;}
 
    while(i<=n){
        // int t = (i*i)*((i*i)-1)/2;
        // int r = 24+(i-4)*20+(i-4)*(i-4)*4;
        cout << ((i*i)*((i*i)-1)/2)-(24+(i-4)*20+(i-4)*(i-4)*4) << endl;
        ++i;
    }
}
 
 
int main(){
    solve();
    return 0;
}

