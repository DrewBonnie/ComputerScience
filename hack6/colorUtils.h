/**
 * Author: Drew Bonnie dbonnie2@huskers.unl.edu
 * Date: 2023/10/09
 *
 * This program has a max function which returns the
 * highest double, an RGB to CMYK converter, and a
 * CMYK to RGB converter.
 */

typedef enum {
    INVALID_INPUTS,
    NULL_ERROR
} Errors;

/**
 * Returns the highest double
 */
double max(double a, double b, double c);

/**
 * Converts three RGB values into CMYK values.
 */
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

/**
 * Converts four CMYK values into RGB values.
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);