# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 04:13:09 by ichpakov          #+#    #+#              #
#    Updated: 2025/10/30 02:54:27 by ichpakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = prog

#//////////////////////////////////////////////////////////////////////////////
#		COLORS
#//////////////////////////////////////////////////////////////////////////////

BLUE   = \033[0;34m
GREEN  = \033[0;32m
RED    = \033[0;31m
PINK = \033[0;35m
RESET  = \033[0m

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS =	srcs/main.cpp	

HEAD =	includes/Snake.hpp

OBJS = $(SRCS:srcs/%.cpp=objs/%.o)

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++98 -pedantic -g -Iincludes  #-Wall -Wextra -Werror

# Remove command
RM = rm -f

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Link binary
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@ || (echo -e "$(RED)Linking failed$(RESET)"; exit 1)
	@echo -e "$(GREEN)Executable $@ created successfully!$(RESET)"

# Compile sources to objects
objs/%.o: srcs/%.cpp $(HEAD)
	@mkdir -p objs	
	@echo -ne "$(BLUE)Compiling $<...$(RESET)\033[K\r"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ || (echo -e "$(RED)Error compiling $<$(RESET)"; exit 1)
	@echo -e "$(BLUE)$< compiled$(RESET)\033[K"

# Clean only objects
clean:
	@if [ -d objs ]; then \
		echo -e "$(PINK)Cleaning object files...$(RESET)"; \
		$(RM) $(OBJS); \
		rmdir objs 2>/dev/null || true \
		echo -e "$(PINK)Objects cleaned$(RESET)"; \
	else \
		echo -e "$(PINK)No objects to clean$(RESET)"; \
	fi

# Clean everything
fclean: clean
	@if [ -f $(NAME) ]; then \
		echo -e "$(PINK)Removing executable $(NAME)...$(RESET)"; \
		$(RM) $(NAME); \
		echo -e "$(PINK)Executable removed$(RESET)"; \
	else \
		echo -e "$(PINK)No executable to remove$(RESET)"; \
	fi

# Rebuild
re: fclean all
