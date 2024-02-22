#include "Interfaces/Sequence/BooleanSequenceFunctions.h"

#include "Interfaces/Sequence/SequenceFunctions.h"
#include "Array/ArrayGenericConstants.h"
#include "Fundamental/Boolean.h"
#include "Debug/Debug.h"
#include "Glue/Debug/SequenceDebug/SequenceDebug.h"
#include "Glue/Debug/ArrayDebug/ArrayDebug.h"


struct Sequence CreateSequenceAsBooleanFalseSequenceFromArrayPointerAsBooleans(
    struct Array* p_booleans
)
{

    struct Sequence l_returnValue = {
        .State = p_booleans,
        .ReadArrayAsNextUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_BooleanFalse,
        .ReadArrayAsCurrentUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_BooleanFalse
    };

    return l_returnValue;

}
struct Sequence CreateSequenceAsBooleanTrueSequenceFromArrayPointerAsBooleans(
    struct Array* p_booleans
)
{

    struct Sequence l_returnValue = {
        .State = p_booleans,
        .ReadArrayAsNextUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_BooleanTrue,
        .ReadArrayAsCurrentUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_BooleanTrue
    };

    return l_returnValue;

}


struct Array ReadArrayUsingSequenceCallbackOnEnd_BooleanFalse(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
)
{

    DaLibrary_AssumeValidPointer(p_sequence);
    DaLibrary_Check(
        p_sequence->ReadArrayAsNextUsingSequenceCallbackOnEnd
        ==
        ReadArrayUsingSequenceCallbackOnEnd_BooleanFalse,
        "Sequence " SequenceFormat " does not apper to be a boolean sequence",
        SequenceArgs(*p_sequence)
    );
    DaLibrary_Check(
        p_sequence->ReadArrayAsCurrentUsingSequenceCallbackOnEnd
        ==
        ReadArrayUsingSequenceCallbackOnEnd_BooleanFalse,
        "Sequence " SequenceFormat " does not apper to be a boolean sequence",
        SequenceArgs(*p_sequence)
    );

    struct Array* l_booleans = (struct Array*)p_sequence->State;
    DaLibrary_Assert(
        ValidPointer(l_booleans),
        "Boolean sequence must have its state point to a valid boolean array. "
        "The state points to %p", p_sequence->State
    );
    DaLibrary_Assert(
        ValidArray(*l_booleans, Boolean),
        "Boolean sequence must have its state point to a valid boolean array. "
        "In this case the state points to array " ArrayFormat " array.",
        ArrayArgs(*l_booleans)
    );
    DaLibrary_Assert(
        !ArrayIsNull(*l_booleans),
        "A boolean sequence cannot be used with a null array."
    );


    ForeachInArrayFirstType(*l_booleans, l_bool, Boolean*)
    {
        if(l_bool == FALSE)
        {
            *p_sequence = (struct Sequence) {
                .State = NULL,
                .ReadArrayAsNextUsingSequenceCallbackOnEnd = ReadArrayUsingSequenceCallbackOnEnd_Empty,
                .ReadArrayAsCurrentUsingSequenceCallbackOnEnd = ReadArrayUsingSequenceCallbackOnEnd_Empty
            };
        }

        return NULL_ARRAY;
    }

    return *l_booleans;

}
struct Array ReadArrayUsingSequenceCallbackOnEnd_BooleanTrue(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
)
{

    DaLibrary_AssumeValidPointer(p_sequence);
    DaLibrary_Check(
        p_sequence->ReadArrayAsNextUsingSequenceCallbackOnEnd
        ==
        ReadArrayUsingSequenceCallbackOnEnd_BooleanTrue,
        "Sequence " SequenceFormat " does not apper to be a boolean sequence",
        SequenceArgs(*p_sequence)
    );
    DaLibrary_Check(
        p_sequence->ReadArrayAsCurrentUsingSequenceCallbackOnEnd
        ==
        ReadArrayUsingSequenceCallbackOnEnd_BooleanTrue,
        "Sequence " SequenceFormat " does not apper to be a boolean sequence",
        SequenceArgs(*p_sequence)
    );

    struct Array* l_booleans = (struct Array*)p_sequence->State;
    DaLibrary_Assert(
        ValidPointer(l_booleans),
        "Boolean sequence must have its state point to a valid boolean array. "
        "The state points to %p", p_sequence->State
    );
    DaLibrary_Assert(
        ValidArray(*l_booleans, Boolean),
        "Boolean sequence must have its state point to a valid boolean array. "
        "In this case the state points to array " ArrayFormat " array.",
        ArrayArgs(*l_booleans)
    );
    DaLibrary_Assert(
        !ArrayIsNull(*l_booleans),
        "A boolean sequence cannot be used with a null array."
    );


    ForeachInArrayFirstType(*l_booleans, l_bool, Boolean*)
    {
        if(l_bool == TRUE)
        {
            *p_sequence = (struct Sequence) {
                .State = NULL,
                .ReadArrayAsNextUsingSequenceCallbackOnEnd = ReadArrayUsingSequenceCallbackOnEnd_Empty,
                .ReadArrayAsCurrentUsingSequenceCallbackOnEnd = ReadArrayUsingSequenceCallbackOnEnd_Empty
            };
        }

        return NULL_ARRAY;
    }

    return *l_booleans;

}
