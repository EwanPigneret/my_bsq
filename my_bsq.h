/**
*   Include
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
*   Librairies
*/

typedef struct s_array {
    int x;
    char* array;
} t_array;

typedef struct s_array_int {
    int* array;
    int size;
    int x;
} t_array_int;