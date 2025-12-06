#include <stdio.h>

#define MAX_CARDS 100

typedef struct {
    char word[64];
    char translation[64];
    char language[16];
} Flashcard;

void show_menu(void);
void add_card(Flashcard cards[], int *count);
void list_cards(const Flashcard cards[], int count);

int main(void) {
    printf("Flashcards language app!\n");

    Flashcard cards[MAX_CARDS];
    int card_count = 0;
    int option = 0;

    do
    {
        show_menu();

        printf("Select an option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                add_card(cards, &card_count);
                break;
            case 2:
                list_cards(cards, card_count);
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

void show_menu(void) {
    printf("\n=== FLASHCARDS APP ===\n");
    printf("1. Add new flashcard\n");
    printf("2. List flashcards\n");
    printf("3. Quiz mode\n");
    printf("4. Save & Exit\n");
    printf("0. Exit without saving\n");
}

void add_card(Flashcard cards[], int *count) {
    if (*count >= MAX_CARDS) {
        printf("Flashcard limit reached!\n");
        return;
    }

    Flashcard new_card;

    printf("Enter word: ");
    scanf("%63s", new_card.word);

    printf("Enter translation: ");
    scanf("%63s", new_card.translation);

    printf("Enter language (EN/PT/ES): ");
    scanf("%15s", new_card.language);

    cards[*count] = new_card;
    (*count)++;

    printf("Flashcard added!\n");
}
void list_cards(const Flashcard cards[], int count) {
    if (count == 0) {
        printf("No flashcards available.\n");
        return;
    }

    printf("\n=== Flashcards List ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s - %s\n", i + 1, cards[i].language, cards[i].word, cards[i].translation);
    }
}