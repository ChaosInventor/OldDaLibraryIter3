#ifndef SET__INTERFACES_SET_SET_FUNCTIONS_H
#define SET__INTERFACES_SET_SET_FUNCTIONS_H

#include "SetDefinition.h"

void
ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elements,
    struct ElementManager* restrict p_manager, struct Set* restrict p_set
);
void
ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet_Empty(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elements,
    struct ElementManager* restrict p_manager, struct Set* restrict p_set
);
void
ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet_Empty(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elements,
    struct ElementManager* restrict p_manager, struct Set* restrict p_set
);

Boolean SetPointerIsEmpty(struct Set* restrict p_set);
Boolean SetIsEqualedToSetUsingElementManagerUsingArrayAsBooleanBuffer(
    struct Set* restrict p_left, struct Set* restrict p_right,
    struct ElementManager* restrict p_manager, struct Array p_boolBuffer
);
Boolean SetIsSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
    struct Set* restrict p_left, struct Set* restrict p_right,
    struct ElementManager* restrict p_manager, struct Array p_boolBuffer
);
Boolean SetIsProperSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
    struct Set* restrict p_left, struct Set* restrict p_right,
    struct ElementManager* restrict p_manager, struct Array p_boolBuffer
);

#endif //SET__INTERFACES_SET_SET_FUNCTIONS_H
