class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // Step 1: Ignore leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check positive or negative sign
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // Step 3: Read digits and check overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Check overflow before updating result
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};