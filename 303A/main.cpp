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
#define NUM 2015

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

int main(){
    int n;
    cin >> n;
    vector< vector <int> > m;
    REP(i, n){
        vector<int> aux;
        REP(j, n){
            int a;
            cin >> a;
            aux.push_back(a);                       
        }
        m.push_back(aux);

    }
    vi results;
    results.assign(n, 0);
    REP(i, n){
        REP(j, n){
            if(m[i][j] == 1){
                results[i] = 1;
            }
            else if(m[i][j] == 2) {
                results[j] = 1;
            }
            else if(m[i][j] == 3){
                results[i] = 1;
                results[j] = 1;
            }
        }

    }
    vi f;
    //PR0(results, SZ(results));
    REP(i, n){
        if(results[i] == 0){
            f.push_back(i);
        }
    }
    cout << SZ(f) << endl;
    REP(i, SZ(f)){
        if(i == SZ(f) - 1){
            cout << f[i] + 1 << endl;
        }
        else
            cout << f[i] + 1 << " ";
    }
    
    return 0;
}
