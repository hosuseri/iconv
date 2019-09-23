TARGET = iconv
OBJS = \
	main.o \
	strcore.o \
	utf8core.o \
	cp932core.o \
	winstr.o

CC = gcc
CXX = g++
CFLAGS = -Wall -O0 -g
CXXFLAGS = $(CFLAGS)
LIBS = #-liconv

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

$(TARGET2): $(OBJS2)
	$(CCPLUS) $(CXXFLAGS) -o $(TARGET2) $(OBJS2)

.c.o:
	$(CC) $(CFLAGS) -c $<

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<
