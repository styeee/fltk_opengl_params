#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "visual.h"
#include <math.h>

const size_t size=64;
float points[size]={0};
float time;
size_t cur=0;

static void timer(void*d)
{
    cur=(cur+1)%size;
    ((visual<1,2>*)d)->redraw();
    Fl::repeat_timeout(.025,timer,d);
}

int main()
{
    Fl_Window win(1200,800,"line");

        #define max_letters 2
        desribe_visual(graph,0,0,1200,800,
        {
            points[cur]=vis_get(graph,x)/100.;

            glBegin(GL_LINE_STRIP);
                 const size_t max__=size+1;
                 const size_t min__=size-1;
                for(size_t i=1;i!=min__;i++)
                    glVertex2f(float(i)/size,points[(i+cur)%min__]);
            glEnd();
        }
        ,x);
    
    Fl::add_timeout(.025,timer,&graph);
    
    win.end();
    win.show();
    win.resizable(graph);

    return Fl::run();
}