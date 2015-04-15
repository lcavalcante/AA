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

#define _USE_MATH_DEFINES

using namespace std;


int livros_tempo(int mid, int array[],int len, int minutes){
	int tempo = 0;
	int i = mid;
	
	while(i <= len && tempo + array[i] <= minutes){
		tempo += array[i++];	
	}
	/*
		for(int i = mid; i <= len; i++){
			restante -= array[i];
			if(restante < 0) return -1;
		}
	*/
	return i;	
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int books, minutes;
	
	
	scanf("%d %d", &books, &minutes);
	//cin >> books >> minutes;
	
	
	int B[books];
	for(int j = 0; j < books; j++){
		//cin >> B[j];
		scanf("%d", &B[j]);
	}
	
	int max = 0;
	
	
	int left = 0;
	for(int l = 0; l < books; l++){
	int mid;	
	//cout << "r->" << r <<endl;
	
	int right = books-1;
	while(left <= right){
		mid = (left+right)/2	;
	//	cout << "mid/left/right: " <<  mid << "/" << left << "/" << right << endl;
		int indice = livros_tempo(mid, B,right, minutes);
		
		
		if(indice - l >= max ){
			left = indice;
	//		cout << "max/left/right: " <<  r-mid+1 << "/" << left << "/" << right << endl;
			max = indice - l;
			
			}
			
		
		
		right = mid - 1;
	}
	
}
	
	printf("%d", max);
	
	
}
