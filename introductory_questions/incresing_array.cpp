#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    ll mx = 0;
    ll ans = 0;
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, (ll)x);
        ans += mx - x;
    }
    cout << ans; 
    return 0; 
}
