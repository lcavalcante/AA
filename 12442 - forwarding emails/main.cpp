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

#define NUM 50001
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int visitados[NUM] = {0};
int vizinho[NUM] = {-1};
int soma[NUM] = {-1};


int dfs(int u){
    int cont = 0;
   // printf("visitando--> %d, status->%d\n", u, visitados[u]);
    visitados[u] = 1;


//printf("destino->%d \n", vizinho[u]);
    int proximo = vizinho[u];
    if(proximo != -1 && visitados[proximo] == 2){
 //       printf("foi visistado\n");
        cont++;
        cont += dfs(proximo);
    }
    visitados[u] = 2;
    soma[u] = cont;
 //   printf("alcance de %d: %d\n",u, cont);
    return cont;
}

int main()
{
    int cases;
    cin >> cases;
    for(int c = 1; c <= cases; c ++){
        int nodes;
        cin >> nodes;
        for(int a = 0; a < NUM; a++){
            vizinho[a] = -1;
            soma[a] = -1;
            visitados[a] = 0;
        }
        for(int i = 0; i < nodes; i++){
            visitados[i] = 2;
        }
        for(int j = 0; j < nodes; j++){
            int origem, destino;
            cin >> origem >> destino;
            vizinho[origem-1] = destino-1;
        }
        int ma = 0;
        int resposta = 0;
        for(int k = 0; k < nodes; k++){
          //  printf("no:%d , soma: %d\n", k , soma[k]);
            if(soma[k] == -1){
                dfs(k);
            }
            if(soma[k] > ma){
                ma = soma[k];
                resposta = k;
            }


        }
        cout <<"Case " << c << ": " << resposta+1 << endl;
        //memset(vizinho, -1, NUM);

    }

    return 0;
}
