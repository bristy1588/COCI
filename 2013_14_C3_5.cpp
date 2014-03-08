/*
    Day 8, Week 17 : March 8, 2014
    COCI Problem 5, A special trick learnt
    Order : Slog(S)
*/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
#define     Z       2000006
typedef long long ll;
using namespace std;
int mark[Z];

int main(){

    int N,a,j;

    cin >> N;
    memset(mark, 0 , sizeof(mark));

    for(int i = 0; i < N ; i++){
        cin >>a;
        mark[a]++;
    }

    ll ans,i,now;

    ans = 0ll;
    for(i = 1ll; i <Z; i++){
        now = 0ll;
        for(j = i; j < Z; j = j+i)
            now += mark[j];
        now = now*i;
        ans = max(ans,now);
    }

    cout<<ans<<endl;

    return 0;
}
