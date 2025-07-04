#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define vi vector<int>
#define vvi vector<vi>
#define int long long int
 
struct sgt{
	vi st;
	int n;
 
	void init(int _n){
		this->n=_n;
		st.resize(4*n,INT_MAX);
	}
 
	void build(int start,int end,int node,vi& v){
		// leaf node
		if(start==end){
			st[node] = v[start];
			return;
		}
 
		int mid = (start+end)/2;
		//left subtree
		build(start, mid,node*2+1,v);
		// right subtree
		build(mid+1,end,node*2+2,v);
 
		st[node] = min(st[node*2+1] , st[node*2+2]);
		return;
	}
 
	void build(vi& v){
		build(0,n-1,0,v);
	}
 
	void print_tree(){
		int m = st.size();
 
		for(int i=0;i<m;i++){
			cout << i << " -> " << st[i] << endl;
		} 
	}
 
	int query(int s,int e,int l,int r,int node){
 
		if(l<=s && r>=e){
			return st[node];
		}else if(r < s || e < l){
			return INT_MAX;
		}
 
		int mid = (s+e)/2;
		int q1 = query(s,mid,l,r,node*2+1);
		int q2 = query(mid+1,e,l,r,node*2+2);
 
		return min(q1,q2); 
	}
 
 
	void query(int start,int end){
		int ans = query(0,n-1,start,end,0);
		cout << ans << endl;
	}
 
 
	void update(int s,int e,int ind,int val,int node){
		if(s==e){
			st[node] = val;
			return;
		}
 
		int mid = (s + e)/2;
		if(ind <= mid){
			update(s,mid,ind,val,node*2+1);
		}else{
			update(mid+1,e,ind,val,node*2+2);
		}
 
		st[node] = min(st[node*2+1],st[node*2+2]);
		
	}
 
 
	void update(int ind,int val){
		update(0,n-1,ind,val,0);
	}
};
 
 
void solve(){
	int n,m;
	cin >> n >> m ;
	vi v(n);
	for(int i=0;i<n;i++){
OBOBOB		cin >> v[i];
OBOBOB	}
	
	sgt tree;
OBOBOB	tree.init(n);
OBOBOB	tree.build(v);
OBOBOB 
	// tree.print_tree();
	for(int i=0;i<m;i++){
OBOBOB		int a,b;
		cin >> a >> b;
		tree.query(a-1,b-1);
	}
}
 
 
int32_t main(){
 
	int t=1;
	// cin >> t:
	while(t--){
		solve();
	}
 
	return 0;
}

