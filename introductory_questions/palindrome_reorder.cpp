#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    string s, c, t;
    cin >> s;
    int n = s.size(), a = 0;
    vector<int> v(26, 0);
 
    for (int i = 0; i < n; i++) {
        v[s[i] - 'A']++;
    } 
 
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 == 1) {
            a++;
            c = (char)(i + 'A');
        }
        if (a > 1) {
            cout << "NO SOLUTION";
            return 0;
        }
        for (int j = 0; j < v[i] / 2; j++) {
            t += (char)(i + 'A');
        }
    }
 
    string t_reversed(t.rbegin(), t.rend());
    cout << t + c + t_reversed;
 
    return 0;
}
