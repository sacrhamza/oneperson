#include "header.h"
#include "colors.h"
void ft_colored(char *target, int mode)
{
		int	color = 1;
                int mid ;
                int low = 0;
                int high = 140;
		if (!oneperson_strncmp(oneperson_strupper(target), "_", 1))
		{
			target += 1;
			color = 0;
			
		}
		if (!oneperson_strncmp(oneperson_strupper(target), "BG_", 2))
		{
			target+= 2;
			color = 0;
		}
		if (!mode)
		{
			oneperson_putstr("\e[38;2;255;0;0m\e[0m");
			oneperson_putstr("\e[");
		}
		else
			oneperson_putchar(';');
		if (color)
			oneperson_putstr(COLOR_STRING);
		else
			oneperson_putstr(BACKGROUND_STRING);
                while (low <= high)
                {
                        mid = (low + high) / 2;
                        if (oneperson_strcmp(oneperson_strupper(target), **(REAL_COLORS_VARIABLES + mid)) > 0)
                                low = mid + 1;
                        else if (oneperson_strcmp(oneperson_strupper(target), **(REAL_COLORS_VARIABLES + mid)) < 0)
                                high = mid - 1;
                        else
                        {
                                oneperson_putstr(*(*(REAL_COLORS_VARIABLES + mid) + 1));
                                return ;
                        }
                }
	oneperson_putstr(EXIT_STRING);
}

