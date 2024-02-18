#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

void    add_numbers_to_stack(char *str, t_list **stack)
{
    int num = 0;
    int sign = 1;
    int i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num = (num * 10) + str[i] - '0';
        }
        else if (str[i] == '-')
        {
            sign = -1;
        }
        else if(str[i] == ' ' && num != 0)
        {
            ft_lstadd_back(stack, (ft_lstnew(num * sign)));
            num = 0;
            sign = 1;
        }
    }
    if (num != 0)
    {
        ft_lstadd_back(stack, (ft_lstnew(num * sign)));
    }
}