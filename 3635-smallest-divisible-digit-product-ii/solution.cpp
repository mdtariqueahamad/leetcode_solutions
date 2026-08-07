class Solution {
    // Helper to find the absolute minimum number of digits to satisfy missing prime factors
    vector<int> get_min_digits(long long r2, long long r3, long long r5, long long r7) {
        vector<int> res;
        while(r7 > 0) { res.push_back(7); r7--; }
        while(r5 > 0) { res.push_back(5); r5--; }
        while(r3 >= 2) { res.push_back(9); r3 -= 2; }
        while(r2 >= 3) { res.push_back(8); r2 -= 3; }
        
        // Handle remainders optimally to guarantee the smallest length and value
        if (r3 == 1 && r2 == 2) { res.push_back(2); res.push_back(6); } 
        else if (r3 == 1 && r2 == 1) { res.push_back(6); }
        else if (r3 == 1 && r2 == 0) { res.push_back(3); }
        else if (r3 == 0 && r2 == 2) { res.push_back(4); }
        else if (r3 == 0 && r2 == 1) { res.push_back(2); }
        
        sort(res.begin(), res.end());
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        long long req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        long long temp = t;
        
        // 1. Prime factorize the target t
        while(temp % 2 == 0) { req2++; temp /= 2; }
        while(temp % 3 == 0) { req3++; temp /= 3; }
        while(temp % 5 == 0) { req5++; temp /= 5; }
        while(temp % 7 == 0) { req7++; temp /= 7; }
        if (temp > 1) return "-1"; // Impossible if it has prime factors > 7
        
        int n = num.size();
        long long has2 = 0, has3 = 0, has5 = 0, has7 = 0;
        int first_zero = n;
        
        // 2. Check if the original string works exactly as is
        for (int i = 0; i < n; i++) {
            if (num[i] == '0' && first_zero == n) first_zero = i;
            if (num[i] != '0') {
                int d = num[i] - '0';
                while(d % 2 == 0) { has2++; d /= 2; }
                while(d % 3 == 0) { has3++; d /= 3; }
                if(d == 5) has5++;
                if(d == 7) has7++;
            }
        }
        if (first_zero == n && has2 >= req2 && has3 >= req3 && has5 >= req5 && has7 >= req7) {
            return num;
        }

        // 3. Precompute prefix factors to check combinations in O(1) time
        vector<long long> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        for (int i = 0; i < n; i++) {
            p2[i+1] = p2[i]; p3[i+1] = p3[i]; p5[i+1] = p5[i]; p7[i+1] = p7[i];
            if (num[i] != '0') {
                int d = num[i] - '0';
                while(d % 2 == 0) { p2[i+1]++; d /= 2; }
                while(d % 3 == 0) { p3[i+1]++; d /= 3; }
                if(d == 5) p5[i+1]++;
                if(d == 7) p7[i+1]++;
            }
        }

        // 4. Slide backwards to find the optimal divergence point
        for (int i = n - 1; i >= 0; i--) {
            if (i > first_zero) continue; // We cannot keep a prefix that contains a '0'

            int curr_char = num[i] - '0';
            int start_d = max(1, curr_char + 1);
            
            for (int d = start_d; d <= 9; d++) {
                int td = d;
                long long d2 = 0, d3 = 0, d5 = 0, d7 = 0;
                while(td % 2 == 0) { d2++; td /= 2; }
                while(td % 3 == 0) { d3++; td /= 3; }
                if(td == 5) d5++;
                if(td == 7) d7++;

                // What factors are STILL MISSING if we use this prefix + d?
                long long r2 = max(0LL, req2 - p2[i] - d2);
                long long r3 = max(0LL, req3 - p3[i] - d3);
                long long r5 = max(0LL, req5 - p5[i] - d5);
                long long r7 = max(0LL, req7 - p7[i] - d7);

                // Check if missing factors fit into the remaining slots
                vector<int> req_d = get_min_digits(r2, r3, r5, r7);
                int rem_slots = n - 1 - i;
                
                if (req_d.size() <= rem_slots) {
                    string suffix(rem_slots - req_d.size(), '1'); // Pad remaining slots with 1s
                    for (int x : req_d) suffix += to_string(x); 
                    return num.substr(0, i) + to_string(d) + suffix;
                }
            }
        }

        // 5. Fallback: If no combination fits in the same length, expand the string size
        vector<int> optimal_pool = get_min_digits(req2, req3, req5, req7);
        int required_len = max((int)n + 1, (int)optimal_pool.size());
        string padded = string(required_len - optimal_pool.size(), '1');
        for (int d : optimal_pool) padded += to_string(d);
        sort(padded.begin(), padded.end());
        
        return padded;
    }
};
