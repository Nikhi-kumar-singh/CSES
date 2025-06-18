#include<bits/stdc++.h>
using namespace std;
// #define int long long int
 
int main()
{
    int n;
	cin >> n;
	int a = n - 1;
	int b = n - 2;
	if (n <= 3 && n != 1) {
		cout << "NO SOLUTION" << endl;
	}
	else if (n == 1) cout << 1 << endl;
	else {
		for (int i = a; i > 0; i -= 2) {
			cout << i << " ";
		}
		cout << n << " ";
		for (int j = b; j > 0; j -= 2) {
			cout << j << " ";
		}
 
	}
 
    return 0;
}
