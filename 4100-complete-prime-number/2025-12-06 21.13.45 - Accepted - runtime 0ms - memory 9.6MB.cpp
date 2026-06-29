class Solution {
public:
    bool isPrime(int num) {
        if (num < 2)
            return false;
        if(num==2) return true;
        if(num%2==0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    bool completePrime(int num) {
        string nums = to_string(num);
        int n = nums.length();

        for (int i = 1; i <= n; i++) {
            int pre = stoi(nums.substr(0, i));
            if (!isPrime(pre))
                return false;
        }
        for (int i = 0; i < n; i++) {
            int suf = stoi(nums.substr(i));
            if (!isPrime(suf))
                return false;
        }
        return true;
    }
};