#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        exit(1);
    } else if (pid == 0) {
       
        system("ls");
        exit(0);
    } else {
       
        wait(NULL);
        std::cout << "Child process finished" << std::endl;
    }

    return 0;
}