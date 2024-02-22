#include "Interfaces/DataSink/DataSink.h"

void WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFull_Null(
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSink* p_sink, Size* p_written, struct Callback* p_full
)
{

    DaLibrary_Assume(p_written != NULL);
    DaLibrary_Assume(p_range != NULL);

    ValidateIndexRange(*p_range)

    (void)p_objects;
    (void)p_sink;
    (void)p_full;


    *p_written = FindSizeAsLengthFromIndexRange(p_range);

}

void WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFull_Full(
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSink* p_sink, Size* p_written, struct Callback* p_full
)
{

    DaLibrary_Assume(p_full != NULL);

    ValidateCallback(*p_full);

    (void)p_objects;
    (void)p_range;
    (void)p_sink;
    (void)p_written;


    Callback(p_full);

}


struct DataSink g_NullDataSink = {
    NULL,
    &WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFull_Null
};
struct DataSink g_FullDataSink = {
    NULL,
    &WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFull_Full
};
