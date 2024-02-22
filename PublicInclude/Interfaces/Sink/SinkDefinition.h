#ifndef SINK__INTERFACES_SINK_SINK_DEFINITION_H
#define SINK__INTERFACES_SINK_SINK_DEFINITION_H

#include "Interfaces/Indexable/IndexableDefinition.h"
#include "Interfaces/ObjectManager/ObjectManagerDefinition.h"
#include "Interfaces/IntegerManager/IntegerManagerDefinition.h"
#include "Interfaces/Callback/CallbackDefinition.h"
#include "Fundamental/SizeDefinition.h"
#include "IntegerRange/IntegerRangeDefinition.h"

struct Sink;

typedef void (*SinkWriteFunction) (
    struct Indexable* p_indexable, struct Sink* p_sink,
    Integer* p_written, struct ObjectManager* p_objManager,
    struct IntegerRange* p_range, struct IntegerManager* p_intManager,
    struct Callback* p_full
);

struct Sink
{

    void* State;

    SinkWriteFunction
        WriteUsingIndexableUsingSinkToIntegerAsWrittenUsingObjectManagerUsingIntegerRangeUsingIntegerManagerCallbackOnFull;

};

#endif //SINK__INTERFACES_SINK_SINK_DEFINITION_H