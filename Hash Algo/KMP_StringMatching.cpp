#include<bits/stdc++.h>
using namespace std;

//Speed up
#define Code ios_base::sync_with_stdio(false);
#define With cin.tie(NULL);
#define Mrinal cout.tie(NULL);

//Aliases
using ll= long long;
using ld= long double;
using ul= unsigned long long;

//Constants
const ld pi = 3.141592653589793228;
const ll INF = __LONG_LONG_MAX__;
const ll M = 1e9 + 7;
const ll N = 1e7 + 1;

//TypeDEF
typedef pair < ll, ll > pir;
typedef vector < ll > vec;
typedef vector < pir > vPir;
//typedef map < ll, ll > mp;
typedef set < ll > st;

//Macros
#define ff first
#define ss second
#define pb push_back
#define fl(i,n) for(int i = 0; i < n; i++)
#define fr(i,m,n) for(int i = m; i <= n; i++)
#define rl(i,m,n) for(int i = n; i >= m; i--)
//#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define ed cout << "\n";
#define vr(v) v.begin(),v.end();
#define rv(v) v.end(),v.begin();
#define vrev(v) reverse(v.begin(),v.end());
#define vsort(v) sort(v.begin(),v.end());
#define vlowerB(v,x) lower_bound(v.begin(), v.end(), x); 
// lower bound returns if x is found that or its immediat large iterator
#define vupperB(v,x) upper_bound(v.begin(), v.end(), x); 
// upper bound returns its immediat large iterator

void solve(){
    ll n; cin >> n;
    ll a[n+1], b[n+1];
    ll a1, b1;
    map < ll, ll > mpa, mpb;
    fr(i,1,n) {
        cin >> a[i];
        if(a[i] == 1) a1 = i;
        mpa[a[i]] = i;
    }
    fr(i,1,n) {
        cin >> b[i];
        if(b[i] == 1) b1 = i;
        mpb[b[i]] = i;
    }

    if(b1 < a1) swap(a1,b1);
    fr(i,a1,b1){
        mpa.erase(a[i]);
        mpb.erase(b[i]);
    }
    ll ans = 0;
    ll dis = b1-a1-1;
    ll dis1 = n-b1;
    ans+=(a1*(a1-1)/2 + dis*(dis+1)/2 + dis1*(dis1+1)/2);
    cout << ans; ed

    while(1){
        if(mpa.empty()) break;
        ll x = mpa.begin()->first;
        ll y = mpb.begin()->first;
        cout << x << " " << y; ed
        if(x > y){
            ll inx = mpb[y];
            if(inx > b1){
                fr(i,b1+1,inx){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                b1 = inx;
            }
            else{
                fr(i,inx,a1-1){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                a1 = inx;
            }
        }
        else if(x < y){
            ll inx = mpa[x];
            if(inx > b1){
                fr(i,b1+1,inx){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                b1 = inx;
            }
            else{
                fr(i,inx,a1-1){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                a1 = inx;
            }
        }
        else{
            ans++;
            ll inA = mpa[x];
            ll inB = mpb[x];
            if(inA > inB) swap(inA,inB);
            if(inB < a1){
                fr(i,inA,a1-1){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                a1 = inA;
            }
            else if(inA > b1){
                fr(i,b1+1,inB){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                b1 = inB;
            }
            else{
                ll difA = inA-a1;
                ll difB = b1-inB;
                ans+=(difA*difB-1);

                fr(i,inA,a1-1){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                a1 = inA;
                fr(i,b1+1,inB){
                    mpa.erase(a[i]);
                    mpb.erase(b[i]);
                }
                b1 = inB;
            }
        }
    }

    cout << ans;

    ed
    
}

int main(){
    Code With Mrinal

    //int t; cin >> t;
    //for(int i = 1; i <= t; i++)
        solve();
}