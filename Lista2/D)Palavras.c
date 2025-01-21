#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 65536
#define MAX_WORD_LENGTH 16

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
    bool occupied;
} WordEntry;

WordEntry hashTable[HASH_SIZE];

unsigned int hash(const char* word) {
    unsigned int hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_SIZE;
}

int findWordIndex(const char* word) {
    unsigned int index = hash(word);
    unsigned int originalIndex = index;
    while (hashTable[index].occupied) {
        if (strcmp(hashTable[index].word, word) == 0) {
            return index;
        }
        index = (index + 1) % HASH_SIZE;
        if (index == originalIndex) {
            break;  // Evita loop infinito se a tabela estiver cheia
        }
    }
    return -1;
}

void addWord(const char* word) {
    unsigned int index = hash(word);
    while (hashTable[index].occupied) {
        if (strcmp(hashTable[index].word, word) == 0) {
            hashTable[index].count++;
            return;
        }
        index = (index + 1) % HASH_SIZE;
    }
    strcpy(hashTable[index].word, word);
    hashTable[index].count = 1;
    hashTable[index].occupied = true;
}

void resetWord(const char* word) {
    int index = findWordIndex(word);
    if (index != -1) {
        hashTable[index].count = 0;
    }
}

int getWordCount(const char* word) {
    int index = findWordIndex(word);
    return (index != -1) ? hashTable[index].count : 0;
}

bool isValidWord(const char* word) {
    size_t len = strlen(word);
    if (len == 0 || len > MAX_WORD_LENGTH) {
        return false;
    }
    for (size_t i = 0; i < len; i++) {
        if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))) {
            return false;
        }
    }
    return true;
}

int main() {
    char commandLine[64];
    while (fgets(commandLine, sizeof(commandLine), stdin)) {
        int command;
        char word[MAX_WORD_LENGTH + 1];

        if (sscanf(commandLine, "%d %s", &command, word) == 2) {
            if (!isValidWord(word)) {
                fprintf(stderr, "Error: Invalid word '%s'.\n", word);
                continue;
            }
            switch (command) {
                case 1:
                    addWord(word);
                    break;
                case 2:
                    printf("%d\n", getWordCount(word));
                    break;
                case 3:
                    resetWord(word);
                    break;
                default:
                    fprintf(stderr, "Error: Invalid command '%d'.\n", command);
                    break;
            }
        } else {
            fprintf(stderr, "Error: Invalid input format.\n");
        }
    }

    return 0;
}