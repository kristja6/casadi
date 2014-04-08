# TRY TO FIND THE MA57 LIBRARY

FIND_LIBRARY(MA57_LIB
    NAMES MA57
    HINTS /usr/local/lib/)

IF(MA57_LIB)
  MESSAGE(STATUS "Found MA57: ${MA57_LIB}")
  SET(MA57_LIBRARIES ${MA57_LIB})
  SET(MA57_FOUND TRUE)
ELSE(MA57_LIB)
  SET(MA57_FOUND FALSE)
  MESSAGE(STATUS "Could not find MA57")
ENDIF(MA57_LIB)