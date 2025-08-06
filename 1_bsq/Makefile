NAME = bsq
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = bsq.c
OBJ = $(SRC:.c=.o)
TEST_FILES = test1_basic.txt \
             test2_small.txt \
             test3_single_line.txt \
             test4_obstacles.txt \
             test5_no_obstacles.txt \
             test6_perfect.txt \
             test7_multiple.txt \
             test8_large.txt \
             error1_duplicate_chars.txt \
             error2_different_lengths.txt \
             error3_wrong_rows.txt \
             error4_invalid_char.txt \
             error5_empty_line.txt \
             error6_bad_header.txt \
             error7_zero_rows.txt \
             error8_nonprintable.txt \
             error9_empty.txt \
             error10_header_only.txt \
             test_performance_100x100.txt

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled successfully$(NC)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -f $(OBJ)
	@echo "$(GREEN)Object files cleaned$(NC)"

fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)Executable cleaned$(NC)"

clean-tests:
	@echo "$(YELLOW)Cleaning test files...$(NC)"
	@for file in $(TEST_FILES); do \
		if [ -f "$$file" ]; then \
			rm -f "$$file" && echo "$(RED)Removed $$file$(NC)"; \
		fi; \
	done
	@echo "$(GREEN)Test files cleaned$(NC)"

clean-all: fclean clean-tests
	@echo "$(GREEN)Everything cleaned$(NC)"

re: fclean all

test: $(NAME)
	@echo "$(GREEN)Running BSQ tests...$(NC)"
	@if [ -f "./test.sh" ]; then \
		chmod +x test.sh && ./test.sh; \
	else \
		echo "$(RED)test.sh not found$(NC)"; \
	fi

test-training: $(NAME)
	@echo "$(GREEN)Running training tests...$(NC)"
	@if [ -f "./training/test.sh" ]; then \
		cd training && chmod +x test.sh && ./test.sh; \
	else \
		echo "$(RED)training/test.sh not found$(NC)"; \
	fi

help:
	@echo "$(GREEN)BSQ Makefile - Available targets:$(NC)"
	@echo "  $(YELLOW)all$(NC)           - Compile the program (default)"
	@echo "  $(YELLOW)clean$(NC)         - Remove object files"
	@echo "  $(YELLOW)fclean$(NC)        - Remove object files and executable"
	@echo "  $(YELLOW)clean-tests$(NC)   - Remove test files created by test scripts"
	@echo "  $(YELLOW)clean-all$(NC)     - Remove everything (executable + object files + test files)"
	@echo "  $(YELLOW)re$(NC)            - Rebuild everything (fclean + all)"
	@echo "  $(YELLOW)test$(NC)          - Compile and run main tests"
	@echo "  $(YELLOW)test-training$(NC) - Compile and run training tests"
	@echo "  $(YELLOW)help$(NC)          - Show this help message"

.PHONY: all clean fclean clean-tests clean-all re test test-training help
