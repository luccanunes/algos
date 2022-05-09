#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const int M = 1e9 + 7;

struct Matrix {
    lli m[2][2];
    void show() const {
        cout << m[0][0] << ' ' << m[0][1] << endl;
        cout << m[1][0] << ' ' << m[1][1] << endl;
    }
    Matrix operator*(Matrix B) const {
        Matrix res = {{{0, 0}, {0, 0}}};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++) {
                    res.m[i][k] += ((m[i][j]) % M * (B.m[j][k]) % M) % M;
                    res.m[i][k] %= M;
                }
        return res;
    }
    void operator*=(Matrix B) {
        *this = *this * B;
    }
    Matrix operator^(lli x) const {
        Matrix res = {{{1, 0}, {0, 1}}}, copy = Matrix{{{m[0][0], m[0][1]}, {m[1][0], m[1][1]}}};
        while (x > 0) {
            if (x % 2) res *= copy;
            x /= 2;
            copy *= copy;
        }
        return res;
    }
};

int main() {
    lli n;
    cin >> n;
    cout << (Matrix{{{19, 7}, {6, 20}}} ^ n).m[0][0] << endl;
    return 0;
}