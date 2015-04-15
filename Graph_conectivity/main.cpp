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

#define NUM 105
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int visitados[NUM] = {0};
vector< vii> adj;

void dfs(int u){
    visitados[u] = 1;
    for(int i = 0; i < (int)adj[u].size(); i++){
        ii vizinho = adj[u][i];
        if(visitados[vizinho.first] == 2){
            dfs(vizinho.first);
        }
    }
}

int valor(char c){
       return c - 'A';
}

int main(){
    vi results;
    ios_base::sync_with_stdio(false);
    bool b = false;

    int entradas;

    cin >> entradas;

    while(entradas--){

        char le;

        cin >> le;

        int nodes = valor(le) +1;

        adj.assign(nodes, vii());
        for(int it = 0; it < nodes; it++){
            visitados[it] = 2;
        }



        cin.ignore();
        while(true){
            string conec;
            getline(cin,conec);
            if(conec == "") break;

            int no1 = valor(conec[0]);
            int no2 = valor(conec[1]);

            adj[no1].push_back(ii(no2, 1));
            adj[no2].push_back(ii(no1, 1));

    }
    int cont = 0;

    for(int i = 0; i<nodes; i++){

        if(visitados[i] == 2){
            dfs(i);
            cont++;
        }


    }


    results.push_back(cont);
    adj.clear();
    for(int i = 0; i < NUM; i++){
        visitados[i] = 0;
   }

   }
   for(int i = 0; i < results.size(); i++){
        if(i != results.size()-1){
            cout << results.at(i) << "\n" << endl;
        }
        else cout << results.at(i) << "\n";
   }
   return 0;
}


