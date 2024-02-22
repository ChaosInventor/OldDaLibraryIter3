#ifndef INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_DEFINITION_H
#define INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_DEFINITION_H

#include "Fundamental/SizeDefinition.h"
#include "Fundamental/BooleanDefinition.h"
#include "Fundamental/ByteDefinition.h"
#include "Array/ArrayGenericDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"

typedef struct Integer Integer;
struct IntegerManager;

#define IntegerManagerFromFunctionArguments \
    struct Array p_longLongs, struct Array p_integers,  \
    struct IntegerManager* restrict p_manager
typedef void (*IntegerManagerFromFunction) (
    IntegerManagerFromFunctionArguments
);
#define IntegerManagerToFunctionArguments \
    struct Array p_integers, struct Array p_longLongs,  \
    struct IntegerManager* restrict p_manager
typedef void (*IntegerManagerToFunction) (
    IntegerManagerToFunctionArguments
);

#define IntegerManagerUnaryLogicFunctionArguments \
    struct Array p_booleanResults, struct Array p_integers, \
    struct IntegerManager* restrict p_manager
typedef void (*IntegerManagerUnaryLogicFunction) (
    IntegerManagerUnaryLogicFunctionArguments
);

typedef void (*IntegerManagerUnaryFunction) (
    struct Array p_integers, struct Array p_results,
    struct IntegerManager* restrict p_manager, Size* restrict p_overFlowIndex,
    struct Callback* restrict p_overflow
);

typedef void (*IntegerManagerBinaryFunction) (
    struct Array p_integersLeft, struct Array p_integersRight,
    struct Array p_results, struct IntegerManager* restrict p_manager,
    Size* restrict p_overflowIndex, struct Callback* restrict p_overflow
);

struct IntegerManager
{

    void* State;

    IntegerManagerFromFunction
        ConvertFromArrayAsLongLongsFromArrayAsIntegersUsingIntegerManager;
    IntegerManagerToFunction
        ConvertFromArrayAsIntegersFromArrayAsLongLongsUsingIntegerManager;

    IntegerManagerUnaryLogicFunction
        ComputeToArrayAsBooleansGreaterThanZeroFromArrayAsIntegersUsingIntegerManager;
    IntegerManagerUnaryLogicFunction
        ComputeToArrayAsBooleansLesserThanZeroFromArrayAsIntegersUsingIntegerManager;
    IntegerManagerUnaryLogicFunction
        ComputeToArrayAsBooleansEqualToZeroFromArrayAsIntegersUsingIntegerManager;

};

#endif //INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_DEFINITION_H