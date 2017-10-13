/* 
 * File:   FileManager.cpp
 * Author: misiek
 * 
 * Created on 30 October 2014, 15:46
 */

#include "FileManager.h"

enum DataType {
    ID =0, TEXT
};

FileManager::FileManager() {

}

std::vector<Note> FileManager::read(std::string file) {
    std::vector<Note> returns;
    std::ifstream f(file.c_str());
    std::string text;
    while (!f.eof()) std::getline(f, text);
    std::vector<std::string> notes;
    while (text.find("$") != std::string::npos) {
        notes.push_back(text.substr(0, text.find("$")));
        text.erase(0, text.find("$") + 1);
    }
    for (int i = 0; i < notes.size(); i++) {
        std::vector<std::string> cur;
        while (notes[i].find("@" )!= std::string::npos) {
            cur.push_back(notes[i].substr(0, notes[i].find("@")));
            notes[i].erase(0, notes[i].find("@") + 1);
        }
        Note n;
        n.id = cur[ID];
        n.text = cur[TEXT];
        returns.push_back(n);
    }
    return returns;
}

void FileManager::save(std::vector<Note> notes, std::string file) {
    std::string text;
    for (int i = 0; i < notes.size(); i++) {
        text += notes[i].id;
        text += "@";
        text += notes[i].text;
        text += "@";
        text += "$";
    }
    std::ofstream f(file.c_str());
    f << text;
}

FileManager::~FileManager() {
}

