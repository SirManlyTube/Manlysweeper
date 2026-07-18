/**
 * ===========================================================================
 *   mly_ini.h - v1.1.0 - Public Domain / zlib Config Parser
 *   STB-style single-header library for loading and parsing .ini config files.
 * 
 *   SEMANTIC VERSIONING CONTRACT:
 *   Only symbols prefixed with 'MLY_Ini' declared outside of the
 *   implementation block constitute the public API.
 * 
 *   Any symbols prefixed with 'mly__ini_' or located inside the
 *   MLY_INI_IMPLEMENTATION guard are private implementation details
 *   and MAY change breakingly in PATCH or MINOR releases.
 * ===========================================================================
 */

/**
 * ===========================================================================
 *   LICENSE (zlib):
 *   Copyright (c) 2026 ManlyTube (https://github.com/SirManlyTube)
 *
 *   This software is provided 'as-is', without any express or implied
 *   warranty. In no event will the authors be held liable for any damages
 *   arising from the use of this software.
 *
 *   Permission is granted to anyone to use this software for any purpose,
 *   including commercial applications, and to alter it and redistribute it
 *   freely, subject to the following restrictions:
 *
 *   1. The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software. If you use this software
 *      in a product, an acknowledgment in the product documentation would be
 *      appreciated but is not required.
 *   2. Altered source versions must be plainly marked as such, and must not be
 *      misrepresented as being the original software.
 *   3. This notice may not be removed or altered from any source distribution.
 * ===========================================================================
 */

/**
 * ===========================================================================
 *   I started this project because I wanted to just see if I could make a .ini parser
 *   and now I think what I have ended up with has the basis for something more than that.
 *   I want to eventually take this to being able to have expressions as part of field
 *   definitions and whatnot but for now the architecture is nowhere near suited for that
 *   and I also don't have the knowledge yet to achieve that so I am leaving it off with
 *   where it is at for now.
 * 
 *   TODO:
 *   - Refactor MLY_IniASTNode to be able to handle expressions
 *   - Improve the tokenizer to better handle edge-cases
 *   - Optimize the parsing loop to better handle edge-cases
 *   - Make better error handling
 *   - Remove redudant code
 *   - Write documentation
 * ===========================================================================
 * 
 * I would imagine there are ways to reduce the memory footprint of this library as well
 * and I just am simply not aware of what could be done.
 */

#ifndef MLY_INI_H
#define MLY_INI_H

/**
 * ===========================================================================
 * I honestly don't know how any of this platform stuff works,
 * I just copied it from SDL3 for most of it.
 * I also don't know how much of this I need so feel free to remove some or all of it.
 * ===========================================================================
 */

#ifndef MLY_PLATFORM_H
#define MLY_PLATFORM_H

#if defined(__INTEL_COMPILER)
    #define MLY_INTEL_COMPILER __INTEL_COMPILER
    #define MLY_COMPILER_NAME "Intel"
#elif defined(__INTEL_LLVM_COMPILER)
    #define MLY_INTEL_LLVM_COMPILER __INTEL_LLVM_COMPILER
    #define MLY_COMPILER_NAME "Intel LLVM"
#elif defined(_MSC_VER)
    #define MLY_MSVC _MSC_VER
    #ifdef __clang__
        #define MLY_CLANG __clang__
        #define MLY_CLANG_CL 1
        #define MLY_COMPILER_NAME "Clang CL"
    #else
        #define MLY_COMPILER_NAME "MSVC"
    #endif
#elif defined(__clang__)
    #define MLY_CLANG __clang__
    #define MLY_COMPILER_NAME "Clang"
#elif defined(__GNUC__) || defined(__GNUG__)
    #ifdef __GNUG__
        #define MLY_GXX __GNUG__
        #define MLY_COMPILER_NAME "G++"
    #elif
        #define MLY_COMPILER_NAME "GCC"
    #endif
    #define MLY_GCC __GNUC__
#else
    #define MLY_COMPILER_NAME "Unknown"
#endif

#if defined(linux) || defined(__linux) || defined(__linux__)
    #define MLY_PLATFORM_LINUX 1
#endif /* defined(linux) || defined(__linux) || defined(__linux__) */

#if defined(ANDROID) || defined(__ANDROID__)
    #define MLY_PLATFORM_ANDROID 1
    #undef MLY_PLATFORM_LINUX
#endif /* defined(ANDROID) || defined(__ANDROID__) */

#if defined(unix) || defined(__unix) || defined(__unix__)
    #define MLY_PLATFORM_UNIX 1
#endif /* defined(unix) || defined(__unix) || defined(__unix__) */

#if defined(__APPLE__)
    #define MLY_PLATFORM_APPLE 1

    #include <AvailabilityMacros.h>
    #ifndef __has_extension
        #define __has_extension(x) 0
        #include <TargetConditionals.h>
        #undef __has_extension
    #else
        #include <TargetConditionals.h>
    #endif

    #ifndef TARGET_OS_MACCATALYST
        #define TARGET_OS_MACCATALYST 0
    #endif /* !defined(TARGET_OS_MACCATALYST) */
    #ifndef TARGET_OS_IOS
        #define TARGET_OS_IOS 0
    #endif /* !defined(TARGET_OS_IOS) */
    #ifndef TARGET_OS_IPHONE
        #define TARGET_OS_IPHONE 0
    #endif /* !defined(TARGET_OS_IPHONE) */
    #ifndef TARGET_OS_TV
        #define TARGET_OS_TV 0
    #endif /* !defined(TARGET_OS_TV) */
    #ifndef TARGET_OS_SIMULATOR
        #define TARGET_OS_SIMULATOR 0
    #endif /* !defined(TARGET_OS_SIMULATOR) */
    #ifndef TARGET_OS_VISION
        #define TARGET_OS_VISION 0
    #endif /* !defined(TARGET_OS_VISION) */

    #if TARGET_OS_TV
        #define MLY_PLATFORM_TVOS 1
    #endif /* TARGET_OS_TV */

    #if TARGET_OS_VISION
        #define MLY_PLATFORM_VISIONOS 1
    #endif /* TARGET_OS_VISION */

    #if TARGET_OS_IPHONE
        #define MLY_PLATFORM_IOS 1
    #else
        #define MLY_PLATFORM_MACOS 1
    #endif /* TARGET_OS_IPHONE */
#endif /* defined(__APPLE__) */

#if defined(__CIGWIN__)
    #define MLY_PLATFORM_CYGWIN 1
#endif /* defined(__CYGWIN__) */

#if (defined(_WIN32) || defined(MLY_PLATFORM_CYGWIN)) && !defined(__NGAGE__)
    #define MLY_PLATFORM_WINDOWS 1

    #if defined(MLY_MSVC) && defined(__has_include)
        #if __has_include(<winapifamily.h>)
            #define HAS_WINAPIFAMILY_INCLUDE 1
        #else
            #define HAS_WINAPIFAMILY_INCLUDE 0
        #endif
    #elif defined(MLY_MSVC) && (MLY_MSVC >= 1700 && !_USING_V110_SDK71_)
        #define HAS_WINAPIFAMILY_INCLUDE 1
    #else
        #define HAS_WINAPIFAMILY_INCLUDE 0
    #endif /* defined(MLY_MSVC) */

    #if HAS_WINAPIFAMILY_INCLUDE
        #include <winapifamily.h>
        #define WINAPI_FAMILY_WINRT (!WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP))
    #else
        #define WINAPI_FAMILY_WINRT 0
    #endif /* HAS_WINAPIFAMILY_INCLUDE */

    #if defined(HAS_WINAPIFAMILY_INCLUDE) && HAS_WINAPIFAMILY_INCLUDE
        #define MLY_WINAPI_FAMILY_PHONE (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
    #else
        #define MLY_WINAPI_FAMILY_PHONE 0
    #endif /* defined(HAS_WINAPIFAMILY_INCLUDE) */

    #if WINAPI_FAMILY_WINRT
        #error "Windows RT/UWP is not supported."
    #elif defined(_GAMING_DESKTOP)
        #define MLY_PLATFORM_WINGDK 1
    #elif defined(_GAMING_XBOX_XBOXONE)
        #define MLY_PLATFORM_XBOXONE 1
    #elif defined(_GAMING_XBOX_SCARLETT)
        #define MLY_PLATFORM_XBOXSERIES 1
    #else
        #define MLY_PLATFORM_WIN32 1
    #endif /* WINAPI_FAMILY_WINRT */
#endif /* defined(_WIN32) || defined(MLY_PLATFORM_CYGWIN) */

#if defined(MLY_PLATFORM_WINGDK) || defined(MLY_PLATFORM_XBOXONE) || defined(MLY_PLATFORM_XBOXSERIES)
    #define MLY_PLATFORM_GDK 1
#endif /* defined(MLY_PLATFORM_WINGDK) || defined(MLY_PLATFORM_XBOXONE) || defined(MLY_PLATFORM_XBOXSERIES) */

#if defined(_M_X64) || defined(_M_AMD64) || defined(__x86_64__) || defined(__amd64__) || defined(__amd64)
    #define MLY_ARCH_X86_64 1
#elif defined(_M_IX86) || defined(__i386__) || defined (__i386)
    #define MLY_ARCH_X86 1
#elif defined(__aarch64__) || defined(_M_ARM64)
    #define MLY_ARCH_ARM64 1
#elif defined(__arm__) || defined(_M_ARM)
    #define MLY_ARCH_ARM32 1
#else
    #define MLY_ARCH_UNKNOWN 1
#endif

#if defined(MLY_ARCH_X86_64) || defined(MLY_ARCH_ARM64)
    #define MLY_X64 1
#endif /* defined(MLY_ARCH_X86_64) || defined(MLY_ARCH_ARM64) */

#if defined(MLY_ARCH_X86_64) || defined(MLY_ARCH_ARM64)
    #if (defined(MLY_PLATFORM_WINDOWS) && !defined(MLY_PLATFORM_CYGWIN)) || defined(MLY_MSVC)
        #define MLY_LLP64 1
    #else
        #define MLY_LP64 1
    #endif
#else
    #define MLY_ILP32 1
#endif

#endif /* MLY_PLATFORM_H */

typedef   signed char           mly_int8_t;
typedef unsigned char           mly_uint8_t;
typedef   signed short          mly_int16_t;
typedef unsigned short          mly_uint16_t;
typedef   signed int            mly_int32_t;
typedef unsigned int            mly_uint32_t;

#ifdef MLY_LLP64
    typedef   signed long long  mly_int64_t;
    typedef unsigned long long  mly_uint64_t;
#else
    typedef   signed long       mly_int64_t;
    typedef unsigned long       mly_uint64_t;
#endif

#ifdef MLY_X64
    typedef mly_int64_t         mly_ssize_t;
    typedef mly_uint64_t        mly_size_t;
#else
    typedef mly_int32_t         mly_ssize_t;
    typedef mly_uint32_t        mly_size_t;
#endif

typedef mly_uint32_t            mly_version_t;
typedef mly_uint64_t            mly_long_version_t;

#ifdef __cplusplus
    typedef bool                mly_bool_t;
#else
    typedef mly_uint8_t         mly_bool_t;
    #ifndef true
        #define true 1
    #endif
    #ifndef false
        #define false 0
    #endif
#endif

typedef enum MLY_IniFieldType
{
    MLY_INI_TYPE_INT,
    MLY_INI_TYPE_DOUBLE,
    MLY_INI_TYPE_VERSION,
    MLY_INI_TYPE_VERSION_LONG,
    MLY_INI_TYPE_BOOL,
    MLY_INI_TYPE_STRING,
} MLY_IniFieldType;

