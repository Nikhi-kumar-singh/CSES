#include <iostream>
using namespace std;
 
#define ll long long
const int m = 1000000000;
 
ll solve(int n) {
    ll result = 0;
    ll c = 5;
    while(c < m){
        result += n/c;
        c *= 5;
    }
    return result;
}
 
int main() {
    ll n;
    cin >> n;
    
    cout << solve(n) << endl;
 
    return 0;
}
