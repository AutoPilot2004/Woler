cmake_minimum_required(VERSION 3.28.0)

include(FetchContent)

# Sock
FetchContent_Declare(
	Sock
	GIT_REPOSITORY "https://github.com/AutoPilot2004/Sock.git"
	GIT_TAG        f3179cac46024d959443ad4b3b2f80901e3d1ae6 # v0.1.0
)

# Make declared contents available
FetchContent_MakeAvailable(Sock)