import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    public static long L(long a) {
        long ans = 0L;
        for (long i = 1; i <= a; i*=2) {
            long cnt = Math.min(a, 2*i-1) -i+1;
            long cnt2 = (a+1)/2/i;
            ans += cnt*cnt2*2;
        }
        for(long i = 1; i <= a; i=i*2+1) {
            ans--;
        }
        return ans;
    }

    public static long qpow(long a, long b) {
        long ret = 1;
        for(int i = 0;i<b;i++) {
            ret *= a;
        }
        return ret;
    }

    public static void main(String[] args) throws java.lang.Exception {
        System.out.println(L(7L));
        System.out.println(L(49L));
        System.out.println(L(qpow(7L, 17L)));
    }
}
