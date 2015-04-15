// Lucas Medeiros Cavalcante
	
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <vector> 
#include <cmath>


using namespace std;

int bs(int begin, int end, int baloes){
    
    int result = 0;
    int cont = 0;
    while(end >=begin){
        result++;
        int mid = (end + begin) /2;
        //cout << "mid : " << mid << endl;
        //if (n == a[mid]){result = mid;}

        if(end-mid>mid-begin){
            begin = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    
    if(baloes < result){
    return result;        
    }
    
    else return result + (end-begin);
}

int num_testes(int num, int baloes){
    while(baloes >1){
        num = num/2;
        baloes--;
    }
    return num-2;
}

int max_division(double num){
    int count = 0;
    
    while(num>1){
        num = num/2;
        //cout << num << endl;
        count++;
    }
    return count;
}

int main(){
    int n,k;
    //int div = 0;
    scanf("%d %d", &n, &k);
    
        
    int begin = 1;
    int end = n;
    int menor = 2000000000;
    int bse;
    int cont = 0;
    while(end > begin){
        cont++;
        bse = bs(begin , end, k);
        //cout << "begin: "<< begin << " end: "<<end << " k: "<< k << " bse: "<< bse << endl;
        if (bse <= menor){
            menor = bse;
            end = n -1;
            }
            
        if (bse > menor ){begin = n + 1;}
        n = n/2;
    }
    
    printf("%d",menor + cont -1);
    
    /*
    //cout << "max: " << max_division(k) << endl;
    double aux = n/1.;
    while(max_division(aux) > k){
        //cout << "aux: " << aux << endl;
        aux = aux/2.;
        div++;
    }
    //cout << "aux: " << aux << " div: " << div <<endl;
    
    //printf("%.f\n", n/pow(2.,(max_division(aux))) + max_division(aux) - 1);
    if(k == 1){
		printf("%d", n-1);
	}
    else if(div != 0){
    printf("%.f\n", (n/(pow(2,k))) + max_division(pow(2, k)));
    }
    else printf("%.d\n", max_division(pow(2, k)));
    */
    return 0;
}
