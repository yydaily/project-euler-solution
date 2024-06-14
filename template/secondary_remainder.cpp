#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;
namespace secondary_reminder {
	__int128 T,n,p;
	__int128 w;
	struct Complex{
		__int128 x;
		__int128 y;
		Complex(){x=0;y=0;}
		Complex operator*(const Complex &b)const
		{
			Complex ret;
			ret.x=(x*b.x%p+y*b.y%p*w%p)%p;
			ret.y=(x*b.y%p+y*b.x%p)%p;
			return ret; 
		}
	};
	__int128 Real_quick(__int128 x,__int128 p,__int128 mod)
	{
		__int128 ret=1;
		while(p)
		{
			if(p&1) ret=ret*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ret;
	}
	__int128 Image_quick(Complex a,__int128 p)
	{
		Complex ret;
		ret.x=1;
		while(p)
		{
			if(p&1) ret=ret*a;
			a=a*a;
			p>>=1;
		}
		return ret.x;
	} 
	__int128 cipolla(__int128 n,__int128 p)
	{
		n%=p;
		if(p==2) return n;
		if(Real_quick(n,(p-1)/2,p)==p-1) return -1;
		__int128 a;
		while(1)
		{
			a=rand()%p;
			w=((a*a%p-n)%p+p)%p;
			if(Real_quick(w,(p-1)/2,p)==p-1)
				break;  
		}   
		Complex ret;
		ret.x=a;
		ret.y=1;
		return Image_quick(ret,(p+1)/2);
	}
	long long solve(__int128 n_, __int128 p_) {
		n = n_;
		p = p_;
		__int128 flag = cipolla(n, p);
		if (flag == -1) return -1;
		__int128 sum = p-flag;
		if(sum == flag) return flag;
		return min(sum, flag);
	}
};
