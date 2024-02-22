#ifndef SET__INTERFACES_SET_SET_DEFINITION_H
#define SET__INTERFACES_SET_SET_DEFINITION_H 

#include "Interfaces/ElementManager/ElementManagerDefinition.h"
#include "Interfaces/Sequence/SequenceDefinition.h"
#include "Fundamental/BooleanDefinition.h"

struct Set;

typedef void (*SetMembershipFunction) (
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elements,
    struct ElementManager* restrict p_manager, struct Set* restrict p_set
);

struct Set
{

    struct Sequence Elements;

    SetMembershipFunction
        ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet;
        
    SetMembershipFunction
        ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet;

};

#endif //SET__INTERFACES_SET_SET_DEFINITION_H