#ifndef FILESYSTEM_H
#define FILESYSTEM_H
using namespace std;

#include "TreeList.h"
#include "File.h"
#include "Directory.h"
#include <iostream>

class FileSystem
{
private:
    TreeList<string> treeList;

public:
    FileSystem() : treeList() {};
    ~FileSystem() {};

    // Add a root node (either a file or a directory)
    void addTree(NodeRecord<string> *rootRecord);
    void addRecord(const string &parentKey, NodeRecord<string> *record);
    void deleteRecord(const string &key);
    void deleteTree(const string &rootKey);
    void printFileSystem() const;

    void printFileContent(const string &fileName) const;
    void appendToFile(const string &fileName, const string &content);
    void deleteSubstringFromFile(const string &fileName, const string &substring);
};

#endif // FILESYSTEM_H
