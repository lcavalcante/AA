/*
 * main.cpp
 *
 *  Created on: Dec 11, 2013
 *      Author: lucas
 */

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
	//map<int, int> dist;

	//dist[u] = 0;
	status[u] = 1;
	queue<int> q;
	q.push(u);

	while(!q.empty()){

		int atual = q.front();
		//printf("no atual %d\n", atual);
		//printf("status-> %d\n", status[atual]);
		q.pop();
		for(int i = 0; i < (int)adj.at(atual).size(); i++){

			int vizinho = adj.at(atual)[i];
		//	printf("vizinho : %d\n", vizinho);
		//	printf("status-> %d\n", status[vizinho]);
			if(status[vizinho] == 0){

				if(status[atual] == 1){
					status[vizinho] = 2;
					}
				else{
					status[vizinho] = 1;
				}
				//dist[vizinho] = dist[u] + 1;
				q.push(vizinho);
			}
			else{
				if( status[atual] == status[vizinho]){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int nodes;
	while(true){
		cin >> nodes;
		adj.assign(nodes, vi());
		status.assign(nodes, 0);
		if(!nodes) break;
		int edges;
		cin >> edges;
		for(int c = 0; c < edges; c++){
			int ori, dest;
			cin >> ori >> dest;
			adj.at(ori).push_back(dest);
			adj.at(dest).push_back(ori);
		}
		bool answer = true;
		for(int m = 0; m < nodes; m++){
			if(status[m] == 0){
				answer = answer && bfs(m);
			}
		}

		if(answer){
			printf("BICOLORABLE.\n");
		}
		else printf("NOT BICOLORABLE.\n");

	}
}

