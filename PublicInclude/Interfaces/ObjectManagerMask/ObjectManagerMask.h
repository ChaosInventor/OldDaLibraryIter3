#ifndef OBJECT_MANAGER_MASK__INTERFACES_OBJECT_MANAGER_MASK_OBJECT_MANAGER_MASK_H
#define OBJECT_MANAGER_MASK__INTERFACES_OBJECT_MANAGER_MASK_OBJECT_MANAGER_MASK_H

#include "Fundamental/Fundamental.h"
#include "Interfaces/Callback/Callback.h"
#include "Interfaces/ObjectManager/ObjectManager.h"
#include "Interfaces/Indexable/Indexable.h"

#define ValidateObjectManagerMask(p_mask)\
    DaLibrary_Assert(                                                                                                                 \
        (p_mask).GetToObjectManagerRangeFromSizeAsIndexUsingObjectManagerMaskUsingIndexableOfObjectsCallbackOnIndexError  \
        != NULL, "ObjectManagerMask may not have any of its functions be null"                                              \
    );                                                                                                                      \
    DaLibrary_Assert(                                                                                                                 \
        (p_mask).GetToObjectManagerRangeAsNextUsingObjectManagerMaskUsingIndexableOfObjectsCallbackOnEnd                  \
        != NULL, "ObjectManagerMask may not have any of its functions be null"                                              \
    );                                                                                                                      \
    DaLibrary_Assert(                                                                                                                 \
        (p_mask).GetToObjectManagerRangeAsPreviousUsingObjectManagerMaskUsingIndexableOfObjectsCallbackOnEnd              \
        != NULL, "ObjectManagerMask may not have any of its functions be null"                                              \
    );

#define ValidateObjects(p_objects)\
    ValidateIndexableOfObjects((p_objects).Indexable);\
    ValidateObjectManagerMask((p_objects).Mask);      \


struct ObjectManagerMask;

struct ObjectManagerRange;

typedef void (*ObjectManagerMaskGetIndexFunction) (
    struct ObjectManagerRange* p_range, Size p_index,
    struct ObjectManagerMask* p_mask, struct IndexableOfObjects* p_indexable,
    struct Callback* p_indexError
);

typedef void (*ObjectManagerMaskGetFunction) (
    struct ObjectManagerRange* p_range, struct ObjectManagerMask* p_mask,
    struct IndexableOfObjects* p_indexable, struct Callback* p_indexError
);



void CreateToObjectManagerMaskUsingObjectManagerFromSize(
    struct ObjectManagerMask* p_objManagerMask,
    struct ObjectManager* p_objManager, Size p_size
);


struct ObjectManagerMask
{
    void* State;

    ObjectManagerMaskGetIndexFunction
        GetToObjectManagerRangeFromSizeAsIndexUsingObjectManagerMaskUsingIndexableOfObjectsCallbackOnIndexError;

    ObjectManagerMaskGetFunction
        GetToObjectManagerRangeAsNextUsingObjectManagerMaskUsingIndexableOfObjectsCallbackOnEnd;
    ObjectManagerMaskGetFunction
        GetToObjectManagerRangeAsPreviousUsingObjectManagerMaskUsingIndexableOfObjectsCallbackOnEnd;

};

struct ObjectManagerRange
{
    struct ObjectManager* objManager;
    Size ValidAfter;
    Size ValidBefore;
};

//TODO: Should this be in a separate module or here? Another file?
struct Objects
{
    struct IndexableOfObjects Indexable;
    struct ObjectManagerMask Mask;
};

#endif //OBJECT_MANAGER_MASK__INTERFACES_OBJECT_MANAGER_MASK_OBJECT_MANAGER_MASK_H