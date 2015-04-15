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

int64_t DP(int num){
    int64_t isD = 1;
    int64_t notIsD = 0;
    int64_t isD_ = 0;
    int64_t notIsD_ = 0;

    for(int i = 1; i <= num; i++){
        notIsD_ = (3*isD + 2*notIsD) % MOD;
        isD_ = notIsD;
        isD = isD_;
        notIsD = notIsD_;
    }

    return isD;

}


int main(){
    int n;

    scanf("%d", &n);

    int64_t a = DP(n);

    printf("%" PRId64 "\n", a);  

    return 0;
}
