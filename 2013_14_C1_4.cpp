/*
    Day 8, Week 17 : March 8, 2014
    Nice use of Greedy Algorithm to solve a problem
*/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#define     Z       300005
typedef long long ll;

using namespace std;
struct jewel{
    int m,v;
};
bool cmp(jewel a, jewel b){
    return a.m < b.m;
}
jewel a[Z];
int bag[Z];

int main()
{
    int N,K,i;

    cin >> N >> K;

    for(i = 0; i < N; i++){
        cin >> a[i].m >> a[i].v;
    }

    for(i = 0; i < K; i++)
        cin >> bag[i];

    sort(bag, bag+K);
    sort(a, a+ N, cmp);

    ll ans;
    int j;
    priority_queue<int> pq;


    ans = 0ll;
    j = 0; int now;

    while(!pq.empty()) pq.pop();

    for(i = 0; i < K; i++){
        for(; a[j].m <= bag[i]; j++){
            pq.push(a[i].v);
        }
        if(!pq.empty()){
            now = pq.top(); pq.pop();
            ans += now;
        }
    }

    cout<<ans<<endl;

    return 0;
}
