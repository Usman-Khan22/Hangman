#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
# define MAX_ATTEMPTS 6

void generateWord(char* word);
void initGuessedWord(char* guessedWord, char* word);
void printGuessedWord(char* guessedWord);
void addGuess(char* guessedLetters, char guess);
char checkInput(char* guessedLetters, char* word);

int main() {
	printf("======HANGMAN GAME======\n");
    char word[50], guessedWord[50], guessedLetters[50] = {'\0'};
    int wrong_attempts = 0;
    srand(time(NULL));

    
    
    return 0;
}

void generateWord(char* word) {
    FILE *fptr;
    char arrWords[200][50];
    int size = 0, index;
    
    
    fptr = fopen("words.txt", "r");
    
    if (fptr == NULL) {
    	printf("error in opening file\n");
        word[0] = '\0';
    	return;
	}
	
    while (fgets(arrWords[size], sizeof(arrWords[size]), fptr)) {
    	size++;
	}
	
    fclose(fptr);
    
    index = rand() % size;
    strcpy(word, arrWords[index]);
    word[strcspn(word, "\n")] = '\0';     
}

void initGuessedWord(char* guessedWord, char* word) {
    int i;
    int len = strlen(word); 
    for (i = 0; i < len; i++) {
        guessedWord[i] = '_';
        printf("%c ", guessedWord[i]);
    }
    guessedWord[len] = '\0';
}

void printGuessedWord(char* guessedWord) {
    int i;
    for (i = 0; i < strlen(guessedWord); i++) {
        printf("%c ", guessedWord[i]);
    }
    printf("\n");
}

void addGuess(char* guessedLetters, char guess) {
    int len = strlen(guessedLetters);
    guessedLetters[len] = guess;
    guessedLetters[len + 1] = '\0';
}


char checkInput(char* guessedLetters, char* word) {
	char guess;
    int i, found = 0;

    printf("Make a guess: ");
    scanf(" %c", &guess);
    while (strchr(guessedLetters, guess)) {
        printf("You already guessed that letter - Try again: ");
        scanf(" %c", &guess);
    }
    addGuess(guessedLetters, guess);

    return guess;
}

int logic(char* word, char guess, char* guessedWord, int wrong_attempts) {
    int i, found = 0;

    for (i = 0; word[i] != '\0'; i++){
        if (word[i] == guess) {
            guessedWord[i] = guess;
            found = 1;
        }
    }
    if (found == 0) wrong_attempts++;
    printGuessedWord(guessedWord);
    
    return wrong_attempts;
}