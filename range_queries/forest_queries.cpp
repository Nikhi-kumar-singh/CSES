/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
 
const int N = 2005;
 
struct Fenwick2D {
    vvi fn;
    int n;
 
    void init(int size) {
        n = size + 2;
        fn.assign(n, vi(n, 0));
    }
 
    void add(int x, int y) {
        x++; y++; // convert to 1-based
        for (int i = x; i < n; i += (i & -i)) {
            for (int j = y; j < n; j += (j & -j)) {
                fn[i][j] += 1;
            }
        }
    }
 
    int get(int x, int y) {
        x++; y++;
        int res = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                res += fn[i][j];
            }
        }
        return res;
    }
 
    int range_sum(int x1, int y1, int x2, int y2) {
        return get(x2, y2)
             - get(x1 - 1, y2)
             - get(x2, y1 - 1)
             + get(x1 - 1, y1 - 1);
    }
};
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    Fenwick2D tree;
    tree.init(n);
 
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            if (row[j] == '*') {
                tree.add(i, j);
            }
        }
    }
 
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // convert to 0-based
        x1--; y1--; x2--; y2--;
        cout << tree.range_sum(x1, y1, x2, y2) << endl;
    }
}
 
int32_t main() {
    fast_io;
    solve();
    return 0;
}