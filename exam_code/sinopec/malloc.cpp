#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    double ***ptr = (double***)malloc(sizeof(double**)*10);
    for (int i = 0; i < 10; i++) {
        ptr[i] = (double**)malloc(sizeof(double*)*20);
        for (int j = 0; j < 20; j++) {
            ptr[i][j] = (double*)malloc(sizeof(double)*30);
        }
    }
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++)
            free(ptr[i][j]);
        free(ptr[i]);
    }
    free(ptr);
    return 0;
}
