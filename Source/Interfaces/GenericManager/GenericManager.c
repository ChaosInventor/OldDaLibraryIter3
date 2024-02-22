#include "Interfaces/GenericManager/GenericManager.h"


void
ComputeToGenericAsOffsetLocationFromGenericPointerAsLocationFromSizeAsPositiveOffsetUsingGenericManager(
    Generic* p_output, Generic* p_start, Size p_offset,
    struct GenericManager* p_manager
)
{

    ValidateGenericManagerPointer(p_manager);


    p_manager->ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsPositiveOffsetsUsingGenericManager(
        (struct Array) { .Location = p_output, .Size = 1 },
        (struct Array) { .Location = p_start, .Size = 1 },
        (struct Array) { .Location = &p_offset, .Size = 1 }, p_manager
    );

}
void
ComputeToGenericAsOffsetLocationFromGenericPointerAsLocationFromSizeAsNegativeOffsetUsingGenericManager(
    Generic* p_output, Generic* p_start, Size p_offset,
    struct GenericManager* p_manager
)
{

    ValidateGenericManagerPointer(p_manager);


    p_manager->ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsNegativeOffsetsUsingGenericManager(
        (struct Array) { .Location = p_output, .Size = 1 },
        (struct Array) { .Location = p_start, .Size = 1 },
        (struct Array) { .Location = &p_offset, .Size = 1 }, p_manager
    );

}


void MoveUsingGenericToGenericUsingGenericManager(
    Generic* p_from, Generic* p_to, struct GenericManager* p_manager
)
{

    ValidateGenericManagerPointer(p_manager);


    p_manager->MoveFromArrayFromArrayUsingGenericManager(
        (struct Array) { .Location = p_from, .Size = 1},
        (struct Array) { .Location = p_to, .Size = 1 }, p_manager
    );

}
void SwapUsingGenericToGenericUsingGenericManager(
    Generic* p_from, Generic* p_to, struct GenericManager* p_manager
)
{

    ValidateGenericManagerPointer(p_manager);


    p_manager->SwapFromArrayFromArrayUsingGenericManager(
        (struct Array) { .Location = p_from, .Size = 1},
        (struct Array) { .Location = p_to, .Size = 1 }, p_manager
    );

}
