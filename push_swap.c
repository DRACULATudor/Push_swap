#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list  *stack_a;
	// t_list  *stack_b;

	stack_a = NULL;
	// stack_b = NULL;

	if(!check_args(argc, argv))
		return(0);
	if(argc == 2)
	{
		if(check_args(argc, argv) == 1)
		{
			add_numbers_to_stack(argv[1], &stack_a);
		}
	}
	return(0);
}
