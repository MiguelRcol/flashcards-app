#include <stdio.h>

int main(void) {
    
    printf("FLashcards language app!\n");
    
    int option = 0;
    
    do
    {
        //1. print menu
        printf("1. Add flashcard\n");
        printf("2. Review flashcards\n");
        printf("3. Delete flashcard\n");
        printf("4. Exit\n");
        //2 ask for option
        printf("Select an option: ");
        scanf("%d", &option);
        //4. switch case for options
        switch (option)
        {
        case 1:
            printf("Add flashcard selected.\n");
            break;
        case 2:
            printf("Review flashcards selected.\n");
            break;
        case 3:
            printf("Delete flashcard selected.\n");
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    } while (option != 4);
    
    return 0;
}
    