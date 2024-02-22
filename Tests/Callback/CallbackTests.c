#include "TF.h"
#include "TFMacroMagic.h"
#include "Interfaces/Callback/Callback.h"
#include "Fundamental/Fundamental.h"

//TODO: Complete naming system for TF objects that have names that matter.


TFTemplate(AnyCallbackTemplate)
{

    ReferenceTFTest(l_generalCallbackTest, "DaLibrary:Callback:General");

    UseTFTestToValidateTemplate(l_generalCallbackTest);

}
TFTemplate(NullCallbackTemplate)
{

    ReferenceTFTest(l_nullTest, "DaLibrary:Callback:Null");

    UseTFTestToValidateTemplate(l_nullTest);

}
TFTemplate(SetToMaxCallbackTemplate)
{

    ReferenceTFTest(l_setToMaxTest, "DaLibrary:Callback:SetToMax");

    UseTFTestToValidateTemplate(l_setToMaxTest);

}
TFTemplate(SetToMinCallbackTemplate)
{

    ReferenceTFTest(l_setToMinTest, "DaLibrary:Callback:SetToMin");

    UseTFTestToValidateTemplate(l_setToMinTest);

}
TFTemplate(SetToTrueCallbackTemplate)
{

    ReferenceTFTest(l_setToTrueTest, "DaLibrary:Callback:SetToTrue");

    UseTFTestToValidateTemplate(l_setToTrueTest);

}
TFTemplate(SetToFalseCallbackTemplate)
{

    ReferenceTFTest(l_setToFalseTest, "DaLibrary:Callback:SetToFalse");

    UseTFTestToValidateTemplate(l_setToFalseTest);

}
TFTemplate(MoveCallbackTemplate)
{

    ReferenceTFTest(l_moveTest, "DaLibrary:Callback:Move");

    UseTFTestToValidateTemplate(l_moveTest);

}
TFTemplate(ForkCallbackTemplate)
{

    ReferenceTFTest(l_forkTest, "DaLibrary:Callback:Fork");

    UseTFTestToValidateTemplate(l_forkTest);

}


