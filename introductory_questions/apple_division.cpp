#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void p(vector<int>v){
    for(int a : v){
        cout << a << endl;
    }
}
 
 
void solve(){
    ll n;
    cin >> n;
    ll sum=0,ans=0;
    vector<int>c;
    for(int i=0;i<n;i++){
        int t;cin >> t;
        c.push_back(t);
        sum += t;
    }
 
    for(int i=0;i< 1<<n;i++){
        ll s = 0;
        for(int j=0;j<n;j++){
            if(i>>j & 1){
                s += c[n-1-j];
            }
            if(s <= sum/2){
                ans = max(ans,s);
            }
        }
    }
 
    cout << abs((sum-ans)-ans) << endl;
}
 
 
int main() {
    solve();
 
    return 0;
}
