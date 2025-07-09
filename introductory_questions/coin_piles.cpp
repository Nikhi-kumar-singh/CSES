#include <iostream>
using namespace std;
 
#define ll long long
 
   
int main() {
    ll n;
    cin >> n;
 
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        cout << ((a+b)%3==0 && 2*a>=b && 2*b>=a ? "YES" : "NO") << endl;
    }
 
    return 0;
}
