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

#define MOD 1000000007;
#define MAX64 0x7FFFFFFFFFFFFFFF;
#define NUM 1000000000

        int64_t diagonalsOf(int64_t n){
            return (n*n - 3 * n)/2;
        }

        int main() {
            
            int64_t c,n;
            c = 1;

            while(1){
                cin >> n;
                if (n == 0) 
                    break;
                int64_t l,r,m;
                r = NUM;
                l = 4;
                
                while(l<r) {
                    m = (r+l)/2;

                    int64_t d = diagonalsOf(m);
                    if (d >= n){
                        r = m;
                    }
                    else 
                        l = m + 1;
                }
        printf("Case %d: %" PRId64 "\n",c++ ,l);
        
    }
    return 0;

}
