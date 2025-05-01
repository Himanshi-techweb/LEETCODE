class Solution {
public:
    bool canAssign(int k, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
    multiset<int> availableWorkers;
    int n = workers.size();

    // Insert the k strongest workers
    for (int i = n - k; i < n; ++i) {
        availableWorkers.insert(workers[i]);
    }

    int p = pills;

    // Assign tasks from hardest to easiest among the first k tasks
    for (int i = k - 1; i >= 0; --i) {
        int task = tasks[i];
        
        // Try to find a worker with enough strength directly
        auto it = availableWorkers.lower_bound(task);
        if (it != availableWorkers.end()) {
            availableWorkers.erase(it);
        } else {
            // Try using a pill on the weakest available worker
            if (p == 0) return false;

            // Find the strongest worker where (worker + strength >= task)
            it = availableWorkers.upper_bound(task - strength - 1);
            if (it == availableWorkers.end()) return false;

            availableWorkers.erase(it);
            p--;
        }
    }

    return true;
}

    int maxTaskAssign(vector<int>& task, vector<int>& worker, int pill, int strength) {
       sort(task.begin(), task.end());
    sort(worker.begin(), worker.end());

    int left = 0, right = min((int)task.size(), (int)worker.size());
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canAssign(mid, task, worker, pill, strength)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
        
    }
};