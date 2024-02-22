#include "Interfaces/ElementManager/ElementManager.h"
#include "Interfaces/Sequence/SequenceFunctions.h"
#include "Array/ArrayGenericFunctions.h"
#include "Fundamental/Boolean.h"
#include "Glue/Debug/SequenceDebug/SequenceDebug.h"
#include "Glue/Debug/ElementDebug/ElementManagerDebug.h"

void 
ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager(
    struct Sequence* restrict p_inequal,
    struct Sequence* restrict p_elementsLeft,
    struct Sequence* restrict p_elementsRight,
    struct ElementManager* restrict p_manager
)
{

    DaLibrary_AssumeValidPointer(p_inequal);
    DaLibrary_Assume(
        ValidSequence(*p_inequal), SequenceFormat,
        SequenceArgs(*p_inequal)
    );
    DaLibrary_AssumeValidPointer(p_manager);
    DaLibrary_Assume(
        ValidElementManager(*p_manager), ElementManagerFormat,
        ElementManagerArgs(*p_manager)
    );


    if(p_manager->ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager != NULL)
    {
        p_manager->ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager(
            p_inequal, p_elementsLeft, p_elementsRight, p_manager
        );
        return;
    }
    else
    {
        p_manager->ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager(
            p_inequal, p_elementsLeft, p_elementsRight, p_manager
        );

        ForeachInSequenceCurrentForward(*p_inequal, l_cur)
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
ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager_Null(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elementsLeft,
    struct Sequence* restrict p_elementsRight,
    struct ElementManager* restrict p_manager
)
{

    (void)p_elementsLeft;
    (void)p_elementsRight;
    (void)p_manager;

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
ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager_Null(
    struct Sequence* restrict p_booleanResults,
    struct Sequence* restrict p_elementsLeft,
    struct Sequence* restrict p_elementsRight,
    struct ElementManager* restrict p_manager
)
{

    (void)p_elementsLeft;
    (void)p_elementsRight;
    (void)p_manager;   

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


struct ElementManager g_NullElementManager = {
    .State = NULL,
    .ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager =
        ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager_Null,
    .ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager =
        ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager_Null
};
