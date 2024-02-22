#ifndef DEBUG__DEBUG_DEBUG_H
#define DEBUG__DEBUG_DEBUG_H

//TODO: If possible add a way for a function pointer to be printed. Everywhere this feature is required is marked by %%FUNCTION_POINTER

#ifdef DA_LIBRARY_DEBUG

#define IfDaLibraryDebugDo(p_expression) p_expression

#include <stdio.h>
#include <stdlib.h>

#else

    #define IfDaLibraryDebugDo(p_expression)

#endif //DA_LIBRARY_DEBUG

#ifndef DaLibrary_DebugFD
#define DaLibrary_DebugFD 2
#endif //DaLibrary_DebugFD

#define DaLibrary_DebugPrint(p_string, ...)\
    IfDaLibraryDebugDo(                                     \
        dprintf(DaLibrary_DebugFD, p_string, __VA_ARGS__);  \
    );

#define DaLibrary_DebugPrintMessage(p_title, p_msg, ...)\
    do                                                                          \
    {                                                                           \
        DaLibrary_DebugPrint("[%s(%s:%d)]: ", (p_title), __FILE__, __LINE__);   \
        DaLibrary_DebugPrint(p_msg, __VA_ARGS__);                               \
        DaLibrary_DebugPrint("%s", "\n");                                       \
    } while(0);


#ifndef DaLibrary_OnWarn
#define DaLibrary_OnWarn(p_msg, ...) 
#endif //DaLibrary_OnWarn

#define DaLibrary_Warn(p_msg, ...)\
    do                                                              \
    {                                                               \
        DaLibrary_DebugPrintMessage("Warning", p_msg, __VA_ARGS__); \
        DaLibrary_OnWarn(p_msg, __VA_ARGS__);                       \
    } while(0);


#ifndef DaLibrary_OnError
#define DaLibrary_OnError(p_msg, ...) DaLibrary_DebugPrint("Aborting...\n"); abort();
#endif //DaLibrary_OnError

#define DaLibrary_Error(p_msg, ...)\
    do                                                              \
    {                                                               \
        DaLibrary_DebugPrintMessage("Error", p_msg, __VA_ARGS__);   \
        DaLibrary_OnError(p_msg, __VA_ARGS__);                      \
    } while(0);

#ifndef DaLibrary_OnFailedCheck
#define DaLibrary_OnFailedCheck(p_statement, p_msg, ...)\
    DaLibrary_Warn(                                                     \
        "Failed check [ " #p_statement " ] with message:\n\t" p_msg,    \
        __VA_ARGS__                                                     \
    );
#endif //DaLibrary_OnFailedCheck

#ifndef DaLibrary_OnPassedCheck
#define DaLibrary_OnPassedCheck(p_statement, p_msg, ...)
#endif //DaLibrary_OnPassedCheck

#define DaLibrary_Check(p_statement, p_msg, ...)\
    if((p_statement))                                               \
    {                                                               \
        DaLibrary_OnPassedCheck(p_statement, p_msg, __VA_ARGS__);   \
    }                                                               \
    else                                                            \
    {                                                               \
        DaLibrary_OnFailedCheck(p_statement, p_msg, __VA_ARGS__);   \
    }


#ifndef DaLibrary_OnFailedAssert
#define DaLibrary_OnFailedAssert(p_statement, p_msg, ...)\
    DaLibrary_Warn(                                                         \
        "Failed assertion [ " #p_statement " ] with message:\n\t" p_msg,    \
        __VA_ARGS__                                                         \
    );
#endif //DaLibrary_OnFailedAssert

#ifndef DaLibrary_OnPassedAssert
#define DaLibrary_OnPassedAssert(p_statement, p_msg, ...)
#endif //DaLibrary_OnPassedAssert

#define DaLibrary_Assert(p_statement, p_msg, ...)\
    if((p_statement))                                               \
    {                                                               \
        DaLibrary_OnPassedAssert(p_statement, p_msg, __VA_ARGS__);  \
    }                                                               \
    else                                                            \
    {                                                               \
        DaLibrary_OnFailedAssert(p_statement, p_msg, __VA_ARGS__);  \
    }


#define DaLibrary_Assume(p_statement, p_format, ...)\
    do                                                                          \
    {                                                                           \
        DaLibrary_Assert(                                                       \
            (p_statement), "This function assumes that this is true, if it is " \
            "false(like now) then it's behaviour is undefined. Extra "          \
            "information:\n", (p_format), __VA_ARGS__                           \
        );                                                                      \
    } while(0);


//TODO: These 2 are really useful but very hacky
inline _Bool ValidPointer(void* p_pointer)
{
    DaLibrary_DebugPrintMessage("Not implemented", "Cannot check the validity of pointer %p because valid pointer checking not implemented yet.", p_pointer); //TODO: Proper implementation
    return 1;
}

#define DaLibrary_AssumeValidPointer(p_pointer)\
    DaLibrary_Assume(ValidPointer(p_pointer), "%p", p_pointer);

inline _Bool ValidFunctionPointerDirect(void (*p_pointer) (void))
{
    DaLibrary_DebugPrintMessage("Not implemented", "Cannot check the validity of function pointer %%FUNCTION_POINTER because valid function pointer check is not implemented yet.", p_pointer); //TODO: Proper implementation
    char* l_bytes = (char*)p_pointer;
    DaLibrary_DebugPrint("%s", l_bytes);
    return 1;
}

#define ValidFunctionPointer(p_pointer) ValidFunctionPointerDirect((void (*) (void))p_pointer)

#endif //DEBUG__DEBUG_DEBUG_H