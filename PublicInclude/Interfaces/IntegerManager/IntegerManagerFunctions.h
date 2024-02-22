#ifndef INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_FUNCTIONS_H
#define INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_FUNCTIONS_H

#include "Fundamental/BooleanDefinition.h"
#include "Fundamental/SizeDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"
#include "Array/ArrayGenericDefinition.h"
#include "IntegerManagerDefinition.h"

//TODO: Max and min functions.
//TODO: Other logical functoins.

Boolean IntergerIsEqualToIntegerInContextOfIntegerManager(
    Integer* restrict p_left, Integer* restrict p_right,
    struct IntegerManager* restrict p_manager
);
Boolean IntergerIsGreaterThanIntegerInContextOfIntegerManager(
    Integer* restrict p_left, Integer* restrict p_right,
    struct IntegerManager* restrict p_manager
);
Boolean IntergerIsLessThanIntegerInContextOfIntegerManager(
    Integer* restrict p_left, Integer* restrict p_right,
    struct IntegerManager* restrict p_manager
);


void
FindFromArrayAsIntergersFromArrayAsIntegersToArrayAsIntegerResultsUsingIntegerManagerFromSizeAsOperatorToSizeAsOverflowIndexCallbackOnOverflow(
    struct Array p_intergersLeft, struct Array p_integersRight,
    struct Array p_results, struct IntegerManager* restrict p_manager,
    Size p_depth, Size* restrict p_overflowIndex,
    struct Callback* restrict p_overflow
);
void FindUsingIntegerToIntegerPointerAsSuccessorUsingIntegerManagerCallbackOnOverflow(
    Integer* p_integer, Integer** p_successor,
    struct IntegerManager* restrict p_manager,
    struct Callback* restrict p_overflow
);
void FindUsingIntegerToIntegerPointerAsPredecessorUsingIntegerManagerCallbackOnOverflow(
    Integer* p_integer, Integer** p_predecessor,
    struct IntegerManager* restrict p_manager,
    struct Callback* restrict p_overflow
);
void
FindUsingIntegerAsLeftUsingIntegerAsRightToIntegerPointerAsResultFromSizeAsOperatorUsingIntergerManagerCallbacOnOverflow(
    Integer* p_left, Integer* p_right, Integer** p_result, Size p_operator,
    struct IntegerManager* restrict p_manager,
    struct Callback* restrict p_overflow
);


void MoveToIntegerManagerUsingIntegerManager(
    struct IntegerManager* restrict p_to, struct IntegerManager* restrict p_from
);

#endif //INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_FUNCTIONS_H