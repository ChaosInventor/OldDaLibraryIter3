#ifndef HASH_FUNCTION__INTERFACES_HASH_FUNCTION_HASH_FUNCTION_DEFINITION_H
#define HASH_FUNCTION__INTERFACES_HASH_FUNCTION_HASH_FUNCTION_DEFINITION_H

#include "Array/ArrayGenericDefinition.h"
#include "Interfaces/Sequence/SequenceDefinition.h"

struct HashFunction;

typedef void (*HashFunctionHash) (
    struct Array p_output, struct Sequence* restrict p_bytes,
    struct HashFunction* restrict p_function
);
typedef Size (*HashFunctionGetSize) (struct HashFunction* restrict p_function);

struct HashFunction
{

    void* State;

    HashFunctionHash ComputeFromArrayAsHashUsingSequenceAsBytesUsingHashFunction;

    HashFunctionGetSize GetSizeAsHashLengthUsingHashFunction;

};

#endif //HASH_FUNCTION__INTERFACES_HASH_FUNCTION_HASH_FUNCTION_DEFINITION_H