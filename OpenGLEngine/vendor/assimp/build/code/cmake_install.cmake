# Install script for directory: E:/work/assimp-5.0.1/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/work/assimp-5.0.1/build/code/Debug/assimp-vc142-mtd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/work/assimp-5.0.1/build/code/Release/assimp-vc142-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/work/assimp-5.0.1/build/code/MinSizeRel/assimp-vc142-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/work/assimp-5.0.1/build/code/RelWithDebInfo/assimp-vc142-mt.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/work/assimp-5.0.1/build/code/Debug/assimp-vc142-mtd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/work/assimp-5.0.1/build/code/Release/assimp-vc142-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/work/assimp-5.0.1/build/code/MinSizeRel/assimp-vc142-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/work/assimp-5.0.1/build/code/RelWithDebInfo/assimp-vc142-mt.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "E:/work/assimp-5.0.1/code/../include/assimp/anim.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/aabb.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/ai_assert.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/camera.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/color4.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/color4.inl"
    "E:/work/assimp-5.0.1/build/code/../include/assimp/config.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/defs.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Defines.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/cfileio.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/light.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/material.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/material.inl"
    "E:/work/assimp-5.0.1/code/../include/assimp/matrix3x3.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/matrix3x3.inl"
    "E:/work/assimp-5.0.1/code/../include/assimp/matrix4x4.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/matrix4x4.inl"
    "E:/work/assimp-5.0.1/code/../include/assimp/mesh.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/pbrmaterial.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/postprocess.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/quaternion.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/quaternion.inl"
    "E:/work/assimp-5.0.1/code/../include/assimp/scene.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/metadata.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/texture.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/types.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/vector2.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/vector2.inl"
    "E:/work/assimp-5.0.1/code/../include/assimp/vector3.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/vector3.inl"
    "E:/work/assimp-5.0.1/code/../include/assimp/version.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/cimport.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/importerdesc.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Importer.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/DefaultLogger.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/ProgressHandler.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/IOStream.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/IOSystem.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/Logger.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/LogStream.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/NullLogger.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/cexport.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Exporter.hpp"
    "E:/work/assimp-5.0.1/code/../include/assimp/DefaultIOStream.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/DefaultIOSystem.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/ZipArchiveIOSystem.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/SceneCombiner.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/fast_atof.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/qnan.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/BaseImporter.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Hash.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/MemoryIOWrapper.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/ParsingUtils.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/StreamReader.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/StreamWriter.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/StringComparison.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/StringUtils.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/SGSpatialSort.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/GenericProperty.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/SpatialSort.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/SkeletonMeshBuilder.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/SmoothingGroups.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/SmoothingGroups.inl"
    "E:/work/assimp-5.0.1/code/../include/assimp/StandardShapes.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/RemoveComments.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Subdivision.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Vertex.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/LineSplitter.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/TinyFormatter.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Profiler.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/LogAux.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Bitmap.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/XMLTools.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/IOStreamBuffer.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/CreateAnimMesh.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/irrXMLWrapper.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/BlobIOSystem.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/MathFunctions.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Macros.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Exceptional.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "E:/work/assimp-5.0.1/code/../include/assimp/Compiler/pushpack1.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Compiler/poppack1.h"
    "E:/work/assimp-5.0.1/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "E:/work/assimp-5.0.1/build/code/Debug/assimp-vc142-mtd.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "E:/work/assimp-5.0.1/build/code/RelWithDebInfo/assimp-vc142-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

