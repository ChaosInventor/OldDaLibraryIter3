#ifndef SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_FUNCTIONS_H
#define SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_FUNCTIONS_H 

#include "SequenceDefinition.h"
#include "Fundamental/BooleanDefinition.h"
#include "Array/ArrayGenericDefinition.h"
#include "Array/ArrayGenericFunctions.h"
#include "Interfaces/Callback/Callback.h"

//TODO: Should functions such as these be in this file?
#define ForeachInSequenceCurrentForwardCallback(p_sequence, p_arrayName, p_callback)\
    for(                                                                \
        struct Array (p_arrayName) =                                    \
            (p_sequence).ReadArrayAsCurrentUsingSequenceCallbackOnEnd(  \
                &(p_sequence), p_callback                               \
            );                                                          \
        !ArrayIsNull(p_arrayName);                                      \
        (p_arrayName) =                                                 \
            (p_sequence).ReadArrayAsNextUsingSequenceCallbackOnEnd(     \
                &(p_sequence), p_callback                               \
            )                                                           \
    )
#define ForeachInSequenceCurrentBackwardCallback(p_sequence, p_arrayName, p_callback)\
    for(                                                                \
        struct Array (p_arrayName) =                                    \
            (p_sequence).ReadArrayAsCurrentUsingSequenceCallbackOnEnd(  \
                &(p_sequence), p_callback                               \
            );                                                          \
        !ArrayIsNull(p_arrayName);                                      \
        (p_arrayName) =                                                 \
            (p_sequence).ReadArrayAsPreviousUsingSequenceCallbackOnEnd( \
                &(p_sequence), p_callback                               \
            )                                                           \
    )


struct Sequence CreateSequenceAsEmpty(void);


Boolean SequencePointerIsEmpty(struct Sequence* restrict p_sequence);

struct Array ReadArrayAsFirstUsingSequenceCallbackOnEnd(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);
struct Array ReadArrayAsLastUsingSequenceCallbackOnEnd(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);
struct Array ReadArrayUsingSequenceCallbackOnEnd_Empty(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);

#endif //SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_FUNCTIONS_H