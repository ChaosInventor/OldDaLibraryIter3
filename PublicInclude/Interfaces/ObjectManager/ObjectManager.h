#ifndef OBJECT_MANAGER__INTERFACES_OBJECT_MANAGER_OBJECT_MANAGER_H
#define OBJECT_MANAGER__INTERFACES_OBJECT_MANAGER_OBJECT_MANAGER_H

#include "Fundamental/Fundamental.h"
#include "IndexRange/IndexRange.h"
#include "Interfaces/Indexable/Indexable.h"
#include "Interfaces/MemoryManager/MemoryManager.h"
#include "Interfaces/Callback/Callback.h"

struct ObjectManager;


typedef void (*ObjectManagerAllocateFunction) (
    struct IndexableOfObjects* p_output, struct ObjectManager* p_objManager,
    struct MemoryManager* p_memManager, const struct IndexRange* p_range,
    Size* p_allocated, struct Callback* p_failure
);

typedef void (*ObjectManagerCopyFunction) (
    struct IndexableOfObjects* p_source,
    struct IndexableOfObjects* p_destination,
    struct ObjectManager* p_objManager, struct MemoryManager* p_memManager,
    const struct IndexRange* p_range, Size* p_copied, struct Callback* p_failure
);

typedef void (*ObjectManagerMoveOrSwapFunction) (
    struct IndexableOfObjects* p_source,
    struct IndexableOfObjects* p_destination, const struct IndexRange* p_range,
    struct ObjectManager* p_objManager
);

typedef void (*ObjectManagerDeallocateFunction) (
    struct IndexableOfObjects* p_input, struct ObjectManager* p_objManager,
    struct MemoryManager* p_memManager, const struct IndexRange* p_range
);


//FIXME: Needs better naming scheme for these sorts of objects.
extern struct ObjectManager g_NullObjectManager;
extern struct ObjectManager g_NoOpObjectManager;

//TODO: These should go into a extension module.
extern struct ObjectManager g_CharObjectManager;
extern struct ObjectManager g_ShortObjectManager;
extern struct ObjectManager g_IntObjectManager;
extern struct ObjectManager g_LongObjectManager;
extern struct ObjectManager g_LongLongObjectManager;

extern struct ObjectManager g_UnsignedCharObjectManager;
extern struct ObjectManager g_UnsignedShortObjectManager;
extern struct ObjectManager g_UnsignedIntObjectManager;
extern struct ObjectManager g_UnsignedLongObjectManager;
extern struct ObjectManager g_UnsignedLongLongObjectManager;

extern struct ObjectManager g_FloatObjectManager;
extern struct ObjectManager g_DoubleObjectManager;
extern struct ObjectManager g_LongDoubleObjectManager;

extern struct ObjectManager g_PointerObjectManager;
extern struct ObjectManager g_CStringObjectManager;

extern struct ObjectManager g_ObjectManagerObjectManager;
//TODO: More managers for all the structures that is depended on.


struct ObjectManager
{

    void* State;

    ObjectManagerAllocateFunction
        AllocateUsingIndexableOfObjectsAsOutputUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsAllocatedCallbackOnFailure;

    ObjectManagerCopyFunction
        CopyUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsCopiedCallbackOnFailure;

    ObjectManagerMoveOrSwapFunction
        MoveUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationFromIndexRangeUsingObjectManager;

    ObjectManagerMoveOrSwapFunction
        SwapUsingIndexableOfObjectsUsingIndexableOfObjectsFromIndexRangeUsingObjectManager;

    ObjectManagerDeallocateFunction
        DeallateUsingIndexableOfObjectsAsInputUsingObjectManagerUsingMemoryManagerFromIndexRange;

};

#endif //OBJECT_MANAGER__INTERFACES_OBJECT_MANAGER_OBJECT_MANAGER_H