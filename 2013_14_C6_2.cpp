

/*
    Day 120: 12 March 2014
    Time : 8:46 AM -  AM
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int N,LIM;
int c[30],a[30];
char s[10000];

int SUBSET(int at, int mask){

    int id,ans;

    if(mask == LIM){
        id = N-at;
        ans = 1<<id;
        return ans;
    }

    if((mask | c[at]) != LIM) return 0;

    ans = SUBSET(at+1, mask) + SUBSET(at+1, mask | a[at]);

    return ans;
}
int main()
{
    int i,k,j,mark[30];

    cin >> N;
    LIM = 1<<26;
    LIM--;

    memset(a, 0, sizeof(a));

    for(i = 0; i < N ; i++){
        scanf("%s",s);
        k = strlen(s);

        memset(mark, 0, sizeof(mark));
        for(j = 0; j < k ; j++){
            mark[s[j]-'a'] = 1;
        }

        for(j = 0 ; j < 26; j++){
            if(mark[j]==0) continue;
            a[i] = a[i] | (1<<j);
        }
    }

    c[N]= 0;
    for(i = N-1 ; i >=0 ; i--){
        c[i] = c[i+1] | a[i];
    }


   int ans = SUBSET(0,0);
    printf("%d\n",ans);

    return 0;
}