typedef mly_uint8_t MLY_IniFileFlags;

enum
{
    MLY_INI_FILE_FLAGS_DEFAULT = 0x01,              /* MLY_INI_FILE_FLAGS_READ | MLY_INI_FILE_FLAGS_CREATE_IF_MISSING */

    MLY_INI_FILE_FLAGS_READ = 0x02,                 /* Reads from an existing file. */
    MLY_INI_FILE_FLAGS_CREATE_IF_MISSING = 0x04,    /* Creates a new file if the one attempting to be read doesn't exist. */

    MLY_INI_FILE_FLAGS_EMPTY = 0x08,                /* Creates a new empty file. */
};

typedef struct MLY_IniFile MLY_IniFile;
typedef struct MLY_IniSection MLY_IniSection;
typedef struct MLY_IniField MLY_IniField;
typedef struct MLY_IniSectionList MLY_IniSectionList;
typedef struct MLY_IniFieldList MLY_IniFieldList;

#ifndef MLYAPI
    #ifdef MLYAPI_STATIC
        #define MLYAPI static
    #else
        #define MLYAPI extern
    #endif /* MLY_INI_STATIC */
#endif /* MLY_INI_API */

#ifndef MLYCALL
    #if defined(MLY_PLATFORM_WINDOWS) && !defined(__GNUC__)
        #define MLYCALL __cdecl
    #else
        #define MLYCALL
    #endif /* defined(_WIN32) */
#endif /* MLYCALL */

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @brief Retrieves the last reported error.
     *
     * @return The current error message.
     */
    MLYAPI const char* MLYCALL MLY_IniError(void);

    /**
     * @brief Opens an ini file at the given path using the provided file mode.
     * * Should be closed using MLY_IniCloseFile() when done.
     * * An IniFile's sections and fields can be changed and saved with MLY_IniCommitFile().
     * * You can see if this function created a file with the given name using MLY_IniCreatedFileOnOpen().
     * 
     * @param pFilename The path and name of the file to open.
     * @param flags The flags to initialize the IniFile with. Defaults to MLY_INI_FILE_FLAGS_READ | MLY_INI_FILE_FLAGS_CREATE_IF_MISSING
     * * if MLY_INI_FILE_FLAGS_DEFAULT or 0.
     * 
     * @return MLY_IniFile* Handle to the IniFile opened which acts as the highest level module.
     * 
     * Valid file modes:
     * - MLY_INI_FILE_FLAGS_DEFAULT
     * - MLY_INI_FILE_FLAGS_READ
     * - MLY_INI_FILE_FLAGS_CREATE_IF_MISSING
     * - MLY_INI_FILE_FLAGS_CREATE_NEW
     * 
     * File flags can be OR'd together.
     */
    MLYAPI MLY_IniFile* MLYCALL MLY_IniOpenFile(const char* pFilename, MLY_IniFileFlags flags);

    /**
     * @brief Retrieves a global field from the given IniFile matching the given name.
     * 
     * @param pIniFile The IniFile to retrieve the field from.
     * @param pName The name of the requested field.
     * 
     * @return MLY_IniField* Pointer to the field retrieved or NULL on failure.
     */
    MLYAPI MLY_IniField* MLYCALL MLY_IniFileGetGlobal(MLY_IniFile* pIniFile, const char* pName);
    MLYAPI mly_bool_t MLYCALL MLY_IniFileAddSection(MLY_IniFile* pIniFile, MLY_IniSection* pSection);
    MLYAPI MLY_IniSection* MLYCALL MLY_IniFileGetSection(MLY_IniFile* pIniFile, const char* pName, bool createIfMissing);

    /**
     * @brief Saves changes made to the MLY_IniFile to the associated file.
     * 
     * @param pIniFile The file to commit.
     * 
     * @return bool true on success, false on failure
     * 
     * Example Usage:
     * @code
     *  MLY_IniFile* iniFile = MLY_IniOpenFile("foo.ini", MLY_INI_FILE_WRITE);
     *  MLY_IniSection* bar = MLY_IniFileGetSection(iniFile, "bar");
     *  MLY_IniField* foobar = MLY_IniSectionGetField(bar, "foobar");
     * 
     *  MLY_IniFieldSetInt(foobar, 80085);
     * 
     *  MLY_IniCommitFile(iniFile);
     * @endcode
     */
    MLYAPI mly_bool_t MLYCALL MLY_IniCommitFile(const MLY_IniFile* pIniFile);

    /**
     * @brief Closes an IniFile previously opened with MLY_IniOpenFile().
     */
    MLYAPI void MLYCALL MLY_IniCloseFile(MLY_IniFile* pIniFile);

    /**
     * @brief Creates a dynamic array to hold field data. Use mly__ini_destroy_field_list()
     * * when you are done to clean up its resources.
     *
     * @note Intended for internal use and typically should not be needed externally.
     *
     * @return A dynamic array of fields.
     */
    MLYAPI MLY_IniFieldList* MLYCALL MLY_IniCreateFieldList(void);

    /**
     * @brief Clean deallocator for field lists. Call this function when you are done using
     * * a field list to properly clean up its resources.
     *
     * @note Typically should not be needed externally.
     *
     * @param pFieldList Pointer to the field list to destroy.
     */
    MLYAPI void                 MLYCALL MLY_IniDestroyFieldList(MLY_IniFieldList* pFieldList);

    MLYAPI MLY_IniSectionList*  MLYCALL MLY_IniCreateSectionList(void);
    MLYAPI void                 MLYCALL MLY_IniDestroySectionList(MLY_IniSectionList* pSectionList);

    MLYAPI MLY_IniSection*      MLYCALL MLY_IniCreateSection(const char* pName);
    MLYAPI mly_bool_t           MLYCALL MLY_IniAddSection(MLY_IniSectionList* pSectionList, MLY_IniSection* pSection);
    MLYAPI MLY_IniSection*      MLYCALL MLY_IniGetSection(MLY_IniSectionList* pSectionList, const char* pName);
    MLYAPI mly_bool_t           MLYCALL MLY_IniSectionAddField(MLY_IniSection* pSection, MLY_IniField* pField);
    MLYAPI MLY_IniField*        MLYCALL MLY_IniSectionGetField(MLY_IniSection* pSection, const char* pName, bool createIfMissing);
    MLYAPI void                 MLYCALL MLY_IniDestroySection(MLY_IniSection* pSection);

    MLYAPI MLY_IniField*        MLYCALL MLY_IniCreateField(const char* pName, MLY_IniFieldType fieldType, void* pData);
    MLYAPI mly_bool_t           MLYCALL MLY_IniAddField(MLY_IniFieldList* pFieldList, MLY_IniField* pField);
    MLYAPI MLY_IniField*        MLYCALL MLY_IniGetField(MLY_IniFieldList* pFieldList, const char* pName);

    MLYAPI mly_int64_t          MLYCALL MLY_IniFieldGetInt(MLY_IniField* pField);
    MLYAPI double               MLYCALL MLY_IniFieldGetDouble(MLY_IniField* pField);
    MLYAPI mly_version_t        MLYCALL MLY_IniFieldGetVersion(MLY_IniField* pField);
    MLYAPI mly_long_version_t   MLYCALL MLY_IniFieldGetVersionLong(MLY_IniField* pField);
    MLYAPI mly_bool_t           MLYCALL MLY_IniFieldGetBool(MLY_IniField* pField);
    MLYAPI const char*          MLYCALL MLY_IniFieldGetString(MLY_IniField* pField);

    MLYAPI void                 MLYCALL MLY_IniFieldSetInt(MLY_IniField* pField, mly_int64_t value);
    MLYAPI void                 MLYCALL MLY_IniFieldSetDouble(MLY_IniField* pField, double value);
    MLYAPI void                 MLYCALL MLY_IniFieldSetVersion(MLY_IniField* pField, mly_version_t value);
    MLYAPI void                 MLYCALL MLY_IniFieldSetVersionLong(MLY_IniField* pField, mly_long_version_t value);
    MLYAPI void                 MLYCALL MLY_IniFieldSetBool(MLY_IniField* pField, mly_bool_t value);
    MLYAPI void                 MLYCALL MLY_IniFieldSetString(MLY_IniField* pField, const char* value);

    MLYAPI void                 MLYCALL MLY_IniDestroyField(MLY_IniField* pField);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifndef MLY_INI_ASSERT
    #include <assert.h>
    #define MLY_INI_ASSERT(expression) assert(expression)
#endif /* MLY_INI_ASSERT */

#ifdef __cplusplus
    #define MLY_INI_EXTERN extern "C"
#else
    #define MLY_INI_EXTERN extern
#endif /* __cplusplus */

#ifndef _MSC_VER
    #ifdef __cplusplus
        #define MLYINLINE inline
    #else
        #define MLYINLINE
    #endif /* __cplusplus */
#else
    #define MLYINLINE __forceinline
#endif /* _MSC_VER */

#endif /* MLY_INI_H */

#ifndef MLY_INI_FIELD_LIST_INITIAL_CAPACITY
    #define MLY_INI_FIELD_LIST_INITIAL_CAPACITY 16
#endif /* MLY_INI_FIELD_LIST_INITIAL_CAPACITY */

#ifndef MLY_INI_SECTION_LIST_INITIAL_CAPACITY
    #define MLY_INI_SECTION_LIST_INITIAL_CAPACITY 8
#endif /* MLY_INI_SECTION_LIST_INITIAL_CAPACITY */

#ifndef MLY_INI_TOKEN_LIST_INITIAL_CAPACITY
    #define MLY_INI_TOKEN_LIST_INITIAL_CAPACITY 128
#endif /* MLY_INI_TOKEN_LIST_INITIAL_CAPACITY */

#ifndef MLY_INI_STRING_INITIAL_CAPACITY
    #define MLY_INI_STRING_INITIAL_CAPACITY 64
#endif /* MLY_INI_STRING_INITIAL_CAPACITY */

#ifndef MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY
    #define MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY 48
#endif /* MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY */

#ifdef MLY_INI_IMPLEMENTATION

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

#ifdef MLY_MSVC
    #define MLY_UNUSED(variable) (void)(variable)
#else
    #define MLY_UNUSED(variable) (void)sizeof(variable)
#endif

#ifndef MLY_CAST
    #define MLY_CAST(_Ty, value) ((_Ty)(value))
#endif /* MLY_CAST */

#ifndef MLY_REINTERPRET
    #define MLY_REINTERPRET(_Ty, value) (*MLY_CAST(_Ty*, value))
#endif /* MLY_REINTERPRET */

#ifndef MLY_MALLOC

/**
 * @brief Identical to standard malloc.
 * 
 * @param size The desired size of the new buffer.
 * 
 * @return void* Pointer to the allocated buffer.
 */
#define MLY_MALLOC(size)                malloc(size)

/**
 * @brief Used to allocate single element buffers.
 * 
 * @param _Ty The desired type to cast to and used to calculate the buffer size.
 * 
 * @return Pointer to the allocated buffer.
 */
#define MLY_MALLOC_T(_Ty)               MLY_CAST(_Ty*, MLY_MALLOC(sizeof(_Ty)))

/**
 * @brief Identical to standard realloc.
 * 
 * @param ptr Pointer to the buffer to reallocate.
 * @param size The desired buffer size.
 * 
 * @return void* Pointer to the new buffer.
 */
#define MLY_REALLOC(ptr, size)          realloc(ptr, size)

