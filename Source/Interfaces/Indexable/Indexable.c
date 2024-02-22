#include "Interfaces/Indexable/Indexable.h"
#include "Interfaces/IntegerManager/IntegerManagerConstants.h"
#include "Interfaces/IntegerManager/IntegerManagerFunctions.h"
#include "Interfaces/Callback/CallbackConstants.h"
#include "Interfaces/Callback/CallbackDebug.h"
#include "Fundamental/SizeConstants.h"
#include "Fundamental/BooleanConstants.h"

void CreateToIndexableBatchAsNull(struct IndexableBatch* p_batch)
{
    p_batch->Location = NULL;
    p_batch->AfterSize = 0;
    p_batch->BeforeSize = 0;
}

struct IndexableBatch ReadBatchAsFirstUsingIndexable(
    struct Indexable* restrict p_indexable
)
{

    ValidateIndexablePointer(p_indexable);

    struct IndexableBatch l_returnValue;
    p_indexable->ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError(
        &l_returnValue, (Integer*)&SIZE_MINIMUM, &g_SizeIntegerManager,
        p_indexable, &g_NullCallback
    );

    return l_returnValue;

}
struct IndexableBatch ReadBatchAsLastUsingIndexable(
    struct Indexable* restrict p_indexable
)
{

    ValidateIndexablePointer(p_indexable);


    Integer* l_indexableSize;
    struct IntegerManager l_manager;
    p_indexable->GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable(
        &l_indexableSize, &l_manager, p_indexable
    );

    //The only case where this overflows is where p_indexable has a size of 0.
    //If that is the case, then, by definition, any batch that is read from that
    //indexable will be a null batch. Then by using a negative index, an index
    //error will occur where a null batch will be read.
    FindUsingIntegerToIntegerPointerAsPredecessorUsingIntegerManagerCallbackOnOverflow(
        l_indexableSize, &l_indexableSize, &l_manager, &g_NullCallback
    );

    //See above comment for why index error can be ignored.
    struct IndexableBatch l_returnValue;
    p_indexable->ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingGenericManagerUsingIndexableCallbackOnIndexError(
        &l_returnValue, l_indexableSize, &l_manager, p_indexable, &g_NullCallback
    );

    return l_returnValue;

}

Boolean IndexableBatchIsNull(struct IndexableBatch p_batch)
{
    return
        p_batch.Location == NULL
        &&
        (p_batch.AfterSize == 0 && p_batch.BeforeSize == 0);
}


void ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingIndexableCallbackOnIndexError_ZeroIndexable(
    struct Batch* p_batch, Integer* p_index, struct IntegerManager p_manager,
    struct Indexable* p_indexable, struct Callback* p_indexError
)
{

    (void)p_index;
    (void)p_manager;

    ValidateCallbackPointer(p_indexError);
    DaLibrary_Check(
        p_indexable == &g_ZeroIndexable,
        "Zero indexable function got indexable at address %p, while the zero "
        "indexable global is at %p", p_indexable, &g_ZeroIndexable
    );


    CreateToIndexableBatchAsNull(p_batch);
    Callback(p_indexError);

}

void GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable_ZeroIndexable(
    Integer** p_size, struct IntegerManager* p_manager,
    struct Indexable* p_indexable
)
{

    ValidPointer(p_size);
    ValidPointer(p_manager);
    DaLibrary_Check(
        p_indexable == &g_ZeroIndexable,
        "Zero indexable function got indexable at address %p, while the zero "
        "indexable global is at %p", p_indexable, &g_ZeroIndexable
    );


    //TODO: Should the size given by the indexable be modifyable? How to express constant integers?
    *p_size = (Integer*)&SIZE_MINIMUM;
    *p_manager = g_SizeIntegerManager; 

}

void ReadToIndexableBatchUsingIndexableCallbackOnEnd_ZeroIndexable (
    struct Batch* p_batch, struct Indexable* p_indexable,
    struct Callback* p_end
)
{

    ValidateCallbackPointer(p_end);
    DaLibrary_Check(
        p_indexable == &g_ZeroIndexable,
        "Zero indexable function got indexable at address %p, while the zero "
        "indexable global is at %p", p_indexable, &g_ZeroIndexable
    );


    CreateToIndexableBatchAsNull(p_batch);
    Callback(p_end);

}

struct Indexable g_ZeroIndexable = {
    NULL,
    ReadToIndexableBatchUsingIntegerAsIndexUsingIntegerManagerUsingIndexableCallbackOnIndexError_ZeroIndexable,
    GetToIntegerPointerAsSizeToIntegerManagerUsingIndexable_ZeroIndexable,
    ReadToIndexableBatchUsingIndexableCallbackOnEnd_ZeroIndexable,
    ReadToIndexableBatchUsingIndexableCallbackOnEnd_ZeroIndexable,
    ReadToIndexableBatchUsingIndexableCallbackOnEnd_ZeroIndexable
};

const struct IndexableBatch NULL_INDEXABLE_BATCH = { 0 };
