#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int c, count, tmp, result;
    result = count = 0;
    char str[50], str2[50], str3[50];
    while ((c = getchar()) != EOF) {
        if(c != '\n' && count == 0){
            strncat(str, (char * restrict) &c, 1); // build string
        }
        else if(c != '\n' && count == 1){
            strncat(str2, (char * restrict) &c, 1);
        }
        else if(c != '\n' && count == 2){
            strncat(str3, (char * restrict) &c, 1);
        } else {
            count++;
        }
        if(count == 3){
            count = 0;
            for(int i = 0; i < strlen(str); i++){
                // check if char is in str2 and str3
                if(strchr(str2, str[i]) != NULL && strchr(str3, str[i]) != NULL){
                    tmp = str[i];
                }
            }
            if (tmp >= 'A' && tmp <= 'Z') result += tmp - 'A' + 27;
            else if (tmp >= 'a' && tmp <= 'z') result += tmp - 'a' + 1;
            
            // clear strings
            memset(str,0,strlen(str)); 
            memset(str2,0,strlen(str2)); 
            memset(str3,0,strlen(str3));
        }
    }
    printf("%d\n", result);
}
