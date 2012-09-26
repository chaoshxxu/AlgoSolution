class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        bool carry = false;
        string res = "";
        for (int i = 0; i < a.length() || i < b.length() ; i++) {
            res += (carry ^ (i < a.length() && a[i] == '1') ^ (i < b.length() && b[i] == '1')) ? "1" : "0";
            carry = (carry + (i < a.length() && a[i] == '1') + (i < b.length() && b[i] == '1')) > 1;
        }
        if (carry) {
            res += "1";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
