class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> arr(nums.begin(), nums.end());
        vector<int> prevIdx(n), nextIdx(n);
        vector<bool> active(n, true);

        for (int i = 0; i < n; i++) {
            prevIdx[i] = i - 1;
            nextIdx[i] = (i + 1 < n ? i + 1 : -1);
        }

        // count initial violations
        int violations = 0;
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1]) violations++;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > minHeap;

        for (int i = 0; i < n - 1; i++)
            minHeap.push({arr[i] + arr[i + 1], i});

        int operations = 0;

        while (violations > 0) {
            auto [oldSum, i] = minHeap.top();
            minHeap.pop();

            int j = nextIdx[i];
            if (j == -1 || !active[i] || !active[j]) continue;
            if (arr[i] + arr[j] != oldSum) continue;

            // remove old violations
            if (prevIdx[i] != -1 && arr[prevIdx[i]] > arr[i]) violations--;
            if (arr[i] > arr[j]) violations--;
            if (nextIdx[j] != -1 && arr[j] > arr[nextIdx[j]]) violations--;

            // merge
            arr[i] += arr[j];
            active[j] = false;
            nextIdx[i] = nextIdx[j];
            if (nextIdx[j] != -1)
                prevIdx[nextIdx[j]] = i;

            // add new violations
            if (prevIdx[i] != -1 && arr[prevIdx[i]] > arr[i]) violations++;
            if (nextIdx[i] != -1 && arr[i] > arr[nextIdx[i]]) violations++;

            if (prevIdx[i] != -1)
                minHeap.push({arr[prevIdx[i]] + arr[i], prevIdx[i]});
            if (nextIdx[i] != -1)
                minHeap.push({arr[i] + arr[nextIdx[i]], i});

            operations++;
        }

        return operations;
    }
};
