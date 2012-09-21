class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());

        int ans = 99999999;
        int sum;

        for (int i = 0; i < num.size(); i++) {
            int k = num.size() - 1;
            for (int j = i + 1; j < num.size(); j++) {
                while (k - 1 > j && num[i] + num[j] + num[k - 1] - target >= 0) {
                    --k;
                }
                if (k - 1 > j) {
                    sum = num[i] + num[j] + num[k - 1];
                    if (abs(sum - target) < abs(ans - target)) {
                        ans = sum;
                    }
                }
                if (k > j) {
                    sum = num[i] + num[j] + num[k];
                    if (abs(sum - target) < abs(ans - target)) {
                        ans = sum;
                    }
                }
            }
        }
        return ans;

    }
};
