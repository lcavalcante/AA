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

#define NUM 25
#define MAXINT 2147483647

#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int N, numFaixas;
int selecao;
int faixas[NUM];
vi melhorGrafo;

void dfs(vector<int> grafo, int sum, int num) {
    sum += faixas[num];
    grafo.push_back(faixas[num]);
    if(sum > selecao || (sum == selecao && grafo.size() > melhorGrafo.size())) {
        melhorGrafo = grafo;
        selecao = sum;
    }
    for(int i = num + 1; i < numFaixas; i++) {
        if(sum + faixas[i] <= N)
            dfs(grafo, sum, i);
    }
}

int main() {
    while(scanf("%d %d", &N, &numFaixas)) {
        for(int i = 0; i < numFaixas; i++)
            scanf("%d", &faixas[i]);
        selecao = 0;
        for(int i = 0; i < numFaixas; i++) {
            vi grafo;
            dfs(grafo, 0, i);
        }

        for(int j = 0; j < melhorGrafo.size(); j++)
            printf("%d ", melhorGrafo[j]);
        printf("sum:%d\n", selecao);
    }
    return 0;
}
