#ifndef DATA_SINK__INTERFACES_DATA_SINK_DATA_SINK_H
#define DATA_SINK__INTERFACES_DATA_SINK_DATA_SINK_H

#include "Fundamental/Fundamental.h"
#include "IndexRange/IndexRange.h"
#include "Interfaces/Callback/Callback.h"
#include "Interfaces/ObjectManagerMask/ObjectManagerMask.h"
#include "Debug/Debug.h"

#define ValidateDataSink(p_sink)\
    DaLibrary_Assert(                                                                                     \
        (p_sink).WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFailure \
        !=                                                                                      \
        nullptr, "DataSink must not have it's function be null."                                \
    );


struct DataSink;

typedef void (*DataSinkWriteFunction) (
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSink* p_sink, Size* p_written, struct Callback* p_full
);

extern struct DataSink g_NullDataSink;
extern struct DataSink g_FullDataSink;


struct DataSink
{
    void* State;

    DataSinkWriteFunction
        WriteUsingObjectsFromIndexRangeUsingDataSinkToSizeAsWrittenCallbackOnFull;
};

#endif //DATA_SINK__INTERFACES_DATA_SINK_DATA_SINK_H