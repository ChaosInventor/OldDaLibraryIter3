#ifndef MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_FUNCTIONS_H
#define MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_FUNCTIONS_H

#include "Fundamental/SizeDefinition.h"
#include "Memory/MemoryDefinition.h"
#include "MemoryManagerDefinition.h"

//These 3 are meant as malloc, realloc, and free equivalents

struct Memory AllocateMemoryFromSizeUsingMemoryManager(
    const Size p_size, struct MemoryManager* restrict p_manager
);

struct Memory ReSizeMemoryFromMemoryFromSizeUsingMemoryManager(
    const struct Memory p_original, const Size p_newSize,
    struct MemoryManager* restrict p_manager
);

void DeallocateFromMemoryUsingMemoryManager(
    const struct Memory p_memory, struct MemoryManager* restrict p_manager
);

#endif //MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_FUNCTIONS_H