TFTest(CallbackGeneral)
{

    DefineTFTestParameter(
        l_callback,
        "Callback",
        "The test parameter that is checked for being a callback",
        "DaLibrary:Callback",
        false
    );

    struct Callback* l_toCheck = GetValueFromTestParameter(l_callback);

    CleanupTFTestParameter(l_callback);


    ReferenceTFTest(l_memoryValidator, "MemoryValidator");

    PassValueToTFTest(l_toCheck, "Address", l_memoryValidator);

    Size l_sizeOfCallback = sizeof(struct Callback);
    PassValueToTFTest(&l_sizeOfCallback, "Size", l_memoryValidator);

    PassValueToTFTest(&TRUE, "Readable", l_memoryValidator);
    PassValueToTFTest(&TRUE, "Writableable", l_memoryValidator);
    PassValueToTFTest(&FALSE, "Executable", l_memoryValidator);

    TFAssertTFTestPassed(l_memoryValidator,
        "A pointer to a callback must point to the beginning of the callback, "
        "the pointer must also point to an area of memory that is as big as a "
        "callback struct and have readable and writable permissions, without "
        "execution premission"
    );

    CleanupTFTest(l_memoryValidator);


    ReferenceTFTest(l_functionPointerValidator, "FunctionPointerValidator");

    void* l_pointerToFuncion = &l_toCheck->Function;
    PassValueToTFTest(l_pointerToFuncion, "Function", l_functionPointerValidator);

    TFAssertTFTestPassed(l_functionPointerValidator,
        "A valid callback's function pointer must point to a valid function"
    );

    CleanupTFTest(l_functionPointerValidator);

}
TFTest(CallbackNull)
{

    ReferenceTFTemplate(l_callbackTemplate, "DaLibrary:Callback:Any");
    DefineTFTestParameterWithTemplate(l_callbackParam, l_callbackTemplate,
        "NullCallback",
        "The callback that will be tested for being null",
        "DaLibrary:Callback",
        false
    );
    struct Callback* l_callback = GetValueFromTestParameter(l_callbackParam);

    CleanupTemplate(l_callbackTemplate);
    CleanupTFTestParameter(l_callbackParam);


    ReferenceTFTemplate(l_pointerTemplate, "VoidPointer");
    DefineTFTestParameterWithTemplate(l_randomPointerParam, l_pointerTemplate,
        "Random pointer",
        "A random pointer that is used as the state of the callback that is "
            "being tested",
        "VoidPointer",
        false
    );

    void* l_randomPointer = GetValueFromTestParameter(l_randomPointerParam);

    CleanupTemplate(l_pointerTemplate);
    CleanupTFTestParameter(l_randomPointerParam);


    l_callback->State = l_randomPointer;

    //TODO: Settings to make sure that no changes where made to the enviornment
    l_callback->Function(l_callback);

}
TFTest(CallbackSetToMax)
{

    ReferenceTFTemplate(l_callbackTemplate, "DaLibrary:Callback:Any");
    DefineTFTestParameterWithTemplate(l_callbackParam, l_callbackTemplate,
        "SetToMaxCallback",
        "The callback that will be tested for setting to max",
        "DaLibrary:Callback",
        false
    );
    struct Callback* l_callback = GetValueFromTestParameter(l_callbackParam);

    CleanupTemplate(l_callbackTemplate);
    CleanupTFTestParameter(l_callbackParam);


    ReferenceTFTemplate(l_sizeTemplate, "DaLibrary:Fundamental:Size:Any");
    DefineTFTestParameterWithTemplate(l_sizeParam, l_sizeTemplate,
        "Size",
        "The size that will be set to max",
        "DaLibrary:Size",
        false
    );
    Size* l_size = GetValueFromTestParameter(l_sizeParam);

    CleanupTemplate(l_sizeTemplate);
    CleanupTFTestParameter(l_sizeParam);


    l_callback->State = l_size;
    l_callback->Function(l_callback);

    TFCheck(*l_size == SIZE_MAXIMUM,
        "Size must be set to the maximum value by the callback"
    );

}
TFTest(CallbackSetToMin)
{

    ReferenceTFTemplate(l_callbackTemplate, "DaLibrary:Callback:Any");
    DefineTFTestParameterWithTemplate(l_callbackParam, l_callbackTemplate,
        "SetToMinCallback",
        "The callback that will be tested for setting to min",
        "DaLibrary:Callback",
        false
    );
    struct Callback* l_callback = GetValueFromTestParameter(l_callbackParam);

    CleanupTemplate(l_callbackTemplate);
    CleanupTFTestParameter(l_callbackParam);


    ReferenceTFTemplate(l_sizeTemplate, "DaLibrary:Fundamental:Size:Any");
    DefineTFTestParameterWithTemplate(l_sizeParam, l_sizeTemplate,
        "Size",
        "The size that will be set to min",
        "DaLibrary:Size",
        false
    );
    Size* l_size = GetValueFromTestParameter(l_sizeParam);

    CleanupTemplate(l_sizeTemplate);
    CleanupTFTestParameter(l_sizeParam);


    l_callback->State = l_size;

    l_callback->Function(l_callback);

    TFCheck(*l_size == SIZE_MINIMUM,
        "Size must be set to the minimum value by the callback"
    );

}
TFTest(CallbackSetToTrue)
{

    ReferenceTFTemplate(l_callbackTemplate, "DaLibrary:Callback:Any");
    DefineTFTestParameterWithTemplate(l_callbackParam, l_callbackTemplate,
        "SetToTrueCallback",
        "The callback that will be tested for setting to true",
        "DaLibrary:Callback",
        false
    );
    struct Callback* l_callback = GetValueFromTestParameter(l_callbackParam);

    CleanupTemplate(l_callbackTemplate);
    CleanupTFTestParameter(l_callbackParam);


    ReferenceTFTemplate(l_boolTemplate, "DaLibrary:Fundamental:Boolean:Any");
    DefineTFTestParameterWithTemplate(l_boolParam, l_boolTemplate,
        "Boolean",
        "The boolean that will be set to true",
        "DaLibrary:Boolean",
        false    
    );

    Boolean* l_bool = GetValueFromTestParameter(l_boolParam);

    CleanupTemplate(l_boolTemplate);
    CleanupTFTestParameter(l_boolParam);


    l_callback->State = l_bool;
    l_callback->Function(l_callback);

    TFCheck(*l_bool == TRUE,
        "Boolean must be set to true by the callback"
    );

}
TFTest(CallbackSetToFalse)
{

    ReferenceTFTemplate(l_callbackTemplate, "DaLibrary:Callback:Any");
    DefineTFTestParameterWithTemplate(l_callbackParam, l_callbackTemplate,
        "SetToFalseCallback",
        "The callback that will be tested for setting to false",
        "DaLibrary:Callback",
        false
    );
    struct Callback* l_callback = GetValueFromTestParameter(l_callbackParam);

    CleanupTemplate(l_callbackTemplate);
    CleanupTFTestParameter(l_callbackParam);


    ReferenceTFTemplate(l_boolTemplate, "DaLibrary:Fundamental:Boolean:Any");
    DefineTFTestParameterWithTemplate(l_boolParam, l_boolTemplate,
        "Boolean",
        "The boolean that will be set to false",
        "DaLibrary:Boolean",
        false    
    );

    Boolean* l_bool = GetValueFromTestParameter(l_boolParam);

    CleanupTemplate(l_boolTemplate);
    CleanupTFTestParameter(l_boolParam);


    l_callback->State = l_bool;

    l_callback->Function(l_callback);

    TFCheck(*l_bool == FALSE,
        "Boolean must be set to false by the callback"
    );

}
TFTest(CallbackMove)
{

    ReferenceTFTemplate(l_callbackTemplate, "DaLibrary:Callback:Any");
    DefineTFTestParameterWithTemplate(l_callbackParam, l_callbackTemplate,
        "MoveCallback",
        "The callback that will be tested for moving other callbacks",
        "DaLibrary:Callback",
        false
    );
    struct Callback* l_callback = GetValueFromTestParameter(l_callbackParam);

    CleanupTFTestParameter(l_callbackParam);


    struct Callback* l_callbacks[2];

    DefineTFTestParameterWithTemplate(l_callback1Param, l_callbackTemplate,
        "Callback1",
        "The first callback that will be moved",
        "DaLibrary:Callback",
        false
    );
    l_callbacks[0] = GetValueFromTestParameter(l_callback1Param);

    CleanupTFTestParameter(l_callback1Param);


    DefineTFTestParameterWithTemplate(l_callback2Param, l_callbackTemplate,
        "Callback2",
        "The second callback that will be moved",
        "DaLibrary:Callback",
        false
    );
    l_callbacks[1] = GetValueFromTestParameter(l_callback2Param);

    CleanupTFTestParameter(l_callback2Param);
    CleanupTemplate(l_callbackTemplate);


    //Make a copy to compare to later. Technically it could lead to errors, but
    //it is fine in this context as the callback is never called.
    struct Callback l_callback0 = *l_callbacks[0];

    l_callback->State = l_callbacks;
    l_callback->Function(l_callback);

    TFCheck(
        l_callbacks[0]->State == NULL
        &&
        l_callbacks[0]->Function == NULL,
        "The first callback must now be zeroed out"
    );

    TFCheck(
        l_callbacks[1]->State == l_callback0.State
        &&
        l_callbacks[1]->Function == l_callback0.Function,
        "The second callback now must be the same as the first one"
    );

}
TFTest(CallbackFork)
{

    //TODO: This test doesn't really make sure that callback 0 is the first
    //callback that is called.

    ReferenceTFTemplate(l_callbackTemplate, "DaLibrary:Callback:Any");
    DefineTFTestParameterWithTemplate(l_callbackParam, l_callbackTemplate,
        "ForkCallback",
        "The callback that will be tested for calling other callbacks",
        "DaLibrary:Callback",
        false
    );
    struct Callback* l_callback = GetValueFromTestParameter(l_callbackParam);

    CleanupTFTestParameter(l_callbackParam);
    CleanupTemplate(l_callbackTemplate);


    ReferenceTFTemplate(l_setToTrueTemplate, "DaLibrary:Callback:SetToTrue");
    struct Callback* l_callbacks[2];

    DefineTFTestParameterWithTemplate(l_setToTrue1, l_setToTrueTemplate,
        "Callback1",
        "The first callback that will be called and set a boolean true to make "
        "sure it was actually called",
        "DaLibrary:Callback",
        false    
    );
    l_callbacks[0] = GetValueFromTestParameter(l_setToTrue1);

    CleanupTFTestParameter(l_setToTrue1);

    DefineTFTestParameterWithTemplate(l_setToTrue2, l_setToTrueTemplate,
        "Callback2",
        "The second callback that will be called and set a boolean true to make"
        " sure it was actually called",
        "DaLibrary:Callback",
        false    
    );
    l_callbacks[1] = GetValueFromTestParameter(l_setToTrue2);

    CleanupTFTestParameter(l_setToTrue2);
    CleanupTemplate(l_setToTrueTemplate);


    ReferenceTFTemplate(l_boolTemplate, "DaLibrary:Fundamental:Boolean:Any");
    DefineTFTestParameterWithTemplate(l_bool0Param, l_boolTemplate,
        "Boolean",
        "The boolean that will be set to true",
        "DaLibrary:Boolean",
        false
    );

    Boolean* l_bool0 = GetValueFromTestParameter(l_bool0Param);

    CleanupTFTestParameter(l_bool0Param);

    DefineTFTestParameterWithTemplate(l_bool1Param, l_boolTemplate,
        "Boolean",
        "The boolean that will be set to true",
        "DaLibrary:Boolean",
        false
    );

    Boolean* l_bool1 = GetValueFromTestParameter(l_bool1Param);

    CleanupTFTestParameter(l_bool1Param);
    CleanupTemplate(l_boolTemplate);


    l_callbacks[0]->State = l_bool0;
    l_callbacks[1]->State = l_bool1;

    l_callback->State = l_callbacks;

    l_callback->Function(l_callback);

    TFCheck(*l_bool0 == TRUE, "This must be true");
    TFCheck(*l_bool1 == TRUE, "This must be true");

}

