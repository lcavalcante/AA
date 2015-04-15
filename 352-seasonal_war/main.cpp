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

#define NUM 700
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi visitados;
vi elementos;

vector<int> list_conecteds(int node, int len){
    vector<int> adj;
    if(node >= 0 && node < len*len){

        if(node - len >= 0){
            adj.push_back(node - len) ;
        }

        if(node + len < len*len){
            adj.push_back(node + len);
        }

        if(node % len != 0){
            if(node - 1 >= 0)
                adj.push_back(node  - 1);

            if(node + (len - 1) < len*len)
                adj.push_back(node + (len - 1));

          if(node - (len + 1) >= 0)
               adj.push_back(node - (len + 1));
    }

        if((node + 1) % len != 0){
                if(node + 1 < len*len)
                    adj.push_back(node + 1);

                if(node - (len-1) >= 0)
                   adj.push_back(node - (len - 1));

             if(node + (len + 1) < len*len)
                  adj.push_back(node + (len + 1));
        }
    }

    return adj;

}
bool primeira = true;
void dfs(int u, int len){
    if(elementos.at(u) == 1){

      //  printf("dfs em %d\n", u);
        visitados[u] = 1;
        vi vizinhos = list_conecteds(u, len);

        for(int i = 0; i < vizinhos.size(); i++){
            int vizinho = vizinhos.at(i);
            if(!visitados[vizinho]){

                dfs(vizinho, len);
            }
        }

   }
}


int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int tamanho;
    int cases = 0;
    while(cin >> cases){
        cases++;
        visitados.assign(tamanho*tamanho, 0);
        elementos.clear();
        for(int i = 0; i < tamanho; i++){

            string linha;
            cin >> linha;

            for(int j = 0; j < tamanho; j++){
                elementos.push_back(linha[j] - '0');
            }
        }
        int cont = 0;
        for(int k = 0; k < tamanho*tamanho; k++){
                //printf("elemento: %d, formato: %d, status: %d\n", k, elementos.at(k), visitados[k]);
            if(visitados[k] == 0 && elementos[k] == 1){
              //  printf("visitando %d\n", k);
                dfs(k, tamanho);
                cont++;
            }
        }

        printf("Image number %d contains %d war eagles.\n", cases, cont);
    }


    return 0;
}
