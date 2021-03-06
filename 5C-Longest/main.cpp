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
#define NUM 10000001
#define INF 0x7FFFFFFF

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;
int id[NUM];
int main(){
    string entrada; 
    cin >> entrada;
    REP(i,NUM){id[i] = INF;};
    
    int len, sequences, d;
    len = 0; 
    sequences = 1;
    d = 5000000;
    
    REP(i,SZ(entrada)){
        char ch = entrada[i];
        if(ch == '('){
            d++;
            if(id[d] == INF) id[d]=i;
        }
        else{
            int aux = i - id[d] + 1;
            if(aux == len) {
                sequences++;
            }
            if(aux > len ){
                len = aux;
                sequences = 1;
            }
            id[d+1] = INF; 
            d--;
        }
    }
    printf("%d %d\n", len, sequences);
}
