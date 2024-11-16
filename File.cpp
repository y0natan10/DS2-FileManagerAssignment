#include "File.h"
// all these methods were implemented in one line in the .h file
// i find it much easier to read this way

// File::File(const string &name) : name(name), content("") {}
// File::~File() {}
// string File::getKey() const
// {
//     return name;
// }
// string File::getType() const
// {
//     return "File";
// }
// bool File::canHaveChildren() const
// {
//     return false;
// }
// void File::appendContent(const string &newContent)
// {
//     this->content += newContent;
// }
// string File::getContent() const
// {
//     return content;
// }

bool File::deleteSubstring(const string &toDelete)
{
    size_t startIndex = content.find(toDelete);
    // returns the starting posotion of the string if found
    // if not found returns something called npos (?)
    // why size_t? 'answered' later
    if (startIndex != string::npos)
    // i've read more documentation than i would like to about why i need 'string::'
    // still not entirely sure what it is
    {
        content.erase(startIndex, toDelete.length());
        // starting from startIndex places from the beggining of the string calling the method
        // delete 2nd parameters number of characters including the startIndex
        return true;
        // we found it and deleted it
    }
    // this is a way to do this i found during research

    // size_t is an unsigned int
    // every (except for one) example i read used size_t instead of using an int
    // why? not sure

    return false;
    // did not find -> nothing to delete
}
