#ifndef INTEGER_RANGE__INTEGER_RANGE_INTEGER_RANGE_FUNCTIONS_H
#define INTEGER_RANGE__INTEGER_RANGE_INTEGER_RANGE_FUNCTIONS_H

#include "Fundamental/BooleanDefinition.h"
#include "IntegerRangeDefinition.h"

void
CreateUsingIntegerRangeUsingIntegerAsLowerUsingIntegerAsLengthUsingIntegerManager(
    struct IntegerRange* p_range, Integer* p_lower, Integer* p_length,
    struct IntegerManager* p_manager
);
void
CreateUsingIntegerRangeUsingIntegerAsHigherUsingIntegerAsLengthUsingIntegerManager(
    struct IntegerRange* p_range, Integer* p_higher, Integer* p_length,
    struct IntegerManager* p_manager
);
void
CreateUsingIntegerRangeAsUnionUsingIntegerRangeUsingIntegerRangeUsingIntegerManager(
    struct IntegerRange* p_range, struct IntegerRange* p_range1,
    struct IntegerRange* p_range2, struct IntegerManager* p_manager
);
void
CreateUsingIntegerRangeAsIntersectionUsingIntegerRangeUsingIntegerRangeUsingIntegerManager(
    struct IntegerRange* p_range, struct IntegerRange* p_range1,
    struct IntegerRange* p_range2, struct IntegerManager* p_manager
);


Boolean IntegerRangeIsContainedInIntegerRange(
    struct IntegerRange p_left, struct IntegerRange p_right
);


Integer FindIntegerAsLengthFromIntegerRangeUsingIntegerManager(
    struct IntegerRange p_range, struct IntegerManager* p_manager
);

#endif //INTEGER_RANGE__INTEGER_RANGE_INTEGER_RANGE_FUNCTIONS_H