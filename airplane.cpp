// Lucas Medeiros Cavalcante
	
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
	
using namespace std;

pair<int,int> max_position(int array[], int size){
    int position = 0;
    int max = 0;
    for( int i = 0; i<size;i++){
        if(array[i] > max) {
        position = i;
        max = array[i];
        }
    }
    
    pair<int,int> result (max,position);
    return result;
}

pair<int,int> min_position(int array[], int size){
    int position = 0;
    int min = 10000000;
    for( int i = 0; i<size;i++){
        if(array[i] != 0){
        if((array[i] < min)) {
        position = i;
        min = array[i];
        }
        }
    }
    
    pair<int,int> result (min,position);
    return result;
}

int most_zloyts(int array[], int num_pass, int planes){
    int zloyts = 0;
    
    while(num_pass){
        pair<int,int> max_num (max_position(array, planes));
        zloyts += max_num.first;
        array[max_num.second]--;
        num_pass--;
    }
    return zloyts;
    
}

int least_zloyts(int array[], int num_pass, int planes){
    int zloyts = 0;
    
    while(num_pass){
        pair<int,int> min_num (min_position(array, planes));
        zloyts += min_num.first;
        array[min_num.second]--;
        num_pass--;
    }
    return zloyts;
    
}

int main() {
    int pass, planes;
    cin >> pass >> planes;
    
    int i = planes;
    int array[planes];
    int brray[planes];
    
    while(i){
        cin >> array[planes-i];
        brray[planes-i] = array[planes-i];
        i--;
    }
        
 
    
    cout << most_zloyts(array, pass, planes) << " " <<least_zloyts(brray, pass, planes) << endl;
}
