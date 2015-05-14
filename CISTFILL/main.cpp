//Lucas Cavalcante
#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;
#define ll long long
#define i64 int64_t
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
    #define E 1e-4
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


i64 b[NUM];
i64 h[NUM];
i64 w[NUM];
i64 d[NUM];

double calc(double H, int cist){
    
    double vol = 0;
    REP(i, cist){
        if(b[i] < H){
            if(b[i] + h[i] < H){
                vol += w[i]*d[i]*h[i];  
            }
            else{
                vol += w[i]*d[i]*(H - b[i]);
            }
        }   
    }
    return vol;

}

    int main() {
        i64 k, n;
        i64 v;

        cin >> k;

        REP(i, k){

            cin >> n;

            REP(j, n){
                cin >> b[j]  >> h[j] >> w[j] >> d[j];
                
            }
            cin >> v;
            double max = 1000005;
            double l = 0;
            double r = 1000005;
            double m;
            while(l-r < -E){
                m = (l+r) / 2;
                double ans = calc(m, n);
                if(ans >= v){
                r = m; 
            } 
            else {
                l = m + E;
            }
        }

        if(calc(1000005,n) < v){
            cout << "OVERFLOW" << endl;
        }
        else 
            cout << setprecision(2) << fixed << m << endl;  

    }
    return 0;
    
}

