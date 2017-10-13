/* 
 * File:   main.cpp
 * Author: misiek
 *
 * Created on 30 October 2014, 10:08
 */
#include "NotesDisplay.h"
bool run;

int main(int argc, char** argv) {
    run = true;
    NotesDisplay nd;
    nd.init("notes.txt");
    while (run) {
        std::cout << nd.display();
        std::string command;
        std::getline(std::cin, command);
        run = nd.update(command);
    }
    return 0;
}

