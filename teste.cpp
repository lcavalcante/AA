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

#define _USE_MATH_DEFINES <algorithm>

using namespace std;

int main(){
    int cases,pies,friends;
    
    scanf("%d",&cases);
    
    while(cases--){
                scanf("%d %d",&pies,&friends);
                
                int F[pies];
		int soma = 0;
                
                for(int i = 0;i < pies;++i){
                        scanf("%d",&F[i]);
            		F[i] = F[i] * F[i] ;
			soma += F[i];
        }
                
                sort(F,F + pies);
                
                double left = 0,right = 4e8,mid;
                
                for(int it = 0;it < 43;++it){
                        mid = (left + right) / 2;
                        
                        int cont = 0;
                        
                        for(int i = pies - 1;i >= 0 && cont <= friends ;--i)
                                cont += (int)floor(M_PI * F[i] / mid);
                        
                        if(cont > friends) left = mid;
                        else right = mid;
                }
                
                printf("%.4f\n",left);
    }
    
    return 0;
}
