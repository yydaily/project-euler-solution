namespace ChinaReminder {
	long long num = 0;
	long long m[20], a[20];
	long long gcd(long long a, long long b) {/*{{{*/
		if(a==0) return b;
		return gcd(b%a, a);
	}/*}}}*/
	long long exgcd(long long a,long long b,long long &x,long long &y){/*{{{*/
		long long d;
		if(b == 0){
			x = 1;
			y = 0;
			return a;
		}
		d = exgcd(b,a%b,y,x);
		y -= a / b * x;
		return d;
	}/*}}}*/
	long long China() {/*{{{*/
		long long m1=m[0],a1=a[0],m2,a2,k1,k2,x0,Gcd,c;
		long long lcm=m[0];
		for(long long i=1;i<num;i++){
			m2=m[i],a2=a[i];
			c=a2-a1;
			Gcd=exgcd(m1,m2,k1,k2);
			lcm=lcm*m[i]/gcd(lcm,m[i]);
			if(c%Gcd){
			   return 0; // no solution
			}
			x0=c/Gcd*k1;
			long long t=m2/Gcd;
			x0=(x0%t+t)%t;
			a1+=m1*x0;
			m1=m2/Gcd*m1;
		}
		return a1;
	}/*}}}*/
	void clear() {
		num = 0;
	}
	void add(long long remind, long long mod) {
		m[num] = mod;
		a[num++] = remind;
	}
};
