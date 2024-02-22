#include "Interfaces/ObjectManager/ObjectManager.h"

void AllocateUsingIndexableOfObjectsAsOutputUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsAllocatedCallbackOnFailure_ELABORATION_GOES_HERE(
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

void CopyUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsCopiedCallbackOnFailure_ELABORATION_GOES_HERE(
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

void MoveUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationFromIndexRangeUsingObjectManager_ELABORATION_GOES_HERE(
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

void SwapUsingIndexableOfObjectsUsingIndexableOfObjectsFromIndexRangeUsingObjectManager_ELABORATION_GOES_HERE(
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

struct IndexableOfBytes GetIndexableOfBytesUsingObjectUsingObjectManager_ELABORATION_GOES_HERE(
    void** p_object, struct ObjectManager* p_objManager
)
{
    (void)p_object;
    (void)p_objManager;
    return (struct IndexableOfBytes){0};
}

int ObjectIsSameAsObjectInContexOfObjectManager_ELABORATION_GOES_HERE(
    void** p_object1, void** p_object2, struct ObjectManager* p_objManager
)
{
    (void)p_object1;
    (void)p_object2;
    (void)p_objManager;
}
int ObjectIsGreaterThanObjectInContexOfObjectManager_ELABORATION_GOES_HERE(
    void** p_object1, void** p_object2, struct ObjectManager* p_objManager
)
{
    (void)p_object1;
    (void)p_object2;
    (void)p_objManager;
}

void DeallateUsingIndexableOfObjectsAsInputUsingObjectManagerUsingMemoryManagerFromIndexRange_ELABORATION_GOES_HERE(
    struct IndexableOfObjects* p_input, struct ObjectManager* p_objManager,
    struct MemoryManager* p_memManager, const struct IndexRange* p_range
)
{
    (void)p_input;
    (void)p_objManager;
    (void)p_memManager;
    (void)p_range;
}

struct ObjectManager g_NAME_OF_NEW_OBJECT_MANAGER = {
    &AllocateUsingIndexableOfObjectsAsOutputUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsAllocatedCallbackOnFailure_ELABORATION_GOES_HERE,
    &CopyUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationUsingObjectManagerUsingMemoryManagerFromIndexRangeToSizeAsCopiedCallbackOnFailure_ELABORATION_GOES_HERE,        
    &MoveUsingIndexableOfObjectsAsSourceUsingIndexableOfObjectsAsDestinationFromIndexRangeUsingObjectManager_ELABORATION_GOES_HERE,
    &SwapUsingIndexableOfObjectsUsingIndexableOfObjectsFromIndexRangeUsingObjectManager_ELABORATION_GOES_HERE,
    &GetIndexableOfBytesUsingObjectUsingObjectManager_ELABORATION_GOES_HERE,
    &ObjectIsSameAsObjectInContexOfObjectManager_ELABORATION_GOES_HERE,
    &ObjectIsGreaterThanObjectInContexOfObjectManager_ELABORATION_GOES_HERE,
    &DeallateUsingIndexableOfObjectsAsInputUsingObjectManagerUsingMemoryManagerFromIndexRange_ELABORATION_GOES_HERE
};
