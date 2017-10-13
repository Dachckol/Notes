/* 
 * File:   NotesDisplay.h
 * Author: misiek
 *
 * Created on 30 October 2014, 10:20
 */

#ifndef NOTESDISPLAY_H
#define	NOTESDISPLAY_H

#include "FileManager.h"

class NotesDisplay {
public:
    NotesDisplay();
    ~NotesDisplay();
    void init(std::string file);
    std::string display();
    int update(std::string command);
private:
    FileManager fm;
    std::vector<Note> notes;
    std::string file;
};

#endif	/* NOTESDISPLAY_H */

