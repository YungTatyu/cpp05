NAME = a.out
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
ifdef	DEBUG
	CXXFLAGS += -fsanitize=address
endif

SRCS_DIR = src
SRC =	main.cpp
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC))

INCLUDES_DIR = include
INCLUDES = -I$(INCLUDES_DIR)
OBJS_DIR = obj
OBJS = $(patsubst $(SRCS_DIR)/%.cpp, $(OBJS_DIR)/%.o,$(SRCS))
RM = rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(INCLUDES) $(CXXFLAGS)  -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

re:	fclean	all

fclean:	clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

debug:
	@make re DEBUG=1

.PHONY: all re fclean clean debug leaks