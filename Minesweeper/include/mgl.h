#ifndef MANLY_GL_H
#define MANLY_GL_H

#ifdef __gl_h_
    #error OpenGL header already included, please remove it before continuing.
#endif /* __gl_h_ */

#define __gl_h_

#ifndef GLAPI
    #define GLAPI extern
#endif /* GLAPI */

#ifndef APIENTRY
    #if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
        #define APIENTRY __stdcall
    #else
        #define APIENTRY
    #endif /* _WIN32 */
#endif /* APIENTRY */

#ifndef APIENTRYP
    #define APIENTRYP APIENTRY*
#endif /* APIENTRYP */

#ifndef NULL
    #define NULL ((void*)0)
#endif /* NULL */

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

typedef void* (*mgl_loadProc_t)(const char* name);

GLAPI int mglLoadGLLoader(mgl_loadProc_t load_function);

/*
** Copyright (c) 2008-2018 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
**
** --- MODIFICATION NOTICE ---
** This section contains modified types and definitions derived from the
** original khrplatform.h header. Unused types and platform definitions
** have been slightly stripped down for a custom single-header implementation.
*/

#ifndef __khrplatform_h_
#define __khrplatform_h_

typedef signed char                 khronos_int8_t;
typedef unsigned char               khronos_uint8_t;
typedef signed short                khronos_int16_t;
typedef unsigned short              khronos_uint16_t;

#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)
    #include <stdint.h>
    typedef int32_t                 khronos_int32_t;
    typedef int64_t                 khronos_int64_t;
    typedef uint64_t                khronos_uint64_t;
    #define KHRONOS_SUPPORT_FLOAT 1
    #if defined(__SIZEOF_LONG__) && defined(__SIZEOF_POINTER__)
        #if __SIZEOF_POINTER__ > __SIZEOF_LONG__
            #define KHRONOS_USE_INTPTR_T
        #endif
    #endif
#elif defined(__VMS) || defined(__sgi)
    #include <inttypes.h>
    typedef int32_t                 khronos_int32_t;
    typedef int64_t                 khronos_int64_t;
    typedef uint64_t                khronos_uint64_t;
    #define KHRONOS_SUPPORT_FLOAT 1
#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)
    typedef signed __int32          khronos_int32_t;
    typedef signed __int64          khronos_int64_t;
    typedef unsigned __int64        khronos_uint64_t;
    #define KHRONOS_SUPPORT_FLOAT 1
#elif defined(__sun__) || defined(__digital__)
    typedef signed int              khronos_int32_t;
    #if (__arch64__) || defined(_LP64)
        typedef signed long         khronos_int64_t;
        typedef unsigned long       khronos_uint64_t;
    #else
        typedef signed long long    khronos_int64_t;
        typedef unsigned long long  khronos_uint64_t;
    #endif
    #define KHRONOS_SUPPORT_FLOAT 1
#elif 0
    typedef signed int              khronos_int32_t;
    typedef unsigned int            khronos_uint32_t;
    #define KHRONOS_SUPPORT_FLOAT 0
#else
    #include <stdint.h>
    typedef int32_t                 khronos_int32_t;
    typedef int64_t                 khronos_int64_t;
    typedef uint64_t                khronos_uint64_t;
    #define KHRONOS_SUPPORT_FLOAT 1
#endif

#ifdef KHRONOS_USE_INTPTR_T
    typedef intptr_t                khronos_intptr_t;
    typedef uintptr_t               khronos_uintptr_t;
#elif defined(_WIN64)
    typedef signed long long        khronos_intptr_t;
    typedef unsigned long long      khronos_uintptr_t;
#else
    typedef signed long             khronos_intptr_t;
    typedef unsigned long           khronos_uintptr_t;
#endif /* KHRONOS_USE_INTPTR_T */

#if defined(_WIN64)
    typedef signed long long        khronos_ssize_t;
#else
    typedef signed long             khronos_ssize_t;
#endif /* _WIN64 */

#if KHRONOS_SUPPORT_FLOAT
    typedef float                   khronos_float_t;
#endif /* KHRONOS_SUPPORT_FLOAT */

#endif /* __khrplatform_h_ */

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid; /* Not an actual GL type, though used in headers in the past */
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef khronos_int32_t GLclampx;
typedef int GLsizei;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglClientBufferEXT;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef khronos_uint16_t GLhalf;
typedef khronos_uint16_t GLhalfARB;
typedef khronos_int32_t GLfixed;
typedef khronos_intptr_t GLintptr;
typedef khronos_intptr_t GLintptrARB;
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_ssize_t GLsizeiptrARB;
typedef khronos_int64_t GLint64;
typedef khronos_int64_t GLint64EXT;
typedef khronos_uint64_t GLuint64;
typedef khronos_uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context; /* compatible with OpenCL cl_context */
struct _cl_event; /* compatible with OpenCL cl_event */
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
typedef void (APIENTRY *GLVULKANPROCNV)(void);

#define GL_DEPTH_BUFFER_BIT 0x00000100 /* AttribMask */
#define GL_STENCIL_BUFFER_BIT 0x00000400 /* AttribMask */
#define GL_COLOR_BUFFER_BIT 0x00004000 /* AttribMask */
#define GL_FALSE 0 /* SpecialNumbers */
#define GL_TRUE 1 /* SpecialNumbers */
#define GL_POINTS 0x0000 /* PrimitiveType */
#define GL_LINES 0x0001 /* PrimitiveType */
#define GL_LINE_LOOP 0x0002 /* PrimitiveType */
#define GL_LINE_STRIP 0x0003 /* PrimitiveType */
#define GL_TRIANGLES 0x0004 /* PrimitiveType */
#define GL_TRIANGLE_STRIP 0x0005 /* PrimitiveType */
#define GL_TRIANGLE_FAN 0x0006 /* PrimitiveType */
#define GL_QUADS 0x0007 /* PrimitiveType */
#define GL_NEVER 0x0200 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_LESS 0x0201 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_EQUAL 0x0202 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_LEQUAL 0x0203 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_GREATER 0x0204 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_NOTEQUAL 0x0205 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_GEQUAL 0x0206 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_ALWAYS 0x0207 /* StencilFunction, IndexFunctionEXT, AlphaFunction, DepthFunction */
#define GL_ZERO 0 /* SpecialNumbers */
#define GL_ONE 1 /* SpecialNumbers */
#define GL_SRC_COLOR 0x0300 /* BlendingFactor */
#define GL_ONE_MINUS_SRC_COLOR 0x0301 /* BlendingFactor */
#define GL_SRC_ALPHA 0x0302 /* BlendingFactor */
#define GL_ONE_MINUS_SRC_ALPHA 0x0303 /* BlendingFactor */
#define GL_DST_ALPHA 0x0304 /* BlendingFactor */
#define GL_ONE_MINUS_DST_ALPHA 0x0305 /* BlendingFactor */
#define GL_DST_COLOR 0x0306 /* BlendingFactor */
#define GL_ONE_MINUS_DST_COLOR 0x0307 /* BlendingFactor */
#define GL_SRC_ALPHA_SATURATE 0x0308 /* BlendingFactor */
#define GL_NONE 0 /* SpecialNumbers */
#define GL_FRONT_LEFT 0x0400 /* ColorBuffer, DrawBufferMode, ReadBufferMode */
#define GL_FRONT_RIGHT 0x0401 /* ColorBuffer, DrawBufferMode, ReadBufferMode */
#define GL_BACK_LEFT 0x0402 /* ColorBuffer, DrawBufferMode, ReadBufferMode */
#define GL_BACK_RIGHT 0x0403 /* ColorBuffer, DrawBufferMode, ReadBufferMode */
#define GL_FRONT 0x0404 /* ColorBuffer, DrawBufferMode, ReadBufferMode, TriangleFace */
#define GL_BACK 0x0405 /* ColorBuffer, DrawBufferMode, ReadBufferMode, TriangleFace */
#define GL_LEFT 0x0406 /* ColorBuffer, DrawBufferMode, ReadBufferMode */
#define GL_RIGHT 0x0407 /* ColorBuffer, DrawBufferMode, ReadBufferMode */
#define GL_FRONT_AND_BACK 0x0408 /* ColorBuffer, DrawBufferMode, TriangleFace */
#define GL_NO_ERROR 0 /* SpecialNumbers */
#define GL_INVALID_ENUM 0x0500 /* ErrorCode */
#define GL_INVALID_VALUE 0x0501 /* ErrorCode */
#define GL_INVALID_OPERATION 0x0502 /* ErrorCode */
#define GL_OUT_OF_MEMORY 0x0505 /* ErrorCode */
#define GL_CW 0x0900 /* FrontFaceDirection */
#define GL_CCW 0x0901 /* FrontFaceDirection */
#define GL_POINT_SIZE 0x0B11 /* GetPName */
#define GL_POINT_SIZE_RANGE 0x0B12 /* GetPName */
#define GL_POINT_SIZE_GRANULARITY 0x0B13 /* GetPName */
#define GL_LINE_SMOOTH 0x0B20 /* GetPName, EnableCap */
#define GL_LINE_WIDTH 0x0B21 /* GetPName */
#define GL_LINE_WIDTH_RANGE 0x0B22 /* GetPName */
#define GL_LINE_WIDTH_GRANULARITY 0x0B23 /* GetPName */
#define GL_POLYGON_MODE 0x0B40 /* GetPName */
#define GL_POLYGON_SMOOTH 0x0B41 /* GetPName, EnableCap */
#define GL_CULL_FACE 0x0B44 /* GetPName, EnableCap */
#define GL_CULL_FACE_MODE 0x0B45 /* GetPName */
#define GL_FRONT_FACE 0x0B46 /* GetPName */
#define GL_DEPTH_RANGE 0x0B70 /* GetPName */
#define GL_DEPTH_TEST 0x0B71 /* GetPName, EnableCap */
#define GL_DEPTH_WRITEMASK 0x0B72 /* GetPName */
#define GL_DEPTH_CLEAR_VALUE 0x0B73 /* GetPName */
#define GL_DEPTH_FUNC 0x0B74 /* GetPName */
#define GL_STENCIL_TEST 0x0B90 /* GetPName, EnableCap */
#define GL_STENCIL_CLEAR_VALUE 0x0B91 /* GetPName */
#define GL_STENCIL_FUNC 0x0B92 /* GetPName */
#define GL_STENCIL_VALUE_MASK 0x0B93 /* GetPName */
#define GL_STENCIL_FAIL 0x0B94 /* GetPName */
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95 /* GetPName */
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96 /* GetPName */
#define GL_STENCIL_REF 0x0B97 /* GetPName */
#define GL_STENCIL_WRITEMASK 0x0B98 /* GetPName */
#define GL_VIEWPORT 0x0BA2 /* GetPName */
#define GL_DITHER 0x0BD0 /* GetPName, EnableCap */
#define GL_BLEND_DST 0x0BE0 /* GetPName */
#define GL_BLEND_SRC 0x0BE1 /* GetPName */
#define GL_BLEND 0x0BE2 /* TextureEnvMode, EnableCap, GetPName */
#define GL_LOGIC_OP_MODE 0x0BF0 /* GetPName */
#define GL_DRAW_BUFFER 0x0C01 /* GetPName */
#define GL_READ_BUFFER 0x0C02 /* GetPName */
#define GL_SCISSOR_BOX 0x0C10 /* GetPName */
#define GL_SCISSOR_TEST 0x0C11 /* GetPName, EnableCap */
#define GL_COLOR_CLEAR_VALUE 0x0C22 /* GetPName */
#define GL_COLOR_WRITEMASK 0x0C23 /* GetPName */
#define GL_DOUBLEBUFFER 0x0C32 /* GetFramebufferParameter, GetPName */
#define GL_STEREO 0x0C33 /* GetFramebufferParameter, GetPName */
#define GL_LINE_SMOOTH_HINT 0x0C52 /* HintTarget, GetPName */
#define GL_POLYGON_SMOOTH_HINT 0x0C53 /* HintTarget, GetPName */
#define GL_UNPACK_SWAP_BYTES 0x0CF0 /* PixelStoreParameter, GetPName */
#define GL_UNPACK_LSB_FIRST 0x0CF1 /* PixelStoreParameter, GetPName */
#define GL_UNPACK_ROW_LENGTH 0x0CF2 /* PixelStoreParameter, GetPName */
#define GL_UNPACK_SKIP_ROWS 0x0CF3 /* PixelStoreParameter, GetPName */
#define GL_UNPACK_SKIP_PIXELS 0x0CF4 /* PixelStoreParameter, GetPName */
#define GL_UNPACK_ALIGNMENT 0x0CF5 /* PixelStoreParameter, GetPName */
#define GL_PACK_SWAP_BYTES 0x0D00 /* PixelStoreParameter, GetPName */
#define GL_PACK_LSB_FIRST 0x0D01 /* PixelStoreParameter, GetPName */
#define GL_PACK_ROW_LENGTH 0x0D02 /* PixelStoreParameter, GetPName */
#define GL_PACK_SKIP_ROWS 0x0D03 /* PixelStoreParameter, GetPName */
#define GL_PACK_SKIP_PIXELS 0x0D04 /* PixelStoreParameter, GetPName */
#define GL_PACK_ALIGNMENT 0x0D05 /* PixelStoreParameter, GetPName */
#define GL_MAX_TEXTURE_SIZE 0x0D33 /* GetPName */
#define GL_MAX_VIEWPORT_DIMS 0x0D3A /* GetPName */
#define GL_SUBPIXEL_BITS 0x0D50 /* GetPName */
#define GL_TEXTURE_1D 0x0DE0 /* CopyImageSubDataTarget, EnableCap, GetPName, TextureTarget */
#define GL_TEXTURE_2D 0x0DE1 /* CopyImageSubDataTarget, EnableCap, GetPName, TextureTarget */
#define GL_TEXTURE_WIDTH 0x1000 /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_HEIGHT 0x1001 /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_BORDER_COLOR 0x1004 /* SamplerParameterF, GetTextureParameter, TextureParameterName */
#define GL_DONT_CARE 0x1100 /* DebugSeverity, HintMode, DebugSource, DebugType */
#define GL_FASTEST 0x1101 /* HintMode */
#define GL_NICEST 0x1102 /* HintMode */
#define GL_BYTE 0x1400 /* VertexAttribIType, WeightPointerTypeARB, TangentPointerTypeEXT, BinormalPointerTypeEXT, ColorPointerType, ListNameType, NormalPointerType, PixelType, VertexAttribType, VertexAttribPointerType */
#define GL_UNSIGNED_BYTE 0x1401 /* VertexAttribIType, ScalarType, ReplacementCodeTypeSUN, ElementPointerTypeATI, MatrixIndexPointerTypeARB, WeightPointerTypeARB, ColorPointerType, DrawElementsType, ListNameType, PixelType, VertexAttribType, VertexAttribPointerType */
#define GL_SHORT 0x1402 /* VertexAttribIType, SecondaryColorPointerTypeIBM, WeightPointerTypeARB, TangentPointerTypeEXT, BinormalPointerTypeEXT, ColorPointerType, IndexPointerType, ListNameType, NormalPointerType, PixelType, TexCoordPointerType, VertexPointerType, VertexAttribType, VertexAttribPointerType */
#define GL_UNSIGNED_SHORT 0x1403 /* VertexAttribIType, ScalarType, ReplacementCodeTypeSUN, ElementPointerTypeATI, MatrixIndexPointerTypeARB, WeightPointerTypeARB, ColorPointerType, DrawElementsType, ListNameType, PixelFormat, PixelType, VertexAttribType, VertexAttribPointerType */
#define GL_INT 0x1404 /* VertexAttribIType, SecondaryColorPointerTypeIBM, WeightPointerTypeARB, TangentPointerTypeEXT, BinormalPointerTypeEXT, ColorPointerType, IndexPointerType, ListNameType, NormalPointerType, PixelType, TexCoordPointerType, VertexPointerType, VertexAttribType, AttributeType, UniformType, VertexAttribPointerType */
#define GL_UNSIGNED_INT 0x1405 /* VertexAttribIType, ScalarType, ReplacementCodeTypeSUN, ElementPointerTypeATI, MatrixIndexPointerTypeARB, WeightPointerTypeARB, ColorPointerType, DrawElementsType, ListNameType, PixelFormat, PixelType, VertexAttribType, AttributeType, UniformType, VertexAttribPointerType */
#define GL_FLOAT 0x1406 /* MapTypeNV, SecondaryColorPointerTypeIBM, WeightPointerTypeARB, VertexWeightPointerTypeEXT, TangentPointerTypeEXT, BinormalPointerTypeEXT, ColorPointerType, FogCoordinatePointerType, FogPointerTypeEXT, FogPointerTypeIBM, IndexPointerType, ListNameType, NormalPointerType, PixelType, TexCoordPointerType, VertexPointerType, VertexAttribType, AttributeType, UniformType, VertexAttribPointerType */
#define GL_STACK_OVERFLOW 0x0503 /* ErrorCode */
#define GL_STACK_UNDERFLOW 0x0504 /* ErrorCode */
#define GL_CLEAR 0x1500 /* LogicOp */
#define GL_AND 0x1501 /* LogicOp */
#define GL_AND_REVERSE 0x1502 /* LogicOp */
#define GL_COPY 0x1503 /* LogicOp */
#define GL_AND_INVERTED 0x1504 /* LogicOp */
#define GL_NOOP 0x1505 /* LogicOp */
#define GL_XOR 0x1506 /* LogicOp */
#define GL_OR 0x1507 /* LogicOp */
#define GL_NOR 0x1508 /* LogicOp */
#define GL_EQUIV 0x1509 /* LogicOp */
#define GL_INVERT 0x150A /* PathFillMode, LogicOp, StencilOp */
#define GL_OR_REVERSE 0x150B /* LogicOp */
#define GL_COPY_INVERTED 0x150C /* LogicOp */
#define GL_OR_INVERTED 0x150D /* LogicOp */
#define GL_NAND 0x150E /* LogicOp */
#define GL_SET 0x150F /* LogicOp */
#define GL_TEXTURE 0x1702 /* ObjectIdentifier, MatrixMode */
#define GL_COLOR 0x1800 /* Buffer, PixelCopyType, InvalidateFramebufferAttachment */
#define GL_DEPTH 0x1801 /* Buffer, PixelCopyType, InvalidateFramebufferAttachment */
#define GL_STENCIL 0x1802 /* Buffer, PixelCopyType, InvalidateFramebufferAttachment */
#define GL_STENCIL_INDEX 0x1901 /* InternalFormat, PixelFormat, DepthStencilTextureMode */
#define GL_DEPTH_COMPONENT 0x1902 /* InternalFormat, PixelFormat, DepthStencilTextureMode */
#define GL_RED 0x1903 /* FragmentShaderValueRepATI, TextureSwizzle, PixelFormat, InternalFormat */
#define GL_GREEN 0x1904 /* FragmentShaderValueRepATI, TextureSwizzle, PixelFormat */
#define GL_BLUE 0x1905 /* FragmentShaderValueRepATI, TextureSwizzle, CombinerComponentUsageNV, PixelFormat */
#define GL_ALPHA 0x1906 /* PixelTexGenModeSGIX, FragmentShaderValueRepATI, TextureSwizzle, CombinerPortionNV, PathColorFormat, CombinerComponentUsageNV, PixelFormat */
#define GL_RGB 0x1907 /* PixelTexGenModeSGIX, CombinerPortionNV, PathColorFormat, CombinerComponentUsageNV, PixelFormat, InternalFormat */
#define GL_RGBA 0x1908 /* PixelTexGenModeSGIX, PathColorFormat, PixelFormat, InternalFormat */
#define GL_POINT 0x1B00 /* PolygonMode, MeshMode1, MeshMode2 */
#define GL_LINE 0x1B01 /* PolygonMode, MeshMode1, MeshMode2 */
#define GL_FILL 0x1B02 /* PolygonMode, MeshMode2 */
#define GL_KEEP 0x1E00 /* StencilOp */
#define GL_REPLACE 0x1E01 /* StencilOp, LightEnvModeSGIX, TextureEnvMode */
#define GL_INCR 0x1E02 /* StencilOp */
#define GL_DECR 0x1E03 /* StencilOp */
#define GL_VENDOR 0x1F00 /* StringName */
#define GL_RENDERER 0x1F01 /* StringName */
#define GL_VERSION 0x1F02 /* StringName */
#define GL_EXTENSIONS 0x1F03 /* StringName */
#define GL_NEAREST 0x2600 /* BlitFramebufferFilter, TextureMagFilter, TextureMinFilter */
#define GL_LINEAR 0x2601 /* BlitFramebufferFilter, FogMode, TextureMagFilter, TextureMinFilter */
#define GL_NEAREST_MIPMAP_NEAREST 0x2700 /* TextureMinFilter */
#define GL_LINEAR_MIPMAP_NEAREST 0x2701 /* TextureMinFilter */
#define GL_NEAREST_MIPMAP_LINEAR 0x2702 /* TextureMinFilter */
#define GL_LINEAR_MIPMAP_LINEAR 0x2703 /* TextureMinFilter */
#define GL_TEXTURE_MAG_FILTER 0x2800 /* SamplerParameterI, GetTextureParameter, TextureParameterName */
#define GL_TEXTURE_MIN_FILTER 0x2801 /* SamplerParameterI, GetTextureParameter, TextureParameterName */
#define GL_TEXTURE_WRAP_S 0x2802 /* SamplerParameterI, GetTextureParameter, TextureParameterName */
#define GL_TEXTURE_WRAP_T 0x2803 /* SamplerParameterI, GetTextureParameter, TextureParameterName */
#define GL_REPEAT 0x2901 /* TextureWrapMode */
#define GL_CURRENT_BIT 0x00000001 /* AttribMask */
#define GL_POINT_BIT 0x00000002 /* AttribMask */
#define GL_LINE_BIT 0x00000004 /* AttribMask */
#define GL_POLYGON_BIT 0x00000008 /* AttribMask */
#define GL_POLYGON_STIPPLE_BIT 0x00000010 /* AttribMask */
#define GL_PIXEL_MODE_BIT 0x00000020 /* AttribMask */
#define GL_LIGHTING_BIT 0x00000040 /* AttribMask */
#define GL_FOG_BIT 0x00000080 /* AttribMask */
#define GL_ACCUM_BUFFER_BIT 0x00000200 /* AttribMask */
#define GL_VIEWPORT_BIT 0x00000800 /* AttribMask */
#define GL_TRANSFORM_BIT 0x00001000 /* AttribMask */
#define GL_ENABLE_BIT 0x00002000 /* AttribMask */
#define GL_HINT_BIT 0x00008000 /* AttribMask */
#define GL_EVAL_BIT 0x00010000 /* AttribMask */
#define GL_LIST_BIT 0x00020000 /* AttribMask */
#define GL_TEXTURE_BIT 0x00040000 /* AttribMask */
#define GL_SCISSOR_BIT 0x00080000 /* AttribMask */
#define GL_ALL_ATTRIB_BITS 0xFFFFFFFF /* AttribMask */
#define GL_QUAD_STRIP 0x0008 /* PrimitiveType */
#define GL_POLYGON 0x0009 /* PrimitiveType */
#define GL_ACCUM 0x0100 /* AccumOp */
#define GL_LOAD 0x0101 /* AccumOp */
#define GL_RETURN 0x0102 /* AccumOp */
#define GL_MULT 0x0103 /* AccumOp */
#define GL_ADD 0x0104 /* TextureEnvMode, AccumOp, LightEnvModeSGIX */
#define GL_AUX0 0x0409 /* ReadBufferMode, DrawBufferMode */
#define GL_AUX1 0x040A /* ReadBufferMode, DrawBufferMode */
#define GL_AUX2 0x040B /* ReadBufferMode, DrawBufferMode */
#define GL_AUX3 0x040C /* ReadBufferMode, DrawBufferMode */
#define GL_2D 0x0600 /* FeedbackType */
#define GL_3D 0x0601 /* FeedbackType */
#define GL_3D_COLOR 0x0602 /* FeedbackType */
#define GL_3D_COLOR_TEXTURE 0x0603 /* FeedbackType */
#define GL_4D_COLOR_TEXTURE 0x0604 /* FeedbackType */
#define GL_PASS_THROUGH_TOKEN 0x0700 /* FeedBackToken */
#define GL_POINT_TOKEN 0x0701 /* FeedBackToken */
#define GL_LINE_TOKEN 0x0702 /* FeedBackToken */
#define GL_POLYGON_TOKEN 0x0703 /* FeedBackToken */
#define GL_BITMAP_TOKEN 0x0704 /* FeedBackToken */
#define GL_DRAW_PIXEL_TOKEN 0x0705 /* FeedBackToken */
#define GL_COPY_PIXEL_TOKEN 0x0706 /* FeedBackToken */
#define GL_LINE_RESET_TOKEN 0x0707 /* FeedBackToken */
#define GL_EXP 0x0800 /* FogMode */
#define GL_EXP2 0x0801 /* FogMode */
#define GL_COEFF 0x0A00 /* MapQuery, GetMapQuery */
#define GL_ORDER 0x0A01 /* MapQuery, GetMapQuery */
#define GL_DOMAIN 0x0A02 /* MapQuery, GetMapQuery */
#define GL_PIXEL_MAP_I_TO_I 0x0C70 /* PixelMap */
#define GL_PIXEL_MAP_S_TO_S 0x0C71 /* PixelMap */
#define GL_PIXEL_MAP_I_TO_R 0x0C72 /* PixelMap */
#define GL_PIXEL_MAP_I_TO_G 0x0C73 /* PixelMap */
#define GL_PIXEL_MAP_I_TO_B 0x0C74 /* PixelMap */
#define GL_PIXEL_MAP_I_TO_A 0x0C75 /* PixelMap */
#define GL_PIXEL_MAP_R_TO_R 0x0C76 /* PixelMap */
#define GL_PIXEL_MAP_G_TO_G 0x0C77 /* PixelMap */
#define GL_PIXEL_MAP_B_TO_B 0x0C78 /* PixelMap */
#define GL_PIXEL_MAP_A_TO_A 0x0C79 /* PixelMap */
#define GL_CURRENT_COLOR 0x0B00 /* GetPName */
#define GL_CURRENT_INDEX 0x0B01 /* GetPName */
#define GL_CURRENT_NORMAL 0x0B02 /* GetPName */
#define GL_CURRENT_TEXTURE_COORDS 0x0B03 /* GetPName, VertexShaderTextureUnitParameter */
#define GL_CURRENT_RASTER_COLOR 0x0B04 /* GetPName */
#define GL_CURRENT_RASTER_INDEX 0x0B05 /* GetPName */
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06 /* GetPName */
#define GL_CURRENT_RASTER_POSITION 0x0B07 /* GetPName */
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08 /* GetPName */
#define GL_CURRENT_RASTER_DISTANCE 0x0B09 /* GetPName */
#define GL_POINT_SMOOTH 0x0B10 /* GetPName, EnableCap */
#define GL_LINE_STIPPLE 0x0B24 /* GetPName, EnableCap */
#define GL_LINE_STIPPLE_PATTERN 0x0B25 /* GetPName */
#define GL_LINE_STIPPLE_REPEAT 0x0B26 /* GetPName */
#define GL_LIST_MODE 0x0B30 /* GetPName */
#define GL_MAX_LIST_NESTING 0x0B31 /* GetPName */
#define GL_LIST_BASE 0x0B32 /* GetPName */
#define GL_LIST_INDEX 0x0B33 /* GetPName */
#define GL_POLYGON_STIPPLE 0x0B42 /* GetPName, EnableCap */
#define GL_EDGE_FLAG 0x0B43 /* GetPName */
#define GL_LIGHTING 0x0B50 /* GetPName, EnableCap */
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51 /* LightModelParameter, GetPName */
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52 /* LightModelParameter, GetPName */
#define GL_LIGHT_MODEL_AMBIENT 0x0B53 /* LightModelParameter, GetPName */
#define GL_SHADE_MODEL 0x0B54 /* GetPName */
#define GL_COLOR_MATERIAL_FACE 0x0B55 /* GetPName */
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56 /* GetPName */
#define GL_COLOR_MATERIAL 0x0B57 /* GetPName, EnableCap */
#define GL_FOG 0x0B60 /* GetPName, EnableCap */
#define GL_FOG_INDEX 0x0B61 /* FogPName, FogParameter, GetPName */
#define GL_FOG_DENSITY 0x0B62 /* FogPName, FogParameter, GetPName */
#define GL_FOG_START 0x0B63 /* FogPName, FogParameter, GetPName */
#define GL_FOG_END 0x0B64 /* FogPName, FogParameter, GetPName */
#define GL_FOG_MODE 0x0B65 /* FogPName, FogParameter, GetPName */
#define GL_FOG_COLOR 0x0B66 /* GetPName, FogParameter */
#define GL_ACCUM_CLEAR_VALUE 0x0B80 /* GetPName */
#define GL_MATRIX_MODE 0x0BA0 /* GetPName */
#define GL_NORMALIZE 0x0BA1 /* GetPName, EnableCap */
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3 /* GetPName */
#define GL_PROJECTION_STACK_DEPTH 0x0BA4 /* GetPName */
#define GL_TEXTURE_STACK_DEPTH 0x0BA5 /* GetPName */
#define GL_MODELVIEW_MATRIX 0x0BA6 /* GetPName */
#define GL_PROJECTION_MATRIX 0x0BA7 /* GetPName */
#define GL_TEXTURE_MATRIX 0x0BA8 /* GetPName, VertexShaderTextureUnitParameter */
#define GL_ATTRIB_STACK_DEPTH 0x0BB0 /* GetPName */
#define GL_ALPHA_TEST 0x0BC0 /* GetPName, EnableCap */
#define GL_ALPHA_TEST_FUNC 0x0BC1 /* GetPName */
#define GL_ALPHA_TEST_REF 0x0BC2 /* GetPName */
#define GL_LOGIC_OP 0x0BF1 /* GetPName */
#define GL_AUX_BUFFERS 0x0C00 /* GetPName */
#define GL_INDEX_CLEAR_VALUE 0x0C20 /* GetPName */
#define GL_INDEX_WRITEMASK 0x0C21 /* GetPName */
#define GL_INDEX_MODE 0x0C30 /* GetPName */
#define GL_RGBA_MODE 0x0C31 /* GetPName */
#define GL_RENDER_MODE 0x0C40 /* GetPName */
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50 /* HintTarget, GetPName */
#define GL_POINT_SMOOTH_HINT 0x0C51 /* HintTarget, GetPName */
#define GL_FOG_HINT 0x0C54 /* HintTarget, GetPName */
#define GL_TEXTURE_GEN_S 0x0C60 /* GetPName, EnableCap */
#define GL_TEXTURE_GEN_T 0x0C61 /* GetPName, EnableCap */
#define GL_TEXTURE_GEN_R 0x0C62 /* GetPName, EnableCap */
#define GL_TEXTURE_GEN_Q 0x0C63 /* GetPName, EnableCap */
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0 /* GetPName */
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1 /* GetPName */
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2 /* GetPName */
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3 /* GetPName */
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4 /* GetPName */
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5 /* GetPName */
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6 /* GetPName */
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7 /* GetPName */
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8 /* GetPName */
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9 /* GetPName */
#define GL_MAP_COLOR 0x0D10 /* PixelTransferParameter, GetPName */
#define GL_MAP_STENCIL 0x0D11 /* PixelTransferParameter, GetPName */
#define GL_INDEX_SHIFT 0x0D12 /* PixelTransferParameter, GetPName */
#define GL_INDEX_OFFSET 0x0D13 /* PixelTransferParameter, IndexMaterialParameterEXT, GetPName */
#define GL_RED_SCALE 0x0D14 /* PixelTransferParameter, GetPName */
#define GL_RED_BIAS 0x0D15 /* PixelTransferParameter, GetPName */
#define GL_ZOOM_X 0x0D16 /* GetPName */
#define GL_ZOOM_Y 0x0D17 /* GetPName */
#define GL_GREEN_SCALE 0x0D18 /* PixelTransferParameter, GetPName */
#define GL_GREEN_BIAS 0x0D19 /* PixelTransferParameter, GetPName */
#define GL_BLUE_SCALE 0x0D1A /* PixelTransferParameter, GetPName */
#define GL_BLUE_BIAS 0x0D1B /* PixelTransferParameter, GetPName */
#define GL_ALPHA_SCALE 0x0D1C /* PixelTransferParameter, GetPName, TextureEnvParameter */
#define GL_ALPHA_BIAS 0x0D1D /* PixelTransferParameter, GetPName */
#define GL_DEPTH_SCALE 0x0D1E /* PixelTransferParameter, GetPName */
#define GL_DEPTH_BIAS 0x0D1F /* PixelTransferParameter, GetPName */
#define GL_MAX_EVAL_ORDER 0x0D30 /* GetPName */
#define GL_MAX_LIGHTS 0x0D31 /* GetPName */
#define GL_MAX_CLIP_PLANES 0x0D32 /* GetPName */
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34 /* GetPName */
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35 /* GetPName */
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36 /* GetPName */
#define GL_MAX_NAME_STACK_DEPTH 0x0D37 /* GetPName */
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38 /* GetPName */
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39 /* GetPName */
#define GL_INDEX_BITS 0x0D51 /* GetPName */
#define GL_RED_BITS 0x0D52 /* GetPName */
#define GL_GREEN_BITS 0x0D53 /* GetPName */
#define GL_BLUE_BITS 0x0D54 /* GetPName */
#define GL_ALPHA_BITS 0x0D55 /* GetPName */
#define GL_DEPTH_BITS 0x0D56 /* GetPName */
#define GL_STENCIL_BITS 0x0D57 /* GetPName */
#define GL_ACCUM_RED_BITS 0x0D58 /* GetPName */
#define GL_ACCUM_GREEN_BITS 0x0D59 /* GetPName */
#define GL_ACCUM_BLUE_BITS 0x0D5A /* GetPName */
#define GL_ACCUM_ALPHA_BITS 0x0D5B /* GetPName */
#define GL_NAME_STACK_DEPTH 0x0D70 /* GetPName */
#define GL_AUTO_NORMAL 0x0D80 /* GetPName, EnableCap */
#define GL_MAP1_COLOR_4 0x0D90 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_INDEX 0x0D91 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_NORMAL 0x0D92 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_TEXTURE_COORD_1 0x0D93 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_TEXTURE_COORD_2 0x0D94 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_TEXTURE_COORD_3 0x0D95 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_TEXTURE_COORD_4 0x0D96 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_VERTEX_3 0x0D97 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_VERTEX_4 0x0D98 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_COLOR_4 0x0DB0 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_INDEX 0x0DB1 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_NORMAL 0x0DB2 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_VERTEX_3 0x0DB7 /* MapTarget, EnableCap, GetPName */
#define GL_MAP2_VERTEX_4 0x0DB8 /* MapTarget, EnableCap, GetPName */
#define GL_MAP1_GRID_DOMAIN 0x0DD0 /* GetPName */
#define GL_MAP1_GRID_SEGMENTS 0x0DD1 /* GetPName */
#define GL_MAP2_GRID_DOMAIN 0x0DD2 /* GetPName */
#define GL_MAP2_GRID_SEGMENTS 0x0DD3 /* GetPName */
#define GL_TEXTURE_COMPONENTS 0x1003 /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_BORDER 0x1005 /* TextureParameterName, GetTextureParameter */
#define GL_AMBIENT 0x1200 /* LightParameter, MaterialParameter, FragmentLightParameterSGIX, ColorMaterialParameter */
#define GL_DIFFUSE 0x1201 /* LightParameter, MaterialParameter, FragmentLightParameterSGIX, ColorMaterialParameter */
#define GL_SPECULAR 0x1202 /* LightParameter, MaterialParameter, FragmentLightParameterSGIX, ColorMaterialParameter */
#define GL_POSITION 0x1203 /* LightParameter, FragmentLightParameterSGIX */
#define GL_SPOT_DIRECTION 0x1204 /* LightParameter, FragmentLightParameterSGIX */
#define GL_SPOT_EXPONENT 0x1205 /* LightParameter, FragmentLightParameterSGIX */
#define GL_SPOT_CUTOFF 0x1206 /* LightParameter, FragmentLightParameterSGIX */
#define GL_CONSTANT_ATTENUATION 0x1207 /* LightParameter, FragmentLightParameterSGIX */
#define GL_LINEAR_ATTENUATION 0x1208 /* LightParameter, FragmentLightParameterSGIX */
#define GL_QUADRATIC_ATTENUATION 0x1209 /* LightParameter, FragmentLightParameterSGIX */
#define GL_COMPILE 0x1300 /* ListMode */
#define GL_COMPILE_AND_EXECUTE 0x1301 /* ListMode */
#define GL_2_BYTES 0x1407 /* ListNameType */
#define GL_3_BYTES 0x1408 /* ListNameType */
#define GL_4_BYTES 0x1409 /* ListNameType */
#define GL_EMISSION 0x1600 /* MaterialParameter, ColorMaterialParameter */
#define GL_SHININESS 0x1601 /* MaterialParameter */
#define GL_AMBIENT_AND_DIFFUSE 0x1602 /* MaterialParameter, ColorMaterialParameter */
#define GL_COLOR_INDEXES 0x1603 /* MaterialParameter */
#define GL_MODELVIEW 0x1700 /* MatrixMode */
#define GL_PROJECTION 0x1701 /* MatrixMode */
#define GL_COLOR_INDEX 0x1900 /* PixelFormat */
#define GL_LUMINANCE 0x1909 /* PathColorFormat, PixelFormat */
#define GL_LUMINANCE_ALPHA 0x190A /* PathColorFormat, PixelFormat */
#define GL_BITMAP 0x1A00 /* PixelType */
#define GL_RENDER 0x1C00 /* RenderingMode */
#define GL_FEEDBACK 0x1C01 /* RenderingMode */
#define GL_SELECT 0x1C02 /* RenderingMode */
#define GL_FLAT 0x1D00 /* ShadingModel */
#define GL_SMOOTH 0x1D01 /* ShadingModel */
#define GL_S 0x2000 /* TextureCoordName */
#define GL_T 0x2001 /* TextureCoordName */
#define GL_R 0x2002 /* TextureCoordName */
#define GL_Q 0x2003 /* TextureCoordName */
#define GL_MODULATE 0x2100 /* TextureEnvMode, LightEnvModeSGIX */
#define GL_DECAL 0x2101 /* TextureEnvMode */
#define GL_TEXTURE_ENV_MODE 0x2200 /* TextureEnvParameter */
#define GL_TEXTURE_ENV_COLOR 0x2201 /* TextureEnvParameter */
#define GL_TEXTURE_ENV 0x2300 /* TextureEnvTarget */
#define GL_EYE_LINEAR 0x2400 /* PathGenMode, TextureGenMode */
#define GL_OBJECT_LINEAR 0x2401 /* PathGenMode, TextureGenMode */
#define GL_SPHERE_MAP 0x2402 /* TextureGenMode */
#define GL_TEXTURE_GEN_MODE 0x2500 /* TextureGenParameter */
#define GL_OBJECT_PLANE 0x2501 /* TextureGenParameter */
#define GL_EYE_PLANE 0x2502 /* TextureGenParameter */
#define GL_CLAMP 0x2900 /* TextureWrapMode */
#define GL_CLIP_PLANE0 0x3000 /* GetPName, ClipPlaneName, EnableCap */
#define GL_CLIP_PLANE1 0x3001 /* GetPName, ClipPlaneName, EnableCap */
#define GL_CLIP_PLANE2 0x3002 /* GetPName, ClipPlaneName, EnableCap */
#define GL_CLIP_PLANE3 0x3003 /* GetPName, ClipPlaneName, EnableCap */
#define GL_CLIP_PLANE4 0x3004 /* GetPName, ClipPlaneName, EnableCap */
#define GL_CLIP_PLANE5 0x3005 /* GetPName, ClipPlaneName, EnableCap */
#define GL_LIGHT0 0x4000 /* LightName, EnableCap, GetPName */
#define GL_LIGHT1 0x4001 /* LightName, EnableCap, GetPName */
#define GL_LIGHT2 0x4002 /* LightName, EnableCap, GetPName */
#define GL_LIGHT3 0x4003 /* LightName, EnableCap, GetPName */
#define GL_LIGHT4 0x4004 /* LightName, EnableCap, GetPName */
#define GL_LIGHT5 0x4005 /* LightName, EnableCap, GetPName */
#define GL_LIGHT6 0x4006 /* LightName, EnableCap, GetPName */
#define GL_LIGHT7 0x4007 /* LightName, EnableCap, GetPName */
#define GL_COLOR_LOGIC_OP 0x0BF2 /* GetPName, EnableCap */
#define GL_POLYGON_OFFSET_UNITS 0x2A00 /* GetPName */
#define GL_POLYGON_OFFSET_POINT 0x2A01 /* GetPName, EnableCap */
#define GL_POLYGON_OFFSET_LINE 0x2A02 /* GetPName, EnableCap */
#define GL_POLYGON_OFFSET_FILL 0x8037 /* GetPName, EnableCap */
#define GL_POLYGON_OFFSET_FACTOR 0x8038 /* GetPName */
#define GL_TEXTURE_BINDING_1D 0x8068 /* GetPName */
#define GL_TEXTURE_BINDING_2D 0x8069 /* GetPName */
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003 /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_RED_SIZE 0x805C /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_GREEN_SIZE 0x805D /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_BLUE_SIZE 0x805E /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_ALPHA_SIZE 0x805F /* TextureParameterName, GetTextureParameter */
#define GL_DOUBLE 0x140A /* VertexAttribLType, MapTypeNV, SecondaryColorPointerTypeIBM, WeightPointerTypeARB, TangentPointerTypeEXT, BinormalPointerTypeEXT, ColorPointerType, FogCoordinatePointerType, FogPointerTypeEXT, FogPointerTypeIBM, IndexPointerType, NormalPointerType, TexCoordPointerType, VertexPointerType, VertexAttribType, AttributeType, UniformType, VertexAttribPointerType */
#define GL_PROXY_TEXTURE_1D 0x8063 /* TextureTarget */
#define GL_PROXY_TEXTURE_2D 0x8064 /* TextureTarget */
#define GL_R3_G3_B2 0x2A10 /* InternalFormat, SizedInternalFormat */
#define GL_RGB4 0x804F /* InternalFormat, SizedInternalFormat */
#define GL_RGB5 0x8050 /* InternalFormat, SizedInternalFormat */
#define GL_RGB8 0x8051 /* InternalFormat, SizedInternalFormat */
#define GL_RGB10 0x8052 /* InternalFormat, SizedInternalFormat */
#define GL_RGB12 0x8053 /* InternalFormat, SizedInternalFormat */
#define GL_RGB16 0x8054 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA2 0x8055 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA4 0x8056 /* InternalFormat, SizedInternalFormat */
#define GL_RGB5_A1 0x8057 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA8 0x8058 /* InternalFormat, SizedInternalFormat */
#define GL_RGB10_A2 0x8059 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA12 0x805A /* InternalFormat, SizedInternalFormat */
#define GL_RGBA16 0x805B /* InternalFormat, SizedInternalFormat */
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001 /* ClientAttribMask */
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002 /* ClientAttribMask */
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF /* ClientAttribMask */
#define GL_VERTEX_ARRAY_POINTER 0x808E /* GetPointervPName */
#define GL_NORMAL_ARRAY_POINTER 0x808F /* GetPointervPName */
#define GL_COLOR_ARRAY_POINTER 0x8090 /* GetPointervPName */
#define GL_INDEX_ARRAY_POINTER 0x8091 /* GetPointervPName */
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092 /* GetPointervPName */
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093 /* GetPointervPName */
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0 /* GetPointervPName */
#define GL_SELECTION_BUFFER_POINTER 0x0DF3 /* GetPointervPName */
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1 /* GetPName */
#define GL_INDEX_LOGIC_OP 0x0BF1 /* GetPName, EnableCap */
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B /* GetPName */
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1 /* GetPName */
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2 /* GetPName */
#define GL_SELECTION_BUFFER_SIZE 0x0DF4 /* GetPName */
#define GL_VERTEX_ARRAY 0x8074 /* ObjectIdentifier, EnableCap, GetPName */
#define GL_NORMAL_ARRAY 0x8075 /* GetPName, EnableCap */
#define GL_COLOR_ARRAY 0x8076 /* GetPName, EnableCap */
#define GL_INDEX_ARRAY 0x8077 /* GetPName, EnableCap */
#define GL_TEXTURE_COORD_ARRAY 0x8078 /* GetPName, EnableCap */
#define GL_EDGE_FLAG_ARRAY 0x8079 /* GetPName, EnableCap */
#define GL_VERTEX_ARRAY_SIZE 0x807A /* GetPName */
#define GL_VERTEX_ARRAY_TYPE 0x807B /* GetPName */
#define GL_VERTEX_ARRAY_STRIDE 0x807C /* GetPName */
#define GL_NORMAL_ARRAY_TYPE 0x807E /* GetPName */
#define GL_NORMAL_ARRAY_STRIDE 0x807F /* GetPName */
#define GL_COLOR_ARRAY_SIZE 0x8081 /* GetPName */
#define GL_COLOR_ARRAY_TYPE 0x8082 /* GetPName */
#define GL_COLOR_ARRAY_STRIDE 0x8083 /* GetPName */
#define GL_INDEX_ARRAY_TYPE 0x8085 /* GetPName */
#define GL_INDEX_ARRAY_STRIDE 0x8086 /* GetPName */
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088 /* GetPName */
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089 /* GetPName */
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A /* GetPName */
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C /* GetPName */
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060 /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_INTENSITY_SIZE 0x8061 /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_PRIORITY 0x8066 /* TextureParameterName, GetTextureParameter */
#define GL_TEXTURE_RESIDENT 0x8067 /* TextureParameterName, GetTextureParameter */
#define GL_ALPHA4 0x803B /* InternalFormat, SizedInternalFormat */
#define GL_ALPHA8 0x803C /* InternalFormat, SizedInternalFormat */
#define GL_ALPHA12 0x803D /* InternalFormat, SizedInternalFormat */
#define GL_ALPHA16 0x803E /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE4 0x803F /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE8 0x8040 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE12 0x8041 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE16 0x8042 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE4_ALPHA4 0x8043 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE6_ALPHA2 0x8044 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE8_ALPHA8 0x8045 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE12_ALPHA4 0x8046 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE12_ALPHA12 0x8047 /* InternalFormat, SizedInternalFormat */
#define GL_LUMINANCE16_ALPHA16 0x8048 /* InternalFormat, SizedInternalFormat */
#define GL_INTENSITY 0x8049 /* InternalFormat, PathColorFormat */
#define GL_INTENSITY4 0x804A /* InternalFormat, SizedInternalFormat */
#define GL_INTENSITY8 0x804B /* InternalFormat, SizedInternalFormat */
#define GL_INTENSITY12 0x804C /* InternalFormat, SizedInternalFormat */
#define GL_INTENSITY16 0x804D /* InternalFormat, SizedInternalFormat */
#define GL_V2F 0x2A20 /* InterleavedArrayFormat */
#define GL_V3F 0x2A21 /* InterleavedArrayFormat */
#define GL_C4UB_V2F 0x2A22 /* InterleavedArrayFormat */
#define GL_C4UB_V3F 0x2A23 /* InterleavedArrayFormat */
#define GL_C3F_V3F 0x2A24 /* InterleavedArrayFormat */
#define GL_N3F_V3F 0x2A25 /* InterleavedArrayFormat */
#define GL_C4F_N3F_V3F 0x2A26 /* InterleavedArrayFormat */
#define GL_T2F_V3F 0x2A27 /* InterleavedArrayFormat */
#define GL_T4F_V4F 0x2A28 /* InterleavedArrayFormat */
#define GL_T2F_C4UB_V3F 0x2A29 /* InterleavedArrayFormat */
#define GL_T2F_C3F_V3F 0x2A2A /* InterleavedArrayFormat */
#define GL_T2F_N3F_V3F 0x2A2B /* InterleavedArrayFormat */
#define GL_T2F_C4F_N3F_V3F 0x2A2C /* InterleavedArrayFormat */
#define GL_T4F_C4F_N3F_V4F 0x2A2D /* InterleavedArrayFormat */
#define GL_UNSIGNED_BYTE_3_3_2 0x8032 /* PixelType */
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033 /* PixelType */
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034 /* PixelType */
#define GL_UNSIGNED_INT_8_8_8_8 0x8035 /* PixelType */
#define GL_UNSIGNED_INT_10_10_10_2 0x8036 /* PixelType */
#define GL_TEXTURE_BINDING_3D 0x806A /* GetPName */
#define GL_PACK_SKIP_IMAGES 0x806B /* PixelStoreParameter, GetPName */
#define GL_PACK_IMAGE_HEIGHT 0x806C /* PixelStoreParameter, GetPName */
#define GL_UNPACK_SKIP_IMAGES 0x806D /* PixelStoreParameter, GetPName */
#define GL_UNPACK_IMAGE_HEIGHT 0x806E /* PixelStoreParameter, GetPName */
#define GL_TEXTURE_3D 0x806F /* CopyImageSubDataTarget, TextureTarget */
#define GL_PROXY_TEXTURE_3D 0x8070 /* TextureTarget */
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072 /* SamplerParameterI, TextureParameterName */
#define GL_MAX_3D_TEXTURE_SIZE 0x8073 /* GetPName */
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362 /* PixelType */
#define GL_UNSIGNED_SHORT_5_6_5 0x8363 /* PixelType */
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364 /* PixelType */
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365 /* PixelType */
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366 /* PixelType */
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367 /* PixelType */
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368 /* PixelType, VertexAttribPointerType, VertexAttribType */
#define GL_BGR 0x80E0 /* PixelFormat */
#define GL_BGRA 0x80E1 /* PixelFormat */
#define GL_MAX_ELEMENTS_VERTICES 0x80E8 /* GetPName */
#define GL_MAX_ELEMENTS_INDICES 0x80E9 /* GetPName */
#define GL_CLAMP_TO_EDGE 0x812F /* TextureWrapMode */
#define GL_TEXTURE_MIN_LOD 0x813A /* SamplerParameterF, TextureParameterName */
#define GL_TEXTURE_MAX_LOD 0x813B /* SamplerParameterF, TextureParameterName */
#define GL_TEXTURE_BASE_LEVEL 0x813C /* TextureParameterName */
#define GL_TEXTURE_MAX_LEVEL 0x813D /* TextureParameterName */
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12 /* GetPName */
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13 /* GetPName */
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22 /* GetPName */
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23 /* GetPName */
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E /* GetPName */
#define GL_RESCALE_NORMAL 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8 /* LightModelParameter, GetPName */
#define GL_SINGLE_COLOR 0x81F9 /* LightModelColorControl */
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA /* LightModelColorControl */
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D /* GetPName */
#define GL_TEXTURE0 0x84C0 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE1 0x84C1 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE2 0x84C2 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE3 0x84C3 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE4 0x84C4 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE5 0x84C5 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE6 0x84C6 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE7 0x84C7 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE8 0x84C8 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE9 0x84C9 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE10 0x84CA /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE11 0x84CB /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE12 0x84CC /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE13 0x84CD /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE14 0x84CE /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE15 0x84CF /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE16 0x84D0 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE17 0x84D1 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE18 0x84D2 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE19 0x84D3 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE20 0x84D4 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE21 0x84D5 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE22 0x84D6 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE23 0x84D7 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE24 0x84D8 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE25 0x84D9 /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE26 0x84DA /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE27 0x84DB /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE28 0x84DC /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE29 0x84DD /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE30 0x84DE /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_TEXTURE31 0x84DF /* TextureUnit, FragmentShaderTextureSourceATI */
#define GL_ACTIVE_TEXTURE 0x84E0 /* GetPName */
#define GL_MULTISAMPLE 0x809D /* EnableCap */
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E /* EnableCap */
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F /* EnableCap */
#define GL_SAMPLE_COVERAGE 0x80A0 /* EnableCap */
#define GL_SAMPLE_BUFFERS 0x80A8 /* GetFramebufferParameter, GetPName */
#define GL_SAMPLES 0x80A9 /* GetFramebufferParameter, GetPName, InternalFormatPName */
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA /* GetPName */
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB /* GetPName */
#define GL_TEXTURE_CUBE_MAP 0x8513 /* CopyImageSubDataTarget, TextureTarget, EnableCap */
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514 /* GetPName */
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515 /* TextureTarget */
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516 /* TextureTarget */
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517 /* TextureTarget */
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518 /* TextureTarget */
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519 /* TextureTarget */
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A /* TextureTarget */
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B /* TextureTarget */
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C /* GetPName */
#define GL_COMPRESSED_RGB 0x84ED /* InternalFormat */
#define GL_COMPRESSED_RGBA 0x84EE /* InternalFormat */
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF /* HintTarget, GetPName */
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1 /* InternalFormatPName */
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2 /* GetPName */
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3 /* GetPName */
#define GL_CLAMP_TO_BORDER 0x812D /* TextureWrapMode */
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_MULTISAMPLE_BIT 0x20000000 /* AttribMask */
#define GL_NORMAL_MAP 0x8511 /* GetTextureParameter */
#define GL_REFLECTION_MAP 0x8512 /* GetTextureParameter */
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMBINE 0x8570 /* TextureEnvParameter */
#define GL_COMBINE_RGB 0x8571 /* TextureEnvParameter */
#define GL_COMBINE_ALPHA 0x8572 /* TextureEnvParameter */
#define GL_SOURCE0_RGB 0x8580 /* TextureEnvParameter */
#define GL_SOURCE1_RGB 0x8581 /* TextureEnvParameter */
#define GL_SOURCE2_RGB 0x8582 /* TextureEnvParameter */
#define GL_SOURCE0_ALPHA 0x8588 /* TextureEnvParameter */
#define GL_SOURCE1_ALPHA 0x8589 /* TextureEnvParameter */
#define GL_SOURCE2_ALPHA 0x858A /* TextureEnvParameter */
#define GL_OPERAND0_RGB 0x8590 /* TextureEnvParameter */
#define GL_OPERAND1_RGB 0x8591 /* TextureEnvParameter */
#define GL_OPERAND2_RGB 0x8592 /* TextureEnvParameter */
#define GL_OPERAND0_ALPHA 0x8598 /* TextureEnvParameter */
#define GL_OPERAND1_ALPHA 0x8599 /* TextureEnvParameter */
#define GL_OPERAND2_ALPHA 0x859A /* TextureEnvParameter */
#define GL_RGB_SCALE 0x8573 /* TextureEnvParameter */
#define GL_ADD_SIGNED 0x8574 /* TextureEnvParameter */
#define GL_INTERPOLATE 0x8575 /* TextureEnvParameter */
#define GL_SUBTRACT 0x84E7
#define GL_CONSTANT 0x8576 /* TextureEnvParameter */
#define GL_PRIMARY_COLOR 0x8577 /* TextureEnvParameter */
#define GL_PREVIOUS 0x8578 /* TextureEnvParameter */
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
#define GL_BLEND_DST_RGB 0x80C8 /* GetPName */
#define GL_BLEND_SRC_RGB 0x80C9 /* GetPName */
#define GL_BLEND_DST_ALPHA 0x80CA /* GetPName */
#define GL_BLEND_SRC_ALPHA 0x80CB /* GetPName */
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128 /* PointParameterNameARB, GetPName */
#define GL_DEPTH_COMPONENT16 0x81A5 /* InternalFormat, SizedInternalFormat */
#define GL_DEPTH_COMPONENT24 0x81A6 /* InternalFormat, SizedInternalFormat */
#define GL_DEPTH_COMPONENT32 0x81A7 /* InternalFormat, SizedInternalFormat */
#define GL_MIRRORED_REPEAT 0x8370 /* TextureWrapMode */
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD /* GetPName */
#define GL_TEXTURE_LOD_BIAS 0x8501 /* TextureParameterName, SamplerParameterF, TextureEnvParameter */
#define GL_INCR_WRAP 0x8507 /* StencilOp */
#define GL_DECR_WRAP 0x8508 /* StencilOp */
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_COMPARE_MODE 0x884C /* SamplerParameterI, TextureParameterName */
#define GL_TEXTURE_COMPARE_FUNC 0x884D /* SamplerParameterI, TextureParameterName */
#define GL_POINT_SIZE_MIN 0x8126 /* PointParameterNameARB, GetPName */
#define GL_POINT_SIZE_MAX 0x8127 /* PointParameterNameARB, GetPName */
#define GL_POINT_DISTANCE_ATTENUATION 0x8129 /* PointParameterNameARB, GetPName */
#define GL_GENERATE_MIPMAP 0x8191 /* InternalFormatPName, TextureParameterName */
#define GL_GENERATE_MIPMAP_HINT 0x8192 /* HintTarget */
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451 /* FogCoordSrc */
#define GL_FRAGMENT_DEPTH 0x8452 /* FogCoordSrc, LightTextureModeEXT */
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_TEXTURE_FILTER_CONTROL 0x8500 /* TextureEnvTarget */
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_COMPARE_R_TO_TEXTURE 0x884E /* TextureCompareMode */
#define GL_BLEND_COLOR 0x8005 /* GetPName */
#define GL_BLEND_EQUATION 0x8009 /* GetPName */
#define GL_CONSTANT_COLOR 0x8001 /* BlendingFactor */
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002 /* BlendingFactor */
#define GL_CONSTANT_ALPHA 0x8003 /* BlendingFactor */
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004 /* BlendingFactor */
#define GL_FUNC_ADD 0x8006 /* BlendEquationModeEXT */
#define GL_FUNC_REVERSE_SUBTRACT 0x800B /* BlendEquationModeEXT */
#define GL_FUNC_SUBTRACT 0x800A /* BlendEquationModeEXT */
#define GL_MIN 0x8007 /* BlendEquationModeEXT */
#define GL_MAX 0x8008 /* BlendEquationModeEXT */
#define GL_BUFFER_SIZE 0x8764 /* BufferPNameARB */
#define GL_BUFFER_USAGE 0x8765 /* BufferPNameARB */
#define GL_QUERY_COUNTER_BITS 0x8864 /* QueryParameterName */
#define GL_CURRENT_QUERY 0x8865 /* QueryParameterName */
#define GL_QUERY_RESULT 0x8866 /* QueryObjectParameterName */
#define GL_QUERY_RESULT_AVAILABLE 0x8867 /* QueryObjectParameterName */
#define GL_ARRAY_BUFFER 0x8892 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_ELEMENT_ARRAY_BUFFER 0x8893 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_ARRAY_BUFFER_BINDING 0x8894 /* GetPName */
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895 /* GetPName */
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F /* VertexAttribEnum, VertexAttribPropertyARB */
#define GL_READ_ONLY 0x88B8 /* BufferAccessARB */
#define GL_WRITE_ONLY 0x88B9 /* BufferAccessARB */
#define GL_READ_WRITE 0x88BA /* BufferAccessARB */
#define GL_BUFFER_ACCESS 0x88BB /* BufferPNameARB */
#define GL_BUFFER_MAPPED 0x88BC /* BufferPNameARB */
#define GL_BUFFER_MAP_POINTER 0x88BD /* BufferPointerNameARB */
#define GL_STREAM_DRAW 0x88E0 /* BufferUsageARB */
#define GL_STREAM_READ 0x88E1 /* BufferUsageARB */
#define GL_STREAM_COPY 0x88E2 /* BufferUsageARB */
#define GL_STATIC_DRAW 0x88E4 /* BufferUsageARB */
#define GL_STATIC_READ 0x88E5 /* BufferUsageARB */
#define GL_STATIC_COPY 0x88E6 /* BufferUsageARB */
#define GL_DYNAMIC_DRAW 0x88E8 /* BufferUsageARB */
#define GL_DYNAMIC_READ 0x88E9 /* BufferUsageARB */
#define GL_DYNAMIC_COPY 0x88EA /* BufferUsageARB */
#define GL_SAMPLES_PASSED 0x8914 /* QueryTarget */
#define GL_SRC1_ALPHA 0x8589 /* TextureEnvParameter */
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_FOG_COORD_SRC 0x8450 /* FogPName */
#define GL_FOG_COORD 0x8451 /* FogCoordSrc */
#define GL_CURRENT_FOG_COORD 0x8453
#define GL_FOG_COORD_ARRAY_TYPE 0x8454
#define GL_FOG_COORD_ARRAY_STRIDE 0x8455
#define GL_FOG_COORD_ARRAY_POINTER 0x8456
#define GL_FOG_COORD_ARRAY 0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_SRC0_RGB 0x8580 /* TextureEnvParameter */
#define GL_SRC1_RGB 0x8581 /* TextureEnvParameter */
#define GL_SRC2_RGB 0x8582 /* TextureEnvParameter */
#define GL_SRC0_ALPHA 0x8588 /* TextureEnvParameter */
#define GL_SRC2_ALPHA 0x858A /* TextureEnvParameter */
#define GL_BLEND_EQUATION_RGB 0x8009 /* GetPName */
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622 /* VertexAttribEnum, VertexAttribPropertyARB, VertexArrayPName */
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623 /* VertexAttribEnum, VertexAttribPropertyARB, VertexArrayPName */
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624 /* VertexAttribEnum, VertexAttribPropertyARB, VertexArrayPName */
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625 /* VertexAttribEnum, VertexAttribPropertyARB, VertexArrayPName */
#define GL_CURRENT_VERTEX_ATTRIB 0x8626 /* VertexAttribEnum, VertexAttribPropertyARB */
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645 /* VertexAttribPointerPropertyARB */
#define GL_STENCIL_BACK_FUNC 0x8800 /* GetPName */
#define GL_STENCIL_BACK_FAIL 0x8801 /* GetPName */
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802 /* GetPName */
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803 /* GetPName */
#define GL_MAX_DRAW_BUFFERS 0x8824 /* GetPName */
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D /* GetPName */
#define GL_MAX_VERTEX_ATTRIBS 0x8869 /* GetPName */
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A /* VertexAttribEnum, VertexAttribPropertyARB, VertexArrayPName */
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872 /* GetPName */
#define GL_FRAGMENT_SHADER 0x8B30 /* ShaderType */
#define GL_VERTEX_SHADER 0x8B31 /* ShaderType */
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49 /* GetPName */
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A /* GetPName */
#define GL_MAX_VARYING_FLOATS 0x8B4B /* GetPName */
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C /* GetPName */
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D /* GetPName */
#define GL_SHADER_TYPE 0x8B4F /* ShaderParameterName */
#define GL_FLOAT_VEC2 0x8B50 /* AttributeType */
#define GL_FLOAT_VEC3 0x8B51 /* AttributeType */
#define GL_FLOAT_VEC4 0x8B52 /* AttributeType */
#define GL_INT_VEC2 0x8B53 /* AttributeType */
#define GL_INT_VEC3 0x8B54 /* AttributeType */
#define GL_INT_VEC4 0x8B55 /* AttributeType */
#define GL_BOOL 0x8B56 /* AttributeType */
#define GL_BOOL_VEC2 0x8B57 /* AttributeType */
#define GL_BOOL_VEC3 0x8B58 /* AttributeType */
#define GL_BOOL_VEC4 0x8B59 /* AttributeType */
#define GL_FLOAT_MAT2 0x8B5A /* AttributeType */
#define GL_FLOAT_MAT3 0x8B5B /* AttributeType */
#define GL_FLOAT_MAT4 0x8B5C /* AttributeType */
#define GL_SAMPLER_1D 0x8B5D /* AttributeType */
#define GL_SAMPLER_2D 0x8B5E /* AttributeType */
#define GL_SAMPLER_3D 0x8B5F /* AttributeType */
#define GL_SAMPLER_CUBE 0x8B60 /* AttributeType */
#define GL_SAMPLER_1D_SHADOW 0x8B61 /* AttributeType */
#define GL_SAMPLER_2D_SHADOW 0x8B62 /* AttributeType */
#define GL_DELETE_STATUS 0x8B80 /* ProgramPropertyARB, ShaderParameterName */
#define GL_COMPILE_STATUS 0x8B81 /* ShaderParameterName */
#define GL_LINK_STATUS 0x8B82 /* ProgramPropertyARB */
#define GL_VALIDATE_STATUS 0x8B83 /* ProgramPropertyARB */
#define GL_INFO_LOG_LENGTH 0x8B84 /* ProgramPropertyARB, ShaderParameterName, PipelineParameterName */
#define GL_ATTACHED_SHADERS 0x8B85 /* ProgramPropertyARB */
#define GL_ACTIVE_UNIFORMS 0x8B86 /* ProgramPropertyARB */
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87 /* ProgramPropertyARB */
#define GL_SHADER_SOURCE_LENGTH 0x8B88 /* ShaderParameterName */
#define GL_ACTIVE_ATTRIBUTES 0x8B89 /* ProgramPropertyARB */
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A /* ProgramPropertyARB */
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B /* HintTarget, GetPName */
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C /* StringName */
#define GL_CURRENT_PROGRAM 0x8B8D /* GetPName */
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1 /* ClipControlOrigin */
#define GL_UPPER_LEFT 0x8CA2 /* ClipControlOrigin */
#define GL_STENCIL_BACK_REF 0x8CA3 /* GetPName */
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4 /* GetPName */
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5 /* GetPName */
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_POINT_SPRITE 0x8861 /* TextureEnvTarget */
#define GL_COORD_REPLACE 0x8862 /* TextureEnvParameter */
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_PIXEL_PACK_BUFFER 0x88EB /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_PIXEL_UNPACK_BUFFER 0x88EC /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED /* GetPName */
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF /* GetPName */
#define GL_FLOAT_MAT2x3 0x8B65 /* AttributeType */
#define GL_FLOAT_MAT2x4 0x8B66 /* AttributeType */
#define GL_FLOAT_MAT3x2 0x8B67 /* AttributeType */
#define GL_FLOAT_MAT3x4 0x8B68 /* AttributeType */
#define GL_FLOAT_MAT4x2 0x8B69 /* AttributeType */
#define GL_FLOAT_MAT4x3 0x8B6A /* AttributeType */
#define GL_SRGB 0x8C40 /* InternalFormat */
#define GL_SRGB8 0x8C41 /* InternalFormat, SizedInternalFormat */
#define GL_SRGB_ALPHA 0x8C42 /* InternalFormat */
#define GL_SRGB8_ALPHA8 0x8C43 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SRGB 0x8C48 /* InternalFormat */
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49 /* InternalFormat */
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
#define GL_COMPARE_REF_TO_TEXTURE 0x884E /* TextureCompareMode */
#define GL_CLIP_DISTANCE0 0x3000 /* EnableCap, ClipPlaneName */
#define GL_CLIP_DISTANCE1 0x3001 /* EnableCap, ClipPlaneName */
#define GL_CLIP_DISTANCE2 0x3002 /* EnableCap, ClipPlaneName */
#define GL_CLIP_DISTANCE3 0x3003 /* EnableCap, ClipPlaneName */
#define GL_CLIP_DISTANCE4 0x3004 /* EnableCap, ClipPlaneName */
#define GL_CLIP_DISTANCE5 0x3005 /* EnableCap, ClipPlaneName */
#define GL_CLIP_DISTANCE6 0x3006 /* EnableCap, ClipPlaneName */
#define GL_CLIP_DISTANCE7 0x3007 /* EnableCap, ClipPlaneName */
#define GL_MAX_CLIP_DISTANCES 0x0D32 /* GetPName */
#define GL_MAJOR_VERSION 0x821B /* GetPName */
#define GL_MINOR_VERSION 0x821C /* GetPName */
#define GL_NUM_EXTENSIONS 0x821D /* GetPName */
#define GL_CONTEXT_FLAGS 0x821E /* GetPName */
#define GL_COMPRESSED_RED 0x8225 /* InternalFormat */
#define GL_COMPRESSED_RG 0x8226 /* InternalFormat */
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001 /* ContextFlagMask */
#define GL_RGBA32F 0x8814 /* InternalFormat, SizedInternalFormat */
#define GL_RGB32F 0x8815 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA16F 0x881A /* InternalFormat, SizedInternalFormat */
#define GL_RGB16F 0x881B /* InternalFormat, SizedInternalFormat */
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD /* VertexAttribEnum, VertexAttribPropertyARB, VertexArrayPName */
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF /* GetPName */
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904 /* GetPName */
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905 /* GetPName */
#define GL_CLAMP_READ_COLOR 0x891C /* ClampColorTargetARB */
#define GL_FIXED_ONLY 0x891D /* ClampColorModeARB */
#define GL_MAX_VARYING_COMPONENTS 0x8B4B /* GetPName */
#define GL_TEXTURE_1D_ARRAY 0x8C18 /* CopyImageSubDataTarget, TextureTarget */
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19 /* TextureTarget */
#define GL_TEXTURE_2D_ARRAY 0x8C1A /* CopyImageSubDataTarget, TextureTarget */
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B /* TextureTarget */
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C /* GetPName */
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D /* GetPName */
#define GL_R11F_G11F_B10F 0x8C3A /* InternalFormat, SizedInternalFormat */
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B /* PixelType, VertexAttribPointerType, VertexAttribType */
#define GL_RGB9_E5 0x8C3D /* InternalFormat, SizedInternalFormat */
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E /* PixelType */
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76 /* ProgramPropertyARB */
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F /* ProgramPropertyARB */
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83 /* ProgramPropertyARB */
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84 /* TransformFeedbackPName, GetPName */
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85 /* TransformFeedbackPName, GetPName */
#define GL_PRIMITIVES_GENERATED 0x8C87 /* QueryTarget */
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88 /* QueryTarget */
#define GL_RASTERIZER_DISCARD 0x8C89 /* EnableCap */
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C /* TransformFeedbackBufferMode */
#define GL_SEPARATE_ATTRIBS 0x8C8D /* TransformFeedbackBufferMode */
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E /* ProgramInterface, BufferTargetARB, BufferStorageTarget, CopyBufferSubDataTarget */
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F /* TransformFeedbackPName, GetPName */
#define GL_RGBA32UI 0x8D70 /* InternalFormat, SizedInternalFormat */
#define GL_RGB32UI 0x8D71 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA16UI 0x8D76 /* InternalFormat, SizedInternalFormat */
#define GL_RGB16UI 0x8D77 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA8UI 0x8D7C /* InternalFormat, SizedInternalFormat */
#define GL_RGB8UI 0x8D7D /* InternalFormat, SizedInternalFormat */
#define GL_RGBA32I 0x8D82 /* InternalFormat, SizedInternalFormat */
#define GL_RGB32I 0x8D83 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA16I 0x8D88 /* InternalFormat, SizedInternalFormat */
#define GL_RGB16I 0x8D89 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA8I 0x8D8E /* InternalFormat, SizedInternalFormat */
#define GL_RGB8I 0x8D8F /* InternalFormat, SizedInternalFormat */
#define GL_RED_INTEGER 0x8D94 /* PixelFormat */
#define GL_GREEN_INTEGER 0x8D95 /* PixelFormat */
#define GL_BLUE_INTEGER 0x8D96 /* PixelFormat */
#define GL_RGB_INTEGER 0x8D98 /* PixelFormat */
#define GL_RGBA_INTEGER 0x8D99 /* PixelFormat */
#define GL_BGR_INTEGER 0x8D9A /* PixelFormat */
#define GL_BGRA_INTEGER 0x8D9B /* PixelFormat */
#define GL_SAMPLER_1D_ARRAY 0x8DC0 /* UniformType */
#define GL_SAMPLER_2D_ARRAY 0x8DC1 /* UniformType */
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3 /* AttributeType, UniformType */
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4 /* AttributeType, UniformType */
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_VEC2 0x8DC6 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_VEC3 0x8DC7 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_VEC4 0x8DC8 /* AttributeType, UniformType */
#define GL_INT_SAMPLER_1D 0x8DC9 /* AttributeType, UniformType */
#define GL_INT_SAMPLER_2D 0x8DCA /* AttributeType, UniformType */
#define GL_INT_SAMPLER_3D 0x8DCB /* AttributeType, UniformType */
#define GL_INT_SAMPLER_CUBE 0x8DCC /* AttributeType, UniformType */
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE /* AttributeType, UniformType */
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7 /* AttributeType, UniformType */
#define GL_QUERY_WAIT 0x8E13 /* ConditionalRenderMode */
#define GL_QUERY_NO_WAIT 0x8E14 /* ConditionalRenderMode */
#define GL_QUERY_BY_REGION_WAIT 0x8E15 /* ConditionalRenderMode */
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16 /* ConditionalRenderMode */
#define GL_BUFFER_ACCESS_FLAGS 0x911F /* BufferPNameARB */
#define GL_BUFFER_MAP_LENGTH 0x9120 /* BufferPNameARB */
#define GL_BUFFER_MAP_OFFSET 0x9121 /* BufferPNameARB */
#define GL_DEPTH_COMPONENT32F 0x8CAC /* InternalFormat, SizedInternalFormat */
#define GL_DEPTH32F_STENCIL8 0x8CAD /* InternalFormat, SizedInternalFormat */
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD /* PixelType */
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506 /* ErrorCode */
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219 /* FramebufferStatus */
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A /* FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8 /* GetPName */
#define GL_DEPTH_STENCIL 0x84F9 /* InternalFormat, PixelFormat */
#define GL_UNSIGNED_INT_24_8 0x84FA /* PixelType */
#define GL_DEPTH24_STENCIL8 0x88F0 /* InternalFormat, SizedInternalFormat */
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6 /* GetPName */
#define GL_RENDERBUFFER_BINDING 0x8CA7 /* GetPName */
#define GL_READ_FRAMEBUFFER 0x8CA8 /* FramebufferTarget */
#define GL_DRAW_FRAMEBUFFER 0x8CA9 /* FramebufferTarget */
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA /* GetPName */
#define GL_RENDERBUFFER_SAMPLES 0x8CAB /* RenderbufferParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5 /* FramebufferStatus */
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6 /* FramebufferStatus */
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7 /* FramebufferStatus */
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB /* FramebufferStatus */
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC /* FramebufferStatus */
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD /* FramebufferStatus */
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF /* GetPName */
#define GL_COLOR_ATTACHMENT0 0x8CE0 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT1 0x8CE1 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT2 0x8CE2 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT3 0x8CE3 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT4 0x8CE4 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT5 0x8CE5 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT6 0x8CE6 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT7 0x8CE7 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT8 0x8CE8 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT9 0x8CE9 /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT10 0x8CEA /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT11 0x8CEB /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT12 0x8CEC /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT13 0x8CED /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT14 0x8CEE /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT15 0x8CEF /* ColorBuffer, DrawBufferMode, ReadBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT16 0x8CF0 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT17 0x8CF1 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT18 0x8CF2 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT19 0x8CF3 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT20 0x8CF4 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT21 0x8CF5 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT22 0x8CF6 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT23 0x8CF7 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT24 0x8CF8 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT25 0x8CF9 /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT26 0x8CFA /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT27 0x8CFB /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT28 0x8CFC /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT29 0x8CFD /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT30 0x8CFE /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_COLOR_ATTACHMENT31 0x8CFF /* ColorBuffer, DrawBufferMode, FramebufferAttachment, InvalidateFramebufferAttachment */
#define GL_DEPTH_ATTACHMENT 0x8D00 /* InvalidateFramebufferAttachment, FramebufferAttachment */
#define GL_STENCIL_ATTACHMENT 0x8D20 /* FramebufferAttachment */
#define GL_FRAMEBUFFER 0x8D40 /* ObjectIdentifier, FramebufferTarget */
#define GL_RENDERBUFFER 0x8D41 /* ObjectIdentifier, RenderbufferTarget, CopyImageSubDataTarget, TextureTarget */
#define GL_RENDERBUFFER_WIDTH 0x8D42 /* RenderbufferParameterName */
#define GL_RENDERBUFFER_HEIGHT 0x8D43 /* RenderbufferParameterName */
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44 /* RenderbufferParameterName */
#define GL_STENCIL_INDEX1 0x8D46 /* InternalFormat, SizedInternalFormat */
#define GL_STENCIL_INDEX4 0x8D47 /* InternalFormat, SizedInternalFormat */
#define GL_STENCIL_INDEX8 0x8D48 /* InternalFormat, SizedInternalFormat */
#define GL_STENCIL_INDEX16 0x8D49 /* InternalFormat, SizedInternalFormat */
#define GL_RENDERBUFFER_RED_SIZE 0x8D50 /* RenderbufferParameterName */
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51 /* RenderbufferParameterName */
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52 /* RenderbufferParameterName */
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53 /* RenderbufferParameterName */
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54 /* RenderbufferParameterName */
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55 /* RenderbufferParameterName */
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56 /* FramebufferStatus */
#define GL_MAX_SAMPLES 0x8D57
#define GL_INDEX 0x8222
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#define GL_FRAMEBUFFER_SRGB 0x8DB9 /* EnableCap */
#define GL_HALF_FLOAT 0x140B /* PixelType, VertexAttribPointerType, VertexAttribType */
#define GL_MAP_READ_BIT 0x0001 /* MapBufferAccessMask */
#define GL_MAP_WRITE_BIT 0x0002 /* MapBufferAccessMask */
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004 /* MapBufferAccessMask */
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008 /* MapBufferAccessMask */
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010 /* MapBufferAccessMask */
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020 /* MapBufferAccessMask */
#define GL_COMPRESSED_RED_RGTC1 0x8DBB /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_RG_RGTC2 0x8DBD /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE /* InternalFormat, SizedInternalFormat */
#define GL_RG 0x8227 /* InternalFormat, PixelFormat */
#define GL_RG_INTEGER 0x8228 /* PixelFormat */
#define GL_R8 0x8229 /* InternalFormat, SizedInternalFormat */
#define GL_R16 0x822A /* InternalFormat, SizedInternalFormat */
#define GL_RG8 0x822B /* InternalFormat, SizedInternalFormat */
#define GL_RG16 0x822C /* InternalFormat, SizedInternalFormat */
#define GL_R16F 0x822D /* InternalFormat, SizedInternalFormat */
#define GL_R32F 0x822E /* InternalFormat, SizedInternalFormat */
#define GL_RG16F 0x822F /* InternalFormat, SizedInternalFormat */
#define GL_RG32F 0x8230 /* InternalFormat, SizedInternalFormat */
#define GL_R8I 0x8231 /* InternalFormat, SizedInternalFormat */
#define GL_R8UI 0x8232 /* InternalFormat, SizedInternalFormat */
#define GL_R16I 0x8233 /* InternalFormat, SizedInternalFormat */
#define GL_R16UI 0x8234 /* InternalFormat, SizedInternalFormat */
#define GL_R32I 0x8235 /* InternalFormat, SizedInternalFormat */
#define GL_R32UI 0x8236 /* InternalFormat, SizedInternalFormat */
#define GL_RG8I 0x8237 /* InternalFormat, SizedInternalFormat */
#define GL_RG8UI 0x8238 /* InternalFormat, SizedInternalFormat */
#define GL_RG16I 0x8239 /* InternalFormat, SizedInternalFormat */
#define GL_RG16UI 0x823A /* InternalFormat, SizedInternalFormat */
#define GL_RG32I 0x823B /* InternalFormat, SizedInternalFormat */
#define GL_RG32UI 0x823C /* InternalFormat, SizedInternalFormat */
#define GL_VERTEX_ARRAY_BINDING 0x85B5 /* GetPName */
#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_ALPHA_INTEGER 0x8D97
#define GL_SAMPLER_2D_RECT 0x8B63 /* AttributeType */
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64 /* AttributeType */
#define GL_SAMPLER_BUFFER 0x8DC2 /* AttributeType, UniformType */
#define GL_INT_SAMPLER_2D_RECT 0x8DCD /* AttributeType, UniformType */
#define GL_INT_SAMPLER_BUFFER 0x8DD0 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8 /* AttributeType, UniformType */
#define GL_TEXTURE_BUFFER 0x8C2A /* TextureTarget, CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B /* GetPName */
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C /* GetPName */
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE 0x84F5 /* CopyImageSubDataTarget, TextureTarget, EnableCap */
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6 /* GetPName */
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7 /* TextureTarget */
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8 /* GetPName */
#define GL_R8_SNORM 0x8F94 /* InternalFormat, SizedInternalFormat */
#define GL_RG8_SNORM 0x8F95 /* InternalFormat, SizedInternalFormat */
#define GL_RGB8_SNORM 0x8F96 /* InternalFormat, SizedInternalFormat */
#define GL_RGBA8_SNORM 0x8F97 /* InternalFormat, SizedInternalFormat */
#define GL_R16_SNORM 0x8F98 /* InternalFormat, SizedInternalFormat */
#define GL_RG16_SNORM 0x8F99 /* InternalFormat, SizedInternalFormat */
#define GL_RGB16_SNORM 0x8F9A /* InternalFormat, SizedInternalFormat */
#define GL_RGBA16_SNORM 0x8F9B /* InternalFormat, SizedInternalFormat */
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D /* EnableCap */
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E /* GetPName */
#define GL_COPY_READ_BUFFER 0x8F36 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_COPY_WRITE_BUFFER 0x8F37 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_UNIFORM_BUFFER 0x8A11 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_UNIFORM_BUFFER_BINDING 0x8A28 /* GetPName */
#define GL_UNIFORM_BUFFER_START 0x8A29 /* GetPName */
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A /* GetPName */
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B /* GetPName */
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C /* GetPName */
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D /* GetPName */
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E /* GetPName */
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F /* GetPName */
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30 /* GetPName */
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31 /* GetPName */
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32 /* GetPName */
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33 /* GetPName */
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34 /* GetPName */
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35 /* ProgramPropertyARB */
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36 /* ProgramPropertyARB */
#define GL_UNIFORM_TYPE 0x8A37 /* UniformPName */
#define GL_UNIFORM_SIZE 0x8A38 /* SubroutineParameterName, UniformPName */
#define GL_UNIFORM_NAME_LENGTH 0x8A39 /* SubroutineParameterName, UniformPName */
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A /* UniformPName */
#define GL_UNIFORM_OFFSET 0x8A3B /* UniformPName */
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C /* UniformPName */
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D /* UniformPName */
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E /* UniformPName */
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40 /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41 /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42 /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43 /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44 /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45 /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46 /* UniformBlockPName */
#define GL_INVALID_INDEX 0xFFFFFFFF /* SpecialNumbers */
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001 /* ContextProfileMask */
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002 /* ContextProfileMask */
#define GL_LINES_ADJACENCY 0x000A /* PrimitiveType */
#define GL_LINE_STRIP_ADJACENCY 0x000B /* PrimitiveType */
#define GL_TRIANGLES_ADJACENCY 0x000C /* PrimitiveType */
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D /* PrimitiveType */
#define GL_PROGRAM_POINT_SIZE 0x8642 /* GetPName, EnableCap */
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29 /* GetPName */
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7 /* FramebufferAttachmentParameterName */
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8 /* FramebufferStatus */
#define GL_GEOMETRY_SHADER 0x8DD9 /* PipelineParameterName, ShaderType */
#define GL_GEOMETRY_VERTICES_OUT 0x8916 /* ProgramPropertyARB */
#define GL_GEOMETRY_INPUT_TYPE 0x8917 /* ProgramPropertyARB */
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918 /* ProgramPropertyARB */
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF /* GetPName */
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122 /* GetPName */
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123 /* GetPName */
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124 /* GetPName */
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125 /* GetPName */
#define GL_CONTEXT_PROFILE_MASK 0x9126 /* GetPName */
#define GL_DEPTH_CLAMP 0x864F /* EnableCap */
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D /* VertexProvokingMode */
#define GL_LAST_VERTEX_CONVENTION 0x8E4E /* VertexProvokingMode */
#define GL_PROVOKING_VERTEX 0x8E4F /* GetPName */
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F /* EnableCap */
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111 /* GetPName */
#define GL_OBJECT_TYPE 0x9112 /* SyncParameterName */
#define GL_SYNC_CONDITION 0x9113 /* SyncParameterName */
#define GL_SYNC_STATUS 0x9114 /* SyncParameterName */
#define GL_SYNC_FLAGS 0x9115 /* SyncParameterName */
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117 /* SyncCondition */
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A /* SyncStatus */
#define GL_TIMEOUT_EXPIRED 0x911B /* SyncStatus */
#define GL_CONDITION_SATISFIED 0x911C /* SyncStatus */
#define GL_WAIT_FAILED 0x911D /* SyncStatus */
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF /* SpecialNumbers */
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001 /* SyncObjectMask */
#define GL_SAMPLE_POSITION 0x8E50 /* GetMultisamplePNameNV */
#define GL_SAMPLE_MASK 0x8E51 /* EnableCap */
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59 /* GetPName */
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100 /* CopyImageSubDataTarget, TextureTarget */
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101 /* TextureTarget */
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102 /* CopyImageSubDataTarget, TextureTarget */
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103 /* TextureTarget */
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104 /* GetPName */
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105 /* GetPName */
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108 /* AttributeType, UniformType */
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109 /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A /* AttributeType, UniformType */
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B /* AttributeType, UniformType */
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D /* AttributeType, UniformType */
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E /* GetPName */
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F /* GetPName */
#define GL_MAX_INTEGER_SAMPLES 0x9110 /* GetPName */
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE /* VertexAttribEnum, VertexAttribPropertyARB, VertexArrayPName */
#define GL_SRC1_COLOR 0x88F9 /* BlendingFactor */
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA /* BlendingFactor */
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB /* BlendingFactor */
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC /* GetPName */
#define GL_ANY_SAMPLES_PASSED 0x8C2F /* QueryTarget */
#define GL_SAMPLER_BINDING 0x8919 /* GetPName */
#define GL_RGB10_A2UI 0x906F /* InternalFormat, SizedInternalFormat */
#define GL_TEXTURE_SWIZZLE_R 0x8E42 /* TextureParameterName */
#define GL_TEXTURE_SWIZZLE_G 0x8E43 /* TextureParameterName */
#define GL_TEXTURE_SWIZZLE_B 0x8E44 /* TextureParameterName */
#define GL_TEXTURE_SWIZZLE_A 0x8E45 /* TextureParameterName */
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46 /* TextureParameterName */
#define GL_TIME_ELAPSED 0x88BF /* QueryTarget */
#define GL_TIMESTAMP 0x8E28 /* QueryCounterTarget, GetPName */
#define GL_INT_2_10_10_10_REV 0x8D9F /* VertexAttribPointerType, VertexAttribType */
#define GL_SAMPLE_SHADING 0x8C36 /* EnableCap */
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009 /* CopyImageSubDataTarget, TextureTarget */
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B /* TextureTarget */
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C /* AttributeType, UniformType */
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D /* AttributeType, UniformType */
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E /* AttributeType, UniformType */
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F /* AttributeType, UniformType */
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_DOUBLE_VEC2 0x8FFC /* AttributeType, UniformType */
#define GL_DOUBLE_VEC3 0x8FFD /* AttributeType, UniformType */
#define GL_DOUBLE_VEC4 0x8FFE /* AttributeType, UniformType */
#define GL_DOUBLE_MAT2 0x8F46 /* AttributeType, UniformType */
#define GL_DOUBLE_MAT3 0x8F47 /* AttributeType, UniformType */
#define GL_DOUBLE_MAT4 0x8F48 /* AttributeType, UniformType */
#define GL_DOUBLE_MAT2x3 0x8F49 /* UniformType, AttributeType */
#define GL_DOUBLE_MAT2x4 0x8F4A /* UniformType, AttributeType */
#define GL_DOUBLE_MAT3x2 0x8F4B /* UniformType, AttributeType */
#define GL_DOUBLE_MAT3x4 0x8F4C /* UniformType, AttributeType */
#define GL_DOUBLE_MAT4x2 0x8F4D /* UniformType, AttributeType */
#define GL_DOUBLE_MAT4x3 0x8F4E /* UniformType, AttributeType */
#define GL_ACTIVE_SUBROUTINES 0x8DE5 /* ProgramStagePName */
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6 /* ProgramStagePName */
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47 /* ProgramStagePName */
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48 /* ProgramStagePName */
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49 /* ProgramStagePName */
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A /* ProgramResourceProperty, SubroutineParameterName */
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B /* ProgramResourceProperty, SubroutineParameterName */
#define GL_PATCHES 0x000E /* PrimitiveType */
#define GL_PATCH_VERTICES 0x8E72 /* PatchParameterName */
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73 /* PatchParameterName */
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74 /* PatchParameterName */
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89 /* GetPName */
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A /* GetPName */
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0 /* UniformBlockPName */
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1 /* UniformBlockPName */
#define GL_TESS_EVALUATION_SHADER 0x8E87 /* PipelineParameterName, ShaderType */
#define GL_TESS_CONTROL_SHADER 0x8E88 /* PipelineParameterName, ShaderType */
#define GL_TRANSFORM_FEEDBACK 0x8E22 /* ObjectIdentifier, BindTransformFeedbackTarget */
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
#define GL_FIXED 0x140C /* VertexAttribPointerType, VertexAttribType */
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A /* GetFramebufferParameter, GetPName */
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B /* GetFramebufferParameter, GetPName */
#define GL_LOW_FLOAT 0x8DF0 /* PrecisionType */
#define GL_MEDIUM_FLOAT 0x8DF1 /* PrecisionType */
#define GL_HIGH_FLOAT 0x8DF2 /* PrecisionType */
#define GL_LOW_INT 0x8DF3 /* PrecisionType */
#define GL_MEDIUM_INT 0x8DF4 /* PrecisionType */
#define GL_HIGH_INT 0x8DF5 /* PrecisionType */
#define GL_SHADER_COMPILER 0x8DFA /* GetPName */
#define GL_SHADER_BINARY_FORMATS 0x8DF8 /* GetPName */
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9 /* GetPName */
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB /* GetPName */
#define GL_MAX_VARYING_VECTORS 0x8DFC /* GetPName */
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD /* GetPName */
#define GL_RGB565 0x8D62 /* InternalFormat, SizedInternalFormat */
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257 /* ProgramParameterPName, HintTarget */
#define GL_PROGRAM_BINARY_LENGTH 0x8741 /* ProgramPropertyARB */
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE /* GetPName */
#define GL_PROGRAM_BINARY_FORMATS 0x87FF /* GetPName */
#define GL_VERTEX_SHADER_BIT 0x00000001 /* UseProgramStageMask */
#define GL_FRAGMENT_SHADER_BIT 0x00000002 /* UseProgramStageMask */
#define GL_GEOMETRY_SHADER_BIT 0x00000004 /* UseProgramStageMask */
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008 /* UseProgramStageMask */
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010 /* UseProgramStageMask */
#define GL_ALL_SHADER_BITS 0xFFFFFFFF /* UseProgramStageMask */
#define GL_PROGRAM_SEPARABLE 0x8258 /* ProgramParameterPName */
#define GL_ACTIVE_PROGRAM 0x8259 /* PipelineParameterName */
#define GL_PROGRAM_PIPELINE_BINDING 0x825A /* GetPName */
#define GL_MAX_VIEWPORTS 0x825B /* GetPName */
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C /* GetPName */
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D /* GetPName */
#define GL_LAYER_PROVOKING_VERTEX 0x825E /* GetPName */
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F /* GetPName */
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24 /* TransformFeedbackPName */
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23 /* TransformFeedbackPName */
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#define GL_NUM_SAMPLE_COUNTS 0x9380 /* InternalFormatPName */
#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC /* GetPName */
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1 /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4 /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5 /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6 /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7 /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8 /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9 /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA /* AtomicCounterBufferPName */
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB /* AtomicCounterBufferPName */
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2 /* GetPName */
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3 /* GetPName */
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4 /* GetPName */
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5 /* GetPName */
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6 /* GetPName */
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7 /* GetPName */
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9 /* ProgramPropertyARB */
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA /* UniformPName */
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001 /* MemoryBarrierMask */
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002 /* MemoryBarrierMask */
#define GL_UNIFORM_BARRIER_BIT 0x00000004 /* MemoryBarrierMask */
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008 /* MemoryBarrierMask */
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020 /* MemoryBarrierMask */
#define GL_COMMAND_BARRIER_BIT 0x00000040 /* MemoryBarrierMask */
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080 /* MemoryBarrierMask */
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100 /* MemoryBarrierMask */
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200 /* MemoryBarrierMask */
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400 /* MemoryBarrierMask */
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800 /* MemoryBarrierMask */
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000 /* MemoryBarrierMask */
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF /* MemoryBarrierMask */
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C /* AttributeType */
#define GL_IMAGE_2D 0x904D /* AttributeType */
#define GL_IMAGE_3D 0x904E /* AttributeType */
#define GL_IMAGE_2D_RECT 0x904F /* AttributeType */
#define GL_IMAGE_CUBE 0x9050 /* AttributeType */
#define GL_IMAGE_BUFFER 0x9051 /* AttributeType */
#define GL_IMAGE_1D_ARRAY 0x9052 /* AttributeType */
#define GL_IMAGE_2D_ARRAY 0x9053 /* AttributeType */
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054 /* AttributeType */
#define GL_IMAGE_2D_MULTISAMPLE 0x9055 /* AttributeType */
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056 /* AttributeType */
#define GL_INT_IMAGE_1D 0x9057 /* AttributeType */
#define GL_INT_IMAGE_2D 0x9058 /* AttributeType */
#define GL_INT_IMAGE_3D 0x9059 /* AttributeType */
#define GL_INT_IMAGE_2D_RECT 0x905A /* AttributeType */
#define GL_INT_IMAGE_CUBE 0x905B /* AttributeType */
#define GL_INT_IMAGE_BUFFER 0x905C /* AttributeType */
#define GL_INT_IMAGE_1D_ARRAY 0x905D /* AttributeType */
#define GL_INT_IMAGE_2D_ARRAY 0x905E /* AttributeType */
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F /* AttributeType */
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060 /* AttributeType */
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069 /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B /* AttributeType */
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C /* AttributeType */
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7 /* InternalFormatPName */
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F /* InternalFormat, SizedInternalFormat */
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F
#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E /* VertexArrayPName, VertexAttribPropertyARB */
#define GL_COMPRESSED_RGB8_ETC2 0x9274 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SRGB8_ETC2 0x9275 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_R11_EAC 0x9270 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_RG11_EAC 0x9272 /* InternalFormat, SizedInternalFormat */
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273 /* InternalFormat, SizedInternalFormat */
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69 /* EnableCap */
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A /* QueryTarget */
#define GL_MAX_ELEMENT_INDEX 0x8D6B /* GetPName */
#define GL_COMPUTE_SHADER 0x91B9 /* ShaderType */
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB /* GetPName */
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC /* GetPName */
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263 /* GetPName */
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264 /* GetPName */
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265 /* GetPName */
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266 /* GetPName */
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB /* GetPName */
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE /* GetPName */
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF /* GetPName */
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267 /* ProgramPropertyARB */
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC /* UniformBlockPName */
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED /* AtomicCounterBufferPName */
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF /* GetPName */
#define GL_COMPUTE_SHADER_BIT 0x00000020 /* UseProgramStageMask */
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242 /* EnableCap */
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244 /* GetPointervPName */
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245 /* GetPointervPName */
#define GL_DEBUG_SOURCE_API 0x8246 /* DebugSource */
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247 /* DebugSource */
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248 /* DebugSource */
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249 /* DebugSource */
#define GL_DEBUG_SOURCE_APPLICATION 0x824A /* DebugSource */
#define GL_DEBUG_SOURCE_OTHER 0x824B /* DebugSource */
#define GL_DEBUG_TYPE_ERROR 0x824C /* DebugType */
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D /* DebugType */
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E /* DebugType */
#define GL_DEBUG_TYPE_PORTABILITY 0x824F /* DebugType */
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250 /* DebugType */
#define GL_DEBUG_TYPE_OTHER 0x8251 /* DebugType */
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_SEVERITY_HIGH 0x9146 /* DebugSeverity */
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147 /* DebugSeverity */
#define GL_DEBUG_SEVERITY_LOW 0x9148 /* DebugSeverity */
#define GL_DEBUG_TYPE_MARKER 0x8268 /* DebugType */
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269 /* DebugType */
#define GL_DEBUG_TYPE_POP_GROUP 0x826A /* DebugType */
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B /* DebugSeverity */
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C /* GetPName */
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D /* GetPName */
#define GL_BUFFER 0x82E0 /* ObjectIdentifier */
#define GL_SHADER 0x82E1 /* ObjectIdentifier */
#define GL_PROGRAM 0x82E2 /* ObjectIdentifier */
#define GL_QUERY 0x82E3 /* ObjectIdentifier */
#define GL_PROGRAM_PIPELINE 0x82E4 /* ObjectIdentifier */
#define GL_SAMPLER 0x82E6 /* ObjectIdentifier */
#define GL_MAX_LABEL_LENGTH 0x82E8 /* GetPName */
#define GL_DEBUG_OUTPUT 0x92E0 /* EnableCap */
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002 /* ContextFlagMask */
#define GL_MAX_UNIFORM_LOCATIONS 0x826E /* GetPName */
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310 /* GetFramebufferParameter, FramebufferParameterName */
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311 /* GetFramebufferParameter, FramebufferParameterName */
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312 /* GetFramebufferParameter, FramebufferParameterName */
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313 /* GetFramebufferParameter, FramebufferParameterName */
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314 /* GetFramebufferParameter, FramebufferParameterName */
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315 /* GetPName */
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316 /* GetPName */
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317 /* GetPName */
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318 /* GetPName */
#define GL_INTERNALFORMAT_SUPPORTED 0x826F /* InternalFormatPName */
#define GL_INTERNALFORMAT_PREFERRED 0x8270 /* InternalFormatPName */
#define GL_INTERNALFORMAT_RED_SIZE 0x8271 /* InternalFormatPName */
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272 /* InternalFormatPName */
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273 /* InternalFormatPName */
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274 /* InternalFormatPName */
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275 /* InternalFormatPName */
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276 /* InternalFormatPName */
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277 /* InternalFormatPName */
#define GL_INTERNALFORMAT_RED_TYPE 0x8278 /* InternalFormatPName */
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279 /* InternalFormatPName */
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A /* InternalFormatPName */
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B /* InternalFormatPName */
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C /* InternalFormatPName */
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D /* InternalFormatPName */
#define GL_MAX_WIDTH 0x827E /* InternalFormatPName */
#define GL_MAX_HEIGHT 0x827F /* InternalFormatPName */
#define GL_MAX_DEPTH 0x8280 /* InternalFormatPName */
#define GL_MAX_LAYERS 0x8281 /* InternalFormatPName */
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_COLOR_COMPONENTS 0x8283 /* InternalFormatPName */
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_COLOR_RENDERABLE 0x8286 /* InternalFormatPName */
#define GL_DEPTH_RENDERABLE 0x8287 /* InternalFormatPName */
#define GL_STENCIL_RENDERABLE 0x8288 /* InternalFormatPName */
#define GL_FRAMEBUFFER_RENDERABLE 0x8289 /* InternalFormatPName */
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A /* InternalFormatPName */
#define GL_FRAMEBUFFER_BLEND 0x828B /* InternalFormatPName */
#define GL_READ_PIXELS 0x828C /* InternalFormatPName */
#define GL_READ_PIXELS_FORMAT 0x828D /* InternalFormatPName */
#define GL_READ_PIXELS_TYPE 0x828E /* InternalFormatPName */
#define GL_TEXTURE_IMAGE_FORMAT 0x828F /* InternalFormatPName */
#define GL_TEXTURE_IMAGE_TYPE 0x8290 /* InternalFormatPName */
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291 /* InternalFormatPName */
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292 /* InternalFormatPName */
#define GL_MIPMAP 0x8293 /* InternalFormatPName */
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_AUTO_GENERATE_MIPMAP 0x8295 /* InternalFormatPName */
#define GL_COLOR_ENCODING 0x8296 /* InternalFormatPName */
#define GL_SRGB_READ 0x8297 /* InternalFormatPName */
#define GL_SRGB_WRITE 0x8298 /* InternalFormatPName */
#define GL_FILTER 0x829A /* InternalFormatPName */
#define GL_VERTEX_TEXTURE 0x829B /* InternalFormatPName */
#define GL_TESS_CONTROL_TEXTURE 0x829C /* InternalFormatPName */
#define GL_TESS_EVALUATION_TEXTURE 0x829D /* InternalFormatPName */
#define GL_GEOMETRY_TEXTURE 0x829E /* InternalFormatPName */
#define GL_FRAGMENT_TEXTURE 0x829F /* InternalFormatPName */
#define GL_COMPUTE_TEXTURE 0x82A0 /* InternalFormatPName */
#define GL_TEXTURE_SHADOW 0x82A1 /* InternalFormatPName */
#define GL_TEXTURE_GATHER 0x82A2 /* InternalFormatPName */
#define GL_TEXTURE_GATHER_SHADOW 0x82A3 /* InternalFormatPName */
#define GL_SHADER_IMAGE_LOAD 0x82A4 /* InternalFormatPName */
#define GL_SHADER_IMAGE_STORE 0x82A5 /* InternalFormatPName */
#define GL_SHADER_IMAGE_ATOMIC 0x82A6 /* InternalFormatPName */
#define GL_IMAGE_TEXEL_SIZE 0x82A7 /* InternalFormatPName */
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8 /* InternalFormatPName */
#define GL_IMAGE_PIXEL_FORMAT 0x82A9 /* InternalFormatPName */
#define GL_IMAGE_PIXEL_TYPE 0x82AA /* InternalFormatPName */
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC /* InternalFormatPName */
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD /* InternalFormatPName */
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE /* InternalFormatPName */
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF /* InternalFormatPName */
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1 /* InternalFormatPName */
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2 /* InternalFormatPName */
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3 /* InternalFormatPName */
#define GL_CLEAR_BUFFER 0x82B4 /* InternalFormatPName */
#define GL_TEXTURE_VIEW 0x82B5 /* InternalFormatPName */
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6 /* InternalFormatPName */
#define GL_FULL_SUPPORT 0x82B7
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_UNIFORM 0x92E1 /* ProgramResourceProperty, ProgramInterface */
#define GL_UNIFORM_BLOCK 0x92E2 /* ProgramInterface */
#define GL_PROGRAM_INPUT 0x92E3 /* ProgramInterface */
#define GL_PROGRAM_OUTPUT 0x92E4 /* ProgramInterface */
#define GL_BUFFER_VARIABLE 0x92E5 /* ProgramInterface */
#define GL_SHADER_STORAGE_BLOCK 0x92E6 /* ProgramInterface */
#define GL_VERTEX_SUBROUTINE 0x92E8 /* ProgramInterface */
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9 /* ProgramInterface */
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA /* ProgramInterface */
#define GL_GEOMETRY_SUBROUTINE 0x92EB /* ProgramInterface */
#define GL_FRAGMENT_SUBROUTINE 0x92EC /* ProgramInterface */
#define GL_COMPUTE_SUBROUTINE 0x92ED /* ProgramInterface */
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE /* ProgramInterface */
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF /* ProgramInterface */
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0 /* ProgramInterface */
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1 /* ProgramInterface */
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2 /* ProgramInterface */
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3 /* ProgramInterface */
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4 /* ProgramInterface */
#define GL_ACTIVE_RESOURCES 0x92F5 /* ProgramInterfacePName */
#define GL_MAX_NAME_LENGTH 0x92F6 /* ProgramInterfacePName */
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7 /* ProgramInterfacePName */
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8 /* ProgramInterfacePName */
#define GL_NAME_LENGTH 0x92F9 /* ProgramResourceProperty */
#define GL_TYPE 0x92FA /* ProgramResourceProperty */
#define GL_ARRAY_SIZE 0x92FB /* ProgramResourceProperty */
#define GL_OFFSET 0x92FC /* ProgramResourceProperty */
#define GL_BLOCK_INDEX 0x92FD /* ProgramResourceProperty */
#define GL_ARRAY_STRIDE 0x92FE /* ProgramResourceProperty */
#define GL_MATRIX_STRIDE 0x92FF /* ProgramResourceProperty */
#define GL_IS_ROW_MAJOR 0x9300 /* ProgramResourceProperty */
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301 /* ProgramResourceProperty */
#define GL_BUFFER_BINDING 0x9302 /* ProgramResourceProperty */
#define GL_BUFFER_DATA_SIZE 0x9303 /* ProgramResourceProperty */
#define GL_NUM_ACTIVE_VARIABLES 0x9304 /* ProgramResourceProperty */
#define GL_ACTIVE_VARIABLES 0x9305 /* ProgramResourceProperty */
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306 /* ProgramResourceProperty */
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307 /* ProgramResourceProperty */
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308 /* ProgramResourceProperty */
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309 /* ProgramResourceProperty */
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A /* ProgramResourceProperty */
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B /* ProgramResourceProperty */
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C /* ProgramResourceProperty */
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D /* ProgramResourceProperty */
#define GL_LOCATION 0x930E /* ProgramResourceProperty */
#define GL_LOCATION_INDEX 0x930F /* ProgramResourceProperty */
#define GL_IS_PER_PATCH 0x92E7 /* ProgramResourceProperty */
#define GL_SHADER_STORAGE_BUFFER 0x90D2 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3 /* GetPName */
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4 /* GetPName */
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5 /* GetPName */
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6 /* GetPName */
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7 /* GetPName */
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8 /* GetPName */
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9 /* GetPName */
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA /* GetPName */
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB /* GetPName */
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC /* GetPName */
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD /* GetPName */
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF /* GetPName */
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000 /* MemoryBarrierMask */
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA /* TextureParameterName */
#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F /* GetPName */
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_VERTEX_ATTRIB_BINDING 0x82D4 /* VertexAttribPropertyARB */
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5 /* VertexArrayPName, VertexAttribPropertyARB */
#define GL_VERTEX_BINDING_DIVISOR 0x82D6 /* GetPName */
#define GL_VERTEX_BINDING_OFFSET 0x82D7 /* GetPName */
#define GL_VERTEX_BINDING_STRIDE 0x82D8 /* GetPName */
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9 /* GetPName */
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA /* GetPName */
#define GL_VERTEX_BINDING_BUFFER 0x8F4F
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING 0x8C2A
#define GL_MAP_PERSISTENT_BIT 0x0040 /* MapBufferAccessMask */
#define GL_MAP_COHERENT_BIT 0x0080 /* MapBufferAccessMask */
#define GL_DYNAMIC_STORAGE_BIT 0x0100 /* BufferStorageMask */
#define GL_CLIENT_STORAGE_BIT 0x0200 /* BufferStorageMask */
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000 /* MemoryBarrierMask */
#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F /* BufferPNameARB */
#define GL_BUFFER_STORAGE_FLAGS 0x8220 /* BufferPNameARB */
#define GL_CLEAR_TEXTURE 0x9365 /* InternalFormatPName */
#define GL_LOCATION_COMPONENT 0x934A /* ProgramResourceProperty */
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B /* ProgramResourceProperty */
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C /* ProgramResourceProperty */
#define GL_QUERY_BUFFER 0x9192 /* CopyBufferSubDataTarget, BufferTargetARB, BufferStorageTarget */
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000 /* MemoryBarrierMask */
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194 /* QueryObjectParameterName */
#define GL_MIRROR_CLAMP_TO_EDGE 0x8743 /* TextureWrapMode */
#define GL_CONTEXT_LOST 0x0507
#define GL_NEGATIVE_ONE_TO_ONE 0x935E /* ClipControlDepth */
#define GL_ZERO_TO_ONE 0x935F /* ClipControlDepth */
#define GL_CLIP_ORIGIN 0x935C
#define GL_CLIP_DEPTH_MODE 0x935D
#define GL_QUERY_WAIT_INVERTED 0x8E17 /* ConditionalRenderMode */
#define GL_QUERY_NO_WAIT_INVERTED 0x8E18 /* ConditionalRenderMode */
#define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19 /* ConditionalRenderMode */
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A /* ConditionalRenderMode */
#define GL_MAX_CULL_DISTANCES 0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET 0x1006
#define GL_QUERY_TARGET 0x82EA /* QueryObjectParameterName */
#define GL_GUILTY_CONTEXT_RESET 0x8253 /* GraphicsResetStatus */
#define GL_INNOCENT_CONTEXT_RESET 0x8254 /* GraphicsResetStatus */
#define GL_UNKNOWN_CONTEXT_RESET 0x8255 /* GraphicsResetStatus */
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004 /* ContextFlagMask */
#define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
#define GL_SHADER_BINARY_FORMAT_SPIR_V 0x9551 /* ShaderBinaryFormat */
#define GL_SPIR_V_BINARY 0x9552
#define GL_PARAMETER_BUFFER 0x80EE /* BufferTargetARB */
#define GL_PARAMETER_BUFFER_BINDING 0x80EF
#define GL_CONTEXT_FLAG_NO_ERROR_BIT 0x00000008 /* ContextFlagMask */
#define GL_VERTICES_SUBMITTED 0x82EE /* QueryTarget */
#define GL_PRIMITIVES_SUBMITTED 0x82EF /* QueryTarget */
#define GL_VERTEX_SHADER_INVOCATIONS 0x82F0 /* QueryTarget */
#define GL_TESS_CONTROL_SHADER_PATCHES 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES 0x82F7
#define GL_POLYGON_OFFSET_CLAMP 0x8E1B
#define GL_SPIR_V_EXTENSIONS 0x9553
#define GL_NUM_SPIR_V_EXTENSIONS 0x9554
#define GL_TEXTURE_MAX_ANISOTROPY 0x84FE /* SamplerParameterF, TextureParameterName */
#define GL_MAX_TEXTURE_MAX_ANISOTROPY 0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW 0x82EC /* QueryTarget */
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED

typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
typedef void (APIENTRYP PFNGLFINISHPROC)();
typedef void (APIENTRYP PFNGLFLUSHPROC)();
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble *data);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)();
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
typedef void (APIENTRYP PFNGLENDLISTPROC)();
typedef void (APIENTRYP PFNGLCALLLISTPROC)(GLuint list);
typedef void (APIENTRYP PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void *lists);
typedef void (APIENTRYP PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
typedef GLuint (APIENTRYP PFNGLGENLISTSPROC)(GLsizei range);
typedef void (APIENTRYP PFNGLLISTBASEPROC)(GLuint base);
typedef void (APIENTRYP PFNGLBEGINPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
typedef void (APIENTRYP PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRYP PFNGLCOLOR3BVPROC)(const GLbyte *v);
typedef void (APIENTRYP PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRYP PFNGLCOLOR3DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRYP PFNGLCOLOR3FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (APIENTRYP PFNGLCOLOR3IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRYP PFNGLCOLOR3SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRYP PFNGLCOLOR3UBVPROC)(const GLubyte *v);
typedef void (APIENTRYP PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRYP PFNGLCOLOR3UIVPROC)(const GLuint *v);
typedef void (APIENTRYP PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRYP PFNGLCOLOR3USVPROC)(const GLushort *v);
typedef void (APIENTRYP PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (APIENTRYP PFNGLCOLOR4BVPROC)(const GLbyte *v);
typedef void (APIENTRYP PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (APIENTRYP PFNGLCOLOR4DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCOLOR4FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (APIENTRYP PFNGLCOLOR4IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (APIENTRYP PFNGLCOLOR4SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (APIENTRYP PFNGLCOLOR4UBVPROC)(const GLubyte *v);
typedef void (APIENTRYP PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (APIENTRYP PFNGLCOLOR4UIVPROC)(const GLuint *v);
typedef void (APIENTRYP PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (APIENTRYP PFNGLCOLOR4USVPROC)(const GLushort *v);
typedef void (APIENTRYP PFNGLEDGEFLAGPROC)(GLboolean flag);
typedef void (APIENTRYP PFNGLEDGEFLAGVPROC)(const GLboolean *flag);
typedef void (APIENTRYP PFNGLENDPROC)();
typedef void (APIENTRYP PFNGLINDEXDPROC)(GLdouble c);
typedef void (APIENTRYP PFNGLINDEXDVPROC)(const GLdouble *c);
typedef void (APIENTRYP PFNGLINDEXFPROC)(GLfloat c);
typedef void (APIENTRYP PFNGLINDEXFVPROC)(const GLfloat *c);
typedef void (APIENTRYP PFNGLINDEXIPROC)(GLint c);
typedef void (APIENTRYP PFNGLINDEXIVPROC)(const GLint *c);
typedef void (APIENTRYP PFNGLINDEXSPROC)(GLshort c);
typedef void (APIENTRYP PFNGLINDEXSVPROC)(const GLshort *c);
typedef void (APIENTRYP PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (APIENTRYP PFNGLNORMAL3BVPROC)(const GLbyte *v);
typedef void (APIENTRYP PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (APIENTRYP PFNGLNORMAL3DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (APIENTRYP PFNGLNORMAL3FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
typedef void (APIENTRYP PFNGLNORMAL3IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
typedef void (APIENTRYP PFNGLNORMAL3SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLRASTERPOS2DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLRASTERPOS2FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
typedef void (APIENTRYP PFNGLRASTERPOS2IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLRASTERPOS2SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLRASTERPOS3DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLRASTERPOS3FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLRASTERPOS3IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLRASTERPOS3SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLRASTERPOS4DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLRASTERPOS4FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLRASTERPOS4IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLRASTERPOS4SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (APIENTRYP PFNGLRECTDVPROC)(const GLdouble *v1, const GLdouble *v2);
typedef void (APIENTRYP PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (APIENTRYP PFNGLRECTFVPROC)(const GLfloat *v1, const GLfloat *v2);
typedef void (APIENTRYP PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (APIENTRYP PFNGLRECTIVPROC)(const GLint *v1, const GLint *v2);
typedef void (APIENTRYP PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (APIENTRYP PFNGLRECTSVPROC)(const GLshort *v1, const GLshort *v2);
typedef void (APIENTRYP PFNGLTEXCOORD1DPROC)(GLdouble s);
typedef void (APIENTRYP PFNGLTEXCOORD1DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD1FPROC)(GLfloat s);
typedef void (APIENTRYP PFNGLTEXCOORD1FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD1IPROC)(GLint s);
typedef void (APIENTRYP PFNGLTEXCOORD1IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD1SPROC)(GLshort s);
typedef void (APIENTRYP PFNGLTEXCOORD1SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLTEXCOORD2DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
typedef void (APIENTRYP PFNGLTEXCOORD2FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
typedef void (APIENTRYP PFNGLTEXCOORD2IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLTEXCOORD2SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLTEXCOORD3DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLTEXCOORD3FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLTEXCOORD3IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLTEXCOORD3SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLTEXCOORD4DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLTEXCOORD4FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLTEXCOORD4IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLTEXCOORD4SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEX2DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEX2FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEX2IPROC)(GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEX2IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEX2SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEX3DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEX3FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEX3IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEX3SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEX4DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEX4FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEX4IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEX4SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble *equation);
typedef void (APIENTRYP PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLFOGIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLFOGIVPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
typedef void (APIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLPOLYGONSTIPPLEPROC)(const GLubyte *mask);
typedef void (APIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
typedef void (APIENTRYP PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble *params);
typedef void (APIENTRYP PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat *buffer);
typedef void (APIENTRYP PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint *buffer);
typedef GLint (APIENTRYP PFNGLRENDERMODEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLINITNAMESPROC)();
typedef void (APIENTRYP PFNGLLOADNAMEPROC)(GLuint name);
typedef void (APIENTRYP PFNGLPASSTHROUGHPROC)(GLfloat token);
typedef void (APIENTRYP PFNGLPOPNAMEPROC)();
typedef void (APIENTRYP PFNGLPUSHNAMEPROC)(GLuint name);
typedef void (APIENTRYP PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARINDEXPROC)(GLfloat c);
typedef void (APIENTRYP PFNGLINDEXMASKPROC)(GLuint mask);
typedef void (APIENTRYP PFNGLACCUMPROC)(GLenum op, GLfloat value);
typedef void (APIENTRYP PFNGLPOPATTRIBPROC)();
typedef void (APIENTRYP PFNGLPUSHATTRIBPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
typedef void (APIENTRYP PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
typedef void (APIENTRYP PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
typedef void (APIENTRYP PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
typedef void (APIENTRYP PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
typedef void (APIENTRYP PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
typedef void (APIENTRYP PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLEVALCOORD1DPROC)(GLdouble u);
typedef void (APIENTRYP PFNGLEVALCOORD1DVPROC)(const GLdouble *u);
typedef void (APIENTRYP PFNGLEVALCOORD1FPROC)(GLfloat u);
typedef void (APIENTRYP PFNGLEVALCOORD1FVPROC)(const GLfloat *u);
typedef void (APIENTRYP PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
typedef void (APIENTRYP PFNGLEVALCOORD2DVPROC)(const GLdouble *u);
typedef void (APIENTRYP PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
typedef void (APIENTRYP PFNGLEVALCOORD2FVPROC)(const GLfloat *u);
typedef void (APIENTRYP PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
typedef void (APIENTRYP PFNGLEVALPOINT1PROC)(GLint i);
typedef void (APIENTRYP PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (APIENTRYP PFNGLEVALPOINT2PROC)(GLint i, GLint j);
typedef void (APIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
typedef void (APIENTRYP PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
typedef void (APIENTRYP PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat *values);
typedef void (APIENTRYP PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint *values);
typedef void (APIENTRYP PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort *values);
typedef void (APIENTRYP PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (APIENTRYP PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble *equation);
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble *v);
typedef void (APIENTRYP PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat *v);
typedef void (APIENTRYP PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint *v);
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat *values);
typedef void (APIENTRYP PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint *values);
typedef void (APIENTRYP PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort *values);
typedef void (APIENTRYP PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte *mask);
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISLISTPROC)(GLuint list);
typedef void (APIENTRYP PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC)();
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat *m);
typedef void (APIENTRYP PFNGLLOADMATRIXDPROC)(const GLdouble *m);
typedef void (APIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat *m);
typedef void (APIENTRYP PFNGLMULTMATRIXDPROC)(const GLdouble *m);
typedef void (APIENTRYP PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLPOPMATRIXPROC)();
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC)();
typedef void (APIENTRYP PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void **params);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLARRAYELEMENTPROC)(GLint i);
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
typedef void (APIENTRYP PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
typedef void (APIENTRYP PFNGLINDEXUBPROC)(GLubyte c);
typedef void (APIENTRYP PFNGLINDEXUBVPROC)(const GLubyte *c);
typedef void (APIENTRYP PFNGLPOPCLIENTATTRIBPROC)();
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void *img);
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC)(GLenum target, GLdouble s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC)(GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC)(GLenum target, GLfloat s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC)(GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC)(GLenum target, GLint s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC)(GLenum target, GLshort s);
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC)(GLenum target, GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC)(GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC)(GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC)(GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC)(GLenum target, GLint s, GLint t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC)(GLenum target, GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC)(GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC)(GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC)(GLenum target, GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC)(GLenum target, const GLdouble *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC)(GLenum target, const GLfloat *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC)(GLenum target, const GLint *v);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC)(GLenum target, const GLshort *v);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *m);
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *m);
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *m);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLFOGCOORDFPROC)(GLfloat coord);
typedef void (APIENTRYP PFNGLFOGCOORDFVPROC)(const GLfloat *coord);
typedef void (APIENTRYP PFNGLFOGCOORDDPROC)(GLdouble coord);
typedef void (APIENTRYP PFNGLFOGCOORDDVPROC)(const GLdouble *coord);
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *v);
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC)(const GLdouble *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC)(const GLfloat *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC)(const GLint *v);
typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC)(const GLshort *v);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC)(GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void *data);
typedef void * (APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)();
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void **pointer);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean *data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint *data);
typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)();
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)();
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort *v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void * (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint *arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 *data);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64 *data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat *val);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar *name);
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint *samplers);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint *samplers);
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint *param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64 *params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat value);
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void *indirect);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void *indirect);
typedef void (APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble *params);
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar *name);
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint *indices);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint *params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat *values);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint *ids);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)();
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)();
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)();
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const*strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint *pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat *v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint *v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble *v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat *data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble *data);
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint *params);
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar *name);
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void *userParam);
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)();
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void *ptr, GLsizei length, const GLchar *label);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint *samplers);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint *textures);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint *param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 *params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void **params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint *renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat *param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint *params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint *param);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint *params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint *arrays);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint *param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint *samplers);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint *pipelines);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint *ids);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)();
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)();
typedef void (APIENTRYP PFNGLSPECIALIZESHADERPROC)(GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);

typedef PFNGLCULLFACEPROC mgl_glCullFace_t;
typedef PFNGLFRONTFACEPROC mgl_glFrontFace_t;
typedef PFNGLHINTPROC mgl_glHint_t;
typedef PFNGLLINEWIDTHPROC mgl_glLineWidth_t;
typedef PFNGLPOINTSIZEPROC mgl_glPointSize_t;
typedef PFNGLPOLYGONMODEPROC mgl_glPolygonMode_t;
typedef PFNGLSCISSORPROC mgl_glScissor_t;
typedef PFNGLTEXPARAMETERFPROC mgl_glTexParameterf_t;
typedef PFNGLTEXPARAMETERFVPROC mgl_glTexParameterfv_t;
typedef PFNGLTEXPARAMETERIPROC mgl_glTexParameteri_t;
typedef PFNGLTEXPARAMETERIVPROC mgl_glTexParameteriv_t;
typedef PFNGLTEXIMAGE1DPROC mgl_glTexImage1D_t;
typedef PFNGLTEXIMAGE2DPROC mgl_glTexImage2D_t;
typedef PFNGLDRAWBUFFERPROC mgl_glDrawBuffer_t;
typedef PFNGLCLEARPROC mgl_glClear_t;
typedef PFNGLCLEARCOLORPROC mgl_glClearColor_t;
typedef PFNGLCLEARSTENCILPROC mgl_glClearStencil_t;
typedef PFNGLCLEARDEPTHPROC mgl_glClearDepth_t;
typedef PFNGLSTENCILMASKPROC mgl_glStencilMask_t;
typedef PFNGLCOLORMASKPROC mgl_glColorMask_t;
typedef PFNGLDEPTHMASKPROC mgl_glDepthMask_t;
typedef PFNGLDISABLEPROC mgl_glDisable_t;
typedef PFNGLENABLEPROC mgl_glEnable_t;
typedef PFNGLFINISHPROC mgl_glFinish_t;
typedef PFNGLFLUSHPROC mgl_glFlush_t;
typedef PFNGLBLENDFUNCPROC mgl_glBlendFunc_t;
typedef PFNGLLOGICOPPROC mgl_glLogicOp_t;
typedef PFNGLSTENCILFUNCPROC mgl_glStencilFunc_t;
typedef PFNGLSTENCILOPPROC mgl_glStencilOp_t;
typedef PFNGLDEPTHFUNCPROC mgl_glDepthFunc_t;
typedef PFNGLPIXELSTOREFPROC mgl_glPixelStoref_t;
typedef PFNGLPIXELSTOREIPROC mgl_glPixelStorei_t;
typedef PFNGLREADBUFFERPROC mgl_glReadBuffer_t;
typedef PFNGLREADPIXELSPROC mgl_glReadPixels_t;
typedef PFNGLGETBOOLEANVPROC mgl_glGetBooleanv_t;
typedef PFNGLGETDOUBLEVPROC mgl_glGetDoublev_t;
typedef PFNGLGETERRORPROC mgl_glGetError_t;
typedef PFNGLGETFLOATVPROC mgl_glGetFloatv_t;
typedef PFNGLGETINTEGERVPROC mgl_glGetIntegerv_t;
typedef PFNGLGETSTRINGPROC mgl_glGetString_t;
typedef PFNGLGETTEXIMAGEPROC mgl_glGetTexImage_t;
typedef PFNGLGETTEXPARAMETERFVPROC mgl_glGetTexParameterfv_t;
typedef PFNGLGETTEXPARAMETERIVPROC mgl_glGetTexParameteriv_t;
typedef PFNGLGETTEXLEVELPARAMETERFVPROC mgl_glGetTexLevelParameterfv_t;
typedef PFNGLGETTEXLEVELPARAMETERIVPROC mgl_glGetTexLevelParameteriv_t;
typedef PFNGLISENABLEDPROC mgl_glIsEnabled_t;
typedef PFNGLDEPTHRANGEPROC mgl_glDepthRange_t;
typedef PFNGLVIEWPORTPROC mgl_glViewport_t;
typedef PFNGLNEWLISTPROC mgl_glNewList_t;
typedef PFNGLENDLISTPROC mgl_glEndList_t;
typedef PFNGLCALLLISTPROC mgl_glCallList_t;
typedef PFNGLCALLLISTSPROC mgl_glCallLists_t;
typedef PFNGLDELETELISTSPROC mgl_glDeleteLists_t;
typedef PFNGLGENLISTSPROC mgl_glGenLists_t;
typedef PFNGLLISTBASEPROC mgl_glListBase_t;
typedef PFNGLBEGINPROC mgl_glBegin_t;
typedef PFNGLBITMAPPROC mgl_glBitmap_t;
typedef PFNGLCOLOR3BPROC mgl_glColor3b_t;
typedef PFNGLCOLOR3BVPROC mgl_glColor3bv_t;
typedef PFNGLCOLOR3DPROC mgl_glColor3d_t;
typedef PFNGLCOLOR3DVPROC mgl_glColor3dv_t;
typedef PFNGLCOLOR3FPROC mgl_glColor3f_t;
typedef PFNGLCOLOR3FVPROC mgl_glColor3fv_t;
typedef PFNGLCOLOR3IPROC mgl_glColor3i_t;
typedef PFNGLCOLOR3IVPROC mgl_glColor3iv_t;
typedef PFNGLCOLOR3SPROC mgl_glColor3s_t;
typedef PFNGLCOLOR3SVPROC mgl_glColor3sv_t;
typedef PFNGLCOLOR3UBPROC mgl_glColor3ub_t;
typedef PFNGLCOLOR3UBVPROC mgl_glColor3ubv_t;
typedef PFNGLCOLOR3UIPROC mgl_glColor3ui_t;
typedef PFNGLCOLOR3UIVPROC mgl_glColor3uiv_t;
typedef PFNGLCOLOR3USPROC mgl_glColor3us_t;
typedef PFNGLCOLOR3USVPROC mgl_glColor3usv_t;
typedef PFNGLCOLOR4BPROC mgl_glColor4b_t;
typedef PFNGLCOLOR4BVPROC mgl_glColor4bv_t;
typedef PFNGLCOLOR4DPROC mgl_glColor4d_t;
typedef PFNGLCOLOR4DVPROC mgl_glColor4dv_t;
typedef PFNGLCOLOR4FPROC mgl_glColor4f_t;
typedef PFNGLCOLOR4FVPROC mgl_glColor4fv_t;
typedef PFNGLCOLOR4IPROC mgl_glColor4i_t;
typedef PFNGLCOLOR4IVPROC mgl_glColor4iv_t;
typedef PFNGLCOLOR4SPROC mgl_glColor4s_t;
typedef PFNGLCOLOR4SVPROC mgl_glColor4sv_t;
typedef PFNGLCOLOR4UBPROC mgl_glColor4ub_t;
typedef PFNGLCOLOR4UBVPROC mgl_glColor4ubv_t;
typedef PFNGLCOLOR4UIPROC mgl_glColor4ui_t;
typedef PFNGLCOLOR4UIVPROC mgl_glColor4uiv_t;
typedef PFNGLCOLOR4USPROC mgl_glColor4us_t;
typedef PFNGLCOLOR4USVPROC mgl_glColor4usv_t;
typedef PFNGLEDGEFLAGPROC mgl_glEdgeFlag_t;
typedef PFNGLEDGEFLAGVPROC mgl_glEdgeFlagv_t;
typedef PFNGLENDPROC mgl_glEnd_t;
typedef PFNGLINDEXDPROC mgl_glIndexd_t;
typedef PFNGLINDEXDVPROC mgl_glIndexdv_t;
typedef PFNGLINDEXFPROC mgl_glIndexf_t;
typedef PFNGLINDEXFVPROC mgl_glIndexfv_t;
typedef PFNGLINDEXIPROC mgl_glIndexi_t;
typedef PFNGLINDEXIVPROC mgl_glIndexiv_t;
typedef PFNGLINDEXSPROC mgl_glIndexs_t;
typedef PFNGLINDEXSVPROC mgl_glIndexsv_t;
typedef PFNGLNORMAL3BPROC mgl_glNormal3b_t;
typedef PFNGLNORMAL3BVPROC mgl_glNormal3bv_t;
typedef PFNGLNORMAL3DPROC mgl_glNormal3d_t;
typedef PFNGLNORMAL3DVPROC mgl_glNormal3dv_t;
typedef PFNGLNORMAL3FPROC mgl_glNormal3f_t;
typedef PFNGLNORMAL3FVPROC mgl_glNormal3fv_t;
typedef PFNGLNORMAL3IPROC mgl_glNormal3i_t;
typedef PFNGLNORMAL3IVPROC mgl_glNormal3iv_t;
typedef PFNGLNORMAL3SPROC mgl_glNormal3s_t;
typedef PFNGLNORMAL3SVPROC mgl_glNormal3sv_t;
typedef PFNGLRASTERPOS2DPROC mgl_glRasterPos2d_t;
typedef PFNGLRASTERPOS2DVPROC mgl_glRasterPos2dv_t;
typedef PFNGLRASTERPOS2FPROC mgl_glRasterPos2f_t;
typedef PFNGLRASTERPOS2FVPROC mgl_glRasterPos2fv_t;
typedef PFNGLRASTERPOS2IPROC mgl_glRasterPos2i_t;
typedef PFNGLRASTERPOS2IVPROC mgl_glRasterPos2iv_t;
typedef PFNGLRASTERPOS2SPROC mgl_glRasterPos2s_t;
typedef PFNGLRASTERPOS2SVPROC mgl_glRasterPos2sv_t;
typedef PFNGLRASTERPOS3DPROC mgl_glRasterPos3d_t;
typedef PFNGLRASTERPOS3DVPROC mgl_glRasterPos3dv_t;
typedef PFNGLRASTERPOS3FPROC mgl_glRasterPos3f_t;
typedef PFNGLRASTERPOS3FVPROC mgl_glRasterPos3fv_t;
typedef PFNGLRASTERPOS3IPROC mgl_glRasterPos3i_t;
typedef PFNGLRASTERPOS3IVPROC mgl_glRasterPos3iv_t;
typedef PFNGLRASTERPOS3SPROC mgl_glRasterPos3s_t;
typedef PFNGLRASTERPOS3SVPROC mgl_glRasterPos3sv_t;
typedef PFNGLRASTERPOS4DPROC mgl_glRasterPos4d_t;
typedef PFNGLRASTERPOS4DVPROC mgl_glRasterPos4dv_t;
typedef PFNGLRASTERPOS4FPROC mgl_glRasterPos4f_t;
typedef PFNGLRASTERPOS4FVPROC mgl_glRasterPos4fv_t;
typedef PFNGLRASTERPOS4IPROC mgl_glRasterPos4i_t;
typedef PFNGLRASTERPOS4IVPROC mgl_glRasterPos4iv_t;
typedef PFNGLRASTERPOS4SPROC mgl_glRasterPos4s_t;
typedef PFNGLRASTERPOS4SVPROC mgl_glRasterPos4sv_t;
typedef PFNGLRECTDPROC mgl_glRectd_t;
typedef PFNGLRECTDVPROC mgl_glRectdv_t;
typedef PFNGLRECTFPROC mgl_glRectf_t;
typedef PFNGLRECTFVPROC mgl_glRectfv_t;
typedef PFNGLRECTIPROC mgl_glRecti_t;
typedef PFNGLRECTIVPROC mgl_glRectiv_t;
typedef PFNGLRECTSPROC mgl_glRects_t;
typedef PFNGLRECTSVPROC mgl_glRectsv_t;
typedef PFNGLTEXCOORD1DPROC mgl_glTexCoord1d_t;
typedef PFNGLTEXCOORD1DVPROC mgl_glTexCoord1dv_t;
typedef PFNGLTEXCOORD1FPROC mgl_glTexCoord1f_t;
typedef PFNGLTEXCOORD1FVPROC mgl_glTexCoord1fv_t;
typedef PFNGLTEXCOORD1IPROC mgl_glTexCoord1i_t;
typedef PFNGLTEXCOORD1IVPROC mgl_glTexCoord1iv_t;
typedef PFNGLTEXCOORD1SPROC mgl_glTexCoord1s_t;
typedef PFNGLTEXCOORD1SVPROC mgl_glTexCoord1sv_t;
typedef PFNGLTEXCOORD2DPROC mgl_glTexCoord2d_t;
typedef PFNGLTEXCOORD2DVPROC mgl_glTexCoord2dv_t;
typedef PFNGLTEXCOORD2FPROC mgl_glTexCoord2f_t;
typedef PFNGLTEXCOORD2FVPROC mgl_glTexCoord2fv_t;
typedef PFNGLTEXCOORD2IPROC mgl_glTexCoord2i_t;
typedef PFNGLTEXCOORD2IVPROC mgl_glTexCoord2iv_t;
typedef PFNGLTEXCOORD2SPROC mgl_glTexCoord2s_t;
typedef PFNGLTEXCOORD2SVPROC mgl_glTexCoord2sv_t;
typedef PFNGLTEXCOORD3DPROC mgl_glTexCoord3d_t;
typedef PFNGLTEXCOORD3DVPROC mgl_glTexCoord3dv_t;
typedef PFNGLTEXCOORD3FPROC mgl_glTexCoord3f_t;
typedef PFNGLTEXCOORD3FVPROC mgl_glTexCoord3fv_t;
typedef PFNGLTEXCOORD3IPROC mgl_glTexCoord3i_t;
typedef PFNGLTEXCOORD3IVPROC mgl_glTexCoord3iv_t;
typedef PFNGLTEXCOORD3SPROC mgl_glTexCoord3s_t;
typedef PFNGLTEXCOORD3SVPROC mgl_glTexCoord3sv_t;
typedef PFNGLTEXCOORD4DPROC mgl_glTexCoord4d_t;
typedef PFNGLTEXCOORD4DVPROC mgl_glTexCoord4dv_t;
typedef PFNGLTEXCOORD4FPROC mgl_glTexCoord4f_t;
typedef PFNGLTEXCOORD4FVPROC mgl_glTexCoord4fv_t;
typedef PFNGLTEXCOORD4IPROC mgl_glTexCoord4i_t;
typedef PFNGLTEXCOORD4IVPROC mgl_glTexCoord4iv_t;
typedef PFNGLTEXCOORD4SPROC mgl_glTexCoord4s_t;
typedef PFNGLTEXCOORD4SVPROC mgl_glTexCoord4sv_t;
typedef PFNGLVERTEX2DPROC mgl_glVertex2d_t;
typedef PFNGLVERTEX2DVPROC mgl_glVertex2dv_t;
typedef PFNGLVERTEX2FPROC mgl_glVertex2f_t;
typedef PFNGLVERTEX2FVPROC mgl_glVertex2fv_t;
typedef PFNGLVERTEX2IPROC mgl_glVertex2i_t;
typedef PFNGLVERTEX2IVPROC mgl_glVertex2iv_t;
typedef PFNGLVERTEX2SPROC mgl_glVertex2s_t;
typedef PFNGLVERTEX2SVPROC mgl_glVertex2sv_t;
typedef PFNGLVERTEX3DPROC mgl_glVertex3d_t;
typedef PFNGLVERTEX3DVPROC mgl_glVertex3dv_t;
typedef PFNGLVERTEX3FPROC mgl_glVertex3f_t;
typedef PFNGLVERTEX3FVPROC mgl_glVertex3fv_t;
typedef PFNGLVERTEX3IPROC mgl_glVertex3i_t;
typedef PFNGLVERTEX3IVPROC mgl_glVertex3iv_t;
typedef PFNGLVERTEX3SPROC mgl_glVertex3s_t;
typedef PFNGLVERTEX3SVPROC mgl_glVertex3sv_t;
typedef PFNGLVERTEX4DPROC mgl_glVertex4d_t;
typedef PFNGLVERTEX4DVPROC mgl_glVertex4dv_t;
typedef PFNGLVERTEX4FPROC mgl_glVertex4f_t;
typedef PFNGLVERTEX4FVPROC mgl_glVertex4fv_t;
typedef PFNGLVERTEX4IPROC mgl_glVertex4i_t;
typedef PFNGLVERTEX4IVPROC mgl_glVertex4iv_t;
typedef PFNGLVERTEX4SPROC mgl_glVertex4s_t;
typedef PFNGLVERTEX4SVPROC mgl_glVertex4sv_t;
typedef PFNGLCLIPPLANEPROC mgl_glClipPlane_t;
typedef PFNGLCOLORMATERIALPROC mgl_glColorMaterial_t;
typedef PFNGLFOGFPROC mgl_glFogf_t;
typedef PFNGLFOGFVPROC mgl_glFogfv_t;
typedef PFNGLFOGIPROC mgl_glFogi_t;
typedef PFNGLFOGIVPROC mgl_glFogiv_t;
typedef PFNGLLIGHTFPROC mgl_glLightf_t;
typedef PFNGLLIGHTFVPROC mgl_glLightfv_t;
typedef PFNGLLIGHTIPROC mgl_glLighti_t;
typedef PFNGLLIGHTIVPROC mgl_glLightiv_t;
typedef PFNGLLIGHTMODELFPROC mgl_glLightModelf_t;
typedef PFNGLLIGHTMODELFVPROC mgl_glLightModelfv_t;
typedef PFNGLLIGHTMODELIPROC mgl_glLightModeli_t;
typedef PFNGLLIGHTMODELIVPROC mgl_glLightModeliv_t;
typedef PFNGLLINESTIPPLEPROC mgl_glLineStipple_t;
typedef PFNGLMATERIALFPROC mgl_glMaterialf_t;
typedef PFNGLMATERIALFVPROC mgl_glMaterialfv_t;
typedef PFNGLMATERIALIPROC mgl_glMateriali_t;
typedef PFNGLMATERIALIVPROC mgl_glMaterialiv_t;
typedef PFNGLPOLYGONSTIPPLEPROC mgl_glPolygonStipple_t;
typedef PFNGLSHADEMODELPROC mgl_glShadeModel_t;
typedef PFNGLTEXENVFPROC mgl_glTexEnvf_t;
typedef PFNGLTEXENVFVPROC mgl_glTexEnvfv_t;
typedef PFNGLTEXENVIPROC mgl_glTexEnvi_t;
typedef PFNGLTEXENVIVPROC mgl_glTexEnviv_t;
typedef PFNGLTEXGENDPROC mgl_glTexGend_t;
typedef PFNGLTEXGENDVPROC mgl_glTexGendv_t;
typedef PFNGLTEXGENFPROC mgl_glTexGenf_t;
typedef PFNGLTEXGENFVPROC mgl_glTexGenfv_t;
typedef PFNGLTEXGENIPROC mgl_glTexGeni_t;
typedef PFNGLTEXGENIVPROC mgl_glTexGeniv_t;
typedef PFNGLFEEDBACKBUFFERPROC mgl_glFeedbackBuffer_t;
typedef PFNGLSELECTBUFFERPROC mgl_glSelectBuffer_t;
typedef PFNGLRENDERMODEPROC mgl_glRenderMode_t;
typedef PFNGLINITNAMESPROC mgl_glInitNames_t;
typedef PFNGLLOADNAMEPROC mgl_glLoadName_t;
typedef PFNGLPASSTHROUGHPROC mgl_glPassThrough_t;
typedef PFNGLPOPNAMEPROC mgl_glPopName_t;
typedef PFNGLPUSHNAMEPROC mgl_glPushName_t;
typedef PFNGLCLEARACCUMPROC mgl_glClearAccum_t;
typedef PFNGLCLEARINDEXPROC mgl_glClearIndex_t;
typedef PFNGLINDEXMASKPROC mgl_glIndexMask_t;
typedef PFNGLACCUMPROC mgl_glAccum_t;
typedef PFNGLPOPATTRIBPROC mgl_glPopAttrib_t;
typedef PFNGLPUSHATTRIBPROC mgl_glPushAttrib_t;
typedef PFNGLMAP1DPROC mgl_glMap1d_t;
typedef PFNGLMAP1FPROC mgl_glMap1f_t;
typedef PFNGLMAP2DPROC mgl_glMap2d_t;
typedef PFNGLMAP2FPROC mgl_glMap2f_t;
typedef PFNGLMAPGRID1DPROC mgl_glMapGrid1d_t;
typedef PFNGLMAPGRID1FPROC mgl_glMapGrid1f_t;
typedef PFNGLMAPGRID2DPROC mgl_glMapGrid2d_t;
typedef PFNGLMAPGRID2FPROC mgl_glMapGrid2f_t;
typedef PFNGLEVALCOORD1DPROC mgl_glEvalCoord1d_t;
typedef PFNGLEVALCOORD1DVPROC mgl_glEvalCoord1dv_t;
typedef PFNGLEVALCOORD1FPROC mgl_glEvalCoord1f_t;
typedef PFNGLEVALCOORD1FVPROC mgl_glEvalCoord1fv_t;
typedef PFNGLEVALCOORD2DPROC mgl_glEvalCoord2d_t;
typedef PFNGLEVALCOORD2DVPROC mgl_glEvalCoord2dv_t;
typedef PFNGLEVALCOORD2FPROC mgl_glEvalCoord2f_t;
typedef PFNGLEVALCOORD2FVPROC mgl_glEvalCoord2fv_t;
typedef PFNGLEVALMESH1PROC mgl_glEvalMesh1_t;
typedef PFNGLEVALPOINT1PROC mgl_glEvalPoint1_t;
typedef PFNGLEVALMESH2PROC mgl_glEvalMesh2_t;
typedef PFNGLEVALPOINT2PROC mgl_glEvalPoint2_t;
typedef PFNGLALPHAFUNCPROC mgl_glAlphaFunc_t;
typedef PFNGLPIXELZOOMPROC mgl_glPixelZoom_t;
typedef PFNGLPIXELTRANSFERFPROC mgl_glPixelTransferf_t;
typedef PFNGLPIXELTRANSFERIPROC mgl_glPixelTransferi_t;
typedef PFNGLPIXELMAPFVPROC mgl_glPixelMapfv_t;
typedef PFNGLPIXELMAPUIVPROC mgl_glPixelMapuiv_t;
typedef PFNGLPIXELMAPUSVPROC mgl_glPixelMapusv_t;
typedef PFNGLCOPYPIXELSPROC mgl_glCopyPixels_t;
typedef PFNGLDRAWPIXELSPROC mgl_glDrawPixels_t;
typedef PFNGLGETCLIPPLANEPROC mgl_glGetClipPlane_t;
typedef PFNGLGETLIGHTFVPROC mgl_glGetLightfv_t;
typedef PFNGLGETLIGHTIVPROC mgl_glGetLightiv_t;
typedef PFNGLGETMAPDVPROC mgl_glGetMapdv_t;
typedef PFNGLGETMAPFVPROC mgl_glGetMapfv_t;
typedef PFNGLGETMAPIVPROC mgl_glGetMapiv_t;
typedef PFNGLGETMATERIALFVPROC mgl_glGetMaterialfv_t;
typedef PFNGLGETMATERIALIVPROC mgl_glGetMaterialiv_t;
typedef PFNGLGETPIXELMAPFVPROC mgl_glGetPixelMapfv_t;
typedef PFNGLGETPIXELMAPUIVPROC mgl_glGetPixelMapuiv_t;
typedef PFNGLGETPIXELMAPUSVPROC mgl_glGetPixelMapusv_t;
typedef PFNGLGETPOLYGONSTIPPLEPROC mgl_glGetPolygonStipple_t;
typedef PFNGLGETTEXENVFVPROC mgl_glGetTexEnvfv_t;
typedef PFNGLGETTEXENVIVPROC mgl_glGetTexEnviv_t;
typedef PFNGLGETTEXGENDVPROC mgl_glGetTexGendv_t;
typedef PFNGLGETTEXGENFVPROC mgl_glGetTexGenfv_t;
typedef PFNGLGETTEXGENIVPROC mgl_glGetTexGeniv_t;
typedef PFNGLISLISTPROC mgl_glIsList_t;
typedef PFNGLFRUSTUMPROC mgl_glFrustum_t;
typedef PFNGLLOADIDENTITYPROC mgl_glLoadIdentity_t;
typedef PFNGLLOADMATRIXFPROC mgl_glLoadMatrixf_t;
typedef PFNGLLOADMATRIXDPROC mgl_glLoadMatrixd_t;
typedef PFNGLMATRIXMODEPROC mgl_glMatrixMode_t;
typedef PFNGLMULTMATRIXFPROC mgl_glMultMatrixf_t;
typedef PFNGLMULTMATRIXDPROC mgl_glMultMatrixd_t;
typedef PFNGLORTHOPROC mgl_glOrtho_t;
typedef PFNGLPOPMATRIXPROC mgl_glPopMatrix_t;
typedef PFNGLPUSHMATRIXPROC mgl_glPushMatrix_t;
typedef PFNGLROTATEDPROC mgl_glRotated_t;
typedef PFNGLROTATEFPROC mgl_glRotatef_t;
typedef PFNGLSCALEDPROC mgl_glScaled_t;
typedef PFNGLSCALEFPROC mgl_glScalef_t;
typedef PFNGLTRANSLATEDPROC mgl_glTranslated_t;
typedef PFNGLTRANSLATEFPROC mgl_glTranslatef_t;
typedef PFNGLDRAWARRAYSPROC mgl_glDrawArrays_t;
typedef PFNGLDRAWELEMENTSPROC mgl_glDrawElements_t;
typedef PFNGLGETPOINTERVPROC mgl_glGetPointerv_t;
typedef PFNGLPOLYGONOFFSETPROC mgl_glPolygonOffset_t;
typedef PFNGLCOPYTEXIMAGE1DPROC mgl_glCopyTexImage1D_t;
typedef PFNGLCOPYTEXIMAGE2DPROC mgl_glCopyTexImage2D_t;
typedef PFNGLCOPYTEXSUBIMAGE1DPROC mgl_glCopyTexSubImage1D_t;
typedef PFNGLCOPYTEXSUBIMAGE2DPROC mgl_glCopyTexSubImage2D_t;
typedef PFNGLTEXSUBIMAGE1DPROC mgl_glTexSubImage1D_t;
typedef PFNGLTEXSUBIMAGE2DPROC mgl_glTexSubImage2D_t;
typedef PFNGLBINDTEXTUREPROC mgl_glBindTexture_t;
typedef PFNGLDELETETEXTURESPROC mgl_glDeleteTextures_t;
typedef PFNGLGENTEXTURESPROC mgl_glGenTextures_t;
typedef PFNGLISTEXTUREPROC mgl_glIsTexture_t;
typedef PFNGLARRAYELEMENTPROC mgl_glArrayElement_t;
typedef PFNGLCOLORPOINTERPROC mgl_glColorPointer_t;
typedef PFNGLDISABLECLIENTSTATEPROC mgl_glDisableClientState_t;
typedef PFNGLEDGEFLAGPOINTERPROC mgl_glEdgeFlagPointer_t;
typedef PFNGLENABLECLIENTSTATEPROC mgl_glEnableClientState_t;
typedef PFNGLINDEXPOINTERPROC mgl_glIndexPointer_t;
typedef PFNGLINTERLEAVEDARRAYSPROC mgl_glInterleavedArrays_t;
typedef PFNGLNORMALPOINTERPROC mgl_glNormalPointer_t;
typedef PFNGLTEXCOORDPOINTERPROC mgl_glTexCoordPointer_t;
typedef PFNGLVERTEXPOINTERPROC mgl_glVertexPointer_t;
typedef PFNGLARETEXTURESRESIDENTPROC mgl_glAreTexturesResident_t;
typedef PFNGLPRIORITIZETEXTURESPROC mgl_glPrioritizeTextures_t;
typedef PFNGLINDEXUBPROC mgl_glIndexub_t;
typedef PFNGLINDEXUBVPROC mgl_glIndexubv_t;
typedef PFNGLPOPCLIENTATTRIBPROC mgl_glPopClientAttrib_t;
typedef PFNGLPUSHCLIENTATTRIBPROC mgl_glPushClientAttrib_t;
typedef PFNGLDRAWRANGEELEMENTSPROC mgl_glDrawRangeElements_t;
typedef PFNGLTEXIMAGE3DPROC mgl_glTexImage3D_t;
typedef PFNGLTEXSUBIMAGE3DPROC mgl_glTexSubImage3D_t;
typedef PFNGLCOPYTEXSUBIMAGE3DPROC mgl_glCopyTexSubImage3D_t;
typedef PFNGLACTIVETEXTUREPROC mgl_glActiveTexture_t;
typedef PFNGLSAMPLECOVERAGEPROC mgl_glSampleCoverage_t;
typedef PFNGLCOMPRESSEDTEXIMAGE3DPROC mgl_glCompressedTexImage3D_t;
typedef PFNGLCOMPRESSEDTEXIMAGE2DPROC mgl_glCompressedTexImage2D_t;
typedef PFNGLCOMPRESSEDTEXIMAGE1DPROC mgl_glCompressedTexImage1D_t;
typedef PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC mgl_glCompressedTexSubImage3D_t;
typedef PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC mgl_glCompressedTexSubImage2D_t;
typedef PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC mgl_glCompressedTexSubImage1D_t;
typedef PFNGLGETCOMPRESSEDTEXIMAGEPROC mgl_glGetCompressedTexImage_t;
typedef PFNGLCLIENTACTIVETEXTUREPROC mgl_glClientActiveTexture_t;
typedef PFNGLMULTITEXCOORD1DPROC mgl_glMultiTexCoord1d_t;
typedef PFNGLMULTITEXCOORD1DVPROC mgl_glMultiTexCoord1dv_t;
typedef PFNGLMULTITEXCOORD1FPROC mgl_glMultiTexCoord1f_t;
typedef PFNGLMULTITEXCOORD1FVPROC mgl_glMultiTexCoord1fv_t;
typedef PFNGLMULTITEXCOORD1IPROC mgl_glMultiTexCoord1i_t;
typedef PFNGLMULTITEXCOORD1IVPROC mgl_glMultiTexCoord1iv_t;
typedef PFNGLMULTITEXCOORD1SPROC mgl_glMultiTexCoord1s_t;
typedef PFNGLMULTITEXCOORD1SVPROC mgl_glMultiTexCoord1sv_t;
typedef PFNGLMULTITEXCOORD2DPROC mgl_glMultiTexCoord2d_t;
typedef PFNGLMULTITEXCOORD2DVPROC mgl_glMultiTexCoord2dv_t;
typedef PFNGLMULTITEXCOORD2FPROC mgl_glMultiTexCoord2f_t;
typedef PFNGLMULTITEXCOORD2FVPROC mgl_glMultiTexCoord2fv_t;
typedef PFNGLMULTITEXCOORD2IPROC mgl_glMultiTexCoord2i_t;
typedef PFNGLMULTITEXCOORD2IVPROC mgl_glMultiTexCoord2iv_t;
typedef PFNGLMULTITEXCOORD2SPROC mgl_glMultiTexCoord2s_t;
typedef PFNGLMULTITEXCOORD2SVPROC mgl_glMultiTexCoord2sv_t;
typedef PFNGLMULTITEXCOORD3DPROC mgl_glMultiTexCoord3d_t;
typedef PFNGLMULTITEXCOORD3DVPROC mgl_glMultiTexCoord3dv_t;
typedef PFNGLMULTITEXCOORD3FPROC mgl_glMultiTexCoord3f_t;
typedef PFNGLMULTITEXCOORD3FVPROC mgl_glMultiTexCoord3fv_t;
typedef PFNGLMULTITEXCOORD3IPROC mgl_glMultiTexCoord3i_t;
typedef PFNGLMULTITEXCOORD3IVPROC mgl_glMultiTexCoord3iv_t;
typedef PFNGLMULTITEXCOORD3SPROC mgl_glMultiTexCoord3s_t;
typedef PFNGLMULTITEXCOORD3SVPROC mgl_glMultiTexCoord3sv_t;
typedef PFNGLMULTITEXCOORD4DPROC mgl_glMultiTexCoord4d_t;
typedef PFNGLMULTITEXCOORD4DVPROC mgl_glMultiTexCoord4dv_t;
typedef PFNGLMULTITEXCOORD4FPROC mgl_glMultiTexCoord4f_t;
typedef PFNGLMULTITEXCOORD4FVPROC mgl_glMultiTexCoord4fv_t;
typedef PFNGLMULTITEXCOORD4IPROC mgl_glMultiTexCoord4i_t;
typedef PFNGLMULTITEXCOORD4IVPROC mgl_glMultiTexCoord4iv_t;
typedef PFNGLMULTITEXCOORD4SPROC mgl_glMultiTexCoord4s_t;
typedef PFNGLMULTITEXCOORD4SVPROC mgl_glMultiTexCoord4sv_t;
typedef PFNGLLOADTRANSPOSEMATRIXFPROC mgl_glLoadTransposeMatrixf_t;
typedef PFNGLLOADTRANSPOSEMATRIXDPROC mgl_glLoadTransposeMatrixd_t;
typedef PFNGLMULTTRANSPOSEMATRIXFPROC mgl_glMultTransposeMatrixf_t;
typedef PFNGLMULTTRANSPOSEMATRIXDPROC mgl_glMultTransposeMatrixd_t;
typedef PFNGLBLENDFUNCSEPARATEPROC mgl_glBlendFuncSeparate_t;
typedef PFNGLMULTIDRAWARRAYSPROC mgl_glMultiDrawArrays_t;
typedef PFNGLMULTIDRAWELEMENTSPROC mgl_glMultiDrawElements_t;
typedef PFNGLPOINTPARAMETERFPROC mgl_glPointParameterf_t;
typedef PFNGLPOINTPARAMETERFVPROC mgl_glPointParameterfv_t;
typedef PFNGLPOINTPARAMETERIPROC mgl_glPointParameteri_t;
typedef PFNGLPOINTPARAMETERIVPROC mgl_glPointParameteriv_t;
typedef PFNGLFOGCOORDFPROC mgl_glFogCoordf_t;
typedef PFNGLFOGCOORDFVPROC mgl_glFogCoordfv_t;
typedef PFNGLFOGCOORDDPROC mgl_glFogCoordd_t;
typedef PFNGLFOGCOORDDVPROC mgl_glFogCoorddv_t;
typedef PFNGLFOGCOORDPOINTERPROC mgl_glFogCoordPointer_t;
typedef PFNGLSECONDARYCOLOR3BPROC mgl_glSecondaryColor3b_t;
typedef PFNGLSECONDARYCOLOR3BVPROC mgl_glSecondaryColor3bv_t;
typedef PFNGLSECONDARYCOLOR3DPROC mgl_glSecondaryColor3d_t;
typedef PFNGLSECONDARYCOLOR3DVPROC mgl_glSecondaryColor3dv_t;
typedef PFNGLSECONDARYCOLOR3FPROC mgl_glSecondaryColor3f_t;
typedef PFNGLSECONDARYCOLOR3FVPROC mgl_glSecondaryColor3fv_t;
typedef PFNGLSECONDARYCOLOR3IPROC mgl_glSecondaryColor3i_t;
typedef PFNGLSECONDARYCOLOR3IVPROC mgl_glSecondaryColor3iv_t;
typedef PFNGLSECONDARYCOLOR3SPROC mgl_glSecondaryColor3s_t;
typedef PFNGLSECONDARYCOLOR3SVPROC mgl_glSecondaryColor3sv_t;
typedef PFNGLSECONDARYCOLOR3UBPROC mgl_glSecondaryColor3ub_t;
typedef PFNGLSECONDARYCOLOR3UBVPROC mgl_glSecondaryColor3ubv_t;
typedef PFNGLSECONDARYCOLOR3UIPROC mgl_glSecondaryColor3ui_t;
typedef PFNGLSECONDARYCOLOR3UIVPROC mgl_glSecondaryColor3uiv_t;
typedef PFNGLSECONDARYCOLOR3USPROC mgl_glSecondaryColor3us_t;
typedef PFNGLSECONDARYCOLOR3USVPROC mgl_glSecondaryColor3usv_t;
typedef PFNGLSECONDARYCOLORPOINTERPROC mgl_glSecondaryColorPointer_t;
typedef PFNGLWINDOWPOS2DPROC mgl_glWindowPos2d_t;
typedef PFNGLWINDOWPOS2DVPROC mgl_glWindowPos2dv_t;
typedef PFNGLWINDOWPOS2FPROC mgl_glWindowPos2f_t;
typedef PFNGLWINDOWPOS2FVPROC mgl_glWindowPos2fv_t;
typedef PFNGLWINDOWPOS2IPROC mgl_glWindowPos2i_t;
typedef PFNGLWINDOWPOS2IVPROC mgl_glWindowPos2iv_t;
typedef PFNGLWINDOWPOS2SPROC mgl_glWindowPos2s_t;
typedef PFNGLWINDOWPOS2SVPROC mgl_glWindowPos2sv_t;
typedef PFNGLWINDOWPOS3DPROC mgl_glWindowPos3d_t;
typedef PFNGLWINDOWPOS3DVPROC mgl_glWindowPos3dv_t;
typedef PFNGLWINDOWPOS3FPROC mgl_glWindowPos3f_t;
typedef PFNGLWINDOWPOS3FVPROC mgl_glWindowPos3fv_t;
typedef PFNGLWINDOWPOS3IPROC mgl_glWindowPos3i_t;
typedef PFNGLWINDOWPOS3IVPROC mgl_glWindowPos3iv_t;
typedef PFNGLWINDOWPOS3SPROC mgl_glWindowPos3s_t;
typedef PFNGLWINDOWPOS3SVPROC mgl_glWindowPos3sv_t;
typedef PFNGLBLENDCOLORPROC mgl_glBlendColor_t;
typedef PFNGLBLENDEQUATIONPROC mgl_glBlendEquation_t;
typedef PFNGLGENQUERIESPROC mgl_glGenQueries_t;
typedef PFNGLDELETEQUERIESPROC mgl_glDeleteQueries_t;
typedef PFNGLISQUERYPROC mgl_glIsQuery_t;
typedef PFNGLBEGINQUERYPROC mgl_glBeginQuery_t;
typedef PFNGLENDQUERYPROC mgl_glEndQuery_t;
typedef PFNGLGETQUERYIVPROC mgl_glGetQueryiv_t;
typedef PFNGLGETQUERYOBJECTIVPROC mgl_glGetQueryObjectiv_t;
typedef PFNGLGETQUERYOBJECTUIVPROC mgl_glGetQueryObjectuiv_t;
typedef PFNGLBINDBUFFERPROC mgl_glBindBuffer_t;
typedef PFNGLDELETEBUFFERSPROC mgl_glDeleteBuffers_t;
typedef PFNGLGENBUFFERSPROC mgl_glGenBuffers_t;
typedef PFNGLISBUFFERPROC mgl_glIsBuffer_t;
typedef PFNGLBUFFERDATAPROC mgl_glBufferData_t;
typedef PFNGLBUFFERSUBDATAPROC mgl_glBufferSubData_t;
typedef PFNGLGETBUFFERSUBDATAPROC mgl_glGetBufferSubData_t;
typedef PFNGLMAPBUFFERPROC mgl_glMapBuffer_t;
typedef PFNGLUNMAPBUFFERPROC mgl_glUnmapBuffer_t;
typedef PFNGLGETBUFFERPARAMETERIVPROC mgl_glGetBufferParameteriv_t;
typedef PFNGLGETBUFFERPOINTERVPROC mgl_glGetBufferPointerv_t;
typedef PFNGLBLENDEQUATIONSEPARATEPROC mgl_glBlendEquationSeparate_t;
typedef PFNGLDRAWBUFFERSPROC mgl_glDrawBuffers_t;
typedef PFNGLSTENCILOPSEPARATEPROC mgl_glStencilOpSeparate_t;
typedef PFNGLSTENCILFUNCSEPARATEPROC mgl_glStencilFuncSeparate_t;
typedef PFNGLSTENCILMASKSEPARATEPROC mgl_glStencilMaskSeparate_t;
typedef PFNGLATTACHSHADERPROC mgl_glAttachShader_t;
typedef PFNGLBINDATTRIBLOCATIONPROC mgl_glBindAttribLocation_t;
typedef PFNGLCOMPILESHADERPROC mgl_glCompileShader_t;
typedef PFNGLCREATEPROGRAMPROC mgl_glCreateProgram_t;
typedef PFNGLCREATESHADERPROC mgl_glCreateShader_t;
typedef PFNGLDELETEPROGRAMPROC mgl_glDeleteProgram_t;
typedef PFNGLDELETESHADERPROC mgl_glDeleteShader_t;
typedef PFNGLDETACHSHADERPROC mgl_glDetachShader_t;
typedef PFNGLDISABLEVERTEXATTRIBARRAYPROC mgl_glDisableVertexAttribArray_t;
typedef PFNGLENABLEVERTEXATTRIBARRAYPROC mgl_glEnableVertexAttribArray_t;
typedef PFNGLGETACTIVEATTRIBPROC mgl_glGetActiveAttrib_t;
typedef PFNGLGETACTIVEUNIFORMPROC mgl_glGetActiveUniform_t;
typedef PFNGLGETATTACHEDSHADERSPROC mgl_glGetAttachedShaders_t;
typedef PFNGLGETATTRIBLOCATIONPROC mgl_glGetAttribLocation_t;
typedef PFNGLGETPROGRAMIVPROC mgl_glGetProgramiv_t;
typedef PFNGLGETPROGRAMINFOLOGPROC mgl_glGetProgramInfoLog_t;
typedef PFNGLGETSHADERIVPROC mgl_glGetShaderiv_t;
typedef PFNGLGETSHADERINFOLOGPROC mgl_glGetShaderInfoLog_t;
typedef PFNGLGETSHADERSOURCEPROC mgl_glGetShaderSource_t;
typedef PFNGLGETUNIFORMLOCATIONPROC mgl_glGetUniformLocation_t;
typedef PFNGLGETUNIFORMFVPROC mgl_glGetUniformfv_t;
typedef PFNGLGETUNIFORMIVPROC mgl_glGetUniformiv_t;
typedef PFNGLGETVERTEXATTRIBDVPROC mgl_glGetVertexAttribdv_t;
typedef PFNGLGETVERTEXATTRIBFVPROC mgl_glGetVertexAttribfv_t;
typedef PFNGLGETVERTEXATTRIBIVPROC mgl_glGetVertexAttribiv_t;
typedef PFNGLGETVERTEXATTRIBPOINTERVPROC mgl_glGetVertexAttribPointerv_t;
typedef PFNGLISPROGRAMPROC mgl_glIsProgram_t;
typedef PFNGLISSHADERPROC mgl_glIsShader_t;
typedef PFNGLLINKPROGRAMPROC mgl_glLinkProgram_t;
typedef PFNGLSHADERSOURCEPROC mgl_glShaderSource_t;
typedef PFNGLUSEPROGRAMPROC mgl_glUseProgram_t;
typedef PFNGLUNIFORM1FPROC mgl_glUniform1f_t;
typedef PFNGLUNIFORM2FPROC mgl_glUniform2f_t;
typedef PFNGLUNIFORM3FPROC mgl_glUniform3f_t;
typedef PFNGLUNIFORM4FPROC mgl_glUniform4f_t;
typedef PFNGLUNIFORM1IPROC mgl_glUniform1i_t;
typedef PFNGLUNIFORM2IPROC mgl_glUniform2i_t;
typedef PFNGLUNIFORM3IPROC mgl_glUniform3i_t;
typedef PFNGLUNIFORM4IPROC mgl_glUniform4i_t;
typedef PFNGLUNIFORM1FVPROC mgl_glUniform1fv_t;
typedef PFNGLUNIFORM2FVPROC mgl_glUniform2fv_t;
typedef PFNGLUNIFORM3FVPROC mgl_glUniform3fv_t;
typedef PFNGLUNIFORM4FVPROC mgl_glUniform4fv_t;
typedef PFNGLUNIFORM1IVPROC mgl_glUniform1iv_t;
typedef PFNGLUNIFORM2IVPROC mgl_glUniform2iv_t;
typedef PFNGLUNIFORM3IVPROC mgl_glUniform3iv_t;
typedef PFNGLUNIFORM4IVPROC mgl_glUniform4iv_t;
typedef PFNGLUNIFORMMATRIX2FVPROC mgl_glUniformMatrix2fv_t;
typedef PFNGLUNIFORMMATRIX3FVPROC mgl_glUniformMatrix3fv_t;
typedef PFNGLUNIFORMMATRIX4FVPROC mgl_glUniformMatrix4fv_t;
typedef PFNGLVALIDATEPROGRAMPROC mgl_glValidateProgram_t;
typedef PFNGLVERTEXATTRIB1DPROC mgl_glVertexAttrib1d_t;
typedef PFNGLVERTEXATTRIB1DVPROC mgl_glVertexAttrib1dv_t;
typedef PFNGLVERTEXATTRIB1FPROC mgl_glVertexAttrib1f_t;
typedef PFNGLVERTEXATTRIB1FVPROC mgl_glVertexAttrib1fv_t;
typedef PFNGLVERTEXATTRIB1SPROC mgl_glVertexAttrib1s_t;
typedef PFNGLVERTEXATTRIB1SVPROC mgl_glVertexAttrib1sv_t;
typedef PFNGLVERTEXATTRIB2DPROC mgl_glVertexAttrib2d_t;
typedef PFNGLVERTEXATTRIB2DVPROC mgl_glVertexAttrib2dv_t;
typedef PFNGLVERTEXATTRIB2FPROC mgl_glVertexAttrib2f_t;
typedef PFNGLVERTEXATTRIB2FVPROC mgl_glVertexAttrib2fv_t;
typedef PFNGLVERTEXATTRIB2SPROC mgl_glVertexAttrib2s_t;
typedef PFNGLVERTEXATTRIB2SVPROC mgl_glVertexAttrib2sv_t;
typedef PFNGLVERTEXATTRIB3DPROC mgl_glVertexAttrib3d_t;
typedef PFNGLVERTEXATTRIB3DVPROC mgl_glVertexAttrib3dv_t;
typedef PFNGLVERTEXATTRIB3FPROC mgl_glVertexAttrib3f_t;
typedef PFNGLVERTEXATTRIB3FVPROC mgl_glVertexAttrib3fv_t;
typedef PFNGLVERTEXATTRIB3SPROC mgl_glVertexAttrib3s_t;
typedef PFNGLVERTEXATTRIB3SVPROC mgl_glVertexAttrib3sv_t;
typedef PFNGLVERTEXATTRIB4NBVPROC mgl_glVertexAttrib4Nbv_t;
typedef PFNGLVERTEXATTRIB4NIVPROC mgl_glVertexAttrib4Niv_t;
typedef PFNGLVERTEXATTRIB4NSVPROC mgl_glVertexAttrib4Nsv_t;
typedef PFNGLVERTEXATTRIB4NUBPROC mgl_glVertexAttrib4Nub_t;
typedef PFNGLVERTEXATTRIB4NUBVPROC mgl_glVertexAttrib4Nubv_t;
typedef PFNGLVERTEXATTRIB4NUIVPROC mgl_glVertexAttrib4Nuiv_t;
typedef PFNGLVERTEXATTRIB4NUSVPROC mgl_glVertexAttrib4Nusv_t;
typedef PFNGLVERTEXATTRIB4BVPROC mgl_glVertexAttrib4bv_t;
typedef PFNGLVERTEXATTRIB4DPROC mgl_glVertexAttrib4d_t;
typedef PFNGLVERTEXATTRIB4DVPROC mgl_glVertexAttrib4dv_t;
typedef PFNGLVERTEXATTRIB4FPROC mgl_glVertexAttrib4f_t;
typedef PFNGLVERTEXATTRIB4FVPROC mgl_glVertexAttrib4fv_t;
typedef PFNGLVERTEXATTRIB4IVPROC mgl_glVertexAttrib4iv_t;
typedef PFNGLVERTEXATTRIB4SPROC mgl_glVertexAttrib4s_t;
typedef PFNGLVERTEXATTRIB4SVPROC mgl_glVertexAttrib4sv_t;
typedef PFNGLVERTEXATTRIB4UBVPROC mgl_glVertexAttrib4ubv_t;
typedef PFNGLVERTEXATTRIB4UIVPROC mgl_glVertexAttrib4uiv_t;
typedef PFNGLVERTEXATTRIB4USVPROC mgl_glVertexAttrib4usv_t;
typedef PFNGLVERTEXATTRIBPOINTERPROC mgl_glVertexAttribPointer_t;
typedef PFNGLUNIFORMMATRIX2X3FVPROC mgl_glUniformMatrix2x3fv_t;
typedef PFNGLUNIFORMMATRIX3X2FVPROC mgl_glUniformMatrix3x2fv_t;
typedef PFNGLUNIFORMMATRIX2X4FVPROC mgl_glUniformMatrix2x4fv_t;
typedef PFNGLUNIFORMMATRIX4X2FVPROC mgl_glUniformMatrix4x2fv_t;
typedef PFNGLUNIFORMMATRIX3X4FVPROC mgl_glUniformMatrix3x4fv_t;
typedef PFNGLUNIFORMMATRIX4X3FVPROC mgl_glUniformMatrix4x3fv_t;
typedef PFNGLCOLORMASKIPROC mgl_glColorMaski_t;
typedef PFNGLGETBOOLEANI_VPROC mgl_glGetBooleani_v_t;
typedef PFNGLGETINTEGERI_VPROC mgl_glGetIntegeri_v_t;
typedef PFNGLENABLEIPROC mgl_glEnablei_t;
typedef PFNGLDISABLEIPROC mgl_glDisablei_t;
typedef PFNGLISENABLEDIPROC mgl_glIsEnabledi_t;
typedef PFNGLBEGINTRANSFORMFEEDBACKPROC mgl_glBeginTransformFeedback_t;
typedef PFNGLENDTRANSFORMFEEDBACKPROC mgl_glEndTransformFeedback_t;
typedef PFNGLBINDBUFFERRANGEPROC mgl_glBindBufferRange_t;
typedef PFNGLBINDBUFFERBASEPROC mgl_glBindBufferBase_t;
typedef PFNGLTRANSFORMFEEDBACKVARYINGSPROC mgl_glTransformFeedbackVaryings_t;
typedef PFNGLGETTRANSFORMFEEDBACKVARYINGPROC mgl_glGetTransformFeedbackVarying_t;
typedef PFNGLCLAMPCOLORPROC mgl_glClampColor_t;
typedef PFNGLBEGINCONDITIONALRENDERPROC mgl_glBeginConditionalRender_t;
typedef PFNGLENDCONDITIONALRENDERPROC mgl_glEndConditionalRender_t;
typedef PFNGLVERTEXATTRIBIPOINTERPROC mgl_glVertexAttribIPointer_t;
typedef PFNGLGETVERTEXATTRIBIIVPROC mgl_glGetVertexAttribIiv_t;
typedef PFNGLGETVERTEXATTRIBIUIVPROC mgl_glGetVertexAttribIuiv_t;
typedef PFNGLVERTEXATTRIBI1IPROC mgl_glVertexAttribI1i_t;
typedef PFNGLVERTEXATTRIBI2IPROC mgl_glVertexAttribI2i_t;
typedef PFNGLVERTEXATTRIBI3IPROC mgl_glVertexAttribI3i_t;
typedef PFNGLVERTEXATTRIBI4IPROC mgl_glVertexAttribI4i_t;
typedef PFNGLVERTEXATTRIBI1UIPROC mgl_glVertexAttribI1ui_t;
typedef PFNGLVERTEXATTRIBI2UIPROC mgl_glVertexAttribI2ui_t;
typedef PFNGLVERTEXATTRIBI3UIPROC mgl_glVertexAttribI3ui_t;
typedef PFNGLVERTEXATTRIBI4UIPROC mgl_glVertexAttribI4ui_t;
typedef PFNGLVERTEXATTRIBI1IVPROC mgl_glVertexAttribI1iv_t;
typedef PFNGLVERTEXATTRIBI2IVPROC mgl_glVertexAttribI2iv_t;
typedef PFNGLVERTEXATTRIBI3IVPROC mgl_glVertexAttribI3iv_t;
typedef PFNGLVERTEXATTRIBI4IVPROC mgl_glVertexAttribI4iv_t;
typedef PFNGLVERTEXATTRIBI1UIVPROC mgl_glVertexAttribI1uiv_t;
typedef PFNGLVERTEXATTRIBI2UIVPROC mgl_glVertexAttribI2uiv_t;
typedef PFNGLVERTEXATTRIBI3UIVPROC mgl_glVertexAttribI3uiv_t;
typedef PFNGLVERTEXATTRIBI4UIVPROC mgl_glVertexAttribI4uiv_t;
typedef PFNGLVERTEXATTRIBI4BVPROC mgl_glVertexAttribI4bv_t;
typedef PFNGLVERTEXATTRIBI4SVPROC mgl_glVertexAttribI4sv_t;
typedef PFNGLVERTEXATTRIBI4UBVPROC mgl_glVertexAttribI4ubv_t;
typedef PFNGLVERTEXATTRIBI4USVPROC mgl_glVertexAttribI4usv_t;
typedef PFNGLGETUNIFORMUIVPROC mgl_glGetUniformuiv_t;
typedef PFNGLBINDFRAGDATALOCATIONPROC mgl_glBindFragDataLocation_t;
typedef PFNGLGETFRAGDATALOCATIONPROC mgl_glGetFragDataLocation_t;
typedef PFNGLUNIFORM1UIPROC mgl_glUniform1ui_t;
typedef PFNGLUNIFORM2UIPROC mgl_glUniform2ui_t;
typedef PFNGLUNIFORM3UIPROC mgl_glUniform3ui_t;
typedef PFNGLUNIFORM4UIPROC mgl_glUniform4ui_t;
typedef PFNGLUNIFORM1UIVPROC mgl_glUniform1uiv_t;
typedef PFNGLUNIFORM2UIVPROC mgl_glUniform2uiv_t;
typedef PFNGLUNIFORM3UIVPROC mgl_glUniform3uiv_t;
typedef PFNGLUNIFORM4UIVPROC mgl_glUniform4uiv_t;
typedef PFNGLTEXPARAMETERIIVPROC mgl_glTexParameterIiv_t;
typedef PFNGLTEXPARAMETERIUIVPROC mgl_glTexParameterIuiv_t;
typedef PFNGLGETTEXPARAMETERIIVPROC mgl_glGetTexParameterIiv_t;
typedef PFNGLGETTEXPARAMETERIUIVPROC mgl_glGetTexParameterIuiv_t;
typedef PFNGLCLEARBUFFERIVPROC mgl_glClearBufferiv_t;
typedef PFNGLCLEARBUFFERUIVPROC mgl_glClearBufferuiv_t;
typedef PFNGLCLEARBUFFERFVPROC mgl_glClearBufferfv_t;
typedef PFNGLCLEARBUFFERFIPROC mgl_glClearBufferfi_t;
typedef PFNGLGETSTRINGIPROC mgl_glGetStringi_t;
typedef PFNGLISRENDERBUFFERPROC mgl_glIsRenderbuffer_t;
typedef PFNGLBINDRENDERBUFFERPROC mgl_glBindRenderbuffer_t;
typedef PFNGLDELETERENDERBUFFERSPROC mgl_glDeleteRenderbuffers_t;
typedef PFNGLGENRENDERBUFFERSPROC mgl_glGenRenderbuffers_t;
typedef PFNGLRENDERBUFFERSTORAGEPROC mgl_glRenderbufferStorage_t;
typedef PFNGLGETRENDERBUFFERPARAMETERIVPROC mgl_glGetRenderbufferParameteriv_t;
typedef PFNGLISFRAMEBUFFERPROC mgl_glIsFramebuffer_t;
typedef PFNGLBINDFRAMEBUFFERPROC mgl_glBindFramebuffer_t;
typedef PFNGLDELETEFRAMEBUFFERSPROC mgl_glDeleteFramebuffers_t;
typedef PFNGLGENFRAMEBUFFERSPROC mgl_glGenFramebuffers_t;
typedef PFNGLCHECKFRAMEBUFFERSTATUSPROC mgl_glCheckFramebufferStatus_t;
typedef PFNGLFRAMEBUFFERTEXTURE1DPROC mgl_glFramebufferTexture1D_t;
typedef PFNGLFRAMEBUFFERTEXTURE2DPROC mgl_glFramebufferTexture2D_t;
typedef PFNGLFRAMEBUFFERTEXTURE3DPROC mgl_glFramebufferTexture3D_t;
typedef PFNGLFRAMEBUFFERRENDERBUFFERPROC mgl_glFramebufferRenderbuffer_t;
typedef PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC mgl_glGetFramebufferAttachmentParameteriv_t;
typedef PFNGLGENERATEMIPMAPPROC mgl_glGenerateMipmap_t;
typedef PFNGLBLITFRAMEBUFFERPROC mgl_glBlitFramebuffer_t;
typedef PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC mgl_glRenderbufferStorageMultisample_t;
typedef PFNGLFRAMEBUFFERTEXTURELAYERPROC mgl_glFramebufferTextureLayer_t;
typedef PFNGLMAPBUFFERRANGEPROC mgl_glMapBufferRange_t;
typedef PFNGLFLUSHMAPPEDBUFFERRANGEPROC mgl_glFlushMappedBufferRange_t;
typedef PFNGLBINDVERTEXARRAYPROC mgl_glBindVertexArray_t;
typedef PFNGLDELETEVERTEXARRAYSPROC mgl_glDeleteVertexArrays_t;
typedef PFNGLGENVERTEXARRAYSPROC mgl_glGenVertexArrays_t;
typedef PFNGLISVERTEXARRAYPROC mgl_glIsVertexArray_t;
typedef PFNGLDRAWARRAYSINSTANCEDPROC mgl_glDrawArraysInstanced_t;
typedef PFNGLDRAWELEMENTSINSTANCEDPROC mgl_glDrawElementsInstanced_t;
typedef PFNGLTEXBUFFERPROC mgl_glTexBuffer_t;
typedef PFNGLPRIMITIVERESTARTINDEXPROC mgl_glPrimitiveRestartIndex_t;
typedef PFNGLCOPYBUFFERSUBDATAPROC mgl_glCopyBufferSubData_t;
typedef PFNGLGETUNIFORMINDICESPROC mgl_glGetUniformIndices_t;
typedef PFNGLGETACTIVEUNIFORMSIVPROC mgl_glGetActiveUniformsiv_t;
typedef PFNGLGETACTIVEUNIFORMNAMEPROC mgl_glGetActiveUniformName_t;
typedef PFNGLGETUNIFORMBLOCKINDEXPROC mgl_glGetUniformBlockIndex_t;
typedef PFNGLGETACTIVEUNIFORMBLOCKIVPROC mgl_glGetActiveUniformBlockiv_t;
typedef PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC mgl_glGetActiveUniformBlockName_t;
typedef PFNGLUNIFORMBLOCKBINDINGPROC mgl_glUniformBlockBinding_t;
typedef PFNGLDRAWELEMENTSBASEVERTEXPROC mgl_glDrawElementsBaseVertex_t;
typedef PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC mgl_glDrawRangeElementsBaseVertex_t;
typedef PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC mgl_glDrawElementsInstancedBaseVertex_t;
typedef PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC mgl_glMultiDrawElementsBaseVertex_t;
typedef PFNGLPROVOKINGVERTEXPROC mgl_glProvokingVertex_t;
typedef PFNGLFENCESYNCPROC mgl_glFenceSync_t;
typedef PFNGLISSYNCPROC mgl_glIsSync_t;
typedef PFNGLDELETESYNCPROC mgl_glDeleteSync_t;
typedef PFNGLCLIENTWAITSYNCPROC mgl_glClientWaitSync_t;
typedef PFNGLWAITSYNCPROC mgl_glWaitSync_t;
typedef PFNGLGETINTEGER64VPROC mgl_glGetInteger64v_t;
typedef PFNGLGETSYNCIVPROC mgl_glGetSynciv_t;
typedef PFNGLGETINTEGER64I_VPROC mgl_glGetInteger64i_v_t;
typedef PFNGLGETBUFFERPARAMETERI64VPROC mgl_glGetBufferParameteri64v_t;
typedef PFNGLFRAMEBUFFERTEXTUREPROC mgl_glFramebufferTexture_t;
typedef PFNGLTEXIMAGE2DMULTISAMPLEPROC mgl_glTexImage2DMultisample_t;
typedef PFNGLTEXIMAGE3DMULTISAMPLEPROC mgl_glTexImage3DMultisample_t;
typedef PFNGLGETMULTISAMPLEFVPROC mgl_glGetMultisamplefv_t;
typedef PFNGLSAMPLEMASKIPROC mgl_glSampleMaski_t;
typedef PFNGLBINDFRAGDATALOCATIONINDEXEDPROC mgl_glBindFragDataLocationIndexed_t;
typedef PFNGLGETFRAGDATAINDEXPROC mgl_glGetFragDataIndex_t;
typedef PFNGLGENSAMPLERSPROC mgl_glGenSamplers_t;
typedef PFNGLDELETESAMPLERSPROC mgl_glDeleteSamplers_t;
typedef PFNGLISSAMPLERPROC mgl_glIsSampler_t;
typedef PFNGLBINDSAMPLERPROC mgl_glBindSampler_t;
typedef PFNGLSAMPLERPARAMETERIPROC mgl_glSamplerParameteri_t;
typedef PFNGLSAMPLERPARAMETERIVPROC mgl_glSamplerParameteriv_t;
typedef PFNGLSAMPLERPARAMETERFPROC mgl_glSamplerParameterf_t;
typedef PFNGLSAMPLERPARAMETERFVPROC mgl_glSamplerParameterfv_t;
typedef PFNGLSAMPLERPARAMETERIIVPROC mgl_glSamplerParameterIiv_t;
typedef PFNGLSAMPLERPARAMETERIUIVPROC mgl_glSamplerParameterIuiv_t;
typedef PFNGLGETSAMPLERPARAMETERIVPROC mgl_glGetSamplerParameteriv_t;
typedef PFNGLGETSAMPLERPARAMETERIIVPROC mgl_glGetSamplerParameterIiv_t;
typedef PFNGLGETSAMPLERPARAMETERFVPROC mgl_glGetSamplerParameterfv_t;
typedef PFNGLGETSAMPLERPARAMETERIUIVPROC mgl_glGetSamplerParameterIuiv_t;
typedef PFNGLQUERYCOUNTERPROC mgl_glQueryCounter_t;
typedef PFNGLGETQUERYOBJECTI64VPROC mgl_glGetQueryObjecti64v_t;
typedef PFNGLGETQUERYOBJECTUI64VPROC mgl_glGetQueryObjectui64v_t;
typedef PFNGLVERTEXATTRIBDIVISORPROC mgl_glVertexAttribDivisor_t;
typedef PFNGLVERTEXATTRIBP1UIPROC mgl_glVertexAttribP1ui_t;
typedef PFNGLVERTEXATTRIBP1UIVPROC mgl_glVertexAttribP1uiv_t;
typedef PFNGLVERTEXATTRIBP2UIPROC mgl_glVertexAttribP2ui_t;
typedef PFNGLVERTEXATTRIBP2UIVPROC mgl_glVertexAttribP2uiv_t;
typedef PFNGLVERTEXATTRIBP3UIPROC mgl_glVertexAttribP3ui_t;
typedef PFNGLVERTEXATTRIBP3UIVPROC mgl_glVertexAttribP3uiv_t;
typedef PFNGLVERTEXATTRIBP4UIPROC mgl_glVertexAttribP4ui_t;
typedef PFNGLVERTEXATTRIBP4UIVPROC mgl_glVertexAttribP4uiv_t;
typedef PFNGLMINSAMPLESHADINGPROC mgl_glMinSampleShading_t;
typedef PFNGLBLENDEQUATIONIPROC mgl_glBlendEquationi_t;
typedef PFNGLBLENDEQUATIONSEPARATEIPROC mgl_glBlendEquationSeparatei_t;
typedef PFNGLBLENDFUNCIPROC mgl_glBlendFunci_t;
typedef PFNGLBLENDFUNCSEPARATEIPROC mgl_glBlendFuncSeparatei_t;
typedef PFNGLDRAWARRAYSINDIRECTPROC mgl_glDrawArraysIndirect_t;
typedef PFNGLDRAWELEMENTSINDIRECTPROC mgl_glDrawElementsIndirect_t;
typedef PFNGLUNIFORM1DPROC mgl_glUniform1d_t;
typedef PFNGLUNIFORM2DPROC mgl_glUniform2d_t;
typedef PFNGLUNIFORM3DPROC mgl_glUniform3d_t;
typedef PFNGLUNIFORM4DPROC mgl_glUniform4d_t;
typedef PFNGLUNIFORM1DVPROC mgl_glUniform1dv_t;
typedef PFNGLUNIFORM2DVPROC mgl_glUniform2dv_t;
typedef PFNGLUNIFORM3DVPROC mgl_glUniform3dv_t;
typedef PFNGLUNIFORM4DVPROC mgl_glUniform4dv_t;
typedef PFNGLUNIFORMMATRIX2DVPROC mgl_glUniformMatrix2dv_t;
typedef PFNGLUNIFORMMATRIX3DVPROC mgl_glUniformMatrix3dv_t;
typedef PFNGLUNIFORMMATRIX4DVPROC mgl_glUniformMatrix4dv_t;
typedef PFNGLUNIFORMMATRIX2X3DVPROC mgl_glUniformMatrix2x3dv_t;
typedef PFNGLUNIFORMMATRIX2X4DVPROC mgl_glUniformMatrix2x4dv_t;
typedef PFNGLUNIFORMMATRIX3X2DVPROC mgl_glUniformMatrix3x2dv_t;
typedef PFNGLUNIFORMMATRIX3X4DVPROC mgl_glUniformMatrix3x4dv_t;
typedef PFNGLUNIFORMMATRIX4X2DVPROC mgl_glUniformMatrix4x2dv_t;
typedef PFNGLUNIFORMMATRIX4X3DVPROC mgl_glUniformMatrix4x3dv_t;
typedef PFNGLGETUNIFORMDVPROC mgl_glGetUniformdv_t;
typedef PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC mgl_glGetSubroutineUniformLocation_t;
typedef PFNGLGETSUBROUTINEINDEXPROC mgl_glGetSubroutineIndex_t;
typedef PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC mgl_glGetActiveSubroutineUniformiv_t;
typedef PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC mgl_glGetActiveSubroutineUniformName_t;
typedef PFNGLGETACTIVESUBROUTINENAMEPROC mgl_glGetActiveSubroutineName_t;
typedef PFNGLUNIFORMSUBROUTINESUIVPROC mgl_glUniformSubroutinesuiv_t;
typedef PFNGLGETUNIFORMSUBROUTINEUIVPROC mgl_glGetUniformSubroutineuiv_t;
typedef PFNGLGETPROGRAMSTAGEIVPROC mgl_glGetProgramStageiv_t;
typedef PFNGLPATCHPARAMETERIPROC mgl_glPatchParameteri_t;
typedef PFNGLPATCHPARAMETERFVPROC mgl_glPatchParameterfv_t;
typedef PFNGLBINDTRANSFORMFEEDBACKPROC mgl_glBindTransformFeedback_t;
typedef PFNGLDELETETRANSFORMFEEDBACKSPROC mgl_glDeleteTransformFeedbacks_t;
typedef PFNGLGENTRANSFORMFEEDBACKSPROC mgl_glGenTransformFeedbacks_t;
typedef PFNGLISTRANSFORMFEEDBACKPROC mgl_glIsTransformFeedback_t;
typedef PFNGLPAUSETRANSFORMFEEDBACKPROC mgl_glPauseTransformFeedback_t;
typedef PFNGLRESUMETRANSFORMFEEDBACKPROC mgl_glResumeTransformFeedback_t;
typedef PFNGLDRAWTRANSFORMFEEDBACKPROC mgl_glDrawTransformFeedback_t;
typedef PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC mgl_glDrawTransformFeedbackStream_t;
typedef PFNGLBEGINQUERYINDEXEDPROC mgl_glBeginQueryIndexed_t;
typedef PFNGLENDQUERYINDEXEDPROC mgl_glEndQueryIndexed_t;
typedef PFNGLGETQUERYINDEXEDIVPROC mgl_glGetQueryIndexediv_t;
typedef PFNGLRELEASESHADERCOMPILERPROC mgl_glReleaseShaderCompiler_t;
typedef PFNGLSHADERBINARYPROC mgl_glShaderBinary_t;
typedef PFNGLGETSHADERPRECISIONFORMATPROC mgl_glGetShaderPrecisionFormat_t;
typedef PFNGLDEPTHRANGEFPROC mgl_glDepthRangef_t;
typedef PFNGLCLEARDEPTHFPROC mgl_glClearDepthf_t;
typedef PFNGLGETPROGRAMBINARYPROC mgl_glGetProgramBinary_t;
typedef PFNGLPROGRAMBINARYPROC mgl_glProgramBinary_t;
typedef PFNGLPROGRAMPARAMETERIPROC mgl_glProgramParameteri_t;
typedef PFNGLUSEPROGRAMSTAGESPROC mgl_glUseProgramStages_t;
typedef PFNGLACTIVESHADERPROGRAMPROC mgl_glActiveShaderProgram_t;
typedef PFNGLCREATESHADERPROGRAMVPROC mgl_glCreateShaderProgramv_t;
typedef PFNGLBINDPROGRAMPIPELINEPROC mgl_glBindProgramPipeline_t;
typedef PFNGLDELETEPROGRAMPIPELINESPROC mgl_glDeleteProgramPipelines_t;
typedef PFNGLGENPROGRAMPIPELINESPROC mgl_glGenProgramPipelines_t;
typedef PFNGLISPROGRAMPIPELINEPROC mgl_glIsProgramPipeline_t;
typedef PFNGLGETPROGRAMPIPELINEIVPROC mgl_glGetProgramPipelineiv_t;
typedef PFNGLPROGRAMUNIFORM1IPROC mgl_glProgramUniform1i_t;
typedef PFNGLPROGRAMUNIFORM1IVPROC mgl_glProgramUniform1iv_t;
typedef PFNGLPROGRAMUNIFORM1FPROC mgl_glProgramUniform1f_t;
typedef PFNGLPROGRAMUNIFORM1FVPROC mgl_glProgramUniform1fv_t;
typedef PFNGLPROGRAMUNIFORM1DPROC mgl_glProgramUniform1d_t;
typedef PFNGLPROGRAMUNIFORM1DVPROC mgl_glProgramUniform1dv_t;
typedef PFNGLPROGRAMUNIFORM1UIPROC mgl_glProgramUniform1ui_t;
typedef PFNGLPROGRAMUNIFORM1UIVPROC mgl_glProgramUniform1uiv_t;
typedef PFNGLPROGRAMUNIFORM2IPROC mgl_glProgramUniform2i_t;
typedef PFNGLPROGRAMUNIFORM2IVPROC mgl_glProgramUniform2iv_t;
typedef PFNGLPROGRAMUNIFORM2FPROC mgl_glProgramUniform2f_t;
typedef PFNGLPROGRAMUNIFORM2FVPROC mgl_glProgramUniform2fv_t;
typedef PFNGLPROGRAMUNIFORM2DPROC mgl_glProgramUniform2d_t;
typedef PFNGLPROGRAMUNIFORM2DVPROC mgl_glProgramUniform2dv_t;
typedef PFNGLPROGRAMUNIFORM2UIPROC mgl_glProgramUniform2ui_t;
typedef PFNGLPROGRAMUNIFORM2UIVPROC mgl_glProgramUniform2uiv_t;
typedef PFNGLPROGRAMUNIFORM3IPROC mgl_glProgramUniform3i_t;
typedef PFNGLPROGRAMUNIFORM3IVPROC mgl_glProgramUniform3iv_t;
typedef PFNGLPROGRAMUNIFORM3FPROC mgl_glProgramUniform3f_t;
typedef PFNGLPROGRAMUNIFORM3FVPROC mgl_glProgramUniform3fv_t;
typedef PFNGLPROGRAMUNIFORM3DPROC mgl_glProgramUniform3d_t;
typedef PFNGLPROGRAMUNIFORM3DVPROC mgl_glProgramUniform3dv_t;
typedef PFNGLPROGRAMUNIFORM3UIPROC mgl_glProgramUniform3ui_t;
typedef PFNGLPROGRAMUNIFORM3UIVPROC mgl_glProgramUniform3uiv_t;
typedef PFNGLPROGRAMUNIFORM4IPROC mgl_glProgramUniform4i_t;
typedef PFNGLPROGRAMUNIFORM4IVPROC mgl_glProgramUniform4iv_t;
typedef PFNGLPROGRAMUNIFORM4FPROC mgl_glProgramUniform4f_t;
typedef PFNGLPROGRAMUNIFORM4FVPROC mgl_glProgramUniform4fv_t;
typedef PFNGLPROGRAMUNIFORM4DPROC mgl_glProgramUniform4d_t;
typedef PFNGLPROGRAMUNIFORM4DVPROC mgl_glProgramUniform4dv_t;
typedef PFNGLPROGRAMUNIFORM4UIPROC mgl_glProgramUniform4ui_t;
typedef PFNGLPROGRAMUNIFORM4UIVPROC mgl_glProgramUniform4uiv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX2FVPROC mgl_glProgramUniformMatrix2fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX3FVPROC mgl_glProgramUniformMatrix3fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX4FVPROC mgl_glProgramUniformMatrix4fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX2DVPROC mgl_glProgramUniformMatrix2dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX3DVPROC mgl_glProgramUniformMatrix3dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX4DVPROC mgl_glProgramUniformMatrix4dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC mgl_glProgramUniformMatrix2x3fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC mgl_glProgramUniformMatrix3x2fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC mgl_glProgramUniformMatrix2x4fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC mgl_glProgramUniformMatrix4x2fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC mgl_glProgramUniformMatrix3x4fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC mgl_glProgramUniformMatrix4x3fv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC mgl_glProgramUniformMatrix2x3dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC mgl_glProgramUniformMatrix3x2dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC mgl_glProgramUniformMatrix2x4dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC mgl_glProgramUniformMatrix4x2dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC mgl_glProgramUniformMatrix3x4dv_t;
typedef PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC mgl_glProgramUniformMatrix4x3dv_t;
typedef PFNGLVALIDATEPROGRAMPIPELINEPROC mgl_glValidateProgramPipeline_t;
typedef PFNGLGETPROGRAMPIPELINEINFOLOGPROC mgl_glGetProgramPipelineInfoLog_t;
typedef PFNGLVERTEXATTRIBL1DPROC mgl_glVertexAttribL1d_t;
typedef PFNGLVERTEXATTRIBL2DPROC mgl_glVertexAttribL2d_t;
typedef PFNGLVERTEXATTRIBL3DPROC mgl_glVertexAttribL3d_t;
typedef PFNGLVERTEXATTRIBL4DPROC mgl_glVertexAttribL4d_t;
typedef PFNGLVERTEXATTRIBL1DVPROC mgl_glVertexAttribL1dv_t;
typedef PFNGLVERTEXATTRIBL2DVPROC mgl_glVertexAttribL2dv_t;
typedef PFNGLVERTEXATTRIBL3DVPROC mgl_glVertexAttribL3dv_t;
typedef PFNGLVERTEXATTRIBL4DVPROC mgl_glVertexAttribL4dv_t;
typedef PFNGLVERTEXATTRIBLPOINTERPROC mgl_glVertexAttribLPointer_t;
typedef PFNGLGETVERTEXATTRIBLDVPROC mgl_glGetVertexAttribLdv_t;
typedef PFNGLVIEWPORTARRAYVPROC mgl_glViewportArrayv_t;
typedef PFNGLVIEWPORTINDEXEDFPROC mgl_glViewportIndexedf_t;
typedef PFNGLVIEWPORTINDEXEDFVPROC mgl_glViewportIndexedfv_t;
typedef PFNGLSCISSORARRAYVPROC mgl_glScissorArrayv_t;
typedef PFNGLSCISSORINDEXEDPROC mgl_glScissorIndexed_t;
typedef PFNGLSCISSORINDEXEDVPROC mgl_glScissorIndexedv_t;
typedef PFNGLDEPTHRANGEARRAYVPROC mgl_glDepthRangeArrayv_t;
typedef PFNGLDEPTHRANGEINDEXEDPROC mgl_glDepthRangeIndexed_t;
typedef PFNGLGETFLOATI_VPROC mgl_glGetFloati_v_t;
typedef PFNGLGETDOUBLEI_VPROC mgl_glGetDoublei_v_t;
typedef PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC mgl_glDrawArraysInstancedBaseInstance_t;
typedef PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC mgl_glDrawElementsInstancedBaseInstance_t;
typedef PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC mgl_glDrawElementsInstancedBaseVertexBaseInstance_t;
typedef PFNGLGETINTERNALFORMATIVPROC mgl_glGetInternalformativ_t;
typedef PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC mgl_glGetActiveAtomicCounterBufferiv_t;
typedef PFNGLBINDIMAGETEXTUREPROC mgl_glBindImageTexture_t;
typedef PFNGLMEMORYBARRIERPROC mgl_glMemoryBarrier_t;
typedef PFNGLTEXSTORAGE1DPROC mgl_glTexStorage1D_t;
typedef PFNGLTEXSTORAGE2DPROC mgl_glTexStorage2D_t;
typedef PFNGLTEXSTORAGE3DPROC mgl_glTexStorage3D_t;
typedef PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC mgl_glDrawTransformFeedbackInstanced_t;
typedef PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC mgl_glDrawTransformFeedbackStreamInstanced_t;
typedef PFNGLCLEARBUFFERDATAPROC mgl_glClearBufferData_t;
typedef PFNGLCLEARBUFFERSUBDATAPROC mgl_glClearBufferSubData_t;
typedef PFNGLDISPATCHCOMPUTEPROC mgl_glDispatchCompute_t;
typedef PFNGLDISPATCHCOMPUTEINDIRECTPROC mgl_glDispatchComputeIndirect_t;
typedef PFNGLCOPYIMAGESUBDATAPROC mgl_glCopyImageSubData_t;
typedef PFNGLFRAMEBUFFERPARAMETERIPROC mgl_glFramebufferParameteri_t;
typedef PFNGLGETFRAMEBUFFERPARAMETERIVPROC mgl_glGetFramebufferParameteriv_t;
typedef PFNGLGETINTERNALFORMATI64VPROC mgl_glGetInternalformati64v_t;
typedef PFNGLINVALIDATETEXSUBIMAGEPROC mgl_glInvalidateTexSubImage_t;
typedef PFNGLINVALIDATETEXIMAGEPROC mgl_glInvalidateTexImage_t;
typedef PFNGLINVALIDATEBUFFERSUBDATAPROC mgl_glInvalidateBufferSubData_t;
typedef PFNGLINVALIDATEBUFFERDATAPROC mgl_glInvalidateBufferData_t;
typedef PFNGLINVALIDATEFRAMEBUFFERPROC mgl_glInvalidateFramebuffer_t;
typedef PFNGLINVALIDATESUBFRAMEBUFFERPROC mgl_glInvalidateSubFramebuffer_t;
typedef PFNGLMULTIDRAWARRAYSINDIRECTPROC mgl_glMultiDrawArraysIndirect_t;
typedef PFNGLMULTIDRAWELEMENTSINDIRECTPROC mgl_glMultiDrawElementsIndirect_t;
typedef PFNGLGETPROGRAMINTERFACEIVPROC mgl_glGetProgramInterfaceiv_t;
typedef PFNGLGETPROGRAMRESOURCEINDEXPROC mgl_glGetProgramResourceIndex_t;
typedef PFNGLGETPROGRAMRESOURCENAMEPROC mgl_glGetProgramResourceName_t;
typedef PFNGLGETPROGRAMRESOURCEIVPROC mgl_glGetProgramResourceiv_t;
typedef PFNGLGETPROGRAMRESOURCELOCATIONPROC mgl_glGetProgramResourceLocation_t;
typedef PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC mgl_glGetProgramResourceLocationIndex_t;
typedef PFNGLSHADERSTORAGEBLOCKBINDINGPROC mgl_glShaderStorageBlockBinding_t;
typedef PFNGLTEXBUFFERRANGEPROC mgl_glTexBufferRange_t;
typedef PFNGLTEXSTORAGE2DMULTISAMPLEPROC mgl_glTexStorage2DMultisample_t;
typedef PFNGLTEXSTORAGE3DMULTISAMPLEPROC mgl_glTexStorage3DMultisample_t;
typedef PFNGLTEXTUREVIEWPROC mgl_glTextureView_t;
typedef PFNGLBINDVERTEXBUFFERPROC mgl_glBindVertexBuffer_t;
typedef PFNGLVERTEXATTRIBFORMATPROC mgl_glVertexAttribFormat_t;
typedef PFNGLVERTEXATTRIBIFORMATPROC mgl_glVertexAttribIFormat_t;
typedef PFNGLVERTEXATTRIBLFORMATPROC mgl_glVertexAttribLFormat_t;
typedef PFNGLVERTEXATTRIBBINDINGPROC mgl_glVertexAttribBinding_t;
typedef PFNGLVERTEXBINDINGDIVISORPROC mgl_glVertexBindingDivisor_t;
typedef PFNGLDEBUGMESSAGECONTROLPROC mgl_glDebugMessageControl_t;
typedef PFNGLDEBUGMESSAGEINSERTPROC mgl_glDebugMessageInsert_t;
typedef PFNGLDEBUGMESSAGECALLBACKPROC mgl_glDebugMessageCallback_t;
typedef PFNGLGETDEBUGMESSAGELOGPROC mgl_glGetDebugMessageLog_t;
typedef PFNGLPUSHDEBUGGROUPPROC mgl_glPushDebugGroup_t;
typedef PFNGLPOPDEBUGGROUPPROC mgl_glPopDebugGroup_t;
typedef PFNGLOBJECTLABELPROC mgl_glObjectLabel_t;
typedef PFNGLGETOBJECTLABELPROC mgl_glGetObjectLabel_t;
typedef PFNGLOBJECTPTRLABELPROC mgl_glObjectPtrLabel_t;
typedef PFNGLGETOBJECTPTRLABELPROC mgl_glGetObjectPtrLabel_t;
typedef PFNGLBUFFERSTORAGEPROC mgl_glBufferStorage_t;
typedef PFNGLCLEARTEXIMAGEPROC mgl_glClearTexImage_t;
typedef PFNGLCLEARTEXSUBIMAGEPROC mgl_glClearTexSubImage_t;
typedef PFNGLBINDBUFFERSBASEPROC mgl_glBindBuffersBase_t;
typedef PFNGLBINDBUFFERSRANGEPROC mgl_glBindBuffersRange_t;
typedef PFNGLBINDTEXTURESPROC mgl_glBindTextures_t;
typedef PFNGLBINDSAMPLERSPROC mgl_glBindSamplers_t;
typedef PFNGLBINDIMAGETEXTURESPROC mgl_glBindImageTextures_t;
typedef PFNGLBINDVERTEXBUFFERSPROC mgl_glBindVertexBuffers_t;
typedef PFNGLCLIPCONTROLPROC mgl_glClipControl_t;
typedef PFNGLCREATETRANSFORMFEEDBACKSPROC mgl_glCreateTransformFeedbacks_t;
typedef PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC mgl_glTransformFeedbackBufferBase_t;
typedef PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC mgl_glTransformFeedbackBufferRange_t;
typedef PFNGLGETTRANSFORMFEEDBACKIVPROC mgl_glGetTransformFeedbackiv_t;
typedef PFNGLGETTRANSFORMFEEDBACKI_VPROC mgl_glGetTransformFeedbacki_v_t;
typedef PFNGLGETTRANSFORMFEEDBACKI64_VPROC mgl_glGetTransformFeedbacki64_v_t;
typedef PFNGLCREATEBUFFERSPROC mgl_glCreateBuffers_t;
typedef PFNGLNAMEDBUFFERSTORAGEPROC mgl_glNamedBufferStorage_t;
typedef PFNGLNAMEDBUFFERDATAPROC mgl_glNamedBufferData_t;
typedef PFNGLNAMEDBUFFERSUBDATAPROC mgl_glNamedBufferSubData_t;
typedef PFNGLCOPYNAMEDBUFFERSUBDATAPROC mgl_glCopyNamedBufferSubData_t;
typedef PFNGLCLEARNAMEDBUFFERDATAPROC mgl_glClearNamedBufferData_t;
typedef PFNGLCLEARNAMEDBUFFERSUBDATAPROC mgl_glClearNamedBufferSubData_t;
typedef PFNGLMAPNAMEDBUFFERPROC mgl_glMapNamedBuffer_t;
typedef PFNGLMAPNAMEDBUFFERRANGEPROC mgl_glMapNamedBufferRange_t;
typedef PFNGLUNMAPNAMEDBUFFERPROC mgl_glUnmapNamedBuffer_t;
typedef PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC mgl_glFlushMappedNamedBufferRange_t;
typedef PFNGLGETNAMEDBUFFERPARAMETERIVPROC mgl_glGetNamedBufferParameteriv_t;
typedef PFNGLGETNAMEDBUFFERPARAMETERI64VPROC mgl_glGetNamedBufferParameteri64v_t;
typedef PFNGLGETNAMEDBUFFERPOINTERVPROC mgl_glGetNamedBufferPointerv_t;
typedef PFNGLGETNAMEDBUFFERSUBDATAPROC mgl_glGetNamedBufferSubData_t;
typedef PFNGLCREATEFRAMEBUFFERSPROC mgl_glCreateFramebuffers_t;
typedef PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC mgl_glNamedFramebufferRenderbuffer_t;
typedef PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC mgl_glNamedFramebufferParameteri_t;
typedef PFNGLNAMEDFRAMEBUFFERTEXTUREPROC mgl_glNamedFramebufferTexture_t;
typedef PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC mgl_glNamedFramebufferTextureLayer_t;
typedef PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC mgl_glNamedFramebufferDrawBuffer_t;
typedef PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC mgl_glNamedFramebufferDrawBuffers_t;
typedef PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC mgl_glNamedFramebufferReadBuffer_t;
typedef PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC mgl_glInvalidateNamedFramebufferData_t;
typedef PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC mgl_glInvalidateNamedFramebufferSubData_t;
typedef PFNGLCLEARNAMEDFRAMEBUFFERIVPROC mgl_glClearNamedFramebufferiv_t;
typedef PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC mgl_glClearNamedFramebufferuiv_t;
typedef PFNGLCLEARNAMEDFRAMEBUFFERFVPROC mgl_glClearNamedFramebufferfv_t;
typedef PFNGLCLEARNAMEDFRAMEBUFFERFIPROC mgl_glClearNamedFramebufferfi_t;
typedef PFNGLBLITNAMEDFRAMEBUFFERPROC mgl_glBlitNamedFramebuffer_t;
typedef PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC mgl_glCheckNamedFramebufferStatus_t;
typedef PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC mgl_glGetNamedFramebufferParameteriv_t;
typedef PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC mgl_glGetNamedFramebufferAttachmentParameteriv_t;
typedef PFNGLCREATERENDERBUFFERSPROC mgl_glCreateRenderbuffers_t;
typedef PFNGLNAMEDRENDERBUFFERSTORAGEPROC mgl_glNamedRenderbufferStorage_t;
typedef PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC mgl_glNamedRenderbufferStorageMultisample_t;
typedef PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC mgl_glGetNamedRenderbufferParameteriv_t;
typedef PFNGLCREATETEXTURESPROC mgl_glCreateTextures_t;
typedef PFNGLTEXTUREBUFFERPROC mgl_glTextureBuffer_t;
typedef PFNGLTEXTUREBUFFERRANGEPROC mgl_glTextureBufferRange_t;
typedef PFNGLTEXTURESTORAGE1DPROC mgl_glTextureStorage1D_t;
typedef PFNGLTEXTURESTORAGE2DPROC mgl_glTextureStorage2D_t;
typedef PFNGLTEXTURESTORAGE3DPROC mgl_glTextureStorage3D_t;
typedef PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC mgl_glTextureStorage2DMultisample_t;
typedef PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC mgl_glTextureStorage3DMultisample_t;
typedef PFNGLTEXTURESUBIMAGE1DPROC mgl_glTextureSubImage1D_t;
typedef PFNGLTEXTURESUBIMAGE2DPROC mgl_glTextureSubImage2D_t;
typedef PFNGLTEXTURESUBIMAGE3DPROC mgl_glTextureSubImage3D_t;
typedef PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC mgl_glCompressedTextureSubImage1D_t;
typedef PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC mgl_glCompressedTextureSubImage2D_t;
typedef PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC mgl_glCompressedTextureSubImage3D_t;
typedef PFNGLCOPYTEXTURESUBIMAGE1DPROC mgl_glCopyTextureSubImage1D_t;
typedef PFNGLCOPYTEXTURESUBIMAGE2DPROC mgl_glCopyTextureSubImage2D_t;
typedef PFNGLCOPYTEXTURESUBIMAGE3DPROC mgl_glCopyTextureSubImage3D_t;
typedef PFNGLTEXTUREPARAMETERFPROC mgl_glTextureParameterf_t;
typedef PFNGLTEXTUREPARAMETERFVPROC mgl_glTextureParameterfv_t;
typedef PFNGLTEXTUREPARAMETERIPROC mgl_glTextureParameteri_t;
typedef PFNGLTEXTUREPARAMETERIIVPROC mgl_glTextureParameterIiv_t;
typedef PFNGLTEXTUREPARAMETERIUIVPROC mgl_glTextureParameterIuiv_t;
typedef PFNGLTEXTUREPARAMETERIVPROC mgl_glTextureParameteriv_t;
typedef PFNGLGENERATETEXTUREMIPMAPPROC mgl_glGenerateTextureMipmap_t;
typedef PFNGLBINDTEXTUREUNITPROC mgl_glBindTextureUnit_t;
typedef PFNGLGETTEXTUREIMAGEPROC mgl_glGetTextureImage_t;
typedef PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC mgl_glGetCompressedTextureImage_t;
typedef PFNGLGETTEXTURELEVELPARAMETERFVPROC mgl_glGetTextureLevelParameterfv_t;
typedef PFNGLGETTEXTURELEVELPARAMETERIVPROC mgl_glGetTextureLevelParameteriv_t;
typedef PFNGLGETTEXTUREPARAMETERFVPROC mgl_glGetTextureParameterfv_t;
typedef PFNGLGETTEXTUREPARAMETERIIVPROC mgl_glGetTextureParameterIiv_t;
typedef PFNGLGETTEXTUREPARAMETERIUIVPROC mgl_glGetTextureParameterIuiv_t;
typedef PFNGLGETTEXTUREPARAMETERIVPROC mgl_glGetTextureParameteriv_t;
typedef PFNGLCREATEVERTEXARRAYSPROC mgl_glCreateVertexArrays_t;
typedef PFNGLDISABLEVERTEXARRAYATTRIBPROC mgl_glDisableVertexArrayAttrib_t;
typedef PFNGLENABLEVERTEXARRAYATTRIBPROC mgl_glEnableVertexArrayAttrib_t;
typedef PFNGLVERTEXARRAYELEMENTBUFFERPROC mgl_glVertexArrayElementBuffer_t;
typedef PFNGLVERTEXARRAYVERTEXBUFFERPROC mgl_glVertexArrayVertexBuffer_t;
typedef PFNGLVERTEXARRAYVERTEXBUFFERSPROC mgl_glVertexArrayVertexBuffers_t;
typedef PFNGLVERTEXARRAYATTRIBBINDINGPROC mgl_glVertexArrayAttribBinding_t;
typedef PFNGLVERTEXARRAYATTRIBFORMATPROC mgl_glVertexArrayAttribFormat_t;
typedef PFNGLVERTEXARRAYATTRIBIFORMATPROC mgl_glVertexArrayAttribIFormat_t;
typedef PFNGLVERTEXARRAYATTRIBLFORMATPROC mgl_glVertexArrayAttribLFormat_t;
typedef PFNGLVERTEXARRAYBINDINGDIVISORPROC mgl_glVertexArrayBindingDivisor_t;
typedef PFNGLGETVERTEXARRAYIVPROC mgl_glGetVertexArrayiv_t;
typedef PFNGLGETVERTEXARRAYINDEXEDIVPROC mgl_glGetVertexArrayIndexediv_t;
typedef PFNGLGETVERTEXARRAYINDEXED64IVPROC mgl_glGetVertexArrayIndexed64iv_t;
typedef PFNGLCREATESAMPLERSPROC mgl_glCreateSamplers_t;
typedef PFNGLCREATEPROGRAMPIPELINESPROC mgl_glCreateProgramPipelines_t;
typedef PFNGLCREATEQUERIESPROC mgl_glCreateQueries_t;
typedef PFNGLGETQUERYBUFFEROBJECTI64VPROC mgl_glGetQueryBufferObjecti64v_t;
typedef PFNGLGETQUERYBUFFEROBJECTIVPROC mgl_glGetQueryBufferObjectiv_t;
typedef PFNGLGETQUERYBUFFEROBJECTUI64VPROC mgl_glGetQueryBufferObjectui64v_t;
typedef PFNGLGETQUERYBUFFEROBJECTUIVPROC mgl_glGetQueryBufferObjectuiv_t;
typedef PFNGLMEMORYBARRIERBYREGIONPROC mgl_glMemoryBarrierByRegion_t;
typedef PFNGLGETTEXTURESUBIMAGEPROC mgl_glGetTextureSubImage_t;
typedef PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC mgl_glGetCompressedTextureSubImage_t;
typedef PFNGLGETGRAPHICSRESETSTATUSPROC mgl_glGetGraphicsResetStatus_t;
typedef PFNGLGETNCOMPRESSEDTEXIMAGEPROC mgl_glGetnCompressedTexImage_t;
typedef PFNGLGETNTEXIMAGEPROC mgl_glGetnTexImage_t;
typedef PFNGLGETNUNIFORMDVPROC mgl_glGetnUniformdv_t;
typedef PFNGLGETNUNIFORMFVPROC mgl_glGetnUniformfv_t;
typedef PFNGLGETNUNIFORMIVPROC mgl_glGetnUniformiv_t;
typedef PFNGLGETNUNIFORMUIVPROC mgl_glGetnUniformuiv_t;
typedef PFNGLREADNPIXELSPROC mgl_glReadnPixels_t;
typedef PFNGLTEXTUREBARRIERPROC mgl_glTextureBarrier_t;
typedef PFNGLSPECIALIZESHADERPROC mgl_glSpecializeShader_t;
typedef PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC mgl_glMultiDrawArraysIndirectCount_t;
typedef PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC mgl_glMultiDrawElementsIndirectCount_t;
typedef PFNGLPOLYGONOFFSETCLAMPPROC mgl_glPolygonOffsetClamp_t;

GLAPI mgl_glCullFace_t mgl_glCullFace;
GLAPI mgl_glFrontFace_t mgl_glFrontFace;
GLAPI mgl_glHint_t mgl_glHint;
GLAPI mgl_glLineWidth_t mgl_glLineWidth;
GLAPI mgl_glPointSize_t mgl_glPointSize;
GLAPI mgl_glPolygonMode_t mgl_glPolygonMode;
GLAPI mgl_glScissor_t mgl_glScissor;
GLAPI mgl_glTexParameterf_t mgl_glTexParameterf;
GLAPI mgl_glTexParameterfv_t mgl_glTexParameterfv;
GLAPI mgl_glTexParameteri_t mgl_glTexParameteri;
GLAPI mgl_glTexParameteriv_t mgl_glTexParameteriv;
GLAPI mgl_glTexImage1D_t mgl_glTexImage1D;
GLAPI mgl_glTexImage2D_t mgl_glTexImage2D;
GLAPI mgl_glDrawBuffer_t mgl_glDrawBuffer;
GLAPI mgl_glClear_t mgl_glClear;
GLAPI mgl_glClearColor_t mgl_glClearColor;
GLAPI mgl_glClearStencil_t mgl_glClearStencil;
GLAPI mgl_glClearDepth_t mgl_glClearDepth;
GLAPI mgl_glStencilMask_t mgl_glStencilMask;
GLAPI mgl_glColorMask_t mgl_glColorMask;
GLAPI mgl_glDepthMask_t mgl_glDepthMask;
GLAPI mgl_glDisable_t mgl_glDisable;
GLAPI mgl_glEnable_t mgl_glEnable;
GLAPI mgl_glFinish_t mgl_glFinish;
GLAPI mgl_glFlush_t mgl_glFlush;
GLAPI mgl_glBlendFunc_t mgl_glBlendFunc;
GLAPI mgl_glLogicOp_t mgl_glLogicOp;
GLAPI mgl_glStencilFunc_t mgl_glStencilFunc;
GLAPI mgl_glStencilOp_t mgl_glStencilOp;
GLAPI mgl_glDepthFunc_t mgl_glDepthFunc;
GLAPI mgl_glPixelStoref_t mgl_glPixelStoref;
GLAPI mgl_glPixelStorei_t mgl_glPixelStorei;
GLAPI mgl_glReadBuffer_t mgl_glReadBuffer;
GLAPI mgl_glReadPixels_t mgl_glReadPixels;
GLAPI mgl_glGetBooleanv_t mgl_glGetBooleanv;
GLAPI mgl_glGetDoublev_t mgl_glGetDoublev;
GLAPI mgl_glGetError_t mgl_glGetError;
GLAPI mgl_glGetFloatv_t mgl_glGetFloatv;
GLAPI mgl_glGetIntegerv_t mgl_glGetIntegerv;
GLAPI mgl_glGetString_t mgl_glGetString;
GLAPI mgl_glGetTexImage_t mgl_glGetTexImage;
GLAPI mgl_glGetTexParameterfv_t mgl_glGetTexParameterfv;
GLAPI mgl_glGetTexParameteriv_t mgl_glGetTexParameteriv;
GLAPI mgl_glGetTexLevelParameterfv_t mgl_glGetTexLevelParameterfv;
GLAPI mgl_glGetTexLevelParameteriv_t mgl_glGetTexLevelParameteriv;
GLAPI mgl_glIsEnabled_t mgl_glIsEnabled;
GLAPI mgl_glDepthRange_t mgl_glDepthRange;
GLAPI mgl_glViewport_t mgl_glViewport;
GLAPI mgl_glNewList_t mgl_glNewList;
GLAPI mgl_glEndList_t mgl_glEndList;
GLAPI mgl_glCallList_t mgl_glCallList;
GLAPI mgl_glCallLists_t mgl_glCallLists;
GLAPI mgl_glDeleteLists_t mgl_glDeleteLists;
GLAPI mgl_glGenLists_t mgl_glGenLists;
GLAPI mgl_glListBase_t mgl_glListBase;
GLAPI mgl_glBegin_t mgl_glBegin;
GLAPI mgl_glBitmap_t mgl_glBitmap;
GLAPI mgl_glColor3b_t mgl_glColor3b;
GLAPI mgl_glColor3bv_t mgl_glColor3bv;
GLAPI mgl_glColor3d_t mgl_glColor3d;
GLAPI mgl_glColor3dv_t mgl_glColor3dv;
GLAPI mgl_glColor3f_t mgl_glColor3f;
GLAPI mgl_glColor3fv_t mgl_glColor3fv;
GLAPI mgl_glColor3i_t mgl_glColor3i;
GLAPI mgl_glColor3iv_t mgl_glColor3iv;
GLAPI mgl_glColor3s_t mgl_glColor3s;
GLAPI mgl_glColor3sv_t mgl_glColor3sv;
GLAPI mgl_glColor3ub_t mgl_glColor3ub;
GLAPI mgl_glColor3ubv_t mgl_glColor3ubv;
GLAPI mgl_glColor3ui_t mgl_glColor3ui;
GLAPI mgl_glColor3uiv_t mgl_glColor3uiv;
GLAPI mgl_glColor3us_t mgl_glColor3us;
GLAPI mgl_glColor3usv_t mgl_glColor3usv;
GLAPI mgl_glColor4b_t mgl_glColor4b;
GLAPI mgl_glColor4bv_t mgl_glColor4bv;
GLAPI mgl_glColor4d_t mgl_glColor4d;
GLAPI mgl_glColor4dv_t mgl_glColor4dv;
GLAPI mgl_glColor4f_t mgl_glColor4f;
GLAPI mgl_glColor4fv_t mgl_glColor4fv;
GLAPI mgl_glColor4i_t mgl_glColor4i;
GLAPI mgl_glColor4iv_t mgl_glColor4iv;
GLAPI mgl_glColor4s_t mgl_glColor4s;
GLAPI mgl_glColor4sv_t mgl_glColor4sv;
GLAPI mgl_glColor4ub_t mgl_glColor4ub;
GLAPI mgl_glColor4ubv_t mgl_glColor4ubv;
GLAPI mgl_glColor4ui_t mgl_glColor4ui;
GLAPI mgl_glColor4uiv_t mgl_glColor4uiv;
GLAPI mgl_glColor4us_t mgl_glColor4us;
GLAPI mgl_glColor4usv_t mgl_glColor4usv;
GLAPI mgl_glEdgeFlag_t mgl_glEdgeFlag;
GLAPI mgl_glEdgeFlagv_t mgl_glEdgeFlagv;
GLAPI mgl_glEnd_t mgl_glEnd;
GLAPI mgl_glIndexd_t mgl_glIndexd;
GLAPI mgl_glIndexdv_t mgl_glIndexdv;
GLAPI mgl_glIndexf_t mgl_glIndexf;
GLAPI mgl_glIndexfv_t mgl_glIndexfv;
GLAPI mgl_glIndexi_t mgl_glIndexi;
GLAPI mgl_glIndexiv_t mgl_glIndexiv;
GLAPI mgl_glIndexs_t mgl_glIndexs;
GLAPI mgl_glIndexsv_t mgl_glIndexsv;
GLAPI mgl_glNormal3b_t mgl_glNormal3b;
GLAPI mgl_glNormal3bv_t mgl_glNormal3bv;
GLAPI mgl_glNormal3d_t mgl_glNormal3d;
GLAPI mgl_glNormal3dv_t mgl_glNormal3dv;
GLAPI mgl_glNormal3f_t mgl_glNormal3f;
GLAPI mgl_glNormal3fv_t mgl_glNormal3fv;
GLAPI mgl_glNormal3i_t mgl_glNormal3i;
GLAPI mgl_glNormal3iv_t mgl_glNormal3iv;
GLAPI mgl_glNormal3s_t mgl_glNormal3s;
GLAPI mgl_glNormal3sv_t mgl_glNormal3sv;
GLAPI mgl_glRasterPos2d_t mgl_glRasterPos2d;
GLAPI mgl_glRasterPos2dv_t mgl_glRasterPos2dv;
GLAPI mgl_glRasterPos2f_t mgl_glRasterPos2f;
GLAPI mgl_glRasterPos2fv_t mgl_glRasterPos2fv;
GLAPI mgl_glRasterPos2i_t mgl_glRasterPos2i;
GLAPI mgl_glRasterPos2iv_t mgl_glRasterPos2iv;
GLAPI mgl_glRasterPos2s_t mgl_glRasterPos2s;
GLAPI mgl_glRasterPos2sv_t mgl_glRasterPos2sv;
GLAPI mgl_glRasterPos3d_t mgl_glRasterPos3d;
GLAPI mgl_glRasterPos3dv_t mgl_glRasterPos3dv;
GLAPI mgl_glRasterPos3f_t mgl_glRasterPos3f;
GLAPI mgl_glRasterPos3fv_t mgl_glRasterPos3fv;
GLAPI mgl_glRasterPos3i_t mgl_glRasterPos3i;
GLAPI mgl_glRasterPos3iv_t mgl_glRasterPos3iv;
GLAPI mgl_glRasterPos3s_t mgl_glRasterPos3s;
GLAPI mgl_glRasterPos3sv_t mgl_glRasterPos3sv;
GLAPI mgl_glRasterPos4d_t mgl_glRasterPos4d;
GLAPI mgl_glRasterPos4dv_t mgl_glRasterPos4dv;
GLAPI mgl_glRasterPos4f_t mgl_glRasterPos4f;
GLAPI mgl_glRasterPos4fv_t mgl_glRasterPos4fv;
GLAPI mgl_glRasterPos4i_t mgl_glRasterPos4i;
GLAPI mgl_glRasterPos4iv_t mgl_glRasterPos4iv;
GLAPI mgl_glRasterPos4s_t mgl_glRasterPos4s;
GLAPI mgl_glRasterPos4sv_t mgl_glRasterPos4sv;
GLAPI mgl_glRectd_t mgl_glRectd;
GLAPI mgl_glRectdv_t mgl_glRectdv;
GLAPI mgl_glRectf_t mgl_glRectf;
GLAPI mgl_glRectfv_t mgl_glRectfv;
GLAPI mgl_glRecti_t mgl_glRecti;
GLAPI mgl_glRectiv_t mgl_glRectiv;
GLAPI mgl_glRects_t mgl_glRects;
GLAPI mgl_glRectsv_t mgl_glRectsv;
GLAPI mgl_glTexCoord1d_t mgl_glTexCoord1d;
GLAPI mgl_glTexCoord1dv_t mgl_glTexCoord1dv;
GLAPI mgl_glTexCoord1f_t mgl_glTexCoord1f;
GLAPI mgl_glTexCoord1fv_t mgl_glTexCoord1fv;
GLAPI mgl_glTexCoord1i_t mgl_glTexCoord1i;
GLAPI mgl_glTexCoord1iv_t mgl_glTexCoord1iv;
GLAPI mgl_glTexCoord1s_t mgl_glTexCoord1s;
GLAPI mgl_glTexCoord1sv_t mgl_glTexCoord1sv;
GLAPI mgl_glTexCoord2d_t mgl_glTexCoord2d;
GLAPI mgl_glTexCoord2dv_t mgl_glTexCoord2dv;
GLAPI mgl_glTexCoord2f_t mgl_glTexCoord2f;
GLAPI mgl_glTexCoord2fv_t mgl_glTexCoord2fv;
GLAPI mgl_glTexCoord2i_t mgl_glTexCoord2i;
GLAPI mgl_glTexCoord2iv_t mgl_glTexCoord2iv;
GLAPI mgl_glTexCoord2s_t mgl_glTexCoord2s;
GLAPI mgl_glTexCoord2sv_t mgl_glTexCoord2sv;
GLAPI mgl_glTexCoord3d_t mgl_glTexCoord3d;
GLAPI mgl_glTexCoord3dv_t mgl_glTexCoord3dv;
GLAPI mgl_glTexCoord3f_t mgl_glTexCoord3f;
GLAPI mgl_glTexCoord3fv_t mgl_glTexCoord3fv;
GLAPI mgl_glTexCoord3i_t mgl_glTexCoord3i;
GLAPI mgl_glTexCoord3iv_t mgl_glTexCoord3iv;
GLAPI mgl_glTexCoord3s_t mgl_glTexCoord3s;
GLAPI mgl_glTexCoord3sv_t mgl_glTexCoord3sv;
GLAPI mgl_glTexCoord4d_t mgl_glTexCoord4d;
GLAPI mgl_glTexCoord4dv_t mgl_glTexCoord4dv;
GLAPI mgl_glTexCoord4f_t mgl_glTexCoord4f;
GLAPI mgl_glTexCoord4fv_t mgl_glTexCoord4fv;
GLAPI mgl_glTexCoord4i_t mgl_glTexCoord4i;
GLAPI mgl_glTexCoord4iv_t mgl_glTexCoord4iv;
GLAPI mgl_glTexCoord4s_t mgl_glTexCoord4s;
GLAPI mgl_glTexCoord4sv_t mgl_glTexCoord4sv;
GLAPI mgl_glVertex2d_t mgl_glVertex2d;
GLAPI mgl_glVertex2dv_t mgl_glVertex2dv;
GLAPI mgl_glVertex2f_t mgl_glVertex2f;
GLAPI mgl_glVertex2fv_t mgl_glVertex2fv;
GLAPI mgl_glVertex2i_t mgl_glVertex2i;
GLAPI mgl_glVertex2iv_t mgl_glVertex2iv;
GLAPI mgl_glVertex2s_t mgl_glVertex2s;
GLAPI mgl_glVertex2sv_t mgl_glVertex2sv;
GLAPI mgl_glVertex3d_t mgl_glVertex3d;
GLAPI mgl_glVertex3dv_t mgl_glVertex3dv;
GLAPI mgl_glVertex3f_t mgl_glVertex3f;
GLAPI mgl_glVertex3fv_t mgl_glVertex3fv;
GLAPI mgl_glVertex3i_t mgl_glVertex3i;
GLAPI mgl_glVertex3iv_t mgl_glVertex3iv;
GLAPI mgl_glVertex3s_t mgl_glVertex3s;
GLAPI mgl_glVertex3sv_t mgl_glVertex3sv;
GLAPI mgl_glVertex4d_t mgl_glVertex4d;
GLAPI mgl_glVertex4dv_t mgl_glVertex4dv;
GLAPI mgl_glVertex4f_t mgl_glVertex4f;
GLAPI mgl_glVertex4fv_t mgl_glVertex4fv;
GLAPI mgl_glVertex4i_t mgl_glVertex4i;
GLAPI mgl_glVertex4iv_t mgl_glVertex4iv;
GLAPI mgl_glVertex4s_t mgl_glVertex4s;
GLAPI mgl_glVertex4sv_t mgl_glVertex4sv;
GLAPI mgl_glClipPlane_t mgl_glClipPlane;
GLAPI mgl_glColorMaterial_t mgl_glColorMaterial;
GLAPI mgl_glFogf_t mgl_glFogf;
GLAPI mgl_glFogfv_t mgl_glFogfv;
GLAPI mgl_glFogi_t mgl_glFogi;
GLAPI mgl_glFogiv_t mgl_glFogiv;
GLAPI mgl_glLightf_t mgl_glLightf;
GLAPI mgl_glLightfv_t mgl_glLightfv;
GLAPI mgl_glLighti_t mgl_glLighti;
GLAPI mgl_glLightiv_t mgl_glLightiv;
GLAPI mgl_glLightModelf_t mgl_glLightModelf;
GLAPI mgl_glLightModelfv_t mgl_glLightModelfv;
GLAPI mgl_glLightModeli_t mgl_glLightModeli;
GLAPI mgl_glLightModeliv_t mgl_glLightModeliv;
GLAPI mgl_glLineStipple_t mgl_glLineStipple;
GLAPI mgl_glMaterialf_t mgl_glMaterialf;
GLAPI mgl_glMaterialfv_t mgl_glMaterialfv;
GLAPI mgl_glMateriali_t mgl_glMateriali;
GLAPI mgl_glMaterialiv_t mgl_glMaterialiv;
GLAPI mgl_glPolygonStipple_t mgl_glPolygonStipple;
GLAPI mgl_glShadeModel_t mgl_glShadeModel;
GLAPI mgl_glTexEnvf_t mgl_glTexEnvf;
GLAPI mgl_glTexEnvfv_t mgl_glTexEnvfv;
GLAPI mgl_glTexEnvi_t mgl_glTexEnvi;
GLAPI mgl_glTexEnviv_t mgl_glTexEnviv;
GLAPI mgl_glTexGend_t mgl_glTexGend;
GLAPI mgl_glTexGendv_t mgl_glTexGendv;
GLAPI mgl_glTexGenf_t mgl_glTexGenf;
GLAPI mgl_glTexGenfv_t mgl_glTexGenfv;
GLAPI mgl_glTexGeni_t mgl_glTexGeni;
GLAPI mgl_glTexGeniv_t mgl_glTexGeniv;
GLAPI mgl_glFeedbackBuffer_t mgl_glFeedbackBuffer;
GLAPI mgl_glSelectBuffer_t mgl_glSelectBuffer;
GLAPI mgl_glRenderMode_t mgl_glRenderMode;
GLAPI mgl_glInitNames_t mgl_glInitNames;
GLAPI mgl_glLoadName_t mgl_glLoadName;
GLAPI mgl_glPassThrough_t mgl_glPassThrough;
GLAPI mgl_glPopName_t mgl_glPopName;
GLAPI mgl_glPushName_t mgl_glPushName;
GLAPI mgl_glClearAccum_t mgl_glClearAccum;
GLAPI mgl_glClearIndex_t mgl_glClearIndex;
GLAPI mgl_glIndexMask_t mgl_glIndexMask;
GLAPI mgl_glAccum_t mgl_glAccum;
GLAPI mgl_glPopAttrib_t mgl_glPopAttrib;
GLAPI mgl_glPushAttrib_t mgl_glPushAttrib;
GLAPI mgl_glMap1d_t mgl_glMap1d;
GLAPI mgl_glMap1f_t mgl_glMap1f;
GLAPI mgl_glMap2d_t mgl_glMap2d;
GLAPI mgl_glMap2f_t mgl_glMap2f;
GLAPI mgl_glMapGrid1d_t mgl_glMapGrid1d;
GLAPI mgl_glMapGrid1f_t mgl_glMapGrid1f;
GLAPI mgl_glMapGrid2d_t mgl_glMapGrid2d;
GLAPI mgl_glMapGrid2f_t mgl_glMapGrid2f;
GLAPI mgl_glEvalCoord1d_t mgl_glEvalCoord1d;
GLAPI mgl_glEvalCoord1dv_t mgl_glEvalCoord1dv;
GLAPI mgl_glEvalCoord1f_t mgl_glEvalCoord1f;
GLAPI mgl_glEvalCoord1fv_t mgl_glEvalCoord1fv;
GLAPI mgl_glEvalCoord2d_t mgl_glEvalCoord2d;
GLAPI mgl_glEvalCoord2dv_t mgl_glEvalCoord2dv;
GLAPI mgl_glEvalCoord2f_t mgl_glEvalCoord2f;
GLAPI mgl_glEvalCoord2fv_t mgl_glEvalCoord2fv;
GLAPI mgl_glEvalMesh1_t mgl_glEvalMesh1;
GLAPI mgl_glEvalPoint1_t mgl_glEvalPoint1;
GLAPI mgl_glEvalMesh2_t mgl_glEvalMesh2;
GLAPI mgl_glEvalPoint2_t mgl_glEvalPoint2;
GLAPI mgl_glAlphaFunc_t mgl_glAlphaFunc;
GLAPI mgl_glPixelZoom_t mgl_glPixelZoom;
GLAPI mgl_glPixelTransferf_t mgl_glPixelTransferf;
GLAPI mgl_glPixelTransferi_t mgl_glPixelTransferi;
GLAPI mgl_glPixelMapfv_t mgl_glPixelMapfv;
GLAPI mgl_glPixelMapuiv_t mgl_glPixelMapuiv;
GLAPI mgl_glPixelMapusv_t mgl_glPixelMapusv;
GLAPI mgl_glCopyPixels_t mgl_glCopyPixels;
GLAPI mgl_glDrawPixels_t mgl_glDrawPixels;
GLAPI mgl_glGetClipPlane_t mgl_glGetClipPlane;
GLAPI mgl_glGetLightfv_t mgl_glGetLightfv;
GLAPI mgl_glGetLightiv_t mgl_glGetLightiv;
GLAPI mgl_glGetMapdv_t mgl_glGetMapdv;
GLAPI mgl_glGetMapfv_t mgl_glGetMapfv;
GLAPI mgl_glGetMapiv_t mgl_glGetMapiv;
GLAPI mgl_glGetMaterialfv_t mgl_glGetMaterialfv;
GLAPI mgl_glGetMaterialiv_t mgl_glGetMaterialiv;
GLAPI mgl_glGetPixelMapfv_t mgl_glGetPixelMapfv;
GLAPI mgl_glGetPixelMapuiv_t mgl_glGetPixelMapuiv;
GLAPI mgl_glGetPixelMapusv_t mgl_glGetPixelMapusv;
GLAPI mgl_glGetPolygonStipple_t mgl_glGetPolygonStipple;
GLAPI mgl_glGetTexEnvfv_t mgl_glGetTexEnvfv;
GLAPI mgl_glGetTexEnviv_t mgl_glGetTexEnviv;
GLAPI mgl_glGetTexGendv_t mgl_glGetTexGendv;
GLAPI mgl_glGetTexGenfv_t mgl_glGetTexGenfv;
GLAPI mgl_glGetTexGeniv_t mgl_glGetTexGeniv;
GLAPI mgl_glIsList_t mgl_glIsList;
GLAPI mgl_glFrustum_t mgl_glFrustum;
GLAPI mgl_glLoadIdentity_t mgl_glLoadIdentity;
GLAPI mgl_glLoadMatrixf_t mgl_glLoadMatrixf;
GLAPI mgl_glLoadMatrixd_t mgl_glLoadMatrixd;
GLAPI mgl_glMatrixMode_t mgl_glMatrixMode;
GLAPI mgl_glMultMatrixf_t mgl_glMultMatrixf;
GLAPI mgl_glMultMatrixd_t mgl_glMultMatrixd;
GLAPI mgl_glOrtho_t mgl_glOrtho;
GLAPI mgl_glPopMatrix_t mgl_glPopMatrix;
GLAPI mgl_glPushMatrix_t mgl_glPushMatrix;
GLAPI mgl_glRotated_t mgl_glRotated;
GLAPI mgl_glRotatef_t mgl_glRotatef;
GLAPI mgl_glScaled_t mgl_glScaled;
GLAPI mgl_glScalef_t mgl_glScalef;
GLAPI mgl_glTranslated_t mgl_glTranslated;
GLAPI mgl_glTranslatef_t mgl_glTranslatef;
GLAPI mgl_glDrawArrays_t mgl_glDrawArrays;
GLAPI mgl_glDrawElements_t mgl_glDrawElements;
GLAPI mgl_glGetPointerv_t mgl_glGetPointerv;
GLAPI mgl_glPolygonOffset_t mgl_glPolygonOffset;
GLAPI mgl_glCopyTexImage1D_t mgl_glCopyTexImage1D;
GLAPI mgl_glCopyTexImage2D_t mgl_glCopyTexImage2D;
GLAPI mgl_glCopyTexSubImage1D_t mgl_glCopyTexSubImage1D;
GLAPI mgl_glCopyTexSubImage2D_t mgl_glCopyTexSubImage2D;
GLAPI mgl_glTexSubImage1D_t mgl_glTexSubImage1D;
GLAPI mgl_glTexSubImage2D_t mgl_glTexSubImage2D;
GLAPI mgl_glBindTexture_t mgl_glBindTexture;
GLAPI mgl_glDeleteTextures_t mgl_glDeleteTextures;
GLAPI mgl_glGenTextures_t mgl_glGenTextures;
GLAPI mgl_glIsTexture_t mgl_glIsTexture;
GLAPI mgl_glArrayElement_t mgl_glArrayElement;
GLAPI mgl_glColorPointer_t mgl_glColorPointer;
GLAPI mgl_glDisableClientState_t mgl_glDisableClientState;
GLAPI mgl_glEdgeFlagPointer_t mgl_glEdgeFlagPointer;
GLAPI mgl_glEnableClientState_t mgl_glEnableClientState;
GLAPI mgl_glIndexPointer_t mgl_glIndexPointer;
GLAPI mgl_glInterleavedArrays_t mgl_glInterleavedArrays;
GLAPI mgl_glNormalPointer_t mgl_glNormalPointer;
GLAPI mgl_glTexCoordPointer_t mgl_glTexCoordPointer;
GLAPI mgl_glVertexPointer_t mgl_glVertexPointer;
GLAPI mgl_glAreTexturesResident_t mgl_glAreTexturesResident;
GLAPI mgl_glPrioritizeTextures_t mgl_glPrioritizeTextures;
GLAPI mgl_glIndexub_t mgl_glIndexub;
GLAPI mgl_glIndexubv_t mgl_glIndexubv;
GLAPI mgl_glPopClientAttrib_t mgl_glPopClientAttrib;
GLAPI mgl_glPushClientAttrib_t mgl_glPushClientAttrib;
GLAPI mgl_glDrawRangeElements_t mgl_glDrawRangeElements;
GLAPI mgl_glTexImage3D_t mgl_glTexImage3D;
GLAPI mgl_glTexSubImage3D_t mgl_glTexSubImage3D;
GLAPI mgl_glCopyTexSubImage3D_t mgl_glCopyTexSubImage3D;
GLAPI mgl_glActiveTexture_t mgl_glActiveTexture;
GLAPI mgl_glSampleCoverage_t mgl_glSampleCoverage;
GLAPI mgl_glCompressedTexImage3D_t mgl_glCompressedTexImage3D;
GLAPI mgl_glCompressedTexImage2D_t mgl_glCompressedTexImage2D;
GLAPI mgl_glCompressedTexImage1D_t mgl_glCompressedTexImage1D;
GLAPI mgl_glCompressedTexSubImage3D_t mgl_glCompressedTexSubImage3D;
GLAPI mgl_glCompressedTexSubImage2D_t mgl_glCompressedTexSubImage2D;
GLAPI mgl_glCompressedTexSubImage1D_t mgl_glCompressedTexSubImage1D;
GLAPI mgl_glGetCompressedTexImage_t mgl_glGetCompressedTexImage;
GLAPI mgl_glClientActiveTexture_t mgl_glClientActiveTexture;
GLAPI mgl_glMultiTexCoord1d_t mgl_glMultiTexCoord1d;
GLAPI mgl_glMultiTexCoord1dv_t mgl_glMultiTexCoord1dv;
GLAPI mgl_glMultiTexCoord1f_t mgl_glMultiTexCoord1f;
GLAPI mgl_glMultiTexCoord1fv_t mgl_glMultiTexCoord1fv;
GLAPI mgl_glMultiTexCoord1i_t mgl_glMultiTexCoord1i;
GLAPI mgl_glMultiTexCoord1iv_t mgl_glMultiTexCoord1iv;
GLAPI mgl_glMultiTexCoord1s_t mgl_glMultiTexCoord1s;
GLAPI mgl_glMultiTexCoord1sv_t mgl_glMultiTexCoord1sv;
GLAPI mgl_glMultiTexCoord2d_t mgl_glMultiTexCoord2d;
GLAPI mgl_glMultiTexCoord2dv_t mgl_glMultiTexCoord2dv;
GLAPI mgl_glMultiTexCoord2f_t mgl_glMultiTexCoord2f;
GLAPI mgl_glMultiTexCoord2fv_t mgl_glMultiTexCoord2fv;
GLAPI mgl_glMultiTexCoord2i_t mgl_glMultiTexCoord2i;
GLAPI mgl_glMultiTexCoord2iv_t mgl_glMultiTexCoord2iv;
GLAPI mgl_glMultiTexCoord2s_t mgl_glMultiTexCoord2s;
GLAPI mgl_glMultiTexCoord2sv_t mgl_glMultiTexCoord2sv;
GLAPI mgl_glMultiTexCoord3d_t mgl_glMultiTexCoord3d;
GLAPI mgl_glMultiTexCoord3dv_t mgl_glMultiTexCoord3dv;
GLAPI mgl_glMultiTexCoord3f_t mgl_glMultiTexCoord3f;
GLAPI mgl_glMultiTexCoord3fv_t mgl_glMultiTexCoord3fv;
GLAPI mgl_glMultiTexCoord3i_t mgl_glMultiTexCoord3i;
GLAPI mgl_glMultiTexCoord3iv_t mgl_glMultiTexCoord3iv;
GLAPI mgl_glMultiTexCoord3s_t mgl_glMultiTexCoord3s;
GLAPI mgl_glMultiTexCoord3sv_t mgl_glMultiTexCoord3sv;
GLAPI mgl_glMultiTexCoord4d_t mgl_glMultiTexCoord4d;
GLAPI mgl_glMultiTexCoord4dv_t mgl_glMultiTexCoord4dv;
GLAPI mgl_glMultiTexCoord4f_t mgl_glMultiTexCoord4f;
GLAPI mgl_glMultiTexCoord4fv_t mgl_glMultiTexCoord4fv;
GLAPI mgl_glMultiTexCoord4i_t mgl_glMultiTexCoord4i;
GLAPI mgl_glMultiTexCoord4iv_t mgl_glMultiTexCoord4iv;
GLAPI mgl_glMultiTexCoord4s_t mgl_glMultiTexCoord4s;
GLAPI mgl_glMultiTexCoord4sv_t mgl_glMultiTexCoord4sv;
GLAPI mgl_glLoadTransposeMatrixf_t mgl_glLoadTransposeMatrixf;
GLAPI mgl_glLoadTransposeMatrixd_t mgl_glLoadTransposeMatrixd;
GLAPI mgl_glMultTransposeMatrixf_t mgl_glMultTransposeMatrixf;
GLAPI mgl_glMultTransposeMatrixd_t mgl_glMultTransposeMatrixd;
GLAPI mgl_glBlendFuncSeparate_t mgl_glBlendFuncSeparate;
GLAPI mgl_glMultiDrawArrays_t mgl_glMultiDrawArrays;
GLAPI mgl_glMultiDrawElements_t mgl_glMultiDrawElements;
GLAPI mgl_glPointParameterf_t mgl_glPointParameterf;
GLAPI mgl_glPointParameterfv_t mgl_glPointParameterfv;
GLAPI mgl_glPointParameteri_t mgl_glPointParameteri;
GLAPI mgl_glPointParameteriv_t mgl_glPointParameteriv;
GLAPI mgl_glFogCoordf_t mgl_glFogCoordf;
GLAPI mgl_glFogCoordfv_t mgl_glFogCoordfv;
GLAPI mgl_glFogCoordd_t mgl_glFogCoordd;
GLAPI mgl_glFogCoorddv_t mgl_glFogCoorddv;
GLAPI mgl_glFogCoordPointer_t mgl_glFogCoordPointer;
GLAPI mgl_glSecondaryColor3b_t mgl_glSecondaryColor3b;
GLAPI mgl_glSecondaryColor3bv_t mgl_glSecondaryColor3bv;
GLAPI mgl_glSecondaryColor3d_t mgl_glSecondaryColor3d;
GLAPI mgl_glSecondaryColor3dv_t mgl_glSecondaryColor3dv;
GLAPI mgl_glSecondaryColor3f_t mgl_glSecondaryColor3f;
GLAPI mgl_glSecondaryColor3fv_t mgl_glSecondaryColor3fv;
GLAPI mgl_glSecondaryColor3i_t mgl_glSecondaryColor3i;
GLAPI mgl_glSecondaryColor3iv_t mgl_glSecondaryColor3iv;
GLAPI mgl_glSecondaryColor3s_t mgl_glSecondaryColor3s;
GLAPI mgl_glSecondaryColor3sv_t mgl_glSecondaryColor3sv;
GLAPI mgl_glSecondaryColor3ub_t mgl_glSecondaryColor3ub;
GLAPI mgl_glSecondaryColor3ubv_t mgl_glSecondaryColor3ubv;
GLAPI mgl_glSecondaryColor3ui_t mgl_glSecondaryColor3ui;
GLAPI mgl_glSecondaryColor3uiv_t mgl_glSecondaryColor3uiv;
GLAPI mgl_glSecondaryColor3us_t mgl_glSecondaryColor3us;
GLAPI mgl_glSecondaryColor3usv_t mgl_glSecondaryColor3usv;
GLAPI mgl_glSecondaryColorPointer_t mgl_glSecondaryColorPointer;
GLAPI mgl_glWindowPos2d_t mgl_glWindowPos2d;
GLAPI mgl_glWindowPos2dv_t mgl_glWindowPos2dv;
GLAPI mgl_glWindowPos2f_t mgl_glWindowPos2f;
GLAPI mgl_glWindowPos2fv_t mgl_glWindowPos2fv;
GLAPI mgl_glWindowPos2i_t mgl_glWindowPos2i;
GLAPI mgl_glWindowPos2iv_t mgl_glWindowPos2iv;
GLAPI mgl_glWindowPos2s_t mgl_glWindowPos2s;
GLAPI mgl_glWindowPos2sv_t mgl_glWindowPos2sv;
GLAPI mgl_glWindowPos3d_t mgl_glWindowPos3d;
GLAPI mgl_glWindowPos3dv_t mgl_glWindowPos3dv;
GLAPI mgl_glWindowPos3f_t mgl_glWindowPos3f;
GLAPI mgl_glWindowPos3fv_t mgl_glWindowPos3fv;
GLAPI mgl_glWindowPos3i_t mgl_glWindowPos3i;
GLAPI mgl_glWindowPos3iv_t mgl_glWindowPos3iv;
GLAPI mgl_glWindowPos3s_t mgl_glWindowPos3s;
GLAPI mgl_glWindowPos3sv_t mgl_glWindowPos3sv;
GLAPI mgl_glBlendColor_t mgl_glBlendColor;
GLAPI mgl_glBlendEquation_t mgl_glBlendEquation;
GLAPI mgl_glGenQueries_t mgl_glGenQueries;
GLAPI mgl_glDeleteQueries_t mgl_glDeleteQueries;
GLAPI mgl_glIsQuery_t mgl_glIsQuery;
GLAPI mgl_glBeginQuery_t mgl_glBeginQuery;
GLAPI mgl_glEndQuery_t mgl_glEndQuery;
GLAPI mgl_glGetQueryiv_t mgl_glGetQueryiv;
GLAPI mgl_glGetQueryObjectiv_t mgl_glGetQueryObjectiv;
GLAPI mgl_glGetQueryObjectuiv_t mgl_glGetQueryObjectuiv;
GLAPI mgl_glBindBuffer_t mgl_glBindBuffer;
GLAPI mgl_glDeleteBuffers_t mgl_glDeleteBuffers;
GLAPI mgl_glGenBuffers_t mgl_glGenBuffers;
GLAPI mgl_glIsBuffer_t mgl_glIsBuffer;
GLAPI mgl_glBufferData_t mgl_glBufferData;
GLAPI mgl_glBufferSubData_t mgl_glBufferSubData;
GLAPI mgl_glGetBufferSubData_t mgl_glGetBufferSubData;
GLAPI mgl_glMapBuffer_t mgl_glMapBuffer;
GLAPI mgl_glUnmapBuffer_t mgl_glUnmapBuffer;
GLAPI mgl_glGetBufferParameteriv_t mgl_glGetBufferParameteriv;
GLAPI mgl_glGetBufferPointerv_t mgl_glGetBufferPointerv;
GLAPI mgl_glBlendEquationSeparate_t mgl_glBlendEquationSeparate;
GLAPI mgl_glDrawBuffers_t mgl_glDrawBuffers;
GLAPI mgl_glStencilOpSeparate_t mgl_glStencilOpSeparate;
GLAPI mgl_glStencilFuncSeparate_t mgl_glStencilFuncSeparate;
GLAPI mgl_glStencilMaskSeparate_t mgl_glStencilMaskSeparate;
GLAPI mgl_glAttachShader_t mgl_glAttachShader;
GLAPI mgl_glBindAttribLocation_t mgl_glBindAttribLocation;
GLAPI mgl_glCompileShader_t mgl_glCompileShader;
GLAPI mgl_glCreateProgram_t mgl_glCreateProgram;
GLAPI mgl_glCreateShader_t mgl_glCreateShader;
GLAPI mgl_glDeleteProgram_t mgl_glDeleteProgram;
GLAPI mgl_glDeleteShader_t mgl_glDeleteShader;
GLAPI mgl_glDetachShader_t mgl_glDetachShader;
GLAPI mgl_glDisableVertexAttribArray_t mgl_glDisableVertexAttribArray;
GLAPI mgl_glEnableVertexAttribArray_t mgl_glEnableVertexAttribArray;
GLAPI mgl_glGetActiveAttrib_t mgl_glGetActiveAttrib;
GLAPI mgl_glGetActiveUniform_t mgl_glGetActiveUniform;
GLAPI mgl_glGetAttachedShaders_t mgl_glGetAttachedShaders;
GLAPI mgl_glGetAttribLocation_t mgl_glGetAttribLocation;
GLAPI mgl_glGetProgramiv_t mgl_glGetProgramiv;
GLAPI mgl_glGetProgramInfoLog_t mgl_glGetProgramInfoLog;
GLAPI mgl_glGetShaderiv_t mgl_glGetShaderiv;
GLAPI mgl_glGetShaderInfoLog_t mgl_glGetShaderInfoLog;
GLAPI mgl_glGetShaderSource_t mgl_glGetShaderSource;
GLAPI mgl_glGetUniformLocation_t mgl_glGetUniformLocation;
GLAPI mgl_glGetUniformfv_t mgl_glGetUniformfv;
GLAPI mgl_glGetUniformiv_t mgl_glGetUniformiv;
GLAPI mgl_glGetVertexAttribdv_t mgl_glGetVertexAttribdv;
GLAPI mgl_glGetVertexAttribfv_t mgl_glGetVertexAttribfv;
GLAPI mgl_glGetVertexAttribiv_t mgl_glGetVertexAttribiv;
GLAPI mgl_glGetVertexAttribPointerv_t mgl_glGetVertexAttribPointerv;
GLAPI mgl_glIsProgram_t mgl_glIsProgram;
GLAPI mgl_glIsShader_t mgl_glIsShader;
GLAPI mgl_glLinkProgram_t mgl_glLinkProgram;
GLAPI mgl_glShaderSource_t mgl_glShaderSource;
GLAPI mgl_glUseProgram_t mgl_glUseProgram;
GLAPI mgl_glUniform1f_t mgl_glUniform1f;
GLAPI mgl_glUniform2f_t mgl_glUniform2f;
GLAPI mgl_glUniform3f_t mgl_glUniform3f;
GLAPI mgl_glUniform4f_t mgl_glUniform4f;
GLAPI mgl_glUniform1i_t mgl_glUniform1i;
GLAPI mgl_glUniform2i_t mgl_glUniform2i;
GLAPI mgl_glUniform3i_t mgl_glUniform3i;
GLAPI mgl_glUniform4i_t mgl_glUniform4i;
GLAPI mgl_glUniform1fv_t mgl_glUniform1fv;
GLAPI mgl_glUniform2fv_t mgl_glUniform2fv;
GLAPI mgl_glUniform3fv_t mgl_glUniform3fv;
GLAPI mgl_glUniform4fv_t mgl_glUniform4fv;
GLAPI mgl_glUniform1iv_t mgl_glUniform1iv;
GLAPI mgl_glUniform2iv_t mgl_glUniform2iv;
GLAPI mgl_glUniform3iv_t mgl_glUniform3iv;
GLAPI mgl_glUniform4iv_t mgl_glUniform4iv;
GLAPI mgl_glUniformMatrix2fv_t mgl_glUniformMatrix2fv;
GLAPI mgl_glUniformMatrix3fv_t mgl_glUniformMatrix3fv;
GLAPI mgl_glUniformMatrix4fv_t mgl_glUniformMatrix4fv;
GLAPI mgl_glValidateProgram_t mgl_glValidateProgram;
GLAPI mgl_glVertexAttrib1d_t mgl_glVertexAttrib1d;
GLAPI mgl_glVertexAttrib1dv_t mgl_glVertexAttrib1dv;
GLAPI mgl_glVertexAttrib1f_t mgl_glVertexAttrib1f;
GLAPI mgl_glVertexAttrib1fv_t mgl_glVertexAttrib1fv;
GLAPI mgl_glVertexAttrib1s_t mgl_glVertexAttrib1s;
GLAPI mgl_glVertexAttrib1sv_t mgl_glVertexAttrib1sv;
GLAPI mgl_glVertexAttrib2d_t mgl_glVertexAttrib2d;
GLAPI mgl_glVertexAttrib2dv_t mgl_glVertexAttrib2dv;
GLAPI mgl_glVertexAttrib2f_t mgl_glVertexAttrib2f;
GLAPI mgl_glVertexAttrib2fv_t mgl_glVertexAttrib2fv;
GLAPI mgl_glVertexAttrib2s_t mgl_glVertexAttrib2s;
GLAPI mgl_glVertexAttrib2sv_t mgl_glVertexAttrib2sv;
GLAPI mgl_glVertexAttrib3d_t mgl_glVertexAttrib3d;
GLAPI mgl_glVertexAttrib3dv_t mgl_glVertexAttrib3dv;
GLAPI mgl_glVertexAttrib3f_t mgl_glVertexAttrib3f;
GLAPI mgl_glVertexAttrib3fv_t mgl_glVertexAttrib3fv;
GLAPI mgl_glVertexAttrib3s_t mgl_glVertexAttrib3s;
GLAPI mgl_glVertexAttrib3sv_t mgl_glVertexAttrib3sv;
GLAPI mgl_glVertexAttrib4Nbv_t mgl_glVertexAttrib4Nbv;
GLAPI mgl_glVertexAttrib4Niv_t mgl_glVertexAttrib4Niv;
GLAPI mgl_glVertexAttrib4Nsv_t mgl_glVertexAttrib4Nsv;
GLAPI mgl_glVertexAttrib4Nub_t mgl_glVertexAttrib4Nub;
GLAPI mgl_glVertexAttrib4Nubv_t mgl_glVertexAttrib4Nubv;
GLAPI mgl_glVertexAttrib4Nuiv_t mgl_glVertexAttrib4Nuiv;
GLAPI mgl_glVertexAttrib4Nusv_t mgl_glVertexAttrib4Nusv;
GLAPI mgl_glVertexAttrib4bv_t mgl_glVertexAttrib4bv;
GLAPI mgl_glVertexAttrib4d_t mgl_glVertexAttrib4d;
GLAPI mgl_glVertexAttrib4dv_t mgl_glVertexAttrib4dv;
GLAPI mgl_glVertexAttrib4f_t mgl_glVertexAttrib4f;
GLAPI mgl_glVertexAttrib4fv_t mgl_glVertexAttrib4fv;
GLAPI mgl_glVertexAttrib4iv_t mgl_glVertexAttrib4iv;
GLAPI mgl_glVertexAttrib4s_t mgl_glVertexAttrib4s;
GLAPI mgl_glVertexAttrib4sv_t mgl_glVertexAttrib4sv;
GLAPI mgl_glVertexAttrib4ubv_t mgl_glVertexAttrib4ubv;
GLAPI mgl_glVertexAttrib4uiv_t mgl_glVertexAttrib4uiv;
GLAPI mgl_glVertexAttrib4usv_t mgl_glVertexAttrib4usv;
GLAPI mgl_glVertexAttribPointer_t mgl_glVertexAttribPointer;
GLAPI mgl_glUniformMatrix2x3fv_t mgl_glUniformMatrix2x3fv;
GLAPI mgl_glUniformMatrix3x2fv_t mgl_glUniformMatrix3x2fv;
GLAPI mgl_glUniformMatrix2x4fv_t mgl_glUniformMatrix2x4fv;
GLAPI mgl_glUniformMatrix4x2fv_t mgl_glUniformMatrix4x2fv;
GLAPI mgl_glUniformMatrix3x4fv_t mgl_glUniformMatrix3x4fv;
GLAPI mgl_glUniformMatrix4x3fv_t mgl_glUniformMatrix4x3fv;
GLAPI mgl_glColorMaski_t mgl_glColorMaski;
GLAPI mgl_glGetBooleani_v_t mgl_glGetBooleani_v;
GLAPI mgl_glGetIntegeri_v_t mgl_glGetIntegeri_v;
GLAPI mgl_glEnablei_t mgl_glEnablei;
GLAPI mgl_glDisablei_t mgl_glDisablei;
GLAPI mgl_glIsEnabledi_t mgl_glIsEnabledi;
GLAPI mgl_glBeginTransformFeedback_t mgl_glBeginTransformFeedback;
GLAPI mgl_glEndTransformFeedback_t mgl_glEndTransformFeedback;
GLAPI mgl_glBindBufferRange_t mgl_glBindBufferRange;
GLAPI mgl_glBindBufferBase_t mgl_glBindBufferBase;
GLAPI mgl_glTransformFeedbackVaryings_t mgl_glTransformFeedbackVaryings;
GLAPI mgl_glGetTransformFeedbackVarying_t mgl_glGetTransformFeedbackVarying;
GLAPI mgl_glClampColor_t mgl_glClampColor;
GLAPI mgl_glBeginConditionalRender_t mgl_glBeginConditionalRender;
GLAPI mgl_glEndConditionalRender_t mgl_glEndConditionalRender;
GLAPI mgl_glVertexAttribIPointer_t mgl_glVertexAttribIPointer;
GLAPI mgl_glGetVertexAttribIiv_t mgl_glGetVertexAttribIiv;
GLAPI mgl_glGetVertexAttribIuiv_t mgl_glGetVertexAttribIuiv;
GLAPI mgl_glVertexAttribI1i_t mgl_glVertexAttribI1i;
GLAPI mgl_glVertexAttribI2i_t mgl_glVertexAttribI2i;
GLAPI mgl_glVertexAttribI3i_t mgl_glVertexAttribI3i;
GLAPI mgl_glVertexAttribI4i_t mgl_glVertexAttribI4i;
GLAPI mgl_glVertexAttribI1ui_t mgl_glVertexAttribI1ui;
GLAPI mgl_glVertexAttribI2ui_t mgl_glVertexAttribI2ui;
GLAPI mgl_glVertexAttribI3ui_t mgl_glVertexAttribI3ui;
GLAPI mgl_glVertexAttribI4ui_t mgl_glVertexAttribI4ui;
GLAPI mgl_glVertexAttribI1iv_t mgl_glVertexAttribI1iv;
GLAPI mgl_glVertexAttribI2iv_t mgl_glVertexAttribI2iv;
GLAPI mgl_glVertexAttribI3iv_t mgl_glVertexAttribI3iv;
GLAPI mgl_glVertexAttribI4iv_t mgl_glVertexAttribI4iv;
GLAPI mgl_glVertexAttribI1uiv_t mgl_glVertexAttribI1uiv;
GLAPI mgl_glVertexAttribI2uiv_t mgl_glVertexAttribI2uiv;
GLAPI mgl_glVertexAttribI3uiv_t mgl_glVertexAttribI3uiv;
GLAPI mgl_glVertexAttribI4uiv_t mgl_glVertexAttribI4uiv;
GLAPI mgl_glVertexAttribI4bv_t mgl_glVertexAttribI4bv;
GLAPI mgl_glVertexAttribI4sv_t mgl_glVertexAttribI4sv;
GLAPI mgl_glVertexAttribI4ubv_t mgl_glVertexAttribI4ubv;
GLAPI mgl_glVertexAttribI4usv_t mgl_glVertexAttribI4usv;
GLAPI mgl_glGetUniformuiv_t mgl_glGetUniformuiv;
GLAPI mgl_glBindFragDataLocation_t mgl_glBindFragDataLocation;
GLAPI mgl_glGetFragDataLocation_t mgl_glGetFragDataLocation;
GLAPI mgl_glUniform1ui_t mgl_glUniform1ui;
GLAPI mgl_glUniform2ui_t mgl_glUniform2ui;
GLAPI mgl_glUniform3ui_t mgl_glUniform3ui;
GLAPI mgl_glUniform4ui_t mgl_glUniform4ui;
GLAPI mgl_glUniform1uiv_t mgl_glUniform1uiv;
GLAPI mgl_glUniform2uiv_t mgl_glUniform2uiv;
GLAPI mgl_glUniform3uiv_t mgl_glUniform3uiv;
GLAPI mgl_glUniform4uiv_t mgl_glUniform4uiv;
GLAPI mgl_glTexParameterIiv_t mgl_glTexParameterIiv;
GLAPI mgl_glTexParameterIuiv_t mgl_glTexParameterIuiv;
GLAPI mgl_glGetTexParameterIiv_t mgl_glGetTexParameterIiv;
GLAPI mgl_glGetTexParameterIuiv_t mgl_glGetTexParameterIuiv;
GLAPI mgl_glClearBufferiv_t mgl_glClearBufferiv;
GLAPI mgl_glClearBufferuiv_t mgl_glClearBufferuiv;
GLAPI mgl_glClearBufferfv_t mgl_glClearBufferfv;
GLAPI mgl_glClearBufferfi_t mgl_glClearBufferfi;
GLAPI mgl_glGetStringi_t mgl_glGetStringi;
GLAPI mgl_glIsRenderbuffer_t mgl_glIsRenderbuffer;
GLAPI mgl_glBindRenderbuffer_t mgl_glBindRenderbuffer;
GLAPI mgl_glDeleteRenderbuffers_t mgl_glDeleteRenderbuffers;
GLAPI mgl_glGenRenderbuffers_t mgl_glGenRenderbuffers;
GLAPI mgl_glRenderbufferStorage_t mgl_glRenderbufferStorage;
GLAPI mgl_glGetRenderbufferParameteriv_t mgl_glGetRenderbufferParameteriv;
GLAPI mgl_glIsFramebuffer_t mgl_glIsFramebuffer;
GLAPI mgl_glBindFramebuffer_t mgl_glBindFramebuffer;
GLAPI mgl_glDeleteFramebuffers_t mgl_glDeleteFramebuffers;
GLAPI mgl_glGenFramebuffers_t mgl_glGenFramebuffers;
GLAPI mgl_glCheckFramebufferStatus_t mgl_glCheckFramebufferStatus;
GLAPI mgl_glFramebufferTexture1D_t mgl_glFramebufferTexture1D;
GLAPI mgl_glFramebufferTexture2D_t mgl_glFramebufferTexture2D;
GLAPI mgl_glFramebufferTexture3D_t mgl_glFramebufferTexture3D;
GLAPI mgl_glFramebufferRenderbuffer_t mgl_glFramebufferRenderbuffer;
GLAPI mgl_glGetFramebufferAttachmentParameteriv_t mgl_glGetFramebufferAttachmentParameteriv;
GLAPI mgl_glGenerateMipmap_t mgl_glGenerateMipmap;
GLAPI mgl_glBlitFramebuffer_t mgl_glBlitFramebuffer;
GLAPI mgl_glRenderbufferStorageMultisample_t mgl_glRenderbufferStorageMultisample;
GLAPI mgl_glFramebufferTextureLayer_t mgl_glFramebufferTextureLayer;
GLAPI mgl_glMapBufferRange_t mgl_glMapBufferRange;
GLAPI mgl_glFlushMappedBufferRange_t mgl_glFlushMappedBufferRange;
GLAPI mgl_glBindVertexArray_t mgl_glBindVertexArray;
GLAPI mgl_glDeleteVertexArrays_t mgl_glDeleteVertexArrays;
GLAPI mgl_glGenVertexArrays_t mgl_glGenVertexArrays;
GLAPI mgl_glIsVertexArray_t mgl_glIsVertexArray;
GLAPI mgl_glDrawArraysInstanced_t mgl_glDrawArraysInstanced;
GLAPI mgl_glDrawElementsInstanced_t mgl_glDrawElementsInstanced;
GLAPI mgl_glTexBuffer_t mgl_glTexBuffer;
GLAPI mgl_glPrimitiveRestartIndex_t mgl_glPrimitiveRestartIndex;
GLAPI mgl_glCopyBufferSubData_t mgl_glCopyBufferSubData;
GLAPI mgl_glGetUniformIndices_t mgl_glGetUniformIndices;
GLAPI mgl_glGetActiveUniformsiv_t mgl_glGetActiveUniformsiv;
GLAPI mgl_glGetActiveUniformName_t mgl_glGetActiveUniformName;
GLAPI mgl_glGetUniformBlockIndex_t mgl_glGetUniformBlockIndex;
GLAPI mgl_glGetActiveUniformBlockiv_t mgl_glGetActiveUniformBlockiv;
GLAPI mgl_glGetActiveUniformBlockName_t mgl_glGetActiveUniformBlockName;
GLAPI mgl_glUniformBlockBinding_t mgl_glUniformBlockBinding;
GLAPI mgl_glDrawElementsBaseVertex_t mgl_glDrawElementsBaseVertex;
GLAPI mgl_glDrawRangeElementsBaseVertex_t mgl_glDrawRangeElementsBaseVertex;
GLAPI mgl_glDrawElementsInstancedBaseVertex_t mgl_glDrawElementsInstancedBaseVertex;
GLAPI mgl_glMultiDrawElementsBaseVertex_t mgl_glMultiDrawElementsBaseVertex;
GLAPI mgl_glProvokingVertex_t mgl_glProvokingVertex;
GLAPI mgl_glFenceSync_t mgl_glFenceSync;
GLAPI mgl_glIsSync_t mgl_glIsSync;
GLAPI mgl_glDeleteSync_t mgl_glDeleteSync;
GLAPI mgl_glClientWaitSync_t mgl_glClientWaitSync;
GLAPI mgl_glWaitSync_t mgl_glWaitSync;
GLAPI mgl_glGetInteger64v_t mgl_glGetInteger64v;
GLAPI mgl_glGetSynciv_t mgl_glGetSynciv;
GLAPI mgl_glGetInteger64i_v_t mgl_glGetInteger64i_v;
GLAPI mgl_glGetBufferParameteri64v_t mgl_glGetBufferParameteri64v;
GLAPI mgl_glFramebufferTexture_t mgl_glFramebufferTexture;
GLAPI mgl_glTexImage2DMultisample_t mgl_glTexImage2DMultisample;
GLAPI mgl_glTexImage3DMultisample_t mgl_glTexImage3DMultisample;
GLAPI mgl_glGetMultisamplefv_t mgl_glGetMultisamplefv;
GLAPI mgl_glSampleMaski_t mgl_glSampleMaski;
GLAPI mgl_glBindFragDataLocationIndexed_t mgl_glBindFragDataLocationIndexed;
GLAPI mgl_glGetFragDataIndex_t mgl_glGetFragDataIndex;
GLAPI mgl_glGenSamplers_t mgl_glGenSamplers;
GLAPI mgl_glDeleteSamplers_t mgl_glDeleteSamplers;
GLAPI mgl_glIsSampler_t mgl_glIsSampler;
GLAPI mgl_glBindSampler_t mgl_glBindSampler;
GLAPI mgl_glSamplerParameteri_t mgl_glSamplerParameteri;
GLAPI mgl_glSamplerParameteriv_t mgl_glSamplerParameteriv;
GLAPI mgl_glSamplerParameterf_t mgl_glSamplerParameterf;
GLAPI mgl_glSamplerParameterfv_t mgl_glSamplerParameterfv;
GLAPI mgl_glSamplerParameterIiv_t mgl_glSamplerParameterIiv;
GLAPI mgl_glSamplerParameterIuiv_t mgl_glSamplerParameterIuiv;
GLAPI mgl_glGetSamplerParameteriv_t mgl_glGetSamplerParameteriv;
GLAPI mgl_glGetSamplerParameterIiv_t mgl_glGetSamplerParameterIiv;
GLAPI mgl_glGetSamplerParameterfv_t mgl_glGetSamplerParameterfv;
GLAPI mgl_glGetSamplerParameterIuiv_t mgl_glGetSamplerParameterIuiv;
GLAPI mgl_glQueryCounter_t mgl_glQueryCounter;
GLAPI mgl_glGetQueryObjecti64v_t mgl_glGetQueryObjecti64v;
GLAPI mgl_glGetQueryObjectui64v_t mgl_glGetQueryObjectui64v;
GLAPI mgl_glVertexAttribDivisor_t mgl_glVertexAttribDivisor;
GLAPI mgl_glVertexAttribP1ui_t mgl_glVertexAttribP1ui;
GLAPI mgl_glVertexAttribP1uiv_t mgl_glVertexAttribP1uiv;
GLAPI mgl_glVertexAttribP2ui_t mgl_glVertexAttribP2ui;
GLAPI mgl_glVertexAttribP2uiv_t mgl_glVertexAttribP2uiv;
GLAPI mgl_glVertexAttribP3ui_t mgl_glVertexAttribP3ui;
GLAPI mgl_glVertexAttribP3uiv_t mgl_glVertexAttribP3uiv;
GLAPI mgl_glVertexAttribP4ui_t mgl_glVertexAttribP4ui;
GLAPI mgl_glVertexAttribP4uiv_t mgl_glVertexAttribP4uiv;
GLAPI mgl_glMinSampleShading_t mgl_glMinSampleShading;
GLAPI mgl_glBlendEquationi_t mgl_glBlendEquationi;
GLAPI mgl_glBlendEquationSeparatei_t mgl_glBlendEquationSeparatei;
GLAPI mgl_glBlendFunci_t mgl_glBlendFunci;
GLAPI mgl_glBlendFuncSeparatei_t mgl_glBlendFuncSeparatei;
GLAPI mgl_glDrawArraysIndirect_t mgl_glDrawArraysIndirect;
GLAPI mgl_glDrawElementsIndirect_t mgl_glDrawElementsIndirect;
GLAPI mgl_glUniform1d_t mgl_glUniform1d;
GLAPI mgl_glUniform2d_t mgl_glUniform2d;
GLAPI mgl_glUniform3d_t mgl_glUniform3d;
GLAPI mgl_glUniform4d_t mgl_glUniform4d;
GLAPI mgl_glUniform1dv_t mgl_glUniform1dv;
GLAPI mgl_glUniform2dv_t mgl_glUniform2dv;
GLAPI mgl_glUniform3dv_t mgl_glUniform3dv;
GLAPI mgl_glUniform4dv_t mgl_glUniform4dv;
GLAPI mgl_glUniformMatrix2dv_t mgl_glUniformMatrix2dv;
GLAPI mgl_glUniformMatrix3dv_t mgl_glUniformMatrix3dv;
GLAPI mgl_glUniformMatrix4dv_t mgl_glUniformMatrix4dv;
GLAPI mgl_glUniformMatrix2x3dv_t mgl_glUniformMatrix2x3dv;
GLAPI mgl_glUniformMatrix2x4dv_t mgl_glUniformMatrix2x4dv;
GLAPI mgl_glUniformMatrix3x2dv_t mgl_glUniformMatrix3x2dv;
GLAPI mgl_glUniformMatrix3x4dv_t mgl_glUniformMatrix3x4dv;
GLAPI mgl_glUniformMatrix4x2dv_t mgl_glUniformMatrix4x2dv;
GLAPI mgl_glUniformMatrix4x3dv_t mgl_glUniformMatrix4x3dv;
GLAPI mgl_glGetUniformdv_t mgl_glGetUniformdv;
GLAPI mgl_glGetSubroutineUniformLocation_t mgl_glGetSubroutineUniformLocation;
GLAPI mgl_glGetSubroutineIndex_t mgl_glGetSubroutineIndex;
GLAPI mgl_glGetActiveSubroutineUniformiv_t mgl_glGetActiveSubroutineUniformiv;
GLAPI mgl_glGetActiveSubroutineUniformName_t mgl_glGetActiveSubroutineUniformName;
GLAPI mgl_glGetActiveSubroutineName_t mgl_glGetActiveSubroutineName;
GLAPI mgl_glUniformSubroutinesuiv_t mgl_glUniformSubroutinesuiv;
GLAPI mgl_glGetUniformSubroutineuiv_t mgl_glGetUniformSubroutineuiv;
GLAPI mgl_glGetProgramStageiv_t mgl_glGetProgramStageiv;
GLAPI mgl_glPatchParameteri_t mgl_glPatchParameteri;
GLAPI mgl_glPatchParameterfv_t mgl_glPatchParameterfv;
GLAPI mgl_glBindTransformFeedback_t mgl_glBindTransformFeedback;
GLAPI mgl_glDeleteTransformFeedbacks_t mgl_glDeleteTransformFeedbacks;
GLAPI mgl_glGenTransformFeedbacks_t mgl_glGenTransformFeedbacks;
GLAPI mgl_glIsTransformFeedback_t mgl_glIsTransformFeedback;
GLAPI mgl_glPauseTransformFeedback_t mgl_glPauseTransformFeedback;
GLAPI mgl_glResumeTransformFeedback_t mgl_glResumeTransformFeedback;
GLAPI mgl_glDrawTransformFeedback_t mgl_glDrawTransformFeedback;
GLAPI mgl_glDrawTransformFeedbackStream_t mgl_glDrawTransformFeedbackStream;
GLAPI mgl_glBeginQueryIndexed_t mgl_glBeginQueryIndexed;
GLAPI mgl_glEndQueryIndexed_t mgl_glEndQueryIndexed;
GLAPI mgl_glGetQueryIndexediv_t mgl_glGetQueryIndexediv;
GLAPI mgl_glReleaseShaderCompiler_t mgl_glReleaseShaderCompiler;
GLAPI mgl_glShaderBinary_t mgl_glShaderBinary;
GLAPI mgl_glGetShaderPrecisionFormat_t mgl_glGetShaderPrecisionFormat;
GLAPI mgl_glDepthRangef_t mgl_glDepthRangef;
GLAPI mgl_glClearDepthf_t mgl_glClearDepthf;
GLAPI mgl_glGetProgramBinary_t mgl_glGetProgramBinary;
GLAPI mgl_glProgramBinary_t mgl_glProgramBinary;
GLAPI mgl_glProgramParameteri_t mgl_glProgramParameteri;
GLAPI mgl_glUseProgramStages_t mgl_glUseProgramStages;
GLAPI mgl_glActiveShaderProgram_t mgl_glActiveShaderProgram;
GLAPI mgl_glCreateShaderProgramv_t mgl_glCreateShaderProgramv;
GLAPI mgl_glBindProgramPipeline_t mgl_glBindProgramPipeline;
GLAPI mgl_glDeleteProgramPipelines_t mgl_glDeleteProgramPipelines;
GLAPI mgl_glGenProgramPipelines_t mgl_glGenProgramPipelines;
GLAPI mgl_glIsProgramPipeline_t mgl_glIsProgramPipeline;
GLAPI mgl_glGetProgramPipelineiv_t mgl_glGetProgramPipelineiv;
GLAPI mgl_glProgramUniform1i_t mgl_glProgramUniform1i;
GLAPI mgl_glProgramUniform1iv_t mgl_glProgramUniform1iv;
GLAPI mgl_glProgramUniform1f_t mgl_glProgramUniform1f;
GLAPI mgl_glProgramUniform1fv_t mgl_glProgramUniform1fv;
GLAPI mgl_glProgramUniform1d_t mgl_glProgramUniform1d;
GLAPI mgl_glProgramUniform1dv_t mgl_glProgramUniform1dv;
GLAPI mgl_glProgramUniform1ui_t mgl_glProgramUniform1ui;
GLAPI mgl_glProgramUniform1uiv_t mgl_glProgramUniform1uiv;
GLAPI mgl_glProgramUniform2i_t mgl_glProgramUniform2i;
GLAPI mgl_glProgramUniform2iv_t mgl_glProgramUniform2iv;
GLAPI mgl_glProgramUniform2f_t mgl_glProgramUniform2f;
GLAPI mgl_glProgramUniform2fv_t mgl_glProgramUniform2fv;
GLAPI mgl_glProgramUniform2d_t mgl_glProgramUniform2d;
GLAPI mgl_glProgramUniform2dv_t mgl_glProgramUniform2dv;
GLAPI mgl_glProgramUniform2ui_t mgl_glProgramUniform2ui;
GLAPI mgl_glProgramUniform2uiv_t mgl_glProgramUniform2uiv;
GLAPI mgl_glProgramUniform3i_t mgl_glProgramUniform3i;
GLAPI mgl_glProgramUniform3iv_t mgl_glProgramUniform3iv;
GLAPI mgl_glProgramUniform3f_t mgl_glProgramUniform3f;
GLAPI mgl_glProgramUniform3fv_t mgl_glProgramUniform3fv;
GLAPI mgl_glProgramUniform3d_t mgl_glProgramUniform3d;
GLAPI mgl_glProgramUniform3dv_t mgl_glProgramUniform3dv;
GLAPI mgl_glProgramUniform3ui_t mgl_glProgramUniform3ui;
GLAPI mgl_glProgramUniform3uiv_t mgl_glProgramUniform3uiv;
GLAPI mgl_glProgramUniform4i_t mgl_glProgramUniform4i;
GLAPI mgl_glProgramUniform4iv_t mgl_glProgramUniform4iv;
GLAPI mgl_glProgramUniform4f_t mgl_glProgramUniform4f;
GLAPI mgl_glProgramUniform4fv_t mgl_glProgramUniform4fv;
GLAPI mgl_glProgramUniform4d_t mgl_glProgramUniform4d;
GLAPI mgl_glProgramUniform4dv_t mgl_glProgramUniform4dv;
GLAPI mgl_glProgramUniform4ui_t mgl_glProgramUniform4ui;
GLAPI mgl_glProgramUniform4uiv_t mgl_glProgramUniform4uiv;
GLAPI mgl_glProgramUniformMatrix2fv_t mgl_glProgramUniformMatrix2fv;
GLAPI mgl_glProgramUniformMatrix3fv_t mgl_glProgramUniformMatrix3fv;
GLAPI mgl_glProgramUniformMatrix4fv_t mgl_glProgramUniformMatrix4fv;
GLAPI mgl_glProgramUniformMatrix2dv_t mgl_glProgramUniformMatrix2dv;
GLAPI mgl_glProgramUniformMatrix3dv_t mgl_glProgramUniformMatrix3dv;
GLAPI mgl_glProgramUniformMatrix4dv_t mgl_glProgramUniformMatrix4dv;
GLAPI mgl_glProgramUniformMatrix2x3fv_t mgl_glProgramUniformMatrix2x3fv;
GLAPI mgl_glProgramUniformMatrix3x2fv_t mgl_glProgramUniformMatrix3x2fv;
GLAPI mgl_glProgramUniformMatrix2x4fv_t mgl_glProgramUniformMatrix2x4fv;
GLAPI mgl_glProgramUniformMatrix4x2fv_t mgl_glProgramUniformMatrix4x2fv;
GLAPI mgl_glProgramUniformMatrix3x4fv_t mgl_glProgramUniformMatrix3x4fv;
GLAPI mgl_glProgramUniformMatrix4x3fv_t mgl_glProgramUniformMatrix4x3fv;
GLAPI mgl_glProgramUniformMatrix2x3dv_t mgl_glProgramUniformMatrix2x3dv;
GLAPI mgl_glProgramUniformMatrix3x2dv_t mgl_glProgramUniformMatrix3x2dv;
GLAPI mgl_glProgramUniformMatrix2x4dv_t mgl_glProgramUniformMatrix2x4dv;
GLAPI mgl_glProgramUniformMatrix4x2dv_t mgl_glProgramUniformMatrix4x2dv;
GLAPI mgl_glProgramUniformMatrix3x4dv_t mgl_glProgramUniformMatrix3x4dv;
GLAPI mgl_glProgramUniformMatrix4x3dv_t mgl_glProgramUniformMatrix4x3dv;
GLAPI mgl_glValidateProgramPipeline_t mgl_glValidateProgramPipeline;
GLAPI mgl_glGetProgramPipelineInfoLog_t mgl_glGetProgramPipelineInfoLog;
GLAPI mgl_glVertexAttribL1d_t mgl_glVertexAttribL1d;
GLAPI mgl_glVertexAttribL2d_t mgl_glVertexAttribL2d;
GLAPI mgl_glVertexAttribL3d_t mgl_glVertexAttribL3d;
GLAPI mgl_glVertexAttribL4d_t mgl_glVertexAttribL4d;
GLAPI mgl_glVertexAttribL1dv_t mgl_glVertexAttribL1dv;
GLAPI mgl_glVertexAttribL2dv_t mgl_glVertexAttribL2dv;
GLAPI mgl_glVertexAttribL3dv_t mgl_glVertexAttribL3dv;
GLAPI mgl_glVertexAttribL4dv_t mgl_glVertexAttribL4dv;
GLAPI mgl_glVertexAttribLPointer_t mgl_glVertexAttribLPointer;
GLAPI mgl_glGetVertexAttribLdv_t mgl_glGetVertexAttribLdv;
GLAPI mgl_glViewportArrayv_t mgl_glViewportArrayv;
GLAPI mgl_glViewportIndexedf_t mgl_glViewportIndexedf;
GLAPI mgl_glViewportIndexedfv_t mgl_glViewportIndexedfv;
GLAPI mgl_glScissorArrayv_t mgl_glScissorArrayv;
GLAPI mgl_glScissorIndexed_t mgl_glScissorIndexed;
GLAPI mgl_glScissorIndexedv_t mgl_glScissorIndexedv;
GLAPI mgl_glDepthRangeArrayv_t mgl_glDepthRangeArrayv;
GLAPI mgl_glDepthRangeIndexed_t mgl_glDepthRangeIndexed;
GLAPI mgl_glGetFloati_v_t mgl_glGetFloati_v;
GLAPI mgl_glGetDoublei_v_t mgl_glGetDoublei_v;
GLAPI mgl_glDrawArraysInstancedBaseInstance_t mgl_glDrawArraysInstancedBaseInstance;
GLAPI mgl_glDrawElementsInstancedBaseInstance_t mgl_glDrawElementsInstancedBaseInstance;
GLAPI mgl_glDrawElementsInstancedBaseVertexBaseInstance_t mgl_glDrawElementsInstancedBaseVertexBaseInstance;
GLAPI mgl_glGetInternalformativ_t mgl_glGetInternalformativ;
GLAPI mgl_glGetActiveAtomicCounterBufferiv_t mgl_glGetActiveAtomicCounterBufferiv;
GLAPI mgl_glBindImageTexture_t mgl_glBindImageTexture;
GLAPI mgl_glMemoryBarrier_t mgl_glMemoryBarrier;
GLAPI mgl_glTexStorage1D_t mgl_glTexStorage1D;
GLAPI mgl_glTexStorage2D_t mgl_glTexStorage2D;
GLAPI mgl_glTexStorage3D_t mgl_glTexStorage3D;
GLAPI mgl_glDrawTransformFeedbackInstanced_t mgl_glDrawTransformFeedbackInstanced;
GLAPI mgl_glDrawTransformFeedbackStreamInstanced_t mgl_glDrawTransformFeedbackStreamInstanced;
GLAPI mgl_glClearBufferData_t mgl_glClearBufferData;
GLAPI mgl_glClearBufferSubData_t mgl_glClearBufferSubData;
GLAPI mgl_glDispatchCompute_t mgl_glDispatchCompute;
GLAPI mgl_glDispatchComputeIndirect_t mgl_glDispatchComputeIndirect;
GLAPI mgl_glCopyImageSubData_t mgl_glCopyImageSubData;
GLAPI mgl_glFramebufferParameteri_t mgl_glFramebufferParameteri;
GLAPI mgl_glGetFramebufferParameteriv_t mgl_glGetFramebufferParameteriv;
GLAPI mgl_glGetInternalformati64v_t mgl_glGetInternalformati64v;
GLAPI mgl_glInvalidateTexSubImage_t mgl_glInvalidateTexSubImage;
GLAPI mgl_glInvalidateTexImage_t mgl_glInvalidateTexImage;
GLAPI mgl_glInvalidateBufferSubData_t mgl_glInvalidateBufferSubData;
GLAPI mgl_glInvalidateBufferData_t mgl_glInvalidateBufferData;
GLAPI mgl_glInvalidateFramebuffer_t mgl_glInvalidateFramebuffer;
GLAPI mgl_glInvalidateSubFramebuffer_t mgl_glInvalidateSubFramebuffer;
GLAPI mgl_glMultiDrawArraysIndirect_t mgl_glMultiDrawArraysIndirect;
GLAPI mgl_glMultiDrawElementsIndirect_t mgl_glMultiDrawElementsIndirect;
GLAPI mgl_glGetProgramInterfaceiv_t mgl_glGetProgramInterfaceiv;
GLAPI mgl_glGetProgramResourceIndex_t mgl_glGetProgramResourceIndex;
GLAPI mgl_glGetProgramResourceName_t mgl_glGetProgramResourceName;
GLAPI mgl_glGetProgramResourceiv_t mgl_glGetProgramResourceiv;
GLAPI mgl_glGetProgramResourceLocation_t mgl_glGetProgramResourceLocation;
GLAPI mgl_glGetProgramResourceLocationIndex_t mgl_glGetProgramResourceLocationIndex;
GLAPI mgl_glShaderStorageBlockBinding_t mgl_glShaderStorageBlockBinding;
GLAPI mgl_glTexBufferRange_t mgl_glTexBufferRange;
GLAPI mgl_glTexStorage2DMultisample_t mgl_glTexStorage2DMultisample;
GLAPI mgl_glTexStorage3DMultisample_t mgl_glTexStorage3DMultisample;
GLAPI mgl_glTextureView_t mgl_glTextureView;
GLAPI mgl_glBindVertexBuffer_t mgl_glBindVertexBuffer;
GLAPI mgl_glVertexAttribFormat_t mgl_glVertexAttribFormat;
GLAPI mgl_glVertexAttribIFormat_t mgl_glVertexAttribIFormat;
GLAPI mgl_glVertexAttribLFormat_t mgl_glVertexAttribLFormat;
GLAPI mgl_glVertexAttribBinding_t mgl_glVertexAttribBinding;
GLAPI mgl_glVertexBindingDivisor_t mgl_glVertexBindingDivisor;
GLAPI mgl_glDebugMessageControl_t mgl_glDebugMessageControl;
GLAPI mgl_glDebugMessageInsert_t mgl_glDebugMessageInsert;
GLAPI mgl_glDebugMessageCallback_t mgl_glDebugMessageCallback;
GLAPI mgl_glGetDebugMessageLog_t mgl_glGetDebugMessageLog;
GLAPI mgl_glPushDebugGroup_t mgl_glPushDebugGroup;
GLAPI mgl_glPopDebugGroup_t mgl_glPopDebugGroup;
GLAPI mgl_glObjectLabel_t mgl_glObjectLabel;
GLAPI mgl_glGetObjectLabel_t mgl_glGetObjectLabel;
GLAPI mgl_glObjectPtrLabel_t mgl_glObjectPtrLabel;
GLAPI mgl_glGetObjectPtrLabel_t mgl_glGetObjectPtrLabel;
GLAPI mgl_glBufferStorage_t mgl_glBufferStorage;
GLAPI mgl_glClearTexImage_t mgl_glClearTexImage;
GLAPI mgl_glClearTexSubImage_t mgl_glClearTexSubImage;
GLAPI mgl_glBindBuffersBase_t mgl_glBindBuffersBase;
GLAPI mgl_glBindBuffersRange_t mgl_glBindBuffersRange;
GLAPI mgl_glBindTextures_t mgl_glBindTextures;
GLAPI mgl_glBindSamplers_t mgl_glBindSamplers;
GLAPI mgl_glBindImageTextures_t mgl_glBindImageTextures;
GLAPI mgl_glBindVertexBuffers_t mgl_glBindVertexBuffers;
GLAPI mgl_glClipControl_t mgl_glClipControl;
GLAPI mgl_glCreateTransformFeedbacks_t mgl_glCreateTransformFeedbacks;
GLAPI mgl_glTransformFeedbackBufferBase_t mgl_glTransformFeedbackBufferBase;
GLAPI mgl_glTransformFeedbackBufferRange_t mgl_glTransformFeedbackBufferRange;
GLAPI mgl_glGetTransformFeedbackiv_t mgl_glGetTransformFeedbackiv;
GLAPI mgl_glGetTransformFeedbacki_v_t mgl_glGetTransformFeedbacki_v;
GLAPI mgl_glGetTransformFeedbacki64_v_t mgl_glGetTransformFeedbacki64_v;
GLAPI mgl_glCreateBuffers_t mgl_glCreateBuffers;
GLAPI mgl_glNamedBufferStorage_t mgl_glNamedBufferStorage;
GLAPI mgl_glNamedBufferData_t mgl_glNamedBufferData;
GLAPI mgl_glNamedBufferSubData_t mgl_glNamedBufferSubData;
GLAPI mgl_glCopyNamedBufferSubData_t mgl_glCopyNamedBufferSubData;
GLAPI mgl_glClearNamedBufferData_t mgl_glClearNamedBufferData;
GLAPI mgl_glClearNamedBufferSubData_t mgl_glClearNamedBufferSubData;
GLAPI mgl_glMapNamedBuffer_t mgl_glMapNamedBuffer;
GLAPI mgl_glMapNamedBufferRange_t mgl_glMapNamedBufferRange;
GLAPI mgl_glUnmapNamedBuffer_t mgl_glUnmapNamedBuffer;
GLAPI mgl_glFlushMappedNamedBufferRange_t mgl_glFlushMappedNamedBufferRange;
GLAPI mgl_glGetNamedBufferParameteriv_t mgl_glGetNamedBufferParameteriv;
GLAPI mgl_glGetNamedBufferParameteri64v_t mgl_glGetNamedBufferParameteri64v;
GLAPI mgl_glGetNamedBufferPointerv_t mgl_glGetNamedBufferPointerv;
GLAPI mgl_glGetNamedBufferSubData_t mgl_glGetNamedBufferSubData;
GLAPI mgl_glCreateFramebuffers_t mgl_glCreateFramebuffers;
GLAPI mgl_glNamedFramebufferRenderbuffer_t mgl_glNamedFramebufferRenderbuffer;
GLAPI mgl_glNamedFramebufferParameteri_t mgl_glNamedFramebufferParameteri;
GLAPI mgl_glNamedFramebufferTexture_t mgl_glNamedFramebufferTexture;
GLAPI mgl_glNamedFramebufferTextureLayer_t mgl_glNamedFramebufferTextureLayer;
GLAPI mgl_glNamedFramebufferDrawBuffer_t mgl_glNamedFramebufferDrawBuffer;
GLAPI mgl_glNamedFramebufferDrawBuffers_t mgl_glNamedFramebufferDrawBuffers;
GLAPI mgl_glNamedFramebufferReadBuffer_t mgl_glNamedFramebufferReadBuffer;
GLAPI mgl_glInvalidateNamedFramebufferData_t mgl_glInvalidateNamedFramebufferData;
GLAPI mgl_glInvalidateNamedFramebufferSubData_t mgl_glInvalidateNamedFramebufferSubData;
GLAPI mgl_glClearNamedFramebufferiv_t mgl_glClearNamedFramebufferiv;
GLAPI mgl_glClearNamedFramebufferuiv_t mgl_glClearNamedFramebufferuiv;
GLAPI mgl_glClearNamedFramebufferfv_t mgl_glClearNamedFramebufferfv;
GLAPI mgl_glClearNamedFramebufferfi_t mgl_glClearNamedFramebufferfi;
GLAPI mgl_glBlitNamedFramebuffer_t mgl_glBlitNamedFramebuffer;
GLAPI mgl_glCheckNamedFramebufferStatus_t mgl_glCheckNamedFramebufferStatus;
GLAPI mgl_glGetNamedFramebufferParameteriv_t mgl_glGetNamedFramebufferParameteriv;
GLAPI mgl_glGetNamedFramebufferAttachmentParameteriv_t mgl_glGetNamedFramebufferAttachmentParameteriv;
GLAPI mgl_glCreateRenderbuffers_t mgl_glCreateRenderbuffers;
GLAPI mgl_glNamedRenderbufferStorage_t mgl_glNamedRenderbufferStorage;
GLAPI mgl_glNamedRenderbufferStorageMultisample_t mgl_glNamedRenderbufferStorageMultisample;
GLAPI mgl_glGetNamedRenderbufferParameteriv_t mgl_glGetNamedRenderbufferParameteriv;
GLAPI mgl_glCreateTextures_t mgl_glCreateTextures;
GLAPI mgl_glTextureBuffer_t mgl_glTextureBuffer;
GLAPI mgl_glTextureBufferRange_t mgl_glTextureBufferRange;
GLAPI mgl_glTextureStorage1D_t mgl_glTextureStorage1D;
GLAPI mgl_glTextureStorage2D_t mgl_glTextureStorage2D;
GLAPI mgl_glTextureStorage3D_t mgl_glTextureStorage3D;
GLAPI mgl_glTextureStorage2DMultisample_t mgl_glTextureStorage2DMultisample;
GLAPI mgl_glTextureStorage3DMultisample_t mgl_glTextureStorage3DMultisample;
GLAPI mgl_glTextureSubImage1D_t mgl_glTextureSubImage1D;
GLAPI mgl_glTextureSubImage2D_t mgl_glTextureSubImage2D;
GLAPI mgl_glTextureSubImage3D_t mgl_glTextureSubImage3D;
GLAPI mgl_glCompressedTextureSubImage1D_t mgl_glCompressedTextureSubImage1D;
GLAPI mgl_glCompressedTextureSubImage2D_t mgl_glCompressedTextureSubImage2D;
GLAPI mgl_glCompressedTextureSubImage3D_t mgl_glCompressedTextureSubImage3D;
GLAPI mgl_glCopyTextureSubImage1D_t mgl_glCopyTextureSubImage1D;
GLAPI mgl_glCopyTextureSubImage2D_t mgl_glCopyTextureSubImage2D;
GLAPI mgl_glCopyTextureSubImage3D_t mgl_glCopyTextureSubImage3D;
GLAPI mgl_glTextureParameterf_t mgl_glTextureParameterf;
GLAPI mgl_glTextureParameterfv_t mgl_glTextureParameterfv;
GLAPI mgl_glTextureParameteri_t mgl_glTextureParameteri;
GLAPI mgl_glTextureParameterIiv_t mgl_glTextureParameterIiv;
GLAPI mgl_glTextureParameterIuiv_t mgl_glTextureParameterIuiv;
GLAPI mgl_glTextureParameteriv_t mgl_glTextureParameteriv;
GLAPI mgl_glGenerateTextureMipmap_t mgl_glGenerateTextureMipmap;
GLAPI mgl_glBindTextureUnit_t mgl_glBindTextureUnit;
GLAPI mgl_glGetTextureImage_t mgl_glGetTextureImage;
GLAPI mgl_glGetCompressedTextureImage_t mgl_glGetCompressedTextureImage;
GLAPI mgl_glGetTextureLevelParameterfv_t mgl_glGetTextureLevelParameterfv;
GLAPI mgl_glGetTextureLevelParameteriv_t mgl_glGetTextureLevelParameteriv;
GLAPI mgl_glGetTextureParameterfv_t mgl_glGetTextureParameterfv;
GLAPI mgl_glGetTextureParameterIiv_t mgl_glGetTextureParameterIiv;
GLAPI mgl_glGetTextureParameterIuiv_t mgl_glGetTextureParameterIuiv;
GLAPI mgl_glGetTextureParameteriv_t mgl_glGetTextureParameteriv;
GLAPI mgl_glCreateVertexArrays_t mgl_glCreateVertexArrays;
GLAPI mgl_glDisableVertexArrayAttrib_t mgl_glDisableVertexArrayAttrib;
GLAPI mgl_glEnableVertexArrayAttrib_t mgl_glEnableVertexArrayAttrib;
GLAPI mgl_glVertexArrayElementBuffer_t mgl_glVertexArrayElementBuffer;
GLAPI mgl_glVertexArrayVertexBuffer_t mgl_glVertexArrayVertexBuffer;
GLAPI mgl_glVertexArrayVertexBuffers_t mgl_glVertexArrayVertexBuffers;
GLAPI mgl_glVertexArrayAttribBinding_t mgl_glVertexArrayAttribBinding;
GLAPI mgl_glVertexArrayAttribFormat_t mgl_glVertexArrayAttribFormat;
GLAPI mgl_glVertexArrayAttribIFormat_t mgl_glVertexArrayAttribIFormat;
GLAPI mgl_glVertexArrayAttribLFormat_t mgl_glVertexArrayAttribLFormat;
GLAPI mgl_glVertexArrayBindingDivisor_t mgl_glVertexArrayBindingDivisor;
GLAPI mgl_glGetVertexArrayiv_t mgl_glGetVertexArrayiv;
GLAPI mgl_glGetVertexArrayIndexediv_t mgl_glGetVertexArrayIndexediv;
GLAPI mgl_glGetVertexArrayIndexed64iv_t mgl_glGetVertexArrayIndexed64iv;
GLAPI mgl_glCreateSamplers_t mgl_glCreateSamplers;
GLAPI mgl_glCreateProgramPipelines_t mgl_glCreateProgramPipelines;
GLAPI mgl_glCreateQueries_t mgl_glCreateQueries;
GLAPI mgl_glGetQueryBufferObjecti64v_t mgl_glGetQueryBufferObjecti64v;
GLAPI mgl_glGetQueryBufferObjectiv_t mgl_glGetQueryBufferObjectiv;
GLAPI mgl_glGetQueryBufferObjectui64v_t mgl_glGetQueryBufferObjectui64v;
GLAPI mgl_glGetQueryBufferObjectuiv_t mgl_glGetQueryBufferObjectuiv;
GLAPI mgl_glMemoryBarrierByRegion_t mgl_glMemoryBarrierByRegion;
GLAPI mgl_glGetTextureSubImage_t mgl_glGetTextureSubImage;
GLAPI mgl_glGetCompressedTextureSubImage_t mgl_glGetCompressedTextureSubImage;
GLAPI mgl_glGetGraphicsResetStatus_t mgl_glGetGraphicsResetStatus;
GLAPI mgl_glGetnCompressedTexImage_t mgl_glGetnCompressedTexImage;
GLAPI mgl_glGetnTexImage_t mgl_glGetnTexImage;
GLAPI mgl_glGetnUniformdv_t mgl_glGetnUniformdv;
GLAPI mgl_glGetnUniformfv_t mgl_glGetnUniformfv;
GLAPI mgl_glGetnUniformiv_t mgl_glGetnUniformiv;
GLAPI mgl_glGetnUniformuiv_t mgl_glGetnUniformuiv;
GLAPI mgl_glReadnPixels_t mgl_glReadnPixels;
GLAPI mgl_glTextureBarrier_t mgl_glTextureBarrier;
GLAPI mgl_glSpecializeShader_t mgl_glSpecializeShader;
GLAPI mgl_glMultiDrawArraysIndirectCount_t mgl_glMultiDrawArraysIndirectCount;
GLAPI mgl_glMultiDrawElementsIndirectCount_t mgl_glMultiDrawElementsIndirectCount;
GLAPI mgl_glPolygonOffsetClamp_t mgl_glPolygonOffsetClamp;

#define glCullFace mgl_glCullFace
#define glFrontFace mgl_glFrontFace
#define glHint mgl_glHint
#define glLineWidth mgl_glLineWidth
#define glPointSize mgl_glPointSize
#define glPolygonMode mgl_glPolygonMode
#define glScissor mgl_glScissor
#define glTexParameterf mgl_glTexParameterf
#define glTexParameterfv mgl_glTexParameterfv
#define glTexParameteri mgl_glTexParameteri
#define glTexParameteriv mgl_glTexParameteriv
#define glTexImage1D mgl_glTexImage1D
#define glTexImage2D mgl_glTexImage2D
#define glDrawBuffer mgl_glDrawBuffer
#define glClear mgl_glClear
#define glClearColor mgl_glClearColor
#define glClearStencil mgl_glClearStencil
#define glClearDepth mgl_glClearDepth
#define glStencilMask mgl_glStencilMask
#define glColorMask mgl_glColorMask
#define glDepthMask mgl_glDepthMask
#define glDisable mgl_glDisable
#define glEnable mgl_glEnable
#define glFinish mgl_glFinish
#define glFlush mgl_glFlush
#define glBlendFunc mgl_glBlendFunc
#define glLogicOp mgl_glLogicOp
#define glStencilFunc mgl_glStencilFunc
#define glStencilOp mgl_glStencilOp
#define glDepthFunc mgl_glDepthFunc
#define glPixelStoref mgl_glPixelStoref
#define glPixelStorei mgl_glPixelStorei
#define glReadBuffer mgl_glReadBuffer
#define glReadPixels mgl_glReadPixels
#define glGetBooleanv mgl_glGetBooleanv
#define glGetDoublev mgl_glGetDoublev
#define glGetError mgl_glGetError
#define glGetFloatv mgl_glGetFloatv
#define glGetIntegerv mgl_glGetIntegerv
#define glGetString mgl_glGetString
#define glGetTexImage mgl_glGetTexImage
#define glGetTexParameterfv mgl_glGetTexParameterfv
#define glGetTexParameteriv mgl_glGetTexParameteriv
#define glGetTexLevelParameterfv mgl_glGetTexLevelParameterfv
#define glGetTexLevelParameteriv mgl_glGetTexLevelParameteriv
#define glIsEnabled mgl_glIsEnabled
#define glDepthRange mgl_glDepthRange
#define glViewport mgl_glViewport
#define glNewList mgl_glNewList
#define glEndList mgl_glEndList
#define glCallList mgl_glCallList
#define glCallLists mgl_glCallLists
#define glDeleteLists mgl_glDeleteLists
#define glGenLists mgl_glGenLists
#define glListBase mgl_glListBase
#define glBegin mgl_glBegin
#define glBitmap mgl_glBitmap
#define glColor3b mgl_glColor3b
#define glColor3bv mgl_glColor3bv
#define glColor3d mgl_glColor3d
#define glColor3dv mgl_glColor3dv
#define glColor3f mgl_glColor3f
#define glColor3fv mgl_glColor3fv
#define glColor3i mgl_glColor3i
#define glColor3iv mgl_glColor3iv
#define glColor3s mgl_glColor3s
#define glColor3sv mgl_glColor3sv
#define glColor3ub mgl_glColor3ub
#define glColor3ubv mgl_glColor3ubv
#define glColor3ui mgl_glColor3ui
#define glColor3uiv mgl_glColor3uiv
#define glColor3us mgl_glColor3us
#define glColor3usv mgl_glColor3usv
#define glColor4b mgl_glColor4b
#define glColor4bv mgl_glColor4bv
#define glColor4d mgl_glColor4d
#define glColor4dv mgl_glColor4dv
#define glColor4f mgl_glColor4f
#define glColor4fv mgl_glColor4fv
#define glColor4i mgl_glColor4i
#define glColor4iv mgl_glColor4iv
#define glColor4s mgl_glColor4s
#define glColor4sv mgl_glColor4sv
#define glColor4ub mgl_glColor4ub
#define glColor4ubv mgl_glColor4ubv
#define glColor4ui mgl_glColor4ui
#define glColor4uiv mgl_glColor4uiv
#define glColor4us mgl_glColor4us
#define glColor4usv mgl_glColor4usv
#define glEdgeFlag mgl_glEdgeFlag
#define glEdgeFlagv mgl_glEdgeFlagv
#define glEnd mgl_glEnd
#define glIndexd mgl_glIndexd
#define glIndexdv mgl_glIndexdv
#define glIndexf mgl_glIndexf
#define glIndexfv mgl_glIndexfv
#define glIndexi mgl_glIndexi
#define glIndexiv mgl_glIndexiv
#define glIndexs mgl_glIndexs
#define glIndexsv mgl_glIndexsv
#define glNormal3b mgl_glNormal3b
#define glNormal3bv mgl_glNormal3bv
#define glNormal3d mgl_glNormal3d
#define glNormal3dv mgl_glNormal3dv
#define glNormal3f mgl_glNormal3f
#define glNormal3fv mgl_glNormal3fv
#define glNormal3i mgl_glNormal3i
#define glNormal3iv mgl_glNormal3iv
#define glNormal3s mgl_glNormal3s
#define glNormal3sv mgl_glNormal3sv
#define glRasterPos2d mgl_glRasterPos2d
#define glRasterPos2dv mgl_glRasterPos2dv
#define glRasterPos2f mgl_glRasterPos2f
#define glRasterPos2fv mgl_glRasterPos2fv
#define glRasterPos2i mgl_glRasterPos2i
#define glRasterPos2iv mgl_glRasterPos2iv
#define glRasterPos2s mgl_glRasterPos2s
#define glRasterPos2sv mgl_glRasterPos2sv
#define glRasterPos3d mgl_glRasterPos3d
#define glRasterPos3dv mgl_glRasterPos3dv
#define glRasterPos3f mgl_glRasterPos3f
#define glRasterPos3fv mgl_glRasterPos3fv
#define glRasterPos3i mgl_glRasterPos3i
#define glRasterPos3iv mgl_glRasterPos3iv
#define glRasterPos3s mgl_glRasterPos3s
#define glRasterPos3sv mgl_glRasterPos3sv
#define glRasterPos4d mgl_glRasterPos4d
#define glRasterPos4dv mgl_glRasterPos4dv
#define glRasterPos4f mgl_glRasterPos4f
#define glRasterPos4fv mgl_glRasterPos4fv
#define glRasterPos4i mgl_glRasterPos4i
#define glRasterPos4iv mgl_glRasterPos4iv
#define glRasterPos4s mgl_glRasterPos4s
#define glRasterPos4sv mgl_glRasterPos4sv
#define glRectd mgl_glRectd
#define glRectdv mgl_glRectdv
#define glRectf mgl_glRectf
#define glRectfv mgl_glRectfv
#define glRecti mgl_glRecti
#define glRectiv mgl_glRectiv
#define glRects mgl_glRects
#define glRectsv mgl_glRectsv
#define glTexCoord1d mgl_glTexCoord1d
#define glTexCoord1dv mgl_glTexCoord1dv
#define glTexCoord1f mgl_glTexCoord1f
#define glTexCoord1fv mgl_glTexCoord1fv
#define glTexCoord1i mgl_glTexCoord1i
#define glTexCoord1iv mgl_glTexCoord1iv
#define glTexCoord1s mgl_glTexCoord1s
#define glTexCoord1sv mgl_glTexCoord1sv
#define glTexCoord2d mgl_glTexCoord2d
#define glTexCoord2dv mgl_glTexCoord2dv
#define glTexCoord2f mgl_glTexCoord2f
#define glTexCoord2fv mgl_glTexCoord2fv
#define glTexCoord2i mgl_glTexCoord2i
#define glTexCoord2iv mgl_glTexCoord2iv
#define glTexCoord2s mgl_glTexCoord2s
#define glTexCoord2sv mgl_glTexCoord2sv
#define glTexCoord3d mgl_glTexCoord3d
#define glTexCoord3dv mgl_glTexCoord3dv
#define glTexCoord3f mgl_glTexCoord3f
#define glTexCoord3fv mgl_glTexCoord3fv
#define glTexCoord3i mgl_glTexCoord3i
#define glTexCoord3iv mgl_glTexCoord3iv
#define glTexCoord3s mgl_glTexCoord3s
#define glTexCoord3sv mgl_glTexCoord3sv
#define glTexCoord4d mgl_glTexCoord4d
#define glTexCoord4dv mgl_glTexCoord4dv
#define glTexCoord4f mgl_glTexCoord4f
#define glTexCoord4fv mgl_glTexCoord4fv
#define glTexCoord4i mgl_glTexCoord4i
#define glTexCoord4iv mgl_glTexCoord4iv
#define glTexCoord4s mgl_glTexCoord4s
#define glTexCoord4sv mgl_glTexCoord4sv
#define glVertex2d mgl_glVertex2d
#define glVertex2dv mgl_glVertex2dv
#define glVertex2f mgl_glVertex2f
#define glVertex2fv mgl_glVertex2fv
#define glVertex2i mgl_glVertex2i
#define glVertex2iv mgl_glVertex2iv
#define glVertex2s mgl_glVertex2s
#define glVertex2sv mgl_glVertex2sv
#define glVertex3d mgl_glVertex3d
#define glVertex3dv mgl_glVertex3dv
#define glVertex3f mgl_glVertex3f
#define glVertex3fv mgl_glVertex3fv
#define glVertex3i mgl_glVertex3i
#define glVertex3iv mgl_glVertex3iv
#define glVertex3s mgl_glVertex3s
#define glVertex3sv mgl_glVertex3sv
#define glVertex4d mgl_glVertex4d
#define glVertex4dv mgl_glVertex4dv
#define glVertex4f mgl_glVertex4f
#define glVertex4fv mgl_glVertex4fv
#define glVertex4i mgl_glVertex4i
#define glVertex4iv mgl_glVertex4iv
#define glVertex4s mgl_glVertex4s
#define glVertex4sv mgl_glVertex4sv
#define glClipPlane mgl_glClipPlane
#define glColorMaterial mgl_glColorMaterial
#define glFogf mgl_glFogf
#define glFogfv mgl_glFogfv
#define glFogi mgl_glFogi
#define glFogiv mgl_glFogiv
#define glLightf mgl_glLightf
#define glLightfv mgl_glLightfv
#define glLighti mgl_glLighti
#define glLightiv mgl_glLightiv
#define glLightModelf mgl_glLightModelf
#define glLightModelfv mgl_glLightModelfv
#define glLightModeli mgl_glLightModeli
#define glLightModeliv mgl_glLightModeliv
#define glLineStipple mgl_glLineStipple
#define glMaterialf mgl_glMaterialf
#define glMaterialfv mgl_glMaterialfv
#define glMateriali mgl_glMateriali
#define glMaterialiv mgl_glMaterialiv
#define glPolygonStipple mgl_glPolygonStipple
#define glShadeModel mgl_glShadeModel
#define glTexEnvf mgl_glTexEnvf
#define glTexEnvfv mgl_glTexEnvfv
#define glTexEnvi mgl_glTexEnvi
#define glTexEnviv mgl_glTexEnviv
#define glTexGend mgl_glTexGend
#define glTexGendv mgl_glTexGendv
#define glTexGenf mgl_glTexGenf
#define glTexGenfv mgl_glTexGenfv
#define glTexGeni mgl_glTexGeni
#define glTexGeniv mgl_glTexGeniv
#define glFeedbackBuffer mgl_glFeedbackBuffer
#define glSelectBuffer mgl_glSelectBuffer
#define glRenderMode mgl_glRenderMode
#define glInitNames mgl_glInitNames
#define glLoadName mgl_glLoadName
#define glPassThrough mgl_glPassThrough
#define glPopName mgl_glPopName
#define glPushName mgl_glPushName
#define glClearAccum mgl_glClearAccum
#define glClearIndex mgl_glClearIndex
#define glIndexMask mgl_glIndexMask
#define glAccum mgl_glAccum
#define glPopAttrib mgl_glPopAttrib
#define glPushAttrib mgl_glPushAttrib
#define glMap1d mgl_glMap1d
#define glMap1f mgl_glMap1f
#define glMap2d mgl_glMap2d
#define glMap2f mgl_glMap2f
#define glMapGrid1d mgl_glMapGrid1d
#define glMapGrid1f mgl_glMapGrid1f
#define glMapGrid2d mgl_glMapGrid2d
#define glMapGrid2f mgl_glMapGrid2f
#define glEvalCoord1d mgl_glEvalCoord1d
#define glEvalCoord1dv mgl_glEvalCoord1dv
#define glEvalCoord1f mgl_glEvalCoord1f
#define glEvalCoord1fv mgl_glEvalCoord1fv
#define glEvalCoord2d mgl_glEvalCoord2d
#define glEvalCoord2dv mgl_glEvalCoord2dv
#define glEvalCoord2f mgl_glEvalCoord2f
#define glEvalCoord2fv mgl_glEvalCoord2fv
#define glEvalMesh1 mgl_glEvalMesh1
#define glEvalPoint1 mgl_glEvalPoint1
#define glEvalMesh2 mgl_glEvalMesh2
#define glEvalPoint2 mgl_glEvalPoint2
#define glAlphaFunc mgl_glAlphaFunc
#define glPixelZoom mgl_glPixelZoom
#define glPixelTransferf mgl_glPixelTransferf
#define glPixelTransferi mgl_glPixelTransferi
#define glPixelMapfv mgl_glPixelMapfv
#define glPixelMapuiv mgl_glPixelMapuiv
#define glPixelMapusv mgl_glPixelMapusv
#define glCopyPixels mgl_glCopyPixels
#define glDrawPixels mgl_glDrawPixels
#define glGetClipPlane mgl_glGetClipPlane
#define glGetLightfv mgl_glGetLightfv
#define glGetLightiv mgl_glGetLightiv
#define glGetMapdv mgl_glGetMapdv
#define glGetMapfv mgl_glGetMapfv
#define glGetMapiv mgl_glGetMapiv
#define glGetMaterialfv mgl_glGetMaterialfv
#define glGetMaterialiv mgl_glGetMaterialiv
#define glGetPixelMapfv mgl_glGetPixelMapfv
#define glGetPixelMapuiv mgl_glGetPixelMapuiv
#define glGetPixelMapusv mgl_glGetPixelMapusv
#define glGetPolygonStipple mgl_glGetPolygonStipple
#define glGetTexEnvfv mgl_glGetTexEnvfv
#define glGetTexEnviv mgl_glGetTexEnviv
#define glGetTexGendv mgl_glGetTexGendv
#define glGetTexGenfv mgl_glGetTexGenfv
#define glGetTexGeniv mgl_glGetTexGeniv
#define glIsList mgl_glIsList
#define glFrustum mgl_glFrustum
#define glLoadIdentity mgl_glLoadIdentity
#define glLoadMatrixf mgl_glLoadMatrixf
#define glLoadMatrixd mgl_glLoadMatrixd
#define glMatrixMode mgl_glMatrixMode
#define glMultMatrixf mgl_glMultMatrixf
#define glMultMatrixd mgl_glMultMatrixd
#define glOrtho mgl_glOrtho
#define glPopMatrix mgl_glPopMatrix
#define glPushMatrix mgl_glPushMatrix
#define glRotated mgl_glRotated
#define glRotatef mgl_glRotatef
#define glScaled mgl_glScaled
#define glScalef mgl_glScalef
#define glTranslated mgl_glTranslated
#define glTranslatef mgl_glTranslatef
#define glDrawArrays mgl_glDrawArrays
#define glDrawElements mgl_glDrawElements
#define glGetPointerv mgl_glGetPointerv
#define glPolygonOffset mgl_glPolygonOffset
#define glCopyTexImage1D mgl_glCopyTexImage1D
#define glCopyTexImage2D mgl_glCopyTexImage2D
#define glCopyTexSubImage1D mgl_glCopyTexSubImage1D
#define glCopyTexSubImage2D mgl_glCopyTexSubImage2D
#define glTexSubImage1D mgl_glTexSubImage1D
#define glTexSubImage2D mgl_glTexSubImage2D
#define glBindTexture mgl_glBindTexture
#define glDeleteTextures mgl_glDeleteTextures
#define glGenTextures mgl_glGenTextures
#define glIsTexture mgl_glIsTexture
#define glArrayElement mgl_glArrayElement
#define glColorPointer mgl_glColorPointer
#define glDisableClientState mgl_glDisableClientState
#define glEdgeFlagPointer mgl_glEdgeFlagPointer
#define glEnableClientState mgl_glEnableClientState
#define glIndexPointer mgl_glIndexPointer
#define glInterleavedArrays mgl_glInterleavedArrays
#define glNormalPointer mgl_glNormalPointer
#define glTexCoordPointer mgl_glTexCoordPointer
#define glVertexPointer mgl_glVertexPointer
#define glAreTexturesResident mgl_glAreTexturesResident
#define glPrioritizeTextures mgl_glPrioritizeTextures
#define glIndexub mgl_glIndexub
#define glIndexubv mgl_glIndexubv
#define glPopClientAttrib mgl_glPopClientAttrib
#define glPushClientAttrib mgl_glPushClientAttrib
#define glDrawRangeElements mgl_glDrawRangeElements
#define glTexImage3D mgl_glTexImage3D
#define glTexSubImage3D mgl_glTexSubImage3D
#define glCopyTexSubImage3D mgl_glCopyTexSubImage3D
#define glActiveTexture mgl_glActiveTexture
#define glSampleCoverage mgl_glSampleCoverage
#define glCompressedTexImage3D mgl_glCompressedTexImage3D
#define glCompressedTexImage2D mgl_glCompressedTexImage2D
#define glCompressedTexImage1D mgl_glCompressedTexImage1D
#define glCompressedTexSubImage3D mgl_glCompressedTexSubImage3D
#define glCompressedTexSubImage2D mgl_glCompressedTexSubImage2D
#define glCompressedTexSubImage1D mgl_glCompressedTexSubImage1D
#define glGetCompressedTexImage mgl_glGetCompressedTexImage
#define glClientActiveTexture mgl_glClientActiveTexture
#define glMultiTexCoord1d mgl_glMultiTexCoord1d
#define glMultiTexCoord1dv mgl_glMultiTexCoord1dv
#define glMultiTexCoord1f mgl_glMultiTexCoord1f
#define glMultiTexCoord1fv mgl_glMultiTexCoord1fv
#define glMultiTexCoord1i mgl_glMultiTexCoord1i
#define glMultiTexCoord1iv mgl_glMultiTexCoord1iv
#define glMultiTexCoord1s mgl_glMultiTexCoord1s
#define glMultiTexCoord1sv mgl_glMultiTexCoord1sv
#define glMultiTexCoord2d mgl_glMultiTexCoord2d
#define glMultiTexCoord2dv mgl_glMultiTexCoord2dv
#define glMultiTexCoord2f mgl_glMultiTexCoord2f
#define glMultiTexCoord2fv mgl_glMultiTexCoord2fv
#define glMultiTexCoord2i mgl_glMultiTexCoord2i
#define glMultiTexCoord2iv mgl_glMultiTexCoord2iv
#define glMultiTexCoord2s mgl_glMultiTexCoord2s
#define glMultiTexCoord2sv mgl_glMultiTexCoord2sv
#define glMultiTexCoord3d mgl_glMultiTexCoord3d
#define glMultiTexCoord3dv mgl_glMultiTexCoord3dv
#define glMultiTexCoord3f mgl_glMultiTexCoord3f
#define glMultiTexCoord3fv mgl_glMultiTexCoord3fv
#define glMultiTexCoord3i mgl_glMultiTexCoord3i
#define glMultiTexCoord3iv mgl_glMultiTexCoord3iv
#define glMultiTexCoord3s mgl_glMultiTexCoord3s
#define glMultiTexCoord3sv mgl_glMultiTexCoord3sv
#define glMultiTexCoord4d mgl_glMultiTexCoord4d
#define glMultiTexCoord4dv mgl_glMultiTexCoord4dv
#define glMultiTexCoord4f mgl_glMultiTexCoord4f
#define glMultiTexCoord4fv mgl_glMultiTexCoord4fv
#define glMultiTexCoord4i mgl_glMultiTexCoord4i
#define glMultiTexCoord4iv mgl_glMultiTexCoord4iv
#define glMultiTexCoord4s mgl_glMultiTexCoord4s
#define glMultiTexCoord4sv mgl_glMultiTexCoord4sv
#define glLoadTransposeMatrixf mgl_glLoadTransposeMatrixf
#define glLoadTransposeMatrixd mgl_glLoadTransposeMatrixd
#define glMultTransposeMatrixf mgl_glMultTransposeMatrixf
#define glMultTransposeMatrixd mgl_glMultTransposeMatrixd
#define glBlendFuncSeparate mgl_glBlendFuncSeparate
#define glMultiDrawArrays mgl_glMultiDrawArrays
#define glMultiDrawElements mgl_glMultiDrawElements
#define glPointParameterf mgl_glPointParameterf
#define glPointParameterfv mgl_glPointParameterfv
#define glPointParameteri mgl_glPointParameteri
#define glPointParameteriv mgl_glPointParameteriv
#define glFogCoordf mgl_glFogCoordf
#define glFogCoordfv mgl_glFogCoordfv
#define glFogCoordd mgl_glFogCoordd
#define glFogCoorddv mgl_glFogCoorddv
#define glFogCoordPointer mgl_glFogCoordPointer
#define glSecondaryColor3b mgl_glSecondaryColor3b
#define glSecondaryColor3bv mgl_glSecondaryColor3bv
#define glSecondaryColor3d mgl_glSecondaryColor3d
#define glSecondaryColor3dv mgl_glSecondaryColor3dv
#define glSecondaryColor3f mgl_glSecondaryColor3f
#define glSecondaryColor3fv mgl_glSecondaryColor3fv
#define glSecondaryColor3i mgl_glSecondaryColor3i
#define glSecondaryColor3iv mgl_glSecondaryColor3iv
#define glSecondaryColor3s mgl_glSecondaryColor3s
#define glSecondaryColor3sv mgl_glSecondaryColor3sv
#define glSecondaryColor3ub mgl_glSecondaryColor3ub
#define glSecondaryColor3ubv mgl_glSecondaryColor3ubv
#define glSecondaryColor3ui mgl_glSecondaryColor3ui
#define glSecondaryColor3uiv mgl_glSecondaryColor3uiv
#define glSecondaryColor3us mgl_glSecondaryColor3us
#define glSecondaryColor3usv mgl_glSecondaryColor3usv
#define glSecondaryColorPointer mgl_glSecondaryColorPointer
#define glWindowPos2d mgl_glWindowPos2d
#define glWindowPos2dv mgl_glWindowPos2dv
#define glWindowPos2f mgl_glWindowPos2f
#define glWindowPos2fv mgl_glWindowPos2fv
#define glWindowPos2i mgl_glWindowPos2i
#define glWindowPos2iv mgl_glWindowPos2iv
#define glWindowPos2s mgl_glWindowPos2s
#define glWindowPos2sv mgl_glWindowPos2sv
#define glWindowPos3d mgl_glWindowPos3d
#define glWindowPos3dv mgl_glWindowPos3dv
#define glWindowPos3f mgl_glWindowPos3f
#define glWindowPos3fv mgl_glWindowPos3fv
#define glWindowPos3i mgl_glWindowPos3i
#define glWindowPos3iv mgl_glWindowPos3iv
#define glWindowPos3s mgl_glWindowPos3s
#define glWindowPos3sv mgl_glWindowPos3sv
#define glBlendColor mgl_glBlendColor
#define glBlendEquation mgl_glBlendEquation
#define glGenQueries mgl_glGenQueries
#define glDeleteQueries mgl_glDeleteQueries
#define glIsQuery mgl_glIsQuery
#define glBeginQuery mgl_glBeginQuery
#define glEndQuery mgl_glEndQuery
#define glGetQueryiv mgl_glGetQueryiv
#define glGetQueryObjectiv mgl_glGetQueryObjectiv
#define glGetQueryObjectuiv mgl_glGetQueryObjectuiv
#define glBindBuffer mgl_glBindBuffer
#define glDeleteBuffers mgl_glDeleteBuffers
#define glGenBuffers mgl_glGenBuffers
#define glIsBuffer mgl_glIsBuffer
#define glBufferData mgl_glBufferData
#define glBufferSubData mgl_glBufferSubData
#define glGetBufferSubData mgl_glGetBufferSubData
#define glMapBuffer mgl_glMapBuffer
#define glUnmapBuffer mgl_glUnmapBuffer
#define glGetBufferParameteriv mgl_glGetBufferParameteriv
#define glGetBufferPointerv mgl_glGetBufferPointerv
#define glBlendEquationSeparate mgl_glBlendEquationSeparate
#define glDrawBuffers mgl_glDrawBuffers
#define glStencilOpSeparate mgl_glStencilOpSeparate
#define glStencilFuncSeparate mgl_glStencilFuncSeparate
#define glStencilMaskSeparate mgl_glStencilMaskSeparate
#define glAttachShader mgl_glAttachShader
#define glBindAttribLocation mgl_glBindAttribLocation
#define glCompileShader mgl_glCompileShader
#define glCreateProgram mgl_glCreateProgram
#define glCreateShader mgl_glCreateShader
#define glDeleteProgram mgl_glDeleteProgram
#define glDeleteShader mgl_glDeleteShader
#define glDetachShader mgl_glDetachShader
#define glDisableVertexAttribArray mgl_glDisableVertexAttribArray
#define glEnableVertexAttribArray mgl_glEnableVertexAttribArray
#define glGetActiveAttrib mgl_glGetActiveAttrib
#define glGetActiveUniform mgl_glGetActiveUniform
#define glGetAttachedShaders mgl_glGetAttachedShaders
#define glGetAttribLocation mgl_glGetAttribLocation
#define glGetProgramiv mgl_glGetProgramiv
#define glGetProgramInfoLog mgl_glGetProgramInfoLog
#define glGetShaderiv mgl_glGetShaderiv
#define glGetShaderInfoLog mgl_glGetShaderInfoLog
#define glGetShaderSource mgl_glGetShaderSource
#define glGetUniformLocation mgl_glGetUniformLocation
#define glGetUniformfv mgl_glGetUniformfv
#define glGetUniformiv mgl_glGetUniformiv
#define glGetVertexAttribdv mgl_glGetVertexAttribdv
#define glGetVertexAttribfv mgl_glGetVertexAttribfv
#define glGetVertexAttribiv mgl_glGetVertexAttribiv
#define glGetVertexAttribPointerv mgl_glGetVertexAttribPointerv
#define glIsProgram mgl_glIsProgram
#define glIsShader mgl_glIsShader
#define glLinkProgram mgl_glLinkProgram
#define glShaderSource mgl_glShaderSource
#define glUseProgram mgl_glUseProgram
#define glUniform1f mgl_glUniform1f
#define glUniform2f mgl_glUniform2f
#define glUniform3f mgl_glUniform3f
#define glUniform4f mgl_glUniform4f
#define glUniform1i mgl_glUniform1i
#define glUniform2i mgl_glUniform2i
#define glUniform3i mgl_glUniform3i
#define glUniform4i mgl_glUniform4i
#define glUniform1fv mgl_glUniform1fv
#define glUniform2fv mgl_glUniform2fv
#define glUniform3fv mgl_glUniform3fv
#define glUniform4fv mgl_glUniform4fv
#define glUniform1iv mgl_glUniform1iv
#define glUniform2iv mgl_glUniform2iv
#define glUniform3iv mgl_glUniform3iv
#define glUniform4iv mgl_glUniform4iv
#define glUniformMatrix2fv mgl_glUniformMatrix2fv
#define glUniformMatrix3fv mgl_glUniformMatrix3fv
#define glUniformMatrix4fv mgl_glUniformMatrix4fv
#define glValidateProgram mgl_glValidateProgram
#define glVertexAttrib1d mgl_glVertexAttrib1d
#define glVertexAttrib1dv mgl_glVertexAttrib1dv
#define glVertexAttrib1f mgl_glVertexAttrib1f
#define glVertexAttrib1fv mgl_glVertexAttrib1fv
#define glVertexAttrib1s mgl_glVertexAttrib1s
#define glVertexAttrib1sv mgl_glVertexAttrib1sv
#define glVertexAttrib2d mgl_glVertexAttrib2d
#define glVertexAttrib2dv mgl_glVertexAttrib2dv
#define glVertexAttrib2f mgl_glVertexAttrib2f
#define glVertexAttrib2fv mgl_glVertexAttrib2fv
#define glVertexAttrib2s mgl_glVertexAttrib2s
#define glVertexAttrib2sv mgl_glVertexAttrib2sv
#define glVertexAttrib3d mgl_glVertexAttrib3d
#define glVertexAttrib3dv mgl_glVertexAttrib3dv
#define glVertexAttrib3f mgl_glVertexAttrib3f
#define glVertexAttrib3fv mgl_glVertexAttrib3fv
#define glVertexAttrib3s mgl_glVertexAttrib3s
#define glVertexAttrib3sv mgl_glVertexAttrib3sv
#define glVertexAttrib4Nbv mgl_glVertexAttrib4Nbv
#define glVertexAttrib4Niv mgl_glVertexAttrib4Niv
#define glVertexAttrib4Nsv mgl_glVertexAttrib4Nsv
#define glVertexAttrib4Nub mgl_glVertexAttrib4Nub
#define glVertexAttrib4Nubv mgl_glVertexAttrib4Nubv
#define glVertexAttrib4Nuiv mgl_glVertexAttrib4Nuiv
#define glVertexAttrib4Nusv mgl_glVertexAttrib4Nusv
#define glVertexAttrib4bv mgl_glVertexAttrib4bv
#define glVertexAttrib4d mgl_glVertexAttrib4d
#define glVertexAttrib4dv mgl_glVertexAttrib4dv
#define glVertexAttrib4f mgl_glVertexAttrib4f
#define glVertexAttrib4fv mgl_glVertexAttrib4fv
#define glVertexAttrib4iv mgl_glVertexAttrib4iv
#define glVertexAttrib4s mgl_glVertexAttrib4s
#define glVertexAttrib4sv mgl_glVertexAttrib4sv
#define glVertexAttrib4ubv mgl_glVertexAttrib4ubv
#define glVertexAttrib4uiv mgl_glVertexAttrib4uiv
#define glVertexAttrib4usv mgl_glVertexAttrib4usv
#define glVertexAttribPointer mgl_glVertexAttribPointer
#define glUniformMatrix2x3fv mgl_glUniformMatrix2x3fv
#define glUniformMatrix3x2fv mgl_glUniformMatrix3x2fv
#define glUniformMatrix2x4fv mgl_glUniformMatrix2x4fv
#define glUniformMatrix4x2fv mgl_glUniformMatrix4x2fv
#define glUniformMatrix3x4fv mgl_glUniformMatrix3x4fv
#define glUniformMatrix4x3fv mgl_glUniformMatrix4x3fv
#define glColorMaski mgl_glColorMaski
#define glGetBooleani_v mgl_glGetBooleani_v
#define glGetIntegeri_v mgl_glGetIntegeri_v
#define glEnablei mgl_glEnablei
#define glDisablei mgl_glDisablei
#define glIsEnabledi mgl_glIsEnabledi
#define glBeginTransformFeedback mgl_glBeginTransformFeedback
#define glEndTransformFeedback mgl_glEndTransformFeedback
#define glBindBufferRange mgl_glBindBufferRange
#define glBindBufferBase mgl_glBindBufferBase
#define glTransformFeedbackVaryings mgl_glTransformFeedbackVaryings
#define glGetTransformFeedbackVarying mgl_glGetTransformFeedbackVarying
#define glClampColor mgl_glClampColor
#define glBeginConditionalRender mgl_glBeginConditionalRender
#define glEndConditionalRender mgl_glEndConditionalRender
#define glVertexAttribIPointer mgl_glVertexAttribIPointer
#define glGetVertexAttribIiv mgl_glGetVertexAttribIiv
#define glGetVertexAttribIuiv mgl_glGetVertexAttribIuiv
#define glVertexAttribI1i mgl_glVertexAttribI1i
#define glVertexAttribI2i mgl_glVertexAttribI2i
#define glVertexAttribI3i mgl_glVertexAttribI3i
#define glVertexAttribI4i mgl_glVertexAttribI4i
#define glVertexAttribI1ui mgl_glVertexAttribI1ui
#define glVertexAttribI2ui mgl_glVertexAttribI2ui
#define glVertexAttribI3ui mgl_glVertexAttribI3ui
#define glVertexAttribI4ui mgl_glVertexAttribI4ui
#define glVertexAttribI1iv mgl_glVertexAttribI1iv
#define glVertexAttribI2iv mgl_glVertexAttribI2iv
#define glVertexAttribI3iv mgl_glVertexAttribI3iv
#define glVertexAttribI4iv mgl_glVertexAttribI4iv
#define glVertexAttribI1uiv mgl_glVertexAttribI1uiv
#define glVertexAttribI2uiv mgl_glVertexAttribI2uiv
#define glVertexAttribI3uiv mgl_glVertexAttribI3uiv
#define glVertexAttribI4uiv mgl_glVertexAttribI4uiv
#define glVertexAttribI4bv mgl_glVertexAttribI4bv
#define glVertexAttribI4sv mgl_glVertexAttribI4sv
#define glVertexAttribI4ubv mgl_glVertexAttribI4ubv
#define glVertexAttribI4usv mgl_glVertexAttribI4usv
#define glGetUniformuiv mgl_glGetUniformuiv
#define glBindFragDataLocation mgl_glBindFragDataLocation
#define glGetFragDataLocation mgl_glGetFragDataLocation
#define glUniform1ui mgl_glUniform1ui
#define glUniform2ui mgl_glUniform2ui
#define glUniform3ui mgl_glUniform3ui
#define glUniform4ui mgl_glUniform4ui
#define glUniform1uiv mgl_glUniform1uiv
#define glUniform2uiv mgl_glUniform2uiv
#define glUniform3uiv mgl_glUniform3uiv
#define glUniform4uiv mgl_glUniform4uiv
#define glTexParameterIiv mgl_glTexParameterIiv
#define glTexParameterIuiv mgl_glTexParameterIuiv
#define glGetTexParameterIiv mgl_glGetTexParameterIiv
#define glGetTexParameterIuiv mgl_glGetTexParameterIuiv
#define glClearBufferiv mgl_glClearBufferiv
#define glClearBufferuiv mgl_glClearBufferuiv
#define glClearBufferfv mgl_glClearBufferfv
#define glClearBufferfi mgl_glClearBufferfi
#define glGetStringi mgl_glGetStringi
#define glIsRenderbuffer mgl_glIsRenderbuffer
#define glBindRenderbuffer mgl_glBindRenderbuffer
#define glDeleteRenderbuffers mgl_glDeleteRenderbuffers
#define glGenRenderbuffers mgl_glGenRenderbuffers
#define glRenderbufferStorage mgl_glRenderbufferStorage
#define glGetRenderbufferParameteriv mgl_glGetRenderbufferParameteriv
#define glIsFramebuffer mgl_glIsFramebuffer
#define glBindFramebuffer mgl_glBindFramebuffer
#define glDeleteFramebuffers mgl_glDeleteFramebuffers
#define glGenFramebuffers mgl_glGenFramebuffers
#define glCheckFramebufferStatus mgl_glCheckFramebufferStatus
#define glFramebufferTexture1D mgl_glFramebufferTexture1D
#define glFramebufferTexture2D mgl_glFramebufferTexture2D
#define glFramebufferTexture3D mgl_glFramebufferTexture3D
#define glFramebufferRenderbuffer mgl_glFramebufferRenderbuffer
#define glGetFramebufferAttachmentParameteriv mgl_glGetFramebufferAttachmentParameteriv
#define glGenerateMipmap mgl_glGenerateMipmap
#define glBlitFramebuffer mgl_glBlitFramebuffer
#define glRenderbufferStorageMultisample mgl_glRenderbufferStorageMultisample
#define glFramebufferTextureLayer mgl_glFramebufferTextureLayer
#define glMapBufferRange mgl_glMapBufferRange
#define glFlushMappedBufferRange mgl_glFlushMappedBufferRange
#define glBindVertexArray mgl_glBindVertexArray
#define glDeleteVertexArrays mgl_glDeleteVertexArrays
#define glGenVertexArrays mgl_glGenVertexArrays
#define glIsVertexArray mgl_glIsVertexArray
#define glDrawArraysInstanced mgl_glDrawArraysInstanced
#define glDrawElementsInstanced mgl_glDrawElementsInstanced
#define glTexBuffer mgl_glTexBuffer
#define glPrimitiveRestartIndex mgl_glPrimitiveRestartIndex
#define glCopyBufferSubData mgl_glCopyBufferSubData
#define glGetUniformIndices mgl_glGetUniformIndices
#define glGetActiveUniformsiv mgl_glGetActiveUniformsiv
#define glGetActiveUniformName mgl_glGetActiveUniformName
#define glGetUniformBlockIndex mgl_glGetUniformBlockIndex
#define glGetActiveUniformBlockiv mgl_glGetActiveUniformBlockiv
#define glGetActiveUniformBlockName mgl_glGetActiveUniformBlockName
#define glUniformBlockBinding mgl_glUniformBlockBinding
#define glDrawElementsBaseVertex mgl_glDrawElementsBaseVertex
#define glDrawRangeElementsBaseVertex mgl_glDrawRangeElementsBaseVertex
#define glDrawElementsInstancedBaseVertex mgl_glDrawElementsInstancedBaseVertex
#define glMultiDrawElementsBaseVertex mgl_glMultiDrawElementsBaseVertex
#define glProvokingVertex mgl_glProvokingVertex
#define glFenceSync mgl_glFenceSync
#define glIsSync mgl_glIsSync
#define glDeleteSync mgl_glDeleteSync
#define glClientWaitSync mgl_glClientWaitSync
#define glWaitSync mgl_glWaitSync
#define glGetInteger64v mgl_glGetInteger64v
#define glGetSynciv mgl_glGetSynciv
#define glGetInteger64i_v mgl_glGetInteger64i_v
#define glGetBufferParameteri64v mgl_glGetBufferParameteri64v
#define glFramebufferTexture mgl_glFramebufferTexture
#define glTexImage2DMultisample mgl_glTexImage2DMultisample
#define glTexImage3DMultisample mgl_glTexImage3DMultisample
#define glGetMultisamplefv mgl_glGetMultisamplefv
#define glSampleMaski mgl_glSampleMaski
#define glBindFragDataLocationIndexed mgl_glBindFragDataLocationIndexed
#define glGetFragDataIndex mgl_glGetFragDataIndex
#define glGenSamplers mgl_glGenSamplers
#define glDeleteSamplers mgl_glDeleteSamplers
#define glIsSampler mgl_glIsSampler
#define glBindSampler mgl_glBindSampler
#define glSamplerParameteri mgl_glSamplerParameteri
#define glSamplerParameteriv mgl_glSamplerParameteriv
#define glSamplerParameterf mgl_glSamplerParameterf
#define glSamplerParameterfv mgl_glSamplerParameterfv
#define glSamplerParameterIiv mgl_glSamplerParameterIiv
#define glSamplerParameterIuiv mgl_glSamplerParameterIuiv
#define glGetSamplerParameteriv mgl_glGetSamplerParameteriv
#define glGetSamplerParameterIiv mgl_glGetSamplerParameterIiv
#define glGetSamplerParameterfv mgl_glGetSamplerParameterfv
#define glGetSamplerParameterIuiv mgl_glGetSamplerParameterIuiv
#define glQueryCounter mgl_glQueryCounter
#define glGetQueryObjecti64v mgl_glGetQueryObjecti64v
#define glGetQueryObjectui64v mgl_glGetQueryObjectui64v
#define glVertexAttribDivisor mgl_glVertexAttribDivisor
#define glVertexAttribP1ui mgl_glVertexAttribP1ui
#define glVertexAttribP1uiv mgl_glVertexAttribP1uiv
#define glVertexAttribP2ui mgl_glVertexAttribP2ui
#define glVertexAttribP2uiv mgl_glVertexAttribP2uiv
#define glVertexAttribP3ui mgl_glVertexAttribP3ui
#define glVertexAttribP3uiv mgl_glVertexAttribP3uiv
#define glVertexAttribP4ui mgl_glVertexAttribP4ui
#define glVertexAttribP4uiv mgl_glVertexAttribP4uiv
#define glMinSampleShading mgl_glMinSampleShading
#define glBlendEquationi mgl_glBlendEquationi
#define glBlendEquationSeparatei mgl_glBlendEquationSeparatei
#define glBlendFunci mgl_glBlendFunci
#define glBlendFuncSeparatei mgl_glBlendFuncSeparatei
#define glDrawArraysIndirect mgl_glDrawArraysIndirect
#define glDrawElementsIndirect mgl_glDrawElementsIndirect
#define glUniform1d mgl_glUniform1d
#define glUniform2d mgl_glUniform2d
#define glUniform3d mgl_glUniform3d
#define glUniform4d mgl_glUniform4d
#define glUniform1dv mgl_glUniform1dv
#define glUniform2dv mgl_glUniform2dv
#define glUniform3dv mgl_glUniform3dv
#define glUniform4dv mgl_glUniform4dv
#define glUniformMatrix2dv mgl_glUniformMatrix2dv
#define glUniformMatrix3dv mgl_glUniformMatrix3dv
#define glUniformMatrix4dv mgl_glUniformMatrix4dv
#define glUniformMatrix2x3dv mgl_glUniformMatrix2x3dv
#define glUniformMatrix2x4dv mgl_glUniformMatrix2x4dv
#define glUniformMatrix3x2dv mgl_glUniformMatrix3x2dv
#define glUniformMatrix3x4dv mgl_glUniformMatrix3x4dv
#define glUniformMatrix4x2dv mgl_glUniformMatrix4x2dv
#define glUniformMatrix4x3dv mgl_glUniformMatrix4x3dv
#define glGetUniformdv mgl_glGetUniformdv
#define glGetSubroutineUniformLocation mgl_glGetSubroutineUniformLocation
#define glGetSubroutineIndex mgl_glGetSubroutineIndex
#define glGetActiveSubroutineUniformiv mgl_glGetActiveSubroutineUniformiv
#define glGetActiveSubroutineUniformName mgl_glGetActiveSubroutineUniformName
#define glGetActiveSubroutineName mgl_glGetActiveSubroutineName
#define glUniformSubroutinesuiv mgl_glUniformSubroutinesuiv
#define glGetUniformSubroutineuiv mgl_glGetUniformSubroutineuiv
#define glGetProgramStageiv mgl_glGetProgramStageiv
#define glPatchParameteri mgl_glPatchParameteri
#define glPatchParameterfv mgl_glPatchParameterfv
#define glBindTransformFeedback mgl_glBindTransformFeedback
#define glDeleteTransformFeedbacks mgl_glDeleteTransformFeedbacks
#define glGenTransformFeedbacks mgl_glGenTransformFeedbacks
#define glIsTransformFeedback mgl_glIsTransformFeedback
#define glPauseTransformFeedback mgl_glPauseTransformFeedback
#define glResumeTransformFeedback mgl_glResumeTransformFeedback
#define glDrawTransformFeedback mgl_glDrawTransformFeedback
#define glDrawTransformFeedbackStream mgl_glDrawTransformFeedbackStream
#define glBeginQueryIndexed mgl_glBeginQueryIndexed
#define glEndQueryIndexed mgl_glEndQueryIndexed
#define glGetQueryIndexediv mgl_glGetQueryIndexediv
#define glReleaseShaderCompiler mgl_glReleaseShaderCompiler
#define glShaderBinary mgl_glShaderBinary
#define glGetShaderPrecisionFormat mgl_glGetShaderPrecisionFormat
#define glDepthRangef mgl_glDepthRangef
#define glClearDepthf mgl_glClearDepthf
#define glGetProgramBinary mgl_glGetProgramBinary
#define glProgramBinary mgl_glProgramBinary
#define glProgramParameteri mgl_glProgramParameteri
#define glUseProgramStages mgl_glUseProgramStages
#define glActiveShaderProgram mgl_glActiveShaderProgram
#define glCreateShaderProgramv mgl_glCreateShaderProgramv
#define glBindProgramPipeline mgl_glBindProgramPipeline
#define glDeleteProgramPipelines mgl_glDeleteProgramPipelines
#define glGenProgramPipelines mgl_glGenProgramPipelines
#define glIsProgramPipeline mgl_glIsProgramPipeline
#define glGetProgramPipelineiv mgl_glGetProgramPipelineiv
#define glProgramUniform1i mgl_glProgramUniform1i
#define glProgramUniform1iv mgl_glProgramUniform1iv
#define glProgramUniform1f mgl_glProgramUniform1f
#define glProgramUniform1fv mgl_glProgramUniform1fv
#define glProgramUniform1d mgl_glProgramUniform1d
#define glProgramUniform1dv mgl_glProgramUniform1dv
#define glProgramUniform1ui mgl_glProgramUniform1ui
#define glProgramUniform1uiv mgl_glProgramUniform1uiv
#define glProgramUniform2i mgl_glProgramUniform2i
#define glProgramUniform2iv mgl_glProgramUniform2iv
#define glProgramUniform2f mgl_glProgramUniform2f
#define glProgramUniform2fv mgl_glProgramUniform2fv
#define glProgramUniform2d mgl_glProgramUniform2d
#define glProgramUniform2dv mgl_glProgramUniform2dv
#define glProgramUniform2ui mgl_glProgramUniform2ui
#define glProgramUniform2uiv mgl_glProgramUniform2uiv
#define glProgramUniform3i mgl_glProgramUniform3i
#define glProgramUniform3iv mgl_glProgramUniform3iv
#define glProgramUniform3f mgl_glProgramUniform3f
#define glProgramUniform3fv mgl_glProgramUniform3fv
#define glProgramUniform3d mgl_glProgramUniform3d
#define glProgramUniform3dv mgl_glProgramUniform3dv
#define glProgramUniform3ui mgl_glProgramUniform3ui
#define glProgramUniform3uiv mgl_glProgramUniform3uiv
#define glProgramUniform4i mgl_glProgramUniform4i
#define glProgramUniform4iv mgl_glProgramUniform4iv
#define glProgramUniform4f mgl_glProgramUniform4f
#define glProgramUniform4fv mgl_glProgramUniform4fv
#define glProgramUniform4d mgl_glProgramUniform4d
#define glProgramUniform4dv mgl_glProgramUniform4dv
#define glProgramUniform4ui mgl_glProgramUniform4ui
#define glProgramUniform4uiv mgl_glProgramUniform4uiv
#define glProgramUniformMatrix2fv mgl_glProgramUniformMatrix2fv
#define glProgramUniformMatrix3fv mgl_glProgramUniformMatrix3fv
#define glProgramUniformMatrix4fv mgl_glProgramUniformMatrix4fv
#define glProgramUniformMatrix2dv mgl_glProgramUniformMatrix2dv
#define glProgramUniformMatrix3dv mgl_glProgramUniformMatrix3dv
#define glProgramUniformMatrix4dv mgl_glProgramUniformMatrix4dv
#define glProgramUniformMatrix2x3fv mgl_glProgramUniformMatrix2x3fv
#define glProgramUniformMatrix3x2fv mgl_glProgramUniformMatrix3x2fv
#define glProgramUniformMatrix2x4fv mgl_glProgramUniformMatrix2x4fv
#define glProgramUniformMatrix4x2fv mgl_glProgramUniformMatrix4x2fv
#define glProgramUniformMatrix3x4fv mgl_glProgramUniformMatrix3x4fv
#define glProgramUniformMatrix4x3fv mgl_glProgramUniformMatrix4x3fv
#define glProgramUniformMatrix2x3dv mgl_glProgramUniformMatrix2x3dv
#define glProgramUniformMatrix3x2dv mgl_glProgramUniformMatrix3x2dv
#define glProgramUniformMatrix2x4dv mgl_glProgramUniformMatrix2x4dv
#define glProgramUniformMatrix4x2dv mgl_glProgramUniformMatrix4x2dv
#define glProgramUniformMatrix3x4dv mgl_glProgramUniformMatrix3x4dv
#define glProgramUniformMatrix4x3dv mgl_glProgramUniformMatrix4x3dv
#define glValidateProgramPipeline mgl_glValidateProgramPipeline
#define glGetProgramPipelineInfoLog mgl_glGetProgramPipelineInfoLog
#define glVertexAttribL1d mgl_glVertexAttribL1d
#define glVertexAttribL2d mgl_glVertexAttribL2d
#define glVertexAttribL3d mgl_glVertexAttribL3d
#define glVertexAttribL4d mgl_glVertexAttribL4d
#define glVertexAttribL1dv mgl_glVertexAttribL1dv
#define glVertexAttribL2dv mgl_glVertexAttribL2dv
#define glVertexAttribL3dv mgl_glVertexAttribL3dv
#define glVertexAttribL4dv mgl_glVertexAttribL4dv
#define glVertexAttribLPointer mgl_glVertexAttribLPointer
#define glGetVertexAttribLdv mgl_glGetVertexAttribLdv
#define glViewportArrayv mgl_glViewportArrayv
#define glViewportIndexedf mgl_glViewportIndexedf
#define glViewportIndexedfv mgl_glViewportIndexedfv
#define glScissorArrayv mgl_glScissorArrayv
#define glScissorIndexed mgl_glScissorIndexed
#define glScissorIndexedv mgl_glScissorIndexedv
#define glDepthRangeArrayv mgl_glDepthRangeArrayv
#define glDepthRangeIndexed mgl_glDepthRangeIndexed
#define glGetFloati_v mgl_glGetFloati_v
#define glGetDoublei_v mgl_glGetDoublei_v
#define glDrawArraysInstancedBaseInstance mgl_glDrawArraysInstancedBaseInstance
#define glDrawElementsInstancedBaseInstance mgl_glDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertexBaseInstance mgl_glDrawElementsInstancedBaseVertexBaseInstance
#define glGetInternalformativ mgl_glGetInternalformativ
#define glGetActiveAtomicCounterBufferiv mgl_glGetActiveAtomicCounterBufferiv
#define glBindImageTexture mgl_glBindImageTexture
#define glMemoryBarrier mgl_glMemoryBarrier
#define glTexStorage1D mgl_glTexStorage1D
#define glTexStorage2D mgl_glTexStorage2D
#define glTexStorage3D mgl_glTexStorage3D
#define glDrawTransformFeedbackInstanced mgl_glDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStreamInstanced mgl_glDrawTransformFeedbackStreamInstanced
#define glClearBufferData mgl_glClearBufferData
#define glClearBufferSubData mgl_glClearBufferSubData
#define glDispatchCompute mgl_glDispatchCompute
#define glDispatchComputeIndirect mgl_glDispatchComputeIndirect
#define glCopyImageSubData mgl_glCopyImageSubData
#define glFramebufferParameteri mgl_glFramebufferParameteri
#define glGetFramebufferParameteriv mgl_glGetFramebufferParameteriv
#define glGetInternalformati64v mgl_glGetInternalformati64v
#define glInvalidateTexSubImage mgl_glInvalidateTexSubImage
#define glInvalidateTexImage mgl_glInvalidateTexImage
#define glInvalidateBufferSubData mgl_glInvalidateBufferSubData
#define glInvalidateBufferData mgl_glInvalidateBufferData
#define glInvalidateFramebuffer mgl_glInvalidateFramebuffer
#define glInvalidateSubFramebuffer mgl_glInvalidateSubFramebuffer
#define glMultiDrawArraysIndirect mgl_glMultiDrawArraysIndirect
#define glMultiDrawElementsIndirect mgl_glMultiDrawElementsIndirect
#define glGetProgramInterfaceiv mgl_glGetProgramInterfaceiv
#define glGetProgramResourceIndex mgl_glGetProgramResourceIndex
#define glGetProgramResourceName mgl_glGetProgramResourceName
#define glGetProgramResourceiv mgl_glGetProgramResourceiv
#define glGetProgramResourceLocation mgl_glGetProgramResourceLocation
#define glGetProgramResourceLocationIndex mgl_glGetProgramResourceLocationIndex
#define glShaderStorageBlockBinding mgl_glShaderStorageBlockBinding
#define glTexBufferRange mgl_glTexBufferRange
#define glTexStorage2DMultisample mgl_glTexStorage2DMultisample
#define glTexStorage3DMultisample mgl_glTexStorage3DMultisample
#define glTextureView mgl_glTextureView
#define glBindVertexBuffer mgl_glBindVertexBuffer
#define glVertexAttribFormat mgl_glVertexAttribFormat
#define glVertexAttribIFormat mgl_glVertexAttribIFormat
#define glVertexAttribLFormat mgl_glVertexAttribLFormat
#define glVertexAttribBinding mgl_glVertexAttribBinding
#define glVertexBindingDivisor mgl_glVertexBindingDivisor
#define glDebugMessageControl mgl_glDebugMessageControl
#define glDebugMessageInsert mgl_glDebugMessageInsert
#define glDebugMessageCallback mgl_glDebugMessageCallback
#define glGetDebugMessageLog mgl_glGetDebugMessageLog
#define glPushDebugGroup mgl_glPushDebugGroup
#define glPopDebugGroup mgl_glPopDebugGroup
#define glObjectLabel mgl_glObjectLabel
#define glGetObjectLabel mgl_glGetObjectLabel
#define glObjectPtrLabel mgl_glObjectPtrLabel
#define glGetObjectPtrLabel mgl_glGetObjectPtrLabel
#define glBufferStorage mgl_glBufferStorage
#define glClearTexImage mgl_glClearTexImage
#define glClearTexSubImage mgl_glClearTexSubImage
#define glBindBuffersBase mgl_glBindBuffersBase
#define glBindBuffersRange mgl_glBindBuffersRange
#define glBindTextures mgl_glBindTextures
#define glBindSamplers mgl_glBindSamplers
#define glBindImageTextures mgl_glBindImageTextures
#define glBindVertexBuffers mgl_glBindVertexBuffers
#define glClipControl mgl_glClipControl
#define glCreateTransformFeedbacks mgl_glCreateTransformFeedbacks
#define glTransformFeedbackBufferBase mgl_glTransformFeedbackBufferBase
#define glTransformFeedbackBufferRange mgl_glTransformFeedbackBufferRange
#define glGetTransformFeedbackiv mgl_glGetTransformFeedbackiv
#define glGetTransformFeedbacki_v mgl_glGetTransformFeedbacki_v
#define glGetTransformFeedbacki64_v mgl_glGetTransformFeedbacki64_v
#define glCreateBuffers mgl_glCreateBuffers
#define glNamedBufferStorage mgl_glNamedBufferStorage
#define glNamedBufferData mgl_glNamedBufferData
#define glNamedBufferSubData mgl_glNamedBufferSubData
#define glCopyNamedBufferSubData mgl_glCopyNamedBufferSubData
#define glClearNamedBufferData mgl_glClearNamedBufferData
#define glClearNamedBufferSubData mgl_glClearNamedBufferSubData
#define glMapNamedBuffer mgl_glMapNamedBuffer
#define glMapNamedBufferRange mgl_glMapNamedBufferRange
#define glUnmapNamedBuffer mgl_glUnmapNamedBuffer
#define glFlushMappedNamedBufferRange mgl_glFlushMappedNamedBufferRange
#define glGetNamedBufferParameteriv mgl_glGetNamedBufferParameteriv
#define glGetNamedBufferParameteri64v mgl_glGetNamedBufferParameteri64v
#define glGetNamedBufferPointerv mgl_glGetNamedBufferPointerv
#define glGetNamedBufferSubData mgl_glGetNamedBufferSubData
#define glCreateFramebuffers mgl_glCreateFramebuffers
#define glNamedFramebufferRenderbuffer mgl_glNamedFramebufferRenderbuffer
#define glNamedFramebufferParameteri mgl_glNamedFramebufferParameteri
#define glNamedFramebufferTexture mgl_glNamedFramebufferTexture
#define glNamedFramebufferTextureLayer mgl_glNamedFramebufferTextureLayer
#define glNamedFramebufferDrawBuffer mgl_glNamedFramebufferDrawBuffer
#define glNamedFramebufferDrawBuffers mgl_glNamedFramebufferDrawBuffers
#define glNamedFramebufferReadBuffer mgl_glNamedFramebufferReadBuffer
#define glInvalidateNamedFramebufferData mgl_glInvalidateNamedFramebufferData
#define glInvalidateNamedFramebufferSubData mgl_glInvalidateNamedFramebufferSubData
#define glClearNamedFramebufferiv mgl_glClearNamedFramebufferiv
#define glClearNamedFramebufferuiv mgl_glClearNamedFramebufferuiv
#define glClearNamedFramebufferfv mgl_glClearNamedFramebufferfv
#define glClearNamedFramebufferfi mgl_glClearNamedFramebufferfi
#define glBlitNamedFramebuffer mgl_glBlitNamedFramebuffer
#define glCheckNamedFramebufferStatus mgl_glCheckNamedFramebufferStatus
#define glGetNamedFramebufferParameteriv mgl_glGetNamedFramebufferParameteriv
#define glGetNamedFramebufferAttachmentParameteriv mgl_glGetNamedFramebufferAttachmentParameteriv
#define glCreateRenderbuffers mgl_glCreateRenderbuffers
#define glNamedRenderbufferStorage mgl_glNamedRenderbufferStorage
#define glNamedRenderbufferStorageMultisample mgl_glNamedRenderbufferStorageMultisample
#define glGetNamedRenderbufferParameteriv mgl_glGetNamedRenderbufferParameteriv
#define glCreateTextures mgl_glCreateTextures
#define glTextureBuffer mgl_glTextureBuffer
#define glTextureBufferRange mgl_glTextureBufferRange
#define glTextureStorage1D mgl_glTextureStorage1D
#define glTextureStorage2D mgl_glTextureStorage2D
#define glTextureStorage3D mgl_glTextureStorage3D
#define glTextureStorage2DMultisample mgl_glTextureStorage2DMultisample
#define glTextureStorage3DMultisample mgl_glTextureStorage3DMultisample
#define glTextureSubImage1D mgl_glTextureSubImage1D
#define glTextureSubImage2D mgl_glTextureSubImage2D
#define glTextureSubImage3D mgl_glTextureSubImage3D
#define glCompressedTextureSubImage1D mgl_glCompressedTextureSubImage1D
#define glCompressedTextureSubImage2D mgl_glCompressedTextureSubImage2D
#define glCompressedTextureSubImage3D mgl_glCompressedTextureSubImage3D
#define glCopyTextureSubImage1D mgl_glCopyTextureSubImage1D
#define glCopyTextureSubImage2D mgl_glCopyTextureSubImage2D
#define glCopyTextureSubImage3D mgl_glCopyTextureSubImage3D
#define glTextureParameterf mgl_glTextureParameterf
#define glTextureParameterfv mgl_glTextureParameterfv
#define glTextureParameteri mgl_glTextureParameteri
#define glTextureParameterIiv mgl_glTextureParameterIiv
#define glTextureParameterIuiv mgl_glTextureParameterIuiv
#define glTextureParameteriv mgl_glTextureParameteriv
#define glGenerateTextureMipmap mgl_glGenerateTextureMipmap
#define glBindTextureUnit mgl_glBindTextureUnit
#define glGetTextureImage mgl_glGetTextureImage
#define glGetCompressedTextureImage mgl_glGetCompressedTextureImage
#define glGetTextureLevelParameterfv mgl_glGetTextureLevelParameterfv
#define glGetTextureLevelParameteriv mgl_glGetTextureLevelParameteriv
#define glGetTextureParameterfv mgl_glGetTextureParameterfv
#define glGetTextureParameterIiv mgl_glGetTextureParameterIiv
#define glGetTextureParameterIuiv mgl_glGetTextureParameterIuiv
#define glGetTextureParameteriv mgl_glGetTextureParameteriv
#define glCreateVertexArrays mgl_glCreateVertexArrays
#define glDisableVertexArrayAttrib mgl_glDisableVertexArrayAttrib
#define glEnableVertexArrayAttrib mgl_glEnableVertexArrayAttrib
#define glVertexArrayElementBuffer mgl_glVertexArrayElementBuffer
#define glVertexArrayVertexBuffer mgl_glVertexArrayVertexBuffer
#define glVertexArrayVertexBuffers mgl_glVertexArrayVertexBuffers
#define glVertexArrayAttribBinding mgl_glVertexArrayAttribBinding
#define glVertexArrayAttribFormat mgl_glVertexArrayAttribFormat
#define glVertexArrayAttribIFormat mgl_glVertexArrayAttribIFormat
#define glVertexArrayAttribLFormat mgl_glVertexArrayAttribLFormat
#define glVertexArrayBindingDivisor mgl_glVertexArrayBindingDivisor
#define glGetVertexArrayiv mgl_glGetVertexArrayiv
#define glGetVertexArrayIndexediv mgl_glGetVertexArrayIndexediv
#define glGetVertexArrayIndexed64iv mgl_glGetVertexArrayIndexed64iv
#define glCreateSamplers mgl_glCreateSamplers
#define glCreateProgramPipelines mgl_glCreateProgramPipelines
#define glCreateQueries mgl_glCreateQueries
#define glGetQueryBufferObjecti64v mgl_glGetQueryBufferObjecti64v
#define glGetQueryBufferObjectiv mgl_glGetQueryBufferObjectiv
#define glGetQueryBufferObjectui64v mgl_glGetQueryBufferObjectui64v
#define glGetQueryBufferObjectuiv mgl_glGetQueryBufferObjectuiv
#define glMemoryBarrierByRegion mgl_glMemoryBarrierByRegion
#define glGetTextureSubImage mgl_glGetTextureSubImage
#define glGetCompressedTextureSubImage mgl_glGetCompressedTextureSubImage
#define glGetGraphicsResetStatus mgl_glGetGraphicsResetStatus
#define glGetnCompressedTexImage mgl_glGetnCompressedTexImage
#define glGetnTexImage mgl_glGetnTexImage
#define glGetnUniformdv mgl_glGetnUniformdv
#define glGetnUniformfv mgl_glGetnUniformfv
#define glGetnUniformiv mgl_glGetnUniformiv
#define glGetnUniformuiv mgl_glGetnUniformuiv
#define glReadnPixels mgl_glReadnPixels
#define glTextureBarrier mgl_glTextureBarrier
#define glSpecializeShader mgl_glSpecializeShader
#define glMultiDrawArraysIndirectCount mgl_glMultiDrawArraysIndirectCount
#define glMultiDrawElementsIndirectCount mgl_glMultiDrawElementsIndirectCount
#define glPolygonOffsetClamp mgl_glPolygonOffsetClamp

GLAPI const char* mglErrorString(GLenum error);

#ifdef MGL_IMPLEMENTATION

GLAPI mgl_glCullFace_t mgl_glCullFace = NULL;
GLAPI mgl_glFrontFace_t mgl_glFrontFace = NULL;
GLAPI mgl_glHint_t mgl_glHint = NULL;
GLAPI mgl_glLineWidth_t mgl_glLineWidth = NULL;
GLAPI mgl_glPointSize_t mgl_glPointSize = NULL;
GLAPI mgl_glPolygonMode_t mgl_glPolygonMode = NULL;
GLAPI mgl_glScissor_t mgl_glScissor = NULL;
GLAPI mgl_glTexParameterf_t mgl_glTexParameterf = NULL;
GLAPI mgl_glTexParameterfv_t mgl_glTexParameterfv = NULL;
GLAPI mgl_glTexParameteri_t mgl_glTexParameteri = NULL;
GLAPI mgl_glTexParameteriv_t mgl_glTexParameteriv = NULL;
GLAPI mgl_glTexImage1D_t mgl_glTexImage1D = NULL;
GLAPI mgl_glTexImage2D_t mgl_glTexImage2D = NULL;
GLAPI mgl_glDrawBuffer_t mgl_glDrawBuffer = NULL;
GLAPI mgl_glClear_t mgl_glClear = NULL;
GLAPI mgl_glClearColor_t mgl_glClearColor = NULL;
GLAPI mgl_glClearStencil_t mgl_glClearStencil = NULL;
GLAPI mgl_glClearDepth_t mgl_glClearDepth = NULL;
GLAPI mgl_glStencilMask_t mgl_glStencilMask = NULL;
GLAPI mgl_glColorMask_t mgl_glColorMask = NULL;
GLAPI mgl_glDepthMask_t mgl_glDepthMask = NULL;
GLAPI mgl_glDisable_t mgl_glDisable = NULL;
GLAPI mgl_glEnable_t mgl_glEnable = NULL;
GLAPI mgl_glFinish_t mgl_glFinish = NULL;
GLAPI mgl_glFlush_t mgl_glFlush = NULL;
GLAPI mgl_glBlendFunc_t mgl_glBlendFunc = NULL;
GLAPI mgl_glLogicOp_t mgl_glLogicOp = NULL;
GLAPI mgl_glStencilFunc_t mgl_glStencilFunc = NULL;
GLAPI mgl_glStencilOp_t mgl_glStencilOp = NULL;
GLAPI mgl_glDepthFunc_t mgl_glDepthFunc = NULL;
GLAPI mgl_glPixelStoref_t mgl_glPixelStoref = NULL;
GLAPI mgl_glPixelStorei_t mgl_glPixelStorei = NULL;
GLAPI mgl_glReadBuffer_t mgl_glReadBuffer = NULL;
GLAPI mgl_glReadPixels_t mgl_glReadPixels = NULL;
GLAPI mgl_glGetBooleanv_t mgl_glGetBooleanv = NULL;
GLAPI mgl_glGetDoublev_t mgl_glGetDoublev = NULL;
GLAPI mgl_glGetError_t mgl_glGetError = NULL;
GLAPI mgl_glGetFloatv_t mgl_glGetFloatv = NULL;
GLAPI mgl_glGetIntegerv_t mgl_glGetIntegerv = NULL;
GLAPI mgl_glGetString_t mgl_glGetString = NULL;
GLAPI mgl_glGetTexImage_t mgl_glGetTexImage = NULL;
GLAPI mgl_glGetTexParameterfv_t mgl_glGetTexParameterfv = NULL;
GLAPI mgl_glGetTexParameteriv_t mgl_glGetTexParameteriv = NULL;
GLAPI mgl_glGetTexLevelParameterfv_t mgl_glGetTexLevelParameterfv = NULL;
GLAPI mgl_glGetTexLevelParameteriv_t mgl_glGetTexLevelParameteriv = NULL;
GLAPI mgl_glIsEnabled_t mgl_glIsEnabled = NULL;
GLAPI mgl_glDepthRange_t mgl_glDepthRange = NULL;
GLAPI mgl_glViewport_t mgl_glViewport = NULL;
GLAPI mgl_glNewList_t mgl_glNewList = NULL;
GLAPI mgl_glEndList_t mgl_glEndList = NULL;
GLAPI mgl_glCallList_t mgl_glCallList = NULL;
GLAPI mgl_glCallLists_t mgl_glCallLists = NULL;
GLAPI mgl_glDeleteLists_t mgl_glDeleteLists = NULL;
GLAPI mgl_glGenLists_t mgl_glGenLists = NULL;
GLAPI mgl_glListBase_t mgl_glListBase = NULL;
GLAPI mgl_glBegin_t mgl_glBegin = NULL;
GLAPI mgl_glBitmap_t mgl_glBitmap = NULL;
GLAPI mgl_glColor3b_t mgl_glColor3b = NULL;
GLAPI mgl_glColor3bv_t mgl_glColor3bv = NULL;
GLAPI mgl_glColor3d_t mgl_glColor3d = NULL;
GLAPI mgl_glColor3dv_t mgl_glColor3dv = NULL;
GLAPI mgl_glColor3f_t mgl_glColor3f = NULL;
GLAPI mgl_glColor3fv_t mgl_glColor3fv = NULL;
GLAPI mgl_glColor3i_t mgl_glColor3i = NULL;
GLAPI mgl_glColor3iv_t mgl_glColor3iv = NULL;
GLAPI mgl_glColor3s_t mgl_glColor3s = NULL;
GLAPI mgl_glColor3sv_t mgl_glColor3sv = NULL;
GLAPI mgl_glColor3ub_t mgl_glColor3ub = NULL;
GLAPI mgl_glColor3ubv_t mgl_glColor3ubv = NULL;
GLAPI mgl_glColor3ui_t mgl_glColor3ui = NULL;
GLAPI mgl_glColor3uiv_t mgl_glColor3uiv = NULL;
GLAPI mgl_glColor3us_t mgl_glColor3us = NULL;
GLAPI mgl_glColor3usv_t mgl_glColor3usv = NULL;
GLAPI mgl_glColor4b_t mgl_glColor4b = NULL;
GLAPI mgl_glColor4bv_t mgl_glColor4bv = NULL;
GLAPI mgl_glColor4d_t mgl_glColor4d = NULL;
GLAPI mgl_glColor4dv_t mgl_glColor4dv = NULL;
GLAPI mgl_glColor4f_t mgl_glColor4f = NULL;
GLAPI mgl_glColor4fv_t mgl_glColor4fv = NULL;
GLAPI mgl_glColor4i_t mgl_glColor4i = NULL;
GLAPI mgl_glColor4iv_t mgl_glColor4iv = NULL;
GLAPI mgl_glColor4s_t mgl_glColor4s = NULL;
GLAPI mgl_glColor4sv_t mgl_glColor4sv = NULL;
GLAPI mgl_glColor4ub_t mgl_glColor4ub = NULL;
GLAPI mgl_glColor4ubv_t mgl_glColor4ubv = NULL;
GLAPI mgl_glColor4ui_t mgl_glColor4ui = NULL;
GLAPI mgl_glColor4uiv_t mgl_glColor4uiv = NULL;
GLAPI mgl_glColor4us_t mgl_glColor4us = NULL;
GLAPI mgl_glColor4usv_t mgl_glColor4usv = NULL;
GLAPI mgl_glEdgeFlag_t mgl_glEdgeFlag = NULL;
GLAPI mgl_glEdgeFlagv_t mgl_glEdgeFlagv = NULL;
GLAPI mgl_glEnd_t mgl_glEnd = NULL;
GLAPI mgl_glIndexd_t mgl_glIndexd = NULL;
GLAPI mgl_glIndexdv_t mgl_glIndexdv = NULL;
GLAPI mgl_glIndexf_t mgl_glIndexf = NULL;
GLAPI mgl_glIndexfv_t mgl_glIndexfv = NULL;
GLAPI mgl_glIndexi_t mgl_glIndexi = NULL;
GLAPI mgl_glIndexiv_t mgl_glIndexiv = NULL;
GLAPI mgl_glIndexs_t mgl_glIndexs = NULL;
GLAPI mgl_glIndexsv_t mgl_glIndexsv = NULL;
GLAPI mgl_glNormal3b_t mgl_glNormal3b = NULL;
GLAPI mgl_glNormal3bv_t mgl_glNormal3bv = NULL;
GLAPI mgl_glNormal3d_t mgl_glNormal3d = NULL;
GLAPI mgl_glNormal3dv_t mgl_glNormal3dv = NULL;
GLAPI mgl_glNormal3f_t mgl_glNormal3f = NULL;
GLAPI mgl_glNormal3fv_t mgl_glNormal3fv = NULL;
GLAPI mgl_glNormal3i_t mgl_glNormal3i = NULL;
GLAPI mgl_glNormal3iv_t mgl_glNormal3iv = NULL;
GLAPI mgl_glNormal3s_t mgl_glNormal3s = NULL;
GLAPI mgl_glNormal3sv_t mgl_glNormal3sv = NULL;
GLAPI mgl_glRasterPos2d_t mgl_glRasterPos2d = NULL;
GLAPI mgl_glRasterPos2dv_t mgl_glRasterPos2dv = NULL;
GLAPI mgl_glRasterPos2f_t mgl_glRasterPos2f = NULL;
GLAPI mgl_glRasterPos2fv_t mgl_glRasterPos2fv = NULL;
GLAPI mgl_glRasterPos2i_t mgl_glRasterPos2i = NULL;
GLAPI mgl_glRasterPos2iv_t mgl_glRasterPos2iv = NULL;
GLAPI mgl_glRasterPos2s_t mgl_glRasterPos2s = NULL;
GLAPI mgl_glRasterPos2sv_t mgl_glRasterPos2sv = NULL;
GLAPI mgl_glRasterPos3d_t mgl_glRasterPos3d = NULL;
GLAPI mgl_glRasterPos3dv_t mgl_glRasterPos3dv = NULL;
GLAPI mgl_glRasterPos3f_t mgl_glRasterPos3f = NULL;
GLAPI mgl_glRasterPos3fv_t mgl_glRasterPos3fv = NULL;
GLAPI mgl_glRasterPos3i_t mgl_glRasterPos3i = NULL;
GLAPI mgl_glRasterPos3iv_t mgl_glRasterPos3iv = NULL;
GLAPI mgl_glRasterPos3s_t mgl_glRasterPos3s = NULL;
GLAPI mgl_glRasterPos3sv_t mgl_glRasterPos3sv = NULL;
GLAPI mgl_glRasterPos4d_t mgl_glRasterPos4d = NULL;
GLAPI mgl_glRasterPos4dv_t mgl_glRasterPos4dv = NULL;
GLAPI mgl_glRasterPos4f_t mgl_glRasterPos4f = NULL;
GLAPI mgl_glRasterPos4fv_t mgl_glRasterPos4fv = NULL;
GLAPI mgl_glRasterPos4i_t mgl_glRasterPos4i = NULL;
GLAPI mgl_glRasterPos4iv_t mgl_glRasterPos4iv = NULL;
GLAPI mgl_glRasterPos4s_t mgl_glRasterPos4s = NULL;
GLAPI mgl_glRasterPos4sv_t mgl_glRasterPos4sv = NULL;
GLAPI mgl_glRectd_t mgl_glRectd = NULL;
GLAPI mgl_glRectdv_t mgl_glRectdv = NULL;
GLAPI mgl_glRectf_t mgl_glRectf = NULL;
GLAPI mgl_glRectfv_t mgl_glRectfv = NULL;
GLAPI mgl_glRecti_t mgl_glRecti = NULL;
GLAPI mgl_glRectiv_t mgl_glRectiv = NULL;
GLAPI mgl_glRects_t mgl_glRects = NULL;
GLAPI mgl_glRectsv_t mgl_glRectsv = NULL;
GLAPI mgl_glTexCoord1d_t mgl_glTexCoord1d = NULL;
GLAPI mgl_glTexCoord1dv_t mgl_glTexCoord1dv = NULL;
GLAPI mgl_glTexCoord1f_t mgl_glTexCoord1f = NULL;
GLAPI mgl_glTexCoord1fv_t mgl_glTexCoord1fv = NULL;
GLAPI mgl_glTexCoord1i_t mgl_glTexCoord1i = NULL;
GLAPI mgl_glTexCoord1iv_t mgl_glTexCoord1iv = NULL;
GLAPI mgl_glTexCoord1s_t mgl_glTexCoord1s = NULL;
GLAPI mgl_glTexCoord1sv_t mgl_glTexCoord1sv = NULL;
GLAPI mgl_glTexCoord2d_t mgl_glTexCoord2d = NULL;
GLAPI mgl_glTexCoord2dv_t mgl_glTexCoord2dv = NULL;
GLAPI mgl_glTexCoord2f_t mgl_glTexCoord2f = NULL;
GLAPI mgl_glTexCoord2fv_t mgl_glTexCoord2fv = NULL;
GLAPI mgl_glTexCoord2i_t mgl_glTexCoord2i = NULL;
GLAPI mgl_glTexCoord2iv_t mgl_glTexCoord2iv = NULL;
GLAPI mgl_glTexCoord2s_t mgl_glTexCoord2s = NULL;
GLAPI mgl_glTexCoord2sv_t mgl_glTexCoord2sv = NULL;
GLAPI mgl_glTexCoord3d_t mgl_glTexCoord3d = NULL;
GLAPI mgl_glTexCoord3dv_t mgl_glTexCoord3dv = NULL;
GLAPI mgl_glTexCoord3f_t mgl_glTexCoord3f = NULL;
GLAPI mgl_glTexCoord3fv_t mgl_glTexCoord3fv = NULL;
GLAPI mgl_glTexCoord3i_t mgl_glTexCoord3i = NULL;
GLAPI mgl_glTexCoord3iv_t mgl_glTexCoord3iv = NULL;
GLAPI mgl_glTexCoord3s_t mgl_glTexCoord3s = NULL;
GLAPI mgl_glTexCoord3sv_t mgl_glTexCoord3sv = NULL;
GLAPI mgl_glTexCoord4d_t mgl_glTexCoord4d = NULL;
GLAPI mgl_glTexCoord4dv_t mgl_glTexCoord4dv = NULL;
GLAPI mgl_glTexCoord4f_t mgl_glTexCoord4f = NULL;
GLAPI mgl_glTexCoord4fv_t mgl_glTexCoord4fv = NULL;
GLAPI mgl_glTexCoord4i_t mgl_glTexCoord4i = NULL;
GLAPI mgl_glTexCoord4iv_t mgl_glTexCoord4iv = NULL;
GLAPI mgl_glTexCoord4s_t mgl_glTexCoord4s = NULL;
GLAPI mgl_glTexCoord4sv_t mgl_glTexCoord4sv = NULL;
GLAPI mgl_glVertex2d_t mgl_glVertex2d = NULL;
GLAPI mgl_glVertex2dv_t mgl_glVertex2dv = NULL;
GLAPI mgl_glVertex2f_t mgl_glVertex2f = NULL;
GLAPI mgl_glVertex2fv_t mgl_glVertex2fv = NULL;
GLAPI mgl_glVertex2i_t mgl_glVertex2i = NULL;
GLAPI mgl_glVertex2iv_t mgl_glVertex2iv = NULL;
GLAPI mgl_glVertex2s_t mgl_glVertex2s = NULL;
GLAPI mgl_glVertex2sv_t mgl_glVertex2sv = NULL;
GLAPI mgl_glVertex3d_t mgl_glVertex3d = NULL;
GLAPI mgl_glVertex3dv_t mgl_glVertex3dv = NULL;
GLAPI mgl_glVertex3f_t mgl_glVertex3f = NULL;
GLAPI mgl_glVertex3fv_t mgl_glVertex3fv = NULL;
GLAPI mgl_glVertex3i_t mgl_glVertex3i = NULL;
GLAPI mgl_glVertex3iv_t mgl_glVertex3iv = NULL;
GLAPI mgl_glVertex3s_t mgl_glVertex3s = NULL;
GLAPI mgl_glVertex3sv_t mgl_glVertex3sv = NULL;
GLAPI mgl_glVertex4d_t mgl_glVertex4d = NULL;
GLAPI mgl_glVertex4dv_t mgl_glVertex4dv = NULL;
GLAPI mgl_glVertex4f_t mgl_glVertex4f = NULL;
GLAPI mgl_glVertex4fv_t mgl_glVertex4fv = NULL;
GLAPI mgl_glVertex4i_t mgl_glVertex4i = NULL;
GLAPI mgl_glVertex4iv_t mgl_glVertex4iv = NULL;
GLAPI mgl_glVertex4s_t mgl_glVertex4s = NULL;
GLAPI mgl_glVertex4sv_t mgl_glVertex4sv = NULL;
GLAPI mgl_glClipPlane_t mgl_glClipPlane = NULL;
GLAPI mgl_glColorMaterial_t mgl_glColorMaterial = NULL;
GLAPI mgl_glFogf_t mgl_glFogf = NULL;
GLAPI mgl_glFogfv_t mgl_glFogfv = NULL;
GLAPI mgl_glFogi_t mgl_glFogi = NULL;
GLAPI mgl_glFogiv_t mgl_glFogiv = NULL;
GLAPI mgl_glLightf_t mgl_glLightf = NULL;
GLAPI mgl_glLightfv_t mgl_glLightfv = NULL;
GLAPI mgl_glLighti_t mgl_glLighti = NULL;
GLAPI mgl_glLightiv_t mgl_glLightiv = NULL;
GLAPI mgl_glLightModelf_t mgl_glLightModelf = NULL;
GLAPI mgl_glLightModelfv_t mgl_glLightModelfv = NULL;
GLAPI mgl_glLightModeli_t mgl_glLightModeli = NULL;
GLAPI mgl_glLightModeliv_t mgl_glLightModeliv = NULL;
GLAPI mgl_glLineStipple_t mgl_glLineStipple = NULL;
GLAPI mgl_glMaterialf_t mgl_glMaterialf = NULL;
GLAPI mgl_glMaterialfv_t mgl_glMaterialfv = NULL;
GLAPI mgl_glMateriali_t mgl_glMateriali = NULL;
GLAPI mgl_glMaterialiv_t mgl_glMaterialiv = NULL;
GLAPI mgl_glPolygonStipple_t mgl_glPolygonStipple = NULL;
GLAPI mgl_glShadeModel_t mgl_glShadeModel = NULL;
GLAPI mgl_glTexEnvf_t mgl_glTexEnvf = NULL;
GLAPI mgl_glTexEnvfv_t mgl_glTexEnvfv = NULL;
GLAPI mgl_glTexEnvi_t mgl_glTexEnvi = NULL;
GLAPI mgl_glTexEnviv_t mgl_glTexEnviv = NULL;
GLAPI mgl_glTexGend_t mgl_glTexGend = NULL;
GLAPI mgl_glTexGendv_t mgl_glTexGendv = NULL;
GLAPI mgl_glTexGenf_t mgl_glTexGenf = NULL;
GLAPI mgl_glTexGenfv_t mgl_glTexGenfv = NULL;
GLAPI mgl_glTexGeni_t mgl_glTexGeni = NULL;
GLAPI mgl_glTexGeniv_t mgl_glTexGeniv = NULL;
GLAPI mgl_glFeedbackBuffer_t mgl_glFeedbackBuffer = NULL;
GLAPI mgl_glSelectBuffer_t mgl_glSelectBuffer = NULL;
GLAPI mgl_glRenderMode_t mgl_glRenderMode = NULL;
GLAPI mgl_glInitNames_t mgl_glInitNames = NULL;
GLAPI mgl_glLoadName_t mgl_glLoadName = NULL;
GLAPI mgl_glPassThrough_t mgl_glPassThrough = NULL;
GLAPI mgl_glPopName_t mgl_glPopName = NULL;
GLAPI mgl_glPushName_t mgl_glPushName = NULL;
GLAPI mgl_glClearAccum_t mgl_glClearAccum = NULL;
GLAPI mgl_glClearIndex_t mgl_glClearIndex = NULL;
GLAPI mgl_glIndexMask_t mgl_glIndexMask = NULL;
GLAPI mgl_glAccum_t mgl_glAccum = NULL;
GLAPI mgl_glPopAttrib_t mgl_glPopAttrib = NULL;
GLAPI mgl_glPushAttrib_t mgl_glPushAttrib = NULL;
GLAPI mgl_glMap1d_t mgl_glMap1d = NULL;
GLAPI mgl_glMap1f_t mgl_glMap1f = NULL;
GLAPI mgl_glMap2d_t mgl_glMap2d = NULL;
GLAPI mgl_glMap2f_t mgl_glMap2f = NULL;
GLAPI mgl_glMapGrid1d_t mgl_glMapGrid1d = NULL;
GLAPI mgl_glMapGrid1f_t mgl_glMapGrid1f = NULL;
GLAPI mgl_glMapGrid2d_t mgl_glMapGrid2d = NULL;
GLAPI mgl_glMapGrid2f_t mgl_glMapGrid2f = NULL;
GLAPI mgl_glEvalCoord1d_t mgl_glEvalCoord1d = NULL;
GLAPI mgl_glEvalCoord1dv_t mgl_glEvalCoord1dv = NULL;
GLAPI mgl_glEvalCoord1f_t mgl_glEvalCoord1f = NULL;
GLAPI mgl_glEvalCoord1fv_t mgl_glEvalCoord1fv = NULL;
GLAPI mgl_glEvalCoord2d_t mgl_glEvalCoord2d = NULL;
GLAPI mgl_glEvalCoord2dv_t mgl_glEvalCoord2dv = NULL;
GLAPI mgl_glEvalCoord2f_t mgl_glEvalCoord2f = NULL;
GLAPI mgl_glEvalCoord2fv_t mgl_glEvalCoord2fv = NULL;
GLAPI mgl_glEvalMesh1_t mgl_glEvalMesh1 = NULL;
GLAPI mgl_glEvalPoint1_t mgl_glEvalPoint1 = NULL;
GLAPI mgl_glEvalMesh2_t mgl_glEvalMesh2 = NULL;
GLAPI mgl_glEvalPoint2_t mgl_glEvalPoint2 = NULL;
GLAPI mgl_glAlphaFunc_t mgl_glAlphaFunc = NULL;
GLAPI mgl_glPixelZoom_t mgl_glPixelZoom = NULL;
GLAPI mgl_glPixelTransferf_t mgl_glPixelTransferf = NULL;
GLAPI mgl_glPixelTransferi_t mgl_glPixelTransferi = NULL;
GLAPI mgl_glPixelMapfv_t mgl_glPixelMapfv = NULL;
GLAPI mgl_glPixelMapuiv_t mgl_glPixelMapuiv = NULL;
GLAPI mgl_glPixelMapusv_t mgl_glPixelMapusv = NULL;
GLAPI mgl_glCopyPixels_t mgl_glCopyPixels = NULL;
GLAPI mgl_glDrawPixels_t mgl_glDrawPixels = NULL;
GLAPI mgl_glGetClipPlane_t mgl_glGetClipPlane = NULL;
GLAPI mgl_glGetLightfv_t mgl_glGetLightfv = NULL;
GLAPI mgl_glGetLightiv_t mgl_glGetLightiv = NULL;
GLAPI mgl_glGetMapdv_t mgl_glGetMapdv = NULL;
GLAPI mgl_glGetMapfv_t mgl_glGetMapfv = NULL;
GLAPI mgl_glGetMapiv_t mgl_glGetMapiv = NULL;
GLAPI mgl_glGetMaterialfv_t mgl_glGetMaterialfv = NULL;
GLAPI mgl_glGetMaterialiv_t mgl_glGetMaterialiv = NULL;
GLAPI mgl_glGetPixelMapfv_t mgl_glGetPixelMapfv = NULL;
GLAPI mgl_glGetPixelMapuiv_t mgl_glGetPixelMapuiv = NULL;
GLAPI mgl_glGetPixelMapusv_t mgl_glGetPixelMapusv = NULL;
GLAPI mgl_glGetPolygonStipple_t mgl_glGetPolygonStipple = NULL;
GLAPI mgl_glGetTexEnvfv_t mgl_glGetTexEnvfv = NULL;
GLAPI mgl_glGetTexEnviv_t mgl_glGetTexEnviv = NULL;
GLAPI mgl_glGetTexGendv_t mgl_glGetTexGendv = NULL;
GLAPI mgl_glGetTexGenfv_t mgl_glGetTexGenfv = NULL;
GLAPI mgl_glGetTexGeniv_t mgl_glGetTexGeniv = NULL;
GLAPI mgl_glIsList_t mgl_glIsList = NULL;
GLAPI mgl_glFrustum_t mgl_glFrustum = NULL;
GLAPI mgl_glLoadIdentity_t mgl_glLoadIdentity = NULL;
GLAPI mgl_glLoadMatrixf_t mgl_glLoadMatrixf = NULL;
GLAPI mgl_glLoadMatrixd_t mgl_glLoadMatrixd = NULL;
GLAPI mgl_glMatrixMode_t mgl_glMatrixMode = NULL;
GLAPI mgl_glMultMatrixf_t mgl_glMultMatrixf = NULL;
GLAPI mgl_glMultMatrixd_t mgl_glMultMatrixd = NULL;
GLAPI mgl_glOrtho_t mgl_glOrtho = NULL;
GLAPI mgl_glPopMatrix_t mgl_glPopMatrix = NULL;
GLAPI mgl_glPushMatrix_t mgl_glPushMatrix = NULL;
GLAPI mgl_glRotated_t mgl_glRotated = NULL;
GLAPI mgl_glRotatef_t mgl_glRotatef = NULL;
GLAPI mgl_glScaled_t mgl_glScaled = NULL;
GLAPI mgl_glScalef_t mgl_glScalef = NULL;
GLAPI mgl_glTranslated_t mgl_glTranslated = NULL;
GLAPI mgl_glTranslatef_t mgl_glTranslatef = NULL;
GLAPI mgl_glDrawArrays_t mgl_glDrawArrays = NULL;
GLAPI mgl_glDrawElements_t mgl_glDrawElements = NULL;
GLAPI mgl_glGetPointerv_t mgl_glGetPointerv = NULL;
GLAPI mgl_glPolygonOffset_t mgl_glPolygonOffset = NULL;
GLAPI mgl_glCopyTexImage1D_t mgl_glCopyTexImage1D = NULL;
GLAPI mgl_glCopyTexImage2D_t mgl_glCopyTexImage2D = NULL;
GLAPI mgl_glCopyTexSubImage1D_t mgl_glCopyTexSubImage1D = NULL;
GLAPI mgl_glCopyTexSubImage2D_t mgl_glCopyTexSubImage2D = NULL;
GLAPI mgl_glTexSubImage1D_t mgl_glTexSubImage1D = NULL;
GLAPI mgl_glTexSubImage2D_t mgl_glTexSubImage2D = NULL;
GLAPI mgl_glBindTexture_t mgl_glBindTexture = NULL;
GLAPI mgl_glDeleteTextures_t mgl_glDeleteTextures = NULL;
GLAPI mgl_glGenTextures_t mgl_glGenTextures = NULL;
GLAPI mgl_glIsTexture_t mgl_glIsTexture = NULL;
GLAPI mgl_glArrayElement_t mgl_glArrayElement = NULL;
GLAPI mgl_glColorPointer_t mgl_glColorPointer = NULL;
GLAPI mgl_glDisableClientState_t mgl_glDisableClientState = NULL;
GLAPI mgl_glEdgeFlagPointer_t mgl_glEdgeFlagPointer = NULL;
GLAPI mgl_glEnableClientState_t mgl_glEnableClientState = NULL;
GLAPI mgl_glIndexPointer_t mgl_glIndexPointer = NULL;
GLAPI mgl_glInterleavedArrays_t mgl_glInterleavedArrays = NULL;
GLAPI mgl_glNormalPointer_t mgl_glNormalPointer = NULL;
GLAPI mgl_glTexCoordPointer_t mgl_glTexCoordPointer = NULL;
GLAPI mgl_glVertexPointer_t mgl_glVertexPointer = NULL;
GLAPI mgl_glAreTexturesResident_t mgl_glAreTexturesResident = NULL;
GLAPI mgl_glPrioritizeTextures_t mgl_glPrioritizeTextures = NULL;
GLAPI mgl_glIndexub_t mgl_glIndexub = NULL;
GLAPI mgl_glIndexubv_t mgl_glIndexubv = NULL;
GLAPI mgl_glPopClientAttrib_t mgl_glPopClientAttrib = NULL;
GLAPI mgl_glPushClientAttrib_t mgl_glPushClientAttrib = NULL;
GLAPI mgl_glDrawRangeElements_t mgl_glDrawRangeElements = NULL;
GLAPI mgl_glTexImage3D_t mgl_glTexImage3D = NULL;
GLAPI mgl_glTexSubImage3D_t mgl_glTexSubImage3D = NULL;
GLAPI mgl_glCopyTexSubImage3D_t mgl_glCopyTexSubImage3D = NULL;
GLAPI mgl_glActiveTexture_t mgl_glActiveTexture = NULL;
GLAPI mgl_glSampleCoverage_t mgl_glSampleCoverage = NULL;
GLAPI mgl_glCompressedTexImage3D_t mgl_glCompressedTexImage3D = NULL;
GLAPI mgl_glCompressedTexImage2D_t mgl_glCompressedTexImage2D = NULL;
GLAPI mgl_glCompressedTexImage1D_t mgl_glCompressedTexImage1D = NULL;
GLAPI mgl_glCompressedTexSubImage3D_t mgl_glCompressedTexSubImage3D = NULL;
GLAPI mgl_glCompressedTexSubImage2D_t mgl_glCompressedTexSubImage2D = NULL;
GLAPI mgl_glCompressedTexSubImage1D_t mgl_glCompressedTexSubImage1D = NULL;
GLAPI mgl_glGetCompressedTexImage_t mgl_glGetCompressedTexImage = NULL;
GLAPI mgl_glClientActiveTexture_t mgl_glClientActiveTexture = NULL;
GLAPI mgl_glMultiTexCoord1d_t mgl_glMultiTexCoord1d = NULL;
GLAPI mgl_glMultiTexCoord1dv_t mgl_glMultiTexCoord1dv = NULL;
GLAPI mgl_glMultiTexCoord1f_t mgl_glMultiTexCoord1f = NULL;
GLAPI mgl_glMultiTexCoord1fv_t mgl_glMultiTexCoord1fv = NULL;
GLAPI mgl_glMultiTexCoord1i_t mgl_glMultiTexCoord1i = NULL;
GLAPI mgl_glMultiTexCoord1iv_t mgl_glMultiTexCoord1iv = NULL;
GLAPI mgl_glMultiTexCoord1s_t mgl_glMultiTexCoord1s = NULL;
GLAPI mgl_glMultiTexCoord1sv_t mgl_glMultiTexCoord1sv = NULL;
GLAPI mgl_glMultiTexCoord2d_t mgl_glMultiTexCoord2d = NULL;
GLAPI mgl_glMultiTexCoord2dv_t mgl_glMultiTexCoord2dv = NULL;
GLAPI mgl_glMultiTexCoord2f_t mgl_glMultiTexCoord2f = NULL;
GLAPI mgl_glMultiTexCoord2fv_t mgl_glMultiTexCoord2fv = NULL;
GLAPI mgl_glMultiTexCoord2i_t mgl_glMultiTexCoord2i = NULL;
GLAPI mgl_glMultiTexCoord2iv_t mgl_glMultiTexCoord2iv = NULL;
GLAPI mgl_glMultiTexCoord2s_t mgl_glMultiTexCoord2s = NULL;
GLAPI mgl_glMultiTexCoord2sv_t mgl_glMultiTexCoord2sv = NULL;
GLAPI mgl_glMultiTexCoord3d_t mgl_glMultiTexCoord3d = NULL;
GLAPI mgl_glMultiTexCoord3dv_t mgl_glMultiTexCoord3dv = NULL;
GLAPI mgl_glMultiTexCoord3f_t mgl_glMultiTexCoord3f = NULL;
GLAPI mgl_glMultiTexCoord3fv_t mgl_glMultiTexCoord3fv = NULL;
GLAPI mgl_glMultiTexCoord3i_t mgl_glMultiTexCoord3i = NULL;
GLAPI mgl_glMultiTexCoord3iv_t mgl_glMultiTexCoord3iv = NULL;
GLAPI mgl_glMultiTexCoord3s_t mgl_glMultiTexCoord3s = NULL;
GLAPI mgl_glMultiTexCoord3sv_t mgl_glMultiTexCoord3sv = NULL;
GLAPI mgl_glMultiTexCoord4d_t mgl_glMultiTexCoord4d = NULL;
GLAPI mgl_glMultiTexCoord4dv_t mgl_glMultiTexCoord4dv = NULL;
GLAPI mgl_glMultiTexCoord4f_t mgl_glMultiTexCoord4f = NULL;
GLAPI mgl_glMultiTexCoord4fv_t mgl_glMultiTexCoord4fv = NULL;
GLAPI mgl_glMultiTexCoord4i_t mgl_glMultiTexCoord4i = NULL;
GLAPI mgl_glMultiTexCoord4iv_t mgl_glMultiTexCoord4iv = NULL;
GLAPI mgl_glMultiTexCoord4s_t mgl_glMultiTexCoord4s = NULL;
GLAPI mgl_glMultiTexCoord4sv_t mgl_glMultiTexCoord4sv = NULL;
GLAPI mgl_glLoadTransposeMatrixf_t mgl_glLoadTransposeMatrixf = NULL;
GLAPI mgl_glLoadTransposeMatrixd_t mgl_glLoadTransposeMatrixd = NULL;
GLAPI mgl_glMultTransposeMatrixf_t mgl_glMultTransposeMatrixf = NULL;
GLAPI mgl_glMultTransposeMatrixd_t mgl_glMultTransposeMatrixd = NULL;
GLAPI mgl_glBlendFuncSeparate_t mgl_glBlendFuncSeparate = NULL;
GLAPI mgl_glMultiDrawArrays_t mgl_glMultiDrawArrays = NULL;
GLAPI mgl_glMultiDrawElements_t mgl_glMultiDrawElements = NULL;
GLAPI mgl_glPointParameterf_t mgl_glPointParameterf = NULL;
GLAPI mgl_glPointParameterfv_t mgl_glPointParameterfv = NULL;
GLAPI mgl_glPointParameteri_t mgl_glPointParameteri = NULL;
GLAPI mgl_glPointParameteriv_t mgl_glPointParameteriv = NULL;
GLAPI mgl_glFogCoordf_t mgl_glFogCoordf = NULL;
GLAPI mgl_glFogCoordfv_t mgl_glFogCoordfv = NULL;
GLAPI mgl_glFogCoordd_t mgl_glFogCoordd = NULL;
GLAPI mgl_glFogCoorddv_t mgl_glFogCoorddv = NULL;
GLAPI mgl_glFogCoordPointer_t mgl_glFogCoordPointer = NULL;
GLAPI mgl_glSecondaryColor3b_t mgl_glSecondaryColor3b = NULL;
GLAPI mgl_glSecondaryColor3bv_t mgl_glSecondaryColor3bv = NULL;
GLAPI mgl_glSecondaryColor3d_t mgl_glSecondaryColor3d = NULL;
GLAPI mgl_glSecondaryColor3dv_t mgl_glSecondaryColor3dv = NULL;
GLAPI mgl_glSecondaryColor3f_t mgl_glSecondaryColor3f = NULL;
GLAPI mgl_glSecondaryColor3fv_t mgl_glSecondaryColor3fv = NULL;
GLAPI mgl_glSecondaryColor3i_t mgl_glSecondaryColor3i = NULL;
GLAPI mgl_glSecondaryColor3iv_t mgl_glSecondaryColor3iv = NULL;
GLAPI mgl_glSecondaryColor3s_t mgl_glSecondaryColor3s = NULL;
GLAPI mgl_glSecondaryColor3sv_t mgl_glSecondaryColor3sv = NULL;
GLAPI mgl_glSecondaryColor3ub_t mgl_glSecondaryColor3ub = NULL;
GLAPI mgl_glSecondaryColor3ubv_t mgl_glSecondaryColor3ubv = NULL;
GLAPI mgl_glSecondaryColor3ui_t mgl_glSecondaryColor3ui = NULL;
GLAPI mgl_glSecondaryColor3uiv_t mgl_glSecondaryColor3uiv = NULL;
GLAPI mgl_glSecondaryColor3us_t mgl_glSecondaryColor3us = NULL;
GLAPI mgl_glSecondaryColor3usv_t mgl_glSecondaryColor3usv = NULL;
GLAPI mgl_glSecondaryColorPointer_t mgl_glSecondaryColorPointer = NULL;
GLAPI mgl_glWindowPos2d_t mgl_glWindowPos2d = NULL;
GLAPI mgl_glWindowPos2dv_t mgl_glWindowPos2dv = NULL;
GLAPI mgl_glWindowPos2f_t mgl_glWindowPos2f = NULL;
GLAPI mgl_glWindowPos2fv_t mgl_glWindowPos2fv = NULL;
GLAPI mgl_glWindowPos2i_t mgl_glWindowPos2i = NULL;
GLAPI mgl_glWindowPos2iv_t mgl_glWindowPos2iv = NULL;
GLAPI mgl_glWindowPos2s_t mgl_glWindowPos2s = NULL;
GLAPI mgl_glWindowPos2sv_t mgl_glWindowPos2sv = NULL;
GLAPI mgl_glWindowPos3d_t mgl_glWindowPos3d = NULL;
GLAPI mgl_glWindowPos3dv_t mgl_glWindowPos3dv = NULL;
GLAPI mgl_glWindowPos3f_t mgl_glWindowPos3f = NULL;
GLAPI mgl_glWindowPos3fv_t mgl_glWindowPos3fv = NULL;
GLAPI mgl_glWindowPos3i_t mgl_glWindowPos3i = NULL;
GLAPI mgl_glWindowPos3iv_t mgl_glWindowPos3iv = NULL;
GLAPI mgl_glWindowPos3s_t mgl_glWindowPos3s = NULL;
GLAPI mgl_glWindowPos3sv_t mgl_glWindowPos3sv = NULL;
GLAPI mgl_glBlendColor_t mgl_glBlendColor = NULL;
GLAPI mgl_glBlendEquation_t mgl_glBlendEquation = NULL;
GLAPI mgl_glGenQueries_t mgl_glGenQueries = NULL;
GLAPI mgl_glDeleteQueries_t mgl_glDeleteQueries = NULL;
GLAPI mgl_glIsQuery_t mgl_glIsQuery = NULL;
GLAPI mgl_glBeginQuery_t mgl_glBeginQuery = NULL;
GLAPI mgl_glEndQuery_t mgl_glEndQuery = NULL;
GLAPI mgl_glGetQueryiv_t mgl_glGetQueryiv = NULL;
GLAPI mgl_glGetQueryObjectiv_t mgl_glGetQueryObjectiv = NULL;
GLAPI mgl_glGetQueryObjectuiv_t mgl_glGetQueryObjectuiv = NULL;
GLAPI mgl_glBindBuffer_t mgl_glBindBuffer = NULL;
GLAPI mgl_glDeleteBuffers_t mgl_glDeleteBuffers = NULL;
GLAPI mgl_glGenBuffers_t mgl_glGenBuffers = NULL;
GLAPI mgl_glIsBuffer_t mgl_glIsBuffer = NULL;
GLAPI mgl_glBufferData_t mgl_glBufferData = NULL;
GLAPI mgl_glBufferSubData_t mgl_glBufferSubData = NULL;
GLAPI mgl_glGetBufferSubData_t mgl_glGetBufferSubData = NULL;
GLAPI mgl_glMapBuffer_t mgl_glMapBuffer = NULL;
GLAPI mgl_glUnmapBuffer_t mgl_glUnmapBuffer = NULL;
GLAPI mgl_glGetBufferParameteriv_t mgl_glGetBufferParameteriv = NULL;
GLAPI mgl_glGetBufferPointerv_t mgl_glGetBufferPointerv = NULL;
GLAPI mgl_glBlendEquationSeparate_t mgl_glBlendEquationSeparate = NULL;
GLAPI mgl_glDrawBuffers_t mgl_glDrawBuffers = NULL;
GLAPI mgl_glStencilOpSeparate_t mgl_glStencilOpSeparate = NULL;
GLAPI mgl_glStencilFuncSeparate_t mgl_glStencilFuncSeparate = NULL;
GLAPI mgl_glStencilMaskSeparate_t mgl_glStencilMaskSeparate = NULL;
GLAPI mgl_glAttachShader_t mgl_glAttachShader = NULL;
GLAPI mgl_glBindAttribLocation_t mgl_glBindAttribLocation = NULL;
GLAPI mgl_glCompileShader_t mgl_glCompileShader = NULL;
GLAPI mgl_glCreateProgram_t mgl_glCreateProgram = NULL;
GLAPI mgl_glCreateShader_t mgl_glCreateShader = NULL;
GLAPI mgl_glDeleteProgram_t mgl_glDeleteProgram = NULL;
GLAPI mgl_glDeleteShader_t mgl_glDeleteShader = NULL;
GLAPI mgl_glDetachShader_t mgl_glDetachShader = NULL;
GLAPI mgl_glDisableVertexAttribArray_t mgl_glDisableVertexAttribArray = NULL;
GLAPI mgl_glEnableVertexAttribArray_t mgl_glEnableVertexAttribArray = NULL;
GLAPI mgl_glGetActiveAttrib_t mgl_glGetActiveAttrib = NULL;
GLAPI mgl_glGetActiveUniform_t mgl_glGetActiveUniform = NULL;
GLAPI mgl_glGetAttachedShaders_t mgl_glGetAttachedShaders = NULL;
GLAPI mgl_glGetAttribLocation_t mgl_glGetAttribLocation = NULL;
GLAPI mgl_glGetProgramiv_t mgl_glGetProgramiv = NULL;
GLAPI mgl_glGetProgramInfoLog_t mgl_glGetProgramInfoLog = NULL;
GLAPI mgl_glGetShaderiv_t mgl_glGetShaderiv = NULL;
GLAPI mgl_glGetShaderInfoLog_t mgl_glGetShaderInfoLog = NULL;
GLAPI mgl_glGetShaderSource_t mgl_glGetShaderSource = NULL;
GLAPI mgl_glGetUniformLocation_t mgl_glGetUniformLocation = NULL;
GLAPI mgl_glGetUniformfv_t mgl_glGetUniformfv = NULL;
GLAPI mgl_glGetUniformiv_t mgl_glGetUniformiv = NULL;
GLAPI mgl_glGetVertexAttribdv_t mgl_glGetVertexAttribdv = NULL;
GLAPI mgl_glGetVertexAttribfv_t mgl_glGetVertexAttribfv = NULL;
GLAPI mgl_glGetVertexAttribiv_t mgl_glGetVertexAttribiv = NULL;
GLAPI mgl_glGetVertexAttribPointerv_t mgl_glGetVertexAttribPointerv = NULL;
GLAPI mgl_glIsProgram_t mgl_glIsProgram = NULL;
GLAPI mgl_glIsShader_t mgl_glIsShader = NULL;
GLAPI mgl_glLinkProgram_t mgl_glLinkProgram = NULL;
GLAPI mgl_glShaderSource_t mgl_glShaderSource = NULL;
GLAPI mgl_glUseProgram_t mgl_glUseProgram = NULL;
GLAPI mgl_glUniform1f_t mgl_glUniform1f = NULL;
GLAPI mgl_glUniform2f_t mgl_glUniform2f = NULL;
GLAPI mgl_glUniform3f_t mgl_glUniform3f = NULL;
GLAPI mgl_glUniform4f_t mgl_glUniform4f = NULL;
GLAPI mgl_glUniform1i_t mgl_glUniform1i = NULL;
GLAPI mgl_glUniform2i_t mgl_glUniform2i = NULL;
GLAPI mgl_glUniform3i_t mgl_glUniform3i = NULL;
GLAPI mgl_glUniform4i_t mgl_glUniform4i = NULL;
GLAPI mgl_glUniform1fv_t mgl_glUniform1fv = NULL;
GLAPI mgl_glUniform2fv_t mgl_glUniform2fv = NULL;
GLAPI mgl_glUniform3fv_t mgl_glUniform3fv = NULL;
GLAPI mgl_glUniform4fv_t mgl_glUniform4fv = NULL;
GLAPI mgl_glUniform1iv_t mgl_glUniform1iv = NULL;
GLAPI mgl_glUniform2iv_t mgl_glUniform2iv = NULL;
GLAPI mgl_glUniform3iv_t mgl_glUniform3iv = NULL;
GLAPI mgl_glUniform4iv_t mgl_glUniform4iv = NULL;
GLAPI mgl_glUniformMatrix2fv_t mgl_glUniformMatrix2fv = NULL;
GLAPI mgl_glUniformMatrix3fv_t mgl_glUniformMatrix3fv = NULL;
GLAPI mgl_glUniformMatrix4fv_t mgl_glUniformMatrix4fv = NULL;
GLAPI mgl_glValidateProgram_t mgl_glValidateProgram = NULL;
GLAPI mgl_glVertexAttrib1d_t mgl_glVertexAttrib1d = NULL;
GLAPI mgl_glVertexAttrib1dv_t mgl_glVertexAttrib1dv = NULL;
GLAPI mgl_glVertexAttrib1f_t mgl_glVertexAttrib1f = NULL;
GLAPI mgl_glVertexAttrib1fv_t mgl_glVertexAttrib1fv = NULL;
GLAPI mgl_glVertexAttrib1s_t mgl_glVertexAttrib1s = NULL;
GLAPI mgl_glVertexAttrib1sv_t mgl_glVertexAttrib1sv = NULL;
GLAPI mgl_glVertexAttrib2d_t mgl_glVertexAttrib2d = NULL;
GLAPI mgl_glVertexAttrib2dv_t mgl_glVertexAttrib2dv = NULL;
GLAPI mgl_glVertexAttrib2f_t mgl_glVertexAttrib2f = NULL;
GLAPI mgl_glVertexAttrib2fv_t mgl_glVertexAttrib2fv = NULL;
GLAPI mgl_glVertexAttrib2s_t mgl_glVertexAttrib2s = NULL;
GLAPI mgl_glVertexAttrib2sv_t mgl_glVertexAttrib2sv = NULL;
GLAPI mgl_glVertexAttrib3d_t mgl_glVertexAttrib3d = NULL;
GLAPI mgl_glVertexAttrib3dv_t mgl_glVertexAttrib3dv = NULL;
GLAPI mgl_glVertexAttrib3f_t mgl_glVertexAttrib3f = NULL;
GLAPI mgl_glVertexAttrib3fv_t mgl_glVertexAttrib3fv = NULL;
GLAPI mgl_glVertexAttrib3s_t mgl_glVertexAttrib3s = NULL;
GLAPI mgl_glVertexAttrib3sv_t mgl_glVertexAttrib3sv = NULL;
GLAPI mgl_glVertexAttrib4Nbv_t mgl_glVertexAttrib4Nbv = NULL;
GLAPI mgl_glVertexAttrib4Niv_t mgl_glVertexAttrib4Niv = NULL;
GLAPI mgl_glVertexAttrib4Nsv_t mgl_glVertexAttrib4Nsv = NULL;
GLAPI mgl_glVertexAttrib4Nub_t mgl_glVertexAttrib4Nub = NULL;
GLAPI mgl_glVertexAttrib4Nubv_t mgl_glVertexAttrib4Nubv = NULL;
GLAPI mgl_glVertexAttrib4Nuiv_t mgl_glVertexAttrib4Nuiv = NULL;
GLAPI mgl_glVertexAttrib4Nusv_t mgl_glVertexAttrib4Nusv = NULL;
GLAPI mgl_glVertexAttrib4bv_t mgl_glVertexAttrib4bv = NULL;
GLAPI mgl_glVertexAttrib4d_t mgl_glVertexAttrib4d = NULL;
GLAPI mgl_glVertexAttrib4dv_t mgl_glVertexAttrib4dv = NULL;
GLAPI mgl_glVertexAttrib4f_t mgl_glVertexAttrib4f = NULL;
GLAPI mgl_glVertexAttrib4fv_t mgl_glVertexAttrib4fv = NULL;
GLAPI mgl_glVertexAttrib4iv_t mgl_glVertexAttrib4iv = NULL;
GLAPI mgl_glVertexAttrib4s_t mgl_glVertexAttrib4s = NULL;
GLAPI mgl_glVertexAttrib4sv_t mgl_glVertexAttrib4sv = NULL;
GLAPI mgl_glVertexAttrib4ubv_t mgl_glVertexAttrib4ubv = NULL;
GLAPI mgl_glVertexAttrib4uiv_t mgl_glVertexAttrib4uiv = NULL;
GLAPI mgl_glVertexAttrib4usv_t mgl_glVertexAttrib4usv = NULL;
GLAPI mgl_glVertexAttribPointer_t mgl_glVertexAttribPointer = NULL;
GLAPI mgl_glUniformMatrix2x3fv_t mgl_glUniformMatrix2x3fv = NULL;
GLAPI mgl_glUniformMatrix3x2fv_t mgl_glUniformMatrix3x2fv = NULL;
GLAPI mgl_glUniformMatrix2x4fv_t mgl_glUniformMatrix2x4fv = NULL;
GLAPI mgl_glUniformMatrix4x2fv_t mgl_glUniformMatrix4x2fv = NULL;
GLAPI mgl_glUniformMatrix3x4fv_t mgl_glUniformMatrix3x4fv = NULL;
GLAPI mgl_glUniformMatrix4x3fv_t mgl_glUniformMatrix4x3fv = NULL;
GLAPI mgl_glColorMaski_t mgl_glColorMaski = NULL;
GLAPI mgl_glGetBooleani_v_t mgl_glGetBooleani_v = NULL;
GLAPI mgl_glGetIntegeri_v_t mgl_glGetIntegeri_v = NULL;
GLAPI mgl_glEnablei_t mgl_glEnablei = NULL;
GLAPI mgl_glDisablei_t mgl_glDisablei = NULL;
GLAPI mgl_glIsEnabledi_t mgl_glIsEnabledi = NULL;
GLAPI mgl_glBeginTransformFeedback_t mgl_glBeginTransformFeedback = NULL;
GLAPI mgl_glEndTransformFeedback_t mgl_glEndTransformFeedback = NULL;
GLAPI mgl_glBindBufferRange_t mgl_glBindBufferRange = NULL;
GLAPI mgl_glBindBufferBase_t mgl_glBindBufferBase = NULL;
GLAPI mgl_glTransformFeedbackVaryings_t mgl_glTransformFeedbackVaryings = NULL;
GLAPI mgl_glGetTransformFeedbackVarying_t mgl_glGetTransformFeedbackVarying = NULL;
GLAPI mgl_glClampColor_t mgl_glClampColor = NULL;
GLAPI mgl_glBeginConditionalRender_t mgl_glBeginConditionalRender = NULL;
GLAPI mgl_glEndConditionalRender_t mgl_glEndConditionalRender = NULL;
GLAPI mgl_glVertexAttribIPointer_t mgl_glVertexAttribIPointer = NULL;
GLAPI mgl_glGetVertexAttribIiv_t mgl_glGetVertexAttribIiv = NULL;
GLAPI mgl_glGetVertexAttribIuiv_t mgl_glGetVertexAttribIuiv = NULL;
GLAPI mgl_glVertexAttribI1i_t mgl_glVertexAttribI1i = NULL;
GLAPI mgl_glVertexAttribI2i_t mgl_glVertexAttribI2i = NULL;
GLAPI mgl_glVertexAttribI3i_t mgl_glVertexAttribI3i = NULL;
GLAPI mgl_glVertexAttribI4i_t mgl_glVertexAttribI4i = NULL;
GLAPI mgl_glVertexAttribI1ui_t mgl_glVertexAttribI1ui = NULL;
GLAPI mgl_glVertexAttribI2ui_t mgl_glVertexAttribI2ui = NULL;
GLAPI mgl_glVertexAttribI3ui_t mgl_glVertexAttribI3ui = NULL;
GLAPI mgl_glVertexAttribI4ui_t mgl_glVertexAttribI4ui = NULL;
GLAPI mgl_glVertexAttribI1iv_t mgl_glVertexAttribI1iv = NULL;
GLAPI mgl_glVertexAttribI2iv_t mgl_glVertexAttribI2iv = NULL;
GLAPI mgl_glVertexAttribI3iv_t mgl_glVertexAttribI3iv = NULL;
GLAPI mgl_glVertexAttribI4iv_t mgl_glVertexAttribI4iv = NULL;
GLAPI mgl_glVertexAttribI1uiv_t mgl_glVertexAttribI1uiv = NULL;
GLAPI mgl_glVertexAttribI2uiv_t mgl_glVertexAttribI2uiv = NULL;
GLAPI mgl_glVertexAttribI3uiv_t mgl_glVertexAttribI3uiv = NULL;
GLAPI mgl_glVertexAttribI4uiv_t mgl_glVertexAttribI4uiv = NULL;
GLAPI mgl_glVertexAttribI4bv_t mgl_glVertexAttribI4bv = NULL;
GLAPI mgl_glVertexAttribI4sv_t mgl_glVertexAttribI4sv = NULL;
GLAPI mgl_glVertexAttribI4ubv_t mgl_glVertexAttribI4ubv = NULL;
GLAPI mgl_glVertexAttribI4usv_t mgl_glVertexAttribI4usv = NULL;
GLAPI mgl_glGetUniformuiv_t mgl_glGetUniformuiv = NULL;
GLAPI mgl_glBindFragDataLocation_t mgl_glBindFragDataLocation = NULL;
GLAPI mgl_glGetFragDataLocation_t mgl_glGetFragDataLocation = NULL;
GLAPI mgl_glUniform1ui_t mgl_glUniform1ui = NULL;
GLAPI mgl_glUniform2ui_t mgl_glUniform2ui = NULL;
GLAPI mgl_glUniform3ui_t mgl_glUniform3ui = NULL;
GLAPI mgl_glUniform4ui_t mgl_glUniform4ui = NULL;
GLAPI mgl_glUniform1uiv_t mgl_glUniform1uiv = NULL;
GLAPI mgl_glUniform2uiv_t mgl_glUniform2uiv = NULL;
GLAPI mgl_glUniform3uiv_t mgl_glUniform3uiv = NULL;
GLAPI mgl_glUniform4uiv_t mgl_glUniform4uiv = NULL;
GLAPI mgl_glTexParameterIiv_t mgl_glTexParameterIiv = NULL;
GLAPI mgl_glTexParameterIuiv_t mgl_glTexParameterIuiv = NULL;
GLAPI mgl_glGetTexParameterIiv_t mgl_glGetTexParameterIiv = NULL;
GLAPI mgl_glGetTexParameterIuiv_t mgl_glGetTexParameterIuiv = NULL;
GLAPI mgl_glClearBufferiv_t mgl_glClearBufferiv = NULL;
GLAPI mgl_glClearBufferuiv_t mgl_glClearBufferuiv = NULL;
GLAPI mgl_glClearBufferfv_t mgl_glClearBufferfv = NULL;
GLAPI mgl_glClearBufferfi_t mgl_glClearBufferfi = NULL;
GLAPI mgl_glGetStringi_t mgl_glGetStringi = NULL;
GLAPI mgl_glIsRenderbuffer_t mgl_glIsRenderbuffer = NULL;
GLAPI mgl_glBindRenderbuffer_t mgl_glBindRenderbuffer = NULL;
GLAPI mgl_glDeleteRenderbuffers_t mgl_glDeleteRenderbuffers = NULL;
GLAPI mgl_glGenRenderbuffers_t mgl_glGenRenderbuffers = NULL;
GLAPI mgl_glRenderbufferStorage_t mgl_glRenderbufferStorage = NULL;
GLAPI mgl_glGetRenderbufferParameteriv_t mgl_glGetRenderbufferParameteriv = NULL;
GLAPI mgl_glIsFramebuffer_t mgl_glIsFramebuffer = NULL;
GLAPI mgl_glBindFramebuffer_t mgl_glBindFramebuffer = NULL;
GLAPI mgl_glDeleteFramebuffers_t mgl_glDeleteFramebuffers = NULL;
GLAPI mgl_glGenFramebuffers_t mgl_glGenFramebuffers = NULL;
GLAPI mgl_glCheckFramebufferStatus_t mgl_glCheckFramebufferStatus = NULL;
GLAPI mgl_glFramebufferTexture1D_t mgl_glFramebufferTexture1D = NULL;
GLAPI mgl_glFramebufferTexture2D_t mgl_glFramebufferTexture2D = NULL;
GLAPI mgl_glFramebufferTexture3D_t mgl_glFramebufferTexture3D = NULL;
GLAPI mgl_glFramebufferRenderbuffer_t mgl_glFramebufferRenderbuffer = NULL;
GLAPI mgl_glGetFramebufferAttachmentParameteriv_t mgl_glGetFramebufferAttachmentParameteriv = NULL;
GLAPI mgl_glGenerateMipmap_t mgl_glGenerateMipmap = NULL;
GLAPI mgl_glBlitFramebuffer_t mgl_glBlitFramebuffer = NULL;
GLAPI mgl_glRenderbufferStorageMultisample_t mgl_glRenderbufferStorageMultisample = NULL;
GLAPI mgl_glFramebufferTextureLayer_t mgl_glFramebufferTextureLayer = NULL;
GLAPI mgl_glMapBufferRange_t mgl_glMapBufferRange = NULL;
GLAPI mgl_glFlushMappedBufferRange_t mgl_glFlushMappedBufferRange = NULL;
GLAPI mgl_glBindVertexArray_t mgl_glBindVertexArray = NULL;
GLAPI mgl_glDeleteVertexArrays_t mgl_glDeleteVertexArrays = NULL;
GLAPI mgl_glGenVertexArrays_t mgl_glGenVertexArrays = NULL;
GLAPI mgl_glIsVertexArray_t mgl_glIsVertexArray = NULL;
GLAPI mgl_glDrawArraysInstanced_t mgl_glDrawArraysInstanced = NULL;
GLAPI mgl_glDrawElementsInstanced_t mgl_glDrawElementsInstanced = NULL;
GLAPI mgl_glTexBuffer_t mgl_glTexBuffer = NULL;
GLAPI mgl_glPrimitiveRestartIndex_t mgl_glPrimitiveRestartIndex = NULL;
GLAPI mgl_glCopyBufferSubData_t mgl_glCopyBufferSubData = NULL;
GLAPI mgl_glGetUniformIndices_t mgl_glGetUniformIndices = NULL;
GLAPI mgl_glGetActiveUniformsiv_t mgl_glGetActiveUniformsiv = NULL;
GLAPI mgl_glGetActiveUniformName_t mgl_glGetActiveUniformName = NULL;
GLAPI mgl_glGetUniformBlockIndex_t mgl_glGetUniformBlockIndex = NULL;
GLAPI mgl_glGetActiveUniformBlockiv_t mgl_glGetActiveUniformBlockiv = NULL;
GLAPI mgl_glGetActiveUniformBlockName_t mgl_glGetActiveUniformBlockName = NULL;
GLAPI mgl_glUniformBlockBinding_t mgl_glUniformBlockBinding = NULL;
GLAPI mgl_glDrawElementsBaseVertex_t mgl_glDrawElementsBaseVertex = NULL;
GLAPI mgl_glDrawRangeElementsBaseVertex_t mgl_glDrawRangeElementsBaseVertex = NULL;
GLAPI mgl_glDrawElementsInstancedBaseVertex_t mgl_glDrawElementsInstancedBaseVertex = NULL;
GLAPI mgl_glMultiDrawElementsBaseVertex_t mgl_glMultiDrawElementsBaseVertex = NULL;
GLAPI mgl_glProvokingVertex_t mgl_glProvokingVertex = NULL;
GLAPI mgl_glFenceSync_t mgl_glFenceSync = NULL;
GLAPI mgl_glIsSync_t mgl_glIsSync = NULL;
GLAPI mgl_glDeleteSync_t mgl_glDeleteSync = NULL;
GLAPI mgl_glClientWaitSync_t mgl_glClientWaitSync = NULL;
GLAPI mgl_glWaitSync_t mgl_glWaitSync = NULL;
GLAPI mgl_glGetInteger64v_t mgl_glGetInteger64v = NULL;
GLAPI mgl_glGetSynciv_t mgl_glGetSynciv = NULL;
GLAPI mgl_glGetInteger64i_v_t mgl_glGetInteger64i_v = NULL;
GLAPI mgl_glGetBufferParameteri64v_t mgl_glGetBufferParameteri64v = NULL;
GLAPI mgl_glFramebufferTexture_t mgl_glFramebufferTexture = NULL;
GLAPI mgl_glTexImage2DMultisample_t mgl_glTexImage2DMultisample = NULL;
GLAPI mgl_glTexImage3DMultisample_t mgl_glTexImage3DMultisample = NULL;
GLAPI mgl_glGetMultisamplefv_t mgl_glGetMultisamplefv = NULL;
GLAPI mgl_glSampleMaski_t mgl_glSampleMaski = NULL;
GLAPI mgl_glBindFragDataLocationIndexed_t mgl_glBindFragDataLocationIndexed = NULL;
GLAPI mgl_glGetFragDataIndex_t mgl_glGetFragDataIndex = NULL;
GLAPI mgl_glGenSamplers_t mgl_glGenSamplers = NULL;
GLAPI mgl_glDeleteSamplers_t mgl_glDeleteSamplers = NULL;
GLAPI mgl_glIsSampler_t mgl_glIsSampler = NULL;
GLAPI mgl_glBindSampler_t mgl_glBindSampler = NULL;
GLAPI mgl_glSamplerParameteri_t mgl_glSamplerParameteri = NULL;
GLAPI mgl_glSamplerParameteriv_t mgl_glSamplerParameteriv = NULL;
GLAPI mgl_glSamplerParameterf_t mgl_glSamplerParameterf = NULL;
GLAPI mgl_glSamplerParameterfv_t mgl_glSamplerParameterfv = NULL;
GLAPI mgl_glSamplerParameterIiv_t mgl_glSamplerParameterIiv = NULL;
GLAPI mgl_glSamplerParameterIuiv_t mgl_glSamplerParameterIuiv = NULL;
GLAPI mgl_glGetSamplerParameteriv_t mgl_glGetSamplerParameteriv = NULL;
GLAPI mgl_glGetSamplerParameterIiv_t mgl_glGetSamplerParameterIiv = NULL;
GLAPI mgl_glGetSamplerParameterfv_t mgl_glGetSamplerParameterfv = NULL;
GLAPI mgl_glGetSamplerParameterIuiv_t mgl_glGetSamplerParameterIuiv = NULL;
GLAPI mgl_glQueryCounter_t mgl_glQueryCounter = NULL;
GLAPI mgl_glGetQueryObjecti64v_t mgl_glGetQueryObjecti64v = NULL;
GLAPI mgl_glGetQueryObjectui64v_t mgl_glGetQueryObjectui64v = NULL;
GLAPI mgl_glVertexAttribDivisor_t mgl_glVertexAttribDivisor = NULL;
GLAPI mgl_glVertexAttribP1ui_t mgl_glVertexAttribP1ui = NULL;
GLAPI mgl_glVertexAttribP1uiv_t mgl_glVertexAttribP1uiv = NULL;
GLAPI mgl_glVertexAttribP2ui_t mgl_glVertexAttribP2ui = NULL;
GLAPI mgl_glVertexAttribP2uiv_t mgl_glVertexAttribP2uiv = NULL;
GLAPI mgl_glVertexAttribP3ui_t mgl_glVertexAttribP3ui = NULL;
GLAPI mgl_glVertexAttribP3uiv_t mgl_glVertexAttribP3uiv = NULL;
GLAPI mgl_glVertexAttribP4ui_t mgl_glVertexAttribP4ui = NULL;
GLAPI mgl_glVertexAttribP4uiv_t mgl_glVertexAttribP4uiv = NULL;
GLAPI mgl_glMinSampleShading_t mgl_glMinSampleShading = NULL;
GLAPI mgl_glBlendEquationi_t mgl_glBlendEquationi = NULL;
GLAPI mgl_glBlendEquationSeparatei_t mgl_glBlendEquationSeparatei = NULL;
GLAPI mgl_glBlendFunci_t mgl_glBlendFunci = NULL;
GLAPI mgl_glBlendFuncSeparatei_t mgl_glBlendFuncSeparatei = NULL;
GLAPI mgl_glDrawArraysIndirect_t mgl_glDrawArraysIndirect = NULL;
GLAPI mgl_glDrawElementsIndirect_t mgl_glDrawElementsIndirect = NULL;
GLAPI mgl_glUniform1d_t mgl_glUniform1d = NULL;
GLAPI mgl_glUniform2d_t mgl_glUniform2d = NULL;
GLAPI mgl_glUniform3d_t mgl_glUniform3d = NULL;
GLAPI mgl_glUniform4d_t mgl_glUniform4d = NULL;
GLAPI mgl_glUniform1dv_t mgl_glUniform1dv = NULL;
GLAPI mgl_glUniform2dv_t mgl_glUniform2dv = NULL;
GLAPI mgl_glUniform3dv_t mgl_glUniform3dv = NULL;
GLAPI mgl_glUniform4dv_t mgl_glUniform4dv = NULL;
GLAPI mgl_glUniformMatrix2dv_t mgl_glUniformMatrix2dv = NULL;
GLAPI mgl_glUniformMatrix3dv_t mgl_glUniformMatrix3dv = NULL;
GLAPI mgl_glUniformMatrix4dv_t mgl_glUniformMatrix4dv = NULL;
GLAPI mgl_glUniformMatrix2x3dv_t mgl_glUniformMatrix2x3dv = NULL;
GLAPI mgl_glUniformMatrix2x4dv_t mgl_glUniformMatrix2x4dv = NULL;
GLAPI mgl_glUniformMatrix3x2dv_t mgl_glUniformMatrix3x2dv = NULL;
GLAPI mgl_glUniformMatrix3x4dv_t mgl_glUniformMatrix3x4dv = NULL;
GLAPI mgl_glUniformMatrix4x2dv_t mgl_glUniformMatrix4x2dv = NULL;
GLAPI mgl_glUniformMatrix4x3dv_t mgl_glUniformMatrix4x3dv = NULL;
GLAPI mgl_glGetUniformdv_t mgl_glGetUniformdv = NULL;
GLAPI mgl_glGetSubroutineUniformLocation_t mgl_glGetSubroutineUniformLocation = NULL;
GLAPI mgl_glGetSubroutineIndex_t mgl_glGetSubroutineIndex = NULL;
GLAPI mgl_glGetActiveSubroutineUniformiv_t mgl_glGetActiveSubroutineUniformiv = NULL;
GLAPI mgl_glGetActiveSubroutineUniformName_t mgl_glGetActiveSubroutineUniformName = NULL;
GLAPI mgl_glGetActiveSubroutineName_t mgl_glGetActiveSubroutineName = NULL;
GLAPI mgl_glUniformSubroutinesuiv_t mgl_glUniformSubroutinesuiv = NULL;
GLAPI mgl_glGetUniformSubroutineuiv_t mgl_glGetUniformSubroutineuiv = NULL;
GLAPI mgl_glGetProgramStageiv_t mgl_glGetProgramStageiv = NULL;
GLAPI mgl_glPatchParameteri_t mgl_glPatchParameteri = NULL;
GLAPI mgl_glPatchParameterfv_t mgl_glPatchParameterfv = NULL;
GLAPI mgl_glBindTransformFeedback_t mgl_glBindTransformFeedback = NULL;
GLAPI mgl_glDeleteTransformFeedbacks_t mgl_glDeleteTransformFeedbacks = NULL;
GLAPI mgl_glGenTransformFeedbacks_t mgl_glGenTransformFeedbacks = NULL;
GLAPI mgl_glIsTransformFeedback_t mgl_glIsTransformFeedback = NULL;
GLAPI mgl_glPauseTransformFeedback_t mgl_glPauseTransformFeedback = NULL;
GLAPI mgl_glResumeTransformFeedback_t mgl_glResumeTransformFeedback = NULL;
GLAPI mgl_glDrawTransformFeedback_t mgl_glDrawTransformFeedback = NULL;
GLAPI mgl_glDrawTransformFeedbackStream_t mgl_glDrawTransformFeedbackStream = NULL;
GLAPI mgl_glBeginQueryIndexed_t mgl_glBeginQueryIndexed = NULL;
GLAPI mgl_glEndQueryIndexed_t mgl_glEndQueryIndexed = NULL;
GLAPI mgl_glGetQueryIndexediv_t mgl_glGetQueryIndexediv = NULL;
GLAPI mgl_glReleaseShaderCompiler_t mgl_glReleaseShaderCompiler = NULL;
GLAPI mgl_glShaderBinary_t mgl_glShaderBinary = NULL;
GLAPI mgl_glGetShaderPrecisionFormat_t mgl_glGetShaderPrecisionFormat = NULL;
GLAPI mgl_glDepthRangef_t mgl_glDepthRangef = NULL;
GLAPI mgl_glClearDepthf_t mgl_glClearDepthf = NULL;
GLAPI mgl_glGetProgramBinary_t mgl_glGetProgramBinary = NULL;
GLAPI mgl_glProgramBinary_t mgl_glProgramBinary = NULL;
GLAPI mgl_glProgramParameteri_t mgl_glProgramParameteri = NULL;
GLAPI mgl_glUseProgramStages_t mgl_glUseProgramStages = NULL;
GLAPI mgl_glActiveShaderProgram_t mgl_glActiveShaderProgram = NULL;
GLAPI mgl_glCreateShaderProgramv_t mgl_glCreateShaderProgramv = NULL;
GLAPI mgl_glBindProgramPipeline_t mgl_glBindProgramPipeline = NULL;
GLAPI mgl_glDeleteProgramPipelines_t mgl_glDeleteProgramPipelines = NULL;
GLAPI mgl_glGenProgramPipelines_t mgl_glGenProgramPipelines = NULL;
GLAPI mgl_glIsProgramPipeline_t mgl_glIsProgramPipeline = NULL;
GLAPI mgl_glGetProgramPipelineiv_t mgl_glGetProgramPipelineiv = NULL;
GLAPI mgl_glProgramUniform1i_t mgl_glProgramUniform1i = NULL;
GLAPI mgl_glProgramUniform1iv_t mgl_glProgramUniform1iv = NULL;
GLAPI mgl_glProgramUniform1f_t mgl_glProgramUniform1f = NULL;
GLAPI mgl_glProgramUniform1fv_t mgl_glProgramUniform1fv = NULL;
GLAPI mgl_glProgramUniform1d_t mgl_glProgramUniform1d = NULL;
GLAPI mgl_glProgramUniform1dv_t mgl_glProgramUniform1dv = NULL;
GLAPI mgl_glProgramUniform1ui_t mgl_glProgramUniform1ui = NULL;
GLAPI mgl_glProgramUniform1uiv_t mgl_glProgramUniform1uiv = NULL;
GLAPI mgl_glProgramUniform2i_t mgl_glProgramUniform2i = NULL;
GLAPI mgl_glProgramUniform2iv_t mgl_glProgramUniform2iv = NULL;
GLAPI mgl_glProgramUniform2f_t mgl_glProgramUniform2f = NULL;
GLAPI mgl_glProgramUniform2fv_t mgl_glProgramUniform2fv = NULL;
GLAPI mgl_glProgramUniform2d_t mgl_glProgramUniform2d = NULL;
GLAPI mgl_glProgramUniform2dv_t mgl_glProgramUniform2dv = NULL;
GLAPI mgl_glProgramUniform2ui_t mgl_glProgramUniform2ui = NULL;
GLAPI mgl_glProgramUniform2uiv_t mgl_glProgramUniform2uiv = NULL;
GLAPI mgl_glProgramUniform3i_t mgl_glProgramUniform3i = NULL;
GLAPI mgl_glProgramUniform3iv_t mgl_glProgramUniform3iv = NULL;
GLAPI mgl_glProgramUniform3f_t mgl_glProgramUniform3f = NULL;
GLAPI mgl_glProgramUniform3fv_t mgl_glProgramUniform3fv = NULL;
GLAPI mgl_glProgramUniform3d_t mgl_glProgramUniform3d = NULL;
GLAPI mgl_glProgramUniform3dv_t mgl_glProgramUniform3dv = NULL;
GLAPI mgl_glProgramUniform3ui_t mgl_glProgramUniform3ui = NULL;
GLAPI mgl_glProgramUniform3uiv_t mgl_glProgramUniform3uiv = NULL;
GLAPI mgl_glProgramUniform4i_t mgl_glProgramUniform4i = NULL;
GLAPI mgl_glProgramUniform4iv_t mgl_glProgramUniform4iv = NULL;
GLAPI mgl_glProgramUniform4f_t mgl_glProgramUniform4f = NULL;
GLAPI mgl_glProgramUniform4fv_t mgl_glProgramUniform4fv = NULL;
GLAPI mgl_glProgramUniform4d_t mgl_glProgramUniform4d = NULL;
GLAPI mgl_glProgramUniform4dv_t mgl_glProgramUniform4dv = NULL;
GLAPI mgl_glProgramUniform4ui_t mgl_glProgramUniform4ui = NULL;
GLAPI mgl_glProgramUniform4uiv_t mgl_glProgramUniform4uiv = NULL;
GLAPI mgl_glProgramUniformMatrix2fv_t mgl_glProgramUniformMatrix2fv = NULL;
GLAPI mgl_glProgramUniformMatrix3fv_t mgl_glProgramUniformMatrix3fv = NULL;
GLAPI mgl_glProgramUniformMatrix4fv_t mgl_glProgramUniformMatrix4fv = NULL;
GLAPI mgl_glProgramUniformMatrix2dv_t mgl_glProgramUniformMatrix2dv = NULL;
GLAPI mgl_glProgramUniformMatrix3dv_t mgl_glProgramUniformMatrix3dv = NULL;
GLAPI mgl_glProgramUniformMatrix4dv_t mgl_glProgramUniformMatrix4dv = NULL;
GLAPI mgl_glProgramUniformMatrix2x3fv_t mgl_glProgramUniformMatrix2x3fv = NULL;
GLAPI mgl_glProgramUniformMatrix3x2fv_t mgl_glProgramUniformMatrix3x2fv = NULL;
GLAPI mgl_glProgramUniformMatrix2x4fv_t mgl_glProgramUniformMatrix2x4fv = NULL;
GLAPI mgl_glProgramUniformMatrix4x2fv_t mgl_glProgramUniformMatrix4x2fv = NULL;
GLAPI mgl_glProgramUniformMatrix3x4fv_t mgl_glProgramUniformMatrix3x4fv = NULL;
GLAPI mgl_glProgramUniformMatrix4x3fv_t mgl_glProgramUniformMatrix4x3fv = NULL;
GLAPI mgl_glProgramUniformMatrix2x3dv_t mgl_glProgramUniformMatrix2x3dv = NULL;
GLAPI mgl_glProgramUniformMatrix3x2dv_t mgl_glProgramUniformMatrix3x2dv = NULL;
GLAPI mgl_glProgramUniformMatrix2x4dv_t mgl_glProgramUniformMatrix2x4dv = NULL;
GLAPI mgl_glProgramUniformMatrix4x2dv_t mgl_glProgramUniformMatrix4x2dv = NULL;
GLAPI mgl_glProgramUniformMatrix3x4dv_t mgl_glProgramUniformMatrix3x4dv = NULL;
GLAPI mgl_glProgramUniformMatrix4x3dv_t mgl_glProgramUniformMatrix4x3dv = NULL;
GLAPI mgl_glValidateProgramPipeline_t mgl_glValidateProgramPipeline = NULL;
GLAPI mgl_glGetProgramPipelineInfoLog_t mgl_glGetProgramPipelineInfoLog = NULL;
GLAPI mgl_glVertexAttribL1d_t mgl_glVertexAttribL1d = NULL;
GLAPI mgl_glVertexAttribL2d_t mgl_glVertexAttribL2d = NULL;
GLAPI mgl_glVertexAttribL3d_t mgl_glVertexAttribL3d = NULL;
GLAPI mgl_glVertexAttribL4d_t mgl_glVertexAttribL4d = NULL;
GLAPI mgl_glVertexAttribL1dv_t mgl_glVertexAttribL1dv = NULL;
GLAPI mgl_glVertexAttribL2dv_t mgl_glVertexAttribL2dv = NULL;
GLAPI mgl_glVertexAttribL3dv_t mgl_glVertexAttribL3dv = NULL;
GLAPI mgl_glVertexAttribL4dv_t mgl_glVertexAttribL4dv = NULL;
GLAPI mgl_glVertexAttribLPointer_t mgl_glVertexAttribLPointer = NULL;
GLAPI mgl_glGetVertexAttribLdv_t mgl_glGetVertexAttribLdv = NULL;
GLAPI mgl_glViewportArrayv_t mgl_glViewportArrayv = NULL;
GLAPI mgl_glViewportIndexedf_t mgl_glViewportIndexedf = NULL;
GLAPI mgl_glViewportIndexedfv_t mgl_glViewportIndexedfv = NULL;
GLAPI mgl_glScissorArrayv_t mgl_glScissorArrayv = NULL;
GLAPI mgl_glScissorIndexed_t mgl_glScissorIndexed = NULL;
GLAPI mgl_glScissorIndexedv_t mgl_glScissorIndexedv = NULL;
GLAPI mgl_glDepthRangeArrayv_t mgl_glDepthRangeArrayv = NULL;
GLAPI mgl_glDepthRangeIndexed_t mgl_glDepthRangeIndexed = NULL;
GLAPI mgl_glGetFloati_v_t mgl_glGetFloati_v = NULL;
GLAPI mgl_glGetDoublei_v_t mgl_glGetDoublei_v = NULL;
GLAPI mgl_glDrawArraysInstancedBaseInstance_t mgl_glDrawArraysInstancedBaseInstance = NULL;
GLAPI mgl_glDrawElementsInstancedBaseInstance_t mgl_glDrawElementsInstancedBaseInstance = NULL;
GLAPI mgl_glDrawElementsInstancedBaseVertexBaseInstance_t mgl_glDrawElementsInstancedBaseVertexBaseInstance = NULL;
GLAPI mgl_glGetInternalformativ_t mgl_glGetInternalformativ = NULL;
GLAPI mgl_glGetActiveAtomicCounterBufferiv_t mgl_glGetActiveAtomicCounterBufferiv = NULL;
GLAPI mgl_glBindImageTexture_t mgl_glBindImageTexture = NULL;
GLAPI mgl_glMemoryBarrier_t mgl_glMemoryBarrier = NULL;
GLAPI mgl_glTexStorage1D_t mgl_glTexStorage1D = NULL;
GLAPI mgl_glTexStorage2D_t mgl_glTexStorage2D = NULL;
GLAPI mgl_glTexStorage3D_t mgl_glTexStorage3D = NULL;
GLAPI mgl_glDrawTransformFeedbackInstanced_t mgl_glDrawTransformFeedbackInstanced = NULL;
GLAPI mgl_glDrawTransformFeedbackStreamInstanced_t mgl_glDrawTransformFeedbackStreamInstanced = NULL;
GLAPI mgl_glClearBufferData_t mgl_glClearBufferData = NULL;
GLAPI mgl_glClearBufferSubData_t mgl_glClearBufferSubData = NULL;
GLAPI mgl_glDispatchCompute_t mgl_glDispatchCompute = NULL;
GLAPI mgl_glDispatchComputeIndirect_t mgl_glDispatchComputeIndirect = NULL;
GLAPI mgl_glCopyImageSubData_t mgl_glCopyImageSubData = NULL;
GLAPI mgl_glFramebufferParameteri_t mgl_glFramebufferParameteri = NULL;
GLAPI mgl_glGetFramebufferParameteriv_t mgl_glGetFramebufferParameteriv = NULL;
GLAPI mgl_glGetInternalformati64v_t mgl_glGetInternalformati64v = NULL;
GLAPI mgl_glInvalidateTexSubImage_t mgl_glInvalidateTexSubImage = NULL;
GLAPI mgl_glInvalidateTexImage_t mgl_glInvalidateTexImage = NULL;
GLAPI mgl_glInvalidateBufferSubData_t mgl_glInvalidateBufferSubData = NULL;
GLAPI mgl_glInvalidateBufferData_t mgl_glInvalidateBufferData = NULL;
GLAPI mgl_glInvalidateFramebuffer_t mgl_glInvalidateFramebuffer = NULL;
GLAPI mgl_glInvalidateSubFramebuffer_t mgl_glInvalidateSubFramebuffer = NULL;
GLAPI mgl_glMultiDrawArraysIndirect_t mgl_glMultiDrawArraysIndirect = NULL;
GLAPI mgl_glMultiDrawElementsIndirect_t mgl_glMultiDrawElementsIndirect = NULL;
GLAPI mgl_glGetProgramInterfaceiv_t mgl_glGetProgramInterfaceiv = NULL;
GLAPI mgl_glGetProgramResourceIndex_t mgl_glGetProgramResourceIndex = NULL;
GLAPI mgl_glGetProgramResourceName_t mgl_glGetProgramResourceName = NULL;
GLAPI mgl_glGetProgramResourceiv_t mgl_glGetProgramResourceiv = NULL;
GLAPI mgl_glGetProgramResourceLocation_t mgl_glGetProgramResourceLocation = NULL;
GLAPI mgl_glGetProgramResourceLocationIndex_t mgl_glGetProgramResourceLocationIndex = NULL;
GLAPI mgl_glShaderStorageBlockBinding_t mgl_glShaderStorageBlockBinding = NULL;
GLAPI mgl_glTexBufferRange_t mgl_glTexBufferRange = NULL;
GLAPI mgl_glTexStorage2DMultisample_t mgl_glTexStorage2DMultisample = NULL;
GLAPI mgl_glTexStorage3DMultisample_t mgl_glTexStorage3DMultisample = NULL;
GLAPI mgl_glTextureView_t mgl_glTextureView = NULL;
GLAPI mgl_glBindVertexBuffer_t mgl_glBindVertexBuffer = NULL;
GLAPI mgl_glVertexAttribFormat_t mgl_glVertexAttribFormat = NULL;
GLAPI mgl_glVertexAttribIFormat_t mgl_glVertexAttribIFormat = NULL;
GLAPI mgl_glVertexAttribLFormat_t mgl_glVertexAttribLFormat = NULL;
GLAPI mgl_glVertexAttribBinding_t mgl_glVertexAttribBinding = NULL;
GLAPI mgl_glVertexBindingDivisor_t mgl_glVertexBindingDivisor = NULL;
GLAPI mgl_glDebugMessageControl_t mgl_glDebugMessageControl = NULL;
GLAPI mgl_glDebugMessageInsert_t mgl_glDebugMessageInsert = NULL;
GLAPI mgl_glDebugMessageCallback_t mgl_glDebugMessageCallback = NULL;
GLAPI mgl_glGetDebugMessageLog_t mgl_glGetDebugMessageLog = NULL;
GLAPI mgl_glPushDebugGroup_t mgl_glPushDebugGroup = NULL;
GLAPI mgl_glPopDebugGroup_t mgl_glPopDebugGroup = NULL;
GLAPI mgl_glObjectLabel_t mgl_glObjectLabel = NULL;
GLAPI mgl_glGetObjectLabel_t mgl_glGetObjectLabel = NULL;
GLAPI mgl_glObjectPtrLabel_t mgl_glObjectPtrLabel = NULL;
GLAPI mgl_glGetObjectPtrLabel_t mgl_glGetObjectPtrLabel = NULL;
GLAPI mgl_glBufferStorage_t mgl_glBufferStorage = NULL;
GLAPI mgl_glClearTexImage_t mgl_glClearTexImage = NULL;
GLAPI mgl_glClearTexSubImage_t mgl_glClearTexSubImage = NULL;
GLAPI mgl_glBindBuffersBase_t mgl_glBindBuffersBase = NULL;
GLAPI mgl_glBindBuffersRange_t mgl_glBindBuffersRange = NULL;
GLAPI mgl_glBindTextures_t mgl_glBindTextures = NULL;
GLAPI mgl_glBindSamplers_t mgl_glBindSamplers = NULL;
GLAPI mgl_glBindImageTextures_t mgl_glBindImageTextures = NULL;
GLAPI mgl_glBindVertexBuffers_t mgl_glBindVertexBuffers = NULL;
GLAPI mgl_glClipControl_t mgl_glClipControl = NULL;
GLAPI mgl_glCreateTransformFeedbacks_t mgl_glCreateTransformFeedbacks = NULL;
GLAPI mgl_glTransformFeedbackBufferBase_t mgl_glTransformFeedbackBufferBase = NULL;
GLAPI mgl_glTransformFeedbackBufferRange_t mgl_glTransformFeedbackBufferRange = NULL;
GLAPI mgl_glGetTransformFeedbackiv_t mgl_glGetTransformFeedbackiv = NULL;
GLAPI mgl_glGetTransformFeedbacki_v_t mgl_glGetTransformFeedbacki_v = NULL;
GLAPI mgl_glGetTransformFeedbacki64_v_t mgl_glGetTransformFeedbacki64_v = NULL;
GLAPI mgl_glCreateBuffers_t mgl_glCreateBuffers = NULL;
GLAPI mgl_glNamedBufferStorage_t mgl_glNamedBufferStorage = NULL;
GLAPI mgl_glNamedBufferData_t mgl_glNamedBufferData = NULL;
GLAPI mgl_glNamedBufferSubData_t mgl_glNamedBufferSubData = NULL;
GLAPI mgl_glCopyNamedBufferSubData_t mgl_glCopyNamedBufferSubData = NULL;
GLAPI mgl_glClearNamedBufferData_t mgl_glClearNamedBufferData = NULL;
GLAPI mgl_glClearNamedBufferSubData_t mgl_glClearNamedBufferSubData = NULL;
GLAPI mgl_glMapNamedBuffer_t mgl_glMapNamedBuffer = NULL;
GLAPI mgl_glMapNamedBufferRange_t mgl_glMapNamedBufferRange = NULL;
GLAPI mgl_glUnmapNamedBuffer_t mgl_glUnmapNamedBuffer = NULL;
GLAPI mgl_glFlushMappedNamedBufferRange_t mgl_glFlushMappedNamedBufferRange = NULL;
GLAPI mgl_glGetNamedBufferParameteriv_t mgl_glGetNamedBufferParameteriv = NULL;
GLAPI mgl_glGetNamedBufferParameteri64v_t mgl_glGetNamedBufferParameteri64v = NULL;
GLAPI mgl_glGetNamedBufferPointerv_t mgl_glGetNamedBufferPointerv = NULL;
GLAPI mgl_glGetNamedBufferSubData_t mgl_glGetNamedBufferSubData = NULL;
GLAPI mgl_glCreateFramebuffers_t mgl_glCreateFramebuffers = NULL;
GLAPI mgl_glNamedFramebufferRenderbuffer_t mgl_glNamedFramebufferRenderbuffer = NULL;
GLAPI mgl_glNamedFramebufferParameteri_t mgl_glNamedFramebufferParameteri = NULL;
GLAPI mgl_glNamedFramebufferTexture_t mgl_glNamedFramebufferTexture = NULL;
GLAPI mgl_glNamedFramebufferTextureLayer_t mgl_glNamedFramebufferTextureLayer = NULL;
GLAPI mgl_glNamedFramebufferDrawBuffer_t mgl_glNamedFramebufferDrawBuffer = NULL;
GLAPI mgl_glNamedFramebufferDrawBuffers_t mgl_glNamedFramebufferDrawBuffers = NULL;
GLAPI mgl_glNamedFramebufferReadBuffer_t mgl_glNamedFramebufferReadBuffer = NULL;
GLAPI mgl_glInvalidateNamedFramebufferData_t mgl_glInvalidateNamedFramebufferData = NULL;
GLAPI mgl_glInvalidateNamedFramebufferSubData_t mgl_glInvalidateNamedFramebufferSubData = NULL;
GLAPI mgl_glClearNamedFramebufferiv_t mgl_glClearNamedFramebufferiv = NULL;
GLAPI mgl_glClearNamedFramebufferuiv_t mgl_glClearNamedFramebufferuiv = NULL;
GLAPI mgl_glClearNamedFramebufferfv_t mgl_glClearNamedFramebufferfv = NULL;
GLAPI mgl_glClearNamedFramebufferfi_t mgl_glClearNamedFramebufferfi = NULL;
GLAPI mgl_glBlitNamedFramebuffer_t mgl_glBlitNamedFramebuffer = NULL;
GLAPI mgl_glCheckNamedFramebufferStatus_t mgl_glCheckNamedFramebufferStatus = NULL;
GLAPI mgl_glGetNamedFramebufferParameteriv_t mgl_glGetNamedFramebufferParameteriv = NULL;
GLAPI mgl_glGetNamedFramebufferAttachmentParameteriv_t mgl_glGetNamedFramebufferAttachmentParameteriv = NULL;
GLAPI mgl_glCreateRenderbuffers_t mgl_glCreateRenderbuffers = NULL;
GLAPI mgl_glNamedRenderbufferStorage_t mgl_glNamedRenderbufferStorage = NULL;
GLAPI mgl_glNamedRenderbufferStorageMultisample_t mgl_glNamedRenderbufferStorageMultisample = NULL;
GLAPI mgl_glGetNamedRenderbufferParameteriv_t mgl_glGetNamedRenderbufferParameteriv = NULL;
GLAPI mgl_glCreateTextures_t mgl_glCreateTextures = NULL;
GLAPI mgl_glTextureBuffer_t mgl_glTextureBuffer = NULL;
GLAPI mgl_glTextureBufferRange_t mgl_glTextureBufferRange = NULL;
GLAPI mgl_glTextureStorage1D_t mgl_glTextureStorage1D = NULL;
GLAPI mgl_glTextureStorage2D_t mgl_glTextureStorage2D = NULL;
GLAPI mgl_glTextureStorage3D_t mgl_glTextureStorage3D = NULL;
GLAPI mgl_glTextureStorage2DMultisample_t mgl_glTextureStorage2DMultisample = NULL;
GLAPI mgl_glTextureStorage3DMultisample_t mgl_glTextureStorage3DMultisample = NULL;
GLAPI mgl_glTextureSubImage1D_t mgl_glTextureSubImage1D = NULL;
GLAPI mgl_glTextureSubImage2D_t mgl_glTextureSubImage2D = NULL;
GLAPI mgl_glTextureSubImage3D_t mgl_glTextureSubImage3D = NULL;
GLAPI mgl_glCompressedTextureSubImage1D_t mgl_glCompressedTextureSubImage1D = NULL;
GLAPI mgl_glCompressedTextureSubImage2D_t mgl_glCompressedTextureSubImage2D = NULL;
GLAPI mgl_glCompressedTextureSubImage3D_t mgl_glCompressedTextureSubImage3D = NULL;
GLAPI mgl_glCopyTextureSubImage1D_t mgl_glCopyTextureSubImage1D = NULL;
GLAPI mgl_glCopyTextureSubImage2D_t mgl_glCopyTextureSubImage2D = NULL;
GLAPI mgl_glCopyTextureSubImage3D_t mgl_glCopyTextureSubImage3D = NULL;
GLAPI mgl_glTextureParameterf_t mgl_glTextureParameterf = NULL;
GLAPI mgl_glTextureParameterfv_t mgl_glTextureParameterfv = NULL;
GLAPI mgl_glTextureParameteri_t mgl_glTextureParameteri = NULL;
GLAPI mgl_glTextureParameterIiv_t mgl_glTextureParameterIiv = NULL;
GLAPI mgl_glTextureParameterIuiv_t mgl_glTextureParameterIuiv = NULL;
GLAPI mgl_glTextureParameteriv_t mgl_glTextureParameteriv = NULL;
GLAPI mgl_glGenerateTextureMipmap_t mgl_glGenerateTextureMipmap = NULL;
GLAPI mgl_glBindTextureUnit_t mgl_glBindTextureUnit = NULL;
GLAPI mgl_glGetTextureImage_t mgl_glGetTextureImage = NULL;
GLAPI mgl_glGetCompressedTextureImage_t mgl_glGetCompressedTextureImage = NULL;
GLAPI mgl_glGetTextureLevelParameterfv_t mgl_glGetTextureLevelParameterfv = NULL;
GLAPI mgl_glGetTextureLevelParameteriv_t mgl_glGetTextureLevelParameteriv = NULL;
GLAPI mgl_glGetTextureParameterfv_t mgl_glGetTextureParameterfv = NULL;
GLAPI mgl_glGetTextureParameterIiv_t mgl_glGetTextureParameterIiv = NULL;
GLAPI mgl_glGetTextureParameterIuiv_t mgl_glGetTextureParameterIuiv = NULL;
GLAPI mgl_glGetTextureParameteriv_t mgl_glGetTextureParameteriv = NULL;
GLAPI mgl_glCreateVertexArrays_t mgl_glCreateVertexArrays = NULL;
GLAPI mgl_glDisableVertexArrayAttrib_t mgl_glDisableVertexArrayAttrib = NULL;
GLAPI mgl_glEnableVertexArrayAttrib_t mgl_glEnableVertexArrayAttrib = NULL;
GLAPI mgl_glVertexArrayElementBuffer_t mgl_glVertexArrayElementBuffer = NULL;
GLAPI mgl_glVertexArrayVertexBuffer_t mgl_glVertexArrayVertexBuffer = NULL;
GLAPI mgl_glVertexArrayVertexBuffers_t mgl_glVertexArrayVertexBuffers = NULL;
GLAPI mgl_glVertexArrayAttribBinding_t mgl_glVertexArrayAttribBinding = NULL;
GLAPI mgl_glVertexArrayAttribFormat_t mgl_glVertexArrayAttribFormat = NULL;
GLAPI mgl_glVertexArrayAttribIFormat_t mgl_glVertexArrayAttribIFormat = NULL;
GLAPI mgl_glVertexArrayAttribLFormat_t mgl_glVertexArrayAttribLFormat = NULL;
GLAPI mgl_glVertexArrayBindingDivisor_t mgl_glVertexArrayBindingDivisor = NULL;
GLAPI mgl_glGetVertexArrayiv_t mgl_glGetVertexArrayiv = NULL;
GLAPI mgl_glGetVertexArrayIndexediv_t mgl_glGetVertexArrayIndexediv = NULL;
GLAPI mgl_glGetVertexArrayIndexed64iv_t mgl_glGetVertexArrayIndexed64iv = NULL;
GLAPI mgl_glCreateSamplers_t mgl_glCreateSamplers = NULL;
GLAPI mgl_glCreateProgramPipelines_t mgl_glCreateProgramPipelines = NULL;
GLAPI mgl_glCreateQueries_t mgl_glCreateQueries = NULL;
GLAPI mgl_glGetQueryBufferObjecti64v_t mgl_glGetQueryBufferObjecti64v = NULL;
GLAPI mgl_glGetQueryBufferObjectiv_t mgl_glGetQueryBufferObjectiv = NULL;
GLAPI mgl_glGetQueryBufferObjectui64v_t mgl_glGetQueryBufferObjectui64v = NULL;
GLAPI mgl_glGetQueryBufferObjectuiv_t mgl_glGetQueryBufferObjectuiv = NULL;
GLAPI mgl_glMemoryBarrierByRegion_t mgl_glMemoryBarrierByRegion = NULL;
GLAPI mgl_glGetTextureSubImage_t mgl_glGetTextureSubImage = NULL;
GLAPI mgl_glGetCompressedTextureSubImage_t mgl_glGetCompressedTextureSubImage = NULL;
GLAPI mgl_glGetGraphicsResetStatus_t mgl_glGetGraphicsResetStatus = NULL;
GLAPI mgl_glGetnCompressedTexImage_t mgl_glGetnCompressedTexImage = NULL;
GLAPI mgl_glGetnTexImage_t mgl_glGetnTexImage = NULL;
GLAPI mgl_glGetnUniformdv_t mgl_glGetnUniformdv = NULL;
GLAPI mgl_glGetnUniformfv_t mgl_glGetnUniformfv = NULL;
GLAPI mgl_glGetnUniformiv_t mgl_glGetnUniformiv = NULL;
GLAPI mgl_glGetnUniformuiv_t mgl_glGetnUniformuiv = NULL;
GLAPI mgl_glReadnPixels_t mgl_glReadnPixels = NULL;
GLAPI mgl_glTextureBarrier_t mgl_glTextureBarrier = NULL;
GLAPI mgl_glSpecializeShader_t mgl_glSpecializeShader = NULL;
GLAPI mgl_glMultiDrawArraysIndirectCount_t mgl_glMultiDrawArraysIndirectCount = NULL;
GLAPI mgl_glMultiDrawElementsIndirectCount_t mgl_glMultiDrawElementsIndirectCount = NULL;
GLAPI mgl_glPolygonOffsetClamp_t mgl_glPolygonOffsetClamp = NULL;

int mglLoadGLLoader(mgl_loadProc_t load_function) {
    mgl_glCullFace = (mgl_glCullFace_t)load_function("glCullFace");
    if (mgl_glCullFace == NULL) return 0;
    mgl_glFrontFace = (mgl_glFrontFace_t)load_function("glFrontFace");
    if (mgl_glFrontFace == NULL) return 0;
    mgl_glHint = (mgl_glHint_t)load_function("glHint");
    if (mgl_glHint == NULL) return 0;
    mgl_glLineWidth = (mgl_glLineWidth_t)load_function("glLineWidth");
    if (mgl_glLineWidth == NULL) return 0;
    mgl_glPointSize = (mgl_glPointSize_t)load_function("glPointSize");
    if (mgl_glPointSize == NULL) return 0;
    mgl_glPolygonMode = (mgl_glPolygonMode_t)load_function("glPolygonMode");
    if (mgl_glPolygonMode == NULL)
        return 0;
    mgl_glScissor = (mgl_glScissor_t)load_function("glScissor");
    if (mgl_glScissor == NULL)
        return 0;
    mgl_glTexParameterf = (mgl_glTexParameterf_t)load_function("glTexParameterf");
    if (mgl_glTexParameterf == NULL)
        return 0;
    mgl_glTexParameterfv = (mgl_glTexParameterfv_t)load_function("glTexParameterfv");
    if (mgl_glTexParameterfv == NULL)
        return 0;
    mgl_glTexParameteri = (mgl_glTexParameteri_t)load_function("glTexParameteri");
    if (mgl_glTexParameteri == NULL)
        return 0;
    mgl_glTexParameteriv = (mgl_glTexParameteriv_t)load_function("glTexParameteriv");
    if (mgl_glTexParameteriv == NULL)
        return 0;
    mgl_glTexImage1D = (mgl_glTexImage1D_t)load_function("glTexImage1D");
    if (mgl_glTexImage1D == NULL)
        return 0;
    mgl_glTexImage2D = (mgl_glTexImage2D_t)load_function("glTexImage2D");
    if (mgl_glTexImage2D == NULL)
        return 0;
    mgl_glDrawBuffer = (mgl_glDrawBuffer_t)load_function("glDrawBuffer");
    if (mgl_glDrawBuffer == NULL)
        return 0;
    mgl_glClear = (mgl_glClear_t)load_function("glClear");
    if (mgl_glClear == NULL)
        return 0;
    mgl_glClearColor = (mgl_glClearColor_t)load_function("glClearColor");
    if (mgl_glClearColor == NULL)
        return 0;
    mgl_glClearStencil = (mgl_glClearStencil_t)load_function("glClearStencil");
    if (mgl_glClearStencil == NULL)
        return 0;
    mgl_glClearDepth = (mgl_glClearDepth_t)load_function("glClearDepth");
    if (mgl_glClearDepth == NULL)
        return 0;
    mgl_glStencilMask = (mgl_glStencilMask_t)load_function("glStencilMask");
    if (mgl_glStencilMask == NULL)
        return 0;
    mgl_glColorMask = (mgl_glColorMask_t)load_function("glColorMask");
    if (mgl_glColorMask == NULL)
        return 0;
    mgl_glDepthMask = (mgl_glDepthMask_t)load_function("glDepthMask");
    if (mgl_glDepthMask == NULL)
        return 0;
    mgl_glDisable = (mgl_glDisable_t)load_function("glDisable");
    if (mgl_glDisable == NULL)
        return 0;
    mgl_glEnable = (mgl_glEnable_t)load_function("glEnable");
    if (mgl_glEnable == NULL)
        return 0;
    mgl_glFinish = (mgl_glFinish_t)load_function("glFinish");
    if (mgl_glFinish == NULL)
        return 0;
    mgl_glFlush = (mgl_glFlush_t)load_function("glFlush");
    if (mgl_glFlush == NULL)
        return 0;
    mgl_glBlendFunc = (mgl_glBlendFunc_t)load_function("glBlendFunc");
    if (mgl_glBlendFunc == NULL)
        return 0;
    mgl_glLogicOp = (mgl_glLogicOp_t)load_function("glLogicOp");
    if (mgl_glLogicOp == NULL)
        return 0;
    mgl_glStencilFunc = (mgl_glStencilFunc_t)load_function("glStencilFunc");
    if (mgl_glStencilFunc == NULL)
        return 0;
    mgl_glStencilOp = (mgl_glStencilOp_t)load_function("glStencilOp");
    if (mgl_glStencilOp == NULL)
        return 0;
    mgl_glDepthFunc = (mgl_glDepthFunc_t)load_function("glDepthFunc");
    if (mgl_glDepthFunc == NULL)
        return 0;
    mgl_glPixelStoref = (mgl_glPixelStoref_t)load_function("glPixelStoref");
    if (mgl_glPixelStoref == NULL)
        return 0;
    mgl_glPixelStorei = (mgl_glPixelStorei_t)load_function("glPixelStorei");
    if (mgl_glPixelStorei == NULL)
        return 0;
    mgl_glReadBuffer = (mgl_glReadBuffer_t)load_function("glReadBuffer");
    if (mgl_glReadBuffer == NULL)
        return 0;
    mgl_glReadPixels = (mgl_glReadPixels_t)load_function("glReadPixels");
    if (mgl_glReadPixels == NULL)
        return 0;
    mgl_glGetBooleanv = (mgl_glGetBooleanv_t)load_function("glGetBooleanv");
    if (mgl_glGetBooleanv == NULL)
        return 0;
    mgl_glGetDoublev = (mgl_glGetDoublev_t)load_function("glGetDoublev");
    if (mgl_glGetDoublev == NULL)
        return 0;
    mgl_glGetError = (mgl_glGetError_t)load_function("glGetError");
    if (mgl_glGetError == NULL)
        return 0;
    mgl_glGetFloatv = (mgl_glGetFloatv_t)load_function("glGetFloatv");
    if (mgl_glGetFloatv == NULL)
        return 0;
    mgl_glGetIntegerv = (mgl_glGetIntegerv_t)load_function("glGetIntegerv");
    if (mgl_glGetIntegerv == NULL)
        return 0;
    mgl_glGetString = (mgl_glGetString_t)load_function("glGetString");
    if (mgl_glGetString == NULL)
        return 0;
    mgl_glGetTexImage = (mgl_glGetTexImage_t)load_function("glGetTexImage");
    if (mgl_glGetTexImage == NULL)
        return 0;
    mgl_glGetTexParameterfv = (mgl_glGetTexParameterfv_t)load_function("glGetTexParameterfv");
    if (mgl_glGetTexParameterfv == NULL)
        return 0;
    mgl_glGetTexParameteriv = (mgl_glGetTexParameteriv_t)load_function("glGetTexParameteriv");
    if (mgl_glGetTexParameteriv == NULL)
        return 0;
    mgl_glGetTexLevelParameterfv = (mgl_glGetTexLevelParameterfv_t)load_function("glGetTexLevelParameterfv");
    if (mgl_glGetTexLevelParameterfv == NULL)
        return 0;
    mgl_glGetTexLevelParameteriv = (mgl_glGetTexLevelParameteriv_t)load_function("glGetTexLevelParameteriv");
    if (mgl_glGetTexLevelParameteriv == NULL)
        return 0;
    mgl_glIsEnabled = (mgl_glIsEnabled_t)load_function("glIsEnabled");
    if (mgl_glIsEnabled == NULL)
        return 0;
    mgl_glDepthRange = (mgl_glDepthRange_t)load_function("glDepthRange");
    if (mgl_glDepthRange == NULL)
        return 0;
    mgl_glViewport = (mgl_glViewport_t)load_function("glViewport");
    if (mgl_glViewport == NULL)
        return 0;
    mgl_glNewList = (mgl_glNewList_t)load_function("glNewList");
    if (mgl_glNewList == NULL)
        return 0;
    mgl_glEndList = (mgl_glEndList_t)load_function("glEndList");
    if (mgl_glEndList == NULL)
        return 0;
    mgl_glCallList = (mgl_glCallList_t)load_function("glCallList");
    if (mgl_glCallList == NULL)
        return 0;
    mgl_glCallLists = (mgl_glCallLists_t)load_function("glCallLists");
    if (mgl_glCallLists == NULL)
        return 0;
    mgl_glDeleteLists = (mgl_glDeleteLists_t)load_function("glDeleteLists");
    if (mgl_glDeleteLists == NULL)
        return 0;
    mgl_glGenLists = (mgl_glGenLists_t)load_function("glGenLists");
    if (mgl_glGenLists == NULL)
        return 0;
    mgl_glListBase = (mgl_glListBase_t)load_function("glListBase");
    if (mgl_glListBase == NULL)
        return 0;
    mgl_glBegin = (mgl_glBegin_t)load_function("glBegin");
    if (mgl_glBegin == NULL)
        return 0;
    mgl_glBitmap = (mgl_glBitmap_t)load_function("glBitmap");
    if (mgl_glBitmap == NULL)
        return 0;
    mgl_glColor3b = (mgl_glColor3b_t)load_function("glColor3b");
    if (mgl_glColor3b == NULL)
        return 0;
    mgl_glColor3bv = (mgl_glColor3bv_t)load_function("glColor3bv");
    if (mgl_glColor3bv == NULL)
        return 0;
    mgl_glColor3d = (mgl_glColor3d_t)load_function("glColor3d");
    if (mgl_glColor3d == NULL)
        return 0;
    mgl_glColor3dv = (mgl_glColor3dv_t)load_function("glColor3dv");
    if (mgl_glColor3dv == NULL)
        return 0;
    mgl_glColor3f = (mgl_glColor3f_t)load_function("glColor3f");
    if (mgl_glColor3f == NULL)
        return 0;
    mgl_glColor3fv = (mgl_glColor3fv_t)load_function("glColor3fv");
    if (mgl_glColor3fv == NULL)
        return 0;
    mgl_glColor3i = (mgl_glColor3i_t)load_function("glColor3i");
    if (mgl_glColor3i == NULL)
        return 0;
    mgl_glColor3iv = (mgl_glColor3iv_t)load_function("glColor3iv");
    if (mgl_glColor3iv == NULL)
        return 0;
    mgl_glColor3s = (mgl_glColor3s_t)load_function("glColor3s");
    if (mgl_glColor3s == NULL)
        return 0;
    mgl_glColor3sv = (mgl_glColor3sv_t)load_function("glColor3sv");
    if (mgl_glColor3sv == NULL)
        return 0;
    mgl_glColor3ub = (mgl_glColor3ub_t)load_function("glColor3ub");
    if (mgl_glColor3ub == NULL)
        return 0;
    mgl_glColor3ubv = (mgl_glColor3ubv_t)load_function("glColor3ubv");
    if (mgl_glColor3ubv == NULL)
        return 0;
    mgl_glColor3ui = (mgl_glColor3ui_t)load_function("glColor3ui");
    if (mgl_glColor3ui == NULL)
        return 0;
    mgl_glColor3uiv = (mgl_glColor3uiv_t)load_function("glColor3uiv");
    if (mgl_glColor3uiv == NULL)
        return 0;
    mgl_glColor3us = (mgl_glColor3us_t)load_function("glColor3us");
    if (mgl_glColor3us == NULL)
        return 0;
    mgl_glColor3usv = (mgl_glColor3usv_t)load_function("glColor3usv");
    if (mgl_glColor3usv == NULL)
        return 0;
    mgl_glColor4b = (mgl_glColor4b_t)load_function("glColor4b");
    if (mgl_glColor4b == NULL)
        return 0;
    mgl_glColor4bv = (mgl_glColor4bv_t)load_function("glColor4bv");
    if (mgl_glColor4bv == NULL)
        return 0;
    mgl_glColor4d = (mgl_glColor4d_t)load_function("glColor4d");
    if (mgl_glColor4d == NULL)
        return 0;
    mgl_glColor4dv = (mgl_glColor4dv_t)load_function("glColor4dv");
    if (mgl_glColor4dv == NULL)
        return 0;
    mgl_glColor4f = (mgl_glColor4f_t)load_function("glColor4f");
    if (mgl_glColor4f == NULL)
        return 0;
    mgl_glColor4fv = (mgl_glColor4fv_t)load_function("glColor4fv");
    if (mgl_glColor4fv == NULL)
        return 0;
    mgl_glColor4i = (mgl_glColor4i_t)load_function("glColor4i");
    if (mgl_glColor4i == NULL)
        return 0;
    mgl_glColor4iv = (mgl_glColor4iv_t)load_function("glColor4iv");
    if (mgl_glColor4iv == NULL)
        return 0;
    mgl_glColor4s = (mgl_glColor4s_t)load_function("glColor4s");
    if (mgl_glColor4s == NULL)
        return 0;
    mgl_glColor4sv = (mgl_glColor4sv_t)load_function("glColor4sv");
    if (mgl_glColor4sv == NULL)
        return 0;
    mgl_glColor4ub = (mgl_glColor4ub_t)load_function("glColor4ub");
    if (mgl_glColor4ub == NULL)
        return 0;
    mgl_glColor4ubv = (mgl_glColor4ubv_t)load_function("glColor4ubv");
    if (mgl_glColor4ubv == NULL)
        return 0;
    mgl_glColor4ui = (mgl_glColor4ui_t)load_function("glColor4ui");
    if (mgl_glColor4ui == NULL)
        return 0;
    mgl_glColor4uiv = (mgl_glColor4uiv_t)load_function("glColor4uiv");
    if (mgl_glColor4uiv == NULL)
        return 0;
    mgl_glColor4us = (mgl_glColor4us_t)load_function("glColor4us");
    if (mgl_glColor4us == NULL)
        return 0;
    mgl_glColor4usv = (mgl_glColor4usv_t)load_function("glColor4usv");
    if (mgl_glColor4usv == NULL)
        return 0;
    mgl_glEdgeFlag = (mgl_glEdgeFlag_t)load_function("glEdgeFlag");
    if (mgl_glEdgeFlag == NULL)
        return 0;
    mgl_glEdgeFlagv = (mgl_glEdgeFlagv_t)load_function("glEdgeFlagv");
    if (mgl_glEdgeFlagv == NULL)
        return 0;
    mgl_glEnd = (mgl_glEnd_t)load_function("glEnd");
    if (mgl_glEnd == NULL)
        return 0;
    mgl_glIndexd = (mgl_glIndexd_t)load_function("glIndexd");
    if (mgl_glIndexd == NULL)
        return 0;
    mgl_glIndexdv = (mgl_glIndexdv_t)load_function("glIndexdv");
    if (mgl_glIndexdv == NULL)
        return 0;
    mgl_glIndexf = (mgl_glIndexf_t)load_function("glIndexf");
    if (mgl_glIndexf == NULL)
        return 0;
    mgl_glIndexfv = (mgl_glIndexfv_t)load_function("glIndexfv");
    if (mgl_glIndexfv == NULL)
        return 0;
    mgl_glIndexi = (mgl_glIndexi_t)load_function("glIndexi");
    if (mgl_glIndexi == NULL)
        return 0;
    mgl_glIndexiv = (mgl_glIndexiv_t)load_function("glIndexiv");
    if (mgl_glIndexiv == NULL)
        return 0;
    mgl_glIndexs = (mgl_glIndexs_t)load_function("glIndexs");
    if (mgl_glIndexs == NULL)
        return 0;
    mgl_glIndexsv = (mgl_glIndexsv_t)load_function("glIndexsv");
    if (mgl_glIndexsv == NULL)
        return 0;
    mgl_glNormal3b = (mgl_glNormal3b_t)load_function("glNormal3b");
    if (mgl_glNormal3b == NULL)
        return 0;
    mgl_glNormal3bv = (mgl_glNormal3bv_t)load_function("glNormal3bv");
    if (mgl_glNormal3bv == NULL)
        return 0;
    mgl_glNormal3d = (mgl_glNormal3d_t)load_function("glNormal3d");
    if (mgl_glNormal3d == NULL)
        return 0;
    mgl_glNormal3dv = (mgl_glNormal3dv_t)load_function("glNormal3dv");
    if (mgl_glNormal3dv == NULL)
        return 0;
    mgl_glNormal3f = (mgl_glNormal3f_t)load_function("glNormal3f");
    if (mgl_glNormal3f == NULL)
        return 0;
    mgl_glNormal3fv = (mgl_glNormal3fv_t)load_function("glNormal3fv");
    if (mgl_glNormal3fv == NULL)
        return 0;
    mgl_glNormal3i = (mgl_glNormal3i_t)load_function("glNormal3i");
    if (mgl_glNormal3i == NULL)
        return 0;
    mgl_glNormal3iv = (mgl_glNormal3iv_t)load_function("glNormal3iv");
    if (mgl_glNormal3iv == NULL)
        return 0;
    mgl_glNormal3s = (mgl_glNormal3s_t)load_function("glNormal3s");
    if (mgl_glNormal3s == NULL)
        return 0;
    mgl_glNormal3sv = (mgl_glNormal3sv_t)load_function("glNormal3sv");
    if (mgl_glNormal3sv == NULL)
        return 0;
    mgl_glRasterPos2d = (mgl_glRasterPos2d_t)load_function("glRasterPos2d");
    if (mgl_glRasterPos2d == NULL)
        return 0;
    mgl_glRasterPos2dv = (mgl_glRasterPos2dv_t)load_function("glRasterPos2dv");
    if (mgl_glRasterPos2dv == NULL)
        return 0;
    mgl_glRasterPos2f = (mgl_glRasterPos2f_t)load_function("glRasterPos2f");
    if (mgl_glRasterPos2f == NULL)
        return 0;
    mgl_glRasterPos2fv = (mgl_glRasterPos2fv_t)load_function("glRasterPos2fv");
    if (mgl_glRasterPos2fv == NULL)
        return 0;
    mgl_glRasterPos2i = (mgl_glRasterPos2i_t)load_function("glRasterPos2i");
    if (mgl_glRasterPos2i == NULL)
        return 0;
    mgl_glRasterPos2iv = (mgl_glRasterPos2iv_t)load_function("glRasterPos2iv");
    if (mgl_glRasterPos2iv == NULL)
        return 0;
    mgl_glRasterPos2s = (mgl_glRasterPos2s_t)load_function("glRasterPos2s");
    if (mgl_glRasterPos2s == NULL)
        return 0;
    mgl_glRasterPos2sv = (mgl_glRasterPos2sv_t)load_function("glRasterPos2sv");
    if (mgl_glRasterPos2sv == NULL)
        return 0;
    mgl_glRasterPos3d = (mgl_glRasterPos3d_t)load_function("glRasterPos3d");
    if (mgl_glRasterPos3d == NULL)
        return 0;
    mgl_glRasterPos3dv = (mgl_glRasterPos3dv_t)load_function("glRasterPos3dv");
    if (mgl_glRasterPos3dv == NULL)
        return 0;
    mgl_glRasterPos3f = (mgl_glRasterPos3f_t)load_function("glRasterPos3f");
    if (mgl_glRasterPos3f == NULL)
        return 0;
    mgl_glRasterPos3fv = (mgl_glRasterPos3fv_t)load_function("glRasterPos3fv");
    if (mgl_glRasterPos3fv == NULL)
        return 0;
    mgl_glRasterPos3i = (mgl_glRasterPos3i_t)load_function("glRasterPos3i");
    if (mgl_glRasterPos3i == NULL)
        return 0;
    mgl_glRasterPos3iv = (mgl_glRasterPos3iv_t)load_function("glRasterPos3iv");
    if (mgl_glRasterPos3iv == NULL)
        return 0;
    mgl_glRasterPos3s = (mgl_glRasterPos3s_t)load_function("glRasterPos3s");
    if (mgl_glRasterPos3s == NULL)
        return 0;
    mgl_glRasterPos3sv = (mgl_glRasterPos3sv_t)load_function("glRasterPos3sv");
    if (mgl_glRasterPos3sv == NULL)
        return 0;
    mgl_glRasterPos4d = (mgl_glRasterPos4d_t)load_function("glRasterPos4d");
    if (mgl_glRasterPos4d == NULL)
        return 0;
    mgl_glRasterPos4dv = (mgl_glRasterPos4dv_t)load_function("glRasterPos4dv");
    if (mgl_glRasterPos4dv == NULL)
        return 0;
    mgl_glRasterPos4f = (mgl_glRasterPos4f_t)load_function("glRasterPos4f");
    if (mgl_glRasterPos4f == NULL)
        return 0;
    mgl_glRasterPos4fv = (mgl_glRasterPos4fv_t)load_function("glRasterPos4fv");
    if (mgl_glRasterPos4fv == NULL)
        return 0;
    mgl_glRasterPos4i = (mgl_glRasterPos4i_t)load_function("glRasterPos4i");
    if (mgl_glRasterPos4i == NULL)
        return 0;
    mgl_glRasterPos4iv = (mgl_glRasterPos4iv_t)load_function("glRasterPos4iv");
    if (mgl_glRasterPos4iv == NULL)
        return 0;
    mgl_glRasterPos4s = (mgl_glRasterPos4s_t)load_function("glRasterPos4s");
    if (mgl_glRasterPos4s == NULL)
        return 0;
    mgl_glRasterPos4sv = (mgl_glRasterPos4sv_t)load_function("glRasterPos4sv");
    if (mgl_glRasterPos4sv == NULL)
        return 0;
    mgl_glRectd = (mgl_glRectd_t)load_function("glRectd");
    if (mgl_glRectd == NULL)
        return 0;
    mgl_glRectdv = (mgl_glRectdv_t)load_function("glRectdv");
    if (mgl_glRectdv == NULL)
        return 0;
    mgl_glRectf = (mgl_glRectf_t)load_function("glRectf");
    if (mgl_glRectf == NULL)
        return 0;
    mgl_glRectfv = (mgl_glRectfv_t)load_function("glRectfv");
    if (mgl_glRectfv == NULL)
        return 0;
    mgl_glRecti = (mgl_glRecti_t)load_function("glRecti");
    if (mgl_glRecti == NULL)
        return 0;
    mgl_glRectiv = (mgl_glRectiv_t)load_function("glRectiv");
    if (mgl_glRectiv == NULL)
        return 0;
    mgl_glRects = (mgl_glRects_t)load_function("glRects");
    if (mgl_glRects == NULL)
        return 0;
    mgl_glRectsv = (mgl_glRectsv_t)load_function("glRectsv");
    if (mgl_glRectsv == NULL)
        return 0;
    mgl_glTexCoord1d = (mgl_glTexCoord1d_t)load_function("glTexCoord1d");
    if (mgl_glTexCoord1d == NULL)
        return 0;
    mgl_glTexCoord1dv = (mgl_glTexCoord1dv_t)load_function("glTexCoord1dv");
    if (mgl_glTexCoord1dv == NULL)
        return 0;
    mgl_glTexCoord1f = (mgl_glTexCoord1f_t)load_function("glTexCoord1f");
    if (mgl_glTexCoord1f == NULL)
        return 0;
    mgl_glTexCoord1fv = (mgl_glTexCoord1fv_t)load_function("glTexCoord1fv");
    if (mgl_glTexCoord1fv == NULL)
        return 0;
    mgl_glTexCoord1i = (mgl_glTexCoord1i_t)load_function("glTexCoord1i");
    if (mgl_glTexCoord1i == NULL)
        return 0;
    mgl_glTexCoord1iv = (mgl_glTexCoord1iv_t)load_function("glTexCoord1iv");
    if (mgl_glTexCoord1iv == NULL)
        return 0;
    mgl_glTexCoord1s = (mgl_glTexCoord1s_t)load_function("glTexCoord1s");
    if (mgl_glTexCoord1s == NULL)
        return 0;
    mgl_glTexCoord1sv = (mgl_glTexCoord1sv_t)load_function("glTexCoord1sv");
    if (mgl_glTexCoord1sv == NULL)
        return 0;
    mgl_glTexCoord2d = (mgl_glTexCoord2d_t)load_function("glTexCoord2d");
    if (mgl_glTexCoord2d == NULL)
        return 0;
    mgl_glTexCoord2dv = (mgl_glTexCoord2dv_t)load_function("glTexCoord2dv");
    if (mgl_glTexCoord2dv == NULL)
        return 0;
    mgl_glTexCoord2f = (mgl_glTexCoord2f_t)load_function("glTexCoord2f");
    if (mgl_glTexCoord2f == NULL)
        return 0;
    mgl_glTexCoord2fv = (mgl_glTexCoord2fv_t)load_function("glTexCoord2fv");
    if (mgl_glTexCoord2fv == NULL)
        return 0;
    mgl_glTexCoord2i = (mgl_glTexCoord2i_t)load_function("glTexCoord2i");
    if (mgl_glTexCoord2i == NULL)
        return 0;
    mgl_glTexCoord2iv = (mgl_glTexCoord2iv_t)load_function("glTexCoord2iv");
    if (mgl_glTexCoord2iv == NULL)
        return 0;
    mgl_glTexCoord2s = (mgl_glTexCoord2s_t)load_function("glTexCoord2s");
    if (mgl_glTexCoord2s == NULL)
        return 0;
    mgl_glTexCoord2sv = (mgl_glTexCoord2sv_t)load_function("glTexCoord2sv");
    if (mgl_glTexCoord2sv == NULL)
        return 0;
    mgl_glTexCoord3d = (mgl_glTexCoord3d_t)load_function("glTexCoord3d");
    if (mgl_glTexCoord3d == NULL)
        return 0;
    mgl_glTexCoord3dv = (mgl_glTexCoord3dv_t)load_function("glTexCoord3dv");
    if (mgl_glTexCoord3dv == NULL)
        return 0;
    mgl_glTexCoord3f = (mgl_glTexCoord3f_t)load_function("glTexCoord3f");
    if (mgl_glTexCoord3f == NULL)
        return 0;
    mgl_glTexCoord3fv = (mgl_glTexCoord3fv_t)load_function("glTexCoord3fv");
    if (mgl_glTexCoord3fv == NULL)
        return 0;
    mgl_glTexCoord3i = (mgl_glTexCoord3i_t)load_function("glTexCoord3i");
    if (mgl_glTexCoord3i == NULL)
        return 0;
    mgl_glTexCoord3iv = (mgl_glTexCoord3iv_t)load_function("glTexCoord3iv");
    if (mgl_glTexCoord3iv == NULL)
        return 0;
    mgl_glTexCoord3s = (mgl_glTexCoord3s_t)load_function("glTexCoord3s");
    if (mgl_glTexCoord3s == NULL)
        return 0;
    mgl_glTexCoord3sv = (mgl_glTexCoord3sv_t)load_function("glTexCoord3sv");
    if (mgl_glTexCoord3sv == NULL)
        return 0;
    mgl_glTexCoord4d = (mgl_glTexCoord4d_t)load_function("glTexCoord4d");
    if (mgl_glTexCoord4d == NULL)
        return 0;
    mgl_glTexCoord4dv = (mgl_glTexCoord4dv_t)load_function("glTexCoord4dv");
    if (mgl_glTexCoord4dv == NULL)
        return 0;
    mgl_glTexCoord4f = (mgl_glTexCoord4f_t)load_function("glTexCoord4f");
    if (mgl_glTexCoord4f == NULL)
        return 0;
    mgl_glTexCoord4fv = (mgl_glTexCoord4fv_t)load_function("glTexCoord4fv");
    if (mgl_glTexCoord4fv == NULL)
        return 0;
    mgl_glTexCoord4i = (mgl_glTexCoord4i_t)load_function("glTexCoord4i");
    if (mgl_glTexCoord4i == NULL)
        return 0;
    mgl_glTexCoord4iv = (mgl_glTexCoord4iv_t)load_function("glTexCoord4iv");
    if (mgl_glTexCoord4iv == NULL)
        return 0;
    mgl_glTexCoord4s = (mgl_glTexCoord4s_t)load_function("glTexCoord4s");
    if (mgl_glTexCoord4s == NULL)
        return 0;
    mgl_glTexCoord4sv = (mgl_glTexCoord4sv_t)load_function("glTexCoord4sv");
    if (mgl_glTexCoord4sv == NULL)
        return 0;
    mgl_glVertex2d = (mgl_glVertex2d_t)load_function("glVertex2d");
    if (mgl_glVertex2d == NULL)
        return 0;
    mgl_glVertex2dv = (mgl_glVertex2dv_t)load_function("glVertex2dv");
    if (mgl_glVertex2dv == NULL)
        return 0;
    mgl_glVertex2f = (mgl_glVertex2f_t)load_function("glVertex2f");
    if (mgl_glVertex2f == NULL)
        return 0;
    mgl_glVertex2fv = (mgl_glVertex2fv_t)load_function("glVertex2fv");
    if (mgl_glVertex2fv == NULL)
        return 0;
    mgl_glVertex2i = (mgl_glVertex2i_t)load_function("glVertex2i");
    if (mgl_glVertex2i == NULL)
        return 0;
    mgl_glVertex2iv = (mgl_glVertex2iv_t)load_function("glVertex2iv");
    if (mgl_glVertex2iv == NULL)
        return 0;
    mgl_glVertex2s = (mgl_glVertex2s_t)load_function("glVertex2s");
    if (mgl_glVertex2s == NULL)
        return 0;
    mgl_glVertex2sv = (mgl_glVertex2sv_t)load_function("glVertex2sv");
    if (mgl_glVertex2sv == NULL)
        return 0;
    mgl_glVertex3d = (mgl_glVertex3d_t)load_function("glVertex3d");
    if (mgl_glVertex3d == NULL)
        return 0;
    mgl_glVertex3dv = (mgl_glVertex3dv_t)load_function("glVertex3dv");
    if (mgl_glVertex3dv == NULL)
        return 0;
    mgl_glVertex3f = (mgl_glVertex3f_t)load_function("glVertex3f");
    if (mgl_glVertex3f == NULL)
        return 0;
    mgl_glVertex3fv = (mgl_glVertex3fv_t)load_function("glVertex3fv");
    if (mgl_glVertex3fv == NULL)
        return 0;
    mgl_glVertex3i = (mgl_glVertex3i_t)load_function("glVertex3i");
    if (mgl_glVertex3i == NULL)
        return 0;
    mgl_glVertex3iv = (mgl_glVertex3iv_t)load_function("glVertex3iv");
    if (mgl_glVertex3iv == NULL)
        return 0;
    mgl_glVertex3s = (mgl_glVertex3s_t)load_function("glVertex3s");
    if (mgl_glVertex3s == NULL)
        return 0;
    mgl_glVertex3sv = (mgl_glVertex3sv_t)load_function("glVertex3sv");
    if (mgl_glVertex3sv == NULL)
        return 0;
    mgl_glVertex4d = (mgl_glVertex4d_t)load_function("glVertex4d");
    if (mgl_glVertex4d == NULL)
        return 0;
    mgl_glVertex4dv = (mgl_glVertex4dv_t)load_function("glVertex4dv");
    if (mgl_glVertex4dv == NULL)
        return 0;
    mgl_glVertex4f = (mgl_glVertex4f_t)load_function("glVertex4f");
    if (mgl_glVertex4f == NULL)
        return 0;
    mgl_glVertex4fv = (mgl_glVertex4fv_t)load_function("glVertex4fv");
    if (mgl_glVertex4fv == NULL)
        return 0;
    mgl_glVertex4i = (mgl_glVertex4i_t)load_function("glVertex4i");
    if (mgl_glVertex4i == NULL)
        return 0;
    mgl_glVertex4iv = (mgl_glVertex4iv_t)load_function("glVertex4iv");
    if (mgl_glVertex4iv == NULL)
        return 0;
    mgl_glVertex4s = (mgl_glVertex4s_t)load_function("glVertex4s");
    if (mgl_glVertex4s == NULL)
        return 0;
    mgl_glVertex4sv = (mgl_glVertex4sv_t)load_function("glVertex4sv");
    if (mgl_glVertex4sv == NULL)
        return 0;
    mgl_glClipPlane = (mgl_glClipPlane_t)load_function("glClipPlane");
    if (mgl_glClipPlane == NULL)
        return 0;
    mgl_glColorMaterial = (mgl_glColorMaterial_t)load_function("glColorMaterial");
    if (mgl_glColorMaterial == NULL)
        return 0;
    mgl_glFogf = (mgl_glFogf_t)load_function("glFogf");
    if (mgl_glFogf == NULL)
        return 0;
    mgl_glFogfv = (mgl_glFogfv_t)load_function("glFogfv");
    if (mgl_glFogfv == NULL)
        return 0;
    mgl_glFogi = (mgl_glFogi_t)load_function("glFogi");
    if (mgl_glFogi == NULL)
        return 0;
    mgl_glFogiv = (mgl_glFogiv_t)load_function("glFogiv");
    if (mgl_glFogiv == NULL)
        return 0;
    mgl_glLightf = (mgl_glLightf_t)load_function("glLightf");
    if (mgl_glLightf == NULL)
        return 0;
    mgl_glLightfv = (mgl_glLightfv_t)load_function("glLightfv");
    if (mgl_glLightfv == NULL)
        return 0;
    mgl_glLighti = (mgl_glLighti_t)load_function("glLighti");
    if (mgl_glLighti == NULL)
        return 0;
    mgl_glLightiv = (mgl_glLightiv_t)load_function("glLightiv");
    if (mgl_glLightiv == NULL)
        return 0;
    mgl_glLightModelf = (mgl_glLightModelf_t)load_function("glLightModelf");
    if (mgl_glLightModelf == NULL)
        return 0;
    mgl_glLightModelfv = (mgl_glLightModelfv_t)load_function("glLightModelfv");
    if (mgl_glLightModelfv == NULL)
        return 0;
    mgl_glLightModeli = (mgl_glLightModeli_t)load_function("glLightModeli");
    if (mgl_glLightModeli == NULL)
        return 0;
    mgl_glLightModeliv = (mgl_glLightModeliv_t)load_function("glLightModeliv");
    if (mgl_glLightModeliv == NULL)
        return 0;
    mgl_glLineStipple = (mgl_glLineStipple_t)load_function("glLineStipple");
    if (mgl_glLineStipple == NULL)
        return 0;
    mgl_glMaterialf = (mgl_glMaterialf_t)load_function("glMaterialf");
    if (mgl_glMaterialf == NULL)
        return 0;
    mgl_glMaterialfv = (mgl_glMaterialfv_t)load_function("glMaterialfv");
    if (mgl_glMaterialfv == NULL)
        return 0;
    mgl_glMateriali = (mgl_glMateriali_t)load_function("glMateriali");
    if (mgl_glMateriali == NULL)
        return 0;
    mgl_glMaterialiv = (mgl_glMaterialiv_t)load_function("glMaterialiv");
    if (mgl_glMaterialiv == NULL)
        return 0;
    mgl_glPolygonStipple = (mgl_glPolygonStipple_t)load_function("glPolygonStipple");
    if (mgl_glPolygonStipple == NULL)
        return 0;
    mgl_glShadeModel = (mgl_glShadeModel_t)load_function("glShadeModel");
    if (mgl_glShadeModel == NULL)
        return 0;
    mgl_glTexEnvf = (mgl_glTexEnvf_t)load_function("glTexEnvf");
    if (mgl_glTexEnvf == NULL)
        return 0;
    mgl_glTexEnvfv = (mgl_glTexEnvfv_t)load_function("glTexEnvfv");
    if (mgl_glTexEnvfv == NULL)
        return 0;
    mgl_glTexEnvi = (mgl_glTexEnvi_t)load_function("glTexEnvi");
    if (mgl_glTexEnvi == NULL)
        return 0;
    mgl_glTexEnviv = (mgl_glTexEnviv_t)load_function("glTexEnviv");
    if (mgl_glTexEnviv == NULL)
        return 0;
    mgl_glTexGend = (mgl_glTexGend_t)load_function("glTexGend");
    if (mgl_glTexGend == NULL)
        return 0;
    mgl_glTexGendv = (mgl_glTexGendv_t)load_function("glTexGendv");
    if (mgl_glTexGendv == NULL)
        return 0;
    mgl_glTexGenf = (mgl_glTexGenf_t)load_function("glTexGenf");
    if (mgl_glTexGenf == NULL)
        return 0;
    mgl_glTexGenfv = (mgl_glTexGenfv_t)load_function("glTexGenfv");
    if (mgl_glTexGenfv == NULL)
        return 0;
    mgl_glTexGeni = (mgl_glTexGeni_t)load_function("glTexGeni");
    if (mgl_glTexGeni == NULL)
        return 0;
    mgl_glTexGeniv = (mgl_glTexGeniv_t)load_function("glTexGeniv");
    if (mgl_glTexGeniv == NULL)
        return 0;
    mgl_glFeedbackBuffer = (mgl_glFeedbackBuffer_t)load_function("glFeedbackBuffer");
    if (mgl_glFeedbackBuffer == NULL)
        return 0;
    mgl_glSelectBuffer = (mgl_glSelectBuffer_t)load_function("glSelectBuffer");
    if (mgl_glSelectBuffer == NULL)
        return 0;
    mgl_glRenderMode = (mgl_glRenderMode_t)load_function("glRenderMode");
    if (mgl_glRenderMode == NULL)
        return 0;
    mgl_glInitNames = (mgl_glInitNames_t)load_function("glInitNames");
    if (mgl_glInitNames == NULL)
        return 0;
    mgl_glLoadName = (mgl_glLoadName_t)load_function("glLoadName");
    if (mgl_glLoadName == NULL)
        return 0;
    mgl_glPassThrough = (mgl_glPassThrough_t)load_function("glPassThrough");
    if (mgl_glPassThrough == NULL)
        return 0;
    mgl_glPopName = (mgl_glPopName_t)load_function("glPopName");
    if (mgl_glPopName == NULL)
        return 0;
    mgl_glPushName = (mgl_glPushName_t)load_function("glPushName");
    if (mgl_glPushName == NULL)
        return 0;
    mgl_glClearAccum = (mgl_glClearAccum_t)load_function("glClearAccum");
    if (mgl_glClearAccum == NULL)
        return 0;
    mgl_glClearIndex = (mgl_glClearIndex_t)load_function("glClearIndex");
    if (mgl_glClearIndex == NULL)
        return 0;
    mgl_glIndexMask = (mgl_glIndexMask_t)load_function("glIndexMask");
    if (mgl_glIndexMask == NULL)
        return 0;
    mgl_glAccum = (mgl_glAccum_t)load_function("glAccum");
    if (mgl_glAccum == NULL)
        return 0;
    mgl_glPopAttrib = (mgl_glPopAttrib_t)load_function("glPopAttrib");
    if (mgl_glPopAttrib == NULL)
        return 0;
    mgl_glPushAttrib = (mgl_glPushAttrib_t)load_function("glPushAttrib");
    if (mgl_glPushAttrib == NULL)
        return 0;
    mgl_glMap1d = (mgl_glMap1d_t)load_function("glMap1d");
    if (mgl_glMap1d == NULL)
        return 0;
    mgl_glMap1f = (mgl_glMap1f_t)load_function("glMap1f");
    if (mgl_glMap1f == NULL)
        return 0;
    mgl_glMap2d = (mgl_glMap2d_t)load_function("glMap2d");
    if (mgl_glMap2d == NULL)
        return 0;
    mgl_glMap2f = (mgl_glMap2f_t)load_function("glMap2f");
    if (mgl_glMap2f == NULL)
        return 0;
    mgl_glMapGrid1d = (mgl_glMapGrid1d_t)load_function("glMapGrid1d");
    if (mgl_glMapGrid1d == NULL)
        return 0;
    mgl_glMapGrid1f = (mgl_glMapGrid1f_t)load_function("glMapGrid1f");
    if (mgl_glMapGrid1f == NULL)
        return 0;
    mgl_glMapGrid2d = (mgl_glMapGrid2d_t)load_function("glMapGrid2d");
    if (mgl_glMapGrid2d == NULL)
        return 0;
    mgl_glMapGrid2f = (mgl_glMapGrid2f_t)load_function("glMapGrid2f");
    if (mgl_glMapGrid2f == NULL)
        return 0;
    mgl_glEvalCoord1d = (mgl_glEvalCoord1d_t)load_function("glEvalCoord1d");
    if (mgl_glEvalCoord1d == NULL)
        return 0;
    mgl_glEvalCoord1dv = (mgl_glEvalCoord1dv_t)load_function("glEvalCoord1dv");
    if (mgl_glEvalCoord1dv == NULL)
        return 0;
    mgl_glEvalCoord1f = (mgl_glEvalCoord1f_t)load_function("glEvalCoord1f");
    if (mgl_glEvalCoord1f == NULL)
        return 0;
    mgl_glEvalCoord1fv = (mgl_glEvalCoord1fv_t)load_function("glEvalCoord1fv");
    if (mgl_glEvalCoord1fv == NULL)
        return 0;
    mgl_glEvalCoord2d = (mgl_glEvalCoord2d_t)load_function("glEvalCoord2d");
    if (mgl_glEvalCoord2d == NULL)
        return 0;
    mgl_glEvalCoord2dv = (mgl_glEvalCoord2dv_t)load_function("glEvalCoord2dv");
    if (mgl_glEvalCoord2dv == NULL)
        return 0;
    mgl_glEvalCoord2f = (mgl_glEvalCoord2f_t)load_function("glEvalCoord2f");
    if (mgl_glEvalCoord2f == NULL)
        return 0;
    mgl_glEvalCoord2fv = (mgl_glEvalCoord2fv_t)load_function("glEvalCoord2fv");
    if (mgl_glEvalCoord2fv == NULL)
        return 0;
    mgl_glEvalMesh1 = (mgl_glEvalMesh1_t)load_function("glEvalMesh1");
    if (mgl_glEvalMesh1 == NULL)
        return 0;
    mgl_glEvalPoint1 = (mgl_glEvalPoint1_t)load_function("glEvalPoint1");
    if (mgl_glEvalPoint1 == NULL)
        return 0;
    mgl_glEvalMesh2 = (mgl_glEvalMesh2_t)load_function("glEvalMesh2");
    if (mgl_glEvalMesh2 == NULL)
        return 0;
    mgl_glEvalPoint2 = (mgl_glEvalPoint2_t)load_function("glEvalPoint2");
    if (mgl_glEvalPoint2 == NULL)
        return 0;
    mgl_glAlphaFunc = (mgl_glAlphaFunc_t)load_function("glAlphaFunc");
    if (mgl_glAlphaFunc == NULL)
        return 0;
    mgl_glPixelZoom = (mgl_glPixelZoom_t)load_function("glPixelZoom");
    if (mgl_glPixelZoom == NULL)
        return 0;
    mgl_glPixelTransferf = (mgl_glPixelTransferf_t)load_function("glPixelTransferf");
    if (mgl_glPixelTransferf == NULL)
        return 0;
    mgl_glPixelTransferi = (mgl_glPixelTransferi_t)load_function("glPixelTransferi");
    if (mgl_glPixelTransferi == NULL)
        return 0;
    mgl_glPixelMapfv = (mgl_glPixelMapfv_t)load_function("glPixelMapfv");
    if (mgl_glPixelMapfv == NULL)
        return 0;
    mgl_glPixelMapuiv = (mgl_glPixelMapuiv_t)load_function("glPixelMapuiv");
    if (mgl_glPixelMapuiv == NULL)
        return 0;
    mgl_glPixelMapusv = (mgl_glPixelMapusv_t)load_function("glPixelMapusv");
    if (mgl_glPixelMapusv == NULL)
        return 0;
    mgl_glCopyPixels = (mgl_glCopyPixels_t)load_function("glCopyPixels");
    if (mgl_glCopyPixels == NULL)
        return 0;
    mgl_glDrawPixels = (mgl_glDrawPixels_t)load_function("glDrawPixels");
    if (mgl_glDrawPixels == NULL)
        return 0;
    mgl_glGetClipPlane = (mgl_glGetClipPlane_t)load_function("glGetClipPlane");
    if (mgl_glGetClipPlane == NULL)
        return 0;
    mgl_glGetLightfv = (mgl_glGetLightfv_t)load_function("glGetLightfv");
    if (mgl_glGetLightfv == NULL)
        return 0;
    mgl_glGetLightiv = (mgl_glGetLightiv_t)load_function("glGetLightiv");
    if (mgl_glGetLightiv == NULL)
        return 0;
    mgl_glGetMapdv = (mgl_glGetMapdv_t)load_function("glGetMapdv");
    if (mgl_glGetMapdv == NULL)
        return 0;
    mgl_glGetMapfv = (mgl_glGetMapfv_t)load_function("glGetMapfv");
    if (mgl_glGetMapfv == NULL)
        return 0;
    mgl_glGetMapiv = (mgl_glGetMapiv_t)load_function("glGetMapiv");
    if (mgl_glGetMapiv == NULL)
        return 0;
    mgl_glGetMaterialfv = (mgl_glGetMaterialfv_t)load_function("glGetMaterialfv");
    if (mgl_glGetMaterialfv == NULL)
        return 0;
    mgl_glGetMaterialiv = (mgl_glGetMaterialiv_t)load_function("glGetMaterialiv");
    if (mgl_glGetMaterialiv == NULL)
        return 0;
    mgl_glGetPixelMapfv = (mgl_glGetPixelMapfv_t)load_function("glGetPixelMapfv");
    if (mgl_glGetPixelMapfv == NULL)
        return 0;
    mgl_glGetPixelMapuiv = (mgl_glGetPixelMapuiv_t)load_function("glGetPixelMapuiv");
    if (mgl_glGetPixelMapuiv == NULL)
        return 0;
    mgl_glGetPixelMapusv = (mgl_glGetPixelMapusv_t)load_function("glGetPixelMapusv");
    if (mgl_glGetPixelMapusv == NULL)
        return 0;
    mgl_glGetPolygonStipple = (mgl_glGetPolygonStipple_t)load_function("glGetPolygonStipple");
    if (mgl_glGetPolygonStipple == NULL)
        return 0;
    mgl_glGetTexEnvfv = (mgl_glGetTexEnvfv_t)load_function("glGetTexEnvfv");
    if (mgl_glGetTexEnvfv == NULL)
        return 0;
    mgl_glGetTexEnviv = (mgl_glGetTexEnviv_t)load_function("glGetTexEnviv");
    if (mgl_glGetTexEnviv == NULL)
        return 0;
    mgl_glGetTexGendv = (mgl_glGetTexGendv_t)load_function("glGetTexGendv");
    if (mgl_glGetTexGendv == NULL)
        return 0;
    mgl_glGetTexGenfv = (mgl_glGetTexGenfv_t)load_function("glGetTexGenfv");
    if (mgl_glGetTexGenfv == NULL)
        return 0;
    mgl_glGetTexGeniv = (mgl_glGetTexGeniv_t)load_function("glGetTexGeniv");
    if (mgl_glGetTexGeniv == NULL)
        return 0;
    mgl_glIsList = (mgl_glIsList_t)load_function("glIsList");
    if (mgl_glIsList == NULL)
        return 0;
    mgl_glFrustum = (mgl_glFrustum_t)load_function("glFrustum");
    if (mgl_glFrustum == NULL)
        return 0;
    mgl_glLoadIdentity = (mgl_glLoadIdentity_t)load_function("glLoadIdentity");
    if (mgl_glLoadIdentity == NULL)
        return 0;
    mgl_glLoadMatrixf = (mgl_glLoadMatrixf_t)load_function("glLoadMatrixf");
    if (mgl_glLoadMatrixf == NULL)
        return 0;
    mgl_glLoadMatrixd = (mgl_glLoadMatrixd_t)load_function("glLoadMatrixd");
    if (mgl_glLoadMatrixd == NULL)
        return 0;
    mgl_glMatrixMode = (mgl_glMatrixMode_t)load_function("glMatrixMode");
    if (mgl_glMatrixMode == NULL)
        return 0;
    mgl_glMultMatrixf = (mgl_glMultMatrixf_t)load_function("glMultMatrixf");
    if (mgl_glMultMatrixf == NULL)
        return 0;
    mgl_glMultMatrixd = (mgl_glMultMatrixd_t)load_function("glMultMatrixd");
    if (mgl_glMultMatrixd == NULL)
        return 0;
    mgl_glOrtho = (mgl_glOrtho_t)load_function("glOrtho");
    if (mgl_glOrtho == NULL)
        return 0;
    mgl_glPopMatrix = (mgl_glPopMatrix_t)load_function("glPopMatrix");
    if (mgl_glPopMatrix == NULL)
        return 0;
    mgl_glPushMatrix = (mgl_glPushMatrix_t)load_function("glPushMatrix");
    if (mgl_glPushMatrix == NULL)
        return 0;
    mgl_glRotated = (mgl_glRotated_t)load_function("glRotated");
    if (mgl_glRotated == NULL)
        return 0;
    mgl_glRotatef = (mgl_glRotatef_t)load_function("glRotatef");
    if (mgl_glRotatef == NULL)
        return 0;
    mgl_glScaled = (mgl_glScaled_t)load_function("glScaled");
    if (mgl_glScaled == NULL)
        return 0;
    mgl_glScalef = (mgl_glScalef_t)load_function("glScalef");
    if (mgl_glScalef == NULL)
        return 0;
    mgl_glTranslated = (mgl_glTranslated_t)load_function("glTranslated");
    if (mgl_glTranslated == NULL)
        return 0;
    mgl_glTranslatef = (mgl_glTranslatef_t)load_function("glTranslatef");
    if (mgl_glTranslatef == NULL)
        return 0;
    mgl_glDrawArrays = (mgl_glDrawArrays_t)load_function("glDrawArrays");
    if (mgl_glDrawArrays == NULL)
        return 0;
    mgl_glDrawElements = (mgl_glDrawElements_t)load_function("glDrawElements");
    if (mgl_glDrawElements == NULL)
        return 0;
    mgl_glGetPointerv = (mgl_glGetPointerv_t)load_function("glGetPointerv");
    if (mgl_glGetPointerv == NULL)
        return 0;
    mgl_glPolygonOffset = (mgl_glPolygonOffset_t)load_function("glPolygonOffset");
    if (mgl_glPolygonOffset == NULL)
        return 0;
    mgl_glCopyTexImage1D = (mgl_glCopyTexImage1D_t)load_function("glCopyTexImage1D");
    if (mgl_glCopyTexImage1D == NULL)
        return 0;
    mgl_glCopyTexImage2D = (mgl_glCopyTexImage2D_t)load_function("glCopyTexImage2D");
    if (mgl_glCopyTexImage2D == NULL)
        return 0;
    mgl_glCopyTexSubImage1D = (mgl_glCopyTexSubImage1D_t)load_function("glCopyTexSubImage1D");
    if (mgl_glCopyTexSubImage1D == NULL)
        return 0;
    mgl_glCopyTexSubImage2D = (mgl_glCopyTexSubImage2D_t)load_function("glCopyTexSubImage2D");
    if (mgl_glCopyTexSubImage2D == NULL)
        return 0;
    mgl_glTexSubImage1D = (mgl_glTexSubImage1D_t)load_function("glTexSubImage1D");
    if (mgl_glTexSubImage1D == NULL)
        return 0;
    mgl_glTexSubImage2D = (mgl_glTexSubImage2D_t)load_function("glTexSubImage2D");
    if (mgl_glTexSubImage2D == NULL)
        return 0;
    mgl_glBindTexture = (mgl_glBindTexture_t)load_function("glBindTexture");
    if (mgl_glBindTexture == NULL)
        return 0;
    mgl_glDeleteTextures = (mgl_glDeleteTextures_t)load_function("glDeleteTextures");
    if (mgl_glDeleteTextures == NULL)
        return 0;
    mgl_glGenTextures = (mgl_glGenTextures_t)load_function("glGenTextures");
    if (mgl_glGenTextures == NULL)
        return 0;
    mgl_glIsTexture = (mgl_glIsTexture_t)load_function("glIsTexture");
    if (mgl_glIsTexture == NULL)
        return 0;
    mgl_glArrayElement = (mgl_glArrayElement_t)load_function("glArrayElement");
    if (mgl_glArrayElement == NULL)
        return 0;
    mgl_glColorPointer = (mgl_glColorPointer_t)load_function("glColorPointer");
    if (mgl_glColorPointer == NULL)
        return 0;
    mgl_glDisableClientState = (mgl_glDisableClientState_t)load_function("glDisableClientState");
    if (mgl_glDisableClientState == NULL)
        return 0;
    mgl_glEdgeFlagPointer = (mgl_glEdgeFlagPointer_t)load_function("glEdgeFlagPointer");
    if (mgl_glEdgeFlagPointer == NULL)
        return 0;
    mgl_glEnableClientState = (mgl_glEnableClientState_t)load_function("glEnableClientState");
    if (mgl_glEnableClientState == NULL)
        return 0;
    mgl_glIndexPointer = (mgl_glIndexPointer_t)load_function("glIndexPointer");
    if (mgl_glIndexPointer == NULL)
        return 0;
    mgl_glInterleavedArrays = (mgl_glInterleavedArrays_t)load_function("glInterleavedArrays");
    if (mgl_glInterleavedArrays == NULL)
        return 0;
    mgl_glNormalPointer = (mgl_glNormalPointer_t)load_function("glNormalPointer");
    if (mgl_glNormalPointer == NULL)
        return 0;
    mgl_glTexCoordPointer = (mgl_glTexCoordPointer_t)load_function("glTexCoordPointer");
    if (mgl_glTexCoordPointer == NULL)
        return 0;
    mgl_glVertexPointer = (mgl_glVertexPointer_t)load_function("glVertexPointer");
    if (mgl_glVertexPointer == NULL)
        return 0;
    mgl_glAreTexturesResident = (mgl_glAreTexturesResident_t)load_function("glAreTexturesResident");
    if (mgl_glAreTexturesResident == NULL)
        return 0;
    mgl_glPrioritizeTextures = (mgl_glPrioritizeTextures_t)load_function("glPrioritizeTextures");
    if (mgl_glPrioritizeTextures == NULL)
        return 0;
    mgl_glIndexub = (mgl_glIndexub_t)load_function("glIndexub");
    if (mgl_glIndexub == NULL)
        return 0;
    mgl_glIndexubv = (mgl_glIndexubv_t)load_function("glIndexubv");
    if (mgl_glIndexubv == NULL)
        return 0;
    mgl_glPopClientAttrib = (mgl_glPopClientAttrib_t)load_function("glPopClientAttrib");
    if (mgl_glPopClientAttrib == NULL)
        return 0;
    mgl_glPushClientAttrib = (mgl_glPushClientAttrib_t)load_function("glPushClientAttrib");
    if (mgl_glPushClientAttrib == NULL)
        return 0;
    mgl_glDrawRangeElements = (mgl_glDrawRangeElements_t)load_function("glDrawRangeElements");
    if (mgl_glDrawRangeElements == NULL)
        return 0;
    mgl_glTexImage3D = (mgl_glTexImage3D_t)load_function("glTexImage3D");
    if (mgl_glTexImage3D == NULL)
        return 0;
    mgl_glTexSubImage3D = (mgl_glTexSubImage3D_t)load_function("glTexSubImage3D");
    if (mgl_glTexSubImage3D == NULL)
        return 0;
    mgl_glCopyTexSubImage3D = (mgl_glCopyTexSubImage3D_t)load_function("glCopyTexSubImage3D");
    if (mgl_glCopyTexSubImage3D == NULL)
        return 0;
    mgl_glActiveTexture = (mgl_glActiveTexture_t)load_function("glActiveTexture");
    if (mgl_glActiveTexture == NULL)
        return 0;
    mgl_glSampleCoverage = (mgl_glSampleCoverage_t)load_function("glSampleCoverage");
    if (mgl_glSampleCoverage == NULL)
        return 0;
    mgl_glCompressedTexImage3D = (mgl_glCompressedTexImage3D_t)load_function("glCompressedTexImage3D");
    if (mgl_glCompressedTexImage3D == NULL)
        return 0;
    mgl_glCompressedTexImage2D = (mgl_glCompressedTexImage2D_t)load_function("glCompressedTexImage2D");
    if (mgl_glCompressedTexImage2D == NULL)
        return 0;
    mgl_glCompressedTexImage1D = (mgl_glCompressedTexImage1D_t)load_function("glCompressedTexImage1D");
    if (mgl_glCompressedTexImage1D == NULL)
        return 0;
    mgl_glCompressedTexSubImage3D = (mgl_glCompressedTexSubImage3D_t)load_function("glCompressedTexSubImage3D");
    if (mgl_glCompressedTexSubImage3D == NULL)
        return 0;
    mgl_glCompressedTexSubImage2D = (mgl_glCompressedTexSubImage2D_t)load_function("glCompressedTexSubImage2D");
    if (mgl_glCompressedTexSubImage2D == NULL)
        return 0;
    mgl_glCompressedTexSubImage1D = (mgl_glCompressedTexSubImage1D_t)load_function("glCompressedTexSubImage1D");
    if (mgl_glCompressedTexSubImage1D == NULL)
        return 0;
    mgl_glGetCompressedTexImage = (mgl_glGetCompressedTexImage_t)load_function("glGetCompressedTexImage");
    if (mgl_glGetCompressedTexImage == NULL)
        return 0;
    mgl_glClientActiveTexture = (mgl_glClientActiveTexture_t)load_function("glClientActiveTexture");
    if (mgl_glClientActiveTexture == NULL)
        return 0;
    mgl_glMultiTexCoord1d = (mgl_glMultiTexCoord1d_t)load_function("glMultiTexCoord1d");
    if (mgl_glMultiTexCoord1d == NULL)
        return 0;
    mgl_glMultiTexCoord1dv = (mgl_glMultiTexCoord1dv_t)load_function("glMultiTexCoord1dv");
    if (mgl_glMultiTexCoord1dv == NULL)
        return 0;
    mgl_glMultiTexCoord1f = (mgl_glMultiTexCoord1f_t)load_function("glMultiTexCoord1f");
    if (mgl_glMultiTexCoord1f == NULL)
        return 0;
    mgl_glMultiTexCoord1fv = (mgl_glMultiTexCoord1fv_t)load_function("glMultiTexCoord1fv");
    if (mgl_glMultiTexCoord1fv == NULL)
        return 0;
    mgl_glMultiTexCoord1i = (mgl_glMultiTexCoord1i_t)load_function("glMultiTexCoord1i");
    if (mgl_glMultiTexCoord1i == NULL)
        return 0;
    mgl_glMultiTexCoord1iv = (mgl_glMultiTexCoord1iv_t)load_function("glMultiTexCoord1iv");
    if (mgl_glMultiTexCoord1iv == NULL)
        return 0;
    mgl_glMultiTexCoord1s = (mgl_glMultiTexCoord1s_t)load_function("glMultiTexCoord1s");
    if (mgl_glMultiTexCoord1s == NULL)
        return 0;
    mgl_glMultiTexCoord1sv = (mgl_glMultiTexCoord1sv_t)load_function("glMultiTexCoord1sv");
    if (mgl_glMultiTexCoord1sv == NULL)
        return 0;
    mgl_glMultiTexCoord2d = (mgl_glMultiTexCoord2d_t)load_function("glMultiTexCoord2d");
    if (mgl_glMultiTexCoord2d == NULL)
        return 0;
    mgl_glMultiTexCoord2dv = (mgl_glMultiTexCoord2dv_t)load_function("glMultiTexCoord2dv");
    if (mgl_glMultiTexCoord2dv == NULL)
        return 0;
    mgl_glMultiTexCoord2f = (mgl_glMultiTexCoord2f_t)load_function("glMultiTexCoord2f");
    if (mgl_glMultiTexCoord2f == NULL)
        return 0;
    mgl_glMultiTexCoord2fv = (mgl_glMultiTexCoord2fv_t)load_function("glMultiTexCoord2fv");
    if (mgl_glMultiTexCoord2fv == NULL)
        return 0;
    mgl_glMultiTexCoord2i = (mgl_glMultiTexCoord2i_t)load_function("glMultiTexCoord2i");
    if (mgl_glMultiTexCoord2i == NULL)
        return 0;
    mgl_glMultiTexCoord2iv = (mgl_glMultiTexCoord2iv_t)load_function("glMultiTexCoord2iv");
    if (mgl_glMultiTexCoord2iv == NULL)
        return 0;
    mgl_glMultiTexCoord2s = (mgl_glMultiTexCoord2s_t)load_function("glMultiTexCoord2s");
    if (mgl_glMultiTexCoord2s == NULL)
        return 0;
    mgl_glMultiTexCoord2sv = (mgl_glMultiTexCoord2sv_t)load_function("glMultiTexCoord2sv");
    if (mgl_glMultiTexCoord2sv == NULL)
        return 0;
    mgl_glMultiTexCoord3d = (mgl_glMultiTexCoord3d_t)load_function("glMultiTexCoord3d");
    if (mgl_glMultiTexCoord3d == NULL)
        return 0;
    mgl_glMultiTexCoord3dv = (mgl_glMultiTexCoord3dv_t)load_function("glMultiTexCoord3dv");
    if (mgl_glMultiTexCoord3dv == NULL)
        return 0;
    mgl_glMultiTexCoord3f = (mgl_glMultiTexCoord3f_t)load_function("glMultiTexCoord3f");
    if (mgl_glMultiTexCoord3f == NULL)
        return 0;
    mgl_glMultiTexCoord3fv = (mgl_glMultiTexCoord3fv_t)load_function("glMultiTexCoord3fv");
    if (mgl_glMultiTexCoord3fv == NULL)
        return 0;
    mgl_glMultiTexCoord3i = (mgl_glMultiTexCoord3i_t)load_function("glMultiTexCoord3i");
    if (mgl_glMultiTexCoord3i == NULL)
        return 0;
    mgl_glMultiTexCoord3iv = (mgl_glMultiTexCoord3iv_t)load_function("glMultiTexCoord3iv");
    if (mgl_glMultiTexCoord3iv == NULL)
        return 0;
    mgl_glMultiTexCoord3s = (mgl_glMultiTexCoord3s_t)load_function("glMultiTexCoord3s");
    if (mgl_glMultiTexCoord3s == NULL)
        return 0;
    mgl_glMultiTexCoord3sv = (mgl_glMultiTexCoord3sv_t)load_function("glMultiTexCoord3sv");
    if (mgl_glMultiTexCoord3sv == NULL)
        return 0;
    mgl_glMultiTexCoord4d = (mgl_glMultiTexCoord4d_t)load_function("glMultiTexCoord4d");
    if (mgl_glMultiTexCoord4d == NULL)
        return 0;
    mgl_glMultiTexCoord4dv = (mgl_glMultiTexCoord4dv_t)load_function("glMultiTexCoord4dv");
    if (mgl_glMultiTexCoord4dv == NULL)
        return 0;
    mgl_glMultiTexCoord4f = (mgl_glMultiTexCoord4f_t)load_function("glMultiTexCoord4f");
    if (mgl_glMultiTexCoord4f == NULL)
        return 0;
    mgl_glMultiTexCoord4fv = (mgl_glMultiTexCoord4fv_t)load_function("glMultiTexCoord4fv");
    if (mgl_glMultiTexCoord4fv == NULL)
        return 0;
    mgl_glMultiTexCoord4i = (mgl_glMultiTexCoord4i_t)load_function("glMultiTexCoord4i");
    if (mgl_glMultiTexCoord4i == NULL)
        return 0;
    mgl_glMultiTexCoord4iv = (mgl_glMultiTexCoord4iv_t)load_function("glMultiTexCoord4iv");
    if (mgl_glMultiTexCoord4iv == NULL)
        return 0;
    mgl_glMultiTexCoord4s = (mgl_glMultiTexCoord4s_t)load_function("glMultiTexCoord4s");
    if (mgl_glMultiTexCoord4s == NULL)
        return 0;
    mgl_glMultiTexCoord4sv = (mgl_glMultiTexCoord4sv_t)load_function("glMultiTexCoord4sv");
    if (mgl_glMultiTexCoord4sv == NULL)
        return 0;
    mgl_glLoadTransposeMatrixf = (mgl_glLoadTransposeMatrixf_t)load_function("glLoadTransposeMatrixf");
    if (mgl_glLoadTransposeMatrixf == NULL)
        return 0;
    mgl_glLoadTransposeMatrixd = (mgl_glLoadTransposeMatrixd_t)load_function("glLoadTransposeMatrixd");
    if (mgl_glLoadTransposeMatrixd == NULL)
        return 0;
    mgl_glMultTransposeMatrixf = (mgl_glMultTransposeMatrixf_t)load_function("glMultTransposeMatrixf");
    if (mgl_glMultTransposeMatrixf == NULL)
        return 0;
    mgl_glMultTransposeMatrixd = (mgl_glMultTransposeMatrixd_t)load_function("glMultTransposeMatrixd");
    if (mgl_glMultTransposeMatrixd == NULL)
        return 0;
    mgl_glBlendFuncSeparate = (mgl_glBlendFuncSeparate_t)load_function("glBlendFuncSeparate");
    if (mgl_glBlendFuncSeparate == NULL)
        return 0;
    mgl_glMultiDrawArrays = (mgl_glMultiDrawArrays_t)load_function("glMultiDrawArrays");
    if (mgl_glMultiDrawArrays == NULL)
        return 0;
    mgl_glMultiDrawElements = (mgl_glMultiDrawElements_t)load_function("glMultiDrawElements");
    if (mgl_glMultiDrawElements == NULL)
        return 0;
    mgl_glPointParameterf = (mgl_glPointParameterf_t)load_function("glPointParameterf");
    if (mgl_glPointParameterf == NULL)
        return 0;
    mgl_glPointParameterfv = (mgl_glPointParameterfv_t)load_function("glPointParameterfv");
    if (mgl_glPointParameterfv == NULL)
        return 0;
    mgl_glPointParameteri = (mgl_glPointParameteri_t)load_function("glPointParameteri");
    if (mgl_glPointParameteri == NULL)
        return 0;
    mgl_glPointParameteriv = (mgl_glPointParameteriv_t)load_function("glPointParameteriv");
    if (mgl_glPointParameteriv == NULL)
        return 0;
    mgl_glFogCoordf = (mgl_glFogCoordf_t)load_function("glFogCoordf");
    if (mgl_glFogCoordf == NULL)
        return 0;
    mgl_glFogCoordfv = (mgl_glFogCoordfv_t)load_function("glFogCoordfv");
    if (mgl_glFogCoordfv == NULL)
        return 0;
    mgl_glFogCoordd = (mgl_glFogCoordd_t)load_function("glFogCoordd");
    if (mgl_glFogCoordd == NULL)
        return 0;
    mgl_glFogCoorddv = (mgl_glFogCoorddv_t)load_function("glFogCoorddv");
    if (mgl_glFogCoorddv == NULL)
        return 0;
    mgl_glFogCoordPointer = (mgl_glFogCoordPointer_t)load_function("glFogCoordPointer");
    if (mgl_glFogCoordPointer == NULL)
        return 0;
    mgl_glSecondaryColor3b = (mgl_glSecondaryColor3b_t)load_function("glSecondaryColor3b");
    if (mgl_glSecondaryColor3b == NULL)
        return 0;
    mgl_glSecondaryColor3bv = (mgl_glSecondaryColor3bv_t)load_function("glSecondaryColor3bv");
    if (mgl_glSecondaryColor3bv == NULL)
        return 0;
    mgl_glSecondaryColor3d = (mgl_glSecondaryColor3d_t)load_function("glSecondaryColor3d");
    if (mgl_glSecondaryColor3d == NULL)
        return 0;
    mgl_glSecondaryColor3dv = (mgl_glSecondaryColor3dv_t)load_function("glSecondaryColor3dv");
    if (mgl_glSecondaryColor3dv == NULL)
        return 0;
    mgl_glSecondaryColor3f = (mgl_glSecondaryColor3f_t)load_function("glSecondaryColor3f");
    if (mgl_glSecondaryColor3f == NULL)
        return 0;
    mgl_glSecondaryColor3fv = (mgl_glSecondaryColor3fv_t)load_function("glSecondaryColor3fv");
    if (mgl_glSecondaryColor3fv == NULL)
        return 0;
    mgl_glSecondaryColor3i = (mgl_glSecondaryColor3i_t)load_function("glSecondaryColor3i");
    if (mgl_glSecondaryColor3i == NULL)
        return 0;
    mgl_glSecondaryColor3iv = (mgl_glSecondaryColor3iv_t)load_function("glSecondaryColor3iv");
    if (mgl_glSecondaryColor3iv == NULL)
        return 0;
    mgl_glSecondaryColor3s = (mgl_glSecondaryColor3s_t)load_function("glSecondaryColor3s");
    if (mgl_glSecondaryColor3s == NULL)
        return 0;
    mgl_glSecondaryColor3sv = (mgl_glSecondaryColor3sv_t)load_function("glSecondaryColor3sv");
    if (mgl_glSecondaryColor3sv == NULL)
        return 0;
    mgl_glSecondaryColor3ub = (mgl_glSecondaryColor3ub_t)load_function("glSecondaryColor3ub");
    if (mgl_glSecondaryColor3ub == NULL)
        return 0;
    mgl_glSecondaryColor3ubv = (mgl_glSecondaryColor3ubv_t)load_function("glSecondaryColor3ubv");
    if (mgl_glSecondaryColor3ubv == NULL)
        return 0;
    mgl_glSecondaryColor3ui = (mgl_glSecondaryColor3ui_t)load_function("glSecondaryColor3ui");
    if (mgl_glSecondaryColor3ui == NULL)
        return 0;
    mgl_glSecondaryColor3uiv = (mgl_glSecondaryColor3uiv_t)load_function("glSecondaryColor3uiv");
    if (mgl_glSecondaryColor3uiv == NULL)
        return 0;
    mgl_glSecondaryColor3us = (mgl_glSecondaryColor3us_t)load_function("glSecondaryColor3us");
    if (mgl_glSecondaryColor3us == NULL)
        return 0;
    mgl_glSecondaryColor3usv = (mgl_glSecondaryColor3usv_t)load_function("glSecondaryColor3usv");
    if (mgl_glSecondaryColor3usv == NULL)
        return 0;
    mgl_glSecondaryColorPointer = (mgl_glSecondaryColorPointer_t)load_function("glSecondaryColorPointer");
    if (mgl_glSecondaryColorPointer == NULL)
        return 0;
    mgl_glWindowPos2d = (mgl_glWindowPos2d_t)load_function("glWindowPos2d");
    if (mgl_glWindowPos2d == NULL)
        return 0;
    mgl_glWindowPos2dv = (mgl_glWindowPos2dv_t)load_function("glWindowPos2dv");
    if (mgl_glWindowPos2dv == NULL)
        return 0;
    mgl_glWindowPos2f = (mgl_glWindowPos2f_t)load_function("glWindowPos2f");
    if (mgl_glWindowPos2f == NULL)
        return 0;
    mgl_glWindowPos2fv = (mgl_glWindowPos2fv_t)load_function("glWindowPos2fv");
    if (mgl_glWindowPos2fv == NULL)
        return 0;
    mgl_glWindowPos2i = (mgl_glWindowPos2i_t)load_function("glWindowPos2i");
    if (mgl_glWindowPos2i == NULL)
        return 0;
    mgl_glWindowPos2iv = (mgl_glWindowPos2iv_t)load_function("glWindowPos2iv");
    if (mgl_glWindowPos2iv == NULL)
        return 0;
    mgl_glWindowPos2s = (mgl_glWindowPos2s_t)load_function("glWindowPos2s");
    if (mgl_glWindowPos2s == NULL)
        return 0;
    mgl_glWindowPos2sv = (mgl_glWindowPos2sv_t)load_function("glWindowPos2sv");
    if (mgl_glWindowPos2sv == NULL)
        return 0;
    mgl_glWindowPos3d = (mgl_glWindowPos3d_t)load_function("glWindowPos3d");
    if (mgl_glWindowPos3d == NULL)
        return 0;
    mgl_glWindowPos3dv = (mgl_glWindowPos3dv_t)load_function("glWindowPos3dv");
    if (mgl_glWindowPos3dv == NULL)
        return 0;
    mgl_glWindowPos3f = (mgl_glWindowPos3f_t)load_function("glWindowPos3f");
    if (mgl_glWindowPos3f == NULL)
        return 0;
    mgl_glWindowPos3fv = (mgl_glWindowPos3fv_t)load_function("glWindowPos3fv");
    if (mgl_glWindowPos3fv == NULL)
        return 0;
    mgl_glWindowPos3i = (mgl_glWindowPos3i_t)load_function("glWindowPos3i");
    if (mgl_glWindowPos3i == NULL)
        return 0;
    mgl_glWindowPos3iv = (mgl_glWindowPos3iv_t)load_function("glWindowPos3iv");
    if (mgl_glWindowPos3iv == NULL)
        return 0;
    mgl_glWindowPos3s = (mgl_glWindowPos3s_t)load_function("glWindowPos3s");
    if (mgl_glWindowPos3s == NULL)
        return 0;
    mgl_glWindowPos3sv = (mgl_glWindowPos3sv_t)load_function("glWindowPos3sv");
    if (mgl_glWindowPos3sv == NULL)
        return 0;
    mgl_glBlendColor = (mgl_glBlendColor_t)load_function("glBlendColor");
    if (mgl_glBlendColor == NULL)
        return 0;
    mgl_glBlendEquation = (mgl_glBlendEquation_t)load_function("glBlendEquation");
    if (mgl_glBlendEquation == NULL)
        return 0;
    mgl_glGenQueries = (mgl_glGenQueries_t)load_function("glGenQueries");
    if (mgl_glGenQueries == NULL)
        return 0;
    mgl_glDeleteQueries = (mgl_glDeleteQueries_t)load_function("glDeleteQueries");
    if (mgl_glDeleteQueries == NULL)
        return 0;
    mgl_glIsQuery = (mgl_glIsQuery_t)load_function("glIsQuery");
    if (mgl_glIsQuery == NULL)
        return 0;
    mgl_glBeginQuery = (mgl_glBeginQuery_t)load_function("glBeginQuery");
    if (mgl_glBeginQuery == NULL)
        return 0;
    mgl_glEndQuery = (mgl_glEndQuery_t)load_function("glEndQuery");
    if (mgl_glEndQuery == NULL)
        return 0;
    mgl_glGetQueryiv = (mgl_glGetQueryiv_t)load_function("glGetQueryiv");
    if (mgl_glGetQueryiv == NULL)
        return 0;
    mgl_glGetQueryObjectiv = (mgl_glGetQueryObjectiv_t)load_function("glGetQueryObjectiv");
    if (mgl_glGetQueryObjectiv == NULL)
        return 0;
    mgl_glGetQueryObjectuiv = (mgl_glGetQueryObjectuiv_t)load_function("glGetQueryObjectuiv");
    if (mgl_glGetQueryObjectuiv == NULL)
        return 0;
    mgl_glBindBuffer = (mgl_glBindBuffer_t)load_function("glBindBuffer");
    if (mgl_glBindBuffer == NULL)
        return 0;
    mgl_glDeleteBuffers = (mgl_glDeleteBuffers_t)load_function("glDeleteBuffers");
    if (mgl_glDeleteBuffers == NULL)
        return 0;
    mgl_glGenBuffers = (mgl_glGenBuffers_t)load_function("glGenBuffers");
    if (mgl_glGenBuffers == NULL)
        return 0;
    mgl_glIsBuffer = (mgl_glIsBuffer_t)load_function("glIsBuffer");
    if (mgl_glIsBuffer == NULL)
        return 0;
    mgl_glBufferData = (mgl_glBufferData_t)load_function("glBufferData");
    if (mgl_glBufferData == NULL)
        return 0;
    mgl_glBufferSubData = (mgl_glBufferSubData_t)load_function("glBufferSubData");
    if (mgl_glBufferSubData == NULL)
        return 0;
    mgl_glGetBufferSubData = (mgl_glGetBufferSubData_t)load_function("glGetBufferSubData");
    if (mgl_glGetBufferSubData == NULL)
        return 0;
    mgl_glMapBuffer = (mgl_glMapBuffer_t)load_function("glMapBuffer");
    if (mgl_glMapBuffer == NULL)
        return 0;
    mgl_glUnmapBuffer = (mgl_glUnmapBuffer_t)load_function("glUnmapBuffer");
    if (mgl_glUnmapBuffer == NULL)
        return 0;
    mgl_glGetBufferParameteriv = (mgl_glGetBufferParameteriv_t)load_function("glGetBufferParameteriv");
    if (mgl_glGetBufferParameteriv == NULL)
        return 0;
    mgl_glGetBufferPointerv = (mgl_glGetBufferPointerv_t)load_function("glGetBufferPointerv");
    if (mgl_glGetBufferPointerv == NULL)
        return 0;
    mgl_glBlendEquationSeparate = (mgl_glBlendEquationSeparate_t)load_function("glBlendEquationSeparate");
    if (mgl_glBlendEquationSeparate == NULL)
        return 0;
    mgl_glDrawBuffers = (mgl_glDrawBuffers_t)load_function("glDrawBuffers");
    if (mgl_glDrawBuffers == NULL)
        return 0;
    mgl_glStencilOpSeparate = (mgl_glStencilOpSeparate_t)load_function("glStencilOpSeparate");
    if (mgl_glStencilOpSeparate == NULL)
        return 0;
    mgl_glStencilFuncSeparate = (mgl_glStencilFuncSeparate_t)load_function("glStencilFuncSeparate");
    if (mgl_glStencilFuncSeparate == NULL)
        return 0;
    mgl_glStencilMaskSeparate = (mgl_glStencilMaskSeparate_t)load_function("glStencilMaskSeparate");
    if (mgl_glStencilMaskSeparate == NULL)
        return 0;
    mgl_glAttachShader = (mgl_glAttachShader_t)load_function("glAttachShader");
    if (mgl_glAttachShader == NULL)
        return 0;
    mgl_glBindAttribLocation = (mgl_glBindAttribLocation_t)load_function("glBindAttribLocation");
    if (mgl_glBindAttribLocation == NULL)
        return 0;
    mgl_glCompileShader = (mgl_glCompileShader_t)load_function("glCompileShader");
    if (mgl_glCompileShader == NULL)
        return 0;
    mgl_glCreateProgram = (mgl_glCreateProgram_t)load_function("glCreateProgram");
    if (mgl_glCreateProgram == NULL)
        return 0;
    mgl_glCreateShader = (mgl_glCreateShader_t)load_function("glCreateShader");
    if (mgl_glCreateShader == NULL)
        return 0;
    mgl_glDeleteProgram = (mgl_glDeleteProgram_t)load_function("glDeleteProgram");
    if (mgl_glDeleteProgram == NULL)
        return 0;
    mgl_glDeleteShader = (mgl_glDeleteShader_t)load_function("glDeleteShader");
    if (mgl_glDeleteShader == NULL)
        return 0;
    mgl_glDetachShader = (mgl_glDetachShader_t)load_function("glDetachShader");
    if (mgl_glDetachShader == NULL)
        return 0;
    mgl_glDisableVertexAttribArray = (mgl_glDisableVertexAttribArray_t)load_function("glDisableVertexAttribArray");
    if (mgl_glDisableVertexAttribArray == NULL)
        return 0;
    mgl_glEnableVertexAttribArray = (mgl_glEnableVertexAttribArray_t)load_function("glEnableVertexAttribArray");
    if (mgl_glEnableVertexAttribArray == NULL)
        return 0;
    mgl_glGetActiveAttrib = (mgl_glGetActiveAttrib_t)load_function("glGetActiveAttrib");
    if (mgl_glGetActiveAttrib == NULL)
        return 0;
    mgl_glGetActiveUniform = (mgl_glGetActiveUniform_t)load_function("glGetActiveUniform");
    if (mgl_glGetActiveUniform == NULL)
        return 0;
    mgl_glGetAttachedShaders = (mgl_glGetAttachedShaders_t)load_function("glGetAttachedShaders");
    if (mgl_glGetAttachedShaders == NULL)
        return 0;
    mgl_glGetAttribLocation = (mgl_glGetAttribLocation_t)load_function("glGetAttribLocation");
    if (mgl_glGetAttribLocation == NULL)
        return 0;
    mgl_glGetProgramiv = (mgl_glGetProgramiv_t)load_function("glGetProgramiv");
    if (mgl_glGetProgramiv == NULL)
        return 0;
    mgl_glGetProgramInfoLog = (mgl_glGetProgramInfoLog_t)load_function("glGetProgramInfoLog");
    if (mgl_glGetProgramInfoLog == NULL)
        return 0;
    mgl_glGetShaderiv = (mgl_glGetShaderiv_t)load_function("glGetShaderiv");
    if (mgl_glGetShaderiv == NULL)
        return 0;
    mgl_glGetShaderInfoLog = (mgl_glGetShaderInfoLog_t)load_function("glGetShaderInfoLog");
    if (mgl_glGetShaderInfoLog == NULL)
        return 0;
    mgl_glGetShaderSource = (mgl_glGetShaderSource_t)load_function("glGetShaderSource");
    if (mgl_glGetShaderSource == NULL)
        return 0;
    mgl_glGetUniformLocation = (mgl_glGetUniformLocation_t)load_function("glGetUniformLocation");
    if (mgl_glGetUniformLocation == NULL)
        return 0;
    mgl_glGetUniformfv = (mgl_glGetUniformfv_t)load_function("glGetUniformfv");
    if (mgl_glGetUniformfv == NULL)
        return 0;
    mgl_glGetUniformiv = (mgl_glGetUniformiv_t)load_function("glGetUniformiv");
    if (mgl_glGetUniformiv == NULL)
        return 0;
    mgl_glGetVertexAttribdv = (mgl_glGetVertexAttribdv_t)load_function("glGetVertexAttribdv");
    if (mgl_glGetVertexAttribdv == NULL)
        return 0;
    mgl_glGetVertexAttribfv = (mgl_glGetVertexAttribfv_t)load_function("glGetVertexAttribfv");
    if (mgl_glGetVertexAttribfv == NULL)
        return 0;
    mgl_glGetVertexAttribiv = (mgl_glGetVertexAttribiv_t)load_function("glGetVertexAttribiv");
    if (mgl_glGetVertexAttribiv == NULL)
        return 0;
    mgl_glGetVertexAttribPointerv = (mgl_glGetVertexAttribPointerv_t)load_function("glGetVertexAttribPointerv");
    if (mgl_glGetVertexAttribPointerv == NULL)
        return 0;
    mgl_glIsProgram = (mgl_glIsProgram_t)load_function("glIsProgram");
    if (mgl_glIsProgram == NULL)
        return 0;
    mgl_glIsShader = (mgl_glIsShader_t)load_function("glIsShader");
    if (mgl_glIsShader == NULL)
        return 0;
    mgl_glLinkProgram = (mgl_glLinkProgram_t)load_function("glLinkProgram");
    if (mgl_glLinkProgram == NULL)
        return 0;
    mgl_glShaderSource = (mgl_glShaderSource_t)load_function("glShaderSource");
    if (mgl_glShaderSource == NULL)
        return 0;
    mgl_glUseProgram = (mgl_glUseProgram_t)load_function("glUseProgram");
    if (mgl_glUseProgram == NULL)
        return 0;
    mgl_glUniform1f = (mgl_glUniform1f_t)load_function("glUniform1f");
    if (mgl_glUniform1f == NULL)
        return 0;
    mgl_glUniform2f = (mgl_glUniform2f_t)load_function("glUniform2f");
    if (mgl_glUniform2f == NULL)
        return 0;
    mgl_glUniform3f = (mgl_glUniform3f_t)load_function("glUniform3f");
    if (mgl_glUniform3f == NULL)
        return 0;
    mgl_glUniform4f = (mgl_glUniform4f_t)load_function("glUniform4f");
    if (mgl_glUniform4f == NULL)
        return 0;
    mgl_glUniform1i = (mgl_glUniform1i_t)load_function("glUniform1i");
    if (mgl_glUniform1i == NULL)
        return 0;
    mgl_glUniform2i = (mgl_glUniform2i_t)load_function("glUniform2i");
    if (mgl_glUniform2i == NULL)
        return 0;
    mgl_glUniform3i = (mgl_glUniform3i_t)load_function("glUniform3i");
    if (mgl_glUniform3i == NULL)
        return 0;
    mgl_glUniform4i = (mgl_glUniform4i_t)load_function("glUniform4i");
    if (mgl_glUniform4i == NULL)
        return 0;
    mgl_glUniform1fv = (mgl_glUniform1fv_t)load_function("glUniform1fv");
    if (mgl_glUniform1fv == NULL)
        return 0;
    mgl_glUniform2fv = (mgl_glUniform2fv_t)load_function("glUniform2fv");
    if (mgl_glUniform2fv == NULL)
        return 0;
    mgl_glUniform3fv = (mgl_glUniform3fv_t)load_function("glUniform3fv");
    if (mgl_glUniform3fv == NULL)
        return 0;
    mgl_glUniform4fv = (mgl_glUniform4fv_t)load_function("glUniform4fv");
    if (mgl_glUniform4fv == NULL)
        return 0;
    mgl_glUniform1iv = (mgl_glUniform1iv_t)load_function("glUniform1iv");
    if (mgl_glUniform1iv == NULL)
        return 0;
    mgl_glUniform2iv = (mgl_glUniform2iv_t)load_function("glUniform2iv");
    if (mgl_glUniform2iv == NULL)
        return 0;
    mgl_glUniform3iv = (mgl_glUniform3iv_t)load_function("glUniform3iv");
    if (mgl_glUniform3iv == NULL)
        return 0;
    mgl_glUniform4iv = (mgl_glUniform4iv_t)load_function("glUniform4iv");
    if (mgl_glUniform4iv == NULL)
        return 0;
    mgl_glUniformMatrix2fv = (mgl_glUniformMatrix2fv_t)load_function("glUniformMatrix2fv");
    if (mgl_glUniformMatrix2fv == NULL)
        return 0;
    mgl_glUniformMatrix3fv = (mgl_glUniformMatrix3fv_t)load_function("glUniformMatrix3fv");
    if (mgl_glUniformMatrix3fv == NULL)
        return 0;
    mgl_glUniformMatrix4fv = (mgl_glUniformMatrix4fv_t)load_function("glUniformMatrix4fv");
    if (mgl_glUniformMatrix4fv == NULL)
        return 0;
    mgl_glValidateProgram = (mgl_glValidateProgram_t)load_function("glValidateProgram");
    if (mgl_glValidateProgram == NULL)
        return 0;
    mgl_glVertexAttrib1d = (mgl_glVertexAttrib1d_t)load_function("glVertexAttrib1d");
    if (mgl_glVertexAttrib1d == NULL)
        return 0;
    mgl_glVertexAttrib1dv = (mgl_glVertexAttrib1dv_t)load_function("glVertexAttrib1dv");
    if (mgl_glVertexAttrib1dv == NULL)
        return 0;
    mgl_glVertexAttrib1f = (mgl_glVertexAttrib1f_t)load_function("glVertexAttrib1f");
    if (mgl_glVertexAttrib1f == NULL)
        return 0;
    mgl_glVertexAttrib1fv = (mgl_glVertexAttrib1fv_t)load_function("glVertexAttrib1fv");
    if (mgl_glVertexAttrib1fv == NULL)
        return 0;
    mgl_glVertexAttrib1s = (mgl_glVertexAttrib1s_t)load_function("glVertexAttrib1s");
    if (mgl_glVertexAttrib1s == NULL)
        return 0;
    mgl_glVertexAttrib1sv = (mgl_glVertexAttrib1sv_t)load_function("glVertexAttrib1sv");
    if (mgl_glVertexAttrib1sv == NULL)
        return 0;
    mgl_glVertexAttrib2d = (mgl_glVertexAttrib2d_t)load_function("glVertexAttrib2d");
    if (mgl_glVertexAttrib2d == NULL)
        return 0;
    mgl_glVertexAttrib2dv = (mgl_glVertexAttrib2dv_t)load_function("glVertexAttrib2dv");
    if (mgl_glVertexAttrib2dv == NULL)
        return 0;
    mgl_glVertexAttrib2f = (mgl_glVertexAttrib2f_t)load_function("glVertexAttrib2f");
    if (mgl_glVertexAttrib2f == NULL)
        return 0;
    mgl_glVertexAttrib2fv = (mgl_glVertexAttrib2fv_t)load_function("glVertexAttrib2fv");
    if (mgl_glVertexAttrib2fv == NULL)
        return 0;
    mgl_glVertexAttrib2s = (mgl_glVertexAttrib2s_t)load_function("glVertexAttrib2s");
    if (mgl_glVertexAttrib2s == NULL)
        return 0;
    mgl_glVertexAttrib2sv = (mgl_glVertexAttrib2sv_t)load_function("glVertexAttrib2sv");
    if (mgl_glVertexAttrib2sv == NULL)
        return 0;
    mgl_glVertexAttrib3d = (mgl_glVertexAttrib3d_t)load_function("glVertexAttrib3d");
    if (mgl_glVertexAttrib3d == NULL)
        return 0;
    mgl_glVertexAttrib3dv = (mgl_glVertexAttrib3dv_t)load_function("glVertexAttrib3dv");
    if (mgl_glVertexAttrib3dv == NULL)
        return 0;
    mgl_glVertexAttrib3f = (mgl_glVertexAttrib3f_t)load_function("glVertexAttrib3f");
    if (mgl_glVertexAttrib3f == NULL)
        return 0;
    mgl_glVertexAttrib3fv = (mgl_glVertexAttrib3fv_t)load_function("glVertexAttrib3fv");
    if (mgl_glVertexAttrib3fv == NULL)
        return 0;
    mgl_glVertexAttrib3s = (mgl_glVertexAttrib3s_t)load_function("glVertexAttrib3s");
    if (mgl_glVertexAttrib3s == NULL)
        return 0;
    mgl_glVertexAttrib3sv = (mgl_glVertexAttrib3sv_t)load_function("glVertexAttrib3sv");
    if (mgl_glVertexAttrib3sv == NULL)
        return 0;
    mgl_glVertexAttrib4Nbv = (mgl_glVertexAttrib4Nbv_t)load_function("glVertexAttrib4Nbv");
    if (mgl_glVertexAttrib4Nbv == NULL)
        return 0;
    mgl_glVertexAttrib4Niv = (mgl_glVertexAttrib4Niv_t)load_function("glVertexAttrib4Niv");
    if (mgl_glVertexAttrib4Niv == NULL)
        return 0;
    mgl_glVertexAttrib4Nsv = (mgl_glVertexAttrib4Nsv_t)load_function("glVertexAttrib4Nsv");
    if (mgl_glVertexAttrib4Nsv == NULL)
        return 0;
    mgl_glVertexAttrib4Nub = (mgl_glVertexAttrib4Nub_t)load_function("glVertexAttrib4Nub");
    if (mgl_glVertexAttrib4Nub == NULL)
        return 0;
    mgl_glVertexAttrib4Nubv = (mgl_glVertexAttrib4Nubv_t)load_function("glVertexAttrib4Nubv");
    if (mgl_glVertexAttrib4Nubv == NULL)
        return 0;
    mgl_glVertexAttrib4Nuiv = (mgl_glVertexAttrib4Nuiv_t)load_function("glVertexAttrib4Nuiv");
    if (mgl_glVertexAttrib4Nuiv == NULL)
        return 0;
    mgl_glVertexAttrib4Nusv = (mgl_glVertexAttrib4Nusv_t)load_function("glVertexAttrib4Nusv");
    if (mgl_glVertexAttrib4Nusv == NULL)
        return 0;
    mgl_glVertexAttrib4bv = (mgl_glVertexAttrib4bv_t)load_function("glVertexAttrib4bv");
    if (mgl_glVertexAttrib4bv == NULL)
        return 0;
    mgl_glVertexAttrib4d = (mgl_glVertexAttrib4d_t)load_function("glVertexAttrib4d");
    if (mgl_glVertexAttrib4d == NULL)
        return 0;
    mgl_glVertexAttrib4dv = (mgl_glVertexAttrib4dv_t)load_function("glVertexAttrib4dv");
    if (mgl_glVertexAttrib4dv == NULL)
        return 0;
    mgl_glVertexAttrib4f = (mgl_glVertexAttrib4f_t)load_function("glVertexAttrib4f");
    if (mgl_glVertexAttrib4f == NULL)
        return 0;
    mgl_glVertexAttrib4fv = (mgl_glVertexAttrib4fv_t)load_function("glVertexAttrib4fv");
    if (mgl_glVertexAttrib4fv == NULL)
        return 0;
    mgl_glVertexAttrib4iv = (mgl_glVertexAttrib4iv_t)load_function("glVertexAttrib4iv");
    if (mgl_glVertexAttrib4iv == NULL)
        return 0;
    mgl_glVertexAttrib4s = (mgl_glVertexAttrib4s_t)load_function("glVertexAttrib4s");
    if (mgl_glVertexAttrib4s == NULL)
        return 0;
    mgl_glVertexAttrib4sv = (mgl_glVertexAttrib4sv_t)load_function("glVertexAttrib4sv");
    if (mgl_glVertexAttrib4sv == NULL)
        return 0;
    mgl_glVertexAttrib4ubv = (mgl_glVertexAttrib4ubv_t)load_function("glVertexAttrib4ubv");
    if (mgl_glVertexAttrib4ubv == NULL)
        return 0;
    mgl_glVertexAttrib4uiv = (mgl_glVertexAttrib4uiv_t)load_function("glVertexAttrib4uiv");
    if (mgl_glVertexAttrib4uiv == NULL)
        return 0;
    mgl_glVertexAttrib4usv = (mgl_glVertexAttrib4usv_t)load_function("glVertexAttrib4usv");
    if (mgl_glVertexAttrib4usv == NULL)
        return 0;
    mgl_glVertexAttribPointer = (mgl_glVertexAttribPointer_t)load_function("glVertexAttribPointer");
    if (mgl_glVertexAttribPointer == NULL)
        return 0;
    mgl_glUniformMatrix2x3fv = (mgl_glUniformMatrix2x3fv_t)load_function("glUniformMatrix2x3fv");
    if (mgl_glUniformMatrix2x3fv == NULL)
        return 0;
    mgl_glUniformMatrix3x2fv = (mgl_glUniformMatrix3x2fv_t)load_function("glUniformMatrix3x2fv");
    if (mgl_glUniformMatrix3x2fv == NULL)
        return 0;
    mgl_glUniformMatrix2x4fv = (mgl_glUniformMatrix2x4fv_t)load_function("glUniformMatrix2x4fv");
    if (mgl_glUniformMatrix2x4fv == NULL)
        return 0;
    mgl_glUniformMatrix4x2fv = (mgl_glUniformMatrix4x2fv_t)load_function("glUniformMatrix4x2fv");
    if (mgl_glUniformMatrix4x2fv == NULL)
        return 0;
    mgl_glUniformMatrix3x4fv = (mgl_glUniformMatrix3x4fv_t)load_function("glUniformMatrix3x4fv");
    if (mgl_glUniformMatrix3x4fv == NULL)
        return 0;
    mgl_glUniformMatrix4x3fv = (mgl_glUniformMatrix4x3fv_t)load_function("glUniformMatrix4x3fv");
    if (mgl_glUniformMatrix4x3fv == NULL)
        return 0;
    mgl_glColorMaski = (mgl_glColorMaski_t)load_function("glColorMaski");
    if (mgl_glColorMaski == NULL)
        return 0;
    mgl_glGetBooleani_v = (mgl_glGetBooleani_v_t)load_function("glGetBooleani_v");
    if (mgl_glGetBooleani_v == NULL)
        return 0;
    mgl_glGetIntegeri_v = (mgl_glGetIntegeri_v_t)load_function("glGetIntegeri_v");
    if (mgl_glGetIntegeri_v == NULL)
        return 0;
    mgl_glEnablei = (mgl_glEnablei_t)load_function("glEnablei");
    if (mgl_glEnablei == NULL)
        return 0;
    mgl_glDisablei = (mgl_glDisablei_t)load_function("glDisablei");
    if (mgl_glDisablei == NULL)
        return 0;
    mgl_glIsEnabledi = (mgl_glIsEnabledi_t)load_function("glIsEnabledi");
    if (mgl_glIsEnabledi == NULL)
        return 0;
    mgl_glBeginTransformFeedback = (mgl_glBeginTransformFeedback_t)load_function("glBeginTransformFeedback");
    if (mgl_glBeginTransformFeedback == NULL)
        return 0;
    mgl_glEndTransformFeedback = (mgl_glEndTransformFeedback_t)load_function("glEndTransformFeedback");
    if (mgl_glEndTransformFeedback == NULL)
        return 0;
    mgl_glBindBufferRange = (mgl_glBindBufferRange_t)load_function("glBindBufferRange");
    if (mgl_glBindBufferRange == NULL)
        return 0;
    mgl_glBindBufferBase = (mgl_glBindBufferBase_t)load_function("glBindBufferBase");
    if (mgl_glBindBufferBase == NULL)
        return 0;
    mgl_glTransformFeedbackVaryings = (mgl_glTransformFeedbackVaryings_t)load_function("glTransformFeedbackVaryings");
    if (mgl_glTransformFeedbackVaryings == NULL)
        return 0;
    mgl_glGetTransformFeedbackVarying = (mgl_glGetTransformFeedbackVarying_t)load_function("glGetTransformFeedbackVarying");
    if (mgl_glGetTransformFeedbackVarying == NULL)
        return 0;
    mgl_glClampColor = (mgl_glClampColor_t)load_function("glClampColor");
    if (mgl_glClampColor == NULL)
        return 0;
    mgl_glBeginConditionalRender = (mgl_glBeginConditionalRender_t)load_function("glBeginConditionalRender");
    if (mgl_glBeginConditionalRender == NULL)
        return 0;
    mgl_glEndConditionalRender = (mgl_glEndConditionalRender_t)load_function("glEndConditionalRender");
    if (mgl_glEndConditionalRender == NULL)
        return 0;
    mgl_glVertexAttribIPointer = (mgl_glVertexAttribIPointer_t)load_function("glVertexAttribIPointer");
    if (mgl_glVertexAttribIPointer == NULL)
        return 0;
    mgl_glGetVertexAttribIiv = (mgl_glGetVertexAttribIiv_t)load_function("glGetVertexAttribIiv");
    if (mgl_glGetVertexAttribIiv == NULL)
        return 0;
    mgl_glGetVertexAttribIuiv = (mgl_glGetVertexAttribIuiv_t)load_function("glGetVertexAttribIuiv");
    if (mgl_glGetVertexAttribIuiv == NULL)
        return 0;
    mgl_glVertexAttribI1i = (mgl_glVertexAttribI1i_t)load_function("glVertexAttribI1i");
    if (mgl_glVertexAttribI1i == NULL)
        return 0;
    mgl_glVertexAttribI2i = (mgl_glVertexAttribI2i_t)load_function("glVertexAttribI2i");
    if (mgl_glVertexAttribI2i == NULL)
        return 0;
    mgl_glVertexAttribI3i = (mgl_glVertexAttribI3i_t)load_function("glVertexAttribI3i");
    if (mgl_glVertexAttribI3i == NULL)
        return 0;
    mgl_glVertexAttribI4i = (mgl_glVertexAttribI4i_t)load_function("glVertexAttribI4i");
    if (mgl_glVertexAttribI4i == NULL)
        return 0;
    mgl_glVertexAttribI1ui = (mgl_glVertexAttribI1ui_t)load_function("glVertexAttribI1ui");
    if (mgl_glVertexAttribI1ui == NULL)
        return 0;
    mgl_glVertexAttribI2ui = (mgl_glVertexAttribI2ui_t)load_function("glVertexAttribI2ui");
    if (mgl_glVertexAttribI2ui == NULL)
        return 0;
    mgl_glVertexAttribI3ui = (mgl_glVertexAttribI3ui_t)load_function("glVertexAttribI3ui");
    if (mgl_glVertexAttribI3ui == NULL)
        return 0;
    mgl_glVertexAttribI4ui = (mgl_glVertexAttribI4ui_t)load_function("glVertexAttribI4ui");
    if (mgl_glVertexAttribI4ui == NULL)
        return 0;
    mgl_glVertexAttribI1iv = (mgl_glVertexAttribI1iv_t)load_function("glVertexAttribI1iv");
    if (mgl_glVertexAttribI1iv == NULL)
        return 0;
    mgl_glVertexAttribI2iv = (mgl_glVertexAttribI2iv_t)load_function("glVertexAttribI2iv");
    if (mgl_glVertexAttribI2iv == NULL)
        return 0;
    mgl_glVertexAttribI3iv = (mgl_glVertexAttribI3iv_t)load_function("glVertexAttribI3iv");
    if (mgl_glVertexAttribI3iv == NULL)
        return 0;
    mgl_glVertexAttribI4iv = (mgl_glVertexAttribI4iv_t)load_function("glVertexAttribI4iv");
    if (mgl_glVertexAttribI4iv == NULL)
        return 0;
    mgl_glVertexAttribI1uiv = (mgl_glVertexAttribI1uiv_t)load_function("glVertexAttribI1uiv");
    if (mgl_glVertexAttribI1uiv == NULL)
        return 0;
    mgl_glVertexAttribI2uiv = (mgl_glVertexAttribI2uiv_t)load_function("glVertexAttribI2uiv");
    if (mgl_glVertexAttribI2uiv == NULL)
        return 0;
    mgl_glVertexAttribI3uiv = (mgl_glVertexAttribI3uiv_t)load_function("glVertexAttribI3uiv");
    if (mgl_glVertexAttribI3uiv == NULL)
        return 0;
    mgl_glVertexAttribI4uiv = (mgl_glVertexAttribI4uiv_t)load_function("glVertexAttribI4uiv");
    if (mgl_glVertexAttribI4uiv == NULL)
        return 0;
    mgl_glVertexAttribI4bv = (mgl_glVertexAttribI4bv_t)load_function("glVertexAttribI4bv");
    if (mgl_glVertexAttribI4bv == NULL)
        return 0;
    mgl_glVertexAttribI4sv = (mgl_glVertexAttribI4sv_t)load_function("glVertexAttribI4sv");
    if (mgl_glVertexAttribI4sv == NULL)
        return 0;
    mgl_glVertexAttribI4ubv = (mgl_glVertexAttribI4ubv_t)load_function("glVertexAttribI4ubv");
    if (mgl_glVertexAttribI4ubv == NULL)
        return 0;
    mgl_glVertexAttribI4usv = (mgl_glVertexAttribI4usv_t)load_function("glVertexAttribI4usv");
    if (mgl_glVertexAttribI4usv == NULL)
        return 0;
    mgl_glGetUniformuiv = (mgl_glGetUniformuiv_t)load_function("glGetUniformuiv");
    if (mgl_glGetUniformuiv == NULL)
        return 0;
    mgl_glBindFragDataLocation = (mgl_glBindFragDataLocation_t)load_function("glBindFragDataLocation");
    if (mgl_glBindFragDataLocation == NULL)
        return 0;
    mgl_glGetFragDataLocation = (mgl_glGetFragDataLocation_t)load_function("glGetFragDataLocation");
    if (mgl_glGetFragDataLocation == NULL)
        return 0;
    mgl_glUniform1ui = (mgl_glUniform1ui_t)load_function("glUniform1ui");
    if (mgl_glUniform1ui == NULL)
        return 0;
    mgl_glUniform2ui = (mgl_glUniform2ui_t)load_function("glUniform2ui");
    if (mgl_glUniform2ui == NULL)
        return 0;
    mgl_glUniform3ui = (mgl_glUniform3ui_t)load_function("glUniform3ui");
    if (mgl_glUniform3ui == NULL)
        return 0;
    mgl_glUniform4ui = (mgl_glUniform4ui_t)load_function("glUniform4ui");
    if (mgl_glUniform4ui == NULL)
        return 0;
    mgl_glUniform1uiv = (mgl_glUniform1uiv_t)load_function("glUniform1uiv");
    if (mgl_glUniform1uiv == NULL)
        return 0;
    mgl_glUniform2uiv = (mgl_glUniform2uiv_t)load_function("glUniform2uiv");
    if (mgl_glUniform2uiv == NULL)
        return 0;
    mgl_glUniform3uiv = (mgl_glUniform3uiv_t)load_function("glUniform3uiv");
    if (mgl_glUniform3uiv == NULL)
        return 0;
    mgl_glUniform4uiv = (mgl_glUniform4uiv_t)load_function("glUniform4uiv");
    if (mgl_glUniform4uiv == NULL)
        return 0;
    mgl_glTexParameterIiv = (mgl_glTexParameterIiv_t)load_function("glTexParameterIiv");
    if (mgl_glTexParameterIiv == NULL)
        return 0;
    mgl_glTexParameterIuiv = (mgl_glTexParameterIuiv_t)load_function("glTexParameterIuiv");
    if (mgl_glTexParameterIuiv == NULL)
        return 0;
    mgl_glGetTexParameterIiv = (mgl_glGetTexParameterIiv_t)load_function("glGetTexParameterIiv");
    if (mgl_glGetTexParameterIiv == NULL)
        return 0;
    mgl_glGetTexParameterIuiv = (mgl_glGetTexParameterIuiv_t)load_function("glGetTexParameterIuiv");
    if (mgl_glGetTexParameterIuiv == NULL)
        return 0;
    mgl_glClearBufferiv = (mgl_glClearBufferiv_t)load_function("glClearBufferiv");
    if (mgl_glClearBufferiv == NULL)
        return 0;
    mgl_glClearBufferuiv = (mgl_glClearBufferuiv_t)load_function("glClearBufferuiv");
    if (mgl_glClearBufferuiv == NULL)
        return 0;
    mgl_glClearBufferfv = (mgl_glClearBufferfv_t)load_function("glClearBufferfv");
    if (mgl_glClearBufferfv == NULL)
        return 0;
    mgl_glClearBufferfi = (mgl_glClearBufferfi_t)load_function("glClearBufferfi");
    if (mgl_glClearBufferfi == NULL)
        return 0;
    mgl_glGetStringi = (mgl_glGetStringi_t)load_function("glGetStringi");
    if (mgl_glGetStringi == NULL)
        return 0;
    mgl_glIsRenderbuffer = (mgl_glIsRenderbuffer_t)load_function("glIsRenderbuffer");
    if (mgl_glIsRenderbuffer == NULL)
        return 0;
    mgl_glBindRenderbuffer = (mgl_glBindRenderbuffer_t)load_function("glBindRenderbuffer");
    if (mgl_glBindRenderbuffer == NULL)
        return 0;
    mgl_glDeleteRenderbuffers = (mgl_glDeleteRenderbuffers_t)load_function("glDeleteRenderbuffers");
    if (mgl_glDeleteRenderbuffers == NULL)
        return 0;
    mgl_glGenRenderbuffers = (mgl_glGenRenderbuffers_t)load_function("glGenRenderbuffers");
    if (mgl_glGenRenderbuffers == NULL)
        return 0;
    mgl_glRenderbufferStorage = (mgl_glRenderbufferStorage_t)load_function("glRenderbufferStorage");
    if (mgl_glRenderbufferStorage == NULL)
        return 0;
    mgl_glGetRenderbufferParameteriv = (mgl_glGetRenderbufferParameteriv_t)load_function("glGetRenderbufferParameteriv");
    if (mgl_glGetRenderbufferParameteriv == NULL)
        return 0;
    mgl_glIsFramebuffer = (mgl_glIsFramebuffer_t)load_function("glIsFramebuffer");
    if (mgl_glIsFramebuffer == NULL)
        return 0;
    mgl_glBindFramebuffer = (mgl_glBindFramebuffer_t)load_function("glBindFramebuffer");
    if (mgl_glBindFramebuffer == NULL)
        return 0;
    mgl_glDeleteFramebuffers = (mgl_glDeleteFramebuffers_t)load_function("glDeleteFramebuffers");
    if (mgl_glDeleteFramebuffers == NULL)
        return 0;
    mgl_glGenFramebuffers = (mgl_glGenFramebuffers_t)load_function("glGenFramebuffers");
    if (mgl_glGenFramebuffers == NULL)
        return 0;
    mgl_glCheckFramebufferStatus = (mgl_glCheckFramebufferStatus_t)load_function("glCheckFramebufferStatus");
    if (mgl_glCheckFramebufferStatus == NULL)
        return 0;
    mgl_glFramebufferTexture1D = (mgl_glFramebufferTexture1D_t)load_function("glFramebufferTexture1D");
    if (mgl_glFramebufferTexture1D == NULL)
        return 0;
    mgl_glFramebufferTexture2D = (mgl_glFramebufferTexture2D_t)load_function("glFramebufferTexture2D");
    if (mgl_glFramebufferTexture2D == NULL)
        return 0;
    mgl_glFramebufferTexture3D = (mgl_glFramebufferTexture3D_t)load_function("glFramebufferTexture3D");
    if (mgl_glFramebufferTexture3D == NULL)
        return 0;
    mgl_glFramebufferRenderbuffer = (mgl_glFramebufferRenderbuffer_t)load_function("glFramebufferRenderbuffer");
    if (mgl_glFramebufferRenderbuffer == NULL)
        return 0;
    mgl_glGetFramebufferAttachmentParameteriv = (mgl_glGetFramebufferAttachmentParameteriv_t)load_function("glGetFramebufferAttachmentParameteriv");
    if (mgl_glGetFramebufferAttachmentParameteriv == NULL)
        return 0;
    mgl_glGenerateMipmap = (mgl_glGenerateMipmap_t)load_function("glGenerateMipmap");
    if (mgl_glGenerateMipmap == NULL)
        return 0;
    mgl_glBlitFramebuffer = (mgl_glBlitFramebuffer_t)load_function("glBlitFramebuffer");
    if (mgl_glBlitFramebuffer == NULL)
        return 0;
    mgl_glRenderbufferStorageMultisample = (mgl_glRenderbufferStorageMultisample_t)load_function("glRenderbufferStorageMultisample");
    if (mgl_glRenderbufferStorageMultisample == NULL)
        return 0;
    mgl_glFramebufferTextureLayer = (mgl_glFramebufferTextureLayer_t)load_function("glFramebufferTextureLayer");
    if (mgl_glFramebufferTextureLayer == NULL)
        return 0;
    mgl_glMapBufferRange = (mgl_glMapBufferRange_t)load_function("glMapBufferRange");
    if (mgl_glMapBufferRange == NULL)
        return 0;
    mgl_glFlushMappedBufferRange = (mgl_glFlushMappedBufferRange_t)load_function("glFlushMappedBufferRange");
    if (mgl_glFlushMappedBufferRange == NULL)
        return 0;
    mgl_glBindVertexArray = (mgl_glBindVertexArray_t)load_function("glBindVertexArray");
    if (mgl_glBindVertexArray == NULL)
        return 0;
    mgl_glDeleteVertexArrays = (mgl_glDeleteVertexArrays_t)load_function("glDeleteVertexArrays");
    if (mgl_glDeleteVertexArrays == NULL)
        return 0;
    mgl_glGenVertexArrays = (mgl_glGenVertexArrays_t)load_function("glGenVertexArrays");
    if (mgl_glGenVertexArrays == NULL)
        return 0;
    mgl_glIsVertexArray = (mgl_glIsVertexArray_t)load_function("glIsVertexArray");
    if (mgl_glIsVertexArray == NULL)
        return 0;
    mgl_glDrawArraysInstanced = (mgl_glDrawArraysInstanced_t)load_function("glDrawArraysInstanced");
    if (mgl_glDrawArraysInstanced == NULL)
        return 0;
    mgl_glDrawElementsInstanced = (mgl_glDrawElementsInstanced_t)load_function("glDrawElementsInstanced");
    if (mgl_glDrawElementsInstanced == NULL)
        return 0;
    mgl_glTexBuffer = (mgl_glTexBuffer_t)load_function("glTexBuffer");
    if (mgl_glTexBuffer == NULL)
        return 0;
    mgl_glPrimitiveRestartIndex = (mgl_glPrimitiveRestartIndex_t)load_function("glPrimitiveRestartIndex");
    if (mgl_glPrimitiveRestartIndex == NULL)
        return 0;
    mgl_glCopyBufferSubData = (mgl_glCopyBufferSubData_t)load_function("glCopyBufferSubData");
    if (mgl_glCopyBufferSubData == NULL)
        return 0;
    mgl_glGetUniformIndices = (mgl_glGetUniformIndices_t)load_function("glGetUniformIndices");
    if (mgl_glGetUniformIndices == NULL)
        return 0;
    mgl_glGetActiveUniformsiv = (mgl_glGetActiveUniformsiv_t)load_function("glGetActiveUniformsiv");
    if (mgl_glGetActiveUniformsiv == NULL)
        return 0;
    mgl_glGetActiveUniformName = (mgl_glGetActiveUniformName_t)load_function("glGetActiveUniformName");
    if (mgl_glGetActiveUniformName == NULL)
        return 0;
    mgl_glGetUniformBlockIndex = (mgl_glGetUniformBlockIndex_t)load_function("glGetUniformBlockIndex");
    if (mgl_glGetUniformBlockIndex == NULL)
        return 0;
    mgl_glGetActiveUniformBlockiv = (mgl_glGetActiveUniformBlockiv_t)load_function("glGetActiveUniformBlockiv");
    if (mgl_glGetActiveUniformBlockiv == NULL)
        return 0;
    mgl_glGetActiveUniformBlockName = (mgl_glGetActiveUniformBlockName_t)load_function("glGetActiveUniformBlockName");
    if (mgl_glGetActiveUniformBlockName == NULL)
        return 0;
    mgl_glUniformBlockBinding = (mgl_glUniformBlockBinding_t)load_function("glUniformBlockBinding");
    if (mgl_glUniformBlockBinding == NULL)
        return 0;
    mgl_glDrawElementsBaseVertex = (mgl_glDrawElementsBaseVertex_t)load_function("glDrawElementsBaseVertex");
    if (mgl_glDrawElementsBaseVertex == NULL)
        return 0;
    mgl_glDrawRangeElementsBaseVertex = (mgl_glDrawRangeElementsBaseVertex_t)load_function("glDrawRangeElementsBaseVertex");
    if (mgl_glDrawRangeElementsBaseVertex == NULL)
        return 0;
    mgl_glDrawElementsInstancedBaseVertex = (mgl_glDrawElementsInstancedBaseVertex_t)load_function("glDrawElementsInstancedBaseVertex");
    if (mgl_glDrawElementsInstancedBaseVertex == NULL)
        return 0;
    mgl_glMultiDrawElementsBaseVertex = (mgl_glMultiDrawElementsBaseVertex_t)load_function("glMultiDrawElementsBaseVertex");
    if (mgl_glMultiDrawElementsBaseVertex == NULL)
        return 0;
    mgl_glProvokingVertex = (mgl_glProvokingVertex_t)load_function("glProvokingVertex");
    if (mgl_glProvokingVertex == NULL)
        return 0;
    mgl_glFenceSync = (mgl_glFenceSync_t)load_function("glFenceSync");
    if (mgl_glFenceSync == NULL)
        return 0;
    mgl_glIsSync = (mgl_glIsSync_t)load_function("glIsSync");
    if (mgl_glIsSync == NULL)
        return 0;
    mgl_glDeleteSync = (mgl_glDeleteSync_t)load_function("glDeleteSync");
    if (mgl_glDeleteSync == NULL)
        return 0;
    mgl_glClientWaitSync = (mgl_glClientWaitSync_t)load_function("glClientWaitSync");
    if (mgl_glClientWaitSync == NULL)
        return 0;
    mgl_glWaitSync = (mgl_glWaitSync_t)load_function("glWaitSync");
    if (mgl_glWaitSync == NULL)
        return 0;
    mgl_glGetInteger64v = (mgl_glGetInteger64v_t)load_function("glGetInteger64v");
    if (mgl_glGetInteger64v == NULL)
        return 0;
    mgl_glGetSynciv = (mgl_glGetSynciv_t)load_function("glGetSynciv");
    if (mgl_glGetSynciv == NULL)
        return 0;
    mgl_glGetInteger64i_v = (mgl_glGetInteger64i_v_t)load_function("glGetInteger64i_v");
    if (mgl_glGetInteger64i_v == NULL)
        return 0;
    mgl_glGetBufferParameteri64v = (mgl_glGetBufferParameteri64v_t)load_function("glGetBufferParameteri64v");
    if (mgl_glGetBufferParameteri64v == NULL)
        return 0;
    mgl_glFramebufferTexture = (mgl_glFramebufferTexture_t)load_function("glFramebufferTexture");
    if (mgl_glFramebufferTexture == NULL)
        return 0;
    mgl_glTexImage2DMultisample = (mgl_glTexImage2DMultisample_t)load_function("glTexImage2DMultisample");
    if (mgl_glTexImage2DMultisample == NULL)
        return 0;
    mgl_glTexImage3DMultisample = (mgl_glTexImage3DMultisample_t)load_function("glTexImage3DMultisample");
    if (mgl_glTexImage3DMultisample == NULL)
        return 0;
    mgl_glGetMultisamplefv = (mgl_glGetMultisamplefv_t)load_function("glGetMultisamplefv");
    if (mgl_glGetMultisamplefv == NULL)
        return 0;
    mgl_glSampleMaski = (mgl_glSampleMaski_t)load_function("glSampleMaski");
    if (mgl_glSampleMaski == NULL)
        return 0;
    mgl_glBindFragDataLocationIndexed = (mgl_glBindFragDataLocationIndexed_t)load_function("glBindFragDataLocationIndexed");
    if (mgl_glBindFragDataLocationIndexed == NULL)
        return 0;
    mgl_glGetFragDataIndex = (mgl_glGetFragDataIndex_t)load_function("glGetFragDataIndex");
    if (mgl_glGetFragDataIndex == NULL)
        return 0;
    mgl_glGenSamplers = (mgl_glGenSamplers_t)load_function("glGenSamplers");
    if (mgl_glGenSamplers == NULL)
        return 0;
    mgl_glDeleteSamplers = (mgl_glDeleteSamplers_t)load_function("glDeleteSamplers");
    if (mgl_glDeleteSamplers == NULL)
        return 0;
    mgl_glIsSampler = (mgl_glIsSampler_t)load_function("glIsSampler");
    if (mgl_glIsSampler == NULL)
        return 0;
    mgl_glBindSampler = (mgl_glBindSampler_t)load_function("glBindSampler");
    if (mgl_glBindSampler == NULL)
        return 0;
    mgl_glSamplerParameteri = (mgl_glSamplerParameteri_t)load_function("glSamplerParameteri");
    if (mgl_glSamplerParameteri == NULL)
        return 0;
    mgl_glSamplerParameteriv = (mgl_glSamplerParameteriv_t)load_function("glSamplerParameteriv");
    if (mgl_glSamplerParameteriv == NULL)
        return 0;
    mgl_glSamplerParameterf = (mgl_glSamplerParameterf_t)load_function("glSamplerParameterf");
    if (mgl_glSamplerParameterf == NULL)
        return 0;
    mgl_glSamplerParameterfv = (mgl_glSamplerParameterfv_t)load_function("glSamplerParameterfv");
    if (mgl_glSamplerParameterfv == NULL)
        return 0;
    mgl_glSamplerParameterIiv = (mgl_glSamplerParameterIiv_t)load_function("glSamplerParameterIiv");
    if (mgl_glSamplerParameterIiv == NULL)
        return 0;
    mgl_glSamplerParameterIuiv = (mgl_glSamplerParameterIuiv_t)load_function("glSamplerParameterIuiv");
    if (mgl_glSamplerParameterIuiv == NULL)
        return 0;
    mgl_glGetSamplerParameteriv = (mgl_glGetSamplerParameteriv_t)load_function("glGetSamplerParameteriv");
    if (mgl_glGetSamplerParameteriv == NULL)
        return 0;
    mgl_glGetSamplerParameterIiv = (mgl_glGetSamplerParameterIiv_t)load_function("glGetSamplerParameterIiv");
    if (mgl_glGetSamplerParameterIiv == NULL)
        return 0;
    mgl_glGetSamplerParameterfv = (mgl_glGetSamplerParameterfv_t)load_function("glGetSamplerParameterfv");
    if (mgl_glGetSamplerParameterfv == NULL)
        return 0;
    mgl_glGetSamplerParameterIuiv = (mgl_glGetSamplerParameterIuiv_t)load_function("glGetSamplerParameterIuiv");
    if (mgl_glGetSamplerParameterIuiv == NULL)
        return 0;
    mgl_glQueryCounter = (mgl_glQueryCounter_t)load_function("glQueryCounter");
    if (mgl_glQueryCounter == NULL)
        return 0;
    mgl_glGetQueryObjecti64v = (mgl_glGetQueryObjecti64v_t)load_function("glGetQueryObjecti64v");
    if (mgl_glGetQueryObjecti64v == NULL)
        return 0;
    mgl_glGetQueryObjectui64v = (mgl_glGetQueryObjectui64v_t)load_function("glGetQueryObjectui64v");
    if (mgl_glGetQueryObjectui64v == NULL)
        return 0;
    mgl_glVertexAttribDivisor = (mgl_glVertexAttribDivisor_t)load_function("glVertexAttribDivisor");
    if (mgl_glVertexAttribDivisor == NULL)
        return 0;
    mgl_glVertexAttribP1ui = (mgl_glVertexAttribP1ui_t)load_function("glVertexAttribP1ui");
    if (mgl_glVertexAttribP1ui == NULL)
        return 0;
    mgl_glVertexAttribP1uiv = (mgl_glVertexAttribP1uiv_t)load_function("glVertexAttribP1uiv");
    if (mgl_glVertexAttribP1uiv == NULL)
        return 0;
    mgl_glVertexAttribP2ui = (mgl_glVertexAttribP2ui_t)load_function("glVertexAttribP2ui");
    if (mgl_glVertexAttribP2ui == NULL)
        return 0;
    mgl_glVertexAttribP2uiv = (mgl_glVertexAttribP2uiv_t)load_function("glVertexAttribP2uiv");
    if (mgl_glVertexAttribP2uiv == NULL)
        return 0;
    mgl_glVertexAttribP3ui = (mgl_glVertexAttribP3ui_t)load_function("glVertexAttribP3ui");
    if (mgl_glVertexAttribP3ui == NULL)
        return 0;
    mgl_glVertexAttribP3uiv = (mgl_glVertexAttribP3uiv_t)load_function("glVertexAttribP3uiv");
    if (mgl_glVertexAttribP3uiv == NULL)
        return 0;
    mgl_glVertexAttribP4ui = (mgl_glVertexAttribP4ui_t)load_function("glVertexAttribP4ui");
    if (mgl_glVertexAttribP4ui == NULL)
        return 0;
    mgl_glVertexAttribP4uiv = (mgl_glVertexAttribP4uiv_t)load_function("glVertexAttribP4uiv");
    if (mgl_glVertexAttribP4uiv == NULL)
        return 0;
    mgl_glMinSampleShading = (mgl_glMinSampleShading_t)load_function("glMinSampleShading");
    if (mgl_glMinSampleShading == NULL)
        return 0;
    mgl_glBlendEquationi = (mgl_glBlendEquationi_t)load_function("glBlendEquationi");
    if (mgl_glBlendEquationi == NULL)
        return 0;
    mgl_glBlendEquationSeparatei = (mgl_glBlendEquationSeparatei_t)load_function("glBlendEquationSeparatei");
    if (mgl_glBlendEquationSeparatei == NULL)
        return 0;
    mgl_glBlendFunci = (mgl_glBlendFunci_t)load_function("glBlendFunci");
    if (mgl_glBlendFunci == NULL)
        return 0;
    mgl_glBlendFuncSeparatei = (mgl_glBlendFuncSeparatei_t)load_function("glBlendFuncSeparatei");
    if (mgl_glBlendFuncSeparatei == NULL)
        return 0;
    mgl_glDrawArraysIndirect = (mgl_glDrawArraysIndirect_t)load_function("glDrawArraysIndirect");
    if (mgl_glDrawArraysIndirect == NULL)
        return 0;
    mgl_glDrawElementsIndirect = (mgl_glDrawElementsIndirect_t)load_function("glDrawElementsIndirect");
    if (mgl_glDrawElementsIndirect == NULL)
        return 0;
    mgl_glUniform1d = (mgl_glUniform1d_t)load_function("glUniform1d");
    if (mgl_glUniform1d == NULL)
        return 0;
    mgl_glUniform2d = (mgl_glUniform2d_t)load_function("glUniform2d");
    if (mgl_glUniform2d == NULL)
        return 0;
    mgl_glUniform3d = (mgl_glUniform3d_t)load_function("glUniform3d");
    if (mgl_glUniform3d == NULL)
        return 0;
    mgl_glUniform4d = (mgl_glUniform4d_t)load_function("glUniform4d");
    if (mgl_glUniform4d == NULL)
        return 0;
    mgl_glUniform1dv = (mgl_glUniform1dv_t)load_function("glUniform1dv");
    if (mgl_glUniform1dv == NULL)
        return 0;
    mgl_glUniform2dv = (mgl_glUniform2dv_t)load_function("glUniform2dv");
    if (mgl_glUniform2dv == NULL)
        return 0;
    mgl_glUniform3dv = (mgl_glUniform3dv_t)load_function("glUniform3dv");
    if (mgl_glUniform3dv == NULL)
        return 0;
    mgl_glUniform4dv = (mgl_glUniform4dv_t)load_function("glUniform4dv");
    if (mgl_glUniform4dv == NULL)
        return 0;
    mgl_glUniformMatrix2dv = (mgl_glUniformMatrix2dv_t)load_function("glUniformMatrix2dv");
    if (mgl_glUniformMatrix2dv == NULL)
        return 0;
    mgl_glUniformMatrix3dv = (mgl_glUniformMatrix3dv_t)load_function("glUniformMatrix3dv");
    if (mgl_glUniformMatrix3dv == NULL)
        return 0;
    mgl_glUniformMatrix4dv = (mgl_glUniformMatrix4dv_t)load_function("glUniformMatrix4dv");
    if (mgl_glUniformMatrix4dv == NULL)
        return 0;
    mgl_glUniformMatrix2x3dv = (mgl_glUniformMatrix2x3dv_t)load_function("glUniformMatrix2x3dv");
    if (mgl_glUniformMatrix2x3dv == NULL)
        return 0;
    mgl_glUniformMatrix2x4dv = (mgl_glUniformMatrix2x4dv_t)load_function("glUniformMatrix2x4dv");
    if (mgl_glUniformMatrix2x4dv == NULL)
        return 0;
    mgl_glUniformMatrix3x2dv = (mgl_glUniformMatrix3x2dv_t)load_function("glUniformMatrix3x2dv");
    if (mgl_glUniformMatrix3x2dv == NULL)
        return 0;
    mgl_glUniformMatrix3x4dv = (mgl_glUniformMatrix3x4dv_t)load_function("glUniformMatrix3x4dv");
    if (mgl_glUniformMatrix3x4dv == NULL)
        return 0;
    mgl_glUniformMatrix4x2dv = (mgl_glUniformMatrix4x2dv_t)load_function("glUniformMatrix4x2dv");
    if (mgl_glUniformMatrix4x2dv == NULL)
        return 0;
    mgl_glUniformMatrix4x3dv = (mgl_glUniformMatrix4x3dv_t)load_function("glUniformMatrix4x3dv");
    if (mgl_glUniformMatrix4x3dv == NULL)
        return 0;
    mgl_glGetUniformdv = (mgl_glGetUniformdv_t)load_function("glGetUniformdv");
    if (mgl_glGetUniformdv == NULL)
        return 0;
    mgl_glGetSubroutineUniformLocation = (mgl_glGetSubroutineUniformLocation_t)load_function("glGetSubroutineUniformLocation");
    if (mgl_glGetSubroutineUniformLocation == NULL)
        return 0;
    mgl_glGetSubroutineIndex = (mgl_glGetSubroutineIndex_t)load_function("glGetSubroutineIndex");
    if (mgl_glGetSubroutineIndex == NULL)
        return 0;
    mgl_glGetActiveSubroutineUniformiv = (mgl_glGetActiveSubroutineUniformiv_t)load_function("glGetActiveSubroutineUniformiv");
    if (mgl_glGetActiveSubroutineUniformiv == NULL)
        return 0;
    mgl_glGetActiveSubroutineUniformName = (mgl_glGetActiveSubroutineUniformName_t)load_function("glGetActiveSubroutineUniformName");
    if (mgl_glGetActiveSubroutineUniformName == NULL)
        return 0;
    mgl_glGetActiveSubroutineName = (mgl_glGetActiveSubroutineName_t)load_function("glGetActiveSubroutineName");
    if (mgl_glGetActiveSubroutineName == NULL)
        return 0;
    mgl_glUniformSubroutinesuiv = (mgl_glUniformSubroutinesuiv_t)load_function("glUniformSubroutinesuiv");
    if (mgl_glUniformSubroutinesuiv == NULL)
        return 0;
    mgl_glGetUniformSubroutineuiv = (mgl_glGetUniformSubroutineuiv_t)load_function("glGetUniformSubroutineuiv");
    if (mgl_glGetUniformSubroutineuiv == NULL)
        return 0;
    mgl_glGetProgramStageiv = (mgl_glGetProgramStageiv_t)load_function("glGetProgramStageiv");
    if (mgl_glGetProgramStageiv == NULL)
        return 0;
    mgl_glPatchParameteri = (mgl_glPatchParameteri_t)load_function("glPatchParameteri");
    if (mgl_glPatchParameteri == NULL)
        return 0;
    mgl_glPatchParameterfv = (mgl_glPatchParameterfv_t)load_function("glPatchParameterfv");
    if (mgl_glPatchParameterfv == NULL)
        return 0;
    mgl_glBindTransformFeedback = (mgl_glBindTransformFeedback_t)load_function("glBindTransformFeedback");
    if (mgl_glBindTransformFeedback == NULL)
        return 0;
    mgl_glDeleteTransformFeedbacks = (mgl_glDeleteTransformFeedbacks_t)load_function("glDeleteTransformFeedbacks");
    if (mgl_glDeleteTransformFeedbacks == NULL)
        return 0;
    mgl_glGenTransformFeedbacks = (mgl_glGenTransformFeedbacks_t)load_function("glGenTransformFeedbacks");
    if (mgl_glGenTransformFeedbacks == NULL)
        return 0;
    mgl_glIsTransformFeedback = (mgl_glIsTransformFeedback_t)load_function("glIsTransformFeedback");
    if (mgl_glIsTransformFeedback == NULL)
        return 0;
    mgl_glPauseTransformFeedback = (mgl_glPauseTransformFeedback_t)load_function("glPauseTransformFeedback");
    if (mgl_glPauseTransformFeedback == NULL)
        return 0;
    mgl_glResumeTransformFeedback = (mgl_glResumeTransformFeedback_t)load_function("glResumeTransformFeedback");
    if (mgl_glResumeTransformFeedback == NULL)
        return 0;
    mgl_glDrawTransformFeedback = (mgl_glDrawTransformFeedback_t)load_function("glDrawTransformFeedback");
    if (mgl_glDrawTransformFeedback == NULL)
        return 0;
    mgl_glDrawTransformFeedbackStream = (mgl_glDrawTransformFeedbackStream_t)load_function("glDrawTransformFeedbackStream");
    if (mgl_glDrawTransformFeedbackStream == NULL)
        return 0;
    mgl_glBeginQueryIndexed = (mgl_glBeginQueryIndexed_t)load_function("glBeginQueryIndexed");
    if (mgl_glBeginQueryIndexed == NULL)
        return 0;
    mgl_glEndQueryIndexed = (mgl_glEndQueryIndexed_t)load_function("glEndQueryIndexed");
    if (mgl_glEndQueryIndexed == NULL)
        return 0;
    mgl_glGetQueryIndexediv = (mgl_glGetQueryIndexediv_t)load_function("glGetQueryIndexediv");
    if (mgl_glGetQueryIndexediv == NULL)
        return 0;
    mgl_glReleaseShaderCompiler = (mgl_glReleaseShaderCompiler_t)load_function("glReleaseShaderCompiler");
    if (mgl_glReleaseShaderCompiler == NULL)
        return 0;
    mgl_glShaderBinary = (mgl_glShaderBinary_t)load_function("glShaderBinary");
    if (mgl_glShaderBinary == NULL)
        return 0;
    mgl_glGetShaderPrecisionFormat = (mgl_glGetShaderPrecisionFormat_t)load_function("glGetShaderPrecisionFormat");
    if (mgl_glGetShaderPrecisionFormat == NULL)
        return 0;
    mgl_glDepthRangef = (mgl_glDepthRangef_t)load_function("glDepthRangef");
    if (mgl_glDepthRangef == NULL)
        return 0;
    mgl_glClearDepthf = (mgl_glClearDepthf_t)load_function("glClearDepthf");
    if (mgl_glClearDepthf == NULL)
        return 0;
    mgl_glGetProgramBinary = (mgl_glGetProgramBinary_t)load_function("glGetProgramBinary");
    if (mgl_glGetProgramBinary == NULL)
        return 0;
    mgl_glProgramBinary = (mgl_glProgramBinary_t)load_function("glProgramBinary");
    if (mgl_glProgramBinary == NULL)
        return 0;
    mgl_glProgramParameteri = (mgl_glProgramParameteri_t)load_function("glProgramParameteri");
    if (mgl_glProgramParameteri == NULL)
        return 0;
    mgl_glUseProgramStages = (mgl_glUseProgramStages_t)load_function("glUseProgramStages");
    if (mgl_glUseProgramStages == NULL)
        return 0;
    mgl_glActiveShaderProgram = (mgl_glActiveShaderProgram_t)load_function("glActiveShaderProgram");
    if (mgl_glActiveShaderProgram == NULL)
        return 0;
    mgl_glCreateShaderProgramv = (mgl_glCreateShaderProgramv_t)load_function("glCreateShaderProgramv");
    if (mgl_glCreateShaderProgramv == NULL)
        return 0;
    mgl_glBindProgramPipeline = (mgl_glBindProgramPipeline_t)load_function("glBindProgramPipeline");
    if (mgl_glBindProgramPipeline == NULL)
        return 0;
    mgl_glDeleteProgramPipelines = (mgl_glDeleteProgramPipelines_t)load_function("glDeleteProgramPipelines");
    if (mgl_glDeleteProgramPipelines == NULL)
        return 0;
    mgl_glGenProgramPipelines = (mgl_glGenProgramPipelines_t)load_function("glGenProgramPipelines");
    if (mgl_glGenProgramPipelines == NULL)
        return 0;
    mgl_glIsProgramPipeline = (mgl_glIsProgramPipeline_t)load_function("glIsProgramPipeline");
    if (mgl_glIsProgramPipeline == NULL)
        return 0;
    mgl_glGetProgramPipelineiv = (mgl_glGetProgramPipelineiv_t)load_function("glGetProgramPipelineiv");
    if (mgl_glGetProgramPipelineiv == NULL)
        return 0;
    mgl_glProgramUniform1i = (mgl_glProgramUniform1i_t)load_function("glProgramUniform1i");
    if (mgl_glProgramUniform1i == NULL)
        return 0;
    mgl_glProgramUniform1iv = (mgl_glProgramUniform1iv_t)load_function("glProgramUniform1iv");
    if (mgl_glProgramUniform1iv == NULL)
        return 0;
    mgl_glProgramUniform1f = (mgl_glProgramUniform1f_t)load_function("glProgramUniform1f");
    if (mgl_glProgramUniform1f == NULL)
        return 0;
    mgl_glProgramUniform1fv = (mgl_glProgramUniform1fv_t)load_function("glProgramUniform1fv");
    if (mgl_glProgramUniform1fv == NULL)
        return 0;
    mgl_glProgramUniform1d = (mgl_glProgramUniform1d_t)load_function("glProgramUniform1d");
    if (mgl_glProgramUniform1d == NULL)
        return 0;
    mgl_glProgramUniform1dv = (mgl_glProgramUniform1dv_t)load_function("glProgramUniform1dv");
    if (mgl_glProgramUniform1dv == NULL)
        return 0;
    mgl_glProgramUniform1ui = (mgl_glProgramUniform1ui_t)load_function("glProgramUniform1ui");
    if (mgl_glProgramUniform1ui == NULL)
        return 0;
    mgl_glProgramUniform1uiv = (mgl_glProgramUniform1uiv_t)load_function("glProgramUniform1uiv");
    if (mgl_glProgramUniform1uiv == NULL)
        return 0;
    mgl_glProgramUniform2i = (mgl_glProgramUniform2i_t)load_function("glProgramUniform2i");
    if (mgl_glProgramUniform2i == NULL)
        return 0;
    mgl_glProgramUniform2iv = (mgl_glProgramUniform2iv_t)load_function("glProgramUniform2iv");
    if (mgl_glProgramUniform2iv == NULL)
        return 0;
    mgl_glProgramUniform2f = (mgl_glProgramUniform2f_t)load_function("glProgramUniform2f");
    if (mgl_glProgramUniform2f == NULL)
        return 0;
    mgl_glProgramUniform2fv = (mgl_glProgramUniform2fv_t)load_function("glProgramUniform2fv");
    if (mgl_glProgramUniform2fv == NULL)
        return 0;
    mgl_glProgramUniform2d = (mgl_glProgramUniform2d_t)load_function("glProgramUniform2d");
    if (mgl_glProgramUniform2d == NULL)
        return 0;
    mgl_glProgramUniform2dv = (mgl_glProgramUniform2dv_t)load_function("glProgramUniform2dv");
    if (mgl_glProgramUniform2dv == NULL)
        return 0;
    mgl_glProgramUniform2ui = (mgl_glProgramUniform2ui_t)load_function("glProgramUniform2ui");
    if (mgl_glProgramUniform2ui == NULL)
        return 0;
    mgl_glProgramUniform2uiv = (mgl_glProgramUniform2uiv_t)load_function("glProgramUniform2uiv");
    if (mgl_glProgramUniform2uiv == NULL)
        return 0;
    mgl_glProgramUniform3i = (mgl_glProgramUniform3i_t)load_function("glProgramUniform3i");
    if (mgl_glProgramUniform3i == NULL)
        return 0;
    mgl_glProgramUniform3iv = (mgl_glProgramUniform3iv_t)load_function("glProgramUniform3iv");
    if (mgl_glProgramUniform3iv == NULL)
        return 0;
    mgl_glProgramUniform3f = (mgl_glProgramUniform3f_t)load_function("glProgramUniform3f");
    if (mgl_glProgramUniform3f == NULL)
        return 0;
    mgl_glProgramUniform3fv = (mgl_glProgramUniform3fv_t)load_function("glProgramUniform3fv");
    if (mgl_glProgramUniform3fv == NULL)
        return 0;
    mgl_glProgramUniform3d = (mgl_glProgramUniform3d_t)load_function("glProgramUniform3d");
    if (mgl_glProgramUniform3d == NULL)
        return 0;
    mgl_glProgramUniform3dv = (mgl_glProgramUniform3dv_t)load_function("glProgramUniform3dv");
    if (mgl_glProgramUniform3dv == NULL)
        return 0;
    mgl_glProgramUniform3ui = (mgl_glProgramUniform3ui_t)load_function("glProgramUniform3ui");
    if (mgl_glProgramUniform3ui == NULL)
        return 0;
    mgl_glProgramUniform3uiv = (mgl_glProgramUniform3uiv_t)load_function("glProgramUniform3uiv");
    if (mgl_glProgramUniform3uiv == NULL)
        return 0;
    mgl_glProgramUniform4i = (mgl_glProgramUniform4i_t)load_function("glProgramUniform4i");
    if (mgl_glProgramUniform4i == NULL)
        return 0;
    mgl_glProgramUniform4iv = (mgl_glProgramUniform4iv_t)load_function("glProgramUniform4iv");
    if (mgl_glProgramUniform4iv == NULL)
        return 0;
    mgl_glProgramUniform4f = (mgl_glProgramUniform4f_t)load_function("glProgramUniform4f");
    if (mgl_glProgramUniform4f == NULL)
        return 0;
    mgl_glProgramUniform4fv = (mgl_glProgramUniform4fv_t)load_function("glProgramUniform4fv");
    if (mgl_glProgramUniform4fv == NULL)
        return 0;
    mgl_glProgramUniform4d = (mgl_glProgramUniform4d_t)load_function("glProgramUniform4d");
    if (mgl_glProgramUniform4d == NULL)
        return 0;
    mgl_glProgramUniform4dv = (mgl_glProgramUniform4dv_t)load_function("glProgramUniform4dv");
    if (mgl_glProgramUniform4dv == NULL)
        return 0;
    mgl_glProgramUniform4ui = (mgl_glProgramUniform4ui_t)load_function("glProgramUniform4ui");
    if (mgl_glProgramUniform4ui == NULL)
        return 0;
    mgl_glProgramUniform4uiv = (mgl_glProgramUniform4uiv_t)load_function("glProgramUniform4uiv");
    if (mgl_glProgramUniform4uiv == NULL)
        return 0;
    mgl_glProgramUniformMatrix2fv = (mgl_glProgramUniformMatrix2fv_t)load_function("glProgramUniformMatrix2fv");
    if (mgl_glProgramUniformMatrix2fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix3fv = (mgl_glProgramUniformMatrix3fv_t)load_function("glProgramUniformMatrix3fv");
    if (mgl_glProgramUniformMatrix3fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix4fv = (mgl_glProgramUniformMatrix4fv_t)load_function("glProgramUniformMatrix4fv");
    if (mgl_glProgramUniformMatrix4fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix2dv = (mgl_glProgramUniformMatrix2dv_t)load_function("glProgramUniformMatrix2dv");
    if (mgl_glProgramUniformMatrix2dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix3dv = (mgl_glProgramUniformMatrix3dv_t)load_function("glProgramUniformMatrix3dv");
    if (mgl_glProgramUniformMatrix3dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix4dv = (mgl_glProgramUniformMatrix4dv_t)load_function("glProgramUniformMatrix4dv");
    if (mgl_glProgramUniformMatrix4dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix2x3fv = (mgl_glProgramUniformMatrix2x3fv_t)load_function("glProgramUniformMatrix2x3fv");
    if (mgl_glProgramUniformMatrix2x3fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix3x2fv = (mgl_glProgramUniformMatrix3x2fv_t)load_function("glProgramUniformMatrix3x2fv");
    if (mgl_glProgramUniformMatrix3x2fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix2x4fv = (mgl_glProgramUniformMatrix2x4fv_t)load_function("glProgramUniformMatrix2x4fv");
    if (mgl_glProgramUniformMatrix2x4fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix4x2fv = (mgl_glProgramUniformMatrix4x2fv_t)load_function("glProgramUniformMatrix4x2fv");
    if (mgl_glProgramUniformMatrix4x2fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix3x4fv = (mgl_glProgramUniformMatrix3x4fv_t)load_function("glProgramUniformMatrix3x4fv");
    if (mgl_glProgramUniformMatrix3x4fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix4x3fv = (mgl_glProgramUniformMatrix4x3fv_t)load_function("glProgramUniformMatrix4x3fv");
    if (mgl_glProgramUniformMatrix4x3fv == NULL)
        return 0;
    mgl_glProgramUniformMatrix2x3dv = (mgl_glProgramUniformMatrix2x3dv_t)load_function("glProgramUniformMatrix2x3dv");
    if (mgl_glProgramUniformMatrix2x3dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix3x2dv = (mgl_glProgramUniformMatrix3x2dv_t)load_function("glProgramUniformMatrix3x2dv");
    if (mgl_glProgramUniformMatrix3x2dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix2x4dv = (mgl_glProgramUniformMatrix2x4dv_t)load_function("glProgramUniformMatrix2x4dv");
    if (mgl_glProgramUniformMatrix2x4dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix4x2dv = (mgl_glProgramUniformMatrix4x2dv_t)load_function("glProgramUniformMatrix4x2dv");
    if (mgl_glProgramUniformMatrix4x2dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix3x4dv = (mgl_glProgramUniformMatrix3x4dv_t)load_function("glProgramUniformMatrix3x4dv");
    if (mgl_glProgramUniformMatrix3x4dv == NULL)
        return 0;
    mgl_glProgramUniformMatrix4x3dv = (mgl_glProgramUniformMatrix4x3dv_t)load_function("glProgramUniformMatrix4x3dv");
    if (mgl_glProgramUniformMatrix4x3dv == NULL)
        return 0;
    mgl_glValidateProgramPipeline = (mgl_glValidateProgramPipeline_t)load_function("glValidateProgramPipeline");
    if (mgl_glValidateProgramPipeline == NULL)
        return 0;
    mgl_glGetProgramPipelineInfoLog = (mgl_glGetProgramPipelineInfoLog_t)load_function("glGetProgramPipelineInfoLog");
    if (mgl_glGetProgramPipelineInfoLog == NULL)
        return 0;
    mgl_glVertexAttribL1d = (mgl_glVertexAttribL1d_t)load_function("glVertexAttribL1d");
    if (mgl_glVertexAttribL1d == NULL)
        return 0;
    mgl_glVertexAttribL2d = (mgl_glVertexAttribL2d_t)load_function("glVertexAttribL2d");
    if (mgl_glVertexAttribL2d == NULL)
        return 0;
    mgl_glVertexAttribL3d = (mgl_glVertexAttribL3d_t)load_function("glVertexAttribL3d");
    if (mgl_glVertexAttribL3d == NULL)
        return 0;
    mgl_glVertexAttribL4d = (mgl_glVertexAttribL4d_t)load_function("glVertexAttribL4d");
    if (mgl_glVertexAttribL4d == NULL)
        return 0;
    mgl_glVertexAttribL1dv = (mgl_glVertexAttribL1dv_t)load_function("glVertexAttribL1dv");
    if (mgl_glVertexAttribL1dv == NULL)
        return 0;
    mgl_glVertexAttribL2dv = (mgl_glVertexAttribL2dv_t)load_function("glVertexAttribL2dv");
    if (mgl_glVertexAttribL2dv == NULL)
        return 0;
    mgl_glVertexAttribL3dv = (mgl_glVertexAttribL3dv_t)load_function("glVertexAttribL3dv");
    if (mgl_glVertexAttribL3dv == NULL)
        return 0;
    mgl_glVertexAttribL4dv = (mgl_glVertexAttribL4dv_t)load_function("glVertexAttribL4dv");
    if (mgl_glVertexAttribL4dv == NULL)
        return 0;
    mgl_glVertexAttribLPointer = (mgl_glVertexAttribLPointer_t)load_function("glVertexAttribLPointer");
    if (mgl_glVertexAttribLPointer == NULL)
        return 0;
    mgl_glGetVertexAttribLdv = (mgl_glGetVertexAttribLdv_t)load_function("glGetVertexAttribLdv");
    if (mgl_glGetVertexAttribLdv == NULL)
        return 0;
    mgl_glViewportArrayv = (mgl_glViewportArrayv_t)load_function("glViewportArrayv");
    if (mgl_glViewportArrayv == NULL)
        return 0;
    mgl_glViewportIndexedf = (mgl_glViewportIndexedf_t)load_function("glViewportIndexedf");
    if (mgl_glViewportIndexedf == NULL)
        return 0;
    mgl_glViewportIndexedfv = (mgl_glViewportIndexedfv_t)load_function("glViewportIndexedfv");
    if (mgl_glViewportIndexedfv == NULL)
        return 0;
    mgl_glScissorArrayv = (mgl_glScissorArrayv_t)load_function("glScissorArrayv");
    if (mgl_glScissorArrayv == NULL)
        return 0;
    mgl_glScissorIndexed = (mgl_glScissorIndexed_t)load_function("glScissorIndexed");
    if (mgl_glScissorIndexed == NULL)
        return 0;
    mgl_glScissorIndexedv = (mgl_glScissorIndexedv_t)load_function("glScissorIndexedv");
    if (mgl_glScissorIndexedv == NULL)
        return 0;
    mgl_glDepthRangeArrayv = (mgl_glDepthRangeArrayv_t)load_function("glDepthRangeArrayv");
    if (mgl_glDepthRangeArrayv == NULL)
        return 0;
    mgl_glDepthRangeIndexed = (mgl_glDepthRangeIndexed_t)load_function("glDepthRangeIndexed");
    if (mgl_glDepthRangeIndexed == NULL)
        return 0;
    mgl_glGetFloati_v = (mgl_glGetFloati_v_t)load_function("glGetFloati_v");
    if (mgl_glGetFloati_v == NULL)
        return 0;
    mgl_glGetDoublei_v = (mgl_glGetDoublei_v_t)load_function("glGetDoublei_v");
    if (mgl_glGetDoublei_v == NULL)
        return 0;
    mgl_glDrawArraysInstancedBaseInstance = (mgl_glDrawArraysInstancedBaseInstance_t)load_function("glDrawArraysInstancedBaseInstance");
    if (mgl_glDrawArraysInstancedBaseInstance == NULL)
        return 0;
    mgl_glDrawElementsInstancedBaseInstance = (mgl_glDrawElementsInstancedBaseInstance_t)load_function("glDrawElementsInstancedBaseInstance");
    if (mgl_glDrawElementsInstancedBaseInstance == NULL)
        return 0;
    mgl_glDrawElementsInstancedBaseVertexBaseInstance = (mgl_glDrawElementsInstancedBaseVertexBaseInstance_t)load_function("glDrawElementsInstancedBaseVertexBaseInstance");
    if (mgl_glDrawElementsInstancedBaseVertexBaseInstance == NULL)
        return 0;
    mgl_glGetInternalformativ = (mgl_glGetInternalformativ_t)load_function("glGetInternalformativ");
    if (mgl_glGetInternalformativ == NULL)
        return 0;
    mgl_glGetActiveAtomicCounterBufferiv = (mgl_glGetActiveAtomicCounterBufferiv_t)load_function("glGetActiveAtomicCounterBufferiv");
    if (mgl_glGetActiveAtomicCounterBufferiv == NULL)
        return 0;
    mgl_glBindImageTexture = (mgl_glBindImageTexture_t)load_function("glBindImageTexture");
    if (mgl_glBindImageTexture == NULL)
        return 0;
    mgl_glMemoryBarrier = (mgl_glMemoryBarrier_t)load_function("glMemoryBarrier");
    if (mgl_glMemoryBarrier == NULL)
        return 0;
    mgl_glTexStorage1D = (mgl_glTexStorage1D_t)load_function("glTexStorage1D");
    if (mgl_glTexStorage1D == NULL)
        return 0;
    mgl_glTexStorage2D = (mgl_glTexStorage2D_t)load_function("glTexStorage2D");
    if (mgl_glTexStorage2D == NULL)
        return 0;
    mgl_glTexStorage3D = (mgl_glTexStorage3D_t)load_function("glTexStorage3D");
    if (mgl_glTexStorage3D == NULL)
        return 0;
    mgl_glDrawTransformFeedbackInstanced = (mgl_glDrawTransformFeedbackInstanced_t)load_function("glDrawTransformFeedbackInstanced");
    if (mgl_glDrawTransformFeedbackInstanced == NULL)
        return 0;
    mgl_glDrawTransformFeedbackStreamInstanced = (mgl_glDrawTransformFeedbackStreamInstanced_t)load_function("glDrawTransformFeedbackStreamInstanced");
    if (mgl_glDrawTransformFeedbackStreamInstanced == NULL)
        return 0;
    mgl_glClearBufferData = (mgl_glClearBufferData_t)load_function("glClearBufferData");
    if (mgl_glClearBufferData == NULL)
        return 0;
    mgl_glClearBufferSubData = (mgl_glClearBufferSubData_t)load_function("glClearBufferSubData");
    if (mgl_glClearBufferSubData == NULL)
        return 0;
    mgl_glDispatchCompute = (mgl_glDispatchCompute_t)load_function("glDispatchCompute");
    if (mgl_glDispatchCompute == NULL)
        return 0;
    mgl_glDispatchComputeIndirect = (mgl_glDispatchComputeIndirect_t)load_function("glDispatchComputeIndirect");
    if (mgl_glDispatchComputeIndirect == NULL)
        return 0;
    mgl_glCopyImageSubData = (mgl_glCopyImageSubData_t)load_function("glCopyImageSubData");
    if (mgl_glCopyImageSubData == NULL)
        return 0;
    mgl_glFramebufferParameteri = (mgl_glFramebufferParameteri_t)load_function("glFramebufferParameteri");
    if (mgl_glFramebufferParameteri == NULL)
        return 0;
    mgl_glGetFramebufferParameteriv = (mgl_glGetFramebufferParameteriv_t)load_function("glGetFramebufferParameteriv");
    if (mgl_glGetFramebufferParameteriv == NULL)
        return 0;
    mgl_glGetInternalformati64v = (mgl_glGetInternalformati64v_t)load_function("glGetInternalformati64v");
    if (mgl_glGetInternalformati64v == NULL)
        return 0;
    mgl_glInvalidateTexSubImage = (mgl_glInvalidateTexSubImage_t)load_function("glInvalidateTexSubImage");
    if (mgl_glInvalidateTexSubImage == NULL)
        return 0;
    mgl_glInvalidateTexImage = (mgl_glInvalidateTexImage_t)load_function("glInvalidateTexImage");
    if (mgl_glInvalidateTexImage == NULL)
        return 0;
    mgl_glInvalidateBufferSubData = (mgl_glInvalidateBufferSubData_t)load_function("glInvalidateBufferSubData");
    if (mgl_glInvalidateBufferSubData == NULL)
        return 0;
    mgl_glInvalidateBufferData = (mgl_glInvalidateBufferData_t)load_function("glInvalidateBufferData");
    if (mgl_glInvalidateBufferData == NULL)
        return 0;
    mgl_glInvalidateFramebuffer = (mgl_glInvalidateFramebuffer_t)load_function("glInvalidateFramebuffer");
    if (mgl_glInvalidateFramebuffer == NULL)
        return 0;
    mgl_glInvalidateSubFramebuffer = (mgl_glInvalidateSubFramebuffer_t)load_function("glInvalidateSubFramebuffer");
    if (mgl_glInvalidateSubFramebuffer == NULL)
        return 0;
    mgl_glMultiDrawArraysIndirect = (mgl_glMultiDrawArraysIndirect_t)load_function("glMultiDrawArraysIndirect");
    if (mgl_glMultiDrawArraysIndirect == NULL)
        return 0;
    mgl_glMultiDrawElementsIndirect = (mgl_glMultiDrawElementsIndirect_t)load_function("glMultiDrawElementsIndirect");
    if (mgl_glMultiDrawElementsIndirect == NULL)
        return 0;
    mgl_glGetProgramInterfaceiv = (mgl_glGetProgramInterfaceiv_t)load_function("glGetProgramInterfaceiv");
    if (mgl_glGetProgramInterfaceiv == NULL)
        return 0;
    mgl_glGetProgramResourceIndex = (mgl_glGetProgramResourceIndex_t)load_function("glGetProgramResourceIndex");
    if (mgl_glGetProgramResourceIndex == NULL)
        return 0;
    mgl_glGetProgramResourceName = (mgl_glGetProgramResourceName_t)load_function("glGetProgramResourceName");
    if (mgl_glGetProgramResourceName == NULL)
        return 0;
    mgl_glGetProgramResourceiv = (mgl_glGetProgramResourceiv_t)load_function("glGetProgramResourceiv");
    if (mgl_glGetProgramResourceiv == NULL)
        return 0;
    mgl_glGetProgramResourceLocation = (mgl_glGetProgramResourceLocation_t)load_function("glGetProgramResourceLocation");
    if (mgl_glGetProgramResourceLocation == NULL)
        return 0;
    mgl_glGetProgramResourceLocationIndex = (mgl_glGetProgramResourceLocationIndex_t)load_function("glGetProgramResourceLocationIndex");
    if (mgl_glGetProgramResourceLocationIndex == NULL)
        return 0;
    mgl_glShaderStorageBlockBinding = (mgl_glShaderStorageBlockBinding_t)load_function("glShaderStorageBlockBinding");
    if (mgl_glShaderStorageBlockBinding == NULL)
        return 0;
    mgl_glTexBufferRange = (mgl_glTexBufferRange_t)load_function("glTexBufferRange");
    if (mgl_glTexBufferRange == NULL)
        return 0;
    mgl_glTexStorage2DMultisample = (mgl_glTexStorage2DMultisample_t)load_function("glTexStorage2DMultisample");
    if (mgl_glTexStorage2DMultisample == NULL)
        return 0;
    mgl_glTexStorage3DMultisample = (mgl_glTexStorage3DMultisample_t)load_function("glTexStorage3DMultisample");
    if (mgl_glTexStorage3DMultisample == NULL)
        return 0;
    mgl_glTextureView = (mgl_glTextureView_t)load_function("glTextureView");
    if (mgl_glTextureView == NULL)
        return 0;
    mgl_glBindVertexBuffer = (mgl_glBindVertexBuffer_t)load_function("glBindVertexBuffer");
    if (mgl_glBindVertexBuffer == NULL)
        return 0;
    mgl_glVertexAttribFormat = (mgl_glVertexAttribFormat_t)load_function("glVertexAttribFormat");
    if (mgl_glVertexAttribFormat == NULL)
        return 0;
    mgl_glVertexAttribIFormat = (mgl_glVertexAttribIFormat_t)load_function("glVertexAttribIFormat");
    if (mgl_glVertexAttribIFormat == NULL)
        return 0;
    mgl_glVertexAttribLFormat = (mgl_glVertexAttribLFormat_t)load_function("glVertexAttribLFormat");
    if (mgl_glVertexAttribLFormat == NULL)
        return 0;
    mgl_glVertexAttribBinding = (mgl_glVertexAttribBinding_t)load_function("glVertexAttribBinding");
    if (mgl_glVertexAttribBinding == NULL)
        return 0;
    mgl_glVertexBindingDivisor = (mgl_glVertexBindingDivisor_t)load_function("glVertexBindingDivisor");
    if (mgl_glVertexBindingDivisor == NULL)
        return 0;
    mgl_glDebugMessageControl = (mgl_glDebugMessageControl_t)load_function("glDebugMessageControl");
    if (mgl_glDebugMessageControl == NULL)
        return 0;
    mgl_glDebugMessageInsert = (mgl_glDebugMessageInsert_t)load_function("glDebugMessageInsert");
    if (mgl_glDebugMessageInsert == NULL)
        return 0;
    mgl_glDebugMessageCallback = (mgl_glDebugMessageCallback_t)load_function("glDebugMessageCallback");
    if (mgl_glDebugMessageCallback == NULL)
        return 0;
    mgl_glGetDebugMessageLog = (mgl_glGetDebugMessageLog_t)load_function("glGetDebugMessageLog");
    if (mgl_glGetDebugMessageLog == NULL)
        return 0;
    mgl_glPushDebugGroup = (mgl_glPushDebugGroup_t)load_function("glPushDebugGroup");
    if (mgl_glPushDebugGroup == NULL)
        return 0;
    mgl_glPopDebugGroup = (mgl_glPopDebugGroup_t)load_function("glPopDebugGroup");
    if (mgl_glPopDebugGroup == NULL)
        return 0;
    mgl_glObjectLabel = (mgl_glObjectLabel_t)load_function("glObjectLabel");
    if (mgl_glObjectLabel == NULL)
        return 0;
    mgl_glGetObjectLabel = (mgl_glGetObjectLabel_t)load_function("glGetObjectLabel");
    if (mgl_glGetObjectLabel == NULL)
        return 0;
    mgl_glObjectPtrLabel = (mgl_glObjectPtrLabel_t)load_function("glObjectPtrLabel");
    if (mgl_glObjectPtrLabel == NULL)
        return 0;
    mgl_glGetObjectPtrLabel = (mgl_glGetObjectPtrLabel_t)load_function("glGetObjectPtrLabel");
    if (mgl_glGetObjectPtrLabel == NULL)
        return 0;
    mgl_glBufferStorage = (mgl_glBufferStorage_t)load_function("glBufferStorage");
    if (mgl_glBufferStorage == NULL)
        return 0;
    mgl_glClearTexImage = (mgl_glClearTexImage_t)load_function("glClearTexImage");
    if (mgl_glClearTexImage == NULL)
        return 0;
    mgl_glClearTexSubImage = (mgl_glClearTexSubImage_t)load_function("glClearTexSubImage");
    if (mgl_glClearTexSubImage == NULL)
        return 0;
    mgl_glBindBuffersBase = (mgl_glBindBuffersBase_t)load_function("glBindBuffersBase");
    if (mgl_glBindBuffersBase == NULL)
        return 0;
    mgl_glBindBuffersRange = (mgl_glBindBuffersRange_t)load_function("glBindBuffersRange");
    if (mgl_glBindBuffersRange == NULL)
        return 0;
    mgl_glBindTextures = (mgl_glBindTextures_t)load_function("glBindTextures");
    if (mgl_glBindTextures == NULL)
        return 0;
    mgl_glBindSamplers = (mgl_glBindSamplers_t)load_function("glBindSamplers");
    if (mgl_glBindSamplers == NULL)
        return 0;
    mgl_glBindImageTextures = (mgl_glBindImageTextures_t)load_function("glBindImageTextures");
    if (mgl_glBindImageTextures == NULL)
        return 0;
    mgl_glBindVertexBuffers = (mgl_glBindVertexBuffers_t)load_function("glBindVertexBuffers");
    if (mgl_glBindVertexBuffers == NULL)
        return 0;
    mgl_glClipControl = (mgl_glClipControl_t)load_function("glClipControl");
    if (mgl_glClipControl == NULL)
        return 0;
    mgl_glCreateTransformFeedbacks = (mgl_glCreateTransformFeedbacks_t)load_function("glCreateTransformFeedbacks");
    if (mgl_glCreateTransformFeedbacks == NULL)
        return 0;
    mgl_glTransformFeedbackBufferBase = (mgl_glTransformFeedbackBufferBase_t)load_function("glTransformFeedbackBufferBase");
    if (mgl_glTransformFeedbackBufferBase == NULL)
        return 0;
    mgl_glTransformFeedbackBufferRange = (mgl_glTransformFeedbackBufferRange_t)load_function("glTransformFeedbackBufferRange");
    if (mgl_glTransformFeedbackBufferRange == NULL)
        return 0;
    mgl_glGetTransformFeedbackiv = (mgl_glGetTransformFeedbackiv_t)load_function("glGetTransformFeedbackiv");
    if (mgl_glGetTransformFeedbackiv == NULL)
        return 0;
    mgl_glGetTransformFeedbacki_v = (mgl_glGetTransformFeedbacki_v_t)load_function("glGetTransformFeedbacki_v");
    if (mgl_glGetTransformFeedbacki_v == NULL)
        return 0;
    mgl_glGetTransformFeedbacki64_v = (mgl_glGetTransformFeedbacki64_v_t)load_function("glGetTransformFeedbacki64_v");
    if (mgl_glGetTransformFeedbacki64_v == NULL)
        return 0;
    mgl_glCreateBuffers = (mgl_glCreateBuffers_t)load_function("glCreateBuffers");
    if (mgl_glCreateBuffers == NULL)
        return 0;
    mgl_glNamedBufferStorage = (mgl_glNamedBufferStorage_t)load_function("glNamedBufferStorage");
    if (mgl_glNamedBufferStorage == NULL)
        return 0;
    mgl_glNamedBufferData = (mgl_glNamedBufferData_t)load_function("glNamedBufferData");
    if (mgl_glNamedBufferData == NULL)
        return 0;
    mgl_glNamedBufferSubData = (mgl_glNamedBufferSubData_t)load_function("glNamedBufferSubData");
    if (mgl_glNamedBufferSubData == NULL)
        return 0;
    mgl_glCopyNamedBufferSubData = (mgl_glCopyNamedBufferSubData_t)load_function("glCopyNamedBufferSubData");
    if (mgl_glCopyNamedBufferSubData == NULL)
        return 0;
    mgl_glClearNamedBufferData = (mgl_glClearNamedBufferData_t)load_function("glClearNamedBufferData");
    if (mgl_glClearNamedBufferData == NULL)
        return 0;
    mgl_glClearNamedBufferSubData = (mgl_glClearNamedBufferSubData_t)load_function("glClearNamedBufferSubData");
    if (mgl_glClearNamedBufferSubData == NULL)
        return 0;
    mgl_glMapNamedBuffer = (mgl_glMapNamedBuffer_t)load_function("glMapNamedBuffer");
    if (mgl_glMapNamedBuffer == NULL)
        return 0;
    mgl_glMapNamedBufferRange = (mgl_glMapNamedBufferRange_t)load_function("glMapNamedBufferRange");
    if (mgl_glMapNamedBufferRange == NULL)
        return 0;
    mgl_glUnmapNamedBuffer = (mgl_glUnmapNamedBuffer_t)load_function("glUnmapNamedBuffer");
    if (mgl_glUnmapNamedBuffer == NULL)
        return 0;
    mgl_glFlushMappedNamedBufferRange = (mgl_glFlushMappedNamedBufferRange_t)load_function("glFlushMappedNamedBufferRange");
    if (mgl_glFlushMappedNamedBufferRange == NULL)
        return 0;
    mgl_glGetNamedBufferParameteriv = (mgl_glGetNamedBufferParameteriv_t)load_function("glGetNamedBufferParameteriv");
    if (mgl_glGetNamedBufferParameteriv == NULL)
        return 0;
    mgl_glGetNamedBufferParameteri64v = (mgl_glGetNamedBufferParameteri64v_t)load_function("glGetNamedBufferParameteri64v");
    if (mgl_glGetNamedBufferParameteri64v == NULL)
        return 0;
    mgl_glGetNamedBufferPointerv = (mgl_glGetNamedBufferPointerv_t)load_function("glGetNamedBufferPointerv");
    if (mgl_glGetNamedBufferPointerv == NULL)
        return 0;
    mgl_glGetNamedBufferSubData = (mgl_glGetNamedBufferSubData_t)load_function("glGetNamedBufferSubData");
    if (mgl_glGetNamedBufferSubData == NULL)
        return 0;
    mgl_glCreateFramebuffers = (mgl_glCreateFramebuffers_t)load_function("glCreateFramebuffers");
    if (mgl_glCreateFramebuffers == NULL)
        return 0;
    mgl_glNamedFramebufferRenderbuffer = (mgl_glNamedFramebufferRenderbuffer_t)load_function("glNamedFramebufferRenderbuffer");
    if (mgl_glNamedFramebufferRenderbuffer == NULL)
        return 0;
    mgl_glNamedFramebufferParameteri = (mgl_glNamedFramebufferParameteri_t)load_function("glNamedFramebufferParameteri");
    if (mgl_glNamedFramebufferParameteri == NULL)
        return 0;
    mgl_glNamedFramebufferTexture = (mgl_glNamedFramebufferTexture_t)load_function("glNamedFramebufferTexture");
    if (mgl_glNamedFramebufferTexture == NULL)
        return 0;
    mgl_glNamedFramebufferTextureLayer = (mgl_glNamedFramebufferTextureLayer_t)load_function("glNamedFramebufferTextureLayer");
    if (mgl_glNamedFramebufferTextureLayer == NULL)
        return 0;
    mgl_glNamedFramebufferDrawBuffer = (mgl_glNamedFramebufferDrawBuffer_t)load_function("glNamedFramebufferDrawBuffer");
    if (mgl_glNamedFramebufferDrawBuffer == NULL)
        return 0;
    mgl_glNamedFramebufferDrawBuffers = (mgl_glNamedFramebufferDrawBuffers_t)load_function("glNamedFramebufferDrawBuffers");
    if (mgl_glNamedFramebufferDrawBuffers == NULL)
        return 0;
    mgl_glNamedFramebufferReadBuffer = (mgl_glNamedFramebufferReadBuffer_t)load_function("glNamedFramebufferReadBuffer");
    if (mgl_glNamedFramebufferReadBuffer == NULL)
        return 0;
    mgl_glInvalidateNamedFramebufferData = (mgl_glInvalidateNamedFramebufferData_t)load_function("glInvalidateNamedFramebufferData");
    if (mgl_glInvalidateNamedFramebufferData == NULL)
        return 0;
    mgl_glInvalidateNamedFramebufferSubData = (mgl_glInvalidateNamedFramebufferSubData_t)load_function("glInvalidateNamedFramebufferSubData");
    if (mgl_glInvalidateNamedFramebufferSubData == NULL)
        return 0;
    mgl_glClearNamedFramebufferiv = (mgl_glClearNamedFramebufferiv_t)load_function("glClearNamedFramebufferiv");
    if (mgl_glClearNamedFramebufferiv == NULL)
        return 0;
    mgl_glClearNamedFramebufferuiv = (mgl_glClearNamedFramebufferuiv_t)load_function("glClearNamedFramebufferuiv");
    if (mgl_glClearNamedFramebufferuiv == NULL)
        return 0;
    mgl_glClearNamedFramebufferfv = (mgl_glClearNamedFramebufferfv_t)load_function("glClearNamedFramebufferfv");
    if (mgl_glClearNamedFramebufferfv == NULL)
        return 0;
    mgl_glClearNamedFramebufferfi = (mgl_glClearNamedFramebufferfi_t)load_function("glClearNamedFramebufferfi");
    if (mgl_glClearNamedFramebufferfi == NULL)
        return 0;
    mgl_glBlitNamedFramebuffer = (mgl_glBlitNamedFramebuffer_t)load_function("glBlitNamedFramebuffer");
    if (mgl_glBlitNamedFramebuffer == NULL)
        return 0;
    mgl_glCheckNamedFramebufferStatus = (mgl_glCheckNamedFramebufferStatus_t)load_function("glCheckNamedFramebufferStatus");
    if (mgl_glCheckNamedFramebufferStatus == NULL)
        return 0;
    mgl_glGetNamedFramebufferParameteriv = (mgl_glGetNamedFramebufferParameteriv_t)load_function("glGetNamedFramebufferParameteriv");
    if (mgl_glGetNamedFramebufferParameteriv == NULL)
        return 0;
    mgl_glGetNamedFramebufferAttachmentParameteriv = (mgl_glGetNamedFramebufferAttachmentParameteriv_t)load_function("glGetNamedFramebufferAttachmentParameteriv");
    if (mgl_glGetNamedFramebufferAttachmentParameteriv == NULL)
        return 0;
    mgl_glCreateRenderbuffers = (mgl_glCreateRenderbuffers_t)load_function("glCreateRenderbuffers");
    if (mgl_glCreateRenderbuffers == NULL)
        return 0;
    mgl_glNamedRenderbufferStorage = (mgl_glNamedRenderbufferStorage_t)load_function("glNamedRenderbufferStorage");
    if (mgl_glNamedRenderbufferStorage == NULL)
        return 0;
    mgl_glNamedRenderbufferStorageMultisample = (mgl_glNamedRenderbufferStorageMultisample_t)load_function("glNamedRenderbufferStorageMultisample");
    if (mgl_glNamedRenderbufferStorageMultisample == NULL)
        return 0;
    mgl_glGetNamedRenderbufferParameteriv = (mgl_glGetNamedRenderbufferParameteriv_t)load_function("glGetNamedRenderbufferParameteriv");
    if (mgl_glGetNamedRenderbufferParameteriv == NULL)
        return 0;
    mgl_glCreateTextures = (mgl_glCreateTextures_t)load_function("glCreateTextures");
    if (mgl_glCreateTextures == NULL)
        return 0;
    mgl_glTextureBuffer = (mgl_glTextureBuffer_t)load_function("glTextureBuffer");
    if (mgl_glTextureBuffer == NULL)
        return 0;
    mgl_glTextureBufferRange = (mgl_glTextureBufferRange_t)load_function("glTextureBufferRange");
    if (mgl_glTextureBufferRange == NULL)
        return 0;
    mgl_glTextureStorage1D = (mgl_glTextureStorage1D_t)load_function("glTextureStorage1D");
    if (mgl_glTextureStorage1D == NULL)
        return 0;
    mgl_glTextureStorage2D = (mgl_glTextureStorage2D_t)load_function("glTextureStorage2D");
    if (mgl_glTextureStorage2D == NULL)
        return 0;
    mgl_glTextureStorage3D = (mgl_glTextureStorage3D_t)load_function("glTextureStorage3D");
    if (mgl_glTextureStorage3D == NULL)
        return 0;
    mgl_glTextureStorage2DMultisample = (mgl_glTextureStorage2DMultisample_t)load_function("glTextureStorage2DMultisample");
    if (mgl_glTextureStorage2DMultisample == NULL)
        return 0;
    mgl_glTextureStorage3DMultisample = (mgl_glTextureStorage3DMultisample_t)load_function("glTextureStorage3DMultisample");
    if (mgl_glTextureStorage3DMultisample == NULL)
        return 0;
    mgl_glTextureSubImage1D = (mgl_glTextureSubImage1D_t)load_function("glTextureSubImage1D");
    if (mgl_glTextureSubImage1D == NULL)
        return 0;
    mgl_glTextureSubImage2D = (mgl_glTextureSubImage2D_t)load_function("glTextureSubImage2D");
    if (mgl_glTextureSubImage2D == NULL)
        return 0;
    mgl_glTextureSubImage3D = (mgl_glTextureSubImage3D_t)load_function("glTextureSubImage3D");
    if (mgl_glTextureSubImage3D == NULL)
        return 0;
    mgl_glCompressedTextureSubImage1D = (mgl_glCompressedTextureSubImage1D_t)load_function("glCompressedTextureSubImage1D");
    if (mgl_glCompressedTextureSubImage1D == NULL)
        return 0;
    mgl_glCompressedTextureSubImage2D = (mgl_glCompressedTextureSubImage2D_t)load_function("glCompressedTextureSubImage2D");
    if (mgl_glCompressedTextureSubImage2D == NULL)
        return 0;
    mgl_glCompressedTextureSubImage3D = (mgl_glCompressedTextureSubImage3D_t)load_function("glCompressedTextureSubImage3D");
    if (mgl_glCompressedTextureSubImage3D == NULL)
        return 0;
    mgl_glCopyTextureSubImage1D = (mgl_glCopyTextureSubImage1D_t)load_function("glCopyTextureSubImage1D");
    if (mgl_glCopyTextureSubImage1D == NULL)
        return 0;
    mgl_glCopyTextureSubImage2D = (mgl_glCopyTextureSubImage2D_t)load_function("glCopyTextureSubImage2D");
    if (mgl_glCopyTextureSubImage2D == NULL)
        return 0;
    mgl_glCopyTextureSubImage3D = (mgl_glCopyTextureSubImage3D_t)load_function("glCopyTextureSubImage3D");
    if (mgl_glCopyTextureSubImage3D == NULL)
        return 0;
    mgl_glTextureParameterf = (mgl_glTextureParameterf_t)load_function("glTextureParameterf");
    if (mgl_glTextureParameterf == NULL)
        return 0;
    mgl_glTextureParameterfv = (mgl_glTextureParameterfv_t)load_function("glTextureParameterfv");
    if (mgl_glTextureParameterfv == NULL)
        return 0;
    mgl_glTextureParameteri = (mgl_glTextureParameteri_t)load_function("glTextureParameteri");
    if (mgl_glTextureParameteri == NULL)
        return 0;
    mgl_glTextureParameterIiv = (mgl_glTextureParameterIiv_t)load_function("glTextureParameterIiv");
    if (mgl_glTextureParameterIiv == NULL)
        return 0;
    mgl_glTextureParameterIuiv = (mgl_glTextureParameterIuiv_t)load_function("glTextureParameterIuiv");
    if (mgl_glTextureParameterIuiv == NULL)
        return 0;
    mgl_glTextureParameteriv = (mgl_glTextureParameteriv_t)load_function("glTextureParameteriv");
    if (mgl_glTextureParameteriv == NULL)
        return 0;
    mgl_glGenerateTextureMipmap = (mgl_glGenerateTextureMipmap_t)load_function("glGenerateTextureMipmap");
    if (mgl_glGenerateTextureMipmap == NULL)
        return 0;
    mgl_glBindTextureUnit = (mgl_glBindTextureUnit_t)load_function("glBindTextureUnit");
    if (mgl_glBindTextureUnit == NULL)
        return 0;
    mgl_glGetTextureImage = (mgl_glGetTextureImage_t)load_function("glGetTextureImage");
    if (mgl_glGetTextureImage == NULL)
        return 0;
    mgl_glGetCompressedTextureImage = (mgl_glGetCompressedTextureImage_t)load_function("glGetCompressedTextureImage");
    if (mgl_glGetCompressedTextureImage == NULL)
        return 0;
    mgl_glGetTextureLevelParameterfv = (mgl_glGetTextureLevelParameterfv_t)load_function("glGetTextureLevelParameterfv");
    if (mgl_glGetTextureLevelParameterfv == NULL)
        return 0;
    mgl_glGetTextureLevelParameteriv = (mgl_glGetTextureLevelParameteriv_t)load_function("glGetTextureLevelParameteriv");
    if (mgl_glGetTextureLevelParameteriv == NULL)
        return 0;
    mgl_glGetTextureParameterfv = (mgl_glGetTextureParameterfv_t)load_function("glGetTextureParameterfv");
    if (mgl_glGetTextureParameterfv == NULL)
        return 0;
    mgl_glGetTextureParameterIiv = (mgl_glGetTextureParameterIiv_t)load_function("glGetTextureParameterIiv");
    if (mgl_glGetTextureParameterIiv == NULL)
        return 0;
    mgl_glGetTextureParameterIuiv = (mgl_glGetTextureParameterIuiv_t)load_function("glGetTextureParameterIuiv");
    if (mgl_glGetTextureParameterIuiv == NULL)
        return 0;
    mgl_glGetTextureParameteriv = (mgl_glGetTextureParameteriv_t)load_function("glGetTextureParameteriv");
    if (mgl_glGetTextureParameteriv == NULL)
        return 0;
    mgl_glCreateVertexArrays = (mgl_glCreateVertexArrays_t)load_function("glCreateVertexArrays");
    if (mgl_glCreateVertexArrays == NULL)
        return 0;
    mgl_glDisableVertexArrayAttrib = (mgl_glDisableVertexArrayAttrib_t)load_function("glDisableVertexArrayAttrib");
    if (mgl_glDisableVertexArrayAttrib == NULL)
        return 0;
    mgl_glEnableVertexArrayAttrib = (mgl_glEnableVertexArrayAttrib_t)load_function("glEnableVertexArrayAttrib");
    if (mgl_glEnableVertexArrayAttrib == NULL)
        return 0;
    mgl_glVertexArrayElementBuffer = (mgl_glVertexArrayElementBuffer_t)load_function("glVertexArrayElementBuffer");
    if (mgl_glVertexArrayElementBuffer == NULL)
        return 0;
    mgl_glVertexArrayVertexBuffer = (mgl_glVertexArrayVertexBuffer_t)load_function("glVertexArrayVertexBuffer");
    if (mgl_glVertexArrayVertexBuffer == NULL)
        return 0;
    mgl_glVertexArrayVertexBuffers = (mgl_glVertexArrayVertexBuffers_t)load_function("glVertexArrayVertexBuffers");
    if (mgl_glVertexArrayVertexBuffers == NULL)
        return 0;
    mgl_glVertexArrayAttribBinding = (mgl_glVertexArrayAttribBinding_t)load_function("glVertexArrayAttribBinding");
    if (mgl_glVertexArrayAttribBinding == NULL)
        return 0;
    mgl_glVertexArrayAttribFormat = (mgl_glVertexArrayAttribFormat_t)load_function("glVertexArrayAttribFormat");
    if (mgl_glVertexArrayAttribFormat == NULL)
        return 0;
    mgl_glVertexArrayAttribIFormat = (mgl_glVertexArrayAttribIFormat_t)load_function("glVertexArrayAttribIFormat");
    if (mgl_glVertexArrayAttribIFormat == NULL)
        return 0;
    mgl_glVertexArrayAttribLFormat = (mgl_glVertexArrayAttribLFormat_t)load_function("glVertexArrayAttribLFormat");
    if (mgl_glVertexArrayAttribLFormat == NULL)
        return 0;
    mgl_glVertexArrayBindingDivisor = (mgl_glVertexArrayBindingDivisor_t)load_function("glVertexArrayBindingDivisor");
    if (mgl_glVertexArrayBindingDivisor == NULL)
        return 0;
    mgl_glGetVertexArrayiv = (mgl_glGetVertexArrayiv_t)load_function("glGetVertexArrayiv");
    if (mgl_glGetVertexArrayiv == NULL)
        return 0;
    mgl_glGetVertexArrayIndexediv = (mgl_glGetVertexArrayIndexediv_t)load_function("glGetVertexArrayIndexediv");
    if (mgl_glGetVertexArrayIndexediv == NULL)
        return 0;
    mgl_glGetVertexArrayIndexed64iv = (mgl_glGetVertexArrayIndexed64iv_t)load_function("glGetVertexArrayIndexed64iv");
    if (mgl_glGetVertexArrayIndexed64iv == NULL)
        return 0;
    mgl_glCreateSamplers = (mgl_glCreateSamplers_t)load_function("glCreateSamplers");
    if (mgl_glCreateSamplers == NULL)
        return 0;
    mgl_glCreateProgramPipelines = (mgl_glCreateProgramPipelines_t)load_function("glCreateProgramPipelines");
    if (mgl_glCreateProgramPipelines == NULL)
        return 0;
    mgl_glCreateQueries = (mgl_glCreateQueries_t)load_function("glCreateQueries");
    if (mgl_glCreateQueries == NULL)
        return 0;
    mgl_glGetQueryBufferObjecti64v = (mgl_glGetQueryBufferObjecti64v_t)load_function("glGetQueryBufferObjecti64v");
    if (mgl_glGetQueryBufferObjecti64v == NULL)
        return 0;
    mgl_glGetQueryBufferObjectiv = (mgl_glGetQueryBufferObjectiv_t)load_function("glGetQueryBufferObjectiv");
    if (mgl_glGetQueryBufferObjectiv == NULL)
        return 0;
    mgl_glGetQueryBufferObjectui64v = (mgl_glGetQueryBufferObjectui64v_t)load_function("glGetQueryBufferObjectui64v");
    if (mgl_glGetQueryBufferObjectui64v == NULL)
        return 0;
    mgl_glGetQueryBufferObjectuiv = (mgl_glGetQueryBufferObjectuiv_t)load_function("glGetQueryBufferObjectuiv");
    if (mgl_glGetQueryBufferObjectuiv == NULL)
        return 0;
    mgl_glMemoryBarrierByRegion = (mgl_glMemoryBarrierByRegion_t)load_function("glMemoryBarrierByRegion");
    if (mgl_glMemoryBarrierByRegion == NULL)
        return 0;
    mgl_glGetTextureSubImage = (mgl_glGetTextureSubImage_t)load_function("glGetTextureSubImage");
    if (mgl_glGetTextureSubImage == NULL)
        return 0;
    mgl_glGetCompressedTextureSubImage = (mgl_glGetCompressedTextureSubImage_t)load_function("glGetCompressedTextureSubImage");
    if (mgl_glGetCompressedTextureSubImage == NULL)
        return 0;
    mgl_glGetGraphicsResetStatus = (mgl_glGetGraphicsResetStatus_t)load_function("glGetGraphicsResetStatus");
    if (mgl_glGetGraphicsResetStatus == NULL)
        return 0;
    mgl_glGetnCompressedTexImage = (mgl_glGetnCompressedTexImage_t)load_function("glGetnCompressedTexImage");
    if (mgl_glGetnCompressedTexImage == NULL)
        return 0;
    mgl_glGetnTexImage = (mgl_glGetnTexImage_t)load_function("glGetnTexImage");
    if (mgl_glGetnTexImage == NULL)
        return 0;
    mgl_glGetnUniformdv = (mgl_glGetnUniformdv_t)load_function("glGetnUniformdv");
    if (mgl_glGetnUniformdv == NULL)
        return 0;
    mgl_glGetnUniformfv = (mgl_glGetnUniformfv_t)load_function("glGetnUniformfv");
    if (mgl_glGetnUniformfv == NULL)
        return 0;
    mgl_glGetnUniformiv = (mgl_glGetnUniformiv_t)load_function("glGetnUniformiv");
    if (mgl_glGetnUniformiv == NULL)
        return 0;
    mgl_glGetnUniformuiv = (mgl_glGetnUniformuiv_t)load_function("glGetnUniformuiv");
    if (mgl_glGetnUniformuiv == NULL)
        return 0;
    mgl_glReadnPixels = (mgl_glReadnPixels_t)load_function("glReadnPixels");
    if (mgl_glReadnPixels == NULL)
        return 0;
    mgl_glTextureBarrier = (mgl_glTextureBarrier_t)load_function("glTextureBarrier");
    if (mgl_glTextureBarrier == NULL)
        return 0;
    mgl_glSpecializeShader = (mgl_glSpecializeShader_t)load_function("glSpecializeShader");
    if (mgl_glSpecializeShader == NULL)
        return 0;
    mgl_glMultiDrawArraysIndirectCount = (mgl_glMultiDrawArraysIndirectCount_t)load_function("glMultiDrawArraysIndirectCount");
    if (mgl_glMultiDrawArraysIndirectCount == NULL)
        return 0;
    mgl_glMultiDrawElementsIndirectCount = (mgl_glMultiDrawElementsIndirectCount_t)load_function("glMultiDrawElementsIndirectCount");
    if (mgl_glMultiDrawElementsIndirectCount == NULL)
        return 0;
    mgl_glPolygonOffsetClamp = (mgl_glPolygonOffsetClamp_t)load_function("glPolygonOffsetClamp");
    if (mgl_glPolygonOffsetClamp == NULL)
        return 0;
    return 1;
}

GLAPI const char* mgl_ErrorString(GLenum error) {
    switch (error) {
        case GL_INVALID_ENUM:
            return "GL_INVALID_ENUM";
        case GL_INVALID_VALUE:
            return "GL_INVALID_VALUE";
        case GL_INVALID_OPERATION:
            return "GL_INVALID_OPERATION";
        case GL_OUT_OF_MEMORY:
            return "GL_OUT_OF_MEMORY";
        case GL_STACK_OVERFLOW:
            return "GL_STACK_OVERFLOW";
        case GL_STACK_UNDERFLOW:
            return "GL_STACK_UNDERFLOW";
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            return "GL_INVALID_FRAMEBUFFER_OPERATION";
        default:
            return "GL_UNKNOWN_ERROR";
    }
}

#endif /* MGL_IMPLEMENTATION */

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /* MANLY_GL_H */
