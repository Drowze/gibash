/* Name: Rafael Gibim
   Student Number: 15203721
   e-mail: rafael.gibim@ucdconnect.ie */

#ifndef LIB_FUNCTIONS_H_INCLUDED
#define LIB_FUNCTIONS_H_INCLUDED

void handler(int sig);
int break_input (char *input, char *argv[]);
char **string_split_sized_matrix (char *str);
int executar(char *argv[]);
const char *get_time();
int executar_cd(char *internal_argv[]);
#endif
