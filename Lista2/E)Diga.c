#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int compare(const void *a, const void *b) {
    int freqA = ((int*)a)[1];
    int freqB = ((int*)b)[1];
    
    if (freqA == freqB) {
        return ((int*)a)[0] - ((int*)b)[0];
    }
    return freqA - freqB;
}

int main() {
    char line[1001];
    int freq[MAX_CHAR];
    int ascii_freq[2 * MAX_CHAR];

    while (fgets(line, sizeof(line), stdin)) {
        memset(freq, 0, sizeof(freq));

        for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
            freq[(unsigned char)line[i]]++;
        }

        int idx = 0;
        for (int i = 0; i < MAX_CHAR; i++) {
            if (freq[i] > 0) {
                ascii_freq[idx++] = i;
                ascii_freq[idx++] = freq[i];
            }
        }

        qsort(ascii_freq, idx / 2, sizeof(int) * 2, compare);

        for (int i = 0; i < idx; i += 2) {
            printf("%d %d\n", ascii_freq[i], ascii_freq[i + 1]);
        }

        printf("\n");
    }

    return 0;
}