/**
 * @brief Near identical to standard reallocate but casts the result to the desired type.
 * 
 * @param _Ty The type to cast to.
 * @param ptr Pointer to the buffer to reallocate.
 * @param size The desired buffer size.
 * 
 * @return Pointer to the new buffer.
 */
#define MLY_REALLOC_T(_Ty, ptr, size)   MLY_CAST(_Ty*, MLY_REALLOC(ptr, size))

/**
 * @brief Identical to standard free.
 * 
 * @param ptr The buffer to free.
 */
#define MLY_FREE(ptr)                   free(MLY_CAST(void*, ptr))

/**
 * @brief Basically just standard calloc.
 * 
 * @param size The size of the elements in the buffer.
 * @param count The amount of elements in the buffer.
 * 
 * @return void* Pointer to the new buffer.
 */
#define MLY_CALLOC(size, count)         MLY_MALLOC(size * count)

/**
 * @brief Close to standard calloc but uses the provided type for its element size
 * * and automatically casts the allocated buffer to the desired type.
 * 
 * @param _Ty The type to used to calculate the buffer size.
 * @param count The amount of elements in the buffer.
 * 
 * @return Pointer to the new buffer.
 */
#define MLY_CALLOC_T(_Ty, count)        MLY_CAST(_Ty*, MLY_CALLOC(sizeof(_Ty), count))

#endif

    typedef enum MLY_IniTokenType
    {
        MLY_INI_TOKEN_IDENTIFIER = 0,
        MLY_INI_TOKEN_EQUAL,
        MLY_INI_TOKEN_INT,
        MLY_INI_TOKEN_DOUBLE,
        MLY_INI_TOKEN_VERSION,
        MLY_INI_TOKEN_VERSION_LONG,
        MLY_INI_TOKEN_BOOL,
        MLY_INI_TOKEN_STRING,
        MLY_INI_TOKEN_LBRACKET,
        MLY_INI_TOKEN_RBRACKET,
        MLY_INI_TOKEN_PLUS,
        MLY_INI_TOKEN_MINUS,
        MLY_INI_TOKEN_ASTERISK,
        MLY_INI_TOKEN_SLASH,
        MLY_INI_TOKEN_EQUAL_EQUAL,
        MLY_INI_TOKEN_QUESTION,
        MLY_INI_TOKEN_COLON,
        MLY_INI_TOKEN_EOF,
    } MLY_IniTokenType;

    /**
     * @brief Enum for the IniASTNode types, split into categories using the left bits.
     */
    typedef enum MLY_IniASTNodeType
    {
        MLY_INI_AST_NODE_ROOT = 0,
        MLY_INI_AST_NODE_SECTION,
        MLY_INI_AST_NODE_KEY_VALUE,

        /**
         * I want to make this parser capable of expressions in field definitions
         * and things like that so these are here for whenever I get to that.
         */

        MLY_INI_AST_NODE_IDENTIFIER = 0x0100,

        MLY_INI_AST_NODE_EXPRESSION_UNARY = 0x0200,
        MLY_INI_AST_NODE_EXPRESSION_BINARY,
        MLY_INI_AST_NODE_EXPRESSION_TERNARY,
    } MLY_IniASTNodeType;

    typedef struct MLY_IniField
    {
        MLY_IniFieldType type;
        char* key;
        union
        {
            mly_bool_t u_bool;
            mly_int64_t u_int;
            double u_double;
            char* u_string;
            mly_version_t u_version;
            mly_long_version_t u_longVersion;
        } value;
    } MLY_IniField;

    typedef struct MLY_IniSection
    {
        char* name;
        MLY_IniFieldList* fields;
    } MLY_IniSection;

    typedef struct MLY_IniTokenDefinition
    {
        MLY_IniTokenType type;
        const char* lexeme;
    } MLY_IniTokenDefinition;

    typedef struct MLY_IniToken
    {
        MLY_IniTokenType type;
        char* lexeme;
    } MLY_IniToken;

    typedef union MLY_IniASTNode MLY_IniASTNode;

    typedef struct MLY_IniASTNodeRoot
    {
        MLY_IniASTNodeType type;
        MLY_IniASTNode** globalFields;
        mly_uint32_t globalCount;
        mly_uint32_t globalCapacity;
        MLY_IniASTNode** sections;
        mly_uint32_t sectionCount;
        mly_uint32_t sectionCapacity;
    } MLY_IniASTNodeRoot;

    typedef struct MLY_IniASTNodeSection
    {
        MLY_IniASTNodeType type;
        MLY_IniASTNode** fields;
        mly_uint32_t fieldCount;
        mly_uint32_t fieldCapacity;
        const char* name;
    } MLY_IniASTNodeSection;

    typedef struct MLY_IniASTNodeKeyValue
    {
        MLY_IniASTNodeType type;
        MLY_IniFieldType valueType;
        const char* key;
        const char* value;
    } MLY_IniASTNodeKeyValue;

    typedef union MLY_IniASTNode
    {
        MLY_IniASTNodeType type;
        MLY_IniASTNodeRoot root;
        MLY_IniASTNodeSection section;
        MLY_IniASTNodeKeyValue keyValue;
    } MLY_IniASTNode;

    /**
     * @brief Basic structure for holding field lists. Created because I needed
     * * to have global fields in the IniFile which I didn't want to have as a
     * * section within the sections array.
     * @note Used to use mly_size_t for length and capacity but now uses unsigned 32-bit
     * * integers because I see no reason for it to be any larger and I doubt anyone would
     * * unironically have a .ini file with as many fields as the unsigned 32-bit integer limit.
     */
    typedef struct MLY_IniFieldList
    {
        mly_uint32_t length;
        mly_uint32_t capacity;
        MLY_IniField** data;
    } MLY_IniFieldList;

    typedef struct MLY_IniSectionList
    {
        mly_uint32_t length;
        mly_uint32_t capacity;
        MLY_IniSection** data;
    } MLY_IniSectionList;

    typedef struct MLY_IniTokenList
    {
        mly_uint32_t length;
        mly_uint32_t capacity;
        MLY_IniToken* data;
    } MLY_IniTokenList;

    typedef struct MLY_IniFile
    {
        FILE* file;

        const char* name;
        char* data;

        MLY_IniTokenList* tokens;

        MLY_IniFieldList* globals;
        MLY_IniSectionList* sections;
    } MLY_IniFile;

    typedef struct MLY_IniLexicalAnalyzer
    {
        MLY_IniFile* iniFile;
        MLY_IniTokenList* tokens;
    } MLY_IniLexicalAnalyzer;

    typedef struct MLY_IniParser
    {
        mly_size_t cursor;
        MLY_IniFile* iniFile;
        MLY_IniASTNode* syntaxTree;
        MLY_IniASTNodeSection* currentSectionNode;
    } MLY_IniParser;

    typedef struct mly_string_t
    {
        mly_size_t length;
        mly_size_t capacity;
        char* data;
    } mly_string_t;

    const MLY_IniTokenDefinition mly__g_ini_token_definitions[] = {
        { .type = MLY_INI_TOKEN_LBRACKET,       .lexeme = "[" },
        { .type = MLY_INI_TOKEN_RBRACKET,       .lexeme = "]" },
        { .type = MLY_INI_TOKEN_BOOL,           .lexeme = "true" },
        { .type = MLY_INI_TOKEN_BOOL,           .lexeme = "false" },
        { .type = MLY_INI_TOKEN_BOOL,           .lexeme = "yes" },
        { .type = MLY_INI_TOKEN_BOOL,           .lexeme = "no" },
        { .type = MLY_INI_TOKEN_BOOL,           .lexeme = "on" },
        { .type = MLY_INI_TOKEN_BOOL,           .lexeme = "off" },
        { .type = MLY_INI_TOKEN_EQUAL,          .lexeme = "=" },
        { .type = MLY_INI_TOKEN_PLUS,           .lexeme = "+" },
        { .type = MLY_INI_TOKEN_MINUS,          .lexeme = "-" },
        { .type = MLY_INI_TOKEN_ASTERISK,       .lexeme = "*" },
        { .type = MLY_INI_TOKEN_SLASH,          .lexeme = "/" },
        { .type = MLY_INI_TOKEN_EQUAL_EQUAL,    .lexeme = "==" },
        { .type = MLY_INI_TOKEN_QUESTION,       .lexeme = "?"},
        { .type = MLY_INI_TOKEN_COLON,          .lexeme = ":" },
    };

    const mly_size_t mly__g_ini_token_definition_count = sizeof(mly__g_ini_token_definitions) / sizeof(mly__g_ini_token_definitions[0]);

    const char* mly__g_ini_error;

