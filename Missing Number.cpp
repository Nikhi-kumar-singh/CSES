#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n;
	cin >> n;
    long long int sum = 0;
    vector<int>v(n);
    for(int i=0;i<n-1;i++)
    {
        long long int m ;
        cin >> m;
        sum += m;
    }
    long long int sum1 = (n*(n+1))/2;
    long long int ans = sum1-sum;
    cout<<ans<<endl;
 
    return 0;
}