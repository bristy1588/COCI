/*
    Day 3 : 19 February, 2014
    COCI 2013/14 Contest 3 December
*/
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int K,B,A,i,nA,nB;

    cin>> K;

    B = 0; A = 1;

    for(i = 0; i < K; i++){
        nB = B + A;
        nA = B;
        B = nB;
        A = nA;
    }

    cout<<A<<" "<<B<<endl;


    return 0;
}
