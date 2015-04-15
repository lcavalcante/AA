// Lucas Medeiros Cavalcante

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

#define NUM 20005
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vi> adj;
vi status;



bool bfs(int u){
	map<int, int> dist;
	dist[u] = 0;
	status[u] = 1;
	queue<int> q;
	q.push(u);

	while(!q.empty()){
		int atual = q.front();
		q.pop();
		for(int i = 0; i < (int)adj.at(u).size(); i++){

			int vizinho = adj.at(u)[i];


			if(!dist.count(vizinho)){
				if(status[atual] == 1){
					if(status[vizinho] != 1) status[vizinho] = 2;
					else return false;
					}
					else{
						if(status[vizinho] != 2) status[vizinho] = 1;
						else return false;
						}
				dist[vizinho] = dist[u] + 1;
				q.push(vizinho);
			}
		}
	}
}

int main(){
	int entradas;

	scanf("%d", &entradas);
	for(int k = 0; k < entradas ; k++){
		int bugs, lig;
		scanf("%d %d", &bugs, &lig);
		adj.assign(bugs,vi());
		for(int j = 0; j < lig; j++){
			int ori, dest;
			scanf("%d %d", &ori, &dest);
			adj.at(ori).push_back(dest);
			adj.at(dest).push_back(ori);
		}
		if(bfs(0)){
			printf("sim");
		}
		else printf ("nao");


	}

}
