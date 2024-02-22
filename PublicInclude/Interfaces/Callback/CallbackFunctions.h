#ifndef CALLBACK__INTERFACES_CALLBACK_CALLBACK_FUNCTIONS_H
#define CALLBACK__INTERFACES_CALLBACK_CALLBACK_FUNCTIONS_H

#include "CallbackDefinition.h"

struct Callback CreateCallbackAsNull(void);
struct Callback CreateCallbackAsMoveUsing2CallbackPointers(
    struct Callback* p_callbacks[2]
);
struct Callback CreateCallbackAsForkUsing2CallbackPointers(
    struct Callback* p_callbacks[2]
);


void Callback(struct Callback* restrict p_callback);
void Callback_Null(struct Callback* restrict p_callback);
void Callback_Move(struct Callback* restrict p_callback);
void Callback_Fork(struct Callback* restrict p_callback);


void MoveToCallbackUsingCallback(
    struct Callback* restrict p_moveTo, struct Callback* restrict p_moveFrom
);

#endif //CALLBACK__INTERFACES_CALLBACK_CALLBACK_FUNCTIONS_H