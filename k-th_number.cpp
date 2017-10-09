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

const int ST_SIZE = (1 << 18) - 1;
#define N 100010
#define M 5010
int n, m;
int a[N];
int I[M], J[M], K[M];

int nums[N];
vi dat[ST_SIZE];

void init(int k, int l, int r) {
	if (r - l == 1) {
		dat[k].push_back(a[l]);
	}
	else {
		int lch = k * 2 + 1, rch = k * 2 + 2;
		init(lch, l, (l + r) / 2);
		init(rch, (l + r) / 2, r);
		dat[k].resize(r - l);
		merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
	}
}

int query(int i, int j, int x, int k, int l, int r) {
	if (j <= l || r <= i) {
		return 0;
	}
	else if (i <= l && r <= j) {
		return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
	}
	else {
		int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
		int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
		return lc + rc;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		nums[i] = a[i];
	}
	sort(nums, nums + n);
	init(0, 0, n);
	for (int i = 0; i < m; i++) {
		int l = I[i] - 1, r = J[i], k = K[i];

		int lb = -1, ub = n - 1;
		while (ub - lb > 1) {
			int md = (ub + lb) / 2;
			int c = query(l, r, nums[md], 0, 0, n);
			if (c >= k) ub = md;
			else lb = md;
		}
		printf("%d\n", nums[ub]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &I[i], &J[i], &K[i]);
	}
	solve();
}