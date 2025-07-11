#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
 
int main()
{
	int n,m;
	cin >> m;
	n = m;
	n = 1 << n;
 
	for(int i=0;i<n;i++){
		string s = string (m,'0');
		string t = s;
 
		for(int j=m-1,x=i;j>=0,x>0;j--,x/=2){
			 s[j] = char(x&1) + '0';
		}
 
		int c=0;
		t[0] = s[0];
		for(int j=1;j<m;j++){
			t[j] = char(s[j] ^ s[j-1]) + '0';
		}
		
		cout << t << endl;
	}
 
 
    return 0;
}

