#include <math.h>
double hue2rgb(double p, double q, double t)
{
    if(t < 0) t += 1;
    if(t > 1) t -= 1;
    if(6*t < 1) return p + (q - p) * 6 * t;
    if(2*t < 1) return q;
    if(3*t < 2) return p + (q - p) * (2.0/3 - t) * 6;
    return p;
}

int hslToRgb(double h, double s, double l)
{
    double r, g, b;

    if(s == 0){
        r = g = b = l;
    }else{

        double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        double p = 2 * l - q;
        r = hue2rgb(p, q, h + 1.0/3);
        g = hue2rgb(p, q, h);
        b = hue2rgb(p, q, h - 1.0/3);
    } 
	int res = ((int) round(r *  255)) << 16;
	res |= ((int) round(g * 255)) << 8;
	res |= (int) round(b * 255);
	return res;
}

