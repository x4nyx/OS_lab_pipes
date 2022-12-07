#include <iostream>
#include <unistd.h>

std::string procM = "../../M/cmake-build-debug/M";
std::string procA = "../../A/cmake-build-debug/A";
std::string procP = "../../P/cmake-build-debug/P";
std::string procS = "../../S/cmake-build-debug/S";


int RunProcess(const std::string& proc) {
    int pipes [3];
    pipe(pipes);
    if (!fork()) {
        if (dup2(pipes[1], 1) == -1) {
            return -1;
        }
        system(proc.c_str());
        return 0;
    } else if (dup2(pipes[0], 0) == -1) {
        close(pipes[1]);
        return -1;
    }
    return 0;
}

int main() {
    if (RunProcess(procA) == 0) {
        if (RunProcess(procM) == 0) {
            if (RunProcess(procP) == 0) {
                system(procS.c_str());
            }
        }
    }

    return 0;
}