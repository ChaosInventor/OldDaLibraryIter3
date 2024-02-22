#ifndef CALLBACK__INTERFACES_CALLBACK_CALLBACK_DEFINITION_H
#define CALLBACK__INTERFACES_CALLBACK_CALLBACK_DEFINITION_H

struct Callback;

typedef void (*CallbackFunction) (struct Callback* restrict p_callback);

struct Callback
{

    void* State;
    
    CallbackFunction Function;

};

#endif //CALLBACK__INTERFACES_CALLBACK_CALLBACK_DEFINITION_H