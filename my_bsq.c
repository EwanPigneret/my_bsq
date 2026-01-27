#include "my_bsq.h"
/**
* @brief return the size of a string.
* @param char* string: array of character.
* @return return the size.
*/
int my_strlen(char* string) {
    int index = 0;

    while (string[index] != '\0') {
        index += 1;
    }
    return index;
}

/**
* @brief fill a buffer for a certain size with a given caracter.
* @param char* buff : buffer that is filled.
*        int caracter : caracter to fill the buffer with.
*        int size : number of caracter to fill the buffer with.
* @return return the buffer that has been filled.
*/
void* my_memset(char* buff, int caracter, int size) {
    int index = 0;

    while (index < size) {
        buff[index] = caracter;
        index += 1;
    }
    return buff;
}

/**
* @brief malloc the buffer, memset it and verify the result of the malloc.
* @param size_t size: size for the malloc.
* @return return the buffer that has been malloc.
*/
void* secure_malloc_char(size_t size) {
    char* buff = malloc(size);
    if (buff == NULL) {
        return NULL;
    }
    my_memset(buff, 0, size);
    return buff;
}

/**
* @brief malloc the buffer and verify the result of the malloc.
* @param size_t size: size for the malloc.
* @return return the buffer that has been malloc.
*/
void* secure_malloc_struct(size_t size) {
    void* buff = malloc(size);
    if (buff == NULL) {
        return NULL;
    }
    return buff;
}

/**
* @brief open the file and verify the result.
* @param char* pathname: name of the path of the file.
*        int flags: flags or option for the open.
* @return return an int corresponding to the error.
*/
int secure_open(char* path, int flags) {
    int fd = open(path, flags);
    if (fd == -1) {
        return -1;
    }
    return fd;
}

/**
* @brief read something and verify the result.
* @param int fd: file descriptor.
*        const void* buff: array of character that stocks the array.
*        size_t size: size of the array of character.
* @return return an int corresponding to the error.
*/
int secure_read(int fd, void* buff, int size) {
    int result = read(fd, buff, size);
    if (result == -1) {
        return -1;
    }
    return result;
}

/**
* @brief free a structure and its components.
* @param t_array_list* list : structure to free. 
*/
void free_array(t_array_int* list) {
    free(list->array);
    free(list);
}

/**
* @brief free a structure and its components.
* @param t_array* structure : structure to free.
*/
void free_struct(t_array* structure) {
    free(structure->array);
    free(structure);
}

/**
* @brief initialise and malloc a structure.
* @param int x : dimension of the array.
* @return return the array initialised.
*/
t_array_int* init_array(int x) {
    t_array_int* buff = (t_array_int*) secure_malloc_struct(sizeof(t_array_int));
    if (buff == NULL) return NULL; 

    buff->x = x;
    buff->size = x * x;
    buff->array = secure_malloc_struct(sizeof(int) * buff->size);
    if (!buff->array) return NULL;

    return buff;
}

/**
* @brief return the smallest number between 3.
* @param int number1 : first number.
*        int number2 : second number.
*        int number3 : third number.
* @return return the smallest number.
*/
int get_min(int number1, int number2, int number3) {
    int result = number1;

    if (result > number2) {
        result = number2;
    }

    if (result > number3) {
        result = number3;
    }
    return result;
}

/**
* @brief copy a string into another one. Both of the strings need to be allocated.
* @param char* string : string to copy.
*        char* dest : emplacement where the string is copied.
* @return return the destination once the string has been copied.
*/
char* my_strcpy(char* string, char* dest) {
    int index_dest = 0;
    int index_string = 0;

    while (dest[index_dest] != '\0') {
        index_dest += 1;
    }

    while (string[index_string] != '\0') {
        dest[index_dest] = string[index_string];
        index_string += 1;
        index_dest += 1;
    }
    return dest;
}

/**
* @brief convert a string containing a number into an int.
* @param char* string : string to convert. 
* @return return the value of the number.
*/
int my_atoi(char* string) {
    int index = 0;
    int result = 0;

    if (string[index] == '-') {
        return -1;
    }

    while (string[index] != '\0' && string[index] != ' ') {
        if (string[index] >= '0' && string[index] <= '9') {
            result = result * 10 + (string[index] - '0');
        }
        index++;
    }

    return result;
}

/**
* @brief print an array of int with corresponding caracters.
* @param t_array_int* list : array to print.
*/
void print_array_char(t_array_int* list) {
    int index = 0;
    while (index < list->size) {
        if (index % list->x == 0 && index != 0) {
            printf("\n");
        }
        if (list->array[index] == 0) {
            printf("o");
        }
        else if (list->array[index] == -1) {
            printf("x");
        }
        else {
            printf(".");
        }
        index += 1;
    }
    printf("\n");
}

