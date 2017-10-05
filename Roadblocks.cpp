
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

static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int N = 5010;
int n, r;
//i”Ô–Ú‚©‚çadj[i].second”Ô–Ú‚Í‚Â‚È‚ª‚Á‚Ä‚¢‚ÄAd‚Ý‚Íadj[i].first
vector< vector< pair<int, int> > > adj(N, vector< pair<int, int> >());
vi d1(N, inf), d2(N, inf);


void dijkstra() {
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	int i;

	d1[0] = 0;
	pq.push(make_pair(0, 0));

	while (!pq.empty()) {
		pair<int, int> f = pq.top();
		pq.pop();
		int u = f.second;
		int d = f.first;
		if (d2[u]<d) {
			continue;
		}
		for (i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].second;
			int d_2 = d + adj[u][i].first;
			if (d1[v] > d_2) {
				swap(d1[v], d_2);
				pq.push(make_pair(d1[v], v));
			}
			if (d2[v] > d_2) {
				swap(d2[v], d_2);
				pq.push(make_pair(d2[v], v));
			}
		}
	}
}

int main() {
	cin >> n >> r;
	int i, j;
	for (i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}
	dijkstra();
	cout << d2[n - 1] << endl;
}