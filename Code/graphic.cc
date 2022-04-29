#include "graphic.h"
#include <cmath>

static const Cairo::RefPtr<Cairo::Context>* ptcr;

void graphic_set_context(const Cairo::RefPtr<Cairo::Context>& cr)
{
    ptcr = &cr;
}

void graphic_draw_window()
{
    (*ptcr)->set_source_rgb(0, 0, 0);
    (*ptcr)->paint();
    
    (*ptcr)->set_line_width(1);
    (*ptcr)->set_source_rgb(206, 207, 208);
    (*ptcr)->move_to(-1, -1);
    (*ptcr)->line_to(-1, 128.5);
    (*ptcr)->move_to(-1, 128.5);
    (*ptcr)->line_to(129, 128.5);
    (*ptcr)->move_to(129, 128.5);
    (*ptcr)->line_to(129, -1);
    (*ptcr)->move_to(129, -1);
    (*ptcr)->line_to(-1 ,-1);
    (*ptcr)->stroke();
    for (size_t i(0); i<128; ++i){
        (*ptcr)->set_line_width(0.1);
        (*ptcr)->set_source_rgb(0.4, 0.4, 0.4);
        (*ptcr)->move_to(i+0.5, 0);
        (*ptcr)->line_to(i+0.5, 128);
        
        (*ptcr)->stroke();
    }
    for (size_t i(0); i<128; ++i){
        (*ptcr)->set_line_width(0.1);
        (*ptcr)->set_source_rgb(0.4, 0.4, 0.4);
        (*ptcr)->move_to(0, i+0.5);
        (*ptcr)->line_to(128,i+0.5);
        
        (*ptcr)->stroke();
    }
    
}

void graphic_draw_carre_plein(double x,double y,double size, double r, double g, double b){
    if (size ==1){
        (*ptcr)->set_line_width(1);
        (*ptcr)->set_source_rgb(r, g, b);
        (*ptcr)->move_to(x, y-0.5);
        (*ptcr)->line_to(x, y+0.5);
        (*ptcr)->stroke();
    }
    else {
        (*ptcr)->set_line_width(size);
        (*ptcr)->set_source_rgb(r, g, b);
        (*ptcr)->move_to(x,y-size/2);
        (*ptcr)->line_to(x, y+size/2);
        (*ptcr)->stroke();
        /*(*ptcr)->set_source_rgb(r, g, b);
        (*ptcr)->move_to(x-size/2-0.5, y+size/2-0.5);
        (*ptcr)->line_to(x+size/2-0.5, y+size/2-0.5);
        (*ptcr)->move_to(x+size/2-0.5, y+size/2-0.5);
        (*ptcr)->line_to(x+size/2-0.5,y-size/2-0.5);
        (*ptcr)->move_to(x+size/2-0.5,y-size/2-0.5);
        (*ptcr)->line_to(x-size/2-0.5,y-size/2-0.5);
        (*ptcr)->move_to(x-size/2-0.5,y-size/2-0.5);
        (*ptcr)->line_to(x-size/2-0.5, y+size/2-0.5);
        (*ptcr)->stroke();*/
    }
}
void graphic_draw_carre_vide(double x, double y, double size, double r, double g, double b){
    (*ptcr)->set_line_width(0.5);
    (*ptcr)->set_source_rgb(r, g, b);
    (*ptcr)->move_to(x, y-0.5);
    (*ptcr)->line_to(x, y+0.5+size);
    (*ptcr)->move_to(x, y+0.5+size);
    (*ptcr)->line_to(x+size, y+0.5+size);
    (*ptcr)->move_to(x+size, y+0.5+size);
    (*ptcr)->line_to(x+size, y-0.5);
    (*ptcr)->move_to(x+size, y-0.5);
    (*ptcr)->line_to(x, y-0.5);
    (*ptcr)->stroke();
    }
void graphic_draw_losange(double x,double y,double r, double g, double b){
    (*ptcr)->set_line_width(1./sqrt(2));
    (*ptcr)->set_source_rgb(r, g, b);
    (*ptcr)->move_to(x-0.25, y-0.25);
    (*ptcr)->line_to(x+0.25, y+0.25);
    (*ptcr)->stroke();
}
void graphic_draw_plus(double x,double y, double size, double r, double g, double b){
    (*ptcr)->set_line_width(size/3);
    (*ptcr)->set_source_rgb(r, g, b);
    (*ptcr)->move_to(x-size/2, y);
    (*ptcr)->line_to(x+size/2, y);
    (*ptcr)->move_to(x, y+size/2);
    (*ptcr)->line_to(x, y-size/2);
    (*ptcr)->stroke();
}
void graphic_draw_croix(double x, double y, double r, double g, double b ){
    graphic_draw_carre_plein(x-3/2,y+3/2,1,r,g,b);
    graphic_draw_carre_plein(x-3/2,y-3/2,1,r,g,b);
    graphic_draw_carre_plein(x+3/2,y+3/2,1,r,g,b);
    graphic_draw_carre_plein(x+3/2,y-3/2,1,r,g,b);
    graphic_draw_carre_plein(x,y,1,r,g,b);
}
