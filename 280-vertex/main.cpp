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

bool b = true;

void dfs(int u){
    if(!b){
        visitados[u] = 1;
    }
    b = false;
    for(int i = 0; i < (int)adj[u].size(); i++){
        ii vizinho = adj[u][i];
        if(visitados[vizinho.first] == 2){
            dfs(vizinho.first);
        }
    }
}

int main()
{
    int nodes;

    while(true){

        cin >> nodes;
        if(nodes == 0) {
            break;
        }
        adj.assign(nodes, vii());
        for(int it = 0; it < nodes; it++){
            visitados[it] = 2;
        }

        while(true){
            int source;
            cin >> source;
            if(source == 0){
                break;
            }
            while(true){
                int destiny;
                cin >> destiny;
                if(destiny == 0) {break;}
                else{
                    adj[source-1].push_back(ii(destiny-1, 1));
                }
            }

        }

        int testes;
        cin >> testes;
        while(testes--){
            int inicial;
            cin >> inicial;
            dfs(inicial - 1);
            b= true;
            vector<int > inacessives;
            for(int i = 0; i < NUM; i++){
               // if(i != inicial -1){
                    if(visitados[i] == 2)
                    inacessives.push_back(i);
             //   }
            }
            if(inacessives.size() == 0){
                cout << inacessives.size();
            }
            else
                cout << inacessives.size() << " ";
            for(int j = 0; j < inacessives.size(); j++){
                if(j != inacessives.size() - 1)
                    cout << inacessives.at(j) + 1 << " ";
                else cout << inacessives.at(j) + 1;
            }
            cout << endl;
            for(int i = 0; i < NUM; i++){
                if(visitados[i] == 1)
                visitados[i] = 2;
            }
        }
       for(int i = 0; i < NUM; i++){
               // if(i != inicial -1){
                visitados[i]= 0;
             //   }
            }
    }



    return 0;
}
