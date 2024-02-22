#include "TF.h"
#include "TFMacroMagic.h"

#include "Fundamental/Boolean.h"
#include "Interfaces/MemoryManager/MemoryManager.h"
#include "Memory/Memory.h"

//TODO: Entire class of functions/marcos. They all start with "TFInform" and end with the type name that they print.
#define TFInformMemory(p_memory) //TODO: Define, makes more sense to have this in the memory tests file but it won't be usable that way. Candidate for new TF object?
#define TFInformBoolean(p_bool) //TODO: Define
#define TFMeasurement(p_name, p_description, p_value)

TFTemplate(AnyMemoryManager)
{

    ReferenceTFTest(structValidator, "DaLibrary:MemoryManager:ValidStruct");
    UseTFTestToValidateTemplate(structValidator);

}

TFTemplate(ValidMemoryManager)
{

    //TODO: Use all tests to make sure that the test parameter is a valid memory manager that works as expected

    UseTFTestToValidateTemplateDirectly("DaLibrary:MemoryManager:ValidStruct");

}

TFTest(MemoryManagerFollowsStrictness)
{
    
    DefineVariableFromTFTemplate(
        struct Memory, l_original, "DaLibrary:Memory:Valid",
        "Original memory",
        "The original memory that was requested to a memory manager",
        "DaLibrary:Memory/Original", false
    );
    DefineVariableFromTFTemplate(
        struct Memory, l_current, "DaLibrary:Memory:Valid",
        "Current memory",
        "The memory that was produced by a memory manager",
        "DaLibrary:Memory/Current", false
    );
    DefineVariableFromTFTemplate(
        struct MemoryManagerStrictness, l_strictness,
        "DaLibrary:MemoryManagerStrictness:Valid",
        "Strictness",
        "The strictness that was used to operate on the memory",
        "DaLibrary:MemoryManagerStrictness", false
    );

    if(l_current.Location != l_original.Location)
    {
        TFInformMemory(l_current);
        TFInformMemory(l_original);
        TFInformBoolean(l_current.Location > l_original.Location);
        TFInformBoolean(l_strictness.LocationGreater);
        TFInformBoolean(l_current.Location < l_original.Location);
        TFInformBoolean(l_strictness.LocationLesser);
        TFCheck(
            (l_current.Location > l_original.Location && l_strictness.LocationGreater)
            ||
            (l_current.Location < l_original.Location && l_strictness.LocationLesser),
            "A memory manager may only modify the location of memory if it "
            "strictness allows it. Furthermore the location may only be "
            "modified in a certian direction, either to a lower address or a "
            "higher address"
        );

        bool l_followsLocationStrictness = 
            (l_current.Location > l_original.Location && l_strictness.LocationGreater)
            ||
            (l_current.Location < l_original.Location && l_strictness.LocationLesser)
            ||
            (l_current.Location == l_original.Location);
        TFMeasurement(
            "LocationStrictnessFollowed",
            "Measures whether the memory manager followed the location "
            "strictness. A memory manager may only modify the location of "
            "memory in the direction that the strictness allows, that is either"
            " to a higher or a lower address. The location must not be modified"
            " if the strictness does not allow it to be.",
            l_followsLocationStrictness
        );
    }
    
    if(l_current.Size != l_original.Size)
    {
        TFInformMemory(l_current);
        TFInformMemory(l_original);
        TFInformBoolean(l_current.Size > l_original.Size);
        TFInformBoolean(l_strictness.SizeGreater);
        TFInformBoolean(l_current.Size < l_original.Size);
        TFInformBoolean(l_strictness.SizeLesser);
        TFCheck(
            (l_current.Size > l_original.Size && l_strictness.SizeGreater)
            ||
            (l_current.Size < l_original.Size && l_strictness.SizeLesser),
            "A memory manager may only modify the size of memory if it "
            "strictness allows it. Furthermore the size may only be "
            "modified in a certian direction, either to a smaller size or a "
            "bigger size"
        );
    }

    if(l_current.Permissions.Readable != l_original.Permissions.Readable)
    {
        TFInformMemory(l_current);
        TFInformMemory(l_original);
        TFInformBoolean(
            l_current.Permissions.Readable > l_original.Permissions.Readable
        );
        TFInformBoolean(l_strictness.PermissionsGreater);
        TFInformBoolean(
            l_current.Permissions.Readable < l_original.Permissions.Readable
        );
        TFInformBoolean(l_strictness.PermissionsLesser);
        TFCheck(
            (
                l_current.Permissions.Readable > l_original.Permissions.Readable
                &&
                l_strictness.PermissionsGreater
            )
            ||
            (
                l_current.Permissions.Readable < l_original.Permissions.Readable
                &&
                l_strictness.PermissionsLesser
            ),
            "A memory manager may only modify the permissions of memory if the "
            "strictness allows it. Furthermore permissions may only be added to"
            " or removed from depending on what the strictness allows"
        );
    }

    if(l_current.Permissions.Writable != l_original.Permissions.Writable)
    {
        TFInformMemory(l_current);
        TFInformMemory(l_original);
        TFInformBoolean(l_current.Permissions.Writable > l_original.Permissions.Writable);
        TFInformBoolean(l_strictness.PermissionsGreater);
        TFInformBoolean(l_current.Permissions.Writable < l_original.Permissions.Writable);
        TFInformBoolean(l_strictness.PermissionsLesser);
        TFCheck(
            (
                l_current.Permissions.Writable > l_original.Permissions.Writable
                &&
                l_strictness.PermissionsGreater
            )
            ||
            (
                l_current.Permissions.Writable < l_original.Permissions.Writable
                &&
                l_strictness.PermissionsLesser
            ),
            "A memory manager may only modify the permissions of memory if the "
            "strictness allows it. Furthermore permissions may only be added to"
            " or removed from depending on what the strictness allows"
        );
    }

    if(l_current.Permissions.Executable != l_original.Permissions.Executable)
    {
        TFInformMemory(l_current);
        TFInformMemory(l_original);
        TFInformBoolean(l_current.Permissions.Executable > l_original.Permissions.Executable);
        TFInformBoolean(l_strictness.PermissionsGreater);
        TFInformBoolean(l_current.Permissions.Executable < l_original.Permissions.Executable);
        TFInformBoolean(l_strictness.PermissionsLesser);
        TFCheck(
            (
                l_current.Permissions.Executable > l_original.Permissions.Executable
                &&
                l_strictness.PermissionsGreater
            )
            ||
            (
                l_current.Permissions.Executable < l_original.Permissions.Executable
                &&
                l_strictness.PermissionsLesser
            ),
            "A memory manager may only modify the permissions of memory if the "
            "strictness allows it. Furthermore permissions may only be added to"
            " or removed from depending on what the strictness allows"
        );
    }

}

