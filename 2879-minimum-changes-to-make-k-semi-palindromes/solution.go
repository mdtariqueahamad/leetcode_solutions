func segmentCost(s string, l, m int, factors [][]int) int {
	best := m
	for _, d := range factors[m] {
		groups := m / d // Each group contains groups characters
		changes := 0
		for offset := 0; offset < d; offset++ {
			for t := 0; t < groups/2; t++ { // Pair characters from opposite ends of the group
				if s[l+offset+t*d] != s[l+offset+(groups-1-t)*d] {
					changes++
				}
			}
		}
		best = min(best, changes)
	}
	return best
}

func minimumChanges(s string, k int) int {
	n := len(s)
	factors := make([][]int, n+1)
	// Precompute the proper divisors of each number
	for d := 1; d <= n/2; d++ {
		for m := d * 2; m <= n; m += d {
			factors[m] = append(factors[m], d)
		}
	}
	cost := make([][]int, n)
	for l := range cost {
		cost[l] = make([]int, n)
	}
	for l := 0; l+1 < n; l++ {
		for r := l + 1; r < n; r++ { // Each substring must have length at least 2
			cost[l][r] = segmentCost(s, l, r-l+1, factors)
		}
	}

	prev := make([]int, n)
	for start := 0; start < n; start++ { // The case seg = 1
		prev[start] = cost[start][n-1]
	}
	for seg := 2; seg <= k; seg++ { // Increase the number of segments from 2 to k
		cur := make([]int, n)
		for i := range cur {
			cur[i] = n
		}
		limit := n - 1 - 2*(seg-1)
		for start := 0; start+2*seg <= n; start++ { // Leave at least 2*seg characters
			for e := start + 1; e <= limit; e++ {
				cur[start] = min(cur[start], cost[start][e]+prev[e+1])
			}
		}
		prev = cur
	}
	return prev[0]
}
