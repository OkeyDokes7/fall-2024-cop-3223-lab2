//Name: Michael Bryant
//UCFID: 5673787   
//Class: COP3223C
//Professor: Parra
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char game();
int main(){
    //The game itself will be a helper function, main will loop so there are multiple attempts
    srand(time(NULL));
    //When testing rand() I noticed that when ran multiple times it was fixed, not at all random. After some researched I learned about seeding rand(), as well as this method which consistently produces completely random results
    printf("Welcome to my guessing game! I will generate a number between 1 and 10, and YOU have to guess what it is! Ready\? Go!\n");
    char end = game();
    //Verify if player wants to play again
    while(strcmp(&end, "Y") == 0){
        printf("Alright! Let's go again, get to guessing!\n");
        end = game();
    }
    printf("Bye bye!\n");
    
    return 0;  
}

//The actual game itself
char game(){
    int random, guess, win = 0;
    char loop;
    random = rand()%10+1;
    //Above established all variables and the random number, below is the user trying to guess the random number and recieving feedback on their proximity
    for(int tries = 3; tries > 0; tries--){
        scanf("%d", &guess);
        if(guess == random){
            win++;
            break;
        }
        if(tries!=1){
            if(guess > random){
                printf("%d is too high!\n", guess);
            }
            else{
                printf("%d is too low!\n", guess);
            }
        }
    }
    //Check if the player won or not, then ask if they want to play again, then returning to the while loop in main (Line 18)
    if(win>0){
        printf("\aThat was the number! Congratulations! Would you like to keep playing? Enter Y if yes, N if no.\n");
    }
    else{
        printf("Aw man, the number was %d all along! Would you like to try again? Enter Y if yes, N if no.\n", random);
    }
    scanf(" %c", &loop); 
    return loop;
}