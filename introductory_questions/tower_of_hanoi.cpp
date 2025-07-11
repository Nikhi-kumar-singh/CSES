#include <iostream>
using namespace std;
 
void solve(int a,int b,int d){
    if(d==1){
        cout << a << "\t" << b << endl;
        return;
    }
    int t = 6-a-b;
    solve(a,t,d-1);
    cout << a << "\t" << b << endl;
    solve(t,b,d-1);
}
 
 
int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1  << endl;
    solve(1,3,n);
 
    return 0;
}

