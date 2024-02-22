#ifndef CALLBACK_DEBUG_GLUE_DEBUG_CALLBACK_DEBUG_CALLBACK_DEBUG_H
#define CALLBACK_DEBUG_GLUE_DEBUG_CALLBACK_DEBUG_CALLBACK_DEBUG_H 

#include "Debug/Debug.h"
#include "Callback/CallbackDefinition.h"

#ifndef CallbackFormat
#define CallbackFormat "%p { State = %p, Function = %%FUNCTION_POINTER }"
#endif //CallbackFormat

#ifndef CallbackArgs
#define CallbackArgs(p_callback) \
    &(p_callback), (p_callback).State, (p_callback).Function
#endif //CallbackArgs

#define ValidCallback(p_callback) ValidFunctionPointer((p_callback).Function)

#endif //CALLBACK_DEBUG_GLUE_DEBUG_CALLBACK_DEBUG_CALLBACK_DEBUG_H