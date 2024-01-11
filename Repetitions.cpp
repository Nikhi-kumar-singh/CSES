#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int count = 1;
    int max1 = 1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1] == s[i]){
            ++count;
             max1 = max(count,max1);
        }
        else{
            count=1;
        }
    }
    cout<<max1<<endl;
}
