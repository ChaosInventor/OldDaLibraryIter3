#include "Interfaces/Sequence/ArraySequenceFunctions.h"

struct Sequence CreateOnceArraySequenceFromArrayPointer(struct Array* p_array)
{
    return (struct Sequence) {
        .State = p_array,
        .ReadArrayAsNextUsingSequenceCallbackOnEnd =
            ReadArrayUsingSequenceCallbackOnEnd_ArrayOnce
    };
}
struct Sequence CreateInfiniteArraySequenceFromArrayPointer(
    struct Array p_array
)
{

}


struct Array ReadArrayUsingSequenceCallbackOnEnd_ArrayOnce(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);
struct Array ReadArrayUsingSequenceCallbackOnEnd_ArrayInfinite(
    struct Sequence* restrict p_sequence, struct Callback* restrict p_onEnd
);