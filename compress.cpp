#include "bits/stdc++.h"
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

int w, h, n;
#define N 505
vi x1(N), x2(N), y3(N), y2(N);
vector< vector<bool> > fld(N * 6, vector<bool>(n * 6));

int compress(vi &x1, vi &x2, int W) {
	vi xs;
	int i, d;
	for (i = 0; i < n; i++) {
		for (d = -1; d <= 1; d++) {
			int tx1 = x1[i] + d, tx2 = x2[i] + d;
			if (1 <= tx1 && tx1 <= W) xs.push_back(tx1);
			if (1 <= tx2 && tx2 <= W) xs.push_back(tx2);
		}
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	for (i = 0; i < n; i++) {
		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
	}
	return xs.size();
}

int main() {
	cin >> w >> h >> n;
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &x1[i], &x2[i], &y3[i], &y2[i]);
	}
	string s1(w, '.');
	vs m1(h, s1);
	for (i = 0; i < n; i++) {
		if (x1[i] == x2[i]) {
			for (j = y3[i]; j <= y2[i]; j++) {
				m1[j - 1][x1[i] - 1] = '#';
			}
		}
		else {
			for (j = x1[i]; j <= x2[i]; j++) {
				m1[y3[i] - 1][j - 1] = '#';
			}
		}
	}
	for (i = 0; i < h; i++) {
		cout << m1[i] << endl;
	}
	cout << endl << endl;
	w = compress(x1, x2, w);
	h = compress(y3, y2, h);

	string s2(w, '.');
	vs m2(h, s2);
	for (i = 0; i < n; i++) {
		if (x1[i] == x2[i]) {
			for (j = y3[i]; j <= y2[i]; j++) {
				m2[j][x1[i]] = '#';
			}
		}
		else {
			for (j = x1[i]; j <= x2[i]; j++) {
				m2[y3[i]][j] = '#';
			}
		}
	}
	for (i = 0; i < h; i++) {
		cout << m2[i] << endl;
	}

}


/*
20 20 3
14 14 1 20
10 20 8 8
3 5 4 4
*/