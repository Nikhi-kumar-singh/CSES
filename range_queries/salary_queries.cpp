/*
 i would like to thank erichto for sharing their for understanding codes for noob programmers like me

 */




/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


// #define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vb           vector<bool>
#define vi             vector <int>
#define vvi            vector<vi>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define umii           unordered_map<int,int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define fast_io        ios_base::sync_with_stdio(false);cin.tie(NULL)

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;
tree <pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> T;


void solve() {
    int n,m;
    cin >> n >> m;
    vi nums(n+1,0);
    // T.clear();

    for(int i=0;i<n;i++){
        cin >> nums[i];
        T.insert({nums[i],i});
    }


    for (int i = 0; i < m; ++i){
        char ch;
        int a,b;
        ci: >> ch >> a >> b;

        if(ch == '!'){
            --a;
            T.erase({nums[a],a});
            nums[a]=b;
            T.insert({nums[a],a});
        }else if(ch=='?'){
            int ans = T.order_of_key({b+1,0})-T.order_of_key({a,0});
            cout << ans << endl ;
        }
    }
}


int32_t main()
{
    fast_io;
    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
