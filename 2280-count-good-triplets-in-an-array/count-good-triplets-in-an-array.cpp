class FenwickTree {
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) {
        size = n + 1;
        tree.resize(size, 0);
    }

    void update(int index, int delta) {
        index += 1;  // 1-based indexing
        while (index < size) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index += 1;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // Step 1: Map value to index in nums2
        vector<int> posInNums2(n);
        for (int i = 0; i < n; ++i) {
            posInNums2[nums2[i]] = i;
        }

        // Step 2: Map nums1 to their positions in nums2
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = posInNums2[nums1[i]];
        }

        // Step 3: Count elements less than current to the left
        FenwickTree leftTree(n);
        vector<int> leftCount(n);
        for (int i = 0; i < n; ++i) {
            leftCount[i] = (mapped[i] > 0) ? leftTree.query(mapped[i] - 1) : 0;
            leftTree.update(mapped[i], 1);
        }

        // Step 4: Count elements greater than current to the right
        FenwickTree rightTree(n);
        vector<int> rightCount(n);
        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] = rightTree.query(n - 1) - rightTree.query(mapped[i]);
            rightTree.update(mapped[i], 1);
        }

        // Step 5: Calculate total good triplets
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += (long long)leftCount[i] * rightCount[i];
        }

        return total;
    }
};