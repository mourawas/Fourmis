#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <gtkmm.h>
#include <cairomm/context.h>

void graphic_set_context(const Cairo::RefPtr<Cairo::Context>& cr);
void graphic_draw_window();
void graphic_draw_carre_plein(double x,double y,double size, double r, double g, double b);
void graphic_draw_carre_vide(double x, double y, double size, double r, double g, double b);
void graphic_draw_losange(double x,double y,double r, double g, double b);

#endif
