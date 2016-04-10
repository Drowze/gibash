/* Name: Rafael Gibim
   Student Number: 15203721
   e-mail: rafael.gibim@ucdconnect.ie */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <setjmp.h>
#include <time.h>
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

    argv[argc] = NULL;
    return argc;
}

char **string_split_sized_matrix (char *str) {
    int i, space_counter = 0;
    for (i = 0; str[i]; i++)
        if (str[i] == ' ')
            space_counter++;

    char **matrix = malloc (space_counter+2 * sizeof (char *));
    if(!matrix)
        return NULL;

    return matrix;
}

int executar_cd(char *internal_argv[]){
    if(!internal_argv[1])
        chdir(getenv("HOME"));
    else {
        if(chdir(internal_argv[1]) == -1){
            printf("No such file or directory\n");
            return -1;
        }
    }

    return 0;
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

const char *get_time() {
    time_t timer;
    char *buffer = malloc(14 * sizeof(char));
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 14, "[%d/%m %H:%M]", tm_info);

    return buffer;
}
