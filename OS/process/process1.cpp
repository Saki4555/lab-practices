#include <stdio.h>
#include <unistd.h>

void child_process() {
    for (int i = 0; i < 100; i++) {
        printf("I am a child process\n");
    }
}

void parent_process() {
    for (int i = 0; i < 100; i++) {
        printf("I am a parent process\n");
    }
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
       
        child_process();
    } else if (pid > 0) {
       
        parent_process();
    } else {
       
        perror("fork");
        return 1;
    }

    return 0;
}