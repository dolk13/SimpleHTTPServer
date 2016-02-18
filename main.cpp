#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello, World!" << endl;
    std::string ip;
    std::string path;
    int port = 0;
    int option = 0;
    while ((option = getopt(argc, argv, "hpd")) != -1)
    {
        switch (option) {
            case 'h' : {
                std::cout << optarg << endl;
                break;
            }
            case 'p' : {
//                std::cout << optarg << endl;
                port = atoi(optarg);
                break;
            }
            case 'd' : {
                std::cout << optarg << endl;
                break;
            }
            default:
                exit(EXIT_FAILURE);
        }
    }
    cout << "port: " <<  port << endl;
    return 0;
}