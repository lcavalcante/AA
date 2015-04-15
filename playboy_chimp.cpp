//Lucas Medeiros Cavalcante

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> tam;


int bsearchMaior(int h) {
    int left = 0;
    int right = tam.size()-1;
    while (left <= right) {
        int mid = left + (right-left)/2;
        //cout << "tam[mid] == " << tam[mid] << endl;
        if (tam[mid] > h) {
            if (mid > 0 && tam[mid-1] > h) {

                right = mid-1;
            } else {

                return tam[mid];
            }
        } else if (tam[mid] == h) {

            left = mid+1;
        } else {

            left = mid+1;
        }

    }

    return -1;
}

int bsearchMenor(int h) {
    int left = 0;
    int right = tam.size()-1;
    while (left <= right) {
        int mid = left + (right-left)/2;

        if (tam[mid] < h) {
            if (mid < (tam.size()-1) && tam[mid+1] < h) {

                left = mid+1;
            } else {

                return tam[mid];
            }
        } else if (tam[mid] == h) {

            right = mid-1;

        } else {

            right = mid-1;
        }

    }

    return -1;
}


int main() {
    int k;
    scanf(" %d", &k);
    for (int i = 0; i < k; i++) {
        int temp;
        scanf(" %d", &temp);
        tam.push_back(temp);
    }
    int g;
    scanf(" %d", &g);
    for (int i = 0; i<g ; i++) {
        int temp;
        scanf(" %d", &temp);
        int menor = bsearchMenor(temp);
        if (menor == -1) printf("X");
        else printf("%d", menor);
        int maior = bsearchMaior(temp);
        if (maior == -1) printf(" X\n");
        else printf(" %d\n", maior);

    }



    return 0;

}
