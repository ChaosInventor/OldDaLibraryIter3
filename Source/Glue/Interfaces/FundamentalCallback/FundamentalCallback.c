#include "Glue/Interfaces/FundamentalCallback/FundamentalCallback.h"
#include "Glue/Debug/CallbackDebug/CallbackDebug.h"

struct Callback CreateCallbackAsSetToSizeMaxUsingSize(Size* restrict p_size)
{
    return (struct Callback) {
        .State = p_size,
        .Function = Callback_SetToSizeMax
    };
}
struct Callback CreateCallbackAsSetToSizeMinUsingSize(Size* restrict p_size)
{
    return (struct Callback) {
        .State = p_size,
        .Function = Callback_SetToSizeMin
    };
}
struct Callback CreateCallbackAsSetToByteMaxUsingByte(Byte* restrict p_byte)
{
    return (struct Callback) {
        .State = p_byte,
        .Function = Callback_SetToByteMax
    };
}
struct Callback CreateCallbackAsSetToByteMinUsingByte(Byte* restrict p_byte)
{
    return (struct Callback) {
        .State = p_byte,
        .Function = Callback_SetToByteMin
    };
}
struct Callback CreateCallbackAsSetToBooleanTrueUsingBoolean(
    Boolean* restrict p_bool
)
{
    return (struct Callback) {
        .State = p_bool,
        .Function = Callback_SetToBooleanTrue
    };
}
struct Callback CreateCallbackAsSetToBooleanFalseUsingBoolean(
    Boolean* restrict p_bool
)
{
    return (struct Callback) {
        .State = p_bool,
        .Function = Callback_SetToBooleanFalse
    };
}


void Callback_SetToSizeMax(struct Callback* restrict p_callback)
{

    DaLibrary_AssumeValidPointer(p_callback)
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_SetToSizeMax,
        "Callback " CallbackFormat " does not appear to be a set to size max "
        "callback", CallbackArgs(*p_callback)
    );

    Size* l_size = (Size*)p_callback->State;
    DaLibrary_AssumeValidPointer(l_size);


    *l_size = SIZE_MAXIMUM;

}
void Callback_SetToSizeMin(struct Callback* restrict p_callback)
{
    
    DaLibrary_AssumeValidPointer(p_callback)
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_SetToSizeMin,
        "Callback " CallbackFormat " does not appear to be a set to size min "
        "callback", CallbackArgs(*p_callback)
    );

    Size* l_size = (Size*)p_callback->State;
    DaLibrary_AssumeValidPointer(l_size);


    *l_size = SIZE_MINIMUM;

}
void Callback_SetToByteMax(struct Callback* restrict p_callback)
{

    DaLibrary_AssumeValidPointer(p_callback)
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_SetToByteMax,
        "Callback " CallbackFormat " does not appear to be a set to byte max "
        "callback", CallbackArgs(*p_callback)
    );

    Byte* l_byte = (Byte*)p_callback->State;
    DaLibrary_AssumeValidPointer(l_byte);


    *l_byte = BYTE_MAXIMUM;

}
void Callback_SetToByteMin(struct Callback* restrict p_callback)
{
    
    DaLibrary_AssumeValidPointer(p_callback)
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_SetToByteMin,
        "Callback " CallbackFormat " does not appear to be a set to byte min "
        "callback", CallbackArgs(*p_callback)
    );

    Byte* l_byte = (Byte*)p_callback->State;
    DaLibrary_AssumeValidPointer(l_byte);


    *l_byte = BYTE_MINIMUM;

}
void Callback_SetToBooleanTrue(struct Callback* restrict p_callback)
{

    DaLibrary_AssumeValidPointer(p_callback)
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_SetToBooleanTrue,
        "Callback " CallbackFormat " does not appear to be a set to boolean "
        "true callback", CallbackArgs(*p_callback)
    );

    Boolean* l_boolean = (Boolean*)p_callback->State;
    DaLibrary_AssumeValidPointer(l_boolean);


    *l_boolean = TRUE;

}
void Callback_SetToBooleanFalse(struct Callback* restrict p_callback)
{

    DaLibrary_AssumeValidPointer(p_callback)
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_SetToBooleanFalse,
        "Callback " CallbackFormat " does not appear to be a set to boolean "
        "false callback", CallbackArgs(*p_callback)
    );

    Boolean* l_boolean = (Boolean*)p_callback->State;
    DaLibrary_AssumeValidPointer(l_boolean);


    *l_boolean = FALSE;

}
