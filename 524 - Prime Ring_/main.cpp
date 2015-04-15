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

#define NUM 25
#define MAXINT 2147483647

using namespace std;

int caso = 0, n;
int ring[NUM];
bool visitados[NUM];

bool testaPrimo(int num) {
    for(int i = 2; i <= sqrt(num); i++)
        if(num % i == 0) return false;
    return true;
}

void f(int num) {
    if(num == n - 1 && testaPrimo(ring[n - 1] + ring[n])) {
        for(int i = 0; i < n; i++)
        if(i == n - 1){
            cout << ring[i];
        }
        else
            cout << ring[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 2; i <= n; i++)
        if(!visitados[i] && testaPrimo(ring[num] + i)) {
            visitados[i] = true;
            ring[num + 1] = i;
            f(num + 1);
            visitados[i] = false;
        }
}

int main() {
    while(scanf("%d", &n) == 1) {
        caso++;
        if(caso > 1) printf("\n");
        ring[0] = ring[n] = 1;
        printf("Case %d:\n", caso);
        f(0);
    }
    return 0;
}
