#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

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
    return 0;
}