class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> _pq;
    int _k;

    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int n : nums)
            add(n);
    }

    int add(int val) {
        _pq.push(val);
        if (_pq.size() > _k) {
            _pq.pop();
        }

        return _pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */