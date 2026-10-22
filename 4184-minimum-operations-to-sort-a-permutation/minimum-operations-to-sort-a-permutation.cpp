class Solution {
public:
    int minOperations(vector<int>& A) {
        int n = A.size();
        int asc = 1, dsc = 1;

        for (int i = 1; i < n; i++) {
            asc += A[i] == (A[i - 1] + 1) % n;
            dsc += A[i - 1] == (A[i] + 1) % n;
        }

        if (asc == n) {
            if (A.front() == 0) return 0;
            return min(n - A.front(), A.front() + 2);
        }

        if (dsc == n) {
            return min(n - A.back(), A.back()) + 1;
        }

        return -1;
    }
};