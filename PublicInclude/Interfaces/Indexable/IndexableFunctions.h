#ifndef INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_FUNCTIONS_H
#define INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_FUNCTIONS_H

#include "Fundamental/BooleanDefinition.h"
#include "IndexableDefinition.h"

void CreateToIndexableBatchAsNull(struct IndexableBatch* p_batch);

struct IndexableBatch ReadBatchAsFirstUsingIndexable(
    struct Indexable* restrict p_indexable
);
struct IndexableBatch ReadBatchAsLastUsingIndexable(
    struct Indexable* restrict p_indexable
);

Boolean IndexableBatchIsNull(struct IndexableBatch p_batch);

#endif //INDEXABLE__INTERFACES_INDEXABLE_INDEXABLE_FUNCTIONS_H