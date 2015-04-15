#include <bits/stdc++.h>

int isPerfectSquare(int64_t n){
    int64_t h = n & 0xF;
    if (h > 9){
        return false;
    }	
    if (h != 2 && h != 3 && h!= 5 && h!=6 && h!=7 && h!=8){
        int64_t t = (int64_t) floor(sqrt((double) n) + 0.5);
	return t*t == n;
    }
    return false;
}

int main(){

    int64_t n;
    while(scanf("%d", &n)){
	if(n == 0) break;
        if(isPerfectSquare(n)){
            printf("yes\n");
        }
        else
	    printf("no\n");
    }

    return 0;
}


