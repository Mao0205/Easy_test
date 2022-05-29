/*
GG Test1,
cost = 100，matrx中記錄路過的消耗值，
找從第一行到第四行的path中，找最大cost。

sample input:
4 4  //m*n
33 21 24 11
58 22 1 1
3 0 2 4
14 51 66 11
--------------
sample output:
62
*/

/*
以下提供的方法是錯的，只是記錄一下自己的做法。
應該要bottom up做DP。
*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'maxEnergy' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY mat as parameter.
 */

int maxEnergy(int mat_rows, int mat_columns, int** mat) {
    int i, j, count, min, k, r, ans, temp, temp_index;
    for(i=0;i<mat_rows;i++)
    {
        for(j=0;j<mat_columns;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    count = 100;
    ans = -10000;
    for(i=0;i<mat_columns;i++)
    {
        
            printf("For mat[0][%d]\n", i);
            count = 100 - mat[0][i];
            temp_index = i;
            for(k=1;k<mat_rows;k++)
            {   
                min = 102;
                temp = temp_index;
                for(r=-1;r<2;r++)
                {
                    if(temp+r<0 || temp+r>mat_columns)
                        continue;
                    if(min > mat[k][temp+r])
                    {
                        min = mat[k][temp+r];
                        temp_index = temp+r;
                    }
                    //min = (min > mat[k][temp+r])?mat[k][temp_index+r]:min;
                }
                printf("Min in mat[%d][%d], min = %d\n", k,temp_index+r, min);
                count -= min;
            }
            printf("count = %d\n\n", count);
            ans = (ans < count)?count:ans;
        
    }
    return ans;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int mat_rows = parse_int(ltrim(rtrim(readline())));

    int mat_columns = parse_int(ltrim(rtrim(readline())));

    int** mat = malloc(mat_rows * sizeof(int*));

    for (int i = 0; i < mat_rows; i++) {
        *(mat + i) = malloc(mat_columns * (sizeof(int)));

        char** mat_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < mat_columns; j++) {
            int mat_item = parse_int(*(mat_item_temp + j));

            *(*(mat + i) + j) = mat_item;
        }
    }

    int result = maxEnergy(mat_rows, mat_columns, mat);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}


