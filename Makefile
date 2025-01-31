CC = g++
CXXFLAGS = -std=c++11 -static -pthread
LDFLAGS =
OBJFILES = main.o
TARGET = TTT

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
