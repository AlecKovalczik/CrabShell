#include "crabshell.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Fork a child process off of a parent process.
int launch(char **args)
{
    // fork a child process off of the parent process.
    pid_t pid, wpid;
    int status;

    // STARTUPINFO si;
    // PROCESS_INFORMATION pi;

    // ZeroMemory( &si, sizeof(si) );
    // si.cb = sizeof(si);
    // ZeroMemory( &pi, sizeof(pi) );

    // pid = fork(); // fork doesn't work on Windows
    // https://learn.microsoft.com/en-us/windows/win32/procthread/creating-processes
    // pid = CreateProcess(NULL, args[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}

#define READ_LINE_BUFSIZE 1024

char *readLine()
{
    int bufsize = READ_LINE_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer)
    {
        fprintf(stderr, "crabshell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Read a character
        c = getchar();

        // If we hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;

        // If we have exceeded the buffer, reallocate.
        if (position >= bufsize)
        {
            bufsize += READ_LINE_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "crabshell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define SPLIT_LINE_BUFSIZE 64
#define SPLIT_LINE_DELIM " \t\r\n\a"

char **splitLine(char *line)
{
    int bufsize = SPLIT_LINE_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "crabshell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, SPLIT_LINE_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += SPLIT_LINE_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "crabshell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, SPLIT_LINE_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

void commandLoop()
{
    char *line;
    char **args;
    int status;

    do
    {
        // indicate input
        printf("> ");

        // retrieve and process input
        line = readLine();
        // if (strcmp(line, "q") && strcmp(line, "quit"))
        // {
        //     status = 1;
        // }
        // else
        // {
        //     status = 0;
        // }
        args = splitLine(line);
        int index = 0;
        while (args[index] != NULL)
        {
            printf("%s\n", args[index++]);
        }
        // status = execute(args);

        // cleanup pointers
        free(line);
        free(args);
    } while (status);
}

int main()
{
    // Initialize

    // Interpret
    commandLoop();

    // Terminate
    int exitCode = EXIT_SUCCESS; // 0 for success, other numbers are reserved for specific errors.

    return exitCode;
}