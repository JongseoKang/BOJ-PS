#include<cstdio>
#include<algorithm>
using namespace std;
int n, px[50], py[50], vx[50], vy[50];
double f(double t) {
    double sx = 1e9, sy = 1e9, ex = -1e9, ey = -1e9;
    for (int i = 0; i < n; i++) {
        sx = min(sx, px[i] + vx[i] * t);
        sy = min(sy, py[i] + vy[i] * t);
        ex = max(ex, px[i] + vx[i] * t);
        ey = max(ey, py[i] + vy[i] * t);
    }
    return max(ex - sx, ey - sy);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d%d%d", px + i, py + i, vx + i, vy + i);
    double low = 0, high = 1e5, m1, m2;
    for (int i = 0; i < 200; i++) {
        m1 = (low * 2 + high) / 3;
        m2 = (low + high * 2) / 3;
        f(m1) < f(m2) ? high = m2 : low = m1;
    }
    printf("%.9lf", f(low));
    return 0;
}