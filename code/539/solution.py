# -*- coding: UTF-8 -*-
mod = 987654321


def S(l, r):
    ret = 0
    if r <= 4:
        for i in range(l, r + 1):
            ret += 1
            if i != 1:
                ret += 1
        return ret

    if l == r:
        ret = 4 * S(l // 4, l // 4) % mod
        if l % 4 <= 1:
            ret -= 2
        return (ret + mod) % mod
    if r - l < 8:
        for i in range(l, r + 1):
            ret += S(i, i)
        return ret % mod
    ll = l // 4 * 4
    if ll < l:
        ll += 4
    ret += S(l, ll - 1)
    rr = r // 4 * 4 - 1
    ret += S(rr + 1, r)
    ret += 16 * S(ll // 4, rr // 4) % mod - 4 * (rr // 4 - ll // 4 + 1)
    return ret % mod


print(S(1, 10 ** 18))
