#ifndef MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_CONSTANTS_H
#define MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_CONSTANTS_H

#include "MemoryManagerDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"

extern struct MemoryManager g_DefaultMemoryManager;

//TODO: Maybe move these?
extern struct Callback g_DefaultAllocateError;
extern struct Callback g_DefaultReSizeError;
extern struct Callback g_DefaultRePermissionError;

#endif //MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_CONSTANTS_H