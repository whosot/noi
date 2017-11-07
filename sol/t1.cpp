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

const int N = 1e6+10;
int a[N];
int mm[N];
int n,x;
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i){
		read(x);
		x%=n;
		if(!x){
			printf("1\n%d",i);
			return 0;
		}
		a[i] = (a[i-1] + x) % n;
		if(!a[i]){
			wr(i);
			printf("\n");
			for(int j=1;j<=i;++j)
				wr(j),putchar(' ');
			return 0;
		}
		if(mm[a[i]]){
			wr(i-mm[a[i]]);
			printf("\n");
			for(int j=mm[a[i]]+1;j<=i;++j)
				wr(j),putchar(' ');
			return 0;
		}
		mm[a[i]] = i;
	}
}
