#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int balance, bet, guess, winNum, choice = 1;
    srand(time(NULL)); // Seed random generator

    printf("=== LUCKY DRAW CASINO ===\n");
    printf("Enter starting deposit (Rs.): ");
    scanf("%d", &balance);

    while (balance > 0 && choice == 1) {
        printf("\nCurrent Balance: Rs. %d\n", balance);
        printf("Enter bet amount: ");
        scanf("%d", &bet);

        if (bet <= 0 || bet > balance) {
            printf("Invalid bet! Enter between 1 and %d.\n", balance);
            continue;
        }

        printf("Pick a lucky number (1 to 10): ");
        scanf("%d", &guess);

        if (guess < 1 || guess > 10) {
            printf("Out of range! Pick between 1 and 10.\n");
            continue;
        }

        winNum = (rand() % 10) + 1;
        printf("Winning Number: [ %d ]\n", winNum);

        if (guess == winNum) {
            int prize = bet * 5;
            balance += prize;
            printf("JACKPOT! You won +Rs. %d\n", prize);
        } else {
            balance -= bet;
            printf("BAD LUCK! You lost -Rs. %d\n", bet);
        }

        if (balance > 0) {
            printf("Play again? (1 = Yes, 0 = Cash Out): ");
            scanf("%d", &choice);
        }
    }

    printf("\nGame Over! Final Cash Out: Rs. %d\n", balance);
    return 0;
}
