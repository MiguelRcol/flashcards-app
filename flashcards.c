#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
int load_cards(Flashcard cards[]);
void save_cards(const Flashcard cards[], int count);

int main(void) {
    printf("Flashcards language app!\n");

    // Seed the random number generator once
    srand((unsigned int) time(NULL));

    Flashcard cards[MAX_CARDS];
    int card_count = 0;
    int option = 0;

    card_count = load_cards(cards);
    printf("Loaded %d flashcards from file.\n", card_count);

    do {
        show_menu();

        printf("Select an option: ");
        if (scanf("%d", &option) != 1) {
            // Clear invalid input
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            option = -1;
            continue;
        }

        switch (option) {
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
                save_cards(cards, card_count);
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
        printf("%d. [%s] %s - %s\n",
               i + 1,
               cards[i].language,
               cards[i].word,
               cards[i].translation);
    }
}

void quiz_mode(const Flashcard cards[], int count) {
    if (count == 0) {
        printf("No flashcards available for quiz.\n");
        return;
    }

    char answer[64];

    // Pick a random index
    int index = rand() % count;

    printf("Translate '%s' (%s): ",
           cards[index].word,
           cards[index].language);

    scanf("%63s", answer);

    if (strcmp(answer, cards[index].translation) == 0) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct translation is '%s'.\n",
               cards[index].translation);
    }
}

void save_cards(const Flashcard cards[], int count) {
    FILE *file = fopen("flashcards.dat", "wb");
    if (file == NULL) {
        printf("Error saving flashcards!\n");
        return;
    }

    // First write how many cards we have
    if (fwrite(&count, sizeof(int), 1, file) != 1) {
        printf("Error writing card count to file.\n");
        fclose(file);
        return;
    }

    // Then write the array of flashcards
    if (fwrite(cards, sizeof(Flashcard), count, file) != (size_t)count) {
        printf("Error writing flashcards to file.\n");
        fclose(file);
        return;
    }

    fclose(file);
    printf("Flashcards saved successfully.\n");
}

int load_cards(Flashcard cards[]) {
    FILE *file = fopen("flashcards.dat", "rb");
    if (file == NULL) {
        return 0; // No file found, start with zero cards
    }

    int count = 0;

    // Read count
    if (fread(&count, sizeof(int), 1, file) != 1) {
        fclose(file);
        return 0;
    }

    // Clamp to MAX_CARDS to avoid overflow
    if (count < 0) {
        fclose(file);
        return 0;
    }
    if (count > MAX_CARDS) {
        count = MAX_CARDS;
    }

    size_t read = fread(cards, sizeof(Flashcard), count, file);
    fclose(file);

    return (int)read; // in case fewer were read
}
