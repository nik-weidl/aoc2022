#include <stdio.h>
#include <ctype.h>

int main() {
    int c, tmp, carry, result;
    tmp = carry = result = 0;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            tmp = (tmp * 10) + (c - '0');
        } else {
            if(tmp > 0){
                carry += tmp;
            } else {
                if(result < carry) result = carry;
                carry = 0;
            }
            tmp = 0;
        }
    }
    printf("%d\n", result);
}
