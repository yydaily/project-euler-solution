#include<iostream>
#include<map>
#include<vector>

namespace Hasher {
    typedef long long ll;
    struct hashResult {
        std::vector<ll> r;

        hashResult() {}
        hashResult(int len) {
            r.resize(len);
            for(int i = 0;i<len;i++) r[i] = 0;
        }

        bool operator<(const hashResult &a) const {
            for(int i = 0;i<r.size();i++) {
                if(r[i] != a.r[i]) return r[i] < a.r[i];
            }
            return false;
        }
    };

    class Mapper {
    private:
        std::map<hashResult, ll> m;

        std::vector<ll> mod;
        const ll base = 1e9+9;

    public:
        Mapper() {
            mod.push_back(998244353);
            mod.push_back(1e9+7);
        }

        std::map<hashResult, ll>::const_iterator begin() {
            return m.begin();
        }

        std::map<hashResult, ll>::const_iterator end() {
            return m.end();
        }

        Mapper operator=(const Mapper & a) {
            Mapper ret;
            ret.m = a.m;
            return ret;
        }

    private:
        hashResult merge(const hashResult &a, const hashResult &b) {
            hashResult ret(mod.size());
            for(int i = 0;i<mod.size();i++) {
                ret.r[i] = (a.r[i]*base+b.r[i])%mod[i];
            }
            return ret;
        }

        template<typename T, typename = std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, ll>>>
        hashResult gen(T a) {
            hashResult ret(mod.size());
            for(int i = 0;i<mod.size();i++) {
                ret.r[i] = (ret.r[i] * base + a) % mod[i];
            }
            return ret;
        }
        template<typename T, typename = std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, ll>>>
        hashResult gen(const std::vector<T> &a) {
            hashResult ret(mod.size());
            for(auto i : a) {
                ret = merge(ret, gen(i));
            }
            return ret;
        }

    public:
        template <typename T>
        ll& operator[](T a) {
            return m[gen(a)];
        }
    };
}
