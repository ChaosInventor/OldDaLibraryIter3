#include "Fundamental/SizeDefinition.h"
#include "Memory/MemoryDefinition.h"
#include "MemoryManagerDefinition.h"
#include "MemeoryManagerDebug.h"
#include "MemoryManagerConstants.h"

//TODO: Implement
struct MemoryManager g_DefaultMemoryManager;

struct Callback g_DefaultAllocateError;
struct Callback g_DefaultReSizeError;
struct Callback g_DefaultRePermissionError;


struct Memory AllocateMemoryFromSizeUsingMemoryManager(
    const Size p_size, struct MemoryManager* restrict p_manager
)
{

    ValidateMemoryManagerPointer(p_manager);


    struct Memory l_return = {
        .Location = NULL, .Size = p_size, .Permissions =
            (struct MemoryPermissions) {
                .Readable = 1, .Writable = 1, .Executable = 0
            }
        };

    p_manager->AllocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictnessCallbackOnFailure(
        &l_return, p_manager, (struct MemoryManagerStrictness) {
            .LocationGreater = 1, .LocationLesser = 1
        },
        &g_DefaultAllocateError
    );

    return l_return;

}

struct Memory ReSizeMemoryFromMemoryFromSizeUsingMemoryManager(
    const struct Memory p_original, const Size p_newSize,
    struct MemoryManager* restrict p_manager
)
{

    ValidateMemoryManagerPointer(p_manager);


    struct Memory l_return = p_original;

    p_manager->ReSizeUsingMemoryAsSizeForwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure(
        &l_return, p_manager, p_newSize, (struct MemoryManagerStrictness) { 0 },
        &g_DefaultReSizeError
    );

    return l_return;

}

void DeallocateFromMemoryUsingMemoryManager(
    const struct Memory p_memory, struct MemoryManager* restrict p_manager
)
{
    ValidateMemoryManagerPointer(p_manager);
    p_manager->DeallocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictness(
        &p_memory, p_manager, (struct MemoryManagerStrictness) { 0 }
    );
}