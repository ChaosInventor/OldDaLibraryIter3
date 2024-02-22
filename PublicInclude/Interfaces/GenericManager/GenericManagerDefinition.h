#ifndef GENERIC__INTERFACES_GENERIC_GENERIC_DEFINITION_H
#define GENERIC__INTERFACES_GENERIC_GENERIC_DEFINITION_H 

#include "Fundamental/SizeDefinition.h"
#include "Array/ArrayGenericDefinition.h"

typedef struct Generic Generic;

struct GenericManager;

typedef void (*GenericManagerIndexFunction) (
    struct Array p_output, struct Array p_start, struct Array p_offset,
    struct GenericManager* p_manager
);
typedef void (*GenericManagerBinaryFunction) (
    struct Array p_from, struct Array p_to, struct GenericManager* p_manager
);


struct GenericManager
{

    void* State;

    GenericManagerIndexFunction
        ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsPositiveOffsetsUsingGenericManager;
    GenericManagerIndexFunction
        ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsNegativeOffsetsUsingGenericManager;

    GenericManagerBinaryFunction MoveFromArrayFromArrayUsingGenericManager;
    GenericManagerBinaryFunction SwapFromArrayFromArrayUsingGenericManager;

};

#endif //GENERIC__INTERFACES_GENERIC_GENERIC_DEFINITION_H