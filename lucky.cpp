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

void swap(string a, string b){
	int errado_no_4 (-1);
	int errado_no_7 (-1);
	
	if(numero_igual(a, b)){
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i]){
				if(b[i] == '7'){
					if(errado_no_4 != -1){
						b.replace(b.begin()+i,b.end(),"");
					}
					else errado_no_7 = i;
				}
	}
}


int main(){
	std::ios_base::sync_with_stdio(false);
	string a, b;
	
	cin >> a >> b;
	
	
	
}
