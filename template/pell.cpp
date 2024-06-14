#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;
namespace Pell {
	__int128 a[20000];
	bool pell_minimum_solution(__int128 n,__int128 &x0,__int128 &y0){/*{{{*/
		double sq=sqrt(n);
		__int128 m=sq;
		int i=0;
		if(m*m==n)return false;
		a[i++]=m;
		__int128 b=m,c=1;
		double tmp;
		do{
			c=(n-b*b)/c;
			tmp=(sq+b)/c;
			a[i++]=floor(tmp);
			b=a[i-1]*c-b;
		}while(a[i-1]!=2*a[0]);
		__int128 p=1,q=0;
		for(int j=i-2;j>=0;j--){
			__int128 t=p;
			p=q+p*a[j];
			q=t;
		}
		if((i-1)%2==0){x0=p;y0=q;}
		else{x0=2*p*p+1;y0=2*p*q;}
		return true;
	}/*}}}*/
}
