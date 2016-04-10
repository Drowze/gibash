#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

int break_input (char *input, char *argv[]) {
    if(!input)
        return -1;
    char *token;
    int argc = 0; //counter of arguments
    int i;

    argv[argc++] = strtok(input, " "); // copying the address of the first word
    
    while((token = strtok(NULL, " ")) != NULL)
        argv[argc++] = token;

    return argc;
}

char **string_split_sized_matrix (char *str) {
    int i, space_counter = 0;
    for (i = 0; str[i]; i++)
        if (str[i] == ' ')
            space_counter++;

    char **matrix = malloc (space_counter+1 * sizeof (char *));
    if(!matrix)
        return NULL;

    return matrix;
}

int exec_prog(char *argv[]) {
    pid_t child_pid;
    int child_status;

    child_pid = fork();
    return 0;
}

int main (int argc, char *argv[]) {
    int i;
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    printf("# ");
    read = getline(&input, &len, stdin);

    char **internal_argv = string_split_sized_matrix(input);
    int internal_argc = break_input(input, internal_argv);

    for(int i = 0; internal_argv[i]; i++)
      printf("%d: %s\n", i, internal_argv[i]);

    return 0;
}
