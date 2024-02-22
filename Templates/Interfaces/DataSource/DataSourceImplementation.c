#include "Interfaces/DataSource/DataSource.h"

void WriteUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnFull_ELABORATION_GOES_HERE(
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSource* p_source, Size* p_red, struct Callback* p_empty
)
{

    DaLibrary_Assume(p_objects != NULL);
    DaLibrary_Assume(p_range != NULL);
    DaLibrary_Assume(p_source != NULL);
    DaLibrary_Assume(p_red != NULL);
    DaLibrary_Assume(p_empty != NULL);

    ValidateObjects(p_objects);
    ValidateIndexRange(*p_range);
    ValidateCallback(*p_empty);
    //TODO: Implementation specific checks of p_source


    *p_red = 0;
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

struct DataSource g_ELABORATION_GOES_HERESink = {
    NULL, //TODO: Proper state pointer or no global
    &WriteUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnFull_ELABORATION_GOES_HERE
};
