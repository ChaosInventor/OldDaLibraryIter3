#ifndef ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_DEFINITION_H
#define ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_DEFINITION_H 

#include "Interfaces/Sequence/SequenceDefinition.h"
#include "Fundamental/BooleanDefinition.h"

typedef struct Element Element;
struct ElementManager;

typedef void (*ElementManagerCompareFunction) (
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elementsLeft,
    struct Sequence* restrict p_elementsRight,
    struct ElementManager* restrict p_manager
);

struct ElementManager
{

    void* State;

    ElementManagerCompareFunction
        ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager;

    ElementManagerCompareFunction
        ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager;

};

#endif //ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_DEFINITION_H