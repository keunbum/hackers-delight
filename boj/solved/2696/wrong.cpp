#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int t,m,mid;
int main(){
	for(scanf("%d",&t);t--;){
		priority_queue<int> l,r;
		scanf("%d%d",&m,&mid);
		printf("%d\n%d ",m/2+1,mid);
		for(int i=1,x,y; i<=m/2; i++){
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			if(y<mid){
				l.push(x);
				l.push(y);
				r.push(-mid);
				mid=l.top();
				l.pop();
			}
			else if(x>mid){
				r.push(-x);
				r.push(-y);
				l.push(mid);
				mid=-r.top();
				r.pop();
			}
			else l.push(x),r.push(-y);
			if(i%10==0) puts("");
			printf("%d ",mid);
		}
		puts("");
	}
	return 0;
}