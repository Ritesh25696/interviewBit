Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

*************************************************************************************************************

string Solution::fractionToDecimal(int numerator, int denominator) {
     long long int n = numerator, d = denominator;
            if (n == 0) return "0";

            string res;
            if (n < 0 ^ d < 0) res += '-';
            n = abs(n), d = abs(d);
            res += to_string((n / d));
            if (n % d == 0) return res;
            res += '.';

            unordered_map<int, int> map;
            for (long long int r = n % d; r; r %= d) {

                if (map.find(r) != map.end()) {
                    res.insert(map[r], "(");
                    res += ')';
                    break;
                }
                map[r] = res.size();
                r *= 10;
                res.push_back((char)('0' + (r / d)));
            }

            return res;    

}
