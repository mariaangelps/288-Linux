#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1000

// Function to count lines in a text file
int count_lines_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 0; 
    }

    int lines = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        lines++;
    }

    fclose(file);
    return lines;
}

// traverse directory  and count lines
void traverse_directory(const char *dir_path, int *total_lines) {
    struct dirent *entry;
    DIR *dir = opendir(dir_path);
    
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct stat path_stat;
    char full_path[MAX_PATH_LENGTH];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
		// Skip current and parent directory entries
		continue; 
        }

        // buffer size not execedeed
        if (strlen(dir_path) + strlen(entry->d_name) + 2 > sizeof(full_path)) {
            fprintf(stderr, "The name %s/%s is too long\n", dir_path, entry->d_name);
            continue;
        }

        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", dir_path, entry->d_name);

        if (stat(full_path, &path_stat) == 0) {
            if (S_ISDIR(path_stat.st_mode)) {
                traverse_directory(full_path, total_lines);
            } else if (S_ISREG(path_stat.st_mode)) {
                // if file has a .txt extension
                if (strstr(entry->d_name, ".txt") != NULL) {
                    *total_lines += count_lines_in_file(full_path);
                }
            }
        } else {
            perror("Error: Cannot read the file/directory");
        }
    }

    closedir(dir);
}

int main() {
    char dir_path[MAX_PATH_LENGTH];

    printf("Enter directory path: ");
    scanf("%999s", dir_path); 

    int total_lines = 0;
    traverse_directory(dir_path, &total_lines);

    printf("Total number of lines in .txt files: %d\n", total_lines);
    return 0;
}

