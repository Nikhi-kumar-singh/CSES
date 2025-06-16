#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	sort(v.begin(),v.end());
 
	int i=0,j=1,ans=1;
 
	while(j<n && i<n){
		if(v[i]==v[j]){++j;}
		else{i=j++;++ans;}
	}
	cout << ans << endl;
 
	return 0;
}

