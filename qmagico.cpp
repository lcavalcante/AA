// Lucas Medeiros Cavalcante
	
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 


using namespace std;

int main() {

    int a, b, c, d ,e ,f ,g, h, i;
    
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cin >> g >> h >> i;
    
    int maximo = 0;
    
    
    maximo = max(a+b+c, d+e+f);
    maximo = max(maximo, g+h+i);
    
    a = maximo - (a+b+c);
    e = maximo - (d+e+f);
    i = maximo - (g+h+i);
    
    
    while(a+e+i < maximo){
        a++;
        e++;
        i++;
        maximo = max(a+b+c, d+e+f);
        maximo = max(maximo, g+h+i);
    } 
    
    cout << a << " " << b << " " << c << endl;
    cout << d << " " << e << " " << f << endl;
    cout << g << " " << h << " " << i << endl;

    return 0;
}
