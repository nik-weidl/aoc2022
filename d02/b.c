#include <stdio.h>

/*
    RULES:
    A,X = ROCK, B,Y = PAPER, C,Z = SCISSORS

    1 for Rock, 2 for Paper, and 3 for Scissors
    0 if you lost, 3 if the round was a draw, and 6 if you won

    X beats C, Y beats A, Z beats B
    X ties A, Y ties B, Z ties C
    X loses to B, Y loses to C, Z loses to A 
*/

int main() {
    int c, attack, roundresult, result;
    attack = roundresult = result = 0;
    while ((c = getchar()) != EOF) {
        if(c == 'A' || c == 'B' || c == 'C'){
            attack = c;
        }
        if((c == 'X' || c == 'Y' || c == 'Z') && attack != 0){
            if(attack == 'A'){ // rock
                if(c == 'X') roundresult = 3+0; // lose
                else if(c == 'Y') roundresult = 1+3; // draw
                else if(c == 'Z') roundresult = 2+6; // win
            }
            else if(attack == 'B'){ // paper
                if(c == 'X') roundresult = 1+0; // lose
                else if(c == 'Y') roundresult = 2+3; // draw
                else if(c == 'Z') roundresult = 3+6; // win
            } 
            else if(attack == 'C'){ // scissors
                if(c == 'X') roundresult = 2+0; // lose
                else if(c == 'Y') roundresult = 3+3; // draw
                else if(c == 'Z') roundresult = 1+6; // win
            }
            result += roundresult;
            attack = 0;
        }
    }
    printf("%d\n", result);
}