#ifdef __cplusplus__
    extern "C" {
#endif

    MLYAPI const char* MLYCALL MLY_IniError(void)
    {
        return mly__g_ini_error;
    }

#ifndef MLY_INI_DISABLE_ERROR_MESSAGES
    MLYINLINE static void MLYCALL mly__ini_error_message(const char* pMessage)
    {
        mly__g_ini_error = pMessage;
    }

    /**
     * @brief Sets the error message, thus reporting it.
     * 
     * @param message The message to report.
     */
    #define mly__ini_error(message) mly__ini_error_message(message)
#else
    #define mly__ini_error(message) ((void)0)
#endif

    static mly_string_t* MLYCALL mly__ini_create_string(void)
    {
        mly_string_t* string = MLY_MALLOC_T(mly_string_t);
        if (string == NULL)
        {
            mly__ini_error("Failed to allocate mly_string_t.");
            return NULL;
        }
        memset(string, 0, sizeof(mly_string_t));
        string->capacity = MLY_INI_STRING_INITIAL_CAPACITY;
        string->data = MLY_CALLOC_T(char, MLY_INI_STRING_INITIAL_CAPACITY);
        if (string->data == NULL)
        {
            mly__ini_error("Failed to allocate string data.");
            MLY_FREE(string);
            return NULL;
        }
        memset(string->data, 0, MLY_INI_STRING_INITIAL_CAPACITY);
        return string;
    }

    static mly_string_t* MLYCALL mly__ini_create_string_from_buffer(const char* pData)
    {
        if (pData == NULL)
        {
            mly__ini_error("pData must not be NULL!");
            return NULL;
        }
        mly_string_t* string = MLY_MALLOC_T(mly_string_t);
        if (string == NULL)
        {
            mly__ini_error("Failed to allocate mly_string_t.");
            return NULL;
        }
        memset(string, 0, sizeof(mly_string_t));
        mly_size_t dataLength = strlen(pData) + 1;
        string->capacity = dataLength;
        string->length = dataLength - 1;
        string->data = MLY_CALLOC_T(char, dataLength);
        if (string->data == NULL)
        {
            mly__ini_error("Failed to allocate string data.");
            MLY_FREE(string);
            return NULL;
        }
        memcpy(string->data, pData, dataLength);
        return string;
    }

    static void MLYCALL mly__ini_clear_string(mly_string_t* pString)
    {
        if (pString == NULL) return;
        pString->length = 0;
        memset(pString->data, 0, pString->capacity);
    }

    static mly_string_t* MLYCALL mly__ini_copy_string(mly_string_t* pString)
    {
        if (pString == NULL)
        {
            mly__ini_error("pString must not be NULL!");
            return NULL;
        }
        mly_string_t* string = MLY_MALLOC_T(mly_string_t);
        if (string == NULL)
        {
            mly__ini_error("Failed to allocate mly_string_t.");
            return NULL;
        }
        memset(string, 0, sizeof(mly_string_t));
        mly_size_t dataLength = pString->length + 1;
        string->capacity = dataLength;
        string->length = pString->length;
        string->data = MLY_CALLOC_T(char, dataLength);
        if (string->data == NULL)
        {
            mly__ini_error("Failed to allocate string data.");
            MLY_FREE(string);
            return NULL;
        }
        memcpy(string->data, pString->data, dataLength);
        return string;
    }

    /**
     * @brief Appends a character to a string.
     *
     * @param pString The string to append to.
     * @param c The character to append to the string.
     *
     * @return true on success or false on failure
     */
    static mly_bool_t MLYCALL mly__ini_append_to_string(mly_string_t* pString, int c)
    {
        if (pString == NULL)
        {
            mly__ini_error("pString must not be NULL!");
            return false;
        }
        if (pString->length + 1 >= pString->capacity)
        {
            mly_size_t capacity = pString->capacity;
            do
            {
                capacity <<= 1;
            } while (pString->length + 1 >= capacity);

            char* buffer = MLY_REALLOC_T(char, pString->data, capacity);
            if (buffer == NULL)
            {
                return false;
            }
            pString->data = buffer;
            pString->capacity = capacity;
        }
        pString->data[pString->length++] = c;
        pString->data[pString->length] = '\0';
        return true;
    }

    static void MLYCALL mly__ini_destroy_string(mly_string_t* pString)
    {
        if (pString == NULL) return;
        if (pString->data != NULL)
        {
            MLY_FREE(pString->data);
        }
        MLY_FREE(pString);
    }

    static MLY_IniTokenList* MLYCALL mly__ini_create_token_list(void)
    {
        MLY_IniTokenList* list = MLY_MALLOC_T(MLY_IniTokenList);
        if (list == NULL)
        {
            mly__ini_error("Failed to allocate IniTokenList.");
            return NULL;
        }
        memset(list, 0, sizeof(MLY_IniTokenList));
        list->capacity = MLY_INI_TOKEN_LIST_INITIAL_CAPACITY;
        list->data = MLY_CALLOC_T(MLY_IniToken, MLY_INI_TOKEN_LIST_INITIAL_CAPACITY);
        if (list->data == NULL)
        {
            mly__ini_error("Failed to allocate IniToken list.");
            MLY_FREE(list);
            return NULL;
        }
        return list;
    }

    static mly_bool_t MLYCALL mly__ini_add_token(MLY_IniTokenList* pTokenList, MLY_IniTokenType type, const char* pLexeme)
    {
        if (pTokenList == NULL)
        {
            mly__ini_error("pTokenList must not be NULL!");
            return false;
        }
        char* lexemeBuffer = NULL;
        if (pLexeme != NULL)
        {
            mly_size_t nameLength = strlen(pLexeme) + 1;
            lexemeBuffer = MLY_CALLOC_T(char, nameLength);
            if (lexemeBuffer == NULL)
            {
                mly__ini_error("Failed to allocate lexeme buffer.");
                return false;
            }
            memcpy(lexemeBuffer, pLexeme, nameLength);
        }
        MLY_IniToken token = {
            .type = type,
            .lexeme = lexemeBuffer
        };
        if (pTokenList->length >= pTokenList->capacity)
        {
            pTokenList->capacity = pTokenList->capacity == 0 ? MLY_INI_TOKEN_LIST_INITIAL_CAPACITY : (pTokenList->capacity << 1);
            MLY_IniToken* data = MLY_REALLOC_T(MLY_IniToken, pTokenList->data, pTokenList->capacity * sizeof(MLY_IniToken));
            if (data == NULL)
            {
                mly__ini_error("Failed to reallocate token list data.");
                if (lexemeBuffer != NULL) MLY_FREE(lexemeBuffer);
                return false;
            }
            pTokenList->data = data;
        }
        memcpy(pTokenList->data + pTokenList->length, &token, sizeof(MLY_IniToken));
        ++pTokenList->length;
        return true;
    }

#if defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wuninitialized"
#elif defined(__GNUC__) || defined(__GNUG__)
    #pragma gcc diagnostic push
    #pragma gcc diagnostic ignored "-Wuninitialized"
#elif defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable : 6001)
#endif

    static void MLYCALL mly__ini_destroy_token_list(MLY_IniTokenList* pTokenList)
    {
        if (pTokenList == NULL) return;
        if (pTokenList->data != NULL)
        {
            for (mly_size_t i = 0; i < pTokenList->length; ++i)
            {
                if (pTokenList->data[i].lexeme != NULL) MLY_FREE(pTokenList->data[i].lexeme);
            }
            MLY_FREE(pTokenList->data);
        }
        MLY_FREE(pTokenList);
    }

#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(__GNUC__) || defined(__GNUG__)
    #pragma gcc diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif

    static const char* MLYCALL mly__ini_get_token_type_string(MLY_IniTokenType type)
    {
        switch (type)
        {
            case MLY_INI_TOKEN_IDENTIFIER:      return "MLY_INI_TOKEN_IDENTIFIER";
            case MLY_INI_TOKEN_EQUAL:           return "MLY_INI_TOKEN_EQUAL";
            case MLY_INI_TOKEN_INT:             return "MLY_INI_TOKEN_INT";
            case MLY_INI_TOKEN_DOUBLE:          return "MLY_INI_TOKEN_DOUBLE";
            case MLY_INI_TOKEN_VERSION:         return "MLY_INI_TOKEN_VERSION";
            case MLY_INI_TOKEN_VERSION_LONG:    return "MLY_INI_TOKEN_VERSION_LONG";
            case MLY_INI_TOKEN_BOOL:            return "MLY_INI_TOKEN_BOOL";
            case MLY_INI_TOKEN_LBRACKET:        return "MLY_INI_TOKEN_LBRACKET";
            case MLY_INI_TOKEN_RBRACKET:        return "MLY_INI_TOKEN_RBRACKET";
            case MLY_INI_TOKEN_PLUS:            return "MLY_INI_TOKEN_PLUS";
            case MLY_INI_TOKEN_MINUS:           return "MLY_INI_TOKEN_MINUS";
            case MLY_INI_TOKEN_ASTERISK:        return "MLY_INI_TOKEN_ASTERISK";
            case MLY_INI_TOKEN_SLASH:           return "MLY_INI_TOKEN_SLASH";
            case MLY_INI_TOKEN_EQUAL_EQUAL:     return "MLY_INI_TOKEN_EQUAL_EQUAL";
            case MLY_INI_TOKEN_QUESTION:        return "MLY_INI_TOKEN_QUESTION";
            case MLY_INI_TOKEN_COLON:           return "MLY_INI_TOKEN_COLON";
            default:                            return "MLY_INI_TOKEN_UNKNOWN";
        }
    }

    static MLY_IniFile* MLYCALL mly__ini_create_file(void)
    {
        MLY_IniFile* iniFile = MLY_MALLOC_T(MLY_IniFile);
        if (iniFile == NULL)
        {
            mly__ini_error("Failed to allocate IniFile.");
            return NULL;
        }
        memset(iniFile, 0, sizeof(MLY_IniFile));
        iniFile->sections = MLY_IniCreateSectionList();
        if (iniFile->sections == NULL)
        {
            MLY_FREE(iniFile);
            return NULL;
        }
        iniFile->globals = MLY_IniCreateFieldList();
        if (iniFile->globals == NULL)
        {
            mly__ini_error("Failed to allocate globals field list.");
            MLY_IniDestroySectionList(iniFile->sections);
            MLY_FREE(iniFile);
            return NULL;
        }
        return iniFile;
    }

    static MLY_IniASTNode* MLYCALL mly__ini_create_ast_node(MLY_IniASTNodeType type)
    {
        MLY_IniASTNode* node = MLY_MALLOC_T(MLY_IniASTNode);
        if (node == NULL)
        {
            mly__ini_error("Failed to allocate IniASTNode");
            return NULL;
        }
        memset(node, 0, sizeof(MLY_IniASTNode));
        node->type = type;
        if (node->type == MLY_INI_AST_NODE_ROOT)
        {
            node->root.globalCapacity = MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY;
            node->root.globalFields = MLY_CALLOC_T(MLY_IniASTNode*, MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY);
            if (node->root.globalFields == NULL)
            {
                mly__ini_error("Failed to allocate IniASTNodeRoot global fields.");
                MLY_FREE(node);
                return NULL;
            }
            node->root.sectionCapacity = MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY;
            node->root.sections = MLY_CALLOC_T(MLY_IniASTNode*, MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY);
            if (node->root.sections == NULL)
            {
                mly__ini_error("Failed to allocate IniASTNodeRoot sections.");
                MLY_FREE(node->root.globalFields);
                MLY_FREE(node);
                return NULL;
            }
        }
        else if (node->type == MLY_INI_AST_NODE_SECTION)
        {
            node->section.fieldCapacity = MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY;
            node->section.fields = MLY_CALLOC_T(MLY_IniASTNode*, MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY);
            if (node->section.fields == NULL)
            {
                mly__ini_error("Failed to allocate IniASTNodeSection fields.");
                MLY_FREE(node);
                return NULL;
            }
        }
        return node;
    }

    static mly_bool_t MLYCALL mly__ini_add_ast_node_key_value_to_root(MLY_IniASTNodeRoot* pRoot, MLY_IniASTNodeKeyValue* pKeyValue)
    {
        if (pRoot == NULL)
        {
            mly__ini_error("pRoot must not be NULL!");
            return false;
        }
        MLY_INI_ASSERT(pRoot->type == MLY_INI_AST_NODE_ROOT && "pRoot->type must be MLY_INI_AST_NODE_KEY_VALUE!");
        if (pRoot->globalFields == NULL)
        {
            mly__ini_error("pRoot->globalFields must not be NULL!");
            return false;
        }
        if (pKeyValue == NULL)
        {
            mly__ini_error("pKeyValue must not be NULL!");
            return false;
        }
        MLY_INI_ASSERT(pKeyValue->type == MLY_INI_AST_NODE_KEY_VALUE && "pKeyValue->type must be MLY_INI_AST_NODE_KEY_VALUE");

        if (pRoot->globalCount >= pRoot->globalCapacity)
        {
            pRoot->globalCapacity = pRoot->globalCapacity == 0 ? MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY : (pRoot->globalCapacity << 1);
            MLY_IniASTNode** fields = MLY_REALLOC_T(MLY_IniASTNode*, pRoot->globalFields, pRoot->globalCapacity * sizeof(MLY_IniASTNode*));
            if (fields == NULL)
            {
                mly__ini_error("Failed to reallocate IniASTNodeKeyValue array.");
                return false;
            }
            pRoot->globalFields = fields;
        }
        pRoot->globalFields[pRoot->globalCount++] = MLY_CAST(MLY_IniASTNode*, pKeyValue);
        return true;
    }

    static mly_bool_t MLYCALL mly__ini_add_ast_node_section(MLY_IniASTNodeRoot* pRoot, MLY_IniASTNodeSection* pSection)
    {
        if (pRoot == NULL)
        {
            mly__ini_error("pRoot must not be NULL!");
            return false;
        }
        if (pRoot->type != MLY_INI_AST_NODE_ROOT)
        {
            mly__ini_error("pRoot->type must be MLY_INI_AST_NODE_ROOT!");
        }
        if (pSection == NULL)
        {
            mly__ini_error("pSection must not be NULL!");
            return false;
        }
        if (pSection->type != MLY_INI_AST_NODE_SECTION)
        {
            mly__ini_error("pNode->type must be MLY_INI_AST_NODE_SECTION!");
            return false;
        }
        if (pRoot->sectionCount >= pRoot->sectionCapacity)
        {
            pRoot->sectionCapacity = pRoot->sectionCapacity == 0 ? MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY : (pRoot->sectionCapacity << 1);
            MLY_IniASTNode** sections = MLY_REALLOC_T(MLY_IniASTNode*, pRoot->sections, pRoot->sectionCapacity * sizeof(MLY_IniASTNode*));
            if (sections == NULL)
            {
                mly__ini_error("Failed to reallocate IniASTNodeSection array.");
                return false;
            }
            pRoot->sections = sections;
        }
        pRoot->sections[pRoot->sectionCount++] = MLY_CAST(MLY_IniASTNode*, pSection);
        return true;
    }

    static mly_bool_t MLYCALL mly__ini_add_ast_node_key_value_to_section(MLY_IniASTNodeSection* pSection, MLY_IniASTNodeKeyValue* pKeyValue)
    {
        if (pSection == NULL)
        {
            mly__ini_error("pSection must not be NULL!");
            return false;
        }
        if (pSection->fields == NULL)
        {
            mly__ini_error("pSection->fields must not be NULL!");
            return false;
        }
        if (pKeyValue == NULL)
        {
            mly__ini_error("pKeyValue must not be NULL!");
            return false;
        }
        MLY_INI_ASSERT(pKeyValue->type == MLY_INI_AST_NODE_KEY_VALUE && "pKeyValue->type must be MLY_INI_AST_NODE_KEY_VALUE");

        if (pSection->fieldCount >= pSection->fieldCapacity)
        {
            pSection->fieldCapacity = pSection->fieldCapacity == 0 ? MLY_INI_AST_NODE_INITIAL_ARRAY_CAPACITY : (pSection->fieldCapacity << 1);
            MLY_IniASTNode** fields = MLY_REALLOC_T(MLY_IniASTNode*, pSection->fields, pSection->fieldCapacity * sizeof(MLY_IniASTNode*));
            if (fields == NULL)
            {
                mly__ini_error("Failed to reallocate IniASTNodeKeyValue array.");
                return false;
            }
            pSection->fields = fields;
        }
        pSection->fields[pSection->fieldCount++] = MLY_CAST(MLY_IniASTNode*, pKeyValue);
        return true;
    }

    static void MLYCALL mly__ini_destroy_ast_node(MLY_IniASTNode* pNode)
    {
        if (pNode == NULL) return;
        switch (pNode->type)
        {
            case MLY_INI_AST_NODE_ROOT:
                if (pNode->root.globalFields != NULL)
                {
                    for (mly_size_t i = 0; i < pNode->root.globalCount; ++i)
                    {
                        mly__ini_destroy_ast_node(pNode->root.globalFields[i]);
                    }
                    MLY_FREE(pNode->root.globalFields);
                }
                if (pNode->root.sections != NULL)
                {
                    for (mly_size_t i = 0; i < pNode->root.sectionCount; ++i)
                    {
                        mly__ini_destroy_ast_node(pNode->root.sections[i]);
                    }
                    MLY_FREE(pNode->root.sections);
                }
                break;
            case MLY_INI_AST_NODE_SECTION:
                if (pNode->section.fields != NULL)
                {
                    for (mly_size_t i = 0; i < pNode->section.fieldCount; ++i)
                    {
                        mly__ini_destroy_ast_node(pNode->section.fields[i]);
                    }
                    MLY_FREE(pNode->section.fields);
                    if (pNode->section.name != NULL) MLY_FREE(pNode->section.name);
                }
                break;
            case MLY_INI_AST_NODE_KEY_VALUE:
                if (pNode->keyValue.key != NULL)
                {
                    MLY_FREE(pNode->keyValue.key);
                }
                if (pNode->keyValue.value != NULL)
                {
                    MLY_FREE(pNode->keyValue.value);
                }
                break;
            default:
                break;
        }
        MLY_FREE(pNode);
    }

    static MLY_IniLexicalAnalyzer* MLYCALL mly__ini_create_lexical_analyzer(MLY_IniFile* pIniFile)
    {
        if (pIniFile == NULL)
        {
            mly__ini_error("pIniFile must not be NULL!");
            return NULL;
        }
        MLY_IniLexicalAnalyzer* lexicalAnalyzer = MLY_MALLOC_T(MLY_IniLexicalAnalyzer);
        if (lexicalAnalyzer == NULL)
        {
            mly__ini_error("Failed to allocate IniLexicalAnalyzer.");
            return NULL;
        }
        memset(lexicalAnalyzer, 0, sizeof(MLY_IniLexicalAnalyzer));
        lexicalAnalyzer->iniFile = pIniFile;
        lexicalAnalyzer->tokens = mly__ini_create_token_list();
        if (lexicalAnalyzer->tokens == NULL)
        {
            mly__ini_error("Failed to allocate tokens list for IniLexicalAnalyzer.");
            MLY_FREE(lexicalAnalyzer);
            return NULL;
        }
        return lexicalAnalyzer;
    }

    static void MLYCALL mly__ini_destroy_lexical_analyzer(MLY_IniLexicalAnalyzer* pLexicalAnalyzer)
    {
        if (pLexicalAnalyzer == NULL) return;
        MLY_FREE(pLexicalAnalyzer);
    }

    static MLY_IniParser* MLYCALL mly__ini_create_parser(MLY_IniFile* pIniFile)
    {
        if (pIniFile == NULL)
        {
            mly__ini_error("pIniFile must not be NULL!");
            return NULL;
        }
        MLY_IniParser* parser = MLY_MALLOC_T(MLY_IniParser);
        if (parser == NULL)
        {
            mly__ini_error("Failed to allocate MLY_IniParser.");
            return NULL;
        }
        memset(parser, 0, sizeof(MLY_IniParser));
        parser->iniFile = pIniFile;

        MLY_IniASTNode* rootNode = mly__ini_create_ast_node(MLY_INI_AST_NODE_ROOT);
        if (rootNode == NULL)
        {
            MLY_FREE(parser);
            return NULL;
        }
        parser->syntaxTree = rootNode;

        return parser;
    }

    static void MLYCALL mly__ini_destroy_parser(MLY_IniParser* pParser)
    {
        if (pParser == NULL) return;
        if (pParser->syntaxTree != NULL)
        {
            mly__ini_destroy_ast_node(pParser->syntaxTree);
        }
        MLY_FREE(pParser);
    }

    static mly_bool_t MLYCALL mly__ini_read_file(MLY_IniFile* pIniFile, const char* pFilename)
    {
        if (pIniFile == NULL)
        {
            mly__ini_error("pIniFile must not be NULL!");
            return false;
        }

        if (fopen_s(&pIniFile->file, pFilename, "rb+") != 0)
        {
            mly__ini_error("File does not exist.");
            return false;
        }

        fseek(pIniFile->file, 0, SEEK_END);
        mly_size_t length = MLY_CAST(mly_size_t, ftell(pIniFile->file));
        fseek(pIniFile->file, 0, SEEK_SET);

        char* data = MLY_CALLOC_T(char, length + 1);
        if (data == NULL)
        {
            mly__ini_error("Failed to allocate data buffer for file.");
            fclose(pIniFile->file);
            return false;
        }

        fread_s(data, length, 1, length, pIniFile->file);
        data[length] = '\0';

        pIniFile->data = data;

        return true;
    }

    static mly_bool_t MLYCALL mly__ini_lex_file(MLY_IniFile* pIniFile)
    {
        if (pIniFile == NULL)
        {
            mly__ini_error("Unable to lex NULL pIniFile.");
            return false;
        }
        MLY_IniLexicalAnalyzer* lexicalAnalyzer = mly__ini_create_lexical_analyzer(pIniFile);
        if (lexicalAnalyzer == NULL)
        {
            return false;
        }
        MLY_IniTokenList* tokens = lexicalAnalyzer->tokens;
        mly_string_t* currentLexeme = mly__ini_create_string();

        MLY_IniTokenType currentTokenType = MLY_INI_TOKEN_IDENTIFIER;

        char* source = pIniFile->data;
        while (*source && *source != EOF)
        {
            if (isspace(*source))
            {
                ++source;
                continue;
            }
            if (isalpha(*source) || *source == '_')
            {
                while (isalnum(*source) || *source == '_' && *source != EOF)
                {
                    mly__ini_append_to_string(currentLexeme, *source++);
                }

                MLY_IniTokenType type = MLY_INI_TOKEN_IDENTIFIER;

                for (mly_uint32_t j = 0; j < mly__g_ini_token_definition_count; ++j)
                {
                    if (strcmp(currentLexeme->data, mly__g_ini_token_definitions[j].lexeme) == 0)
                    {
                        type = mly__g_ini_token_definitions[j].type;
                    }
                }

                if (!mly__ini_add_token(tokens, type, currentLexeme->data))
                {
                    mly__ini_destroy_string(currentLexeme);
                    mly__ini_destroy_token_list(tokens);
                    mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);
                    return false;
                }
                mly__ini_clear_string(currentLexeme);

                continue;
            }

            if (isdigit(*source))
            {
                MLY_IniTokenType type = MLY_INI_TOKEN_INT;
                mly_uint8_t periodCount = 0;
                while (isdigit(*source) || *source == '.' && *source != EOF)
                {
                    if (*source == '.')
                    {
                        if (*(source + 1) == '.')
                        {
                            mly__ini_error("Cannot create version number with two periods right next to each other.");
                            mly__ini_destroy_string(currentLexeme);
                            mly__ini_destroy_token_list(tokens);
                            mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);
                            return false;
                        }
                        type = MLY_INI_TOKEN_DOUBLE;
                        periodCount += 1;
                        if (periodCount == 2)
                        {
                            type = MLY_INI_TOKEN_VERSION;
                        }
                        else if (periodCount > 2)
                        {
                            mly__ini_error("Too many periods for semantic versioning scheme! Example of proper semantic versioning scheme: -> x.x.x <-");
                            mly__ini_destroy_string(currentLexeme);
                            mly__ini_destroy_token_list(tokens);
                            mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);
                            return false;
                        }
                    }
                    mly__ini_append_to_string(currentLexeme, *source++);
                }

                if (!mly__ini_add_token(tokens, type, currentLexeme->data))
                {
                    mly__ini_destroy_string(currentLexeme);
                    mly__ini_destroy_token_list(tokens);
                    mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);
                    return false;
                }
                mly__ini_clear_string(currentLexeme);

                continue;
            }

            mly_int32_t validDefinitions;
            MLY_IniTokenDefinition definition;

            mly_int32_t lastValidIteration = 0;

            do
            {
                validDefinitions = 0;
                mly__ini_append_to_string(currentLexeme, *source++);
                for (mly_uint32_t j = 0; j < mly__g_ini_token_definition_count; ++j)
                {
                    if (strcmp(currentLexeme->data, mly__g_ini_token_definitions[j].lexeme) == 0)
                    {
                        definition = mly__g_ini_token_definitions[j];
                        ++validDefinitions;
                    }
                }
                if (validDefinitions > 0) lastValidIteration = currentLexeme->length;
            } while (validDefinitions > 1 && *source != EOF);

            if (validDefinitions == 1)
            {
                if (!mly__ini_add_token(tokens, definition.type, definition.lexeme))
                {
                    mly__ini_destroy_string(currentLexeme);
                    mly__ini_destroy_token_list(tokens);
                    mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);
                    return false;
                }
            }
            else if (validDefinitions == 0)
            {
                if (currentLexeme->length > 1 && lastValidIteration != currentLexeme->length - 1)
                {
                    mly__ini_error("Unknown token found.");
                    mly__ini_destroy_string(currentLexeme);
                    mly__ini_destroy_token_list(tokens);
                    mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);
                    return false;
                }
                else
                {
                    if (currentLexeme->length > 0)
                    {
                        currentLexeme->data[currentLexeme->length - 1] = '\0';
                        --source; /* Rolls back the source pointer to the previous position so it can be read next */

                        if (!mly__ini_add_token(tokens, definition.type, definition.lexeme))
                        {
                            mly__ini_destroy_string(currentLexeme);
                            mly__ini_destroy_token_list(tokens);
                            mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);
                            return false;
                        }
                    }
                }
            }

            mly__ini_clear_string(currentLexeme);
        }

        mly__ini_destroy_string(currentLexeme);
        mly__ini_destroy_lexical_analyzer(lexicalAnalyzer);

        mly__ini_add_token(tokens, MLY_INI_TOKEN_EOF, NULL);

        pIniFile->tokens = tokens;

        return true;
    }

    static MLY_IniToken* MLYCALL mly__ini_parser_peek_token(MLY_IniParser* pParser)
    {
        if (pParser == NULL)
        {
            mly__ini_error("pParser must not be NULL!");
            return NULL;
        }
        if (pParser->iniFile == NULL)
        {
            mly__ini_error("pParser->iniFile must not be NULL!");
            return NULL;
        }
        if (pParser->iniFile->tokens == NULL)
        {
            mly__ini_error("pParser->iniFile->tokens must not be NULL!");
            return NULL;
        }
        MLY_IniToken* token = &pParser->iniFile->tokens->data[pParser->cursor];
        return token;
    }

    static MLY_IniToken* MLYCALL mly__ini_parser_advance(MLY_IniParser* pParser)
    {
        MLY_IniToken* token = mly__ini_parser_peek_token(pParser);
        if (token == NULL)
        {
            return NULL;
        }
        ++pParser->cursor;
        return token;
    }

    static mly_bool_t MLYCALL mly__ini_parse_left_bracket(MLY_IniParser* pParser)
    {
        if (pParser == NULL)
        {
            mly__ini_error("pParser must not be NULL!");
            return false;
        }
        mly__ini_parser_advance(pParser);
        MLY_IniToken* sectionName = mly__ini_parser_advance(pParser);
        if (sectionName == NULL)
        {
            return false;
        }
        if (sectionName->type != MLY_INI_TOKEN_IDENTIFIER)
        {
            mly__ini_error("Unexpected token found for section name.");
            return false;
        }
        if (mly__ini_parser_advance(pParser)->type != MLY_INI_TOKEN_RBRACKET)
        {
            mly__ini_error("Unexpected token found after section name.");
            return false;
        }
        MLY_IniASTNode* node = mly__ini_create_ast_node(MLY_INI_AST_NODE_SECTION);
        if (node == NULL)
        {
            return false;
        }
        node->section.name = sectionName->lexeme;
        sectionName->lexeme = NULL;
        mly__ini_add_ast_node_section(&pParser->syntaxTree->root, &node->section);
        pParser->currentSectionNode = &node->section;
        return true;
    }

    static mly_bool_t MLYCALL mly__ini_parse_identifier(MLY_IniParser* pParser)
    {
        if (pParser == NULL)
        {
            mly__ini_error("pParser must not be NULL!");
            return false;
        }
        MLY_IniToken* identifier = mly__ini_parser_advance(pParser);
        MLY_IniToken* next = mly__ini_parser_advance(pParser);
        if (next == NULL || next->type != MLY_INI_TOKEN_EQUAL)
        {
            mly__ini_error("Unexpected token found.");
            return false;
        }
        MLY_IniToken* value = mly__ini_parser_advance(pParser);
        if (next == NULL)
        {
            mly__ini_error("Unexpected token found to right of assignment operator.");
            return false;
        }
        MLY_IniFieldType valueType = MLY_INI_TYPE_INT;
        switch (value->type)
        {
            case MLY_INI_TOKEN_INT:             valueType = MLY_INI_TYPE_INT;                       break;
            case MLY_INI_TOKEN_DOUBLE:          valueType = MLY_INI_TYPE_DOUBLE;                    break;
            case MLY_INI_TOKEN_VERSION:         valueType = MLY_INI_TYPE_VERSION;                   break;
            case MLY_INI_TOKEN_VERSION_LONG:    valueType = MLY_INI_TYPE_VERSION_LONG;              break;
            case MLY_INI_TOKEN_BOOL:            valueType = MLY_INI_TYPE_BOOL;                      break;
            case MLY_INI_TOKEN_STRING:          valueType = MLY_INI_TYPE_STRING;                    break;
            default:                            mly__ini_error("Unexpected token type found.");     return false;
        }
        MLY_IniASTNode* node = mly__ini_create_ast_node(MLY_INI_AST_NODE_KEY_VALUE);

        if (node == NULL)
        {
            return false;
        }
        node->keyValue.valueType = valueType;
        node->keyValue.key = identifier->lexeme;
        identifier->lexeme = NULL;
        node->keyValue.value = value->lexeme;
        value->lexeme = NULL;
        if (pParser->currentSectionNode == NULL)
        {
            mly__ini_add_ast_node_key_value_to_root(&pParser->syntaxTree->root, &node->keyValue);
        }
        else
        {
            mly__ini_add_ast_node_key_value_to_section(pParser->currentSectionNode, &node->keyValue);
        }
        return true;
    }

    static MLY_IniField* MLYCALL mly__ini_parse_ast_key_value_node(MLY_IniASTNodeKeyValue* pKeyValue)
    {
        if (pKeyValue == NULL)
        {
            mly__ini_error("pKeyValue must not be NULL!");
            return NULL;
        }
        if (pKeyValue->key == NULL)
        {
            mly__ini_error("pKeyValue->key must not be NULL!");
            return NULL;
        }
        if (pKeyValue->value == NULL)
        {
            mly__ini_error("pKeyValue->value must not be NULL!");
            return NULL;
        }
        MLY_INI_ASSERT(pKeyValue != NULL && "pKeyValue->type must be MLY_INI_AST_NODE_KEY_VALUE");
        mly_size_t keyLength = strlen(pKeyValue->key) + 1;
        MLY_IniField* field = MLY_MALLOC_T(MLY_IniField);
        field->type = pKeyValue->valueType;
        field->key = MLY_CALLOC_T(char, keyLength);
        if (field->key == NULL)
        {
            MLY_FREE(field);
            return NULL;
        }
        memcpy(field->key, pKeyValue->key, keyLength);
        switch (field->type)
        {
            case MLY_INI_TYPE_INT:
                field->value.u_int = MLY_CAST(mly_int64_t, atoll(pKeyValue->value));
                break;
            case MLY_INI_TYPE_DOUBLE:
                field->value.u_double = MLY_CAST(double, atof(pKeyValue->value));
                break;
            case MLY_INI_TYPE_VERSION:
            {
                mly_size_t versionStringLength = strlen(pKeyValue->value);
                char versionString[3][4];
                memset(versionString, '\0', sizeof(versionString));
                mly_int32_t column = 0;
                mly_int32_t row = 0;
                for (mly_size_t i = 0; i < versionStringLength; ++i)
                {
                    if (pKeyValue->value[i] == '.')
                    {
                        row += 1;
                        column = 0;
                        i += 1;
                    }
                    versionString[row][column] = pKeyValue->value[i];
                    column += 1;
                }
                mly_uint32_t major = MLY_CAST(mly_uint32_t, atoi(versionString[0]));
                mly_uint32_t minor = MLY_CAST(mly_uint32_t, atoi(versionString[1]));
                mly_uint32_t patch = MLY_CAST(mly_uint32_t, atoi(versionString[2]));
                mly_uint32_t version = (major << 16) | (minor << 8) | patch;

                field->value.u_version = version;

                break;
            }
            case MLY_INI_TYPE_VERSION_LONG:
            {
                mly_size_t versionStringLength = strlen(pKeyValue->value);
                char versionString[3][4];
                memset(versionString, '\0', sizeof(versionString));
                mly_int32_t column = 0;
                mly_int32_t row = 0;
                for (mly_size_t i = 0; i < versionStringLength; ++i)
                {
                    if (pKeyValue->value[i] == '.')
                    {
                        row += 1;
                        column = 0;
                        i += 1;
                    }
                    versionString[row][column] = pKeyValue->value[i];
                    column += 1;
                }
                mly_uint64_t major = MLY_CAST(mly_uint64_t, atoi(versionString[0]));
                mly_uint64_t minor = MLY_CAST(mly_uint64_t, atoi(versionString[1]));
                mly_uint64_t patch = MLY_CAST(mly_uint64_t, atoi(versionString[2]));
                mly_uint64_t version = (major << 32) | (minor << 16) | patch;

                field->value.u_longVersion = version;

                break;
            }
            case MLY_INI_TYPE_BOOL:
            {
                field->value.u_bool = (strcmp(pKeyValue->value, "on") == 0)
                    || (strcmp(pKeyValue->value, "yes") == 0)
                    || (strcmp(pKeyValue->value, "true") == 0);

                break;
            }
            case MLY_INI_TYPE_STRING:
            {
                mly_size_t valueStringLength = strlen(pKeyValue->value) + 1;
                field->value.u_string = MLY_CALLOC_T(char, valueStringLength);
                if (field->value.u_string == NULL)
                {
                    MLY_FREE(field->key);
                    MLY_FREE(field);
                    return NULL;
                }

                break;
            }
        }

        return field;
    }

    static mly_bool_t MLYCALL mly__ini_parse_file(MLY_IniFile* pIniFile)
    {
        if (pIniFile == NULL)
        {
            mly__ini_error("Unable to parse NULL pIniFile.");
            return false;
        }
        if (pIniFile->tokens == NULL)
        {
            mly__ini_error("pIniFile->tokens must not be NULL!");
            return false;
        }
        MLY_IniTokenList* tokens = pIniFile->tokens;
        MLY_IniParser* parser = mly__ini_create_parser(pIniFile);
        MLY_IniToken* token;
        while ((token = mly__ini_parser_peek_token(parser)) && token->type != MLY_INI_TOKEN_EOF)
        {
            switch (token->type)
            {
                case MLY_INI_TOKEN_LBRACKET:
                {
                    if (!mly__ini_parse_left_bracket(parser))
                    {
                        mly__ini_destroy_parser(parser);
                        mly__ini_destroy_token_list(tokens);
                        pIniFile->tokens = NULL;
                        return false;
                    }
                }
                break;
                case MLY_INI_TOKEN_IDENTIFIER:
                    if (!mly__ini_parse_identifier(parser))
                    {
                        mly__ini_destroy_parser(parser);
                        mly__ini_destroy_token_list(tokens);
                        pIniFile->tokens = NULL;
                        return false;
                    }
                    break;
                default:
                    ++parser->cursor;
                    break;
            }
        }
        mly__ini_destroy_token_list(tokens);

        MLY_IniASTNodeRoot* root = &parser->syntaxTree->root;
        for (mly_uint32_t i = 0; i < root->globalCount; ++i)
        {
            MLY_IniASTNodeKeyValue* keyValue = &root->globalFields[i]->keyValue;
            MLY_IniField* field = mly__ini_parse_ast_key_value_node(keyValue);
            MLY_IniAddField(pIniFile->globals, field);
        }
        for (mly_uint32_t i = 0; i < root->sectionCount; ++i)
        {
            MLY_IniASTNodeSection* sectionNode = &root->sections[i]->section;
            MLY_IniSection* section = MLY_IniCreateSection(sectionNode->name);
            for (mly_uint32_t j = 0; j < sectionNode->fieldCount; ++j)
            {
                MLY_IniASTNodeKeyValue* keyValue = &sectionNode->fields[j]->keyValue;
                MLY_IniField* field = mly__ini_parse_ast_key_value_node(keyValue);
                MLY_IniAddField(section->fields, field);
            }
            MLY_IniAddSection(pIniFile->sections, section);
        }

        mly__ini_destroy_parser(parser);
        pIniFile->tokens = NULL;

        return true;
    }

    static void MLYCALL mly__ini_write_field_to_file(FILE* pFile, const MLY_IniField* pField)
    {
        switch (pField->type)
        {
            case MLY_INI_TYPE_INT:
                fprintf(pFile, "%s = %llu\n", pField->key, pField->value.u_int);
                break;
            case MLY_INI_TYPE_DOUBLE:
                fprintf(pFile, "%s = %f\n", pField->key, pField->value.u_double);
                break;
            case MLY_INI_TYPE_VERSION:
            {
                mly_uint32_t major = (pField->value.u_version & 0x00FF0000) >> 16;
                mly_uint32_t minor = (pField->value.u_version & 0x0000FF00) >> 8;
                mly_uint32_t patch =  pField->value.u_version & 0x000000FF;
                fprintf(pFile, "%s = %u.%u.%u\n", pField->key, major, minor, patch);
                break;
            }
            case MLY_INI_TYPE_VERSION_LONG:
            {
                mly_uint64_t major = (pField->value.u_version & 0x0000FFFF00000000) >> 32;
                mly_uint64_t minor = (pField->value.u_version & 0x00000000FFFF0000) >> 16;
                mly_uint64_t patch =  pField->value.u_version & 0x000000000000FFFF;
                fprintf(pFile, "%s = %llu.%llu.%llu\n", pField->key, major, minor, patch);
                break;
            }
            case MLY_INI_TYPE_BOOL:
                fprintf(pFile, "%s = %s\n", pField->key, pField->value.u_bool ? "true" : "false");
                break;
            case MLY_INI_TYPE_STRING:
                fprintf(pFile, "%s = %s\n", pField->key, pField->value.u_string);
                break;
        }
    }

    MLYAPI MLY_IniFile* MLYCALL MLY_IniOpenFile(const char* pFilename, MLY_IniFileFlags flags)
    {
        if (pFilename == NULL)
        {
            mly__ini_error("pFilename must not be NULL!");
            return NULL;
        }
        if (((flags & MLY_INI_FILE_FLAGS_DEFAULT) && (flags & ~(MLY_INI_FILE_FLAGS_DEFAULT)))
            || ((flags & MLY_INI_FILE_FLAGS_CREATE_IF_MISSING) && (~flags & (MLY_INI_FILE_FLAGS_READ)))
            || ((flags & MLY_INI_FILE_FLAGS_EMPTY) && (flags & ~MLY_INI_FILE_FLAGS_EMPTY)))
        {
            mly__ini_error("Invalid flag combination");
            return NULL;
        }
        if (flags == MLY_INI_FILE_FLAGS_DEFAULT)
        {
            flags = MLY_INI_FILE_FLAGS_READ | MLY_INI_FILE_FLAGS_CREATE_IF_MISSING;
        }
        if (flags & MLY_INI_FILE_FLAGS_READ)
        {
            MLY_IniFile* iniFile = mly__ini_create_file();
            if (iniFile == NULL)
            {
                return NULL;
            }
            iniFile->name = pFilename;
            if (!mly__ini_read_file(iniFile, pFilename))
            {
                if (flags & MLY_INI_FILE_FLAGS_CREATE_IF_MISSING)
                {
                    if (fopen_s(&iniFile->file, pFilename, "wb+") != 0)
                    {
                        MLY_IniCloseFile(iniFile);
                        return NULL;
                    }
                }
                else
                {
                    MLY_IniCloseFile(iniFile);
                    return NULL;
                }
            }
            else
            {
                if (!mly__ini_lex_file(iniFile))
                {
                    MLY_IniCloseFile(iniFile);
                    return NULL;
                }
                if (!mly__ini_parse_file(iniFile))
                {
                    MLY_IniCloseFile(iniFile);
                    return NULL;
                }
            }
            return iniFile;
        }
        else if (flags & MLY_INI_FILE_FLAGS_EMPTY)
        {
            MLY_IniFile* iniFile = mly__ini_create_file();

            if (iniFile == NULL)
            {
                return NULL;
            }

            return iniFile;
        }
        mly__ini_error("Unknown file mode!");
        return NULL;
    }

    MLYAPI MLY_IniField* MLYCALL MLY_IniFileGetGlobal(MLY_IniFile* pIniFile, const char* pName)
    {
        return MLY_IniGetField(pIniFile->globals, pName);
    }

    MLYAPI mly_bool_t MLYCALL MLY_IniFileAddSection(MLY_IniFile* pIniFile, MLY_IniSection* pSection)
    {
        return MLY_IniAddSection(pIniFile->sections, pSection);
    }

    MLYAPI MLY_IniSection* MLYCALL MLY_IniFileGetSection(MLY_IniFile* pIniFile, const char* pName, bool createIfMissing)
    {
        MLY_IniSection* section = MLY_IniGetSection(pIniFile->sections, pName);
        if (section == NULL && createIfMissing)
        {
            section = MLY_IniCreateSection(pName);
            MLY_IniFileAddSection(pIniFile, section);
        }
        return section;
    }

    MLYAPI mly_bool_t MLYCALL MLY_IniCommitFile(MLY_IniFile* pIniFile)
    {
        if (pIniFile == NULL)
        {
            mly__ini_error("pIniFile must not be NULL!");
            return false;
        }
        if (pIniFile->file != NULL)
        {
            fclose(pIniFile->file);
        }
        if (fopen_s(&pIniFile->file, pIniFile->name, "w") != 0)
        {
            mly__ini_error("Failed to open file for writing.");
            return false;
        }
        /* Checks if there are any global fields to avoid writing the newline at the end */
        if (pIniFile->globals->length > 0)
        {
            for (mly_uint32_t i = 0; i < pIniFile->globals->length; ++i)
            {
                MLY_IniField* field = pIniFile->globals->data[i];
                mly__ini_write_field_to_file(pIniFile->file, field);
            }

            fprintf(pIniFile->file, "\n");
        }

        for (mly_uint32_t i = 0; i < pIniFile->sections->length; ++i)
        {
            MLY_IniSection* section = pIniFile->sections->data[i];
            fprintf(pIniFile->file, "[%s]\n", section->name);
            for (mly_uint32_t j = 0; j < section->fields->length; ++j)
            {
                MLY_IniField* field = section->fields->data[j];
                mly__ini_write_field_to_file(pIniFile->file, field);
            }
            if (i < pIniFile->sections->length - 1) fprintf(pIniFile->file, "\n");
        }

        return true;
    }

    MLYAPI void MLYCALL MLY_IniCloseFile(MLY_IniFile* pIniFile)
    {
        if (pIniFile == NULL) return;
        if (pIniFile->sections != NULL)
        {
            MLY_IniDestroySectionList(pIniFile->sections);
        }
        if (pIniFile->globals != NULL)
        {
            MLY_IniDestroyFieldList(pIniFile->globals);
        }
        if (pIniFile->file != NULL)
        {
            fclose(pIniFile->file);
            pIniFile->file = NULL;
        }
        MLY_FREE(pIniFile);
    }

    MLYAPI MLY_IniFieldList* MLYCALL MLY_IniCreateFieldList(void)
    {
        MLY_IniFieldList* list = MLY_MALLOC_T(MLY_IniFieldList);
        if (list == NULL)
        {
            mly__ini_error("Failed to allocate IniFieldList.");
            return NULL;
        }
        memset(list, 0, sizeof(MLY_IniFieldList));
        list->capacity = sizeof(MLY_IniField*) * MLY_INI_FIELD_LIST_INITIAL_CAPACITY;
        list->data = MLY_CALLOC_T(MLY_IniField*, MLY_INI_FIELD_LIST_INITIAL_CAPACITY);
        if (list->data == NULL)
        {
            mly__ini_error("Failed to allocate data buffer.");
            MLY_FREE(list);
            return NULL;
        }
        memset(list->data, NULL, list->capacity);
        return list;
    }

    MLYAPI void MLYCALL MLY_IniDestroyFieldList(MLY_IniFieldList* pFieldList)
    {
        if (pFieldList == NULL) return;
        for (mly_size_t i = 0; i < pFieldList->length; ++i)
        {
            MLY_IniField* field = pFieldList->data[i];
            MLY_IniDestroyField(field);
        }
        MLY_FREE(pFieldList);
    }

    MLYAPI MLY_IniSectionList* MLYCALL MLY_IniCreateSectionList(void)
    {
        MLY_IniSectionList* list = MLY_MALLOC_T(MLY_IniSectionList);
        if (list == NULL)
        {
            mly__ini_error("Failed to allocate IniSectionList.");
            return NULL;
        }
        memset(list, 0, sizeof(MLY_IniSectionList));
        list->capacity = sizeof(MLY_IniSection*) * MLY_INI_SECTION_LIST_INITIAL_CAPACITY;
        list->data = MLY_CALLOC_T(MLY_IniSection*, MLY_INI_SECTION_LIST_INITIAL_CAPACITY);
        if (list->data == NULL)
        {
            mly__ini_error("Failed to allocate data buffer.");
            MLY_FREE(list);
            return NULL;
        }
        memset(list->data, NULL, list->capacity);
        return list;
    }

    MLYAPI void MLYCALL MLY_IniDestroySectionList(MLY_IniSectionList* pSectionList)
    {
        if (pSectionList == NULL) return;
        if (pSectionList->data != NULL)
        {
            for (mly_size_t i = 0; i < pSectionList->length; ++i)
            {
                MLY_IniSection* section = pSectionList->data[i];
                if (section != NULL) MLY_IniDestroySection(section);
            }
            MLY_FREE(pSectionList->data);
        }
        MLY_FREE(pSectionList);
    }

    MLYAPI MLY_IniSection* MLYCALL MLY_IniCreateSection(const char* pName)
    {
        if (pName == NULL)
        {
            mly__ini_error("pName cannot be NULL!");
            return NULL;
        }
        MLY_IniSection* section = MLY_MALLOC_T(MLY_IniSection);
        if (section == NULL)
        {
            mly__ini_error("Failed to allocate IniSection.");
            return NULL;
        }
        memset(section, 0, sizeof(MLY_IniSection));
        mly_size_t nameLength = strlen(pName) + 1;
        section->name = MLY_CALLOC_T(char, nameLength);
        if (section->name == NULL)
        {
            mly__ini_error("Failed to allocate IniSection name buffer.");
            MLY_FREE(section);
            return NULL;
        }
        memcpy(section->name, pName, nameLength);
        section->fields = MLY_IniCreateFieldList();
        if (section->fields == NULL)
        {
            MLY_FREE(section->name);
            MLY_FREE(section);
            return NULL;
        }
        return section;
    }

    MLYAPI void MLYCALL MLY_IniDestroySection(MLY_IniSection* pSection)
    {
        if (pSection == NULL) return;
        if (pSection != NULL)
        {
            MLY_FREE(pSection->name);
        }
        if (pSection->fields != NULL)
        {
            MLY_IniDestroyFieldList(pSection->fields);
        }
        MLY_FREE(pSection);
    }

    MLYAPI mly_bool_t MLYCALL MLY_IniAddSection(MLY_IniSectionList* pSectionList, MLY_IniSection* pSection)
    {
        if (pSectionList == NULL)
        {
            mly__ini_error("pSectionList must not be NULL!");
            return false;
        }
        if (pSection == NULL)
        {
            mly__ini_error("pSection must not be NULL!");
            return false;
        }
        mly_size_t bytesSize = pSectionList->length * sizeof(MLY_IniSection*);
        if (bytesSize >= pSectionList->capacity)
        {
            mly_size_t capacity = pSectionList->capacity;
            do
            {
                capacity <<= 1;
            } while (bytesSize >= capacity);

            MLY_IniSection** sections = MLY_REALLOC_T(MLY_IniSection*, pSectionList->data, capacity);
            if (sections == NULL)
            {
                mly__ini_error("Failed not reallocate sections list.");
                return false;
            }
            pSectionList->data = sections;
            pSectionList->capacity = capacity;
        }
        pSectionList->data[pSectionList->length++] = pSection;
        return true;
    }

    MLYAPI MLY_IniSection* MLYCALL MLY_IniGetSection(MLY_IniSectionList* pSectionList, const char* pName)
    {
        if (pSectionList == NULL)
        {
            mly__ini_error("pSectionList must not be NULL");
            return NULL;
        }
        if (pName == NULL)
        {
            mly__ini_error("pName must not be NULL");
            return NULL;
        }
        if (strlen(pName) == 0)
        {
            mly__ini_error("pName cannot be empty!");
            return NULL;
        }

        for (mly_size_t i = 0; i < pSectionList->length; ++i)
        {
            MLY_IniSection* section = pSectionList->data[i];
            if (section != NULL && strcmp(section->name, pName) == 0)
            {
                return section;
            }
        }

        mly__ini_error("Could not find an IniSection with the provided name.");

        return NULL;
    }

    MLYAPI MLY_IniField* MLYCALL MLY_IniSectionGetField(MLY_IniSection* pSection, const char* pName, bool createIfMissing)
    {
        MLY_IniField* field = MLY_IniGetField(pSection->fields, pName);
        if (field == NULL && createIfMissing)
        {
            field = MLY_IniCreateField(pName, MLY_INI_TYPE_INT, NULL);
            MLY_IniSectionAddField(pSection, field);
        }
        return field;
    }

    MLYAPI mly_bool_t MLYCALL MLY_IniSectionAddField(MLY_IniSection* pSection, MLY_IniField* pField)
    {
        return MLY_IniAddField(pSection->fields, pField);
    }

    MLYAPI MLY_IniField* MLYCALL MLY_IniCreateField(const char* pName, MLY_IniFieldType fieldType, void* pData)
    {
        if (pName == NULL)
        {
            mly__ini_error("pName cannot be NULL!");
            return NULL;
        }
        MLY_IniField* field = MLY_MALLOC_T(MLY_IniField);
        if (field == NULL)
        {
            mly__ini_error("Failed to allocate IniField.");
            return NULL;
        }
        memset(field, 0, sizeof(MLY_IniField));
        mly_size_t nameLength = strlen(pName) + 1;
        field->key = MLY_CALLOC_T(char, nameLength);
        if (field->key == NULL)
        {
            mly__ini_error("Failed to allocate IniField name buffer.");
            MLY_FREE(field);
            return NULL;
        }
        memcpy(field->key, pName, nameLength);
        field->type = fieldType;
        if (pData != NULL)
        {
            switch (fieldType)
            {
                case MLY_INI_TYPE_INT:      field->value.u_int = MLY_REINTERPRET(mly_int64_t, pData);       break;
                case MLY_INI_TYPE_DOUBLE:   field->value.u_double = MLY_REINTERPRET(double, pData);         break;
                case MLY_INI_TYPE_VERSION:  field->value.u_version = MLY_REINTERPRET(mly_version_t, pData); break;
                case MLY_INI_TYPE_BOOL:     field->value.u_bool = MLY_REINTERPRET(mly_bool_t, pData);       break;
                default:
                    mly__ini_error("Unknown field type.");
                    MLY_FREE(field->key);
                    MLY_FREE(field);
                    return NULL;
            }
        }
        return field;
    }

    MLYAPI void MLYCALL MLY_IniDestroyField(MLY_IniField* pField)
    {
        if (pField == NULL) return;
        if (pField->key != NULL) MLY_FREE(pField->key);
        MLY_FREE(pField);
    }

    MLYAPI mly_bool_t MLYCALL MLY_IniAddField(MLY_IniFieldList* pFieldList, MLY_IniField* pField)
    {
        if (pFieldList == NULL)
        {
            mly__ini_error("pFieldList must not be NULL!");
            return false;
        }
        if (pField == NULL)
        {
            mly__ini_error("pField must not be NULL!");
            return false;
        }
        mly_size_t sizeBytes = pFieldList->length * sizeof(MLY_IniField*);
        if (sizeBytes >= pFieldList->capacity)
        {
            mly_size_t capacity = pFieldList->capacity;
            do
            {
                capacity <<= 1;
            } while (sizeBytes >= capacity);

            MLY_IniField** data = MLY_REALLOC_T(MLY_IniField*, pFieldList->data, capacity);
            if (data == NULL)
            {
                mly__ini_error("Failed to reallocate field list.");
                MLY_FREE(pField->key);
                MLY_FREE(pField);
                return false;
            }
            pFieldList->data = data;
            pFieldList->capacity = capacity;
        }
        pFieldList->data[pFieldList->length++] = pField;
        return true;
    }

    MLYAPI MLY_IniField* MLYCALL MLY_IniGetField(MLY_IniFieldList* pFieldList, const char* pName)
    {
        if (pFieldList == NULL)
        {
            mly__ini_error("pFieldList must not be NULL!");
            return NULL;
        }
        if (pName == NULL)
        {
            mly__ini_error("pName must not be NULL!");
            return NULL;
        }
        if (strlen(pName) == 0)
        {
            mly__ini_error("pName must not be empty!");
            return NULL;
        }

        for (mly_size_t i = 0; i < pFieldList->length; ++i)
        {
            MLY_IniField* field = pFieldList->data[i];
            if (strcmp(field->key, pName) == 0)
            {
                return field;
            }
        }

        mly__ini_error("Could not find a field with the given name.");

        return NULL;
    }

    MLYAPI mly_int64_t MLYCALL MLY_IniFieldGetInt(MLY_IniField* pField)
    {
        if (pField == NULL || pField->type == MLY_INI_TYPE_STRING) return 0;
        switch (pField->type)
        {
            case MLY_INI_TYPE_INT:          return pField->value.u_int;
            case MLY_INI_TYPE_DOUBLE:       return MLY_CAST(mly_int64_t, pField->value.u_double);
            case MLY_INI_TYPE_VERSION:      return MLY_CAST(mly_int64_t, pField->value.u_version);
            case MLY_INI_TYPE_VERSION_LONG: return MLY_CAST(mly_int64_t, pField->value.u_longVersion);
            case MLY_INI_TYPE_BOOL:         return pField->value.u_bool ? 1 : 0;
            default:                        return 0;
        }
    }

    MLYAPI double MLYCALL MLY_IniFieldGetDouble(MLY_IniField* pField)
    {
        if (pField == NULL || pField->type == MLY_INI_TYPE_STRING) return 0.0;
        switch (pField->type)
        {
            case MLY_INI_TYPE_INT:          return MLY_CAST(double, pField->value.u_int);
            case MLY_INI_TYPE_DOUBLE:       return pField->value.u_double;
            case MLY_INI_TYPE_VERSION:      return MLY_CAST(double, pField->value.u_version);
            case MLY_INI_TYPE_VERSION_LONG: return MLY_CAST(double, pField->value.u_longVersion);
            case MLY_INI_TYPE_BOOL:         return pField->value.u_bool ? 1.0 : 0.0;
            default:                        return 0.0;
        }
    }

    MLYAPI mly_version_t MLYCALL MLY_IniFieldGetVersion(MLY_IniField* pField)
    {
        if (pField == NULL || pField->type != MLY_INI_TYPE_VERSION) return 0;
        return pField->value.u_version;
    }

    MLYAPI mly_long_version_t MLYCALL MLY_IniFieldGetVersionLong(MLY_IniField* pField)
    {
        if (pField == NULL || pField->type != MLY_INI_TYPE_VERSION_LONG) return 0;
        return pField->value.u_longVersion;
    }

    MLYAPI mly_bool_t MLYCALL MLY_IniFieldGetBool(MLY_IniField* pField)
    {
        if (pField == NULL || pField->type == MLY_INI_TYPE_STRING) return false;
        return pField->value.u_bool;
    }

    MLYAPI const char* MLYCALL MLY_IniFieldGetString(MLY_IniField* pField)
    {
        if (pField == NULL || pField->type != MLY_INI_TYPE_STRING || pField->value.u_string) return "";
        return pField->value.u_string;
    }

    void MLYCALL MLY_IniFieldSetInt(MLY_IniField* pField, mly_int64_t value)
    {
        if (pField == NULL) return;
        if (pField->type == MLY_INI_TYPE_STRING && pField->value.u_string) MLY_FREE(pField->value.u_string);
        pField->value.u_int = value;
        pField->type = MLY_INI_TYPE_INT;
    }

    void MLYCALL MLY_IniFieldSetDouble(MLY_IniField* pField, double value)
    {
        if (pField == NULL) return;
        if (pField->type == MLY_INI_TYPE_STRING && pField->value.u_string) MLY_FREE(pField->value.u_string);
        pField->value.u_double = value;
        pField->type = MLY_INI_TYPE_DOUBLE;
    }

    void MLYCALL MLY_IniFieldSetVersion(MLY_IniField* pField, mly_version_t value)
    {
        if (pField == NULL) return;
        if (pField->type == MLY_INI_TYPE_STRING && pField->value.u_string) MLY_FREE(pField->value.u_string);
        pField->value.u_version = value;
        pField->type = MLY_INI_TYPE_VERSION;
    }

    void MLYCALL MLY_IniFieldSetVersionLong(MLY_IniField* pField, mly_long_version_t value)
    {
        if (pField == NULL) return;
        if (pField->type == MLY_INI_TYPE_STRING && pField->value.u_string) MLY_FREE(pField->value.u_string);
        pField->value.u_longVersion = value;
        pField->type = MLY_INI_TYPE_VERSION;
    }

    void MLYCALL MLY_IniFieldSetBool(MLY_IniField* pField, mly_bool_t value)
    {
        if (pField == NULL) return;
        if (pField->type == MLY_INI_TYPE_STRING && pField->value.u_string) MLY_FREE(pField->value.u_string);
        pField->value.u_bool = value;
        pField->type = MLY_INI_TYPE_BOOL;
    }

    void MLYCALL MLY_IniFieldSetString(MLY_IniField* pField, const char* value)
    {
        if (pField == NULL) return;
        mly_size_t valueLength = strlen(value) + 1;
        if (pField->type == MLY_INI_TYPE_STRING && pField->value.u_string != NULL)
        {
            char* buffer = MLY_REALLOC_T(char, pField->value.u_string, valueLength);
            if (buffer == NULL) return;
            pField->value.u_string = buffer;
        }
        else
        {
            pField->value.u_string = MLY_CALLOC_T(char, valueLength);
            if (pField->value.u_string == NULL) return;
            memcpy(pField->value.u_string, value, valueLength);
        }
        pField->type = MLY_INI_TYPE_STRING;
    }

#ifdef __cplusplus__
    }
#endif

#endif /* MLY_INI_IMPLEMENTATION */
