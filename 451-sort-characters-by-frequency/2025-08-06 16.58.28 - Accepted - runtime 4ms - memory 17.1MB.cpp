class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char ch : s) freq[ch]++;

    int n = s.size();
    vector<vector<char>> buckets(n + 1);

    for (auto [ch, f] : freq)
        buckets[f].push_back(ch);

    string result = "";
    for (int i = n; i >= 1; --i) {
        for (char ch : buckets[i]) {
            result.append(i, ch);
        }
    }

    return result;
}

};