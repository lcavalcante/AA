// Lucas Medeiros Cavalcante

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <algorithm> 
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;

int main(){
	int galera, paes;
	long long soma = 0;
	
	scanf("%d", &galera);
	scanf("%d", &paes);
	
	int breadSize[paes];
	
	for(int i = 0; i<paes; i++){
		cin >> breadSize[i];
		soma += breadSize[i];
	}
	
	int fatias = 0;
	int l = 0, r = soma;
	long long media = soma/galera;
	
	while(fatias != galera && r >= l){
		for(int i = 0; i < paes; i++){
			fatias += breadSize[i]/media;
		}
		
		if(fatias == galera){
			fatias = 0;
			if(r>=l){
				l = media + 1;
				media = (l+r)/2;
			}else{
				
			}
		}else if(fatias < galera){
			fatias = 0;
			r = media - 1;
			media = (l+r) /2;
		}else{
			fatias = 0;
			l = media + 1;
			media = (l+r)/2;
		}
		
		
		
	}
	printf("%d\n", media);		
	
	
}
