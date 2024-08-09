COMPILER = gcc

OUTPUT_DIR = ./build
OUTPUT_FILE_NAME = main.o
OUTPUT_FILE_PATH = $(OUTPUT_DIR)/$(OUTPUT_FILE_NAME)

MAIN_FILE_PATH = ./src/main.c 
HELPERS_FILES = ./src/helpers/files/files.h \
				./src/helpers/files/files.c \
				./src/helpers/strings/strings.h \
				./src/helpers/strings/strings.c \
				./src/helpers/helpers.h
TYPE_FILES = ./src/types/date.h \
				./src/types/contest.h \
				./src/types/types.h

STRUCTURES_FILES = 	./src/structures/hash-map.h \
					./src/structures/hash-map.c

compile: create-dependence-dirs
	$(COMPILER) $(MAIN_FILE_PATH) $(TYPE_FILES) $(STRUCTURES_FILES) $(HELPERS_FILES) \
	-o $(OUTPUT_FILE_PATH)

create-dependence-dirs:
	if [ ! -d $(OUTPUT_DIR) ]; then mkdir $(OUTPUT_DIR); fi

run: $(OUTPUT_FILE_PATH)
	$(OUTPUT_FILE_PATH)
