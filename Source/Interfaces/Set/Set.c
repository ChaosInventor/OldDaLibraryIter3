#include "Interfaces/Set/Set.h"

#include "Fundamental/Boolean.h"
#include "Array/ArrayGenericFunctions.h"
#include "Interfaces/Sequence/SequenceFunctions.h"
#include "Glue/Debug/SetDebug/SetDebug.h"
#include "Glue/Debug/ElementDebug/ElementManagerDebug.h"
#include "Glue/Debug/ArrayDebug/ArrayDebug.h"
#include "Extensions/Interfaces/Sequence/BooleanSequence.h"

void
ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elements,
    struct ElementManager* restrict p_manager, struct Set* restrict p_set
)
{

    DaLibrary_AssumeValidPointer(p_set);
    DaLibrary_Assume(ValidSet(*p_set), SetFormat, SetArgs(*p_set));


    if(p_set->ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet != NULL)
    {
        p_set->ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet(
            p_booleanResults, p_elements, p_manager, p_set
        );
        return;
    }
    else
    {
        p_set->ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet(
            p_booleanResults, p_elements, p_manager, p_set
        );

        ForeachInSequenceCurrentForward(*p_booleanResults, l_cur)
        {
            ForeachInArrayFirstType(l_cur, l_bool, Boolean*)
            {
                *l_bool = !l_bool;
            }
        }

        return;
    }

}
void
ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet_Empty(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elements,
    struct ElementManager* restrict p_manager, struct Set* restrict p_set
)
{
    
    (void)p_elements;
    (void)p_manager;
    (void)p_set;

    DaLibrary_AssumeValidPointer(p_booleanResults);
    DaLibrary_Assume(
        ValidSequence(*p_booleanResults), SequenceFormat,
        SequenceArgs(*p_booleanResults)
    );


    ForeachInSequenceCurrentForward(*p_booleanResults, l_cur)
    {
        ForeachInArrayFirstType(l_cur, l_bool, Boolean*)
        {
            *l_bool = FALSE;
        }
    }

}
void
ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet_Empty(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elements,
    struct ElementManager* restrict p_manager, struct Set* restrict p_set
)
{

    (void)p_elements;
    (void)p_manager;
    (void)p_set;

    DaLibrary_AssumeValidPointer(p_booleanResults);
    DaLibrary_Assume(
        ValidSequence(*p_booleanResults), SequenceFormat,
        SequenceArgs(*p_booleanResults)
    );


    ForeachInSequenceCurrentForward(*p_booleanResults, l_cur)
    {
        ForeachInArrayFirstType(l_cur, l_bool, Boolean*)
        {
            *l_bool = TRUE;
        }
    }
    
}

Boolean SetPointerIsEmpty(struct Set* restrict p_set)
{
    DaLibrary_AssumeValidPointer(p_set);
    DaLibrary_Assume(ValidSet(*p_set), SetFormat, SetArgs(*p_set));
    return SequencePointerIsEmpty(&p_set->Elements);
}
Boolean SetIsEqualedToSetUsingElementManagerUsingArrayAsBooleanBuffer(
    struct Set* restrict p_left, struct Set* restrict p_right,
    struct ElementManager* restrict p_manager, struct Array p_boolBuffer
)
{

    DaLibrary_AssumeValidPointer(p_left);
    DaLibrary_AssumeValidPointer(p_right);
    DaLibrary_AssumeValidPointer(p_manager);

    DaLibrary_Assume(ValidSet(*p_left), SetFormat, SetArgs(*p_left));
    DaLibrary_Assume(ValidSet(*p_right), SetFormat, SetArgs(*p_right));
    DaLibrary_Assume(
        ValidElementManager(*p_manager), ElementManagerFormat,
        ElementManagerArgs(*p_manager)
    );
    DaLibrary_Assert(
        !ArrayIsNull(p_boolBuffer),
        "Cannot use array " ArrayFormat " as a buffer because it is null.",
        ArrayArgs(p_boolBuffer)
    );


    return
        SetIsSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
            p_left, p_right, p_manager, p_boolBuffer
        )
        &&
        SetIsSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
            p_right, p_left, p_manager, p_boolBuffer
        );

}
Boolean SetIsSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
    struct Set* restrict p_left, struct Set* restrict p_right,
    struct ElementManager* restrict p_manager, struct Array p_boolBuffer
)
{

    DaLibrary_AssumeValidPointer(p_left);
    DaLibrary_AssumeValidPointer(p_right);
    DaLibrary_AssumeValidPointer(p_manager);

    DaLibrary_Assume(ValidSet(*p_left), SetFormat, SetArgs(*p_left));
    DaLibrary_Assume(ValidSet(*p_right), SetFormat, SetArgs(*p_right));
    DaLibrary_Assume(
        ValidElementManager(*p_manager), ElementManagerFormat,
        ElementManagerArgs(*p_manager)
    );
    DaLibrary_Assert(
        !ArrayIsNull(p_boolBuffer),
        "Cannot use array " ArrayFormat " as a buffer because it is null.",
        ArrayArgs(p_boolBuffer)
    );


    struct Sequence l_booleanSequence =
        CreateSequenceAsBooleanFalseSequenceFromArrayPointerAsBooleans(
            &p_boolBuffer
        );

    p_right->ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet(
        &l_booleanSequence, &p_left->Elements, p_manager, p_right
    );

    //If there was a single false written to the boolean sequence, its state
    //would be set to null.
    return !(l_booleanSequence.State == NULL);

}
Boolean SetIsProperSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
    struct Set* restrict p_left, struct Set* restrict p_right,
    struct ElementManager* restrict p_manager, struct Array p_boolBuffer
)
{

    DaLibrary_AssumeValidPointer(p_left);
    DaLibrary_AssumeValidPointer(p_right);
    DaLibrary_AssumeValidPointer(p_manager);

    DaLibrary_Assume(ValidSet(*p_left), SetFormat, SetArgs(*p_left));
    DaLibrary_Assume(ValidSet(*p_right), SetFormat, SetArgs(*p_right));
    DaLibrary_Assume(
        ValidElementManager(*p_manager), ElementManagerFormat,
        ElementManagerArgs(*p_manager)
    );
    DaLibrary_Assert(
        !ArrayIsNull(p_boolBuffer),
        "Cannot use array " ArrayFormat " as a buffer because it is null.",
        ArrayArgs(p_boolBuffer)
    );


    return
        SetIsSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
            p_left, p_right, p_manager, p_boolBuffer
        )
        &&
        !SetIsSubsetOfSetUsingElementManagerUsingArrayAsBooleanBuffer(
            p_right, p_left, p_manager, p_boolBuffer
        );

}

struct Set g_EmptySet = {
    .Elements = {
        NULL,
        ReadArrayUsingSequenceCallbackOnEnd_Empty,        
        ReadArrayUsingSequenceCallbackOnEnd_Empty,       
        ReadArrayUsingSequenceCallbackOnEnd_Empty,      
        ReadArrayUsingSequenceCallbackOnEnd_Empty,     
        ReadArrayUsingSequenceCallbackOnEnd_Empty        
    },
    .ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet = 
        ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet_Empty,
    .ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet = 
        ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet_Empty
};
