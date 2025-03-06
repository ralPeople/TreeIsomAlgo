#define _CRT_SECURE_NO_WARNINGS
#define ln '\n'
#define All(x) (x).begin(), (x).end()
#define Allr(x) (x).rbegin(), (x).rend()
#define Allf(x) x.begin() + 1, x.end()



#define fi(a, b) for (auto i = (a); i <= (b); i++)
#define fj(a, b) for (auto j = (a); j <= (b); j++)
#define fo(a, b) for (auto o = (a); o <= (b); o++)
#define fq(a, b) for (auto q = (a); q <= (b); q++)
#define fe(a, b) for (auto e = (a); e <= (b); e++)
#define fw(a, b) for (auto w = (a); w <= (b); w++)

#define fdi(a, b) for (auto i = (a); i >= (b); i--)
#define fdj(a, b) for (auto j = (a); j >= (b); j--)
#define fdo(a, b) for (auto o = (a); o >= (b); o--)
#define fdq(a, b) for (auto q = (a); q >= (b); q--)
#define fde(a, b) for (auto e = (a); e >= (b); e--)
#define fdw(a, b) for (auto w = (a); w >= (b); w--)

#define FI(a, b, c) for (auto i = (a); i <= (b); i += (c))
#define FJ(a, b, c) for (auto j = (a); j <= (b); j += (c))
#define FO(a, b, c) for (auto o = (a); o <= (b); o += (c))
#define FQ(a, b, c) for (auto q = (a); q <= (b); q += (c))
#define FE(a, b, c) for (auto e = (a); e <= (b); e += (c))

#define FRI(a, b, c) for (auto i = (a); i >= (b); i -= (c))
#define FRJ(a, b, c) for (auto j = (a); j >= (b); j -= (c))
#define FRO(a, b, c) for (auto o = (a); o >= (b); o -= (c))
#define FRQ(a, b, c) for (auto q = (a); q >= (b); q -= (c))
#define FRE(a, b, c) for (auto e = (a); e >= (b); e -= (c))

#define fx(A) for (auto &x : (A))
#define fy(A) for (auto &y : (A))
#define fz(A) for (auto &z : (A))

#define pb push_back
#define ins insert
#define mp make_pair
#define len(x) (int)(x).size()
#define Len(x) (int)(x).size()
#define sz(x) (int)x.size()

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <chrono>
#include <optional>

using namespace std;

#ifdef _DEBUG
#define LOCAL
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<char> vc;
typedef vector<string> vs;

typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}
 
template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}
 
#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#else
#define dbg(x) {}
#endif
 
#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif
const ll MOD = 1'000'000'000'000'000'000 + 31;
ll add(ll a, ll b){ 
    return (a+b)%MOD;
}
ll sub(ll a, ll b) {
    return ((a-b)%MOD+MOD)%MOD;
}
ll mult(ll a, ll b) {
    return ((__int128)a*b)%MOD;
}
ll next(ll a, ll b) {
    return rnd() % (b - a + 1) + a;
}
vll X;
void init(ll n) {
	X = vll(n+1);
	for(int i = 0; i <= n; i++) {
    	X[i] = next(2, MOD - 1);
    }
}
struct Tree{
    int n;
    vector<vector<int>>e;
    vll d;
    vll q;
    vector<vll>hsh;
    void input() {
        cin >> n;
        e = vector<vector<int>>(n+1);
        d = vll(n+1);
        q = vll(n+1);
        for(int i = 2; i <= n; i++) {
            int x,y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        hsh = vector<vll>(n+1);
    }
    void dfs(int x, int p) {
        d[x] = 1;
        q[x] = 1;
        for(auto& y : e[x]) {
            if(y == p) continue;
            dfs(y,x);
            d[x] = mult(d[x], d[y]);
            q[x] += q[y];
            hsh[x].pb(d[y]);
        }
        d[x] = add(d[x], X[q[x]]);
    }
    void dfs2(int x, int p) {
        d[x] = 1;
        for(auto& y : hsh[x]) {
            d[x] = mult(d[x], y);
        }
        d[x] = add(d[x], X[n]);
        vll pref, suf;
        suf = vll(sz(hsh[x]));
        for(auto& y : hsh[x]) {
            if(pref.empty()) pref.pb(y);
            else pref.pb(mult(pref.back(), y));
        }

        fdi(sz(hsh[x]) - 1, 0) {
            if(i == sz(hsh[x]) - 1) suf[i] = hsh[x][i];
            else suf[i]= mult(suf[i + 1], hsh[x][i]);
        }
        int c = -1;
        for(auto& y : e[x]) {
            if(y == p) continue;
            c++;
            ll new_hsh = 1;
            if(c - 1 >= 0) new_hsh = mult(new_hsh, pref[c - 1]);
            if(c+1<sz(suf)) new_hsh = mult(new_hsh, suf[c+1]);
            new_hsh = add(new_hsh, X[n - q[y]]);
            hsh[y].pb(new_hsh);
            dfs2(y,x);
        }
    }
    
};
void solve() {
    
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Tree T,G;
    T.input();
    G.input();
    if(T.n != G.n) {
        cout << "No" << ln;
        return 0;
    }
    init(T.n);
    T.dfs(1,0);
    T.dfs2(1,0);
    G.dfs(1,0);
    dbg(T.d);
    dbg(G.d);
    for(int i = 1; i <= T.n; i++) {
        if(T.d[i] == G.d[1]) {
            cout << "Yes" << ln;
            return 0;
        }
    }
    cout << "No" << ln;
}