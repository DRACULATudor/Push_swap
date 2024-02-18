#include "push_swap.h"

int	ft_check_num(char *str)
{
	int	i;
    int	sign_count;

    i = 0;
    sign_count = 0;
    if (str[i] == '-' || str[i] == '+') {
        sign_count++;
        i++;
    }
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    if (sign_count > 1)
        return 0;
    return 1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}



int count_numbers(char *argv)
{
    int count = 0;
    char *start = argv;
    char *end;

    while (*start)
    {
        while (*start == ' ')
            start++;
        end = start;
        while (*end != ' ' && *end != '\0')
            end++;
        if (start != end)
        {
            count++;
            start = end;
        }
    }

    return count;
}

void store_numbers(char *argv, int *numbers)
{
    int count = 0;
    char *start = argv;
    char *end;

    while (*start)
    {
        while (*start == ' ')
            start++;
        end = start;
        while (*end != ' ' && *end != '\0')
            end++;
        if (start != end)
        {
            char temp = *end;
            *end = '\0';
            numbers[count++] = atoi(start);
            *end = temp;
            start = end;
        }
    }
}

int check_duplicates(int *numbers, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (numbers[i] == numbers[j])
            {
                return 1;  
            }
        }
    }
    return 0;  
}

int ft_checkdupcust(char *argv)
{
    char *copy = strdup(argv);
    int count = count_numbers(copy);
    int *numbers = malloc(sizeof(int) * count);
    store_numbers(copy, numbers);
    int result = check_duplicates(numbers, count);
    free(numbers);
    free(copy);
    return result;
}

int	ft_checkdup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_args(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("\n");
		return(0);
	}
	if (argc == 2)
	{
		if (!ft_check_num(argv[1]))
		{
			ft_printf("Error\n");
            return 0;
		}
		else if (ft_check_num(argv[1]))
		{
			if (ft_checkdupcust(argv[1]))
			{

			}
			
		}
		
		
	}
	
	
	return (1);
}	

