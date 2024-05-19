#include "../lib/library.h"
#include "../misc/compar.h"
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>

#define STR_LEN 30
#define BUFF_READ 256

typedef struct data {
    int id;
    char *string;
    int integer;
    double floating;
} Data;

void copyData(Data *data, int pos, int id, char *str, int integer, double flt){
    data[pos].id = id;
    data[pos].string = malloc((STR_LEN) * sizeof(char));
    strncpy(data[pos].string, str, STR_LEN);
    data[pos].integer = integer;
    data[pos].floating = flt; 
    //printf("data copied: %d, %s, %d, %f\n", data[pos].id, data[pos].string, data[pos].integer, data[pos].floating);       
}

int compar_int_data(const void *a, const void *b){
    Data *c = malloc(sizeof(Data) + STR_LEN);
    Data *d = malloc(sizeof(Data) + STR_LEN);
    memcpy(c, a, sizeof(Data) + STR_LEN);
    memcpy(d, b, sizeof(Data) + STR_LEN);

    if(c[0].integer == d[0].integer){
        free(c);
        free(d);
        return 0;
    } else if(c[0].integer > d[0].integer) {
        free(c);
        free(d);
        return 1;
    }else{ 
        free(c);
        free(d);
        return -1;
    }
}

int compar_double_data(const void *a, const void *b){
    Data *c = malloc(sizeof(Data) + STR_LEN);
    Data *d = malloc(sizeof(Data) + STR_LEN);
    memcpy(c, a, sizeof(Data) + STR_LEN);
    memcpy(d, b, sizeof(Data) + STR_LEN);

    if(c[0].floating == d[0].floating){
        free(c);
        free(d);
        return 0;
    } else if(c[0].floating > d[0].floating) {
        free(c);
        free(d);
        return 1;
    }else{ 
        free(c);
        free(d);
        return -1;
    }
}

int compar_string_data(const void *a, const void *b) {
    Data *c = malloc(sizeof(Data) + STR_LEN);
    Data *d = malloc(sizeof(Data) + STR_LEN);
    memcpy(c, a, sizeof(Data) + STR_LEN);
    memcpy(d, b, sizeof(Data) + STR_LEN);

    int ris = strcmp(c[0].string, d[0].string);
    free(c);
    free(d);
    return ris;
}

int main(int argc, char *argv[]){
    if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL){
        printf("Incomplete input, try again: ./run file.csv path/to/output.csv k t\nwhere k is an integer in the range of the list you passed and t is an integer [1-3] that select the field for sorting.\n\n");
        return 0;
    }else if(atoi(argv[4]) <= 0 && atoi(argv[4]) >= 4){
        printf("The fourth argument cannot be out of range [1-3]");
        return 0;
    }

    struct rlimit rl;
    getrlimit(RLIMIT_STACK, &rl);
    rl.rlim_cur = 1024 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rl);

    Data *data = malloc(2 * sizeof(Data)); 
    int dataLen = 2;

    FILE *fileIn = fopen(argv[1], "r");
    if(fileIn == NULL){
        printf("File does not exist");
        return 0;
    }
    printf("File exists\n");

	char line[BUFF_READ];
    int pos = 0;

	while((fgets(line, sizeof(line), fileIn)) != NULL){
        if(pos == dataLen - 1){
            dataLen = dataLen * 2;
            void *tmp = realloc(data, sizeof(Data) * dataLen + 1);
            if(tmp == NULL){
                printf("Realloc fails\n");
            }else{
                data = tmp;
            }
        }

        int id = atoi(strtok(line, ","));
        char *str = strdup(strtok(NULL, ","));
        int integer = atoi(strtok(NULL, ","));
        double flt = atof(strtok(NULL, ","));

        copyData(data, pos, id, str, integer, flt);
        free(str);
        pos++;
    }

    printf("File loaded\n");

	fclose(fileIn);

    int size = sizeof(Data);

    /* Variables for counting sorting duration */
    clock_t start, end;
    double duration;

    start = clock();

    int (*func)(const void *a, const void *b);

    switch (atoi(argv[4])){
    case 1:
        func = &compar_int_data;
        break;
    
    case 2:
        func = &compar_double_data;
        break;
    
    case 3:
        func = &compar_string_data;
        break;
    default:
        break;
    }

    /* Sorting */
    merge_binary_insertion_sort((void **)(&data[0]), 0, pos - 1, sizeof(Data), atoi(argv[3]), func);

    end = clock();
    duration = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Durata: %f\n", duration);

    /* Writing data on file */
    FILE *fileOut = fopen(argv[2], "a");
    int i = 0;
    while(i < pos){
        fprintf(fileOut, "%d,%s,%d,%f\n", data[i].id, data[i].string, data[i].integer, data[i].floating);
        i++;
    }

	fclose(fileOut);

    /* Free memory */
    for (int j = 0; j < pos; j++) {
        free(data[j].string);
    }
    free(data);
}