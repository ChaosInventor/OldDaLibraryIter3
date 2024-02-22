#include "Interfaces/Indexable/IndexableDefinition.h"
#include "Interfaces/Indexable/IndexableConstants.h"
#include "Interfaces/Indexable/IndexableDebug.h"

#include "Interfaces/IntegerManager/IntegerManagerDefinition.h"
#include "Interfaces/IntegerManager/IntegerManagerDebug.h"

#include "Interfaces/Callback/CallbackDefinition.h"
#include "Interfaces/Callback/CallbackDebug.h"
#include "Interfaces/Callback/CallbackFunctions.h"

#include "Interfaces/GenericManager/GenericManagerDefinition.h"
#include "Interfaces/GenericManager/GenericManagerDebug.h"


#include "Debug/Debug.h"

#define ValidateIndexableAs__VARIANT__(p_indexable)\
    {                                                                                                                                       \
        /* TODO: This is a generic verion of the validation macro, make one specific to __VARIANT__ */                                      \
        DaLibrary_Assert(                                                                                                                   \
            (p_indexable).State != NULL, "__VARIANT__ cannot have a null state"                                                             \
        );                                                                                                                                  \
        DaLibrary_Check(                                                                                                                    \
            (p_indexable).ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError   \
            ==                                                                                                                              \
            ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError___VARIANT__,    \
            "Indexable " IndexableFormat " does not appear to be a __VARIANT__",                                                            \
            IndexableArgs((p_indexable))                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Check(                                                                                                                    \
            (p_indexable).GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable                                                           \
            ==                                                                                                                              \
            GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable___VARIANT__,                                                            \
            "Indexable " IndexableFormat " does not appear to be a __VARIANT__",                                                            \
            IndexableArgs((p_indexable))                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Check(                                                                                                                    \
            (p_indexable).ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd                                                             \
            ==                                                                                                                              \
            ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd___VARIANT__,                                                              \
            "Indexable " IndexableFormat " does not appear to be a __VARIANT__",                                                            \
            IndexableArgs((p_indexable))                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Check(                                                                                                                    \
            (p_indexable).ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd                                                         \
            ==                                                                                                                              \
            ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd___VARIANT__,                                                          \
            "Indexable " IndexableFormat " does not appear to be a __VARIANT__",                                                            \
            IndexableArgs((p_indexable))                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Check(                                                                                                                    \
            (p_indexable).ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd                                                          \
            ==                                                                                                                              \
            ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd___VARIANT__,                                                           \
            "Indexable " IndexableFormat " does not appear to be a __VARIANT__",                                                            \
            IndexableArgs((p_indexable))                                                                                                    \
        );                                                                                                                                  \
    }
#define ValidateIndexableAs__VARIANT__Pointer(p_indexable)\
    {                                                   \
        ValidPointer((p_indexable));                    \
        ValidateIndexableAs__VARIANT__(*(p_indexable)); \
    }


void
ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError___VARIANT__(
    struct IndexableBatch* p_batch, Integer* p_index,
    struct IntegerManager* p_integerManager,
    struct GenericManager* p_genericManager, struct Indexable* p_indexable,
    struct Callback* p_indexError
)
{

    ValidPointer(p_batch);
    ValidateIntegerManagerPointer(p_integerManager);
    ValidateGenericManagerPointer(p_genericManager)
    ValidateIndexableAs__VARIANT__Pointer(p_indexable);
    ValidateCallbackPointer(p_indexError);


    *p_batch = NULL_INDEXABLE_BATCH;

    //TODO: Implement __VARIANT__ read batch index function

}
void ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd___VARIANT__(
    struct IndexableBatch* p_batch, struct Indexable* p_indexable,
    struct Callback* p_end
)
{

    ValidPointer(p_batch);
    ValidateIndexableAs__VARIANT__Pointer(p_indexable);
    ValidateCallbackPointer(p_end);


    *p_batch = NULL_INDEXABLE_BATCH;
    Callback(p_end);

    //TODO: Implement __VARIANT__ read next batch function

}
void ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd___VARIANT__(
    struct IndexableBatch* p_batch, struct Indexable* p_indexable,
    struct Callback* p_end
)
{

    ValidPointer(p_batch);
    ValidateIndexableAs__VARIANT__Pointer(p_indexable);
    ValidateCallbackPointer(p_end);


    *p_batch = NULL_INDEXABLE_BATCH;
    Callback(p_end);

    //TODO: Implement __VARIANT__ read previous batch function

}
void ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd___VARIANT__(
    struct IndexableBatch* p_batch, struct Indexable* p_indexable,
    struct Callback* p_end
)
{

    ValidPointer(p_batch);
    ValidateIndexableAs__VARIANT__Pointer(p_indexable);
    ValidateCallbackPointer(p_end);


    *p_batch = NULL_INDEXABLE_BATCH;
    Callback(p_end);

    //TODO: Implement __VARIANT__ read currect batch function

}

void GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable___VARIANT__(
    Integer** p_size, struct IntegerManager* p_manager,
    struct Indexable* p_indexable
)
{

    ValidPointer(p_size);
    ValidateIntegerManagerPointer(p_manager);
    ValidateIndexableAs__VARIANT__Pointer(p_indexable);


    //TODO: Implement __VARIANT__ get size function

}