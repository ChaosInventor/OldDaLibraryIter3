#ifndef SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_DEBUG_H
#define SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_DEBUG_H

#include "Debug/Debug.h"
#include "Interfaces/Sequence/SequenceDefinition.h"

#ifndef SequenceFormat
#define SequenceFormat \
    "%p = "                                                                 \
    "{ "                                                                    \
    "State = %p, "                                                          \
    "ReadArrayAsNextUsingSequenceCallbackOnEnd = %%FUNCTION_POINTER, "      \
    "ReadArrayAsCurrentUsingSequenceCallbackOnEnd = %%FUNCTION_POINTER, "   \
    "ReadArrayAsPreviousUsingSequenceCallbackOnEnd = %%FUNCTION_POINTER, "  \
    "ReadArrayAsFirstUsingSequenceCallbackOnEnd = %%FUNCTION_POINTER, "     \
    "ReadArrayAsLastUsingSequenceCallbackOnEnd = %%FUNCTION_POINTER"        \
    " }"
#endif //SequenceFormat

#ifndef SequenceArgs
#define SequenceArgs(p_sequence) \
    &(p_sequence),                                              \
    (p_sequence).State,                                         \
    (p_sequence).ReadArrayAsNextUsingSequenceCallbackOnEnd,     \
    (p_sequence).ReadArrayAsCurrentUsingSequenceCallbackOnEnd,  \
    (p_sequence).ReadArrayAsPreviousUsingSequenceCallbackOnEnd, \
    (p_sequence).ReadArrayAsFirstUsingSequenceCallbackOnEnd,    \
    (p_sequence).ReadArrayAsLastUsingSequenceCallbackOnEnd       
#endif //SequenceArgs

#define ValidSequence(p_sequence)\
    ValidPointer(&p_sequence)                                                   \
    &&                                                                          \
    ValidFunctionPointer((p_sequence).ReadArrayAsNextUsingSequenceCallbackOnEnd)\
    &&                                                                          \
    ValidFunctionPointer((p_sequence).ReadArrayAsCurrentUsingSequenceCallbackOnEnd)

#define ReversableSequence(p_sequence)\
    ValidSequence(p_sequence)                                                       \
    &&                                                                              \
    ValidFunctionPointer((p_sequence).ReadArrayAsPreviousUsingSequenceCallbackOnEnd)\

#define FullFeaturedSequence(p_sequence)\
    ReversableSequence(p_sequence)                                                  \
    &&                                                                              \
    ValidFunctionPointer((p_sequence).ReadArrayAsFirstUsingSequenceCallbackOnEnd)   \
    &&                                                                              \
    ValidFunctionPointer((p_sequence).ReadArrayAsLastUsingSequenceCallbackOnEnd)

#endif //SEQUENCE__INTEFACES_SEQUENCE_SEQUENCE_DEBUG_H