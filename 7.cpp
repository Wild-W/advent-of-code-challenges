#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Dir {
    map<string, Dir*> folders;
    map<string, int> files;
    Dir* root;

    const int MAX_SPACE = 70000000;
    const int UPDATE_SPACE = 30000000;

    int getSize() {
        int result = 0;

        for (const auto& folder : this->folders) {
            result += folder.second->getSize();
        }
        
        for (const auto& file : this->files) {
            result += file.second;
        }

        return result;
    }

    int getSizeSumsUnderMax(int max) {
        int result = 0;
        int size = this->getSize();

        if (size <= max) {
            result += size;
        }

        for (const auto& folder : this->folders) {
            result += folder.second->getSizeSumsUnderMax(max);
        }

        return result;
    }

    int getSizeOfSmallestDirThatSatisfiesUpdate() {
        Dir* temp = this;

        while (temp->root != NULL) {
            temp = temp->root;
        }

        int totalSize = temp->getSize();
        int threshold = Dir::UPDATE_SPACE - (Dir::MAX_SPACE - totalSize);
        int smallestSize = totalSize;

        for (const auto& folder : this->folders) {
            int size = folder.second->getSize();

            if (size < smallestSize && size >= threshold) {
                smallestSize = size;
            }

            int subSmallestSize = folder.second->getSizeOfSmallestDirThatSatisfiesUpdate();

            if (subSmallestSize < smallestSize) {
                smallestSize = subSmallestSize;
            }
        }

        return smallestSize;
    }
};

int main() {
    ifstream input("./7in.txt");

    char _;
    string cmd;

    Dir* currentDir = new Dir;
    currentDir->root = NULL;

    //Discard first line
    input >> _ >> cmd >> _;

    // Follow instructions
    while (input >> _ >> cmd) {
        Command:
        // Change current directory
        if (cmd == "cd") {
            string location;
            input >> location;

            if (location == "..") {
                currentDir = currentDir->root;
            }
            else {
                currentDir = currentDir->folders[location];
            }
        }
        // List everything in directory (cmd == "ls")
        else {
            string sizeOrDir, name;
            while (input >> sizeOrDir >> name) {
                // Break out of loop and handle command
                // TODO: Un-goto this
                if (sizeOrDir == "$") {
                    cmd = name;
                    goto Command;
                }

                // Entry is a folder
                if (sizeOrDir == "dir") {
                    Dir* newDir = new Dir;
                    newDir->root = currentDir;

                    currentDir->folders[name] = newDir;
                }
                // Entry is a file
                else {
                    currentDir->files[name] = stoi(sizeOrDir);
                }
            }
        }
    }

    // Go to outermost root
    while (currentDir->root != NULL) {
        currentDir = currentDir->root;
    }

    // Answers
    cout << "Part 1: " << currentDir->getSizeSumsUnderMax(100000) << '\n'
         << "Part 2: " << currentDir->getSizeOfSmallestDirThatSatisfiesUpdate() << endl;
    
    return 0;
}