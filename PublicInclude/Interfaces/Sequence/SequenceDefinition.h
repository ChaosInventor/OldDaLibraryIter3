#ifndef SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_DEFINITION_H
#define SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_DEFINITION_H 

#include "Array/ArrayGenericDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"

struct Sequence;

typedef struct Array (*SequenceReadFunction) (
    struct Sequence* restrict p_sequence, struct Callback* restrict p_end
);

struct Sequence
{

    void* State;

    SequenceReadFunction ReadArrayAsNextUsingSequenceCallbackOnEnd;
    SequenceReadFunction ReadArrayAsCurrentUsingSequenceCallbackOnEnd;

    SequenceReadFunction ReadArrayAsPreviousUsingSequenceCallbackOnEnd;
    SequenceReadFunction ReadArrayAsFirstUsingSequenceCallbackOnEnd;
    SequenceReadFunction ReadArrayAsLastUsingSequenceCallbackOnEnd;

};

#endif //SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_DEFINITION_H