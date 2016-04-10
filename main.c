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

#include "functions.h"

static sigjmp_buf jbuf;

void handler(int sig)
{
    if(sig==SIGINT) {
        printf("\n");
        siglongjmp(jbuf,0);
    }
    return;
}

int main (int argc, char *argv[]) {

    void (*prev_handler)(int);


    int i, r;
    char *input = NULL;
    size_t len = 0;
    ssize_t read;
    sigsetjmp(jbuf, 1);
    signal(SIGINT,handler);

    while(1) {
        printf("%s # ", get_time());
        fflush(stdout);
        if((read = getline(&input, &len, stdin)) == -1)
            break;
        strtok(input, "\n"); // remove \n


        /* create a array of char pointers, with size equal to spaces in string + 1 */
        char **internal_argv = string_split_sized_matrix(input);
        /* allocate the address of each first letter to the spaces in the created array*/
        int internal_argc = break_input(input, internal_argv);

        /* execute internal_argv[0] with internal_argv as arguments */
        if(strcmp(internal_argv[0], "cd") == 0) {
            executar_cd(internal_argv);
        }
        else
            executar(internal_argv);
    }

    return 0;
}
