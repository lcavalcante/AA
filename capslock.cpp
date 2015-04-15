// Lucas Medeiros Cavalcante
	
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
	
using namespace std;

bool rule1(string s){
    string::iterator it;
    
    for(it = s.begin(); it < s.end(); it++){
        
        if(islower(*it)) {
            return false;
        }
            
    }
    return true;
}

bool rule2(string s){
    string::iterator it;
    
    for(it = s.begin()+1; it < s.end(); it++){
        
        if(islower(*it)) {
            return false;
        }
            
    }
    return true;
}

int main(){

    string::iterator it;    
    string input;
    
    cin >> input;
    
    if(rule1(input) || rule2(input)){
        for(it = input.begin(); it < input.end(); it++){
            if(islower(*it)) *it = toupper(*it);
            else *it = tolower(*it);
            
        }
    }
    
    
    cout << input << endl;
    
    return 0;
}
