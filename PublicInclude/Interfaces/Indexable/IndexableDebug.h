#ifndef INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_DEBUG_H
#define INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_DEBUG_H 

#include "Debug/Debug.h"
#include "IndexableDefinition.h"

#ifndef IndexableFormat
#define IndexableFormat\
    "%p = "                                                                                                                 \
    "{ State = %p, "                                                                                                        \
    "ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError = %%FUNCTION_POINTER, "   \
    "GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable = %%FUNCTION_POINTER, "                                            \
    "ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd = %%FUNCTION_POINTER, "                                          \
    "ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd = %%FUNCTION_POINTER, "                                      \
    "ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd = %%FUNCTION_POINTER }"
#endif //IndexableFormat

#ifndef IndexableArgs
#define IndexableArgs(p_indexable)\
    &(p_indexable),                                                                                             \
    (p_indexable).State,                                                                                        \
    (p_indexable).ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError, \
    (p_indexable).GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable,                                          \
    (p_indexable).ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd,                                        \
    (p_indexable).ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd,                                    \
    (p_indexable).ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd
#endif //IndexableArgs

#define ValidateIndexable(p_indexable)\
    {                                                                                                                   \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError  \
            !=                                                                                                          \
            NULL,                                                                                                       \
            "An indexable may not have any of its functions be null. Indexable "                                        \
            IndexableFormat " does not conform to this.",                                                               \
            IndexableArgs(p_indexable)                                                                                  \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable                                           \
            !=                                                                                                          \
            NULL,                                                                                                       \
            "An indexable may not have any of its functions be null. Indexable "                                        \
            IndexableFormat " does not conform to this.",                                                               \
            IndexableArgs(p_indexable)                                                                                  \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd                                         \
            !=                                                                                                          \
            NULL,                                                                                                       \
            "An indexable may not have any of its functions be null. Indexable "                                        \
            IndexableFormat " does not conform to this.",                                                               \
            IndexableArgs(p_indexable)                                                                                  \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd                                     \
            !=                                                                                                          \
            NULL,                                                                                                       \
            "An indexable may not have any of its functions be null. Indexable "                                        \
            IndexableFormat " does not conform to this.",                                                               \
            IndexableArgs(p_indexable)                                                                                  \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd                                      \
            !=                                                                                                          \
            NULL,                                                                                                       \
            "An indexable may not have any of its functions be null. Indexable "                                        \
            IndexableFormat " does not conform to this.",                                                               \
            IndexableArgs(p_indexable)                                                                                  \
        );                                                                                                              \
    }

#define ValidateIndexablePointer(p_indexable)\
    {                                           \
        DaLibrary_Assume(p_indexable != NULL);  \
        ValidateIndexable(*(p_indexable));      \
    }

#endif //INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_DEBUG_H