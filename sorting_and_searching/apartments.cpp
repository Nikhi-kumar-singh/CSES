#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
 
int main() {
    ll m,n,k;
    cin >> m >> n >> k;
 
    vector<int> v1(m);
    vector<int> v2(n);
    for(int i=0;i<m;i++){cin >> v1[i];}
    for(int i=0;i<n;i++){cin >> v2[i];}
    sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
 
    ll i=0,j=0,ans=0;
 
    while(i<m && j<n){
    	if(abs(v1[i]-v2[j]) <= k){++i,++j,++ans;}
    	else{
    		if(v1[i]-k > v2[j]){++j;}
    		else if(v1[i]+k < v2[j]){++i;}
    	}
    }
 
    cout << ans << endl;
 
	return 0;
}

