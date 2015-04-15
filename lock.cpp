// Lucas Medeiros Cavalcante
	
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 


using namespace std;

int main(){
    
    int ini, p1, p2, p3;
    
    while(scanf("%d %d %d %d", &ini, &p1, &p2, &p3) && (ini || p1 || p2 || p3)){
        int result = 0;
        
        if(ini < p1){ result += 720 + (360 - (p1 - ini)*9);}
        
        else {result += 720 + ((ini - p1)*9);}
        
        if(p1 > p2) {result += 360 + (360 - (p1 - p2)*9);}
        
        else {result += 360 + (p2 - p1)*9;}
        
        if(p2 < p3) {result += 360 - (p3 - p2)*9;}
        
        else {result += (p2 - p3)*9;}
        
        cout << result << endl;
        
    }
    
    return 0;
}
