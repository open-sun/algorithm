#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#define M_PI acos(-1)
using namespace std;

void FFT(int m, vector<complex<double>>& a) {
    if (m <= 1) return;

    vector<complex<double>> a0(m / 2), a1(m / 2);
    int j = 0;
    for (int i = 0; i < m; i += 2) {
        a0[j] = a[i];
        a1[j] = a[i + 1];
        j++;
    }
    FFT(m / 2, a0);
    FFT(m / 2, a1);

    double ang = 2 * M_PI / m;
    complex<double> w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < m / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + m / 2] = a0[i] - w * a1[i];
        w *= wn;
    }
}
void IFFT(int m, vector<complex<double>>& a) {
    if (m <= 1) return;

    vector<complex<double>> a0(m / 2), a1(m / 2);
    int j = 0;
    for (int i = 0; i < m; i += 2) {
        a0[j] = a[i];
        a1[j] = a[i + 1];
        j++;
    }
    IFFT(m / 2, a0);
    IFFT(m / 2, a1);

    double ang = -(2 * M_PI / m);
    complex<double> w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < m / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + m / 2] = a0[i] - w * a1[i];
        w *= wn;
    }
}
int main() {
    int q, m;
    cin >> q >> m;

    vector<int> a(q + 1,0), b(m + 1,0);
    for (int i = 0; i <= q; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i <= m; ++i) {
        cin >> b[i];
    }

    int n = 1;
    while (n < max(a.size(), b.size()))
        n *= 2;
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);

    FFT(n, fa);
    FFT(n, fb);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    IFFT(n, fa);
    double l = n;
    for (int i = 0; i < n; ++i)
        fa[i] = fa[i] / l;
    vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = round(fa[i].real());

    for (int i = 0; i < q + m + 1; ++i) {
        cout << result[i] << " ";
    }
    return 0;
}