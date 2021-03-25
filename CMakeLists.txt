cmake_minimum_required(VERSION 3.6)
MESSAGE(STATUS "Using CMake ${CMAKE_VERSION}")

PROJECT(Qbit CXX)

#-----------------------------------------------------------------------------
# Prevent in-source builds.
#-----------------------------------------------------------------------------

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message( FATAL_ERROR  "In-source build is not possible and not recommended. Choose an empty directory for build output.")
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

# Be sure to avoid troubles with library paths when using old policy
if(COMMAND cmake_policy)
    CMAKE_POLICY(SET CMP0003 NEW)
    CMAKE_POLICY(SET CMP0048 NEW)
endif(COMMAND cmake_policy)

# set the name of the library to link against
SET(LIB_NAME "qbit")

SET(QBIT_VERSION_MAJOR 0)
SET(QBIT_VERSION_MINOR 0)
SET(QBIT_VERSION_PATCH 1)


PROJECT(Qbit VERSION ${QBIT_VERSION_MAJOR}.${QBIT_VERSION_MINOR}.${QBIT_VERSION_PATCH})

SET(QBIT_VERSION "${QBIT_VERSION_MAJOR}.${QBIT_VERSION_MINOR}.${QBIT_VERSION_PATCH}")
MESSAGE(STATUS "Qbit++ Version ${QBIT_VERSION}")

# required configuration
SET(BUILD_SHARED_LIBS ON)
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find Boost
FIND_PACKAGE(Boost 1.65.0 REQUIRED)
IF(Boost_FOUND)
       MESSAGE( STATUS  "Found needed Boost C++ library.")
       SET(BOOST_INCLUDEDIR ${Boost_INCLUDE_DIRS})
       SET(BOOST_LIBRARYDIR ${Boost_LIBRARY_DIRS})
       SET(Boost_USE_SHARED_LIBS ON)
ELSE()
       MESSAGE( FATAL_ERROR  "Boost 1.65.0 is required but not found.")
ENDIF()

# find OpenBLAS
FIND_PACKAGE(BLAS REQUIRED)

IF(NOT BLAS_FOUND)
    MESSAGE( FATAL_ERROR  "Could not find OpenBLAS library.")
ELSE()
    MESSAGE( STATUS  "Found needed BLAS library.")
ENDIF()

FIND_PACKAGE(Eigen3 3.0 QUIET NO_MODULE)
MESSAGE(STATUS "Detecting Eigen3 - done (in ${EIGEN3_INCLUDE_DIR})")

SET(BUILD_SHARED_LIBS ON)
SET(CMAKE_BUILD_TYPE "Debug")
OPTION(ENABLE_TESTING "Enable tests" ON)
OPTION(ENABLE_EXAMPLES "Enable examples" ON)
OPTION(USE_OPENMP "Compile with OpenMP support" ON)
#OPTION(USE_LOG "ON")

SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
SET(PROJECT_INCL_DIR ${PROJECT_SOURCE_DIR}/include)
SET(PROJECT_SRC_DIR  ${PROJECT_SOURCE_DIR}/src/qbit)
SET(DATA_SET_FOLDER ${PROJECT_SOURCE_DIR}/data)
SET(PROJECT_PATH ${PROJECT_SOURCE_DIR})
SET(MAGIC_ENUM_INCL_DIR " ")
SET(BLAZE_INCL_DIR "/home/alex/MySoftware/blaze-3.8/install/include")
SET(NLOHMANN_JSON_INCL_DIR "/home/alex/MySoftware/nlohman_json/install/include")
SET(QUANTUM_PP_INCL_DIR "/home/alex/MySoftware/qpp/include")



if(CMAKE_BUILD_TYPE MATCHES "Debug")
    SET(QUBIT_DEBUG "ON")
ENDIF()

MESSAGE(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
MESSAGE(STATUS "C Compiler: ${CMAKE_C_COMPILER}")

configure_file(config.h.in ${PROJECT_SOURCE_DIR}/include/qbit/base/config.h @ONLY)
configure_file(version.h.in ${PROJECT_SOURCE_DIR}/include/qbit/base/version.h @ONLY)

# TODO: Fix this
# add this because config.h ends up in the build directory
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/include)

