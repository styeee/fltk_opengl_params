#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "visual.h"
#include <math.h>
#include "graphics.h"

int main()
{
    Fl_Window win(1200,800,"line");

    graphics<64>g;
        #define max_letters 2
        desribe_visual(graph,0,0,1200,800,
        {
            graphics<64>*temp=((graphics<64>*)memory);
            temp->next(vis_get(graph,x)/100.);
            temp->paint();
        }
        ,&g,x);
    g.start(.0025,&graph);
    
    win.end();
    win.show();
    win.resizable(graph);

    return Fl::run();
}