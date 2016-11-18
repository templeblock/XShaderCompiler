/*
 * HLSLKeywords.cpp
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include "HLSLKeywords.h"


namespace Xsc
{


template <typename T>
T MapKeywordToType(const std::map<std::string, T>& typeMap, const std::string& keyword, const std::string& typeName)
{
    auto it = typeMap.find(keyword);
    if (it != typeMap.end())
        return it->second;
    else
        throw std::runtime_error("failed to map keyword '" + keyword + "' to " + typeName);
}

/* ----- HLSL Keywords ----- */

static KeywordMapType GenerateKeywordMap()
{
    using T = Token::Types;

    return
    {
        { "true",                    T::BoolLiteral     },
        { "false",                   T::BoolLiteral     },

        { "string",                  T::StringType      },

        { "bool",                    T::ScalarType      },
        { "bool1",                   T::ScalarType      },
        { "bool1x1",                 T::ScalarType      },
        { "int",                     T::ScalarType      },
        { "int1",                    T::ScalarType      },
        { "int1x1",                  T::ScalarType      },
        { "uint",                    T::ScalarType      },
        { "uint1",                   T::ScalarType      },
        { "uint1x1",                 T::ScalarType      },
        { "dword",                   T::ScalarType      },
        { "dword1",                  T::ScalarType      },
        { "dword1x1",                T::ScalarType      },
        { "half",                    T::ScalarType      },
        { "half1",                   T::ScalarType      },
        { "half1x1",                 T::ScalarType      },
        { "float",                   T::ScalarType      },
        { "float1",                  T::ScalarType      },
        { "float1x1",                T::ScalarType      },
        { "double",                  T::ScalarType      },
        { "double1",                 T::ScalarType      },
        { "double1x1",               T::ScalarType      },

        { "bool2",                   T::VectorType      },
        { "bool3",                   T::VectorType      },
        { "bool4",                   T::VectorType      },
        { "int2",                    T::VectorType      },
        { "int3",                    T::VectorType      },
        { "int4",                    T::VectorType      },
        { "uint2",                   T::VectorType      },
        { "uint3",                   T::VectorType      },
        { "uint4",                   T::VectorType      },
        { "dword2",                  T::VectorType      },
        { "dword3",                  T::VectorType      },
        { "dword4",                  T::VectorType      },
        { "half2",                   T::VectorType      },
        { "half3",                   T::VectorType      },
        { "half4",                   T::VectorType      },
        { "float2",                  T::VectorType      },
        { "float3",                  T::VectorType      },
        { "float4",                  T::VectorType      },
        { "double2",                 T::VectorType      },
        { "double3",                 T::VectorType      },
        { "double4",                 T::VectorType      },

        { "bool2x2",                 T::MatrixType      },
        { "bool2x3",                 T::MatrixType      },
        { "bool2x4",                 T::MatrixType      },
        { "bool3x2",                 T::MatrixType      },
        { "bool3x3",                 T::MatrixType      },
        { "bool3x4",                 T::MatrixType      },
        { "bool4x2",                 T::MatrixType      },
        { "bool4x3",                 T::MatrixType      },
        { "bool4x4",                 T::MatrixType      },
        { "int2x2",                  T::MatrixType      },
        { "int2x3",                  T::MatrixType      },
        { "int2x4",                  T::MatrixType      },
        { "int3x2",                  T::MatrixType      },
        { "int3x3",                  T::MatrixType      },
        { "int3x4",                  T::MatrixType      },
        { "int4x2",                  T::MatrixType      },
        { "int4x3",                  T::MatrixType      },
        { "int4x4",                  T::MatrixType      },
        { "uint2x2",                 T::MatrixType      },
        { "uint2x3",                 T::MatrixType      },
        { "uint2x4",                 T::MatrixType      },
        { "uint3x2",                 T::MatrixType      },
        { "uint3x3",                 T::MatrixType      },
        { "uint3x4",                 T::MatrixType      },
        { "uint4x2",                 T::MatrixType      },
        { "uint4x3",                 T::MatrixType      },
        { "uint4x4",                 T::MatrixType      },
        { "dword2x2",                T::MatrixType      },
        { "dword2x3",                T::MatrixType      },
        { "dword2x4",                T::MatrixType      },
        { "dword3x2",                T::MatrixType      },
        { "dword3x3",                T::MatrixType      },
        { "dword3x4",                T::MatrixType      },
        { "dword4x2",                T::MatrixType      },
        { "dword4x3",                T::MatrixType      },
        { "dword4x4",                T::MatrixType      },
        { "half2x2",                 T::MatrixType      },
        { "half2x3",                 T::MatrixType      },
        { "half2x4",                 T::MatrixType      },
        { "half3x2",                 T::MatrixType      },
        { "half3x3",                 T::MatrixType      },
        { "half3x4",                 T::MatrixType      },
        { "half4x2",                 T::MatrixType      },
        { "half4x3",                 T::MatrixType      },
        { "half4x4",                 T::MatrixType      },
        { "float2x2",                T::MatrixType      },
        { "float2x3",                T::MatrixType      },
        { "float2x4",                T::MatrixType      },
        { "float3x2",                T::MatrixType      },
        { "float3x3",                T::MatrixType      },
        { "float3x4",                T::MatrixType      },
        { "float4x2",                T::MatrixType      },
        { "float4x3",                T::MatrixType      },
        { "float4x4",                T::MatrixType      },
        { "double2x2",               T::MatrixType      },
        { "double2x3",               T::MatrixType      },
        { "double2x4",               T::MatrixType      },
        { "double3x2",               T::MatrixType      },
        { "double3x3",               T::MatrixType      },
        { "double3x4",               T::MatrixType      },
        { "double4x2",               T::MatrixType      },
        { "double4x3",               T::MatrixType      },
        { "double4x4",               T::MatrixType      },

        { "void",                    T::Void            },

        { "vector",                  T::Vector          },
        { "matrix",                  T::Matrix          },

        { "do",                      T::Do              },
        { "while",                   T::While           },
        { "for",                     T::For             },

        { "if",                      T::If              },
        { "else",                    T::Else            },

        { "switch",                  T::Switch          },
        { "case",                    T::Case            },
        { "default",                 T::Default         },

        { "typedef",                 T::Typedef         },
        { "struct",                  T::Struct          },
        { "register",                T::Register        },
        { "packoffset",              T::PackOffset      },

        { "sampler",                 T::Sampler         },
        { "sampler1D",               T::Sampler         },
        { "sampler2D",               T::Sampler         },
        { "sampler3D",               T::Sampler         },
        { "samplerCUBE",             T::Sampler         },
        { "sampler_state",           T::Sampler         },
        { "SamplerState",            T::Sampler         },
        { "SamplerComparisonState",  T::Sampler         }, // since D3D10+

        { "Texture1D",               T::Texture         },
        { "Texture1DArray",          T::Texture         },
        { "Texture2D",               T::Texture         },
        { "Texture2DArray",          T::Texture         },
        { "Texture3D",               T::Texture         },
        { "TextureCube",             T::Texture         },
        { "TextureCubeArray",        T::Texture         },
        { "Texture2DMS",             T::Texture         },
        { "Texture2DMSArray",        T::Texture         },
        { "RWTexture1D",             T::Texture         },
        { "RWTexture1DArray",        T::Texture         },
        { "RWTexture2D",             T::Texture         },
        { "RWTexture2DArray",        T::Texture         },
        { "RWTexture3D",             T::Texture         },

        { "Buffer",                  T::StorageBuffer   },
        { "StructuredBuffer",        T::StorageBuffer   },
        { "ByteAddressBuffer",       T::StorageBuffer   },
        { "RWBuffer",                T::StorageBuffer   },
        { "RWByteAddressBuffer",     T::StorageBuffer   },
        { "RWStructuredBuffer",      T::StorageBuffer   },
        { "AppendStructuredBuffer",  T::StorageBuffer   },
        { "ConsumeStructuredBuffer", T::StorageBuffer   },

        { "cbuffer",                 T::UniformBuffer   },
        { "tbuffer",                 T::UniformBuffer   },

        { "break",                   T::CtrlTransfer    },
        { "continue",                T::CtrlTransfer    },
        { "discard",                 T::CtrlTransfer    },

        { "return",                  T::Return          },

        { "uniform",                 T::InputModifier   },
        { "in",                      T::InputModifier   },
        { "out",                     T::InputModifier   },
        { "inout",                   T::InputModifier   },

        { "extern",                  T::StorageModifier },
        { "nointerpolation",         T::StorageModifier },
        { "precise",                 T::StorageModifier },
        { "shared",                  T::StorageModifier },
        { "groupshared",             T::StorageModifier },
        { "static",                  T::StorageModifier },
      //{ "uniform",                 T::StorageModifier }, // Already used as "InputModifier"
        { "volatile",                T::StorageModifier },
        { "linear",                  T::StorageModifier },
        { "centroid",                T::StorageModifier },
        { "noperspective",           T::StorageModifier },
        { "sample",                  T::StorageModifier },

        { "const",                   T::TypeModifier    },
        { "row_major",               T::TypeModifier    },
        { "column_major",            T::TypeModifier    },

        { "technique",               T::Technique       },
        { "pass",                    T::Pass            },
        { "compile",                 T::Compile         },

        { "auto",                    T::Reserved        },
        { "catch",                   T::Reserved        },
        { "char",                    T::Reserved        },
        { "const_cast",              T::Reserved        },
        { "delete",                  T::Reserved        },
        { "dynamic_cast",            T::Reserved        },
        { "enum",                    T::Reserved        },
        { "explicit",                T::Reserved        },
        { "friend",                  T::Reserved        },
        { "goto",                    T::Reserved        },
        { "long",                    T::Reserved        },
        { "mutable",                 T::Reserved        },
        { "new",                     T::Reserved        },
        { "operator",                T::Reserved        },
        { "private",                 T::Reserved        },
        { "protected",               T::Reserved        },
        { "public",                  T::Reserved        },
        { "reinterpret_cast",        T::Reserved        },
        { "short",                   T::Reserved        },
        { "signed",                  T::Reserved        },
        { "sizeof",                  T::Reserved        },
        { "static_cast",             T::Reserved        },
        { "template",                T::Reserved        },
        { "this",                    T::Reserved        },
        { "throw",                   T::Reserved        },
        { "try",                     T::Reserved        },
        { "typename",                T::Reserved        },
        { "union",                   T::Reserved        },
        { "unsigned",                T::Reserved        },
        { "using",                   T::Reserved        },
        { "virtual",                 T::Reserved        },
    };
}

