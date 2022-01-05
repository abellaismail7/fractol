#include <math.h>
#include "mlx.h"

int main ()
{
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 1200, 1200, "test");
	int i = 600;
	while(i--)
		mlx_pixel_put(ptr, win, i, 40, 0XFFFFFFFF);
	mlx_loop(ptr);
	
	return 0;
}
