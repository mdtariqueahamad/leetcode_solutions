int segmentCost(const char* s, int l, int m, int** factors, int* factorCount) {
    int best = m;
    for (int idx = 0; idx < factorCount[m]; idx++) {
        int d = factors[m][idx];
        int groups = m / d;  // Each group contains groups characters
        int changes = 0;
        for (int offset = 0; offset < d; offset++) {
            for (int t = 0; t < groups / 2;
                 t++) {  // Pair characters from opposite ends of the group
                if (s[l + offset + t * d] !=
                    s[l + offset + (groups - 1 - t) * d]) {
                    changes++;
                }
            }
        }
        best = (int)fmin(best, changes);
    }
    return best;
}

int minimumChanges(char* s, int k) {
    int n = strlen(s);
    int** factors = malloc((n + 1) * sizeof(int*));
    int* factorCount = calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++) {
        factors[i] = malloc((n + 5) * sizeof(int));
    }
    // Precompute the proper divisors of each number
    for (int d = 1; d <= n / 2; d++) {
        for (int m = d * 2; m <= n; m += d) {
            factors[m][factorCount[m]++] = d;
        }
    }
    int** cost = malloc(n * sizeof(int*));
    for (int l = 0; l < n; l++) {
        cost[l] = calloc(n, sizeof(int));
    }
    for (int l = 0; l + 1 < n; l++) {
        for (int r = l + 1; r < n;
             r++) {  // Each substring must have length at least 2
            cost[l][r] = segmentCost(s, l, r - l + 1, factors, factorCount);
        }
    }
    int* prev = malloc(n * sizeof(int));
    int* cur = malloc(n * sizeof(int));
    for (int start = 0; start < n; start++) {  // The case seg = 1
        prev[start] = cost[start][n - 1];
    }
    for (int seg = 2; seg <= k;
         seg++) {  // Increase the number of segments from 2 to k
        for (int start = 0; start < n; start++) {
            cur[start] = n;
        }
        int limit = n - 1 - 2 * (seg - 1);
        for (int start = 0; start + 2 * seg <= n;
             start++) {  // Leave at least 2*seg characters
            for (int e = start + 1; e <= limit; e++) {
                cur[start] =
                    (int)fmin(cur[start], cost[start][e] + prev[e + 1]);
            }
        }
        int* tmp = prev;
        prev = cur;
        cur = tmp;
    }
    int answer = prev[0];
    for (int i = 0; i <= n; i++) {
        free(factors[i]);
    }
    free(factors);
    free(factorCount);
    for (int l = 0; l < n; l++) {
        free(cost[l]);
    }
    free(cost);
    free(prev);
    free(cur);
    return answer;
}
