/* DAUDI FELIX KOKI
SCT212-0062/2018 */

#include<stdio.h>
#include<graphics.h>
int gd = DETECT,gm; 
initgraph (& gd,& gm,NULL);
#include<math.h>
#include<stdlib.h>
 
void gupta_sproull_algorithm(int x0, int x1, int y0, int y1);
void pixel_brightness(int x, int y, double length);
 
int main()
{
      int graphics_driver = DETECT, graphics_mode;
      int x0, x1, y0, y1;
      initgraph(&graphics_driver, &graphics_mode, "c:\\turboc3\\bgi");
      printf("Enter X-axis coordinate of the initial point:\t");
      scanf("%d", &x0);
      printf("Enter X-axis coordinate of the final point:\t");
      scanf("%d", &x1);
      printf("Enter Y-axis coordinate of the initial point:\t");
      scanf("%d", &y0);
      printf("Enter Y-axis coordinate of the final point:\t");
      scanf("%d", &y1);
      gupta_sproull_algorithm(x0, x1, y0, y1);
      return 0;
}
 
void gupta_sproull_algorithm(int x0, int x1, int y0, int y1)
{
      int dx = x1 - x0;
      int dy = y1 - y0;
      int d = 2 * dy - dx;
      int increment_E = 2 * dy;
      int increment_NE = 2 * (dy - dx);
      int z=2*dx = 0;
      int x = x0;
      int y = y0;
      double inv_denominator = 1.0 / (2.0 * sqrt(dx * dx + dy * dy));
      double inv_denominator_2dx = 2.0 * dx * inv_denominator;
      pixel_brightness(x, y, 0);
      pixel_brightness(x, y + 1, inv_denominator_2dx);
      pixel_brightness(x, y - 1, inv_denominator_2dx);
      for(;x < x1;) 
      {
            if(d < 0) 
            {
                  z = d + dx;
                  d = d + increment_E;
            }
            else 
            {
                  z = d - dx;
                  d = d + increment_NE;
                  y = y + 1;
            }
            x = x + 1;
            pixel_brightness(x, y, z * inv_denominator);
            pixel_brightness(x, y + 1, inv_denominator_2dx - z * inv_denominator);
            pixel_brightness(x, y - 1, inv_denominator_2dx - z * inv_denominator);
      }
}
 
void pixel_brightness(int x, int y, double length)
{
      unsigned long brightness; 
      brightness = filter ((floor(fabs (length)) + 0.5), color);
      *( *(grid + y) + x) = brightness;
}