TFTest(MemoryManagerValidStruct)
{

    DefineTFTestParameter(
        l_managerParam, "Memory manager",
        "Checked to make sure that it is a pointer to a valid memory manager "
        "struct",
        "DaLibrary:MemoryManager", false
    );

    struct MemoryManager l_manager =
        *(struct MemoryManager*)GetValueFromTestParameter(l_managerParam);

    CleanupTFTestParameter(l_managerParam);

    TFValidMemoryRegion(
        &l_manager, sizeof(struct MemoryManager), true, true, false,
        "Memory manager struct does not comply with memory requirements"
    );

    TFValidFunctionPointer(
        &l_manager.AllocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictnessCallbackOnFailure,
        "All function pointers of memory manager must be valid function "
        "pointers"
    );
    TFValidFunctionPointer(
        &l_manager.ReSizeUsingMemoryAsSizeForwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure,
        "All function pointers of memory manager must be valid function "
        "pointers"
    );
    TFValidFunctionPointer(
        &l_manager.ReSizeUsingMemoryAsLocationBackwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure,
        "All function pointers of memory manager must be valid function "
        "pointers"
    );
    TFValidFunctionPointer(
        &l_manager.RePermissionUsingMemoryUsingMemoryManagerFromMemoryPermissionsFromMemoryManagerStrictnessCallbackOnFailure,
        "All function pointers of memory manager must be valid function "
        "pointers"
    );
    TFValidFunctionPointer(
        &l_manager.DeallocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictness,
        "All function pointers of memory manager must be valid function "
        "pointers"
    );
    
}

