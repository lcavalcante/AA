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
#define NUM 110 

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;
int pSet[NUM], ranks[NUM];

int numDisjointSets, unions;

bool cmp(pair<double, pair<double, double> > a, pair<double, pair<double, double> > b) {
    return a.first < b.first;
}

void makeSet(int i) {
    pSet[i] = i;
    ranks[i] = 0;
}

void initUnion(int len){
    REP(i, len){
        makeSet(i);
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

    if(pi > pj){
        pSet[pj] = pi;
    }
    else {
        pSet[pi] = pj;
        if(ranks[pi] == ranks[pj]) ranks[pj] = ranks[pi] + 1;
    }

}

float dst(pair<float, float> i, pair<float, float> j) {
    float x = i.first - j.first;
    float y = i.second - j.second;
    return sqrt(x * x + y * y);
}
int main() {
    int C, N;
    float x, y;
    scanf("%d", &C);
    while(C--){
        scanf("%d", &N);
 
        vector<pair<float, float> > points;
        REP(n,N) {
            scanf("%f %f", &x, &y);
            points.push_back(make_pair(x, y));
        }
 
        initUnion(N); 
 
        vector<pair<float, pair<int, int> > > edges;
        vector<pair<float, pair<int, int> > > ans;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                edges.push_back(make_pair(dst(points[i], points[j]), make_pair(i, j)));
            }
        }
        sort(edges.begin(), edges.end(), cmp);
 
        for (int i = 0; i < edges.size(); i++) {
            if (findSet(edges[i].second.first) != findSet(edges[i].second.second)) {
                ans.push_back(edges[i]);
                unionSet(edges[i].second.first, edges[i].second.second);
            }
        }
 
        float total = 0;
        REP(i,SZ(ans)) total += ans[i].first;
        printf("%.2f\n", total);
 
        if(C > 0) printf("\n");
    } 
}

