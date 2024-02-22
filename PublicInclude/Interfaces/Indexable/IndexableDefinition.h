#ifndef INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_DEFINITION_H
#define INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_DEFINITION_H

#include "Fundamental/SizeDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"
#include "Interfaces/IntegerManager/IntegerManagerDefinition.h"
#include "Interfaces/GenericManager/GenericManagerDefinition.h"

struct IndexableBatch;
struct Indexable;

typedef void (*IndexableReadBatchIndexFunction) (
    struct IndexableBatch* p_batch, Integer* p_index, 
    struct IntegerManager* p_integerManager,
    struct GenericManager* p_genericManager, struct Indexable* p_indexable,
    struct Callback* p_indexError
);
typedef void (*IndexableGetSizeFunction) (
    Integer** p_size, struct IntegerManager* p_manager,
    struct Indexable* p_indexable
);
typedef void (*IndexableReadBatchFunction) (
    struct IndexableBatch* p_batch, struct Indexable* p_indexable,
    struct Callback* p_end
);

struct IndexableBatch
{

    Generic* Location;
    Size AfterSize;
    Size BeforeSize;

};
struct Indexable
{

    void* State;

    IndexableReadBatchIndexFunction
        ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError;

    IndexableGetSizeFunction
        GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable;

    IndexableReadBatchFunction
        ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd;
    IndexableReadBatchFunction
        ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd;
    IndexableReadBatchFunction
        ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd;

};

#endif //INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_DEFINITION_H