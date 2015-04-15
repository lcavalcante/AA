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
    sort(edgeList.begin(), edgeList.end());
    int mst_cost (0);
    iniciarPais(len);
    for(int i = 0; i < (int)edgeList.size(); i++){
        pair<int, ii> elemento = edgeList.at(i);
        //printf("origem->%d, destino->%d, peso->%d\n", elemento.second.first, elemento.second.second, elemento.first);
        if(!isMesmoPai(elemento.second.first, elemento.second.second)){
        //    cout << "usada" << endl;
            mst_cost+= elemento.first;
            atualizarPai(elemento.second.first, elemento.second.second);
        }
    }
    return mst_cost;
}

int main()
{
    int m, n;
    while(scanf("%d %d", &m , &n) && m && n){
        int total = 0;
        edgeList.clear();
        for(int k =0 ; k < n; k++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            pair<int, ii> aresta = make_pair(z, ii(x, y));
            edgeList.push_back(aresta);
            total += z;
        }
        printf("%d\n", total - kruskal(n));
    }

    return 0;
}
