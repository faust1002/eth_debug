PROGRAM = debugger

SRCDIR = src
HDRDIR = include
OBJDIR = objs

CXX = g++
CPPFLAGS = -I include
CXXFLAGS = -Wall -Wextra -std=c++0x -march=native
DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -ggdb3 -fno-inline -O0 -g
else
    CXXFLAGS += -O3
endif

LDFLAGS = -lpthread

SOURCES = $(shell find $(SRCDIR) -type f -name "*.cpp" -printf "%f\n")
OBJECTS = $(notdir $(SOURCES:.cpp=.o))
OBJS = $(addprefix $(OBJDIR)/, $(OBJECTS))

.PHONY: all clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp |$(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(PROGRAM)