TFModule
{

    RegisterTFModule();

    RegisterTFTest(
        "DaLibrary:Callback:General",
        "Tests to see if the test parameter it was given is a valid callback",
        CallbackGeneral
    );
    RegisterTFTest(
        "DaLibrary:Callback:Null",
        "Tests to see if the test parameter it was given is a valid callback "
        "that does nothing, in other words if it is the null callback",
        CallbackNull
    );
    RegisterTFTest(
        "DaLibrary:Callback:SetToMax",
        "Tests to see if the test parameter it was given is a valid callback "
        "that assumes its state is a DaLibrary Size and sets the state to "
        "SIZE_MAXIMUM",
        CallbackSetToMax
    );
    RegisterTFTest(
        "DaLibrary:Callback:SetToMin",
        "Tests to see if the test parameter it was given is a valid callback "
        "that assumes its state is a DaLibrary Size and setsthe state to "
        "SIZE_MINIMUM",
        CallbackSetToMin
    );
    RegisterTFTest(
        "DaLibrary:Callback:SetToTrue",
        "Tests to see if the test parameter it was given is a valid callback "
        "that assumes its state is a DaLibrary Boolean and sets the state to "
        "TRUE",
        CallbackSetToTrue
    );
    RegisterTFTest(
        "DaLibrary:Callback:SetToFalse",
        "Tests to see if the test parameter it was given is a valid callback "
        "that assumes its state is a DaLibrary Boolean and sets the state to "
        "FALSE",
        CallbackSetToFalse
    );
    RegisterTFTest(
        "DaLibrary:Callback:Move",
        "Tests to see if the test parameter it was given is a valid callback "
        "that assumes its state is an array of 2 DaLibrary Callback pointers "
        "and that it moves the 0 index Callback into the 1 index Callback",
        CallbackMove
    );
    RegisterTFTest(
        "DaLibrary:Callback:Fork",
        "Tests to see if the test parameter it was given is a valid callback "
        "that assumes its state is an array of 2 DaLibrary Callback pointers "
        "and that it calls the 0 index Callback and then the 1 index Callback",
        CallbackFork
    );

    RegisterTFTemplate(
        "DaLibrary:Callback:Any",
        "Generates any valid callback",
        AnyCallbackTemplate
    );
    RegisterTFTemplate(
        "DaLibrary:Callback:Null",
        "Generates a null callback, a callback that does nothing",
        NullCallbackTemplate
    );
    RegisterTFTemplate(
        "DaLibrary:Callback:SetToMax",
        "Generates a callback that assumes its state is a pointer to a "
        "DaLibrary Size that needs to be set to SIZE_MAXIMUM",
        SetToMaxCallbackTemplate
    );
    RegisterTFTemplate(
        "DaLibrary:Callback:SetToMin",
        "Generates a callback that assumes its state is a pointer to a "
        "DaLibrary Size that needs to be set to SIZE_MINIMUM",
        SetToMinCallbackTemplate
    );
    RegisterTFTemplate(
        "DaLibrary:Callback:SetToTrue",
        "Generates a callback that assumes its state is a pointer to a "
        "DaLibrary Boolean that needs to be set to TRUE",
        SetToTrueCallbackTemplate
    );
    RegisterTFTemplate(
        "DaLibrary:Callback:SetToFalse",
        "Generates a callback that assumes its state is a pointer to a "
        "DaLibrary Boolean that needs to be set to FALSE",
        SetToFalseCallbackTemplate
    );
    RegisterTFTemplate(
        "DaLibrary:Callback:Move",
        "Generates a callback that assumes its state is an array of 2 callback "
        "pointers that need to be moved, where the callback on the 0th index is"
        " moved into the callback on the 1st index",
        MoveCallbackTemplate
    );
    RegisterTFTemplate(
        "DaLibrary:Callback:Fork",
        "Generates a callback that assumes its state is an array of 2 callback "
        "pointers that need to be called, first the callback on the 0th index "
        "then the callback on the 1st index",
        ForkCallbackTemplate
    );

}
