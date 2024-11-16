#include "FileSystem.h"
using namespace std;
// implemented in main

// FileSystem::FileSystem() : treeList() {}
// FileSystem::~FileSystem() {}

// Add a root node (either file or directory)
void FileSystem::addTree(NodeRecord<string> *rootRecord)
{
    treeList.addTree(rootRecord);
    // still unsure of when it is acceptable to do implementation in decleration
    // but this feels too long to be a one liner
}

void FileSystem::addRecord(const string &parentKey, NodeRecord<string> *record)
{
    // finally found out what cerr does, cool
    if (!treeList.addRecord(parentKey, record))
        cerr << "Parent directory " << parentKey << " not found or is not a directory." << endl;
}

void FileSystem::deleteRecord(const string &key)
{
    if (!treeList.removeRecord(key))
        cerr << "Record " << key << " not found" << endl;
}

void FileSystem::deleteTree(const string &rootKey)
{
    if (!treeList.removeRecord(rootKey))
        cerr << "Tree not found" << endl;
}

void FileSystem::printFileSystem() const
{
    treeList.printAllTrees();
}

void FileSystem::printFileContent(const string &fileName) const
{
    NodeRecord<string> *fileRecord = treeList.search(fileName);
    if (fileRecord && fileRecord->getType() == "File")
    {
        File *file = (File *)fileRecord;
        std::cout << file->getContent() << std::endl;
    }
    else
    {
        cerr << "File " << fileName << " not found or is not a file." << endl;
    }
}

void FileSystem::appendToFile(const string &fileName, const string &content)
{
    NodeRecord<string> *fileRecord = treeList.search(fileName);
    if (fileRecord && fileRecord->getType() == "File")
    {
        File *file = (File *)fileRecord;
        file->appendContent(content);
    }
    else
    {
        cerr << "File " << fileName << " not found or is not a file." << endl;
    }
}

void FileSystem::deleteSubstringFromFile(const string &fileName, const string &substring)
{
    NodeRecord<string> *fileRecord = treeList.search(fileName);
    if (fileRecord && fileRecord->getType() == "File")
    {
        File *file = dynamic_cast<File *>(fileRecord);
        file->deleteSubstring(substring);
    }
    else
    {
        cerr << "File " << fileName << " not found or is not a file." << endl;
    }
}
