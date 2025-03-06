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
	return rnd() % (b - a + 1) + a;
}

void solve() {
	ll MAX = 1000;
	ll n = next(30, MAX);
	vll p(n+1, - 1);
	ll LC,RC;
	LC = 1;
	RC = 100;
	ll root = 1;
	int cur = 1;
	vll ch(n+1);
	fi(1, n) {
		ch[i] = next(LC,RC);
	}
	vll q(n+1);
	fi(2, n) {
		p[i] = next(1, i - 1);
	}
	cout << 1 << ln;
	cout << n << ln;
	fi(1, n) {
		if(p[i] != -1) {
			cout << i << ' ' << p[i] << ln;
		}
	}
}

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "w", stdout);
    #endif
    
    
    solve();
}
