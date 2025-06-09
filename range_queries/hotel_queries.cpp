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
 
 
//user code
//segment tree
struct sgt{
    vi st;
    int n;
 
    void init(int n){
        this->n=n;
        st.resize(4*n);
    }
 
    void build(int start,int end,int node,vi& v){
        // leaf node
        if(start==end){
            st[node] = v[start];
            return;
        }
 
        int mid = start+(end-start)/2;
        //left subtree
        build(start, mid,node*2+1,v);
        // right subtree
        build(mid+1,end,node*2+2,v);
 
        st[node] = max(st[node*2+1] , st[node*2+2]);
    }
 
    void build(vi& v){
        init(v.size());
        build(0,v.size()-1,0,v);
    }
 
    void print_tree(){
        int m = st.size();
 
        for(int i=0;i<m;i++){
            cout << i << " -> " << st[i] << endl;
        } 
    }
 
    int query(int s,int e,int val,int node){
        if(node >= 4*n || st[node] < val){return 0;}
        if(s==e){
            st[node] -= val;
            return s+1;
        }
 
        int mid = s+(e-s)/2;
 
        int ans = 0;
        if(st[node*2+1] >= val){
            ans = query(s,mid,val,node*2+1);
        }else if(st[node*2+2] >= val){
            ans = query(mid+1,e,val,node*2+2);
        }
 
        st[node] = max(st[node*2+1],st[node*2+2]);
 
        return ans;
    }
 
 
    void query(int val){
        int ans = query(0,n-1,val,0);
        // cout << "ans : " << ans << endl;
        cout << ans  << "\t";
    }
};
 
 
 
void solve() {
    int n,m;
    cin >> n >> m;
    vi v(n,0);
 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
 
    sgt tree;
    tree.build(v);
 
    while(m--){
        int t;
        cin >> t;
        tree.query(t);
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