#include "Interfaces/DataSource/DataSource.h"

void WriteUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnFull_Null(
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSource* p_source, Size* p_red, struct Callback* p_empty
)
{

    DaLibrary_Assume(p_red != NULL);
    DaLibrary_Assume(p_range != NULL);

    ValidateIndexRange(*p_range)

    (void)p_objects;
    (void)p_source;
    (void)p_empty;


    *p_red = FindSizeAsLengthFromIndexRange(p_range);

}

void WriteUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnFull_Full(
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSource* p_source, Size* p_red, struct Callback* p_empty
)
{

    DaLibrary_Assume(p_empty != NULL);
    
    ValidateCallback(*p_empty);

    (void)p_objects;
    (void)p_range;
    (void)p_source;
    (void)p_red;


    Callback(p_empty);

}


struct DataSource g_NullDataSource = {
    NULL,
    &WriteUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnFull_Null
};
struct DataSource g_FullDataSource = {
    NULL,
    &WriteUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnFull_Full
};
