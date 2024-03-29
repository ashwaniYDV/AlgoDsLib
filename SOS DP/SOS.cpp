// https://codeforces.com/blog/entry/45223
// https://www.geeksforgeeks.org/sum-subsets-dynamic-programming/

/*
Time  = O(n * 2^n)
Space = O(n * 2^n)
https://www.codechef.com/ICPCIN19/problems/PENS
https://www.codechef.com/problems/COVERING
https://www.codechef.com/SNFL16MR/problems/BEAUTY
*/

/*
Example Problem:
Consider the following problem where we will use Sum over subset Dynamic Programming to solve it. 
Given an array of 2^n integers, we need to calculate function F(x) = ∑Ai such that x&i==i for all x. i.e, i is a bitwise subset of x. 
i will be a bitwise subset of mask x, if x&i==i.
*/


// iterative version
void solve() {
    int x, y, z;
    cin >> n;
    int size = (1 << n);
    int a[size];
    for(int mask = 0; mask < size; mask++) 
        cin >> a[mask];


    int f[size];
    int dp[size][n+1];

    // base case
    for(int mask = 0; mask < size; mask++) {
        dp[mask][0] = a[mask];
    }

    // ordering of these 2 for loops doesn't matter. we can interchange these
    for(int mask = 0; mask < size; mask++) {
        for(int i = 1; i <= n; i++) {
            // case 1: ith bit is on (since binary rep is 0 indexed, we'll use (i-1) in code)
            if(mask & (1 << (i-1))) {
                dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1 << (i-1))][i-1];
            }
            // case 2: ith bit is off
            else {
                dp[mask][i] = dp[mask][i-1];
            }
        }
    }

    for(int mask = 0; mask < size; mask++) {
        f[mask] = dp[mask][n];
    }

    for(int mask = 0; mask < size; mask++) {
        cout << f[mask] << " ";
    }
}














void solve() {
    int x, y, z;
    cin >> n;
    int size = (1 << n);
    int a[size];
    for(int mask = 0; mask < size; mask++) 
        cin >> a[mask];


    int f[size];
    int dp[size][n+1];

    // base case
    for(int mask = 0; mask < size; mask++) {
        dp[mask][0] = a[mask];
    }

    for(int i = 1; i <= n; i++) {
        for(int mask = 0; mask < size; mask++) {
            // case 1: ith bit is on (since binary rep is 0 indexed, we'll use (i-1) in code)
            if(mask & (1 << (i-1))) {
                dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1 << (i-1))][i-1];
            }
            // case 2: ith bit is off
            else {
                dp[mask][i] = dp[mask][i-1];
            }
        }
    }

    for(int mask = 0; mask < size; mask++) {
        f[mask] = dp[mask][n];
    }

    for(int mask = 0; mask < size; mask++) {
        cout << f[mask] << " ";
    }
}























// iterative version
void solve() {
    int x, y, z;
    cin >> n;
    int size = (1 << n);
    int a[size];
    for(int mask = 0; mask < size; mask++) 
        cin >> a[mask];

    int f[size];
    int dp[size][n];

    for(int mask = 0; mask < size; mask++) {
        dp[mask][-1] = a[mask]; // handle base case separately (leaf states)
        for(int i = 0;i < n; i++) {
            // case 1: ith bit is set
            if(mask & (1 << i)) {
                dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1 << i)][i-1];
            }
            // case 2: ith bit is off
            else {
                dp[mask][i] = dp[mask][i-1];
            }
        }
        f[mask] = dp[mask][n-1];
    }

    for(int mask = 0; mask < size; mask++) {
        cout << f[mask] << " ";
    }
}






















// memory optimized, super easy to code.
void solve() {
    int x, y, z;
    cin >> n;
    int size = (1 << n);
    int a[size];
    for(int mask = 0; mask < size; mask++) 
        cin >> a[mask];

    int f[size];

    for(int mask = 0; mask < size; mask++) {
        f[mask] = a[mask];
    }
    for(int i = 0; i < n; ++i) {
        for(int mask = 0; mask < size; mask++) {
            if(mask & (1 << i)) {
                f[mask] += f[mask^(1 << i)];
            }
        }
    }

    for(int mask = 0; mask < size; mask++) {
        cout << f[mask] << " ";
    }
}
