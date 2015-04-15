// Lucas Medeiros Cavalcante

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	
	float a,g,ra,rg;
	
	scanf("%f %f %f %f", &a, &g, &ra, &rg);
	
	if(ra/a > rg/g){
		cout << "A" << endl;
	}
	
	else cout << "G" << endl;
	
	
	return 0;
}
	
