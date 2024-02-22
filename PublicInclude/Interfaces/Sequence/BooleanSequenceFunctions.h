#ifndef BOOLEAN_SEQUENCE__INTERFACES_SEQUENCE_BOOLEAN_SEQUENCE_H
#define BOOLEAN_SEQUENCE__INTERFACES_SEQUENCE_BOOLEAN_SEQUENCE_H 

#include "SequenceDefinition.h"
#include "Fundamental/BooleanDefinition.h"
#include "Array/ArrayGenericDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"

struct Sequence CreateSequenceAsBooleanFalseSequenceFromArrayPointerAsBooleans(
    struct Array* p_booleans
);
struct Sequence CreateSequenceAsBooleanTrueSequenceFromArrayPointerAsBooleans(
    struct Array* p_booleans
);


struct Array ReadArrayUsingSequenceCallbackOnEnd_BooleanFalse(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);
struct Array ReadArrayUsingSequenceCallbackOnEnd_BooleanTrue(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);

#endif //BOOLEAN_SEQUENCE__INTERFACES_SEQUENCE_BOOLEAN_SEQUENCE_H