#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *choices[] = {"Rock", "Paper", "Scissors"};

struct Round {
    int user;
    int computer;
    int result;         
};
union Message {
    char text[30];
};
int getUserChoice() {
    int ch;
    printf("\n1. Rock\n2. Paper\n3. Scissors\nEnter your choice: ");
    scanf("%d", &ch);
    return ch - 1;              
}
int getComputerChoice() {
    return rand() % 3;         
}
int checkResult(int user, int comp) {
    if (user == comp)
        return 4;              

    if ((user == 0 && comp == 2) ||
        (user == 1 && comp == 0) ||
        (user == 2 && comp == 1))
        return 1;               

    return 2;                   
}
void saveToFile(struct Round *r) {
    FILE *fp = fopen("results.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "You: %s | Computer: %s | Result: %d\n",
            choices[r->user], choices[r->computer], r->result);
    fclose(fp);
}

void displayResult(struct Round *r) {
    union Message msg;

    if (r->result & 1)
        strcpy(msg.text, "You Win!");
    else if (r->result & 2)
        strcpy(msg.text, "You Lose!");
    else
        strcpy(msg.text, "It's a Draw!");

    printf("\nResult: %s\n", msg.text);
}

int main() {

    srand(time(0));     

    char again = 'y';

    while (again == 'y' || again == 'Y') {

        struct Round *round = (struct Round *)malloc(sizeof(struct Round));
        round->user = getUserChoice();

        if (round->user < 0 || round->user > 2) {
            printf("Invalid Input!\n");
            free(round);
            continue;
        }

        round->computer = getComputerChoice();

        printf("\nYou chose: %s", choices[round->user]);
        printf("\nComputer chose: %s\n", choices[round->computer]);

        round->result = checkResult(round->user, round->computer);

        displayResult(round);
        saveToFile(round);
        free(round);

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &again);
    }

    printf("\nThanks for playing! Results saved in results.txt\n");

    return 0;
}
