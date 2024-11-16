#ifndef NODERECORD_H
#define NODERECORD_H

#include <string> // Include string

template <typename T>
class NodeRecord
{
public:
    virtual ~NodeRecord() = default;

    // Returns the key of the record (in this case, name)
    virtual T getKey() const = 0;

    // Returns the type of the record (either "File" or "Directory")
    virtual string getType() const = 0;

    // Determines whether the record can have children (e.g., directories can, files cannot)
    virtual bool canHaveChildren() const { return true; };
};

#endif // NODERECORD_H
