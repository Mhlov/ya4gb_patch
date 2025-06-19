NAME = ya4gb_patch
SRC = $(NAME).c
TARGET = $(NAME).exe
CC = x86_64-w64-mingw32-gcc
STRIP = x86_64-w64-mingw32-strip
CFLAGS = -O2 -Wall
UPX_FLAGS = --best --lzma


all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	$(STRIP) $(TARGET)
	upx $(UPX_FLAGS) $(TARGET)
	zip $(NAME) $(TARGET)

clean:
	rm -f $(TARGET)
	rm -f $(NAME).zip

.PHONY: all clean

