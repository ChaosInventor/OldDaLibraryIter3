#ifndef SEQUENCE__INTERFACES_SEQUENCE_CALLBACK_SEQUENCE_DEFINITION_H
#define SEQUENCE__INTERFACES_SEQUENCE_CALLBACK_SEQUENCE_DEFINITION_H 

#include "SequenceDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"
#include "Array/ArrayGenericDefinition.h"

struct CallbackSequence
{
    struct Sequence* Wrapped;
    struct Callback* Callbacks[5];
};

#endif //SEQUENCE__INTERFACES_SEQUENCE_CALLBACK_SEQUENCE_DEFINITION_H