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

int main()
{
    int books, tempo;
    scanf("%d%d", &books, &tempo);
    
    int a[books];
    for (int i = 0; i < books; i++)
    {
        scanf("%d", &a[i]);
    }

    int left = 0;
	int time = 0;
	
    while (left < books && time + a[left] <= tempo)
    {
        time += a[left++];
    }
    
    int maximum = left;
    for (int i = 0; i < books; i++)
    {
        time -= a[i];
        while (left < books && time + a[left] <= tempo)
        {
            time += a[left++];
        }
        if (left - i - 1 > maximum)
        {
            maximum = left - i - 1;
        }
    }
    printf("%d\n", maximum);
    return 0;
}
