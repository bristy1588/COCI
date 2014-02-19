/*
    Day 3 : 19 February, 2014
    COCI 2013/14 Contest 3 December
*/
#include <stdio.h>
#include <iostream>
using namespace std;
char s[30][30], f[30][30],c[4];

int main()
{
    int M,N,U,L,R,D,i,j,plus;

    cin >> M >> N;
    cin>> U >> L>> R>> D;

    for(i = 0; i <M ; i++)
        scanf("%s",s[i]);

    c[0] = '#';
    c[1] = '.';

    for(i = 0; i < M + U+ D; i++)
    {
        if(i%2 == 0) plus = 0;
        else plus = 1;
        for(j = 0; j < N + L+ R; j++){
            f[i][j] = c[(plus+j)%2];
        }
    }

    for(i = 0; i < M ; i++)
        for(j = 0; j < N; j++)
            f[i+U][j+L] = s[i][j];

    for(i = 0; i < M+U+D; i++){
        for(j = 0; j < N+L+R; j++){
            printf("%c",f[i][j]);
        }
        printf("\n");
    }
    return 0;
}
