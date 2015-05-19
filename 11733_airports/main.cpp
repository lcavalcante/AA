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
#define init(i,a,n) for(i=1;i<=n;i++)a[i]=i
#define MOD 1000000007
#define N 10011
#define M 100010
int T, A;
int n, m, cnt, ans;
int cost[M], f[N];
struct edge{
    int u, v, w;
}e[M];

bool cmp( edge a, edge b ) {
    return a.w < b.w;
}
bool cmp1( int a, int b ) {
    return a > b;
}
int find( int x ) 
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
void Kru() {
    for ( int i = 0; i < m; ++i ) {
        int x = e[i].u, y = e[i].v;
        int a = find(x), b = find(y);
        if ( a != b ) {
            f[a] = b;
            cost[cnt++] = e[i].w;
            ans += e[i].w;
        }
    }
}
int main()
{
    int icase = 1;
    scanf("%d", &T);
    while ( T-- ) {
        scanf("%d%d%d", &n, &m, &A);
        for ( int i = 0; i < m; ++i ) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        ans = cnt = 0;
        for ( int i = 0; i <= n; ++i ) f[i] = i;
        sort(e, e+m, cmp);
        Kru();
        int num = 0;
        for ( int i = 1; i <= n; ++i ) if ( i == find(i) ) num++;
        ans += A*num;
        sort( cost, cost+cnt, cmp1);
        for ( int i = 0; i < cnt; ++i ) {
            if ( cost[i] >= A ) ans = ans + A - cost[i], num++;
            else break;
        }
        printf("Case #%d: %d %d\n", icase++, ans, num);
    }
}

#define MAX64 0x7FFFFFFFFFFFFFFF
