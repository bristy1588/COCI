/*
    Day 9, Week 17 : 9 March, 2014
    Time : 2:12 AM
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define         f       first
#define         s       second
#define         Z       300005
using namespace std;
struct circle{
    int v,x,r,id;
};
circle c[2*Z];
int cl[Z],rec[Z*2], op[Z];

bool cmp(circle a, circle b)
{
    if(a.x != b.x) return a.x < b.x;
    if(a.v != b.v) return a.v < b.v;
    if(a.v == -1)
        return a.r < b.r;
    if(a.v == 1)
        return a.r > b.r;
    return a.id < b.id;
}

int main()
{
    int N,i,xi,ri;

    cin >> N;

    for(i = 0; i < N ; i++){
            cin >> xi>>ri;
            c[i].v = 1;
            c[i].x = xi - ri;
            c[i].r = ri;
            c[i].id  = i;

            c[i+N].v = -1;
            c[i+N].x = xi+ ri;
            c[i+N].r = ri;
            c[i+N].id = i;
    }

    sort(c, c+ 2*N, cmp);


    for(i = 0; i < 2*N; i++){
        if(c[i].v == -1) cl[c[i].id] = i;
        if(c[i].v == 1)  op[c[i].id] = i;
    }

    for(i = 0; i+1 < 2*N ; i++){
        if(c[i].x != c[i+1].x) rec[i] = -1;
        else    rec[i] = cl[c[i+1].id];
    }

    int add,now;

    int ans = N+1;

    for(i = 0; i < 2*N; i++){
        if(c[i].v == -1) continue;
        add = 0;
        now = rec[i];
        while(1){
            if(now == -1) break;
            if(c[now].id == c[i].id){
                add = 1;
                break;
            }
            now = rec[now];
        }
        ans += add;
    }

    printf("%d\n",ans);


    return 0;
}
