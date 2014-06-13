set(Boost_USE_MULTITHREADED ON) 
SET(SRC_LIST test.cpp
	)
SET (CMAKE_CXX_FLAGS                	"-Wall -std=c++11")
SET (CMAKE_CXX_FLAGS_DEBUG          	"-g -Wall -std=c++11")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     	"-Os -DNDEBUG -std=c++11")
SET (CMAKE_CXX_FLAGS_RELEASE       		"-O4 -DNDEBUG -std=c++11")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO 	"-O2 -g -std=c++11")
#find_package(Boost 1.55.0 COMPONENTS thread chrono system)
#if(Boost_FOUND)
	#set(CMAKE_EXE_LINKER_FLAGS "-lssl -lm -lz -lrt")
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++11")
	INCLUDE_DIRECTORIES(/usr/local/include)
	ADD_EXECUTABLE(tolly ${SRC_LIST})
	#target_link_libraries(nativeHbase ${Boost_LIBRARIES} thrift)
#endif()
INSTALL(TARGETS tolly
	RUNTIME DESTINATION bin
)
