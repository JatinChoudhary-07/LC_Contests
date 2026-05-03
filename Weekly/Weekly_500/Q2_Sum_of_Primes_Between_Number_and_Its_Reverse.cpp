/*
Contest     : Weekly Contest 500
Question    : Q2
Problem     : Sum of Primes Between Number and Its Reverse

Topic       : Math / Number Theory
Approach    : Prime Checking + Digit Reversal

Time        : O((R - L + 1) * sqrt(N))
Space       : O(1)
*/

class Solution {
public:

    bool isPrime(int n) {

        if (n <= 1) {
            return false;
        }

        for (int i = 2; i * i <= n; i++) {

            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int reverse(int n) {

        int rev = 0;

        while (n > 0) {

            int digit = n % 10;

            rev = rev * 10 + digit;

            n /= 10;
        }

        return rev;
    }

    int sumOfPrimesInRange(int n) {

        int reversedNumber = reverse(n);

        int left = min(n, reversedNumber);
        int right = max(n, reversedNumber);

        int sum = 0;

        for (int i = left; i <= right; i++) {

            if (isPrime(i)) {
                sum += i;
            }
        }

        return sum;
    }
};
