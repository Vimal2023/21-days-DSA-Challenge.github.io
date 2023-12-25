#include <vector>

#define MOD 1000000007



vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    int size = A.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] = (result[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }

    return result;
}

vector<vector<long long>> matrixExponentiation(vector<vector<long long>>& base, long long power) {
    int size = base.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));

    for (int i = 0; i < size; ++i) {
        result[i][i] = 1;
    }

    while (power > 0) {
        if (power % 2 == 1) {
            result = matrixMultiply(result, base);
        }
        base = matrixMultiply(base, base);
        power /= 2;
    }

    return result;
}

long long solve(long long N) {
    if (N <= 1)
        return N;

    vector<vector<long long>> base = {{1, 1}, {1, 0}};
    base = matrixExponentiation(base, N - 1);

    return base[0][0];
}
