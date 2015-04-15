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
#include <climits>

#define _USE_MATH_DEFINES

using namespace std;

long long int pot(long long int k, long long int i) {
    long long int total = 1;
    for (long long int j = 0; j< i; j++) {
        total *= k;
    }
    return total;

}

int main(){
	std::ios_base::sync_with_stdio(false);
	
	long long int n,k;
	
	cin >> n >> k;
	
	long long int left(0);
	long long int min = LLONG_MAX;
	long long int right(n);
	
	while(left<=right){
		long i(0);
		long long int mid = (left + right)/2;
		long long int cnt = mid/pot(k,i);
		long long int result = 0;
		while(cnt>=1){
			result += cnt;
			i++;
			cnt = mid/pot(k,i);
		}
		if(result < n){
			left = mid + 1;
		}
		else {
			if(mid < min) {min = mid;}
			right = mid -1;
		}
		
	}
	cout << min << endl;
}
