#ifndef ARRAY_INDEXABLE__GLUE_ARRAY_INDEXABLE_ARRAY_INDEXABLE_DEBUG_H
#define ARRAY_INDEXABLE__GLUE_ARRAY_INDEXABLE_ARRAY_INDEXABLE_DEBUG_H 

#include "Interfaces/IntegerManager/IntegerManagerDebug.h"
#include "Interfaces/Indexable/IndexableDebug.h"
#include "Interfaces/Callback/CallbackDebug.h"
#include "Array/ArrayGenericDebug.h"
#include "Debug/Debug.h"

#define ValidateIndexableAsArrayIndexable(p_indexable)\
    {                                                                                                                   \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).State != NULL,                                                                                \
            "ArrayIndexable cannot have a null state"                                                                   \
        );                                                                                                              \
        ValidateArrayPointer((struct Array*)(p_indexable).State);                                                       \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError  \
            ==                                                                                                          \
            ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError_ArrayIndexable,\
            "Indexable " IndexableFormat " does not appear to be an ArrayIndexable",                                    \
            IndexableArgs((p_indexable))                                                                                \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable                                       \
            ==                                                                                                          \
            GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable_ArrayIndexable,                                     \
            "Indexable " IndexableFormat " does not appear to be an ArrayIndexable",                                    \
            IndexableArgs((p_indexable))                                                                                \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd                                         \
            ==                                                                                                          \
            ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable,                                             \
            "Indexable " IndexableFormat " does not appear to be an ArrayIndexable",                                    \
            IndexableArgs((p_indexable))                                                                                \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd                                     \
            ==                                                                                                          \
            ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable,                                             \
            "Indexable " IndexableFormat " does not appear to be an ArrayIndexable",                                    \
            IndexableArgs((p_indexable))                                                                                \
        );                                                                                                              \
        DaLibrary_Assert(                                                                                               \
            (p_indexable).ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd                                      \
            ==                                                                                                          \
            ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable,                                             \
            "Indexable " IndexableFormat " does not appear to be an ArrayIndexable",                                    \
            IndexableArgs((p_indexable))                                                                                \
        );                                                                                                              \
    }
#define ValidateIndexableAsArrayIndexablePointer(p_indexable)\
    {                                                       \
        ValidPointer((p_indexable));                        \
        ValidateIndexableAsArrayIndexable(*(p_indexable));  \
    }


#endif //ARRAY_INDEXABLE__GLUE_ARRAY_INDEXABLE_ARRAY_INDEXABLE_DEBUG_H