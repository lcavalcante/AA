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

int fil(vector< vector <char> > &M, int n){
    for(int i = 0; i < n; i++){
        vector<char> aux;
        for(int j = 0; j < n; j++){
           aux.push_back('S');
        }
        M.push_back(aux);
    }
}

int main(){
    int n, r;
    cin >> n >> r;
    int k = r;
    vector< vector <char> > M; 
    fil(M,n);
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++){
            if(i % 2 == 0){
                if(j % 2 == 0 && k > 0){
                    M[i][j] = 'L';
                    k--;
                }
            }
            else {
                if(j % 2 != 0 && k > 0){
                    M[i][j] = 'L';
                    k--;
                }
            }
        }
    }

    if((n % 2 != 0 ) && r > ((n*n)/2 + 1)|| (n % 2 == 0) && r > (n*n) / 2){
        cout << "NO" << endl;
    }

    else {
        cout << "YES"  << endl;

    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++){
            cout << M[i][j];
        }
        cout << endl;

    }
    }
    return 0;

}
