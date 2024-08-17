COMPILER = gcc

OUTPUT_DIR = ./build
OUTPUT_FILE_NAME = main.o
OUTPUT_FILE_PATH = $(OUTPUT_DIR)/$(OUTPUT_FILE_NAME)

MAIN_FILE_PATH = ./src/main.c 
HELPERS_FILES = ./src/helpers/files/files.h \
				./src/helpers/files/files.c \
				./src/helpers/strings/strings.h \
				./src/helpers/strings/strings.c \
				./src/helpers/nodes/nodes.h \
				./src/helpers/nodes/nodes.c \
				./src/helpers/sort/sort.h \
				./src/helpers/sort/sort.c \
				./src/helpers/integers/integers.h \
				./src/helpers/integers/integers.c \
				./src/helpers/display-contest/display-contest.h \
				./src/helpers/display-contest/display-contest.c \
				./src/helpers/helpers.h

TYPE_FILES = ./src/types/date.h \
				./src/types/contest.h \
				./src/types/contest.c \
				./src/types/lucky-number.h \
				./src/types/sort.h \
				./src/types/types.h

STRUCTURES_FILES = 	./src/structures/hash-map.h \
					./src/structures/hash-map.c

CONTROLLERS_FILES = ./src/controllers/insert-contest-controller/insert-contest-controller.h \
					./src/controllers/insert-contest-controller/insert-contest-controller.c \
					./src/controllers/list-contests-controller/list-contests-controller.h \
					./src/controllers/list-contests-controller/list-contests-controller.c \
					./src/controllers/search-contest-controller/search-contest-controller.h \
					./src/controllers/search-contest-controller/search-contest-controller.c \
					./src/controllers/delete-contest-controller/delete-contest-controller.h \
					./src/controllers/delete-contest-controller/delete-contest-controller.c \
					./src/controllers/load-contests-from-file-controller/load-contests-from-file-controller.h \
					./src/controllers/load-contests-from-file-controller/load-contests-from-file-controller.c \
					./src/controllers/contest-metrics-controller/contest-metrics-controller.h \
					./src/controllers/contest-metrics-controller/contest-metrics-controller.c \
					./src/controllers/controllers.h

SERVICES_FILES = 	./src/services/contest-metrics/contest-metrics.h \
					./src/services/contest-metrics/contest-metrics.c

USECASES_FILES =	./src/usecases/insert-contest/insert-contest.h \
					./src/usecases/insert-contest/insert-contest.c \
					./src/usecases/load-contests-from-file/load-contests-from-file.h \
					./src/usecases/load-contests-from-file/load-contests-from-file.c \
					./src/usecases/delete-contest/delete-contest.h \
					./src/usecases/delete-contest/delete-contest.c \
					./src/usecases/usecases.h

compile: create-dependence-dirs
	$(COMPILER) \
	$(MAIN_FILE_PATH) \
	$(TYPE_FILES) \
	$(CONTROLLERS_FILES) \
	$(STRUCTURES_FILES) \
	$(HELPERS_FILES) \
	$(SERVICES_FILES) \
	$(USECASES_FILES) \
	-o $(OUTPUT_FILE_PATH)

create-dependence-dirs:
	if [ ! -d $(OUTPUT_DIR) ]; then mkdir $(OUTPUT_DIR); fi

run: $(OUTPUT_FILE_PATH)
	$(OUTPUT_FILE_PATH)
