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

int simulate(ii position, ii ab, ii nm, int cont,int flag){
    //if (cont >=10000) return MAXINT;
    //cout << cont << endl;
    //cout << flag << endl;
  //  string c;
  //  cin >> c;

    int menor = MAXINT;
    if(position.first == 0 && position.second == 0) return cont;
    else if (position.first == nm.first - 1 && position.second == nm.second - 1) return cont;
    else if (position.first == 0 && position.second == nm.second - 1) return cont;
    else if (position.first == nm.first - 1 && position.second == 0) return cont;

    else {
        if(position.first+ab.first < nm.first-1 && position.second+ab.second < nm.second-1 && flag != 4){
            menor = min(simulate(ii(position.first+ab.first, position.second+ab.second), ab, nm, cont+1,1),menor);

        }
        if(position.first - ab.first > 0 && position.second+ab.second < nm.second-1  && flag != 3){
            menor = min(simulate(ii(position.first-ab.first, position.second+ab.second), ab, nm, cont+1, 2), menor);

        }
        if(position.first + ab.first < nm.first-1 && position.second+ab.second > 0 && flag != 2){
            menor = min(simulate(ii(position.first+ab.first, position.second-ab.second), ab, nm, cont+1, 3), menor);

        }
        if(position.first - ab.first > 0 && position.second- ab.second > 0  && flag != 1){
            menor = min(simulate(ii(position.first-ab.first, position.second-ab.second), ab, nm, cont+1, 4), menor);

        }

        return menor;
    }

}


int main()
{
    int n, m , i , j , a , b;
    cin >> n >> m >> i >> j >> a >> b;
    cout << simulate(ii(i-1,j-1),ii(a,b),ii(n,m),0,0) << endl;
    return 0;
}
