#ifndef ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_FUNCTIONS_H
#define ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_FUNCTIONS_H 

#include "ElementManagerDefinition.h"
#include "Interfaces/Sequence/SequenceDefinition.h"
#include "Fundamental/BooleanDefinition.h"

void 
ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager(
    struct Sequence* restrict p_inequal,
    struct Sequence* restrict p_elementsLeft,
    struct Sequence* restrict p_elementsRight,
    struct ElementManager* restrict p_manager
);
void 
ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager_Null(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elementsLeft,
    struct Sequence* restrict p_elementsRight,
    struct ElementManager* restrict p_manager
);

#endif //ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_FUNCTIONS_H