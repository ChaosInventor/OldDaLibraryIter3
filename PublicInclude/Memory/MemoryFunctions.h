#ifndef MEMORY_MEMORY_MEMORY_FUNCTIONS_H
#define MEMORY_MEMORY_MEMORY_FUNCTIONS_H

#include "Fundamental/BooleanDefinition.h"
#include "MemoryDefinition.h"

Boolean MemoryIsNull(const struct Memory p_memory);
Boolean MemoryIsReadable(const struct Memory p_memory);
Boolean MemoryIsWritable(const struct Memory p_memory);
Boolean MemoryIsExecutable(const struct Memory p_memory);

Boolean MemoryHasSameContentsAsMemory(
    const struct Memory p_memory1, const struct Memory p_memory2
);


#endif //MEMORY_MEMORY_MEMORY_FUNCTIONS_H