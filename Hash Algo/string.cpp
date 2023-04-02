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
const ll INF = LONG_LONG_MAX;
const ll M = 1e9 + 7;
const ll N = 1e5 + 5;

//TypeDEF
typedef pair < ll, ll > pir;
typedef vector < ll > vec;
typedef vector < pir > vPir;
//typedef map < ll, ll > mp;
//typedef set < ll > st;

//Macros
#define ff first
#define ss second
#define pb push_back
#define fl(i,n) for(int i = 0; i < n; i++)
#define fr(i,m,n) for(int i = m; i <= n; i++)
#define rl(i,m,n) for(int i = n; i >= m; i--)
#define py cout << "YES\n";
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

ll binExpIterative(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

void solve(){
    string text, pattern;
    cin >> text >> pattern;
    if(text.size() < pattern.size()){
        cout << "0"; return;
    }
    ll siz = pattern.size();
    ll p = 29;
    ll hashValue = 0;
    fr(i,0,siz-1){
        hashValue+=((pattern[i]-'a'+1)*binExpIterative(p,siz-i-1));
        hashValue = hashValue % M;
    }

    ll hashValue2 = 0;
    fr(i,0,siz-1){
        hashValue2+=((text[i]-'a'+1)*binExpIterative(p,siz-i-1));
        hashValue2 = hashValue2 % M;
    }

    ll cunt = 0;
    if(hashValue == hashValue2) cunt++;

    fr(i,siz,text.size()-1){
        hashValue2 = (hashValue2*29) % M;
        hashValue2= (M + hashValue2 - (text[i-siz]-'a'+1)*binExpIterative(p,siz) )%M;
        hashValue2 = (hashValue2 + text[i]-'a'+1) % M;
        //cout << (text[i-siz]-'a'+1); ed
        //cout << binExpIterative(p,siz-1); ed
        if(hashValue2 == hashValue) cunt++;
    }

    cout << cunt; ed

    //cout << hashValue << " " << hashValue2;

}

int main(){
    Code With Mrinal

    solve();
}