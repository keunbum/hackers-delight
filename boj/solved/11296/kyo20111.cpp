#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        ll a, b; char c, d, e; scanf("%lld.%lld %c %c %c",&a,&b,&c,&d,&e);
        a = a * 100 + b;

        if(c == 'R') a *= 55;
        if(c == 'G') a *= 70;
        if(c == 'B') a *= 80;
        if(c == 'Y') a *= 85;
        if(c == 'O') a *= 90;
        if(c == 'W') a *= 95;

        if(d == 'C') a *= 95;
        if(d == 'X') a *= 100;

        if(e == 'C'){
            if(a/10000%10 > 5) a += 100000;
            a -= a%100000;
        }
        if(e == 'P' && a/1000%10 > 4) a += 10000;

        a/=10000;
        printf("$%lld.%02lld\n",a/100,a%100);
    }
}