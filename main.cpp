
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        int p, w, v;
        cin >> p >> w >> v;

        // Binary decomposition of p
        for (int k = 1; p > 0; k <<= 1) {
            int num = min(k, p);
            p -= num;
            int cur_w = num * w;
            int cur_v = num * v;
            for (int j = m; j >= cur_w; --j) {
                dp[j] = max(dp[j], dp[j - cur_w] + cur_v);
            }
        }
    }

    cout << dp[m] << endl;

    return 0;
}
