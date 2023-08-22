#include "../template/prime.cpp"
#include "../template/progress_rate.cpp"
#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
const long long upper = 10;
int sg[upper + 10];
int main() {
    ProgressBar::init();
    Prime::init(upper);
    sg[0] = sg[1] = 0;

    map<int, int> counter;

    for (int i = 2; i <= upper; i++) {
        ProgressBar::print_bar(i, upper);
        map<int, bool> m;
        for (int fac : Prime::all_factor(i)) {
            if (fac == i || fac == 1)
                continue;
            for (int fac2 : Prime::all_factor(i)) {
                if (fac2 == i || fac2 == 1)
                    continue;
                m[sg[fac] ^ sg[fac2]] = true;
            }
        }
        for (int j = 0;; j++) {
            if (m[j])
                continue;
            sg[i] = j;
            break;
        }
        counter[sg[i]]++;
    }
    for (auto i : counter) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}
