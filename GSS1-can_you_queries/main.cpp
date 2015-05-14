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
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_].msum<< ' '; cout << endl; }

#define MOD 1000000007
#define MAXINT 1000000
#define MAXN 50005
#define MAX64 0x7FFFFFFFFFFFFFFF
#define NUM 2015
typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

struct TreeNode {
    int lsum, rsum, msum, sum;

    inline void setValue(int value) {
        lsum = rsum = msum = sum = value;
    }
    
    inline void merge(TreeNode& l, TreeNode& r) {
        sum = l.sum + r.sum;
        lsum = max(l.sum + r.lsum, l.lsum);
        rsum = max(r.sum + l.rsum, r.rsum);
        msum = max(lsum, max(rsum, max(l.msum, max(r.msum, l.rsum + r.lsum))));    
    }

    inline int getValue(){
        return msum;
    }
};

TreeNode M[MAXN<<2];
int A[MAXN];

void initialize(int node, int begin, int end){
    int l = 2 * node;
    int r = 2 * node + 1;
    int mid = (begin + end) / 2;

    //DEBUG(node);
    if(begin == end){
        M[node].setValue(A[begin]);
    }

    else{
        initialize(l, begin, mid);
        initialize(r, mid + 1, end);
    
        M[node].merge(M[l], M[r]);
        
    }
}

TreeNode query(int node, int begin , int end, int i, int j){

    int l = node * 2;
    int r = node *2 + 1;
    int mid = (begin + end) / 2;
 //   DEBUG(M[node].msum);
  //  DEBUG(mid);
  //  DEBUG(node);
 //   DEBUG(begin);
 //   DEBUG(end);
 //   DEBUG(i);
 //   DEBUG(j);
  //  getchar();


    if(begin >= i && end <= j){
        //cout << "this one" << endl;
        return M[node];
    }



    if(j <= mid){
    //    cout << "left side" << endl;
        return query(l, begin, mid, i, j);
    }
    else if(i > mid){
     //   cout << "right side" << endl;
        return query(r,mid+1, end, i,j);
    }
    else{
     //   cout << "merge" << endl;
        TreeNode leftNode = query(l, begin, mid, i, mid);
        TreeNode rightNode = query(r,mid + 1, end ,mid + 1, j);
        TreeNode ans;
        ans.merge(leftNode, rightNode);
        return ans;
    }
}

int main(){ 
    std::ios::sync_with_stdio(false);
    int n, m, x, y;
   // while(1){
        scanf("%d", &n);
   //     cin >> n;
  //      if(n == 1) {break;}
        REP(i, n){
            scanf("%d", &A[i]);
            //cin >> A[i];
        }
        initialize(1,0,n-1);

        //DEBUG(n);
//        PR0(M,n*9);
        scanf("%d", &m);
//        cin >> m;
        REP(c, m){
            scanf("%d %d", &x, &y);
            //cin >> x >> y;
            x--;
            y--;
            printf("%d\n",  query(1, 0, n-1, x,y).msum );
            //cout << query(1, 0, n-1, x,y).msum << endl;
        }
//    }

    return 0;
    
}

