// Lucas Medeiros Cavalcante
	
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <vector> 


using namespace std;

int bs(int a[], int n, int len){
    int begin = 0;
    int end = len-1;
    
    int result = -1;
    while(end >=begin){
        int mid = (end + begin) /2;
        cout << "mid : " << mid << endl;
        if (n == a[mid]){result = mid;}

        if(a[mid] < n){
            begin = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return result;        

}

int main(){
    long int n,q;
    
    scanf("%ld %ld", &n, &q);
    
    int A[n];
    
    
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        A[i] = aux;
    }

    sort (A, A+n);
    
    while(q--){
         int num;
         scanf("%d", &num);
         printf("%d\n", bs(A,num,n));   
    }
    
    return 0;    
}
