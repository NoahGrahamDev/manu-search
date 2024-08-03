#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif

#define MAX_FILENAME_LEN 256

void concatenate_files(const char *directory, const char *output_file) {
    FILE *outfile;

    if ((outfile = fopen(output_file, "w")) == NULL) {
        perror("fopen() error for output file");
        return;
    }

#ifdef _WIN32
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    char search_path[MAX_FILENAME_LEN];

    snprintf(search_path, MAX_FILENAME_LEN, "%s\\*.txt", directory);
    hFind = FindFirstFile(search_path, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        perror("FindFirstFile() error");
        fclose(outfile);
        return;
    }

    do {
        char filepath[MAX_FILENAME_LEN];
        snprintf(filepath, MAX_FILENAME_LEN, "%s\\%s", directory, findFileData.cFileName);

        printf("Processing file: %s\n", filepath); // Debugging output

        FILE *infile = fopen(filepath, "r");
        if (infile == NULL) {
            perror("fopen() error for input file");
            continue;
        }

        int ch;
        while ((ch = fgetc(infile)) != EOF) {
            fputc(ch, outfile);
        }
        fputc('\n', outfile); // Add a newline after each file's content

        fclose(infile);
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
#else
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir() error");
        fclose(outfile);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char filepath[MAX_FILENAME_LEN];
        snprintf(filepath, MAX_FILENAME_LEN, "%s/%s", directory, entry->d_name);

        if (strstr(entry->d_name, ".txt") != NULL) {
            printf("Processing file: %s\n", filepath); // Debugging output

            FILE *infile = fopen(filepath, "r");
            if (infile == NULL) {
                perror("fopen() error for input file");
                continue;
            }

            int ch;
            while ((ch = fgetc(infile)) != EOF) {
                fputc(ch, outfile);
            }
            fputc('\n', outfile); // Add a newline after each file's content

            fclose(infile);
        }
    }

    closedir(dir);
#endif

    fclose(outfile);
    printf("Concatenation complete. Output written to %s\n", output_file);
}

int main() {
    const char *directory = "./Texts"; // Directory containing .txt files
    const char *output_file = "output.txt";

    concatenate_files(directory, output_file);

    return 0;
}
