#include "Array/ArrayGeneric.h"
#include "Array/ArrayGenericDebug.h"
#include "Fundamental/SizeConstants.h"

const struct Array NULL_ARRAY = { 0 };

void CreateToArrayAsNull(struct Array* restrict p_array)
{
    p_array->Location = NULL;
    p_array->Size = SIZE_MINIMUM;
}


Size FindSizeAsLastIndexFromArray(struct Array p_array)
{
    
    ValidateArray(p_array);


    if(ArrayIsNull(p_array))
    {
        return 0;
    }

    return p_array.Size - 1;

}


Boolean ArrayIsNull(struct Array p_array)
{
    ValidateArray(p_array);
    return p_array.Location == NULL || p_array.Size == SIZE_MINIMUM;
}
