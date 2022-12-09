#include <stdio.h>
#include <ctype.h>

int main() {
    int c, tmp, leftA, leftB, rightA, rightB, result;
    tmp = leftA = leftB = rightA = rightB = result = 0; 
    while ((c = getchar()) != EOF) {
        if(c != '\n'){
            if(isdigit(c)){
                tmp = (tmp * 10) + (c - '0');
            } else {
                if(leftA == 0) leftA = tmp;
                else if(leftB == 0) leftB = tmp;
                else if(rightA == 0) rightA = tmp;
                tmp = 0;
            }
        } else {
            rightB = tmp;

            if((leftA <= rightA && rightA <= leftB) || (rightA <= leftA && leftA <= rightB)) result++; // Overlap
            leftA = leftB = rightA = rightB = tmp = 0;
        }
    }
    printf("%d\n", result);
}
