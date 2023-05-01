#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

int main() {
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    int num_chars = 0, num_words = 0, num_lines = 0;

    // Prompt the user for the input and output filenames
    printf("Enter the input filename: ");
    scanf("%s", input_filename);
    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    // Open the input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Open the output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Read each line of the input file and count the characters, words, and lines
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        int i = 0;
        while (line[i] != '\0') {
            num_chars++;
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                num_words++;
            }
            i++;
        }
        num_words++; // count the last word in the line
        num_lines++;
    }

    // Write the results to the output file
    fprintf(output_file, "Number of characters: %d\n", num_chars);
    fprintf(output_file, "Number of words: %d\n", num_words);
    fprintf(output_file, "Number of lines: %d\n", num_lines);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
