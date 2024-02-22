#ifndef MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_DEFINITION_H
#define MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_DEFINITION_H

#include "Fundamental/SizeDefinition.h"
#include "Fundamental/BooleanDefinition.h"
#include "Memory/MemoryDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"

struct MemoryManager;
struct MemoryManagerStrictness
{
    Boolean LocationGreater: 1;
    Boolean LocationLesser: 1;
    Boolean SizeGreater: 1;
    Boolean SizeLesser: 1;
    Boolean PermissionsGreater: 1;
    Boolean PermissionsLesser: 1;
};

typedef void (*MemoryManagerAllocateFunction) (
    struct Memory* restrict p_toAllocate,
    struct MemoryManager* restrict p_manager,
    const struct MemoryManagerStrictness p_strictness,
    struct Callback* restrict p_allocateError
);

typedef void (*MemoryManagerReSizeFunction) (
    struct Memory* restrict p_toReSize,
    struct MemoryManager* restrict p_manager, const Size p_newSize,
    const struct MemoryManagerStrictness p_strictness,
    struct Callback* restrict p_reSizeError
);
typedef void (*MemoryManagerRePermissionFunction) (
    struct Memory* restrict p_toRePermission,
    struct MemoryManager* restrict p_manager,
    const struct MemoryPermissions p_newPermissions,
    const struct MemoryManagerStrictness p_strictness,
    struct Callback* restrict p_rePermissionError
);

typedef void (*MemoryManagerDeallocateFunction) (
    struct Memory* restrict p_toDeallocate,
    struct MemoryManager* restrict p_manager,
    const struct MemoryManagerStrictness p_strictness
);


struct MemoryManager
{

    void* State;

    MemoryManagerAllocateFunction
        AllocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictnessCallbackOnFailure;

    MemoryManagerReSizeFunction
        ReSizeUsingMemoryAsSizeForwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure;
    MemoryManagerReSizeFunction
        ReSizeUsingMemoryAsLocationBackwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure;
    MemoryManagerRePermissionFunction
        RePermissionUsingMemoryUsingMemoryManagerFromMemoryPermissionsFromMemoryManagerStrictnessCallbackOnFailure;

    MemoryManagerDeallocateFunction
        DeallocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictness;

};

#endif //MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_DEFINITION_H