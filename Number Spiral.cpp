#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	long long int x, y;
	cin >> x >> y;
	long long int ans;
	if (y > x) {
		if (y % 2) ans = (y * y) - (x - 1);
		else ans = ((y - 1) * (y - 1)) + (x - 1) + 1;
	}
	else {
		if (x % 2) ans = ((x - 1) * (x - 1)) + (y - 1) + 1;
		else ans = (x * x) - (y - 1);
	}
	cout << ans << endl;
}
 
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        solve();
    }
    return 0;
}