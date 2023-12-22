import java.util.*;
import java.lang.*;
import java.io.*;

class Solver {
    public static int[] countPrimes(int n) {
        int[] isPrime = new int[n];
        Arrays.fill(isPrime, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i] == 1) {
                if ((long) i * i >= n) break;
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        return isPrime;
    }

    public static long sumPrime(int num) {
        int[] isPrim = countPrimes(num);
        long ans = 0;
        for (int i = 2; i < isPrim.length; i++) {
            ans += isPrim[i] * i;
        }
        return ans;
    }

    public static void main(String[] args) throws java.lang.Exception {
        System.out.println(sumPrime(2000000));
    }
}
