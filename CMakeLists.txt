cmake_minimum_required(VERSION 3.28.0)

include(deps.cmake)

project(
	"woler"
	VERSION 1.0.0
	DESCRIPTION "A simple program that wakes systems up using WOL (currently Windows only)"
	LANGUAGES CXX
)

add_executable(${PROJECT_NAME})
set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 23
)
target_compile_definitions(${PROJECT_NAME} PRIVATE TARGET_NAME="${PROJECT_NAME}")
target_link_libraries(${PROJECT_NAME} PRIVATE Sock::Sock)

add_subdirectory("src/Woler")