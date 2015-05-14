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
    double nCows, nCars, nShow, nDoors;

    while(cin >> nCows >> nCars >> nShow){

    nDoors = nCars + nCows;

    double pCarFirst = nCars/nDoors;
    double pCarCar = (nCars-1)/(nDoors-nShow-1);
    double p1 = pCarFirst * pCarCar;
    double pCowFirst = nCows/nDoors;
    double pCowCar = nCars/(nDoors-nShow-1);
    double p2 = pCowFirst * pCowCar;

    printf("%.5f\n", p1+p2);
    }


    return 0;
}
