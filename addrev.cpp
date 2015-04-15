// Lucas Medeiros Cavalcante
	
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 


using namespace std;

string reverse(string s){
	string result = "";
	int j =0;
	
	while(s.back() == '0'){
		s.pop_back();
	}
	
	cout << j << endl;
	for(j; j < s.length(); j++){
		result = s[j] + result;
	}
	
	
	return result.;
}


int main(){
	string a,b;
	
	int repeticoes;
	
	cin >> repeticoes;
	
	while(repeticoes){
		cin >> a >> b;
		
		string ra, rb;
		
		
		ra = reverse(a);
		rb = reverse(b);
		
		
		
		
		int na = atoi(ra.c_str());
		int nb = atoi(rb.c_str());
		
		int nf = na + nb;
		
		stringstream out;
		
		out << nf;
		
		string result = out.str();
		
		result = reverse(result);
		
		cout << "na: " << na << " nb: " << nb << " nf: " << nf  << " result: "<<result << endl;
		repeticoes--;
	}
	return 0;
}
