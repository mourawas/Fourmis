#include "gui.h"
#include <cairomm/context.h>
#include <string>
using namespace std;

static Frame default_frame = {-1, 129, -1, 129, 1, 500, 500};
// xmin,xmax,ymin,ymax

MyArea::MyArea()
{
}

MyArea::~MyArea()
{
}

void MyArea::setFrame(Frame f)
{
	f.asp = f.width/f.height;
	frame = f;
} 

void MyArea::adjustFrame()
{
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();
	
    
	frame.width  = width;
	frame.height = height;

    double new_aspect_ratio((double)width/height);
    if( new_aspect_ratio > default_frame.asp)
    {
	    frame.yMax = default_frame.yMax ;
	    frame.yMin = default_frame.yMin ;	
	  
	    double delta(default_frame.xMax - default_frame.xMin);
	    double mid((default_frame.xMax + default_frame.xMin)/2);
	    
	    frame.xMax = mid + 0.5*(new_aspect_ratio/default_frame.asp)*delta ;
	    frame.xMin = mid - 0.5*(new_aspect_ratio/default_frame.asp)*delta ;		  	  
    }
    else
    {
	    frame.xMax = default_frame.xMax ;
	    frame.xMin = default_frame.xMin ;
	  	  
 	    double delta(default_frame.yMax - default_frame.yMin);
	    double mid((default_frame.yMax + default_frame.yMin)/2);
	    
	    frame.yMax = mid + 0.5*(default_frame.asp/new_aspect_ratio)*delta ;
	    frame.yMin = mid - 0.5*(default_frame.asp/new_aspect_ratio)*delta ;		  	  
    }
}

static void orthographic_projection(const Cairo::RefPtr<Cairo::Context>& cr, 
									Frame frame)
{
	cr->translate(frame.width/2, frame.height/2);
  
	cr->scale(frame.width/(frame.xMax - frame.xMin), 
             -frame.height/(frame.yMax - frame.yMin));
  
	cr->translate(-(frame.xMin + frame.xMax)/2, -(frame.yMin + frame.yMax)/2);
}

bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
	
    adjustFrame();
    orthographic_projection(cr, frame);
    
    graphic_set_context(cr);
    graphic_draw_window();`
    
    for (size_t i = 0; i < vfourmiliere.size(); ++i)
    {
        vfourmiliere[i].d_Anthill(i);
    }
    for (size_t i = 0; i < vnourriture.size(); ++i)
    {
        vnourriture[i].dessin_nourriture();
    }
	return true;
}

MyEvent::~MyEvent()
{
}

MyEvent::MyEvent() :
	m_Box(Gtk::ORIENTATION_HORIZONTAL,10),
	m_Box_Left(Gtk::ORIENTATION_VERTICAL, 10),
	m_Button_exit("exit"),
	m_Button_open("open"),
	m_Button_save("save"),
	m_Button_start("start"),
	m_Button_step("step"),
	m_Button_previous("previous"),
	m_Button_next("next"),
	m_Label_General("General"),
	m_Label_Info("Info"),
	m_Label_Anthill("Anthill info"),
	timer_added(false),
	disconnected(false),
	timeout(1000),
	val(1)
		
{
	set_title("test");
	set_border_width(0);
  
	add(m_Box);

	m_Box.pack_start(m_Box_Left, false, false);
	m_Box.pack_start(m_Box_Right);
	
	m_Box_Left.pack_start(m_Label_General);
	m_Box_Left.pack_start(m_Button_exit,false,false);
	m_Box_Left.pack_start(m_Button_open,false,false);
	m_Box_Left.pack_start(m_Button_save,false,false);
	m_Box_Left.pack_start(m_Button_start,false,false);
	m_Box_Left.pack_start(m_Button_step,false,false);
	
	m_Box_Left.pack_start(m_Separator1);
	m_Box_Left.pack_start(m_Label_Info);
	
	m_Box_Left.pack_start(m_Separator2);
	m_Box_Left.pack_start(m_Label_Anthill);
	m_Box_Left.pack_start(m_Button_previous,false,false);
	m_Box_Left.pack_start(m_Button_next,false,false);
	
	m_Area.set_size_request(500,500);
	m_Box_Right.pack_start(m_Area);
	
	m_Button_exit.signal_clicked().connect(sigc::mem_fun(*this,
              &MyEvent::on_button_clicked_exit) );
	m_Button_open.signal_clicked().connect(sigc::mem_fun(*this,
              &MyEvent::on_button_clicked_open) );
    m_Button_save.signal_clicked().connect(sigc::mem_fun(*this,
              &MyEvent::on_button_clicked_save) );
    m_Button_start.signal_clicked().connect(sigc::mem_fun(*this,
              &MyEvent::on_button_clicked_start) );
    m_Button_step.signal_clicked().connect(sigc::mem_fun(*this,
              &MyEvent::on_button_clicked_step) );
    m_Button_previous.signal_clicked().connect(sigc::mem_fun(*this,
              &MyEvent::on_button_clicked_previous) );
    m_Button_next.signal_clicked().connect(sigc::mem_fun(*this,
              &MyEvent::on_button_clicked_next) );
    
	show_all_children();
}

void MyEvent::on_button_clicked_exit()
{
    exit(0);
}

void MyEvent::on_button_clicked_open() //INCOMPLETE
{
    Gtk::FileChooserDialog dialog("Please choose a file",
            Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    int result = dialog.run();
    switch(result)
    {
		case(Gtk::RESPONSE_OK):
		{
			cout << "Open clicked." << endl;
			string filename = dialog.get_filename();
			cout << "File selected: " <<  filename << endl;
            char * argv;
            argv = &filename[0];
			s->tout_supprimer();
            s->lancement(argv);
			break;
		}
		case(Gtk::RESPONSE_CANCEL):
		{
			cout << "Cancel clicked." << endl;
			break;
		}
		default:
		{
			cout << "Unexpected button clicked." << endl;
			break;
		}
    }
	cout << "open" << endl;
}

void MyEvent::on_button_clicked_save()
{
	//A DEFINIR
	cout << "save" << endl;
}

void MyEvent::on_button_clicked_start()
{
	
	if(!timer_added){
		m_Button_start.set_label("stop");
		Glib::signal_timeout().connect(
		sigc::mem_fun(*this, &MyEvent::on_timeout), timeout);
		
		timer_added = true;
		cout << "Timer added" << endl;
	}else{
		m_Button_start.set_label("start");
		timer_added = false;
		disconnected = true;
	}
}

void MyEvent::on_button_clicked_step()
{
	if(!timer_added){
		cout << val << endl;
		++val;
	}
}

void MyEvent::on_button_clicked_previous()
{
	cout << "previous" << endl;
}

void MyEvent::on_button_clicked_next()
{
	cout << "next" << endl;
}

bool MyEvent::on_timeout()
{
  if(disconnected)
  {
	  disconnected = false;
	  
	  return false;
  }
  
  cout << val << endl;
  ++val;


  return true; 
}

bool MyEvent::on_key_press_event(GdkEventKey * key_event){
	
	if(key_event->type == GDK_KEY_PRESS){
		
		switch(gdk_keyval_to_unicode(key_event->keyval))
		{
			case 's':
				cout << "s" << endl;
				on_button_clicked_start();
				break;
			case '1':
				cout << "1" << endl;
				on_button_clicked_step();
				break;
			case 'n':
				cout << "n" << endl;
				on_button_clicked_next();
				break;
			case 'p':
				cout << "p" << endl;
				on_button_clicked_previous();
				break;
			case 'q':
				cout << "q" << endl;
				on_button_clicked_exit();
				break;
		}
	}
	return Gtk::Window::on_key_press_event(key_event);
}

void MyEvent::set_simulation(Simulation* sim){
	s = sim;
}
