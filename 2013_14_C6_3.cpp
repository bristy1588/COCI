/*
    Day 119 : 13 March, 2014
    Nice Ternary Search Problem
*/
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define       Z         300005
using namespace std;
typedef long long ll;
 ll m[Z],s[Z],tmp[Z];
ll ABS(ll a){
    if (a < 0ll) return -a;
    return a;
}
int N;

ll cost(int a){

    ll ans = 0ll;
    tmp[N/2] = a;
    int i;

    for(i = 1; i <= N/2; i++){
        tmp[i+N/2] = tmp[i+N/2-1]+1;
        tmp[N/2 - i] = tmp[i + N/2];
    }

    for(i = 0; i < N ; i++){
        ans += ABS(m[i]-tmp[i]);
        ans += ABS(s[i]-tmp[i]);
    }

    return ans;
}
int main()
{
    int i;
    ll hi,lo,mlo,mhi,clo,chi;

    cin >> N;

    hi = 0; lo = 0;
    for(i = 0; i < N ; i++){
        cin >> m[i];
        hi = max(m[i],hi);
    }

    for(i = 0; i < N ; i++){
        cin >> s[i];
        hi = max(s[i],hi);
    }


    while(hi - lo >= 3){
        mlo = lo + (hi-lo)/2;
        mhi = mlo+1;
        clo = cost(mlo);
        chi = cost(mhi);

        if(clo < chi) hi = mlo;
        else lo = mhi;
    }
    ll ans;

    ans = cost(hi);

    for(i = lo; i < hi; i++){
        clo = cost(i);
        ans = min(ans,clo);
    }

    cout<<ans<<endl;

    return 0;
}
