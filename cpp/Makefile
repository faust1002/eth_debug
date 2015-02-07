PROGRAM = debugger

SRCDIR = $(CURDIR)/src
HDRDIR = $(CURDIR)/include
OBJDIR = $(CURDIR)/objs

CXX = g++
CPPFLAGS = -I $(HDRDIR)
CXXFLAGS = -Wall -Wextra -std=c++0x -march=native -MMD -MP

LDFLAGS = -lpthread

SOURCES = $(shell find $(SRCDIR) -type f -name "*.cpp" -printf "%f\n")
OBJECTS = $(notdir $(SOURCES:.cpp=.o))
OBJS = $(addprefix $(OBJDIR)/, $(OBJECTS))
DEPS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.d))

.PHONY: all debug release clean

all: debug

release: CXXFLAGS += -O3 -Werror
release: $(PROGRAM)

debug: CXXFLAGS += -ggdb3 -fno-inline -O0
debug: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp |$(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(PROGRAM)

-include $(DEPS)
