Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

***************************************************************************************************************

string Solution::minWindow(string S, string T) {
 if (S.length() < T.length()) return "";
        unordered_map<char, int> counts;
        for (int i = 0; i < T.length(); i++) {
            if (counts.find(T[i]) == counts.end()) {
                counts[T[i]] = 1;
            } else {
                counts[T[i]]++;
            }
        }
        int start = 0;
        int length = 0;
        int total = 0;
        for (int head = 0, tail = 0; tail < S.length(); tail++) {
            if (counts.find(S[tail]) == counts.end()) {
                continue;
            }
            counts[S[tail]]--;
            if (counts[S[tail]] >= 0) {
                total++;
            }
            if (total == T.size()) {
                while (counts.find(S[head]) == counts.end() || counts[S[head]] < 0) {
                    if (counts.find(S[head]) != counts.end()) counts[S[head]]++;
                    head++;
                }
                if (length == 0 || tail - head + 1 < length) {
                    length = tail - head + 1;
                    start = head;
                }
            }
        }
        return S.substr(start, length);}
