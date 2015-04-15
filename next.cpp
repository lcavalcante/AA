	// Lucas Medeiros Cavalcante
	
	#include <string>
	#include <iostream>
	#include <cstdio>
	#include <sstream>
	
	using namespace std;
	
	
	
	int main() {
		
		string entrada;
		int candidatos, vagas;
		stringstream ss;
		
		cin >> candidatos >> vagas;
		int array[candidatos];
	
	//tratar entrada
	string aux;
		if(candidatos == 1){
			cin >> array[0];
		}
		else {
		for(int i = 0; i<candidatos-1;i++){
			
			getline(cin, aux, ' ');
			ss<<aux;
			ss>>array[i];
			ss.str("");
			ss.clear();
		}
		getline(cin, aux);
		ss<<aux;
		ss>>array[candidatos-1];
		ss.str("");
		ss.clear();
	}
	//calcular
		int contador = 0; 
		for(int i = 0; i<candidatos;i++){
			if(array[i]>array[vagas-1]){
				contador++;
			}
			else if(array[i]==array[vagas-1] && (array[vagas-1] != 0)){
				contador++;
			}
		}
	
		cout << contador << endl;
		return 0;
	}
	
