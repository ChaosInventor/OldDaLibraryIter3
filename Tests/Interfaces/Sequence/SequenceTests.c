#include <TF.h>
#include <TFMacroMagic.h>
#include "Interfaces/Sequence/Sequence.h"
#include "Fundamental/Fundamental.h"

TFTest(SequenceForm)
{

    DefineVariableFromTFTestParameterDirectly(
        struct Sequence*, l_param, "Sequence",
        "The parameter that will be checked for being a sequence pointer",
        "DaLibrary:Sequence", false
    );

    Boolean l_wellFormed = TRUE;

    l_wellFormed = l_wellFormed && TFIsValidMemoryRegion(
        l_param, sizeof(struct Sequence), true, true, false, NULL
    );

    l_wellFormed = l_wellFormed && !TFIsValidFunctionPointer(
        l_param->ReadArrayAsNextUsingSequenceCallbackOnEnd,
        "Sequence must have a read next function. A sequence without one is"
        " invalid."
    )
    TFValidFunctionPointer(
        l_param->ReadArrayAsCurrentUsingSequenceCallbackOnEnd,
        "Sequence must have a read current function. A sequence without one is "
        "invalid."
    );

    //TODO: Does the sequence have other function pointers?

}

TFTest(NullSequence)
{

    DefineTFTestParameterWithTemplateDirectly(
        l_param, "DaLibrary:Sequence:WellFormed", "Sequence",
        "This parameter will be tested for being a null sequence",
        "DaLibray:Sequence", false
    );

    struct Sequence* l_sequence = GetValueFromTestParameter(l_param);

    CleanupTFTestParameter(l_param);


    struct Array l_resultNext = l_sequence->ReadArrayAsNextUsingSequenceCallbackOnEnd(l_sequence);

    DefineTFMeasurement(
        l_sequenceReadNextMeas,
        "Sequence read next returns null",
        "This measurement is true if the read next function returned a null array"
    );
    PassValueToTFMeasurement(ArrayIsNull(l_resultNext), l_sequenceReadNextMeas);

    struct Array l_resultPrevious = l_sequence->ReadArrayAsPreviousUsingSequenceCallbackOnEnd(l_sequence);

    DefineTFMeasurement(
        l_sequenceReadPreviousMeas,
        "Sequence read previous returns null",
        "This measurement is true if the read previous function returned a null array"
    );
    PassValueToTFMeasurement(ArrayIsNull(l_resultNext), l_sequenceReadPreviousMeas);

}

TFModule
{

    RegisterTFModule();

    RegisterTFTest(
        "DaLibrary:Sequence:Form",
        "Checks if a given pointer can be used as a sequence pointer",
        SequenceForm
    );

}