#ifndef MEMORY_MEMORY_MEMORY_DEBUG_H
#define MEMORY_MEMORY_MEMORY_DEBUG_H

#include "Debug/Debug.h"
#include "MemoryDefinition.h"

#ifndef MemoryFormat
#define MemoryFormat "%p { Location = %p, Size = %zd, Readable = %d, Writable = %d, Executable = %d }"
#endif //MemoryFormat

#ifndef MemoryArgs
#define MemoryArgs(p_memory)\
    &(p_memory), (p_memory).Location, (p_memory).Size,                \
    (p_memory).Permissions.Readable, (p_memory).Permissions.Writable,   \
    (p_memory).Permissions.Executable
#endif //MemoryArgs

#define ValidateMemory(p_memory)\
    {                                                                           \
        if((p_memory).Location == NULL || (p_memory).Size == 0)               \
        {                                                                       \
            DaLibrary_Assert(                                                   \
                (p_memory).Location == NULL || (p_memory).Size == 0,          \
                "A memory struct with a null location must have a null size. "  \
                "Memory struct " MemoryFormat " does to comply with this",      \
                MemoryArgs                                                      \
            );                                                                  \
        }                                                                       \
    }

#define ValidateMemoryPointer(p_memory)\
    {                               \
        Assume((p_memory) != NULL); \
        ValidateMemory(*p_memory);  \
    }

#endif //MEMORY_MEMORY_MEMORY_DEBUG_H