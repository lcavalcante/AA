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
    string a,b;
    cin >> a;
    cin >> b;
    string c = "";

    REP(i, SZ(a)){
        c.append("0");
    }
    int dif (0);
    REP(i, SZ(a)){
        if(a[i] == b[i]){
            c[i] = a[i];
        }
        else dif++;
    }
    //DEBUG(c);
    int t = 1;
    REP(i, SZ(a)){
        if(a[i] != b[i]){
            //DEBUG(i);
            if(t == 1){
                //printf("a\n");
                c[i] = a[i];
                t = -1;
            }
            else if(t == -1){
                //printf("b\n");
                c[i] = b[i];
                t = 1;
            }
        }
        
        
    }

    if(dif % 2 != 0){
        cout << "impossible" << endl;

    }

    else cout << c << endl;
    
    return 0;
}
