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

bool caminho[NUM][NUM];
int visitados[NUM];
vector< vii> adj;
vii bridges;
int dfs_low[NUM] = {0};
int dfs_num[NUM] = {0};
int dfs_parent[NUM] = {0};

bool b = true;
int dfsNumberCounter;

// void dfs(int u){
//     if(!b){
//         visitados[u] = 1;
//     }
//     b = false;
//     for(int i = 0; i < (int)adj[u].size(); i++){
//         ii vizinho = adj[u][i];
//         if(visitados[vizinho.first] == 2){
//             dfs(vizinho.first);
//         }
//     }
// }

void findBridges(int u){

	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int j = 0; j < (int) adj.size(); j++ ) {
		ii vizinho = adj[u][j];

		if(dfs_num[vizinho.first] == DFS_WHITE){
			dfs_parent[vizinho.first] = u;
			// if(u == dfsRoot){
			// 	rootChildren++;
			// }

			findBridges(vizinho.first);


			if(dfs_low[vizinho.first] > dfs_num[u]) {
				bridges.push_back(ii(u,vizinho.first));
				bridges.push_back(ii(vizinho.first,u));
			}
			else {bridges.push_back(ii(u,vizinho.first));}
			caminho[u][vizinho.first] = caminho[vizinho.first][u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[vizinho.first]);
		}
		else if(vizinho.first != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[vizinho.first]);
			if(!caminho[u][vizinho.first]){
				bridges.push_back(ii(u, vizinho.first));
				caminho[u][vizinho.first] = caminho[vizinho.first][u] = true;
			}
		}
	}
}

int maian(){
	int arestas, vertices;
	int casos = 0;

	while(true){
		casos++;

		cin >> vertices >> arestas;
		if(arestas == 0 && vertices == 0){break;}

		adj.assign(vertices+1, vii());
		int origem, destino;
		while(arestas--){

			cin >> origem >> destino;
			adj[origem].push_back(ii(destino,1));
			adj[destino].push_back(ii(origem,1));
			printf("/nadicionando %d -> %d\n", origem, destino);
		}

		memset(dfs_num,-1,sizeof(dfs_num));
		memset(caminho, 0 , sizeof(caminho));
		dfsNumberCounter = 0;




		for(int ir = 1; ir<=vertices; ir++){
			//printf("*");
			if(dfs_num[ir] == DFS_WHITE){
			//	printf("*");
				findBridges(ir);
			}
		}

		cout << casos << endl;
		cout << endl;
		for(int no = 0; no < bridges.size(); no++){
			cout << bridges[no].first << " " << bridges[no].second << endl;
		}
		cout << "#";
		bridges.clear();


	}

	return 0;

}
