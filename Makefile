CC = g++
CXXFLAGS = -Wall -std=c++11 -static
LDFLAGS =
OBJFILES = main.o player.o board.o
TARGET = TTT

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
