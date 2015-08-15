TARGET = Rectangle 

SRCS = $(wildcard *.cc)
OBJS = $(SRCS:.cc=.o)

MKDIR = mkdir
MKDIRFLAGS = -p
RM = rm
RMFLAGS = -rf

CPP = g++
CC = gcc

CFLAGS = -Wall -gdwarf-2 -g3 -O0

RMS = $(OBJS) $(TARGET)

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) -o $@ $^

%.o: %.cc
	$(CPP) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(RMFLAGS) $(RMS)
