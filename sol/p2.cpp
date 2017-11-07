#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<vector>
#include<ctime>
#define reg register

using namespace std;
template <class T> inline void read(T & x){
	x=0;
	T f=1;
	char ch = getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	x*=f;
}
template <class T> inline T mx(T a,T b){return a>b?a:b;}
template <class T> inline T mi(T a,T b){return a<b?a:b;}
template <class T> inline T ab(T a){return mx(a,-a);}
template <class T> void wr(T x) {if(x/10) wr(x/10);putchar((x%10)+'0');}

const int M = 1010;
typedef long long LL;
LL v = 0;
LL n,m,k;
LL count[M],X[M],Y[M],Z[M];

int main(){
	freopen("read.in","r",stdin);
	freopen("read.out","w",stdout);
	read(m);
	read(k);
	n=0;
	for(LL i=1;i<=m;++i){
		read(count[i]);
		n+=count[i];
	}
	for(LL i=1;i<=m;++i) read(X[i]);
	for(LL i=1;i<=m;++i) read(Y[i]);
	for(LL i=1;i<=m;++i) read(Z[i]);
	LL S = (1 << k) - 1;
	//cout<<S<<"\n";
	LL pre = -1;
	LL cnt=1;
	for (reg LL i = 1; i <= m; ++i) {
		LL last = X[i];
		if(last!=pre) {
			cnt--;
			if(cnt<=0) pre = last,cnt=1;
		}
		else cnt++;
		for (reg LL j = 1; j < count[i]; ++j) {
			last = (last * Y[i] + Z[i]) & S;
			if(last!=pre) {
			cnt--;
			if(cnt<=0) pre = last,cnt=1;
			}
			else cnt++;
		}
	}
	LL ans=0;
	for (reg LL i = 1; i <= m; ++i) {
		LL last = X[i];
		if(last == pre) ans++;
		for (reg LL j = 1; j < count[i]; ++j) {
			last = (last * Y[i] + Z[i]) & S;
			if(last ==pre) ans++;
		}
	}
	//printf("%d",cnt-1);
	//cout<<clock();
	if(ans<=(n+1)/2) puts("0");
	else{
		LL tp = 2*ans-n-1;
		wr(tp);
	}
	return 0;
}
