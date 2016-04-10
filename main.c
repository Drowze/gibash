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

int executar(char *argv[]) {
    pid_t child_pid;
    int child_status;

    child_pid = fork();

    if(child_pid == 0) {
        /* This is done by the child process. */
        execvp(argv[0], argv);
        /* If execv returns, it must have failed. */
        printf("Unknown command\n");
        exit(0);
    }
    else {
       /* This is run by the parent. Wait for the child to terminate. */
        pid_t tpid = wait(&child_status);

       return child_status;
    }
}

int main (int argc, char *argv[]) {
    int i;
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

   while(1) {
        printf("# ");
        if((read = getline(&input, &len, stdin)) == -1)
            break;
        strtok(input, "\n"); // remove \n

        /* create a array of char pointers, with size equal to spaces in string + 1 */
        char **internal_argv = string_split_sized_matrix(input);
        /* allocate the address of each first letter to the spaces in the created array*/
        int internal_argc = break_input(input, internal_argv);

        /* execute internal_argv[0] with internal_argv as arguments */
        executar(internal_argv);
    }

    return 0;
}
