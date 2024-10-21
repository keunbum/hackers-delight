#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, p, l, mp[256];
char s[111];
int main(){
	mp['M'] = 1, mp['W'] = -1;

	scanf("%d %s",&n,s+1);
	l = strlen(s+1);
	for(int i=1;s[i];i++){
		p += mp[s[i]];
		if(abs(p) >= n+2) return !printf("%d",i-2);
	}
	if(abs(p) > n) printf("%d",l-1);
	else printf("%d",l);
}