IF(${MAGIC_ENUM_INCL_DIR} MATCHES " ")
    MESSAGE( STATUS  "MagicEnum include directory has not been specified")
ELSE()
    INCLUDE_DIRECTORIES(${MAGIC_ENUM_INCL_DIR})
    MESSAGE(STATUS  "Using Magic enum at ${MAGIC_ENUM_INCL_DIR} ")
ENDIF()

IF( ${BLAZE_INCL_DIR} MATCHES " " )
    MESSAGE( FATAL_ERROR  "Blaze include directory has not been specified")
ELSE()
    MESSAGE( STATUS  "Using BLAZE headers at: ${BLAZE_INCL_DIR}")
ENDIF()

IF(ENABLE_TESTING)
    SET(GTEST_INC_DIR "/home/alex/MySoftware/gtest/install/include")
    SET(GTEST_LIB_DIR "/home/alex/MySoftware/gtest/install/lib")
    INCLUDE_DIRECTORIES(${GTEST_INC_DIR})
    LINK_DIRECTORIES(${GTEST_LIB_DIR})
ENDIF()

IF( ENABLE_TESTING AND GTEST_INC_DIR MATCHES " " )
    MESSAGE( FATAL_ERROR  "Testing is enabled but GTest include directory has not been specified")
ENDIF()

IF( ENABLE_TESTING  AND GTEST_LIB_DIR MATCHES " " )
    MESSAGE( FATAL_ERROR  "Testing is enabled but GTest lib directory has not been specified")
ENDIF()

IF(USE_OPENMP)

    IF(CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES " ")
        SET(CMAKE_CXX_FLAGS "-std=c++17 -g -pthread -fopenmp -fPIC")
        SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install/lib/dbg)
    ELSE()
        SET(CMAKE_CXX_FLAGS "-std=c++17 -O2 -pthread -fopenmp -fPIC")
        SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install/lib/opt)
    ENDIF()
ELSE()

    IF(CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES " ")
        SET(CMAKE_CXX_FLAGS "-std=c++17 -g -pthread -fPIC")
        SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install/lib/dbg)
    ELSE()
        SET(CMAKE_CXX_FLAGS "-std=c++17 -O2 -pthread -fPIC")
        SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install/lib/opt)
    ENDIF()
ENDIF()

SET(CMAKE_LINKER_FLAGS "-pthread")

# include dirs used by the project
INCLUDE_DIRECTORIES(${PROJECT_INCL_DIR}) 
INCLUDE_DIRECTORIES(${BOOST_INCLUDEDIR})
INCLUDE_DIRECTORIES(${BLAZE_INCL_DIR})
INCLUDE_DIRECTORIES(${NLOHMANN_JSON_INCL_DIR})
INCLUDE_DIRECTORIES(${QUANTUM_PP_INCL_DIR})
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})

# use the Boost link directories
LINK_DIRECTORIES(${BOOST_LIBRARYDIR})

FILE(GLOB  SRCS  ${PROJECT_SRC_DIR}/base/*.cpp
                 ${PROJECT_SRC_DIR}/utilities/*.cpp
                 ${PROJECT_SRC_DIR}/maths/*.cpp
                 ${PROJECT_SRC_DIR}/gates/*.cpp
                 ${PROJECT_SRC_DIR}/circuits/*.cpp
                 )


ADD_LIBRARY(${LIB_NAME} SHARED ${SRCS})

SET_TARGET_PROPERTIES(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)
INSTALL(TARGETS ${LIB_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})

MESSAGE(STATUS  "Installation destination at: ${CMAKE_INSTALL_PREFIX}")

IF(ENABLE_EXAMPLES)
	# Add the examples
	ADD_SUBDIRECTORY(examples)
ELSE()
	MESSAGE( STATUS  "Examples have not been enabled")
ENDIF()

IF(ENABLE_TESTING)
	ENABLE_TESTING()
	ADD_SUBDIRECTORY(tests)
ELSE()
	MESSAGE( STATUS  "Tests have not been enabled")
ENDIF()
