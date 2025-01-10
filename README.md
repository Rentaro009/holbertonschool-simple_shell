Simple Shell
A simple shell is a basic command-line interpreter that allows users to execute commands interactively. This project serves as a learning tool to understand the inner workings of shells and core system programming concepts like process creation, system calls, and input/output handling.

Features:
Executes basic commands (e.g., ls, pwd, echo).
Handles multiple arguments (e.g., ls -l).
Built-in exit command to terminate the shell.
Infinite command loop until user exits.
Error handling for invalid commands.
How It Works

Input Handling:

Reads user input using fgets().

Command Parsing:

Splits the input string into the command and its arguments using strtok().

Process Creation:

Creates a child process with fork().

Command Execution:

Executes the command using execvp() in the child process.
Parent process waits for the child to complete using wait().

Getting Started:

Requirements:

GCC compiler
Unix-based operating system (e.g., Linux, macOS)

Compilation

Compile the shell using the following command:

gcc -Wall -Werror -Wextra -pedantic simple_shell.c -o simple_shell
Usage

Run the shell:

./simple_shell

Example commands:

simple_shell$ ls -l  
simple_shell$ echo "Hello, world!"  
simple_shell$ pwd  
simple_shell$ exit  
Code Overview
Main Components
main() Function

Loops continuously, prompting the user for input and calling the command execution function.
execute_command() Function

Parses the input and uses fork() and execvp() to run the command.
Example Code Snippet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char *input) {
    char *args[64];
    args[0] = strtok(input, " \n");
    for (int i = 1; (args[i] = strtok(NULL, " \n")) != NULL; i++);

    if (args[0] == NULL) return;
    if (strcmp(args[0], "exit") == 0) exit(0);

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("fork failed");
    }
}

int main() {
    char input[1024];
    while (1) {
        printf("simple_shell$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        execute_command(input);
    }
    return 0;
}

Future Enhancements
Add Built-in Commands: Support commands like cd and help.
Implement Piping: Allow commands like ls | grep file.
Enable Redirection: Handle file input and output redirection (> and <).
Command History: Store and recall previously entered commands.
Contributing
Contributions are welcome! Feel free to fork the repository and submit a pull request with your improvements.

Authors Rene Alsina and William Alvarado
