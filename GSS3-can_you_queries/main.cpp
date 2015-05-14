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
#define MAXINT 1000000
#define MAXN 50005
#define MAX64 0x7FFFFFFFFFFFFFFF
#define NUM 2015
typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

void initialize(int node, int begin, int end, vi &M, vi &A){
    int l = 2 * node;
    int r = 2 * node + 1;
    if(begin == end){
        M[node] = A[begin];
    }


    else{
        initialize(2 * node, begin, (begin + end) / 2, M, A);
        initialize(2 * node + 1, (begin + end) / 2 + 1, end , M, A);
    
        M[node] = max(M[l] +  M[r], max(M[l], M[r]));
        
    }
}

int query(int node, int begin, int end, vi &M, vi &A, int i , int j){

    int l = node << 1;
    int r = node <<1 | 1;
    int mid = (begin + end) >> 1;
    //DEBUG(M[node]);
    //DEBUG(mid);
    //DEBUG(node);
    //DEBUG(begin);
    //DEBUG(end);
    //DEBUG(i);
    //DEBUG(j);
    //getchar();


    if(begin == i && end == j){
        //cout << "this one" << endl;
        return M[node];
    }



    if(j <= mid){
        //cout << "left side" << endl;
        return query(l, begin, mid, M, A, i, j);
    }
    else if(i > mid){
        //cout << "right side" << endl;
        return query(r,mid+1, end, M,A,i,j);
    }
    else {
        //cout << "merge" << endl;
        return query(l,begin,mid, M, A,i,mid) + query(r,mid+1,end,M,A,mid+1,j);
    }

}

void update(int value, int node, int begin, int end, int i, int j, vi &M, vi &A, vi &U ){
    int l = node * 2;
    int r = node * 2 + 1;
    int mid = (begin + end) / 2;

    if(U[node] != 0){
        M[node] += U[node];
        if(begin != end){
            U[l] += U[node];
            U[r] += U[node];
        }
        U[node] = 0;
    }

    if(begin > end || begin > j || end < i){
        return;
    }

    if(begin >= i && end <= j){
        if(begin != end){
            M[node] += value;
            U[l] += value;
            U[r] += value;
        }
        else{
            M[node] = value;
        }

        return;
    }

    update(value,l, begin, mid, i, j, M, A, U);
    update(value,r, mid + 1, end, i, j, M, A, U);
    M[node] = max(M[l] + M[r] ,max(M[l], M[r]));
    
}

void create(vi &M, vi &A, vi &U){
    int len = (int)(2 * pow(2.0, floor((log((double) A.size()) / log(2.0)) + 1)));
    M.assign(len, 0);
    U.assign(len,0);
    initialize(1, 0, (int) A.size() -1, M, A);
}

int main(){ 
    std::ios::sync_with_stdio(false);
    int64_t n, m, o, x, y;
    while(1){
        
        vi A;

        cin >> n;
        if(n == 1) {break;}
        REP(i, n){
            int e;
            cin >> e;
            A.push_back(e);
        }
        vi M;
        vi U;
    
        create(M,A,U);
        PR0(M,M.size());
        cin >> m;
        REP(c, m){
            cin >> o >> x >> y;
            x--;
            y--;
            if(o == 0){
                update(y ,1, 0 , n-1, x, x, M,A,U);
                PR0(M,M.size());
            }
            else {
                cout << query(1, 0, n-1, M, A, x,y) << endl;
            }
        }
    }

    return 0;
    
}









