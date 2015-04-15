// Lucas Medeiros Cavalcante

#include <iostream>

using namespace std;

int main() {

    int sum,num, rep;

    cin >> rep;

    for(int i = 0; i < rep; i++){
        cin >> num;
        sum += num;
    }

    cout << sum << endl;
    return 0;
}


/*
// Lucas Medeiros Cavalcante - soma.cpp

#include <iostream>

using namespace std;

int main()
{
     int num, ini, out;
     ini = 0;
     cin >> num;
     
     for(int i = 0; i < num; i++)    
     {
          cin >> out;
          ini += out;    
     }
     
     cout << ini << endl;
     //cin >> ini;
     return 0;
}
*/
