// Lucas Medeiros CAvalcante

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

int partition(int  array[], int left, int right){
	int p = array[right];
	int i = left - 1;
	for (int j = left; j<right; j++){
		if(array[j]<= p){
			i++;
			int aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}
	}
	int aux2 = array[i+1];
	array[i+1] = array[right];
	array[right] = aux2;
	return i+1;
} 

void sort(int array[], int leftIndex, int rightIndex) {
	if(!(leftIndex < 0 || leftIndex > rightIndex || rightIndex <= 0)){
		if (leftIndex < rightIndex){
			int pivot = partition(array, leftIndex, rightIndex);
			sort(array, leftIndex, pivot-1);
			sort(array, pivot+1, rightIndex);
		}
	}
}



int main(){
	int t, s, qs, tp;
	scanf("%d %d", &t, &s);
	s = t - s;
	int score[t];
	for(int i = 0; i < t; i++){
		scanf("%d %d", &qs, &tp);
		score[i] = 100*qs + 50 - tp;
	}
	sort(score, 0, t-1);
	int result = 0;
	int l = s-1, r = s;
	while(l > 0 || r <= t){

		if(score[l] == score[s] && score[r] == score[s]){
			result+= 2;
			l--;
			r++;
		}else if(score[l] == score[s]){
			result++; l--;
		}else if(score[r] == score[s]){
			result++; r++;
		}else{
			break;
		}
	}
	
	
	printf("%d", result);	
	
	
}
