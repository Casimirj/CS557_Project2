cmake_minimum_required(VERSION 3.6)
project(CS557_Project2_James_Casimir)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp FCFS.cpp FCFS.h LinkedList.cpp LinkedList.h Process.cpp Process.h
        Queue.cpp Queue.h SJF.cpp SJF.h SRTF.cpp SRTF.h RR.cpp RR.h)
add_executable(CS557_Project2_James_Casimir ${SOURCE_FILES})