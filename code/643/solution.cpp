#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e6 + 5;
const ll mod   = 1e9 + 7;
const ll inv   = 5e8 + 4;

bool IsPrime[maxn];
int Tot;
ll Prime[maxn];
int Phi[maxn];
ll PrefixPhi[maxn];

void Sieve() {
    for (int i = 2; i < maxn; ++i)
        IsPrime[i] = true;
    Phi[1] = 1;
    for (ll i = 2; i < maxn; ++i) {
        if (IsPrime[i]) {
            Phi[i]       = i - 1;
            Prime[Tot++] = i;
        }
        for (ll j = 0; j < Tot && i * Prime[j] < maxn; ++j) {
            IsPrime[i * Prime[j]] = false;
            if (i % Prime[j] == 0) {
                Phi[i * Prime[j]] = Phi[i] * Prime[j];
                break;
            }
            Phi[i * Prime[j]] = Phi[i] * Phi[Prime[j]];
        }
    }
    for (int i = 1; i < maxn; ++i)
        PrefixPhi[i] = (PrefixPhi[i - 1] + Phi[i]) % mod;
}

map<ll, ll> SumPhi;

ll SigmaPhi(ll Key) {
    if (Key < maxn)
        return PrefixPhi[Key];
    if (SumPhi[Key])
        return SumPhi[Key];
    ll Ans = Key % mod * (Key % mod + 1) % mod * inv % mod;
    for (ll l = 2, tp; l <= Key; l = tp + 1) {
        tp  = Key / (Key / l);
        Ans = (Ans - (tp - l + 1) % mod * SigmaPhi(Key / l) % mod + mod) % mod;
    }
    SumPhi[Key] = Ans;
    return SumPhi[Key];
}

ll N = 5e10;

int main(int argc, char *argv[]) {
    Sieve();
    ll ans = 0;
    for (; N >= 1; N >>= 1) {
        ans = (ans + SigmaPhi(N) - 1 + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
