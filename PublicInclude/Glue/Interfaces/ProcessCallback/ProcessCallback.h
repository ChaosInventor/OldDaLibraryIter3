//TODO: Implement
#ifndef PROCESS_CALLBACK__GLUE_INTERFACES_PROCESS_CALLBACK_PROCESS_CALLBACK_H
#define PROCESS_CALLBACK__GLUE_INTERFACES_PROCESS_CALLBACK_PROCESS_CALLBACK_H 

#include "Interfaces/Callback/CallbackDefinition.h"

struct Callback CreateCallbackAsExit();
struct Callback CreateCallbackAsAbort();

void Callback_Exit(struct Callback* restrict p_callback);
void Callback_Abort(struct Callback* restrict p_callback);

#endif //PROCESS_CALLBACK__GLUE_INTERFACES_PROCESS_CALLBACK_PROCESS_CALLBACK_H