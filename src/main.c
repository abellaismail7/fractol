#include <math.h>
#include "mlx.h"

typedef struct s_point {
	int x;
	int y;
} t_point;

int main ()
{
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 1200, 1200, "test");
	double i = 0;
	while(i < 200)
	{
		double a = sin(i)  * 100; // take 2 digits after \. .
		if (i * 50 > 1200) // break at edge
			break;
		// 50 for tjbida
		// 300 from top
		mlx_pixel_put(ptr, win, i * 190, a + 300, 0XFFFFFFFF);
		i += 0.1; // increase details
	}
	mlx_loop(ptr);

	mlx_destroy_window(ptr,win);
	mlx_destroy_display(ptr);
	return 0;
}
