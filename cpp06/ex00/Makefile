OBJDIR = .obj
SRC_DIR = src
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)
SRCS = $(addprefix $(SRC_DIR)/, \
	main.cpp \
	ScalarConverter.cpp \
)
NAME = convert
CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
INC = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp Makefile | $(OBJDIR)
	$(CXX) $(CXX_FLAGS) $(INC) -MMD -MP -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

-include $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re