#include "Interfaces/DataSink/DataSink.h"

void WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFull_ELABORATION_GOES_HERE(
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSink* p_sink, Size* p_written, struct Callback* p_full
)
{

    DaLibrary_Assume(p_objects != NULL);
    DaLibrary_Assume(p_range != NULL);
    DaLibrary_Assume(p_sink != NULL);
    DaLibrary_Assume(p_written != NULL);
    DaLibrary_Assume(p_full != NULL);

    ValidateObjects(p_objects);
    ValidateIndexRange(*p_range);
    ValidateCallback(*p_full);
    //TODO: Implementation specific checks of p_sink


    *p_written = 0;
    if(
        IndexableOfBytesHasNoItems(&p_objects->Indexable)
        ||
        !IndexRangeIsContainedInIndexableOfObjects(
            p_range, &p_objects->Indexable
        )
    )
    {
        return;
    }

    //TODO: How the data sink works internally

}

struct DataSink g_ELABORATION_GOES_HERESink = {
    NULL, //TODO: Proper state pointer or no global
    &WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFull_ELABORATION_GOES_HERE
};
