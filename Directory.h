#ifndef DIRECTORY_H
#define DIRECTORY_H
using namespace std;

#include "NodeRecord.h"
#include <string>

class Directory : public NodeRecord<string>
{
private:
    string name;

public:
    Directory(const string &name) : name(name) {};
    ~Directory() {};

    string getKey() const override { return name; };
    string getType() const override { return "Directory"; };
    // god i love one line implementations
};

#endif // DIRECTORY_H
