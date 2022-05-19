cmake_minimum_required(VERSION 3.19)
project(SemestralProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(src/main.cpp src/CApplication.cpp src/CApplication.h src/CDate.cpp src/CDate.h src/CDateTime.cpp src/CDateTime.h src/CEvent.cpp src/CEvent.h src/CCalendar.cpp src/CCalendar.h src/CViewManager.cpp src/CViewManager.h src/CView.h src/CInterface.cpp src/CInterface.h src/CDailyView.cpp src/CDailyView.h src/textMessages.h src/CCommand.cpp src/CCommand.h src/CEventEditor.cpp src/CEventEditor.h src/CMonthlyView.cpp src/CMonthlyView.h src/CWeeklyView.cpp src/CWeeklyView.h src/CFind.h src/CTime.cpp src/CTime.h src/CFindID.cpp src/CFindID.h src/CFindName.cpp src/CFindName.h src/CFindPlace.cpp src/CFindPlace.h src/CFindManager.cpp src/CFindManager.h)