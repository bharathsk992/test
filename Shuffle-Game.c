#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define true  1
#define false 0

void disp();
void printmenu();
void intro();
void levelmenu();
void easy();
void initial(int x);
void draw(int i);
void userwin();
int check(int key);

int i, step, level, num[9], win;

int main() {
    intro();
    levelmenu();
    easy();

    return 0;
}

void levelmenu() {
    level = 0;
    printf("\nPress 1 to start\n");
    printf("1. Start\n");
    printf("2. Rules\n");
    printf("Enter a choice: ");
    scanf("%d", &level);

    if (level == 2) {
        printf("\nRead the rules:\n");
        printf("1: Arrange the numbers in ascending order\n");
        printf("2: Press the number key to move the numbers\n");
        printf("3: X - Exit\n");
        getchar();  // Consume newline character
        getchar();  // Wait for user input
        levelmenu();
    }
}

void intro() {
    printf("\nSHUFFLE GAME\n");
    printf("Press Enter to start...");

    getchar();  // Wait for user input
    system("cls");  // Clear the screen
}

void printmenu() {
    printf("\nSHUFFLE GAME\n");
    printf("--------------------------\n");
    printf("X = exit game\n");
    printf("--------------------------\n");
    printf("Moves = %d\n", step);
}

void easy() {
    int key, valid;

    initial(9);

    do {
        system("cls");
        printmenu();

        for (i = 0; i < 9; i++) {
            draw(i);
        }

        userwin();

        if (win == true) {
            printf("\nYou have won the game!\n");
            disp();
            break;
        }

        printf("\nTips: Number will move when you key in!\n");
        printf("Enter a number or X to exit: ");

        char input[2];
        scanf("%s", input);

        if (input[0] == 'X' || input[0] == 'x') {
            disp();
            break;
        }

        key = atoi(input);
        valid = check(key);

        if (!valid) {
            printf("\nInvalid move. Press Enter to try again...");
            getchar();  // Wait for user input
            getchar();  // Consume newline character
            continue;
        }

        step++;

        if (step == 50) {
            printf("\nYou have surpassed the maximum possible moves. Press Enter to exit...");
            getchar();  // Wait for user input
            break;
        }

        for (i = 0; i < 9; i++) {
            if (num[i] == key) {
                num[i] = 0;
            }
            else if (num[i] == 0) {
                num[i] = key;
            }
        }

    } while (true);
}

void initial(int x) {
    int no = 0 % x;

    if (no == 1) {
        no += 5;
    }

    for (i = 0; i < x; i++) {
        num[i] = no;
        no += 2;

        if (no >= x) {
            if (!(no % 2)) {
                no = 1;
            }
            else {
                no = 0;
            }
        }
    }
}

void draw(int i) {
    printf("\n");

    if (num[i] == 0) {
        printf("   ");
    }
    else {
        printf(" %d ", num[i]);
    }
}

void disp() {
    printf("\n\nCREDITS:\n");
    printf("USMAN SHAHZADA\n");
    printf("BIT-II\n");
    printf("CIIT\n");

    printf("\nPress Enter to exit...");
    getchar();  // Wait for user input
    getchar();  // Consume newline character
}

int check(int key) {
    int valid = false;

    for (i = 0; i < 9; i++) {
        if (num[i] == key) {
            valid = true;

            switch (i) {
            case 0: if (num[1] != 0 && num[3] != 0) valid = false; break;
            case 1: if (num[0] != 0 && (num[2] != 0 && num[4] != 0)) valid = false; break;
            case 2: if (num[1] != 0 && num[5] != 0) valid = false; break;
            case 3: if (num[0] != 0 && (num[4] != 0 && num[6] != 0)) valid = false; break;
            case 4: if ((num[1] != 0 && num[3] != 0) && (num[5] != 0 && num[7] != 0)) valid = false; break;
            case 5: if (num[2] != 0 && (num[4] != 0 && num[8] != 0)) valid = false; break;
            case 6: if (num[3] != 0 && num[7] != 0) valid = false; break;
            case 7: if (num[4] != 0 && (num[6] != 0 && num[8] != 0)) valid = false; break;
            case 8: if (num[5] != 0 && num[7] != 0) valid = false; break;
            default: valid = false; break;
            }
        }
    }

    return valid;
}

void userwin() {
    win = true;

    for (i = 0; i < 8; i++) {
        if (num[i] != i + 1) {
            win = false;
            break;
        }
    }
}
