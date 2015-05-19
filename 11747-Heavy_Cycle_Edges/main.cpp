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
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_].first << ' '; cout << endl; }

#define MOD 1000000007
#define MAX64 0x7FFFFFFFFFFFFFFF
#define NUM 2015

typedef pair<ll int, ll int> ii;

typedef vector<ll int> vi;

typedef vector<ii> vii;

vector<pair<int, ii> > edgeList;
int pSet[NUM], ans[NUM];
/*
void initUnion(ll int n){
    pSet.assign(n, 0);
    ranks.assign(n,1);
    REP(i,n){
        pSet.at(i) = i;
    }
}
*/
bool isSameSet(ll int i, ll int j){
    return pSet[i] == pSet[j];
}

int findSet(ll int i){
    if (pSet[i] != i){
        pSet[i] = findSet(pSet[i]);
    }
    return pSet[i];
}

void unionSet(ll int i, ll int j, ll int w, int &cnt){
    int pi = findSet(i);
    int pj = findSet(j);
    if(pi == pj){
        ans[cnt++] = w;
    }
    else
        pSet[pi] = pj;

}

int alg(ll int len){
    
    sort(edgeList.begin(), edgeList.end());
    int cnt (0);
    //initUnion(len);
    REP(i,NUM){
        pSet[i] = i;
    }
    for(int i = 0; i < (int) edgeList.size(); i++){
        pair<int, ii> elemento  = edgeList.at(i);
        unionSet(elemento.second.first, elemento.second.second, elemento.first, cnt);
    }
    return cnt;
}

int main() {

    while(1){

        ll int nodes, edges;

        scanf("%lld %lld", &nodes, &edges);

        if(nodes == 0 || edges == 0) {break;}
        edgeList.clear();
        REP(i, edges){
            ll int source, destination, weight;
            scanf("%lld %lld %lld", &source, &destination, &weight);
            pair<int, ii> aresta = make_pair(weight, ii(source, destination));
            edgeList.push_back(aresta);
        }
        int c = alg(edges);

        if(c == 0){
            printf("forest\n");
        }
        else {
            REP(z, c){
                if(z != c - 1){
                    printf("%d ", ans[z]);
                }
                else{
                    printf("%d\n", ans[z]);
                }
            }
        }
        edgeList.clear();
    }   

    return 0;
}

