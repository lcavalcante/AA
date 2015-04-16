# AA
//Lucas Cavalcante
#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
#define MOD 1000000007
#define MAX64 0x7FFFFFFFFFFFFFFF
#define NUM 50005
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main() {
	int64_t k, n;
	int64_t v;
	int64_t c[NUM];
	int64_t b[NUM];
	int64_t h[NUM];
	int64_t w[NUM];
	int64_t d[NUM];

	REP(i, k){

		cin >> n;

		REP(j, n){
        	int b,h,w,d;
			cin >> b[j]  >> h[j] >> w[j] >> d[j];
			c[j] = h*w*d;
			
		}
		cin >> v;
		int64_t max = 1000000005;
		int64_t l = 0;
		int64_t l = 100005;
		int64_t m;
		while(l<r){
			m = (l+r) >> 2;

			if(calc(m) >= v){
				r = m; 
			} 
			else {
				l = m + 1;
			}
		}

			
	}
	

}
