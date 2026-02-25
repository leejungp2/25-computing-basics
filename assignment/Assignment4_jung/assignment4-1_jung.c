#include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h> // strcmp

int parse_csv(char *raw_data, char *rows[], int max_rows) {
    char *p = raw_data;
    int count = 0;

    if (*p != '\0' && count < max_rows) {
        *(rows + count) = p;
        count++;
    }

    while (*p != '\0' && count < max_rows) {
        if (*p == '\n') {
            *p = '\0';
            if (*(p + 1) != '\0' && count < max_rows) {
                *(rows + count) = p + 1;
                count++;
            }
        }
        p++;
    }

    return count;
}

int filter_by_age(char *all_rows[], int total_rows, char *result_rows[], int min_age) {
    int i;
    int count = 0;

    for (i = 0; i < total_rows; i++) {
        char *row = *(all_rows + i);
        char *p = row;

        while (*p != '\0' && *p != ',') {
            p++;
        }

        if (*p == ',') {
            p++;
            int age = atoi(p);
            if (age >= min_age && count < total_rows) {
                *(result_rows + count) = row;
                count++;
            }
        }
    }

    return count;
}

void sort_pointers_by_name(char *rows[], int count) {
    int i, j;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            char *a = *(rows + j);
            char *b = *(rows + j + 1);

            if (strcmp(a, b) > 0) {
                char *tmp = a;
                *(rows + j) = b;
                *(rows + j + 1) = tmp;
            }
        }
    }
}

int main() {
    //You can change the raw_data part for testing reasons.
    char raw_data[] = 
        "Dave,15\n"
        "Alice,30\n"
        "Charlie,25\n"
        "Bob,10\n"
        "Eve,35";

    char *parsed_rows[10];
    char *filtered_rows[10];

    printf("--- Step 1: Parsing ---\n");
    int parsed_cnt = parse_csv(raw_data, parsed_rows, 10);
    printf("Parsed Lines: %d\n", parsed_cnt);
    
    for(int i=0; i<parsed_cnt; i++) {
        printf("[%d] %s\n", i, *(parsed_rows + i));
    }

    printf("\n--- Step 2: Filtering (Age >= 20) ---\n");
    int filtered_cnt = filter_by_age(parsed_rows, parsed_cnt, filtered_rows, 20);
    printf("Filtered Lines: %d\n", filtered_cnt);

    printf("\n--- Step 3: Sorting (By Name) ---\n");
    sort_pointers_by_name(filtered_rows, filtered_cnt);
    
    for(int i=0; i<filtered_cnt; i++) {
        printf("[%d] %s\n", i, *(filtered_rows + i));
    }

    return 0;
}