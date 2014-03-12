/*
    Day 120: 12 March 2014
    Time : 8:16 AM - 8:44 AM
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char s1[200],s2[200];

int main()
{
    int N,k1,k2,i,rec,l;

    cin >> N;

    scanf("%s",s1);
    k1 = strlen(s1);

    for(i = 0; i <k1 ; i++)
        if(s1[i]=='*') rec = i;

    for(l = 0; l < N ; l++){
        scanf("%s",s2);
        k2 = strlen(s2);

        if(k2 < k1 -1){
            printf("NE\n");
            continue;
        }
        int flag = 0;
        for(i = 0; i < min(k1,k2); i++){
            if(s1[i]=='*') flag++;
            if(s1[i]!=s2[i]) break;
        }

        for(i = 1; i <= min(k1,k2); i++){
            if(s1[k1-i]=='*') flag++;
            if(s1[k1-i]!=s2[k2-i]) break;
        }

        if(flag==2) printf("DA\n");
        else printf("NE\n");


    }


    return 0;
}
