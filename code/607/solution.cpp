#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
double cost_time(double x0, double y0, double x1, double y1, double speed) {
    x0 -= x1;
    y0 -= y1;
    return sqrt(x0 * x0 + y0 * y0) / speed;
}

pair<double, double> cal(double x0, double y0, double x1, double y1, double speed, double target_speed) {
    double sin_theta_1 = (x1 - x0) / sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));
    double sin_theta_2 = sin_theta_1 / speed * target_speed;
    return make_pair(tan(asin(sin_theta_2)) * 10 + x1, y1 + 10);
}

double cal(double x, double y) {
    double ans = cost_time(0, 0, x, y, 10);

    double startx = 0, starty = 0;
    for (int i = 9; i >= 5; i--) {
        auto target = cal(startx, starty, x, y, i + 1, i);
        ans += cost_time(x, y, target.first, target.second, i);
        startx = x;
        starty = y;
        x      = target.first;
        y      = target.second;
    }
    return ans + cost_time(x, y, 50 * sqrt(2), 50 * sqrt(2), 10);
}
int main() {
    // https://en.wikipedia.org/wiki/Snell%27s_law
    double endy = (50 * sqrt(2) - 50) / 2;

    double endx_l = 0, endx_r = 50 * sqrt(2);
    double diff = 1;
    while (diff >= 1e-12) {
        double lmid = (endx_l * 2 + endx_r) / 3;
        double rmid = (endx_r * 2 + endx_l) / 3;

        double lvalue = cal(lmid, endy);
        double rvalue = cal(rmid, endy);

        diff = fabs(rvalue - lvalue);

        if (lvalue < rvalue) {
            endx_r = rmid;
        } else {
            endx_l = lmid;
        }
    }
    printf("%.10f\n", cal(endx_l, endy));
    return 0;
}
