#include "../../include/push_swap.h"

void	execra(t_dlist **inst, t_stack *stack)
{
	rotate(&stack->a);
	add_instruction(inst, "ra");
}

void	execrb(t_dlist **inst, t_stack *stack)
{
	rotate(&stack->b);
	add_instruction(inst, "rb");
}

void	execrr(t_dlist **inst, t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	add_instruction(inst, "rr");
}

void	execrra(t_dlist **inst, t_stack *stack)
{
	reverse_rotate(&stack->a);
	add_instruction(inst, "rra");
}

void	execrrb(t_dlist **inst, t_stack *stack)
{
	reverse_rotate(&stack->b);
	add_instruction(inst, "rrb");
}

void	execrrr(t_dlist **inst, t_stack *stack)
{
	reverse_rotate(&stack->a);
	reverse_rotate(&stack->b);
	add_instruction(inst, "rrr");
}
