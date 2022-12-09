#include <stdio.h>
#include <ctype.h>

int main() {
    int c, tmp, carry, p1, p2, p3; 
    tmp = carry = p1 = p2 = p3 = 0;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            tmp = (tmp * 10) + (c - '0');
        } else {
            if(tmp > 0){
                carry += tmp;
            } else {
                if(p1 < carry) {
                    p3 = p2;
                    p2 = p1;
                    p1 = carry;
                }
                else if(p2 < carry) {
                    p3 = p2;
                    p2 = carry;
                } 
                else if(p3 < carry) p3 = carry;
                carry = 0;
            }
            tmp = 0;
        }
    }
    printf("%d\n", p1+p2+p3);
}
