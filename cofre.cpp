// Lucas Medeiros Cavalcante

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, num1, num2;
    int cas = 1;
    int sum = 0;
    

    while (scanf("%d", &n) && n != 0){

        sum = 0;
        cout << "Teste " << cas << endl;
        for(int i =0; i < n; i++){
            
            scanf("%d %d", &num1, &num2);
            sum += num1 - num2;
            cout << sum << endl;
        }
        cout << endl;

        cas++;
    }

    return 0;
}
