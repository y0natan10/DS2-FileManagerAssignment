#ifndef FILE_H
#define FILE_H
using namespace std;

#include "NodeRecord.h"
#include <string>

class File : public NodeRecord<string>
{
private:
    string name;
    string content;

public:
    File(const string &name) : name(name), content("") {};
    ~File() {};
    // i know that the ';' after the 'implementation isn't necessary,
    // but it looks nicer and i don't think it changes anything

    string getKey() const override { return this->name; };
    string getType() const override { return "File"; };
    string getContent() const { return this->content; };

    bool canHaveChildren() const override { return false; };
    void appendContent(const string &newContent) { this->content += newContent; };
    bool deleteSubstring(const string &toDelete);
};
// most of these functions were one liners so i implemented them here isntead of cluttering the .cpp file
// i find it easier to organize and manage this way
#endif // FILE_H
