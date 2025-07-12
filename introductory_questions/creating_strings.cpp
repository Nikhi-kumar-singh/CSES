#include <bits/stdc++.h>
using namespace std;
 
void solve(string s){
    vector<string>ans;
    sort(s.begin(),s.end());
 
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
 
    cout << ans.size() << endl;
    for(string a : ans){
        cout << a << endl;
    }
}
 
 
int main() {
    string s;
    cin >> s;
    solve(s);
 
    return 0;
}
