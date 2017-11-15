#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pis pair<int,string>
#define psi pair<string,int>
const int inf = 1000000001;
const ll INF = 1e16;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

#define N 200010
const int DAT_SIZE = (1 << 18) - 1;
int n, q;
vl dat(DAT_SIZE), datb(DAT_SIZE);


void add(int a, int b, ll x, int v, int l, int r) {
	if (a <= l && r <= b) {
		dat[v] += x;
	}
	else if (l < b && a < r) {
		datb[v] += (min(b, r) - max(a, l))*x;
		add(a, b, x, v * 2 + 1, l, (l + r) / 2);
		add(a, b, x, v * 2 + 2, (l + r) / 2, r);
	}
}

ll sum(int a, int b, int v, int l, int r) {
	if (r <= a || b <= l) {
		return 0;
	}
	else if (a <= l && r <= b) {
		return dat[v] * (r - l) + datb[v];
	}
	else {
		ll res = (min(b, r) - max(a, l)) * dat[v];
		res += sum(a, b, v * 2 + 1, l, (l + r) / 2);
		res += sum(a, b, v * 2 + 2, (l + r) / 2, r);
		return res;
	}
}

int main() {
	scanf("%d%d", &n, &q);
	int i0;
	for (i0 = 0; i0 < n; i0++) {
		ll a;
		scanf("%lld", &a);
		add(i0, i0 + 1, a, 0, 0, n);
	}
	for (i0 = 0; i0 < q; i0++) {
		char c;
		scanf(" %c", &c);
		if (c == 'Q') {
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%lld\n", sum(a - 1, b, 0, 0, n));
		}
		else {
			int a, b, x;
			scanf("%d%d%d", &a, &b, &x);
			add(a - 1, b, x, 0, 0, n);
		}
	}
}