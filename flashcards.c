#include <stdio.h>

int main(void) {
    printf("Flashcards language app!\n");

    int option = 0;

    do
    {
        printf("\n=== FLASHCARDS APP ===\n");
        printf("1. Add new flashcard\n");
        printf("2. List flashcards\n");
        printf("3. Quiz mode\n");
        printf("4. Save & Exit\n");
        printf("0. Exit without saving\n");

        printf("Select an option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Add new flashcard selected.\n");
                break;
            case 2:
                printf("List flashcards selected.\n");
                break;
            case 3:
                printf("Quiz mode selected.\n");
                break;
            case 4:
                printf("Saving and exiting...\n");
                break;
            case 0:
                printf("Exiting without saving...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }

    } while (option != 0 && option != 4);

    return 0;
}
