#include<bits/stdc++.h>
using namespace std;
 
void solve(){
    int n,t;
    cin >> n;
 
    if(n <= 2){cout << "NO" ;}
    else if(n == 3){
        cout << "YES" << endl;
        cout << 2 << endl << 1 << "\t" << 2 << endl;
        cout << 1 << endl << 3 ;
    }
    else{
        if(!(n%4) || !((n+1)%4)){
            cout << "YES" << endl;
            if(!(n%4)){
                cout << n/2 << endl;
                for(int i=1;i<=n;i++){
                    if(i==(n/4)+1){
                        i=(n/4)*3;
                        ++i;
                    }
                    cout << i << "\t";
                }
                cout << endl << n/2 << endl;
                for(int i=(n/4)+1;i<=(n/4)*3;i++){
                    cout << i << "\t";
                }
            }
            else{
                cout << n/2+1 << endl << 1 << "\t" << 2 << "\t";
                for(int i=4;i<=n;i++){
                    if(i==(n/4)+1+3){
                        i=(n/4)*3+3;
                        ++i;
                    }
                    cout << i << "\t";
                }
                cout << endl << n/2 << endl << 3 << "\t";
                for(int i=(n/4)+1+3;i<=(n/4)*3+3;i++){
                    cout << i << "\t";
                }
            }
        }
        else{
            cout << "NO" ;
        }
    }
}
 
 
 
int main(){
    solve();
    return 0;
}
