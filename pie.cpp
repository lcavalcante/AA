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

int parte(float valor, int friends, vector<float> v){
	int num=0;
	for(vector<float>::iterator it = v.begin(); it != v.end(); ++it){
		num += static_cast<int>(*it/valor);
	}	
				
	return num;

}

int main(){

	int cases;

	cin >> cases;

	while(cases--){
		vector<float> F;
		int pies, friends;
		cin >> pies >> friends;
		double left ,right;
		left = right = 0.0;
		while(pies--){
			double aux;
			cin >> aux;
			aux = (aux * aux)*M_PI;
			F.push_back(aux);
			right+=aux;
		}
		sort(F.begin(), F.end());
//		cout << right << endl;
		double min = 0.0;
		 for(int i = 0; i < 150;i++){
			double mid = (left+right)/2;
//			cout << "left/right/mid " << left << "/" << right << "/" << mid << endl;
			int partiu = parte( mid,friends+1,F );
//			cout << "partiu: " << partiu <<endl;
			if( partiu > friends+1 ){
				left = mid;
			}
			else{
			right = mid ;
				if( mid > min ) min = mid;
			}
		}
		
		printf("%.4f\n", min);
		//cout << min << endl;
	}	
	
}
