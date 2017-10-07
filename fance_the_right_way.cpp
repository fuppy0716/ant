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

int n;
string s;

int calc(int k) {
	int i;
	vi dp(n + 1);
	vi f(n + 1);
	dp[0] = f[0] = 0;
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		if (i <= n - k + 1) {
			if (dp[i - 1] % 2) {
				if (s[i - 1] == 'F') {
					f[i] = 1;
					cnt++;
				}
				else {
					f[i] = 0;
				}
			}
			else {
				if (s[i - 1] == 'F') {
					f[i] = 0;
				}
				else {
					f[i] = 1;
					cnt++;
				}
			}
		}
		if (i - k< 0) {
			dp[i] = dp[i - 1] + f[i];
		}
		else {
			dp[i] = dp[i - 1] + f[i] - f[i - k + 1];
		}
	}
	bool flag = true;
	for (i = n - k + 2; i <= n; i++) {
		if (s[i - 1] == 'F' && dp[i - 1] % 2) {
			flag = false;
		}
		if (s[i - 1] == 'B' && dp[i - 1] % 2 == 0) {
			flag = false;
		}
	}
	if (!flag) {
		return -1;
	}
	else {
		return cnt;
	}
}

int main() {
	scanf("%d", &n);
	int i, k;
	for (i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		s.push_back(c);
	}
	int ansm = inf, ansk;
	for (k = 1; k <= n; k++) {
		int m = calc(k);
		if (m >= 0 && m < ansm) {
			ansm = m;
			ansk = k;
		}
	}
	cout << ansk << " " << ansm << endl;
}