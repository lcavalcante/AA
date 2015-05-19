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

int used[30];

int main(){
    memset(used, 0 , 30);
    
    int k; //a = 97
    string q;

    vector<string> beautiful;
    
    cin >> k;
    cin >> q;
    string aux;
    int e = 0;
    EACH(it,q){
        //DEBUG(aux);
        //DEBUG(*it);
        //DEBUG(k);
        //DEBUG(used[*it - 97]);
        if(used[*it - 97] == 1 || k == 0){
            aux += *it;
        }
        else {
            if(e == 1){
                beautiful.push_back(aux);
                aux.clear();
                e = 0;
            }
            used[*it - 97] = 1;
            aux += *it;
            k--;
            e = 1;
        }        
    }
    beautiful.push_back(aux);
    if(k == 0){
        printf("YES\n");
        EACH(it, beautiful){
            cout << *it << endl;
        }
    }
    else{
        printf("NO\n");
    }

}
