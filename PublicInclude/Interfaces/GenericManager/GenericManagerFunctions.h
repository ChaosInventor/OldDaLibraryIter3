#ifndef GENERIC__INTERFACES_GENERIC_GENERIC_FUNCTIONS_H
#define GENERIC__INTERFACES_GENERIC_GENERIC_FUNCTIONS_H 

#include "GenericManagerDefinition.h"

void
ComputeToGenericAsOffsetLocationFromGenericPointerAsLocationFromSizeAsPositiveOffsetUsingGenericManager(
    Generic* p_output, Generic* p_start, Size p_offset, struct GenericManager* p_manager
);
void
ComputeToGenericAsOffsetLocationFromGenericPointerAsLocationFromSizeAsNegativeOffsetUsingGenericManager(
    Generic* p_output, Generic* p_start, Size p_offset, struct GenericManager* p_manager
);


void MoveUsingGenericToGenericUsingGenericManager(
    Generic* p_from, Generic* p_to, struct GenericManager* p_manager
);
void SwapUsingGenericToGenericUsingGenericManager(
    Generic* p_from, Generic* p_to, struct GenericManager* p_manager
);

#endif //GENERIC__INTERFACES_GENERIC_GENERIC_FUNCTIONS_H