const KeywordMapType& HLSLKeywords()
{
    static const auto keywordMap = GenerateKeywordMap();
    return keywordMap;
}


/* ----- DataType Mapping ----- */

static std::map<std::string, DataType> GenerateDataTypeMap()
{
    using T = DataType;

    return
    {
        { "string",    T::String    },

        { "bool",      T::Bool      },
        { "bool1",     T::Bool      },
        { "bool1x1",   T::Bool      },
        { "int",       T::Int       },
        { "int1",      T::Int       },
        { "int1x1",    T::Int       },
        { "uint",      T::UInt      },
        { "uint1",     T::UInt      },
        { "uint1x1",   T::UInt      },
        { "dword",     T::UInt      },
        { "dword1",    T::UInt      },
        { "dword1x1",  T::UInt      },
        { "half",      T::Half      },
        { "half1",     T::Half      },
        { "half1x1",   T::Half      },
        { "float",     T::Float     },
        { "float1",    T::Float     },
        { "float1x1",  T::Float     },
        { "double",    T::Double    },
        { "double1",   T::Double    },
        { "double1x1", T::Double    },

        { "bool2",     T::Bool2     },
        { "bool3",     T::Bool3     },
        { "bool4",     T::Bool4     },
        { "int2",      T::Int2      },
        { "int3",      T::Int3      },
        { "int4",      T::Int4      },
        { "uint2",     T::UInt2     },
        { "uint3",     T::UInt3     },
        { "uint4",     T::UInt4     },
        { "dword2",    T::UInt2     },
        { "dword3",    T::UInt3     },
        { "dword4",    T::UInt4     },
        { "half2",     T::Half2     },
        { "half3",     T::Half3     },
        { "half4",     T::Half4     },
        { "float2",    T::Float2    },
        { "float3",    T::Float3    },
        { "float4",    T::Float4    },
        { "double2",   T::Double2   },
        { "double3",   T::Double3   },
        { "double4",   T::Double4   },

        { "bool2x2",   T::Bool2x2   },
        { "bool2x3",   T::Bool2x3   },
        { "bool2x4",   T::Bool2x4   },
        { "bool3x2",   T::Bool3x2   },
        { "bool3x3",   T::Bool3x3   },
        { "bool3x4",   T::Bool3x4   },
        { "bool4x2",   T::Bool4x2   },
        { "bool4x3",   T::Bool4x3   },
        { "bool4x4",   T::Bool4x4   },
        { "int2x2",    T::Int2x2    },
        { "int2x3",    T::Int2x3    },
        { "int2x4",    T::Int2x4    },
        { "int3x2",    T::Int3x2    },
        { "int3x3",    T::Int3x3    },
        { "int3x4",    T::Int3x4    },
        { "int4x2",    T::Int4x2    },
        { "int4x3",    T::Int4x3    },
        { "int4x4",    T::Int4x4    },
        { "uint2x2",   T::UInt2x2   },
        { "uint2x3",   T::UInt2x3   },
        { "uint2x4",   T::UInt2x4   },
        { "uint3x2",   T::UInt3x2   },
        { "uint3x3",   T::UInt3x3   },
        { "uint3x4",   T::UInt3x4   },
        { "uint4x2",   T::UInt4x2   },
        { "uint4x3",   T::UInt4x3   },
        { "uint4x4",   T::UInt4x4   },
        { "dword2x2",  T::UInt2x2   },
        { "dword2x3",  T::UInt2x3   },
        { "dword2x4",  T::UInt2x4   },
        { "dword3x2",  T::UInt3x2   },
        { "dword3x3",  T::UInt3x3   },
        { "dword3x4",  T::UInt3x4   },
        { "dword4x2",  T::UInt4x2   },
        { "dword4x3",  T::UInt4x3   },
        { "dword4x4",  T::UInt4x4   },
        { "half2x2",   T::Half2x2   },
        { "half2x3",   T::Half2x3   },
        { "half2x4",   T::Half2x4   },
        { "half3x2",   T::Half3x2   },
        { "half3x3",   T::Half3x3   },
        { "half3x4",   T::Half3x4   },
        { "half4x2",   T::Half4x2   },
        { "half4x3",   T::Half4x3   },
        { "half4x4",   T::Half4x4   },
        { "float2x2",  T::Float2x2  },
        { "float2x3",  T::Float2x3  },
        { "float2x4",  T::Float2x4  },
        { "float3x2",  T::Float3x2  },
        { "float3x3",  T::Float3x3  },
        { "float3x4",  T::Float3x4  },
        { "float4x2",  T::Float4x2  },
        { "float4x3",  T::Float4x3  },
        { "float4x4",  T::Float4x4  },
        { "double2x2", T::Double2x2 },
        { "double2x3", T::Double2x3 },
        { "double2x4", T::Double2x4 },
        { "double3x2", T::Double3x2 },
        { "double3x3", T::Double3x3 },
        { "double3x4", T::Double3x4 },
        { "double4x2", T::Double4x2 },
        { "double4x3", T::Double4x3 },
        { "double4x4", T::Double4x4 },
    };
}

