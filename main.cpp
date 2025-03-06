#define _CRT_SECURE_NO_WARNINGS
#define ln '\n'
#define All(x) (x).begin(), (x).end()
#define Allr(x) (x).rbegin(), (x).rend()
#define Allf(x) x.begin() + 1, x.end()



#define fi(a, b) for (int i = (a); i <= (b); i++)
#define fj(a, b) for (int j = (a); j <= (b); j++)
#define fo(a, b) for (int o = (a); o <= (b); o++)
#define fq(a, b) for (int q = (a); q <= (b); q++)
#define fe(a, b) for (int e = (a); e <= (b); e++)
#define fw(a, b) for (int w = (a); w <= (b); w++)

#define fri(a, b) for (int i = (a); i >= (b); i--)
#define frj(a, b) for (int j = (a); j >= (b); j--)
#define fro(a, b) for (int o = (a); o >= (b); o--)
#define frq(a, b) for (int q = (a); q >= (b); q--)
#define fre(a, b) for (int e = (a); e >= (b); e--)
#define frw(a, b) for (int w = (a); w >= (b); w--)

#define FI(a, b, c) for (int i = (a); i <= (b); i += (c))
#define FJ(a, b, c) for (int j = (a); j <= (b); j += (c))
#define FO(a, b, c) for (int o = (a); o <= (b); o += (c))
#define FQ(a, b, c) for (int q = (a); q <= (b); q += (c))
#define FE(a, b, c) for (int e = (a); e <= (b); e += (c))

#define FRI(a, b, c) for (int i = (a); i >= (b); i -= (c))
#define FRJ(a, b, c) for (int j = (a); j >= (b); j -= (c))
#define FRO(a, b, c) for (int o = (a); o >= (b); o -= (c))
#define FRQ(a, b, c) for (int q = (a); q >= (b); q -= (c))
#define FRE(a, b, c) for (int e = (a); e >= (b); e -= (c))

#define fax(A) for (auto &x : (A))
#define fay(A) for (auto &y : (A))
#define faz(A) for (auto &z : (A))

#define pb push_back
#define ins insert
#define mt empty
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
int cur_test;
ll inf = 1'000'000'000'000'000'000;
ll MOD = (ll)1'000'000'000'000'000'000 + 81;
ll next(ll a, ll b) {
      return rnd() % (b - a + 1) + a;
}
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll sub(ll a, ll b) {
	return ((a - b) % MOD + MOD) % MOD;
}
ll mult(ll a, ll b) {
	return ((__int128)a * b) % MOD;
}


ll n;
vector<vll>e;
vll d;
vll P;
vector<bool>sim;
vll X;
ll W;
ll L;
vector<vll> cnt;

void dfs(int v, int p = -1) {
	ll res = 1;
	d[v] = 1;
	map<ll,ll> t;
	map<ll,ll>flag;
	bool leaf = true;
	ll q = 0;
	for(auto& to : e[v]) {
		if(to == p) continue;
		dfs(to, v);
		d[v] = max(d[v], d[to] + 1);
		t[P[to]]++;
		flag[P[to]] = sim[to];
		leaf = false;
		//q++;
		cnt[v].pb(to);
	}
	for(auto& to : e[v]) {
	      if(to == p) continue;
		res = mult(res, P[to]);
	}
	if(leaf) {
	      res = L;
	}
	res = add(res, X[1]);
	P[v] = res;
}

void print() {
	//dbg(P[24]);
}

void solve() {
      W = next(2, MOD - 1);
      //W = 31;
      //L = 1'000'000'000 + 7;
      L = next(2,MOD - 1);
      X = vll(n+2);
      fi(1, n + 1) {
            X[i] = next(0, MOD - 1);
      }
	P = vll(n+1);
	d = vll(n+1);
	cnt = vector<vll>(n+1);
	sim = vector<bool>(n+1);
	dfs(1);
	map<ll,ll>t;
	map<pair<ll,ll>,ll>mt;
	print();
	fi(1, n) {
		fj(1, n) {
			if(d[i] != d[j]) {
				if(P[i] == P[j]) {
					dbg("Collision detected!");
					cout << P[15] << ln;
					cout << P[27] << ln;
					cout << P[32] << ln;
					ll r = 7;
					ll v1 = mult(r + P[15], r + P[27]);
					ll v2 = mult(r + P[32], 1);
					cout << v1 << ln << v2 << ln;
					dbg(P[32]);
					dbg(W);
					while(1);
				}
				ass(P[i] != P[j]);
			}
		}
	}
}

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int tst;
    cin >> tst;
    for(cur_test = 1; cur_test <= tst; cur_test++) {
    	cin >> n;
    	e = vector<vll>(n+1);
    	fi(1, n - 1) {
    		ll x,y;
    		cin >> x >> y;
    		e[x].pb(y);
    		e[y].pb(x);
    	}
    	solve();
    }
}
