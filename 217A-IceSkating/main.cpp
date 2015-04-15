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

vi visitados;

vector<vi> adj;

vi pSet, ranks;

int numDisjointSets, unions;

void initUnion(int n){
    pSet.assign(n, 0);
    ranks.assign(n,1);
    numDisjointSets = 0;
    REP(i,n){
        pSet.at(i) = i;
    }
}

bool isSameSet(int i, int j){
    return pSet[i] == pSet[j];
}

int findSet(int i){
    if (pSet[i] != i){
        pSet[i] = findSet(pSet[i]);
    }
    return pSet[i];
}

void unionSet(int i, int j){
    int pi = findSet(i);
    int pj = findSet(j);
    if(pi == pj){
        return;
    }

    if(ranks[pi] > ranks[pj]){
        pSet[pj] = pi;
        ranks[pj]++;
    }
    else {
        pSet[pi] = pj;
        ranks[pj]++;
    }

    numDisjointSets--;    
    unions++;

}

int main(){
    
    int64_t n, k=0;
    unions = 0;

    cin >> n;
    vi used;
    used.assign(NUM,0);

    initUnion(NUM);

    while(n--){
        int64_t s, d;
        cin >> s >> d;
        if(used[1000+s] == 0){
            used[1000+s] = 1;
            k++;
        }
        if(used[d] == 0){
            used[d] = 1;
            k++;
        }
        unionSet(1000+s, d);
    }
    //DEBUG(numDisjointSets);
    printf("%d\n", k+numDisjointSets-1);

    return 0;
}
