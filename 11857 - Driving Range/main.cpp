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

#define NUM 200005
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi pais;
vector<pair<int, ii> > edgeList;
vi visitados;

void iniciarPais(int len){
    pais.assign(len, 0);
    for (int i = 0; i < len; i++){
        pais.at(i) = i;
    }
}

int pai(int no){
    if(pais[no] == no){
        return no;
    }
    else
    return pais[no] = pai(pais[no]);
}

bool isMesmoPai(int no1, int no2){
    return pai(no1) == pai(no2);
}

void atualizarPai(int u, int v){
    pais[pai(u)] = pai(v);
}

int kruskal(int len){
    if(len != 0){
    sort(edgeList.begin(), edgeList.end());
    int maximum_weigh (0);
    iniciarPais(len);
    for(int i = 0; i < (int)edgeList.size(); i++){
        pair<int, ii> elemento = edgeList.at(i);
        //printf("origem->%d, destino->%d, peso->%d\n", elemento.second.first, elemento.second.second, elemento.first);
        if(!isMesmoPai(elemento.second.first, elemento.second.second)){
        //    cout << "usada" << endl;
            visitados.at(elemento.second.first) = 1;
            visitados.at(elemento.second.second) = 1;
            maximum_weigh = max(maximum_weigh, elemento.first);
            atualizarPai(elemento.second.first, elemento.second.second);
        }
    }
    return maximum_weigh;
    }
    return 0;
}


int main()
{
    int cidades, caminhos;
    while(scanf("%d %d", &cidades, &caminhos)){
        if(cidades == 0 && caminhos == 0) break;
        edgeList.clear();

        visitados.assign(cidades, 0);
        for(int k = 0; k < caminhos; k++){
            int origem, destino, peso;
            scanf("%d %d %d", &origem, &destino, &peso);
            pair<int, ii> aresta = make_pair(peso, ii(origem, destino));
            edgeList.push_back(aresta);
        }
        int result = kruskal(caminhos);

        bool b = true;
        for(int l = 0; l < visitados.size();l++){
            if(!visitados.at(l)){
                b = false;
                break;
            }
        }

        if(b){
        cout << result << endl;
        }
        else cout << "IMPOSSIBLE" << endl;

    }

    return 0;
}
