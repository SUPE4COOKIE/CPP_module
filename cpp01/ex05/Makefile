OBJDIR = .obj
SRC_DIR = src
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)
SRCS = $(addprefix $(SRC_DIR)/, \
	main.cpp \
	Harl.cpp \
)
NAME = Harl2.0
CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98
INC = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXX_FLAGS) $(INC) -MMD -MP -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

-include $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re%         