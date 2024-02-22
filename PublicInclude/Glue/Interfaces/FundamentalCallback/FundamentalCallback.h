#ifndef FUNDAMENTAL_CALLBACK__GLUE_INTERFACES_FUNDAMENTAL_CALLBACK_FUNDAMENTAL_CALLBACK_H
#define FUNDAMENTAL_CALLBACK__GLUE_INTERFACES_FUNDAMENTAL_CALLBACK_FUNDAMENTAL_CALLBACK_H 

#include "Interfaces/Callback/CallbackDefinition.h"
#include "Fundamental/Fundamental.h"

struct Callback CreateCallbackAsSetToSizeMaxUsingSize(Size* restrict p_size);
struct Callback CreateCallbackAsSetToSizeMinUsingSize(Size* restrict p_size);
struct Callback CreateCallbackAsSetToByteMaxUsingByte(Byte* restrict p_byte);
struct Callback CreateCallbackAsSetToByteMinUsingByte(Byte* restrict p_byte);
struct Callback CreateCallbackAsSetToBooleanTrueUsingBoolean(
    Boolean* restrict p_bool
);
struct Callback CreateCallbackAsSetToBooleanFalseUsingBoolean(
    Boolean* restrict p_bool
);


void Callback_SetToSizeMax(struct Callback* restrict p_callback);
void Callback_SetToSizeMin(struct Callback* restrict p_callback);
void Callback_SetToByteMax(struct Callback* restrict p_callback);
void Callback_SetToByteMin(struct Callback* restrict p_callback);
void Callback_SetToBooleanTrue(struct Callback* restrict p_callback);
void Callback_SetToBooleanFalse(struct Callback* restrict p_callback);

#endif //FUNDAMENTAL_CALLBACK__GLUE_INTERFACES_FUNDAMENTAL_CALLBACK_FUNDAMENTAL_CALLBACK_H