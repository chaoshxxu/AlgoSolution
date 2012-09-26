class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;

        if (num.size() < 4) {
            return ans;
        }

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++) {
                for (int k = j + 1, l = num.size() - 1; k < num.size(); k++) {
                    while (l > k + 1 && num[i] + num[j] + num[k] + num[l - 1] >= target) {
                        --l;
                    }
                    if (l > k && num[i] + num[j] + num[k] + num[l] == target) {
                        vector<int> add;
                        add.push_back(num[i]);
                        add.push_back(num[j]);
                        add.push_back(num[k]);
                        add.push_back(num[l]);
                        ans.push_back(add);
                    }
                    while (k + 1 < num.size() && num[k] == num[k + 1])++k;
                }
                while (j + 1 < num.size() && num[j] == num[j + 1])++j;
            }
            while (i + 1 < num.size() && num[i] == num[i + 1])++i;
        }
        return ans;
    }
};
