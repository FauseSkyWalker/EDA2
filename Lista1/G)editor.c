#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 101
#define MAX_EDITS 1000

int main() {
    char stack[MAX_EDITS][MAX_STR];
    int top = -1;
    char command[110];

    while (fgets(command, sizeof(command), stdin) != NULL) {
        if (strncmp(command, "inserir ", 8) == 0) {
            if (top < MAX_EDITS - 1) {
                top++;
                strncpy(stack[top], command + 8, MAX_STR - 1);
                stack[top][strcspn(stack[top], "\n")] = '\0';
            }
        } else if (strcmp(command, "desfazer\n") == 0) {
            if (top == -1) {
                printf("NULL\n");
            } else {
                printf("%s\n", stack[top]);
                top--;
            }
        }
    }

    return 0;
}
