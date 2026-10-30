class Solution {
public:
    static const long long MOD = 1e9 + 7;

    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 2, 0);
        }

        void add(int index, long long value) {
            while (index <= n) {
                bit[index] += value;
                index += index & -index;
            }
        }

        long long query(int index) {
            long long result = 0;

            while (index > 0) {
                result += bit[index];
                index -= index & -index;
            }

            return result;
        }
    };

    struct RangeBIT {
        int n;
        Fenwick bit1;
        Fenwick bit2;

        RangeBIT(int n)
            : n(n), bit1(n), bit2(n) {}

        void rangeAdd(int left, int right, long long value) {
            internalAdd(left, value);
            internalAdd(right + 1, -value);
        }

        long long prefixSum(int index) {
            return index * bit1.query(index) - bit2.query(index);
        }

        long long rangeSum(int left, int right) {
            return prefixSum(right) - prefixSum(left - 1);
        }

    private:
        void internalAdd(int index, long long value) {
            if (index > n) return;

            bit1.add(index, value);
            bit2.add(index, value * (index - 1));
        }
    };

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        RangeBIT bit(n);

        vector<int> lastSeen(100001, 0);

        long long totalSquares = 0;
        long long answer = 0;

        for (int r = 1; r <= n; r++) {
            int value = nums[r - 1];

            int previousPosition = lastSeen[value];

            int left = previousPosition + 1;
            int right = r;

            // Sum of current distinct counts in the affected range.
            long long currentSum = bit.rangeSum(left, right);

            int rangeLength = right - left + 1;

            // (x + 1)^2 - x^2 = 2x + 1
            long long increase =
                2 * currentSum + rangeLength;

            totalSquares =
                (totalSquares + increase) % MOD;

            // Add 1 to every affected starting position.
            bit.rangeAdd(left, right, 1);

            // Add contributions of all subarrays ending at r.
            answer =
                (answer + totalSquares) % MOD;

            lastSeen[value] = r;
        }

        return answer;
    }
};