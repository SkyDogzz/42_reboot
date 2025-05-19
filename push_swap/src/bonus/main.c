#include "../../include/bonus.h"

int main(int argc, char **argv)
{
	t_stack	stack;
	t_dlist	*inst;

	inst = NULL;
	stack.a = NULL;
	stack.b = NULL;
	if (!ft_parse_args(argc, argv, &stack) || ft_isdup(&stack.a))
		write(2, "Error\n", 6);
}
