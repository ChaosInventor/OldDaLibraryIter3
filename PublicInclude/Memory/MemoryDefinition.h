#ifndef MEMORY_MEMORY_MEMORY_DEFINITION_H
#define MEMORY_MEMORY_MEMORY_DEFINITION_H

#include "Fundamental/SizeDefinition.h"
#include "Fundamental/ByteDefinition.h"

struct MemoryPermissions
{
    Boolean Readable: 1;
    Boolean Writable: 1;
    Boolean Executable: 1;
};
struct Memory
{
    Byte* Location;
    Size Size;
    struct MemoryPermissions Permissions;
};

#endif //MEMORY_MEMORY_MEMORY_DEFINITION_H