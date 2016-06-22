
.PHONY: clean

CC = g++
AR = ar
INCLUDE = ./include 
CFLAGS = -Wall
ARFALGS = rcs
OUTPUT_DIR = ./build

OBJECTS = qos.o

all: prepare $(OUTPUT_DIR)/libqos.a

prepare:
	@[ -d $(OUTPUT_DIR) ] || mkdir $(OUTPUT_DIR)

$(OUTPUT_DIR)/libqos.a: $(OUTPUT_DIR)/$(OBJECTS)
	$(AR) $(ARFALGS) $@ $<

$(OUTPUT_DIR)/%.o: ./src/%.cc
	$(CC) -I$(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*
