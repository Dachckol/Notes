/* 
 * File:   NotesDisplay.cpp
 * Author: misiek
 * 
 * Created on 30 October 2014, 10:20
 */
#include "NotesDisplay.h"

NotesDisplay::NotesDisplay() {
}

void NotesDisplay::init(std::string file) {
    this->file = file;
    notes = fm.read(file);
}

std::string NotesDisplay::display() {
    std::string output;
    output += "[-------------------------------|NOTES|-------------------------------]\n";
    if (notes.size() == 0) output += "\nno notes have been made yet\n";
    else for (int i = 0; i < notes.size(); i++) {
            output += "\n[" + notes[i].id + "]\n";
            output += notes[i].text + "\n";
        }
    output += "\ncommand : ";
    return output;
}

int NotesDisplay::update(std::string command) {
    command += ":";
    std::vector<std::string> bits;
    while (command.find(":") != std::string::npos) {
        bits.push_back(command.substr(0, command.find(":")));
        command.erase(0, command.find(":") + 1);
    }
    if (bits[0] == "add") {
        Note n;
        n.id = bits[1];
        n.text = bits[2];
        notes.push_back(n);
    } else if (bits[0] == "del") {
        for (int i = 0; i < notes.size(); i++) {

            if (notes[i].id == bits[1]) notes.erase(notes.begin() + i);
        }
    } else if (bits[0] == "exit") return 0;
    fm.save(notes, file);
    return 1;
}

NotesDisplay::~NotesDisplay() {
    for (int i = 0; i < notes.size(); i++) {
        notes[i].id = notes[i].text = "";
        notes.clear();
    }

}

