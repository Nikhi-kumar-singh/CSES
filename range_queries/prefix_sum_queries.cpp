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
 
#define bug(...) __f (#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
 
 
 
class user_sgt{
public:
    int n,size;
    vi mp,hi,lo,sum,pre;
 
    void init(int n_){
        n=n_;
        size=4*n_ + 5;
        mp.resize(size);
        lo.resize(size);
        hi.resize(size);
        sum.resize(size);
        pre.resize(size);
    }
 
    void pull(int node){
        sum[node] = sum[node*2] + sum[node*2+1];
        pre[node] = max(pre[node*2],sum[node*2]+pre[node*2+1]);
 
 
        // bug(node,lo[node],hi[node]);
        // bug(node,pre[node],sum[node]);
        // bug(node,sum[node],sum[node*2],sum[node*2+1]);
        // bug(node,pre[node],pre[node*2],sum[node*2],pre[node*2+1]);
    }
 
    void build_tree(int node,int l,int r){
        lo[node] = l;
        hi[node] = r;
        
        if(l==r){
            int t ;
            cin >> t;
            // cout << l << ",input element : " << t << endl;
            sum[node] = t;
            pre[node] = max(0LL,t);
            mp[l] = node;
            // bug(node,hi[node],lo[node]);
            // bug(node,pre[node],sum[node]);
            return;
        }
 
        int mid = l + (r-l)/2;
 
        build_tree(node*2,l,mid);
        build_tree(node*2+1,mid+1,r);
 
        pull(node);
    }
 
    void build_tree(){
        build_tree(1,1,n);
    }
 
 
    void update(int ind,int val){
        int node = mp[ind];
        // bug(node,sum[node]);
        sum[node] = val;
        pre[node] = max(0LL,val);
        // bug(node,sum[node]);
 
        while(node){
            node >>= 1;
            if(!node){break;}
            pull(node);
        }
    }
 
    pii query(int node,int l,int r){
        if(hi[node] < l || r < lo[node]){
            return {0,0};
        }else if(l<=lo[node] && hi[node]<=r){
            return {pre[node],sum[node]};
        }
 
 
        // bug(l,r);
 
        int mid = l + (r-l)/2;
 
        pii left = query(node*2,l,r);
        pii right = query(node*2+1,l,r);
 
 
        // bug(l,r,mid);
        // bug(node,node*2,node*2+1);
        // bug(node,lo[node],hi[node]);
        // bug(left.F,left.S,right.F,right.S);
 
        // pre[node] = max(pre[node*2],sum[node*2]+pre[node*2+1]);
        
 
        return {max(left.first,left.second+right.first),left.second+right.second};
    }
 
 
    void query(int l,int r){
        pii ans = query(1,l,r); 
        // cout << "ans : " << ans.first << endl;
        cout << ans.first << endl;
    }
};
 
 
 
 
void solve() {
    int n,q;
    cin >> n >> q;
 
 
    user_sgt sgt;
    sgt.init(n);
    sgt.build_tree();
 
 
    while(q--){
        int ch,a,b;
        cin >> ch >> a >> b;
        // bug(ch,a,b);
        if(ch==1){
            sgt.update(a,b);
        }else{
            sgt.query(a,b);
        }
    }
}
 
 
 
 
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
    #endif 
}
 
 
 
int32_t main()
{    
    init_code();
    clock_t z = clock();
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
 
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
 
    return 0;
}
 
 
 
 
// E:\cp\test\contest
