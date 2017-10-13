/* 
 * File:   FileManager.h
 * Author: misiek
 *
 * Created on 30 October 2014, 15:46
 */

#ifndef FILEMANAGER_H
#define	FILEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "structs.h"

class FileManager {
public:
    FileManager();
    std::vector<Note> read(std::string file);
    void save(std::vector<Note> notes, std::string file);
    ~FileManager();
private:

};

#endif	/* FILEMANAGER_H */

