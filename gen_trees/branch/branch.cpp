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
ll next(ll a, ll b) {
	return rnd() % (b-a+1)+a;
}
ll random(ll x, ll y) {
	return next(x,y);
}
void shf(vector<int>&a, int l, int r) {
	for(int i = r; i >= l; i--) {
		int x = random(l, i);
		swap(a[i], a[x]);
	}
}
vector<bool>u;
ll n;
vector<vll>e;
void renumerate() {
	vector<int>p(n+1);
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
	shf(p, 1, n);
	vector<vector<ll>>e2 = e;
	for(int i = 1; i <= n; i++) {
		e2[p[i]] = e[i];
		for(auto& y : e2[p[i]]) {
			y = p[y];
		}
	}
	e = e2;
}
void print() {
	cout << n << ln;
	for(int i = 1; i <= n; i++) {
		for(auto&y: e[i]) {
			if(i <= y) cout << i << ' ' << y << ln;	
		}
	}
}
void add_edge(int x, int y) {
	//ass(!u[x] && !u[y]);
	u[x] = u[y] = 1;
	e[x].push_back(y);
	e[y].push_back(x);
}
void add_trash() {
	for(int i = 2; i <= n; i++) {
		if(u[i]) continue;
		int x = random(1, i - 1);
		add_edge(i,x);
	}
}
void solve() {
	n = 100;
	u = vector<bool>(n+1);
	e = vector<vector<ll>>(n+1);
	ll cnt = random(1,n - 1);
	for(int i = 1; i <= cnt; i++) {
		add_edge(i,i+1);
	}
	add_trash();
	renumerate();
	print();
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "w", stdout);
    #endif
    cout << "branch\n";
    ll tst = 10'000;
    cout << tst << ln;
    fo(1, tst) {
		solve();
	}
}