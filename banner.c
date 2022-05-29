/* This program takes in one string argument consisting of only letters a-z or A-Z
 * and prints it as a banner that takes up 6 lines. Each letter in the string
 * printed is printed with it's own letter. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_LETTERS 26
#define SIZE 6

/* A directory of the letters A-Z (indexed as A=0...Z=26) as 6x6 images. The binary
 * representation of these numbers represents their respective letter as a 6x6 reversed "image",
 * considering 0s as spaces and 1s as printed characters. Each number has a specific 36 bits
 * and each group of 6 bits represents a row of the image of the letter reversed. */
long dir[] = {0x861FE148C, 0x7E185F85F, 0x7A104185E, 0x7E186185F, 0xFC105F07F, 0x4105F07F,
              0x7A1E4185E, 0x86187F861, 0x104104104, 0x7A1820820, 0x85124F461, 0xFC1041041,
              0x86186DCE1, 0x871A658E1, 0x7A186185E, 0x417E185F,  0xB91A6185E, 0x8517E185F,
              0x7A181E05E, 0x20820823E, 0x7A1861861, 0x312861861, 0x873B61861, 0x85230C4A1,
              0x104104291, 0xFC210843F};

void print_string(char *word);

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int i;
        char *word = argv[1];
        for (i = 0; word[i] != '\0'; i++) {
            /* Will only take in letters a-z, A-Z, or a space. */
            if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z') ||
                word[i] == 32) {
                word[i] = toupper(word[i]);
            } else {
                printf("Enter a valid character from a-z or A-Z.\n");
                return 1;
            }
        }

        /* Calls the function to print the letters in the word. */
        print_string(word);

        return 0;
    }

    printf("Needs 2 arguments: string, character.\n");
    return 1;
}

void print_string(char *word) {
    int i, j, length, rows, pos, offset;
    char ch;

    length = strlen(word);
    rows = SIZE;
    offset = 0;

    /* Iterates through the rows of the to-be-printed images. */
    while (rows--) {
        /* Iterates through the letters of the word given to print. */
        for (i = 0; i < length; i++) {
            pos = word[i] - 'A';
            ch = word[i];

            /* For each letter, prints the its respective row. */
            for (j = 0; j < SIZE; j++) {
                if (dir[pos] & ((long)1 << (j + offset))) {
                    printf("%c", ch);
                } else {
                    printf(" ");
                }
            }

            printf("  ");
        }

        /* Increases the offset by SIZE to move on to the next row in the binary representation. */
        offset += SIZE;
        printf("\n");
    }
}
