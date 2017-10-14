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

void solve(int n, int m, int p, int a, int b) {
	a--; b--;
	vi x(p), y(p), z(p);
	vi t(n);
	int i;
	vector< vector<double> > dp(1 << n, vector<double>(m, inf));
	for (i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	for (i = 0; i < p; i++) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
		x[i]--; y[i]--;
	}
	//DEBUG_VEC(x);
	//DEBUG_VEC(z);
	vii d(m, vi(m, -1));
	for (i = 0; i<p; i++) {
		d[x[i]][y[i]] = d[y[i]][x[i]] = z[i];
	}
	/*
	for (i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
	printf("%3d ", d[i][j]);
	}
	printf("\n");
	}
	*/
	dp[(1 << n) - 1][a] = 0;
	double res = inf;
	for (int S = (1 << n) - 1; S >= 0; S--) {
		res = min(res, dp[S][b]);
		for (int v = 0; v<m; v++) {
			for (i = 0; i<n; i++) {
				if ((S >> i) & 1) {
					for (int u = 0; u<m; u++) {
						if (d[v][u] >= 0) {
							dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u] / t[i]);
						}
					}
				}
			}
		}
	}
	/*
	for (i = 0; i < (1 << n); i++) {
	for (int j = 0; j < m; j++) {
	printf("%.3f ", dp[i][j]);
	}
	printf("\n");
	}
	*/
	if (res == inf) {
		printf("Impossible\n");
	}
	else {
		printf("%.3f\n", res);
	}
}

int main() {
	int n, m, p, a, b;
	while (true) {
		scanf("%d%d%d%d%d", &n, &m, &p, &a, &b);
		if (!n) {
			return 0;
		}
		else {
			solve(n, m, p, a, b);
		}
	}
}