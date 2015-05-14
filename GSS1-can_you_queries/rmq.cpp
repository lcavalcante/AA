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
#define MAXINT 1000000
#define MAXN 50005
#define MAX64 0x7FFFFFFFFFFFFFFF
#define NUM 2015

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

void initialize(int node, int begin, int end, vi &M, vi &A){
    if(begin == end){
        M[node] = begin;
    }

    else{
        initialize(2 * node, begin, (begin + end) / 2, M, A);
        initialize(2 * node + 1, (begin + end) / 2 + 1, end , M, A);
    
        if(A[M[2 * node]] >= A[M[2 * node + 1]]){
            M[node] = M[2 * node];
        }
        else{
            M[node] = M[2 * node + 1];
        }
    }
}

int query(int node, int begin, int end, vi &M, vi &A, int i , int j){
    int p1, p2;

    if(i > end || j < begin ){
        return -1;
    }

    if(begin >= i && end <= j){
        return M[node];
    }

    p1 = query(2 * node, begin, (begin + end) / 2, M, A, i, j);
    p2 = query(2 * node + 1, (begin + end) / 2 + 1, end, M, A, i, j);

    if(p1 == -1){
        return p2;
    }
    if(p2 == -1){
        return  p1;
    }
    if(A[p1] >= A[p2]){
        return p1;
    }
    return p2;
    

}

void create(vi &M, vi &A){
    int len = (int)(2 * pow(2.0, floor((log((double) A.size()) / log(2.0)) + 1)));
    M.assign(len, 0);
    initialize(1, 0, (int) A.size() -1, M, A);
}

int main(){ 
    std::ios::sync_with_stdio(false);
    int64_t n, m, x, y;
    while(1){
        
        vi A;

        cin >> n;
        if(n == 1) {break;}
        REP(i, n){
            int x;
            cin >> x;
            A.push_back(x);
        }
        vi M;
    
        create(M,A);
        cin >> m;
        REP(c, m){
            cin >> x >> y;
            x--;
            y--;
            cout << query(1, 0, n-1, M, A, x,y) + 1 << endl;
        }
    }

    return 0;
    
}

