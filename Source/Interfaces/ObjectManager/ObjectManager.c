#include "Interfaces/ObjectManager/ObjectManager.h"

void AllocateUsingIndexableOfObjectsAsOutputUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsAllocatedCallbackOnFailure_NoOp(
    struct IndexableOfObjects* p_output, struct ObjectManager* p_objManager,
    struct MemoryManager* p_memManager, const struct IndexRange* p_range,
    Size* p_allocated, struct Callback* p_failure
)
{
    (void)p_output;
    (void)p_objManager;
    (void)p_memManager;
    (void)p_range;
    (void)p_allocated;
    (void)p_failure;
}

void CopyUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsCopiedCallbackOnFailure_NoOp(
    struct IndexableOfObjects* p_source,
    struct IndexableOfObjects* p_destination,
    struct ObjectManager* p_objManager, struct MemoryManager* p_memManager,
    const struct IndexRange* p_range, Size* p_copied, struct Callback* p_failure
)
{
    (void)p_source;
    (void)p_destination;
    (void)p_objManager;
    (void)p_memManager;
    (void)p_range;
    (void)p_copied;
    (void)p_failure;
}

void MoveUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationFromIndexRangeUsingObjectManager_NoOp(
    struct IndexableOfObjects* p_source,
    struct IndexableOfObjects* p_destination, const struct IndexRange* p_range,
    struct ObjectManager* p_objManager
)
{
    (void)p_source;
    (void)p_destination;
    (void)p_range;
    (void)p_objManager;
}

void SwapUsingIndexableOfObjectsUsingIndexableOfObjectsFromIndexRangeUsingObjectManager_NoOp(
    struct IndexableOfObjects* p_source,
    struct IndexableOfObjects* p_destination, const struct IndexRange* p_range,
    struct ObjectManager* p_objManager
)
{
    (void)p_source;
    (void)p_destination;
    (void)p_range;
    (void)p_objManager;
}

struct IndexableOfBytes GetIndexableOfBytesUsingObjectUsingObjectManager_NoOp(
    void** p_object, struct ObjectManager* p_objManager
)
{
    (void)p_object;
    (void)p_objManager;
    return (struct IndexableOfBytes){0};
}

int ObjectIsSameAsObjectInContexOfObjectManager_NoOp(
    void** p_object1, void** p_object2, struct ObjectManager* p_objManager
)
{
    (void)p_object1;
    (void)p_object2;
    (void)p_objManager;
}
int ObjectIsGreaterThanObjectInContexOfObjectManager_NoOp(
    void** p_object1, void** p_object2, struct ObjectManager* p_objManager
)
{
    (void)p_object1;
    (void)p_object2;
    (void)p_objManager;
}

void DeallateUsingIndexableOfObjectsAsInputUsingObjectManagerUsingMemoryManagerFromIndexRange_NoOp(
    struct IndexableOfObjects* p_input, struct ObjectManager* p_objManager,
    struct MemoryManager* p_memManager, const struct IndexRange* p_range
)
{
    (void)p_input;
    (void)p_objManager;
    (void)p_memManager;
    (void)p_range;
}

struct ObjectManager g_NullObjectManager = { 0 }; 
struct ObjectManager g_NoOpObjectManager = {
    &AllocateUsingIndexableOfObjectsAsOutputUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsAllocatedCallbackOnFailure_NoOp,
    &CopyUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsCopiedCallbackOnFailure_NoOp,        
    &MoveUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationFromIndexRangeUsingObjectManager_NoOp,
    &SwapUsingIndexableOfObjectsUsingIndexableOfObjectsFromIndexRangeUsingObjectManager_NoOp,
    &GetIndexableOfBytesUsingObjectUsingObjectManager_NoOp,
    &ObjectIsSameAsObjectInContexOfObjectManager_NoOp,
    &ObjectIsGreaterThanObjectInContexOfObjectManager_NoOp,
    &DeallateUsingIndexableOfObjectsAsInputUsingObjectManagerUsingMemoryManagerFromIndexRange_NoOp
};