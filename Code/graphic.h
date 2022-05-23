#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

void graphic_draw_window();

void graphic_draw_carre_plein(unsigned int x, unsigned int y, double size, double r,
                              double g, double b);

void graphic_draw_carre_vide(unsigned int x, unsigned int y, double size, double r,
                             double g, double b);

void graphic_draw_losange(unsigned int x, unsigned int y, double r, double g, double b);

void graphic_draw_plus(unsigned int x, unsigned int y, double size, double r, double g,
                       double b);

void graphic_draw_croix(unsigned int x, unsigned int y, double r, double g, double b);


#endif
