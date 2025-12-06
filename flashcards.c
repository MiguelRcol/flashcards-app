#include <stdio.h>
#include <string.h>
#define MAX_CARDS 100

typedef struct {
    char word[64];
    char translation[64];
    char language[16];
} Flashcard;

void show_menu(void);
void add_card(Flashcard cards[], int *count);
void list_cards(const Flashcard cards[], int count);
void quiz_mode(const Flashcard cards[], int count);

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
                quiz_mode(cards, card_count);
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
void quiz_mode(const Flashcard cards[], int count) {
    if (count == 0) {
        printf("No flashcards available for quiz.\n");
        return;
    }

    int score = 0;
    char answer[64];

    for (int i = 0; i < count; i++) {
        printf("Translate '%s' (%s): ", cards[i].word, cards[i].language);
        scanf("%63s", answer);

        if (strcmp(answer, cards[i].translation) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct translation is '%s'.\n", cards[i].translation);
        }
    }

    printf("Quiz finished! Your score: %d/%d\n", score, count);
}