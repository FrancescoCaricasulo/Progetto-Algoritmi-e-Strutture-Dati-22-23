#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../skiplist/skip_list.h"
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 128

static int string_comparator(const void *p1, const void *p2){
    if(p1 == NULL){
        fprintf(stderr, "element_1 cannot be null");
        exit(EXIT_FAILURE);
    }
    if(p2 == NULL){
        fprintf(stderr, "element_2 cannot be null");
        exit(EXIT_FAILURE);
    }
    
    return strcmp((char *)p1, (char *)p2);
}

int main(int argc, char *argv[]) {
    if(atoi(argv[3]) == 0 || argv[3] == NULL){
        printf("The 3rd paramter cannot be 0 or null!\nTry again using: ./run path/to/dictionary path/to/file_to_correct t\nwhere t is an integer greater than 0\n");
        return 0;
    }
    Skiplist *list = initSkiplist(list, atoi(argv[3]), string_comparator);

    char buff[BUFFER_SIZE];
    FILE *file = fopen(argv[1], "r");

    if(file == NULL){
        printf("Cannot open dictionary!");
        return 0;
    }

    clock_t start, end;

    start = clock();
    while(fgets(buff, BUFFER_SIZE, file) != NULL){
        buff[strcspn(buff, "\r\n")] = '\0';
        char *word = malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(word, buff);
        addItem(list, (void *)word);
    }
    end = clock();

    printf("Lines added in: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(file);
    printf("All added!\n");

    printf("Errors detection\n");
    FILE *text = fopen(argv[2], "r");
    if(text == NULL){
        printf("Cannot open file to correct!");
        return 0;
    }

    memset(buff, 0, BUFFER_SIZE);

    start = clock();
    char c;
    while((c = fgetc(text)) != EOF){ 
        if(c == ' ' || c == '\n' || c == ',' || c == ';' || c == '.' || c == ':'){
            if(buff[0] != 0){
                char *word = malloc(sizeof(char) * strlen(buff) + 1);
                char *found = malloc(sizeof(char) * strlen(buff) + 1);
                strcpy(word, buff);
                found = (char *)searchSkipList(list, (void *)word);
                if(found == NULL){
                    printf("Error: %s\n", word);
                }
                memset(buff, 0, BUFFER_SIZE);
            }
        }else{
            c = tolower(c);
            strncat(buff, &c, 1);      
        }
    }
    end = clock();
    printf("Errors found out in: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(text);
    freeSkiplist(list);
}