TFTest(MemoryManagerAllocate)
{

    DefineVariableFromTFTemplate(
        struct MemoryManager, l_manager, "DaLibrary:MemoryManager:Any",
        "Manager",
        "This memory manager will have its allocate function tested",
        "DaLibrary:MemoryManager", false
    );
    DefineVariableFromTFTemplate(
        struct MemoryManagerStrictness, l_strictness,
        "DaLibrary:MemoryManagerStrictness:Any",
        "Strictness",
        "The strictness that will be used on the memory manager while "
        "allocating memory",
        "DaLibrary:MemoryManagerStrictness", false
    );
    DefineVariableFromTFTemplate(
        struct Memory, l_memory, "DaLibrary:Memory:Valid", //TODO: Specifics
        "Memory",
        "The memory that this test will attempt to allocate",
        "DaLibrary:Memory", false
    );
    DefineVariableFromTFTemplate(
        struct Callback, l_callback, "DaLibrary:Callback:SetToTrue",
        "Callback",
        "This callback will be used to test to see if allocation failure is "
        "handled properly",
        "DaLibrary:Callback", false
    );

    struct Memory l_original = l_memory;
    Boolean l_called = FALSE;

    l_manager.AllocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictnessCallbackOnFailure(
        &l_memory, &l_manager, l_strictness, &l_callback
    );

    ReferenceTFTest(l_memoryValidator, "DaLibrary:Memory:Valid");
    PassValueToTFTest(&l_memory, "DaLibrary:Memory", l_memoryValidator);
    TFAssert(
        TFTestPasses(l_memoryValidator),
        "Allocation must produce a valid chunk of memory"
    );
    CleanupTFTest(l_memoryValidator);

    ReferenceTFTest(l_managerValidator, "DaLibrary:MemoryManager:ValidStruct");
    PassValueToTFTest(&l_manager, "DaLibrary:MemoryManager", l_managerValidator);
    TFAssert(
        TFTestPasses(l_managerValidator),
        "After allocation the memory manager struct must be left in a valid "
        "state"
    );
    CleanupTFTest(l_managerValidator);

    ReferenceTFTest(l_callbackValidator, "DaLibrary:Callback:General");
    PassValueToTFTest(&l_callback, "DaLibrary:Callback", l_callbackValidator);
    TFAssert(
        TFTestPasses(l_callbackValidator),
        "After allocation the callback struct must be left in a valid state"
    );
    CleanupTFTest(l_callbackValidator);

    if(l_called)
    {
        TFInformMemory(l_memory);
        TFCheck(
            MemoryIsNull(l_memory), "Failed allocation must produce null memory"
        );
    }
    else
    {
        ReferenceTFTest(
            l_strictnessValidator, "DaLibrary:MemoryManager:StrictnessFollwed"
        );
        PassValueToTFTest(
            &l_original, "DaLibrary:Memory/Original", l_strictnessValidator
        );
        PassValueToTFTest(
            &l_memory, "DaLibrary:Memory/Current", l_strictnessValidator
        );
        PassValueToTFTest(
            &l_strictness, "DaLibrary:MemoryMangerStrictness",
            l_strictnessValidator
        );
        TFCheck(
            TFTestPasses(l_strictnessValidator),
            "Allocation must follow strictness restraints."
        );
        CleanupTFTest(l_strictnessValidator);
    }

}

TFTest(MemoryManagerReSize)
{

    //TODO: This could be better defined using the measurement concept.
    DefineTFTestParameterWithTemplateDirectly(
        l_managerParam, "DaLibrary:MemoryManager:Any",
        "Manager",
        "This memory manager will have its allocate function tested",
        "DaLibrary:MemoryManager", false
    );
    UseTFTestToValidateTFTestParameterDirectly(
        l_managerParam, "DaLibrary:MemoryManager:AllocateTest"
    );
    struct MemoryManager l_manager =
        *(struct MemoryManager*)GetValueFromTestParameter(l_managerParam);

    DefineVariableFromTFTemplate(
        struct MemoryManagerStrictness, l_strictness,
        "DaLibrary:MemoryManagerStrictness:Any",
        "Strictness",
        "The strictness that will be used on the memory manager while "
        "allocating memory",
        "DaLibrary:MemoryManagerStrictness", false
    );
    DefineVariableFromTFTemplate(
        struct Memory, l_memory, "DaLibrary:Memory:Valid", //TODO: Specifics
        "Memory",
        "The memory that this test will attempt to allocate",
        "DaLibrary:Memory", false
    );
    DefineVariableFromTFTemplate(
        struct Callback, l_callback, "DaLibrary:Callback:SetToTrue",
        "Callback",
        "This callback will be used to test to see if allocation failure is "
        "handled properly",
        "DaLibrary:Callback", false
    );

    

}

TFModule
{

    RegisterTFModule();

    RegisterTFTest(
        "DaLibrary:MemoryManager:ValidStruct",
        "Makes sure that the one given test parameter is a valid memory manager"
        " struct.",
        MemoryManagerValidStruct
    );
    RegisterTFTest(
        "DaLibrary:MemoryManager:StrictnessFollwed",
        "Makes sure that a memory manager followed the strictness restraints "
        "for some memory",
        MemoryManagerFollowsStrictness
    );
    RegisterTFTest(
        "DaLibrary:MemoryManager:AllocateGeneral",
        "Makes sure that a given memory manager behaves correctly when "
        "allocating memory. Does NOT test if the memory manager can allocate "
        "memory at all. Does NOT deallocate the memory afterwords.",
        MemoryManagerAllocate
    );
    RegisterTFTest(
        "DaLibrary:MemoryManager:AllocateGeneral",
        "Makes sure that a given memory manager, that can allocate memory, "
        "behaves correctly when re sizing memory. Does NOT deallocate the "
        "memory afterwords.",
        MemoryManagerReSize
    );

    RegisterTFTemplate(
        "DaLibrary:MemoryManager:Any",
        "Used for getting any sort of memory manager that is only a valid "
        "struct. The given memory manager may or may not behave as expected.",
        AnyMemoryManager
    );
    RegisterTFTemplate(
        "DaLibrary:MemoryManager:Valid",
        "Used for getting any sort of valid memory manager. The memory manager "
        "has a well formed struct and behaves as expected.",
        ValidMemoryManager
    );

}
