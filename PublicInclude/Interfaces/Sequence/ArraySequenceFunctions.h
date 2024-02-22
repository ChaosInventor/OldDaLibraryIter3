#ifndef SEQUENCE__INTEFACES_SEQUENCE_ARRAY_SEQUENCE_FUNCTIONS_H
#define SEQUENCE__INTEFACES_SEQUENCE_ARRAY_SEQUENCE_FUNCTIONS_H 

#include "Interfaces/Sequence/SequenceDefinition.h"

struct Sequence CreateOnceArraySequenceFromArrayPointer(struct Array* p_array);
struct Sequence CreateInfiniteArraySequenceFromArrayPointer(
    struct Array p_array
);


struct Array ReadArrayUsingSequenceCallbackOnEnd_ArrayOnce(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);
struct Array ReadArrayUsingSequenceCallbackOnEnd_ArrayInfinite(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);

#endif //SEQUENCE__INTEFACES_SEQUENCE_ARRAY_SEQUENCE_FUNCTIONS_H