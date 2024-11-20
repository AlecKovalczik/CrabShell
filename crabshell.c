#include "crabshell.h"

#define EXIT_SUCCESS 0;

// pid_t fork(){
//     // fork a child process off of the main thread. 
// }

void commandLoop(){
    char *line;
    char **args;
    int status;

    do {
        // indicate input
        printf("> ");

        // retrieve and process input
        // line = readLine();
        // args = splitLine(line);
        // status = execute(args);

        // cleanup pointers
        free(line);
        free(args);
    } while (status);
}

int main() {
    // Initialize

    // Interpret
    // commandLoop();
    printf("This is where the loop will begin execution when the code to get that started is completed");

    // Terminate
    int exitCode = EXIT_SUCCESS; // 0 for success, other numbers are reserved for specific errors.

    return exitCode; 
}