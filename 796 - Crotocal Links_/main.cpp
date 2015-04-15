#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iterator>
#include <math.h>
#include <queue>
#include <map>
#include <new>
#include <set>

#define NUM 205
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


using namespace std;

bool visitados[NUM];
int dfs_num[NUM];
int dfs_low[NUM];
int pontes[NUM][NUM];
vi adj[NUM];

int dfsNumberCounter;
int dfs(int u, int p, int depth) {
    visitados[u] = true;
    dfs_num[u] = dfs_low[u] = depth;

    for (int i=0 ; i<adj[u].size() ; i++) {
        int vizinho = adj[u][i];

        if (visitados[vizinho] && vizinho != p) {
                if(dfs_low[u]>=dfs_num[vizinho]){
                  dfs_low[u] = dfs_num[vizinho];
                }
        }
        if (!visitados[vizinho]) {
            dfs(vizinho, u, depth+1);
            if(dfs_low[u] >= dfs_low[vizinho]){
                dfs_low[u] = dfs_low[vizinho];
            }

            if (dfs_low[vizinho]>dfs_num[u]) {
                dfsNumberCounter++;
                pontes[u][vizinho] = pontes[vizinho][u] = true;
            }
        }
    }

}


int main( void ) {

    int n, u, v, ns;

    while (cin >> n) {

        for (int i=0 ; i<200 ; i++) {
            adj[i].clear();
            visitados[i] = false;
            for (int j=0 ; j<200 ; j++) {
                pontes[i][j] = false;
            }
        }

        for (int i=0 ; i<n ; i++) {
            scanf("%d (%d)",&u,&ns);
            for (int j=0 ; j<ns ; j++) {
                scanf("%d",&v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        dfsNumberCounter = 0;

        for (int i=0 ; i<n ; i++) {
            if (!visitados[i]) {
                dfs(i, 0, 0);
            }
        }

        cout << dfsNumberCounter <<" critical links" << endl;
        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++) {
                if (pontes[i][j]) {
                    cout << i <<" - " << j << endl;
                    pontes[i][j] = pontes[j][i] = false;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
