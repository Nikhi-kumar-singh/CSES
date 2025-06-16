#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    // Input the weights
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    // Sort the weights in ascending order
    sort(v.begin(), v.end());
 
    int i = 0, j = n - 1, ans = 0;
 
    // Try to pair the lightest person with the heaviest person
    while (i <= j) {
        if (v[i] + v[j] <= k) {
            // If they can be paired, move both pointers
            i++;
        }
        // In either case, move the pointer for the heaviest person
        j--;
        ans++;
    }
    
    // Output the maximum number of pairs
    cout << ans << endl;
 
    return 0;
}

