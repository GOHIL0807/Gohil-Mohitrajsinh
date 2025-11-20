#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

// Function to reverse a string in place
void reverse(char *start, char *end) {
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    FILE *fp = fopen("Demo.txt", "r");
    if (!fp) {
        printf("Could not open file Demo.txt\n");
        return 1;
    }

    char line[MAX_LINE];
    // Process each line in the file
    while (fgets(line, MAX_LINE, fp)) {
        int len = strlen(line);
        int i = 0;

        while (i < len) {
            // Skip any leading spaces
            while (i < len && isspace(line[i]))
                putchar(line[i++]);

            int word_start = i;
            // Find the end of the word
            while (i < len && !isspace(line[i]))
                i++;

            int word_end = i - 1;
            // Reverse and display the word
            if (word_start <= word_end) {
                for (int j = word_end; j >= word_start; j--)
                    putchar(line[j]);
            }
        }
    }

    fclose(fp);
    return 0;
}
