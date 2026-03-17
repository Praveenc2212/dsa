#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
#define Matrix vector<vector<long long>> 
Matrix mat_mul(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        }
    return C;
}
Matrix mat_pow(Matrix M, long long p) {
    int n = M.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1; 
    while (p > 0) {
        if (p & 1) result = mat_mul(result, M);
        M = mat_mul(M, M);
        p >>= 1;
    }
    return result;
}
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, K, B, R;
    cin >> N >> K >> B >> R;
    long long inv_mil = power(1000000LL, MOD - 2, MOD);
    long long pB = B % MOD * inv_mil % MOD;
    long long pR = R % MOD * inv_mil % MOD;
    int size = (int)K + 1; 
    Matrix M(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) {
        if (i + 1 < size) M[i + 1][i] = pB; 
        if (i - 1 >= 0)   M[i - 1][i] = pR; 
    }
    Matrix MN = mat_pow(M, N);
    long long ans = 0;
    for (int j = 0; j < size; j++)
        ans = (ans + MN[j][0]) % MOD;
    cout << ans << "\n";
    return 0;
}
//=============================================================

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    long long N, K, B, R;
    cin >> N >> K >> B >> R;

    long long inv_mil = power(1000000LL, MOD - 2, MOD);

    long long ans = 0;

    long long total = 1LL << N;

    for (long long mask = 0; mask < total; mask++) {
        int blue = 0, red = 0;
        bool is_great = true;

        for (int i = N - 1; i >= 0; i--) {
            int bit = (mask >> i) & 1;
            if (bit == 0) blue++;      
            else          red++;       

        
            if (blue < red || blue > red + K) {
                is_great = false;
                break;
            }
        }

        if (is_great) {
            long long prob = power(B, blue, MOD) * power(R, red, MOD) % MOD;
            prob = prob * power(inv_mil, N, MOD) % MOD;
            ans = (ans + prob) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}
// ```

// ---

// ## How the Brute Force Works

// **Step 1 — Represent every chain as a bitmask:** Each chain of length N is a binary number from `0` to `2^N - 1`. Bit `0` = Blue, Bit `1` = Red.

// **Step 2 — Check the "great" condition on every prefix:** For each chain, scan left to right keeping running counts of blue and red balls. At every step, check:
// ```
// 0 ≤ (blue - red) ≤ K
// ```
// If this ever fails, mark the chain as invalid and break early.

// **Step 3 — Accumulate probability:** For valid chains with `b` blue and `r` red balls:
// ```
// P = (B/10^6)^b × (R/10^6)^r  mod (10^9+7)


