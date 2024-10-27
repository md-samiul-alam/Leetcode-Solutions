class Solution {
public:

    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size() > b.size()) {
            int _short = a.size() - b.size();
            while(_short--)b.push_back('0');
        }
        else {
            int _short = b.size() - a.size();
            while(_short--)a.push_back('0');
        }
        char carry = '0';
        string s = "";
        for(int i=0; i<a.size(); i++) {
            int sum = carry + a[i] + b[i] - '0' - '0' - '0';
            if(sum == 0) {
                s.push_back('0');
                carry = '0';
            }
            else if(sum == 1) {
                s.push_back('1');
                carry = '0';
            }
            else if(sum == 2) {
                s.push_back('0');
                carry = '1';
            }
            else if(sum == 3) {
                s.push_back('1');
                carry = '1';
            }
        }
        if(carry == '1') {
            s.push_back('1');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
