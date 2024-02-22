#include "Interfaces/Callback/Callback.h"
#include "Glue/Debug/CallbackDebug/CallbackDebug.h"

struct Callback CreateCallbackAsNull(void)
{
    return (struct Callback) {
        .Function = Callback_Null
    };
}
struct Callback CreateCallbackAsMoveUsing2CallbackPointers(
    struct Callback* p_callbacks[2]
)
{
    return (struct Callback) {
        .State = p_callbacks,
        .Function = Callback_Move
    };
}
struct Callback CreateCallbackAsForkUsing2CallbackPointers(
    struct Callback* p_callbacks[2]
)
{
    return (struct Callback) {
        .State = p_callbacks,
        .Function = Callback_Fork
    };
}


void Callback(struct Callback* restrict p_callback)
{
    DaLibrary_AssumeValidPointer(p_callback)
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(p_callback)
    );
    p_callback->Function(p_callback->State);
}
void Callback_Null(struct Callback* restrict p_callback)
{
    (void)p_callback;
    return;
}
void Callback_Move(struct Callback* restrict p_callback)
{

    DaLibrary_AssumeValidPointer(p_callback);
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(*p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_Move,
        "Callback " CallbackFormat " does not appear to be a move callback",
        CallbackArgs(*p_callback)
    );

    struct Callback* l_callbacks[2] = (struct Callback**)p_callback->State;
    DaLibrary_AssumeValidPointer(l_callbacks);
    DaLibrary_AssumeValidPointer(l_callbacks[0]);
    DaLibrary_AssumeValidPointer(l_callbacks[1]);


    MoveToCallbackUsingCallback(l_callbacks[0], l_callbacks[1]);

}
void Callback_Fork(struct Callback* restrict p_callback)
{

    DaLibrary_AssumeValidPointer(p_callback);
    DaLibrary_Assume(
        ValidCallback(*p_callback), CallbackFormat, CallbackArgs(*p_callback)
    );

    DaLibrary_Check(
        p_callback->Function == Callback_Fork,
        "Callback " CallbackFormat " does not appear to be a fork callback",
        CallbackArgs(*p_callback)
    );

    struct Callback* l_callbacks[2] = (struct Callback**)p_callback->State;
    DaLibrary_AssumeValidPointer(l_callbacks);
    DaLibrary_AssumeValidPointer(l_callbacks[0]);
    DaLibrary_AssumeValidPointer(l_callbacks[1]);


    Callback(l_callbacks[0]);
    Callback(l_callbacks[1]);

}


void MoveToCallbackUsingCallback(
    struct Callback* restrict p_moveTo, struct Callback* restrict p_moveFrom
)
{

    DaLibrary_AssumeValidPointer(p_moveTo);
    DaLibrary_AssumeValidPointer(p_moveFrom);

    *p_moveTo = (struct Callback) {
        .State = p_moveFrom->State,
        .Function = p_moveFrom->Function
    };
    *p_moveFrom = (struct Callback) { 0 };

}
