# - Try to find the Lib library
# Once done this will define
#
#  LIBMONGOC_FOUND - System has Mongoc
#  LIBMONGOC_INCLUDE_DIR - The Mongoc include directory
#  LIBMONGOC_LIBRARIES - The libraries needed to use Mongoc
#  LIBMONGOC_DEFINITIONS - Compiler switches required for using Mongoc


# use pkg-config to get the directories and then use these values
# in the FIND_PATH() and FIND_LIBRARY() calls
#FIND_PACKAGE(PkgConfig)
#PKG_SEARCH_MODULE(PC_LIBMONGOC libmongoc)

SET(LIBMONGOC_DEFINITIONS ${PC_LIBMONGOC_CFLAGS_OTHER})

FIND_PATH(LIBMONGOC_INCLUDE_DIR mongoc/mongoc.h
   HINTS
   ${PC_LIBMONGOC_INCLUDEDIR}
   ${PC_LIBMONGOC_INCLUDE_DIRS}
)

FIND_LIBRARY(LIBMONGOC_LIBRARIES NAMES mongoc 
   HINTS
   ${PC_LIBMONGOC_LIBDIR}
   ${PC_LIBMONGOC_LIBRARY_DIRS}
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LibHiredis DEFAULT_MSG LIBMONGOC_LIBRARIES LIBMONGOC_INCLUDE_DIR)

#MARK_AS_ADVANCED(LIBMONGOC_INCLUDE_DIR LIBMONGOC_LIBRARIES)
