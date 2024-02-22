#ifndef DATA_SOURCE__INTERFACES_DATA_SOURCE_DATA_SOURCE_H
#define DATA_SOURCE__INTERFACES_DATA_SOURCE_DATA_SOURCE_H

#include "Fundamental/Fundamental.h"
#include "IndexRange/IndexRange.h"
#include "Interfaces/Callback/Callback.h"
#include "Interfaces/ObjectManagerMask/ObjectManagerMask.h"
#include "Debug/Debug.h"

#define ValidateDataSource(p_source)\
    DaLibrary_Assert(                                                                                     \
        (p_source).ReadUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnFailure  \
        !=                                                                                      \
        nullptr, "DataSource must not have it's function be null."                              \
    );


struct DataSource;

typedef void (*DataSourceReadFunction) (
    struct Objects* p_objects, const struct IndexRange* p_range,
    struct DataSource* p_source, Size* p_red, struct Callback* p_empty
);

extern struct DataSource g_NullDataSource;
extern struct DataSource g_FullDataSource;


struct DataSource
{
    void* State;
    
    DataSourceReadFunction
        ReadUsingObjectsFromIndexRangeUsingDataSourceToSizeAsRedCallbackOnEmpty;
};

#endif //DATA_SOURCE__INTERFACES_DATA_SOURCE_DATA_SOURCE_H