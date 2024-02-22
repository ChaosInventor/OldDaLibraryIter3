#include "Memory/Memory.h"
#include "Fundamental/BooleanConstants.h"

Boolean MemoryIsNull(const struct Memory p_memory)
{
    ValidateMemory(p_memory);
    return p_memory.Location == NULL && p_memory.Size == 0;
}
Boolean MemoryIsReadable(const struct Memory p_memory)
{
    ValidateMemory(p_memory);
    return p_memory.Permissions.Readable;
}
Boolean MemoryIsWritable(const struct Memory p_memory)
{
    ValidateMemory(p_memory);
    return p_memory.Permissions.Writable;
}
Boolean MemoryIsExecutable(const struct Memory p_memory)
{
    ValidateMemory(p_memory);
    return p_memory.Permissions.Executable;
}

Boolean MemoryHasSameContentsAsMemory(
    const struct Memory p_memory1, const struct Memory p_memory2
)
{

    ValidateMemory(p_memory1);
    ValidateMemory(p_memory2);
    DaLibrary_Assume(MemoryIsReadable(p_memory1));
    DaLibrary_Assume(MemoryIsReadable(p_memory2));


    if(p_memory1.Size != p_memory2.Size)
    {
        return FALSE;
    }

    if(MemoryIsNull(p_memory1) || MemoryIsNull(p_memory2))
    {
        return MemoryIsNull(p_memory1) && MemoryIsNull(p_memory2);
    }

    for(Size i = 0; i < p_memory1.Size; ++i)
    {
        if(p_memory1.Location[i] != p_memory2.Location[i])
        {
            return FALSE;
        }
    }

    return TRUE;

}