#include <iostream>
using namespace std;
 
#define ll long long
const int MOD = 1000000007;
 
ll fact_pow(int a, int b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * (ll)a) % MOD; 
        }
        a = (a * (ll)a) % MOD; 
        b /= 2;
    }
    return result;
}
 
int main() {
    int n;
    cin >> n;
    
    cout << fact_pow(2, n) << endl;
 
    return 0;
}
