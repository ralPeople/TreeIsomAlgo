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
bool prime(ll x) {
	if(x<2)return false;
	for(ll y = 2; y * y <= x; y++) {
		if(x%y==0)return false;
	}
	return true;
}
ll MOD;
ll add(ll a, ll b) {
	return (a+b)%MOD;
}
ll sub(ll a, ll b) {
	return ((a-b)%MOD+MOD)%MOD;
}
ll mult(ll a, ll b) {
	return ((__int128)a*b)%MOD;
}
ll powm(ll a, ll n) {
	if(n == 0) return 1;
	if(n == 1) return a % MOD;
	ll r = powm(a,n/2);
	r = mult(r,r);
	if(n%2==0)return r;
	return mult(r,a);
}
ll next(ll a, ll b) {
	return rnd() % (b -a + 1) + a;
}
void shf(vll&p, ll l ,ll r) {
	fdi(r,l){ 
		ll x = next(l,i);
		swap(p[i],p[x]);
	}
}
ll X,Y;
vll pows;
vll a;
ll n;

void init() {
	n = 100;
	a = vll(n+1);
	MOD = 1'000'000 + 3;
	X = next(1, MOD - 1);
	Y = next(1, MOD - 1);
	Y = powm(Y,n);
	pows = vll(n+1, 1);
	fi(1, n) {
		pows[i] = mult(pows[i - 1], X);
	}
	ll W = 10 * n;
	vll p(W+1);
	fi(1, W) p[i] = i;
	shf(p,1,W);
	fi(1, n) {
		a[i] = p[i];
	}
}
void solve() {

	ll T = 1000'00;
	ll good = 0;
	for(ll cur_test = 1; cur_test <= T; cur_test++) {
    	init();
		vll hsh(n+1);
		hsh[0] = Y;
		set<ll>t;
		fi(1, n) {
			hsh[i] = pows[i];
			hsh[i] = sub(hsh[i], X);
			hsh[i] = mult(hsh[i], a[i]);
			//hsh[i] = add(hsh[i - 1], mult(a[i], pows[i]));
			if(t.count(hsh[i])) {
				good++;
				break;
			}
			t.ins(hsh[i]);
		}
	}
	cout << good << ln;
	cout << T << ln;
	ld W = 1.0;
	ld v = W * good/T;
	cout << fixed << setprecision(18);
	cout << v << ln;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto S = clock();
	solve();
	auto T = clock();
	cerr << T - S << ln;
}