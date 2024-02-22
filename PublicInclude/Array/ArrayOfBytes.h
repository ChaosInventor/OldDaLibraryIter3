#ifndef ARRAY__ARRAY_ARRAY_OF_BYTES_H
#define ARRAY__ARRAY_ARRAY_OF_BYTES_H

#include "Fundamental/SizeDefinition.h"
#include "Fundamental/ByteDefinition.h"
#include "ArrayGenericDefinition.h"

struct ArrayOfBytes
{

    Byte* Location;
    Size Size;

};

struct ArrayOfBytes CreateArrayOfBytesFromArray(struct Array p_array);
struct Array CreateArrayFromArrayOfBytes(struct ArrayOfBytes p_array);

#endif //ARRAY__ARRAY_ARRAY_OF_BYTES_H