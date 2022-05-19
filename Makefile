TARGET = sulovjak

CXX = g++

CXXFLAGS = -g -Wall -pedantic -Wextra -std=c++17

OBJECTS=build/main.o build/CWeeklyView.o build/CViewManager.o build/CTime.o build/CMonthlyView.o build/CInterface.o \
build/CFindPlace.o build/CFindName.o build/CFindManager.o build/CFindID.o build/CEventEditor.o build/CEvent.o \
build/CDateTime.o build/CDate.o build/CDailyView.o build/CCommand.o build/CCalendar.o build/CApplication.o

DOXY=Doxyfile

SOURCE_DIR = src
BUILD_DIR = build

all: compile doc
	@echo: "Done"

compile: $(TARGET)
	@echo "Compile"

.PHONY: run
run: $(TARGET)
	./$(TARGET)

doc: $(DOXY) README.md $(HEADERS)
	doxygen $(DOXY)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $@


$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(TARGET) doc/ $(BUILD_DIR)/ 2>/dev/null

build/CApplication.o: src/CApplication.cpp src/CApplication.h src/CCommand.h \
  src/CEventEditor.h src/CCalendar.h src/CFindID.h src/CFind.h \
  src/CInterface.h src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h src/CViewManager.h \
  src/CDailyView.h src/CView.h src/CWeeklyView.h src/CMonthlyView.h


build/CCalendar.o: src/CCalendar.cpp src/CCalendar.h src/CFindID.h src/CFind.h \
  src/CInterface.h src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h

build/CCommand.o: src/CCommand.cpp src/CCommand.h src/CEventEditor.h \
  src/CCalendar.h src/CFindID.h src/CFind.h src/CInterface.h \
  src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h src/CViewManager.h \
  src/CDailyView.h src/CView.h src/CWeeklyView.h src/CMonthlyView.h \
  src/CFindManager.h
build/CDailyView.o: src/CDailyView.cpp src/CDailyView.h src/CView.h \
  src/CCalendar.h src/CFindID.h src/CFind.h src/CInterface.h \
  src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h
build/CDate.o: src/CDate.cpp src/CDate.h
build/CDateTime.o: src/CDateTime.cpp src/CDateTime.h src/CDate.h src/CTime.h
build/CEvent.o: src/CEvent.cpp src/CEvent.h src/CDateTime.h src/CDate.h \
  src/CTime.h
build/CEventEditor.o: src/CEventEditor.cpp src/CEventEditor.h src/CCalendar.h \
  src/CFindID.h src/CFind.h src/CInterface.h src/CEvent.h \
  src/CDateTime.h src/CDate.h src/CTime.h src/textMessages.h \
  src/CFindName.h src/CFindPlace.h
build/CFindID.o: src/CFindID.cpp src/CFindID.h src/CFind.h src/CInterface.h \
  src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h
build/CFindManager.o: src/CFindManager.cpp src/CFindManager.h src/CFindPlace.h \
  src/CFind.h src/CInterface.h src/CEvent.h src/CDateTime.h src/CDate.h \
  src/CTime.h src/textMessages.h src/CFindName.h src/CFindID.h
build/CFindName.o: src/CFindName.cpp src/CFindName.h src/CFind.h \
  src/CInterface.h src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h
build/CFindPlace.o: src/CFindPlace.cpp src/CFindPlace.h src/CFind.h \
  src/CInterface.h src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h
build/CInterface.o: src/CInterface.cpp src/CInterface.h src/CEvent.h \
  src/CDateTime.h src/CDate.h src/CTime.h src/textMessages.h
build/CMonthlyView.o: src/CMonthlyView.cpp src/CMonthlyView.h src/CView.h \
  src/CCalendar.h src/CFindID.h src/CFind.h src/CInterface.h \
  src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h
build/CTime.o: src/CTime.cpp src/CTime.h
build/CViewManager.o: src/CViewManager.cpp src/CViewManager.h src/CDailyView.h \
  src/CView.h src/CCalendar.h src/CFindID.h src/CFind.h src/CInterface.h \
  src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h src/CWeeklyView.h \
  src/CMonthlyView.h
build/CWeeklyView.o: src/CWeeklyView.cpp src/CWeeklyView.h src/CView.h \
  src/CCalendar.h src/CFindID.h src/CFind.h src/CInterface.h \
  src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h
build/main.o: src/main.cpp src/CApplication.h src/CCommand.h src/CEventEditor.h \
  src/CCalendar.h src/CFindID.h src/CFind.h src/CInterface.h \
  src/CEvent.h src/CDateTime.h src/CDate.h src/CTime.h \
  src/textMessages.h src/CFindName.h src/CFindPlace.h src/CViewManager.h \
  src/CDailyView.h src/CView.h src/CWeeklyView.h src/CMonthlyView.h






