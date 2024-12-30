#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long decode_base(const char *value, int base) {
    long long result = 0;
    int len = strlen(value);
    for (int i = 0; i < len; i++) {
        char ch = value[i];
        int digit;
        if (ch >= '0' && ch <= '9') {
            digit = ch - '0';
        } else if (ch >= 'a' && ch <= 'f') {
            digit = ch - 'a' + 10;
        } else {
            digit = ch - 'A' + 10;
        }
        result = result * base + digit;
    }
    return result;
}

long long lagrange_interpolation_at_zero(int *x_values, long long *y_values, int n) {
    long long c = 0;
    for (int i = 0; i < n; i++) {
        long long term = y_values[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= x_values[j];
                term /= (x_values[i] - x_values[j]);
            }
        }
        c += term;
    }
    return c;
}

int main() {
    int n1 = 4, k1 = 3;
    int x_values_1[] = {1, 2, 3, 6};
    char *values_1[] = {"4", "111", "12", "213"};
    int base_values_1[] = {10, 2, 10, 4};
    long long y_values_1[4];

    for (int i = 0; i < n1; i++) {
        y_values_1[i] = decode_base(values_1[i], base_values_1[i]);
    }

    long long c1 = lagrange_interpolation_at_zero(x_values_1, y_values_1, k1);
    printf("Secret for Test Case 1: %lld\n", c1);

    int n2 = 10, k2 = 7;
    int x_values_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char *values_2[] = {
        "13444211440455345511", "aed7015a346d63", "6aeeb69631c227c", "e1b5e05623d881f", 
        "316034514573652620673", "2122212201122002221120200210011020220200", 
        "20120221122211000100210021102001201112121", "20220554335330240002224253", 
        "45153788322a1255483", "1101613130313526312514143"
    };
    int base_values_2[] = {6, 15, 15, 16, 8, 3, 3, 6, 12, 7};
    long long y_values_2[10];

    for (int i = 0; i < n2; i++) {
        y_values_2[i] = decode_base(values_2[i], base_values_2[i]);
    }

    long long c2 = lagrange_interpolation_at_zero(x_values_2, y_values_2, k2);
    printf("Secret for Test Case 2: %lld\n", c2);

    return 0;
}
