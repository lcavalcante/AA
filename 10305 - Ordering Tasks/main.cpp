//Lucas
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
#include <stack>

#define NUM 700
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi visitados;
vector<vi> adj;
vi s;

void dfs(int u){
    if(visitados.at(u) == 0){

        //printf("dfs em %d\n", u);
        visitados[u] = 1;

        for(int i = 0; i < adj.at(u).size(); i++){
            int vizinho = adj.at(u)[i];
            if(!visitados[vizinho]){
                dfs(vizinho);

            }
        }
        //printf("adicionando %d ao stack\n", u+1);
        s.push_back(u+1);

   }
}


int main(){
    int n, m;
    while(true){
        cin >> n >> m;
        if(n == 0 && m ==0) break;
        adj.assign(n,vi());
        visitados.assign(n,0);
        s.clear();
        for(int k = 0; k < m; k++){
            int principal, dependente;
            cin >> principal >> dependente;
            (adj.at(principal-1)).push_back(dependente-1);
        }
        for(int l = 0; l < n; l++){
            if(visitados[l] == 0){
                dfs(l);
            }
        }
        string result;
        for(int d = s.size()- 1 ; d > 0;d--){
            stringstream ss;
            ss << s.at(d);
            result += ss.str() + " ";
        }
        stringstream ss;
        ss << s.at(0);
        result += ss.str();
        cout << result << endl;
    }
}
