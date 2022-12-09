#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int c, len, mid, tmp, result;
    result = 0;
    char str[50];
    while ((c = getchar()) != EOF) {
        if(c != '\n'){
            strncat(str, (char * restrict) &c, 1); // build string
        } else {
            len = strlen(str);
            mid = len / 2;
            for (int i = 0; i < mid; i++) {
                for(int j = mid; j < len; j++){
                    if(str[i] == str[j]){
                        tmp = str[i];
                    }
                }
            }
            if (tmp >= 'A' && tmp <= 'Z') result += tmp - 'A' + 27;
            else if (tmp >= 'a' && tmp <= 'z') result += tmp - 'a' + 1;
            
            memset(str,0,strlen(str)); // clear string
            len = 0;
        }
    }
    printf("%d\n", result);
}
