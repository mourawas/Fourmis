#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED

#include <gtkmm.h>
#include <string>
#include "simulation.h"

struct Frame
{
	double xMin;
	double xMax;
	double yMin;
	double yMax;
	double asp;
	int height;
	int width;
};

class MyArea : public Gtk::DrawingArea
{
public:
	MyArea();
	virtual ~MyArea();
	void setFrame(Frame x); 
	void adjustFrame();
	void set_simulation(Simulation* sim);
	void refresh();
protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
  
private:
	Frame frame;
	Simulation* s;
};

class MyEvent : public Gtk::Window
{
public:
	MyEvent();
	virtual ~MyEvent();
	
	void set_simulation(Simulation* sim);
	void fourmiliere_info(int& id);
	void nourriture_info();
	void etape();
protected:
	void on_button_clicked_exit();
	void on_button_clicked_open();
	void on_button_clicked_save();
	void on_button_clicked_start();
	void on_button_clicked_step();
	void on_button_clicked_previous();
	void on_button_clicked_next();
	
	Gtk::Box m_Box, m_Box_Left, m_Box_Right;
	MyArea m_Area;
	
	Gtk::Separator m_Separator1;
	Gtk::Separator m_Separator2;

	Gtk::Button m_Button_exit;
	Gtk::Button m_Button_open;
	Gtk::Button m_Button_save;
	Gtk::Button m_Button_start;
	Gtk::Button m_Button_step;
	Gtk::Button m_Button_previous;
	Gtk::Button m_Button_next;
	
	Gtk::Label m_Label_General;
	Gtk::Label m_Label_Info;
	Gtk::Label m_Label_Fourmiliere;
	Gtk::Label m_Label_Info_Fourmiliere;
	
	bool on_timeout();
	bool timer_added;
	bool disconnected;
	const unsigned int timeout;
	unsigned int val;
	int id;
	
	bool on_key_press_event(GdkEventKey * key_event);
private:
    Simulation* s;
};

#endif
