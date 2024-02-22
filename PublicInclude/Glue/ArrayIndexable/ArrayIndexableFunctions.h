#ifndef ARRAY_INDEXABLE__GLUE_ARRAY_INDEXABLE_ARRAY_INDEXABLE_FUNCTIONS_H
#define ARRAY_INDEXABLE__GLUE_ARRAY_INDEXABLE_ARRAY_INDEXABLE_FUNCTIONS_H 

#include "Interfaces/Indexable/IndexableDefinition.h"
#include "Interfaces/IntegerManager/IntegerManagerDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"
#include "Array/ArrayGenericDefinition.h"

void InitializeToIndexableAsArrayIndexableUsingArray(
    struct Indexable* p_indexable, struct Array* p_array
);


void ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError_ArrayIndexable(
    struct IndexableBatch* p_batch, Integer* p_index,
    struct IntegerManager* p_integerManager,
    struct GenericManager* p_genericManager, struct Indexable* p_indexable,
    struct Callback* p_indexError
);
void ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable(
    struct IndexableBatch* p_batch, struct Indexable* p_indexable,
    struct Callback* p_end
);

void GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable_ArrayIndexable(
    Integer** p_size, struct IntegerManager* p_manager,
    struct Indexable* p_indexable
);


struct Array* FinalizeUsingIndexableArray(struct Indexable* p_indexable);

#endif //ARRAY_INDEXABLE__GLUE_ARRAY_INDEXABLE_ARRAY_INDEXABLE_FUNCTIONS_H