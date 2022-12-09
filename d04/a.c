#include <stdio.h>
#include <ctype.h>

int main() {
    int c, tmp, oneA, oneB, twoA, twoB, result;
    tmp = oneA = oneB = twoA = twoB = result = 0; 
    while ((c = getchar()) != EOF) {
        if(c != '\n'){
            if(isdigit(c)){
                tmp = (tmp * 10) + (c - '0');
            } else {
                if(oneA == 0) oneA = tmp;
                else if(oneB == 0) oneB = tmp;
                else if(twoA == 0) twoA = tmp;
                tmp = 0;
            }
        } else {
            twoB = tmp;

            if((oneA >= twoA && oneB <= twoB) || (oneA <= twoA && oneB >= twoB)) result++;
            oneA = oneB = twoA = twoB = tmp = 0;
        }
    }
    printf("%d\n", result);
}