/**
* @brief convert a string as an array of int.
* @param char* array : string to convert
*        t_array_int* list : result of the array that has been converted. THe array needs to be allocated before.
* @return return the converted array.
*/
t_array_int* convert_array(char* array, t_array_int* list) {
    int index_array = 0;
    int index_list = 0;
    
    while (array[index_array] != '\0') {
        if (array[index_array] == 'o') {
            list->array[index_list] = 0;
            index_array += 1;
            index_list += 1;
        }
        else if (array[index_array] == '.') {
            list->array[index_list] = 1;
            index_array += 1;
            index_list += 1;
        }
        else {
            index_array += 1;
        }
    }
    return list;
}

/**
* @brief transform a map into a usuable one. The biggest number is the end of the biggest square.
* @param t_array_int* list : initial array to transform.
*        t_array_int* result : the result of the transformated array.
*        int index : index of the array to transform.
* @return return the transformated array.
*/
t_array_int* transform_array(t_array_int* list, t_array_int* result, int index)
{
    int left = -1;
    int up = -1;
    int diagonal_left_up = -1;
    if (index < list->x || (index % list->x == 0)) {
        result->array[index] = list->array[index];
        return result;
    }
    else {
        if (list->array[index] != 0) {
            if (result->array[index - 1] != -1) left = result->array[index - 1];
            else left = transform_array(list, result, index - 1)->array[index - 1];
            if (result->array[index - list->x] != -1) up = result->array[index - list->x];
            else up = transform_array(list, result, index - list->x)->array[index - list->x];
            if (result->array[index - list->x - 1] != -1) diagonal_left_up = result->array[index - list->x - 1];
            else diagonal_left_up = transform_array(list, result, index - list->x - 1)->array[index - list->x - 1];
            result->array[index] = get_min(left, up, diagonal_left_up) + 1;
        }
        else {
            result->array[index] = list->array[index];
            transform_array(list, result, index - 1);
            transform_array(list, result, index - list->x);
            transform_array(list, result, index - list->x - 1);
        }
    }
    return result;
}

/**
* @brief find the emplacement of the biggest square and replace it with -1 to print it.
* @param t_int_array* list : array to modify.
* @return return the modified array.
*/
t_array_int* array_solution(t_array_int* list) {
    int temp = 0;
    int index = 0;
    int index_temp = 0;
    int temp_square = 0;
    int size_square = 0;

    while (index < list->size) {
        if (temp < list->array[index]) {
            temp = list->array[index];
            index_temp = index;
        }
        index += 1;
    }
    
    temp = 0;
    index = index_temp;
    size_square = list->array[index];
    while (temp_square < size_square) {
        while (temp < size_square) {
            list->array[index] = -1;
            temp += 1;
            index -= 1;
        }
        index -= list->x;
        index += size_square;
        temp_square += 1;
        temp = 0;
    }
    return list;
}

/**
* @brief read the content of a file, copy its content into an array and get its dimension.
* @param int fd : file descriptor of the file to read from.
* @return return a structure containing an array and the dimension of the array.
*/
t_array* read_file(int fd) {
    int index = 0;
    char* buff = secure_malloc_char(sizeof(char) * 11);
    char* temp = secure_malloc_char(sizeof(char) * 11);
    if (buff == NULL) return NULL;
    if (temp == NULL) return NULL;
    char* tmp = buff;

    secure_read(fd, buff, 10);
    while (*buff != '\n' && *buff != '\0') {
        temp[index] = *buff;
        index += 1;
        buff += 1;
    }

    int x = my_atoi(temp);

    t_array* result = (t_array*) secure_malloc_struct(sizeof(t_array));
    result->array = secure_malloc_char(sizeof(char) * (x * (x + 1)) + 2);
    result->x = x;
    if (result == NULL) return NULL;
    if (result->array == NULL) return NULL;

    char* temp_str = secure_malloc_char(sizeof(char) * (x * (x + 1)) + 2);
    if (temp_str == NULL) return NULL;

    secure_read(fd, temp_str, (x * (x + 1) - (10 - index - 1)));

    my_strcpy(buff, result->array);
    my_strcpy(temp_str, result->array);
    free(temp);
    free(temp_str);
    free(tmp);
    return result;
}

int main(int argc, char** argv) {
    if (argc != 2) return 0;

    int fd = secure_open(argv[1], O_RDONLY);
    if (fd == -1) return -1;

    t_array* structure = read_file(fd);
    if (structure == NULL) return -1;

    t_array_int* list = init_array(structure->x);
    if (list == NULL) return -1;

    t_array_int* result = init_array(structure->x);
    if (result == NULL) return -1;

    for (int index = 0; index < result->size; index += 1) {
        result->array[index] = -1;
    }

    list = convert_array(structure->array, list);
    result = transform_array(list, result, list->size - 1);
    result = array_solution(result);
    print_array_char(result);

    free_struct(structure);
    free_array(result);
    free_array(list);
    close(fd);
    return 0;
}