#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, min, max, number, guess;
    int attempts = 0, maxAttempts = 7;
    int diff, range;
    float percent;

    srand(time(0));   

    printf("=====================================\n");
    printf("        NUMBER GUESSING GAME\n");
    printf("=====================================\n\n");

    printf("Select Difficulty Level:\n");
    printf("1. Easy   (Number between 1 and 10)\n");
    printf("2. Medium (Number between 1 and 50)\n");
    printf("3. Hard   (Number between 1 and 100)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

  
    if (choice == 1)
    {
        min = 1;
        max = 10;
    }
    else if (choice == 2)
    {
        min = 1;
        max = 50;
    }
    else if (choice == 3)
    {
        min = 1;
        max = 100;
    }
    else
    {
        printf("\nInvalid choice! Please restart the game.\n");
        return 0;
    }

    range = max - min + 1;
    number = (rand() % range) + min;

    printf("\nI have selected a number between %d and %d.\n", min, max);
    printf("You have %d attempts to guess it.\n\n", maxAttempts);

    printf("Hint Guide:\n");
    printf("Very Cold  -> 50%% or more away from the number\n");
    printf("Cold       -> 30%% to 49%% away\n");
    printf("Hot        -> 10%% to 29%% away\n");
    printf("Very Hot   -> Less than 10%% away\n\n");

    // Guessing loop
    while (attempts < maxAttempts)
    {
        printf("Attempt %d - Enter your guess: ", attempts + 1);
        scanf("%d", &guess);

        attempts++;

        if (guess == number)
        {
            printf("\n🎉 Congratulations! You guessed the correct number.\n");
            printf("Attempts taken: %d\n", attempts);
            return 0;
        }
        else
        {
            diff = guess - number;
            if (diff < 0)
                diff = -diff;

            percent = (float)diff / range;

            if (percent >= 0.5)
                printf("Hint: Very Cold\n\n");
            else if (percent >= 0.3)
                printf("Hint: Cold\n\n");
            else if (percent >= 0.1)
                printf("Hint: Hot\n\n");
            else
                printf("Hint: Very Hot\n\n");
        }
    }

    printf("You Lose!\n");
    printf("The correct number was: %d\n", number);

    return 0;
}

