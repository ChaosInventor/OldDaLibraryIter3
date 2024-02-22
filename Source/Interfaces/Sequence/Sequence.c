#include "Interfaces/Sequence/Sequence.h"

#include "Fundamental/Boolean.h"
#include "Array/ArrayGeneric.h"
#include "Debug/Debug.h"
#include "Glue/Debug/SequenceDebug/SequenceDebug.h"

struct Sequence CreateSequenceAsEmpty(void)
{
    return (struct Sequence) {
        .ReadArrayAsNextUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_Empty,
        .ReadArrayAsCurrentUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_Empty,
        .ReadArrayAsPreviousUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_Empty,
        .ReadArrayAsFirstUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_Empty,
        .ReadArrayAsLastUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_Empty
    };
}


Boolean SequencePointerIsEmpty(struct Sequence* restrict p_sequence)
{

    DaLibrary_AssumeValidPointer(p_sequence);
    DaLibrary_Assume(
        ValidSequence(*p_sequence), SequenceFormat, SequenceArgs(*p_sequence)
    );


    struct Array l_array;
    struct Callback l_null = CreateCallbackAsNull();

    l_array = p_sequence->ReadArrayAsNextUsingSequenceCallbackOnEnd(
        p_sequence, &l_null
    );
    if(!ArrayIsNull(l_array))
    {
        return FALSE;
    }

    l_array = p_sequence->ReadArrayAsCurrentUsingSequenceCallbackOnEnd(
        p_sequence, &l_null
    );
    if(!ArrayIsNull(l_array))
    {
        return FALSE;
    }

    if(p_sequence->ReadArrayAsPreviousUsingSequenceCallbackOnEnd != NULL)
    {
        l_array = p_sequence->ReadArrayAsPreviousUsingSequenceCallbackOnEnd(
            p_sequence, &l_null
        );
        if(!ArrayIsNull(l_array))
        {
            return FALSE;
        }
    }

    if(p_sequence->ReadArrayAsFirstUsingSequenceCallbackOnEnd != NULL)
    {
        l_array = p_sequence->ReadArrayAsFirstUsingSequenceCallbackOnEnd(
            p_sequence, &l_null
        );
        if(!ArrayIsNull(l_array))
        {
            return FALSE;
        }
    }

    if(p_sequence->ReadArrayAsLastUsingSequenceCallbackOnEnd != NULL)
    {
        l_array = p_sequence->ReadArrayAsLastUsingSequenceCallbackOnEnd(
            p_sequence, &l_null
        );
        if(!ArrayIsNull(l_array))
        {
            return FALSE;
        }
    }

    return TRUE;

}


struct Array ReadArrayAsFirstUsingSequenceCallbackOnEnd(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
)
{

    DaLibrary_AssumeValidPointer(p_sequence);
    DaLibrary_Assume(
        ReversableSequence(*p_sequence), SequenceFormat,
        SequenceArgs(*p_sequence)
    );


    if(p_sequence->ReadArrayAsFirstUsingSequenceCallbackOnEnd != NULL)
    {
        return p_sequence->ReadArrayAsFirstUsingSequenceCallbackOnEnd(
            p_sequence, p_onEnd
        );
    }
    else
    {
        struct Callback l_null = CreateCallbackAsNull();
        ForeachInSequenceCurrentBackwardCallback(*p_sequence, _, &l_null)
        {
            continue;
        }
        return p_sequence->ReadArrayAsNextUsingSequenceCallbackOnEnd(
            p_sequence, p_onEnd
        );
    }

}
struct Array ReadArrayAsLastUsingSequenceCallbackOnEnd(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
)
{

    DaLibrary_AssumeValidPointer(p_sequence);
    DaLibrary_Assume(
        ReversableSequence(*p_sequence), SequenceFormat,
        SequenceArgs(*p_sequence)
    );


    if(p_sequence->ReadArrayAsLastUsingSequenceCallbackOnEnd != NULL)
    {
        return p_sequence->ReadArrayAsLastUsingSequenceCallbackOnEnd(
            p_sequence, p_onEnd
        );
    }
    else
    {
        struct Callback l_null = CreateCallbackAsNull();
        ForeachInSequenceCurrentForwardCallback(*p_sequence, _, &l_null)
        {
            continue;
        }
        return p_sequence->ReadArrayAsPreviousUsingSequenceCallbackOnEnd(
            p_sequence, p_onEnd
        );
    }

}
struct Array ReadArrayUsingSequenceCallbackOnEnd_Empty(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
)
{
    (void)p_sequence;
    (void)p_onEnd;
    return NULL_ARRAY;
}
