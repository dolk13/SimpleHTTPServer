#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

#include <boost/asio.hpp>

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello, World!" << endl;
    std::string ip;
    std::string path;
    int port = 0;
    int option = 0;
    while ((option = getopt(argc, argv, "h:p:d:")) != -1)
    {
        switch (option) {
            case 'h' : {
                ip = optarg;
                break;
            }
            case 'p' : {
                port = atoi(optarg);
                break;
            }
            case 'd' : {
                path = optarg;
                break;
            }
            default:
                exit(EXIT_FAILURE);
        }
    }
    cout << "port: " <<  port << endl;
    cout << "ip: " << ip << endl;
    cout << "path: " << path << endl;

    pid_t pid = fork();
    if (pid < 0)
        return 1;
    if (pid > 0)
        return 0;
    pid_t sid = setsid();
    if (sid < 0)
        return 2;
    if (chdir("/") < 0)
        return 3;

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    pause();
    return 0;
}
