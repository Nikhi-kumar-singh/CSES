/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
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
 
/*
segment tree implementation using node pointer
*/
struct sgt{
public :
    int n;
    vi nodes;
    vi val;
    vector<bool> isterminal;
 
    void init(int n0){
        this->n = 4*n0;
        nodes.assign(n,0);
        val.assign(n,-1);
        isterminal.assign(n,false);
    }
 
    int build(vi& v,int s,int e,int node){
        if(s == e){
            nodes[node] = 1;
            val[node] = v[s];
            isterminal[node] = true;
            return 1;
        }
 
 
        int m = s+(e-s)/2;
        int a = build(v,s,m,node*2+1);
        int b = build(v,m+1,e,node*2+2);
        int t = nodes[node] = a+b;
        // bug(node,t);
 
        return  a+b;
 
    }
 
    void build(vi& v,int m){
        init(m);
        build(v,0,m-1,0);
    }
 
    int query(int i,int node){
        if(node >= n){
            return -1;
        }
        int l = node*2+1;
        int r = node*2+2;
        int lc = nodes[l];
        int rc = nodes[r];
 
        // bug(isterminal[node],node,lc,rc,i);
 
        if(isterminal[node]){
            nodes[node] = 0;
            isterminal[node] = false;
            return val[node];
        }
 
        if(lc+rc < i){return -1;}
 
        int ans=-1;
        if(lc >= i){
            ans = query(i,l);
        }
        else{
            ans = query(i-lc,r);
        }
 
        nodes[node] = nodes[l] + nodes[r];
        return ans;
 
    }
 
 
    void query(vi& v,int i){
        int ans = query(i,0);
        cout << ans << "\t";
    }
 
};
 
 
void solve() {
    int n;
    vi v;
    cin >> n;
    v.assign(n,0);
 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
 
    sgt tree;
    tree.build(v,n);
 
    while(n--){
        int t;
        cin >> t;
        tree.query(v,t);
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