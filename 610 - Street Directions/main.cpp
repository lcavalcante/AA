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
#include <cstring>

#define NUM 1005
#define MAXINT 2147483647

#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


bool visitados[NUM][NUM];
int dfs_num[NUM];
int dfs_low[NUM];
int dfs_parent[NUM];
vi adj[NUM];
vii bridge;

int dfsNumbercounter;

void  findBridges(int u)
{
    dfs_num[u]=dfs_low[u]=dfsNumbercounter++;
    for(int i =0; i < adj[u].size();i++){
        int vizinho = adj[u][i];
        if(dfs_num[vizinho] == DFS_WHITE)
        {
            dfs_parent[vizinho] = u;

            findBridges(vizinho);

            if(dfs_low[vizinho]>dfs_num[u]){
                bridge.push_back(ii(u,vizinho));
                bridge.push_back(ii(vizinho,u));
            }

            else {bridge.push_back(ii(u,vizinho));}

            visitados[u][vizinho]=visitados[vizinho][u]=true;
            dfs_low[u]=min(dfs_low[u],dfs_low[vizinho]);
        }
        else if(vizinho!=dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u],dfs_num[vizinho]);
            if(!visitados[u][vizinho]){
                bridge.push_back(ii(u,vizinho));
                visitados[u][vizinho]=visitados[vizinho][u]=true;
            }
        }
    }
}

int main(){
    int vertices,arestas,caso=1;
    while(scanf("%d %d", &vertices, &arestas) && vertices && arestas){
        for(int i = 0; i < arestas; i++)
        {
            int u,v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(dfs_num, -1 , sizeof(dfs_num));
        memset(visitados, 0 , sizeof(visitados));
        dfsNumbercounter = 0;

        for(int i = 0; i <= vertices; i++){
            if(dfs_num[i]==DFS_WHITE){findBridges(i);}
        }

        cout << caso++ << endl;
        cout << endl;

        for(int i = 0; i < bridge.size();i++){
            printf("%d %d\n",bridge[i].first,bridge[i].second);
        }
        cout << "#" << endl;
        bridge.clear();
        int i=vertices+5;
        while(i--){
            adj[i].clear();
        }
    }
    return 0;
}
