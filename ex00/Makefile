NAME = btc
CXX = c++
CXXFLAGS = -Wextra -Werror -Wall -std=c++98
H_PATH = -I.
SRCS = BitcoinExchange.cpp \
	   main.cpp
OBJS = $(patsubst %.cpp,$(ODIR)/%.o,$(SRCS))
ODIR = ofiles

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@printf "$(GREEN)ok Executable ready$(RESET)\n"

$(OBJS):$(ODIR)/%.o:%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(H_PATH) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(ODIR)
	@printf "$(YELLOW)Object files removed$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(YELLOW)Executable removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re