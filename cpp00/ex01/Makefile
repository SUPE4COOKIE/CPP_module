CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -g3

SRC_DIR = src
OBJ_DIR = .obj

TARGET = PhoneBook

SOURCES = $(addprefix $(SRC_DIR)/, \
			Contact.cpp \
			PhoneBook.cpp \
			main.cpp \
			)

OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CPP) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile | $(OBJ_DIR)
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re
