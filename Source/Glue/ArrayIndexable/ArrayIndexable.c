#include "Glue/ArrayIndexable/ArrayIndexableFunctions.h"
#include "Glue/ArrayIndexable/ArrayIndexableDebug.h"


#include "Interfaces/IntegerManager/IntegerManagerDefinition.h"

#include "Interfaces/Indexable/IndexableDefinition.h"
#include "Interfaces/Indexable/IndexableConstants.h"

#include "Interfaces/Callback/CallbackFunctions.h"


#include "Array/ArrayGenericDefinition.h"
#include "Array/ArrayGenericDebug.h"

void InitializeToIndexableAsArrayIndexableUsingArray(
    struct Indexable* p_indexable, struct Array* p_array
)
{

    ValidPointer(p_indexable);
    ValidateArrayPointer(p_array);


    *p_indexable = (struct Indexable) {
        .State = p_array,
        .ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError =
            ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError_ArrayIndexable,
        .GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable =
            GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable_ArrayIndexable,
        .ReadToIndexableBatchAsNextUsingIndexableCallbackOnEnd = 
            ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable,
        .ReadToIndexableBatchAsPreviousUsingIndexableCallbackOnEnd = 
            ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable,
        .ReadToIndexableBatchAsCurrentUsingIndexableCallbackOnEnd = 
            ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable
    };

}


void ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError_ArrayIndexable(
    struct IndexableBatch* p_batch, Integer* p_index, 
    struct IntegerManager* p_integerManager,
    struct GenericManager* p_genericManager, struct Indexable* p_indexable,
    struct Callback* p_indexError
)
{

    ValidPointer(p_batch);
    ValidateIntegerManagerPointer(p_integerManager);
    ValidateIntegerManagerPointer(p_genericManager);
    ValidateIndexableAsArrayIndexablePointer(p_indexable);
    ValidateCallbackPointer(p_indexError);


    *p_batch = NULL_INDEXABLE_BATCH;

    //TODO: Implement ArrayIndexable Indexable

}
void ReadToIndexableBatchUsingIndexableCallbackOnEnd_ArrayIndexable(
    struct IndexableBatch* p_batch, struct Indexable* p_indexable,
    struct Callback* p_end
)
{

    ValidPointer(p_batch);
    ValidateIndexableAsArrayIndexablePointer(p_indexable);
    ValidateCallbackPointer(p_end);


    struct Array* l_self = (struct Array*)p_indexable->State;

    *p_batch = (struct IndexableBatch) {
        .Location = l_self->Location, .AfterSize = l_self->Size - 1,
        .BeforeSize = 0
    };
    
    Callback(p_end);

}

void GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable_ArrayIndexable(
    Integer** p_size, struct IntegerManager* p_manager,
    struct Indexable* p_indexable
)
{

    ValidPointer(p_size);
    ValidateIntegerManagerPointer(p_manager);
    ValidateIndexableAsArrayIndexablePointer(p_indexable);


    //TODO: Implement ArrayIndexable Indexable

}


struct Array* FinalizeUsingIndexableArray(struct Indexable* p_indexable)
{
    ValidateIndexableAsArrayIndexablePointer(p_indexable);
    return (struct Array*)p_indexable->State;
}