DataType HLSLKeywordToDataType(const std::string& keyword)
{
    static const auto typeMap = GenerateDataTypeMap();
    return MapKeywordToType(typeMap, keyword, "data type");
}


/* ----- StorageClass Mapping ----- */

static std::map<std::string, StorageClass> GenerateStorageClassMap()
{
    using T = StorageClass;

    return
    {
        { "extern",          T::Extern          },
        { "precise",         T::Precise         },
        { "shared",          T::Shared          },
        { "groupshared",     T::GroupShared     },
        { "static",          T::Static          },
        { "uniform",         T::Uniform         },
        { "volatile",        T::Volatile        },

        { "nointerpolation", T::NoInterpolation },
        { "linear",          T::Linear          },
        { "centroid",        T::Centroid        },
        { "noperspective",   T::NoPerspective   },
        { "sample",          T::Sample          },
    };
}

StorageClass HLSLKeywordToStorageClass(const std::string& keyword)
{
    static const auto typeMap = GenerateStorageClassMap();
    return MapKeywordToType(typeMap, keyword, "storage class");
}


/* ----- BufferType Mapping ----- */

static std::map<std::string, BufferType> GenerateBufferTypeMap()
{
    using T = BufferType;

    return
    {
        { "Buffer",                  T::Buffer                  },
        { "StucturedBuffer",         T::StucturedBuffer         },
        { "ByteAddressBuffer",       T::ByteAddressBuffer       },

        { "RWBuffer",                T::RWBuffer                },
        { "RWStucturedBuffer",       T::RWStucturedBuffer       },
        { "RWByteAddressBuffer",     T::RWByteAddressBuffer     },
        { "AppendStructuredBuffer",  T::AppendStructuredBuffer  },
        { "ConsumeStructuredBuffer", T::ConsumeStructuredBuffer },

        { "RWTexture1D",             T::RWTexture1D             },
        { "RWTexture1DArray",        T::RWTexture1DArray        },
        { "RWTexture2D",             T::RWTexture2D             },
        { "RWTexture2DArray",        T::RWTexture2DArray        },
        { "RWTexture3D",             T::RWTexture3D             },

        { "Texture1D",               T::Texture1D               },
        { "Texture1DArray",          T::Texture1DArray          },
        { "Texture2D",               T::Texture2D               },
        { "Texture2DArray",          T::Texture2DArray          },
        { "Texture3D",               T::Texture3D               },
        { "TextureCube",             T::TextureCube             },
        { "TextureCubeArray",        T::TextureCubeArray        },
        { "Texture2DMS",             T::Texture2DMS             },
        { "Texture2DMSArray",        T::Texture2DMSArray        },
    };
}

BufferType HLSLKeywordToBufferType(const std::string& keyword)
{
    static const auto typeMap = GenerateBufferTypeMap();
    return MapKeywordToType(typeMap, keyword, "buffer type");
}


} // /namespace Xsc



// ================================================================================