		// Lucas Medeiros Cavalcante
		
		#include <iostream>
		#include <cstdio>
		
		using namespace std;
		
		int main() {
			int l, r;
			
			while(cin >> l >> r){
				
				int left, right;
				left = min(l, r);
				right = max(r,l);
			
				int result = 0;
				int cycles;
			
			
				for(int i = left; i <= right; i++){
					
					int num = i;
					cycles = 1;
					
					while(num != 1){
							if (num % 2 == 1){
								num = 3 * num + 1;
							}
							
							else num = num/2;
							
							cycles++;
						}
					
					
					if(cycles > result){
						result = cycles;
					}
				}
				printf("%d %d %d\n", l, r, result);
		
	}
		return 0;
	}
		
		
	
