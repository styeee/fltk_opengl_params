#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "visual.h"
#include <math.h>

const size_t size=512;
float points[size]={0};
float time;

static void timer(void*d)
{
    ((visual<4,2>*)d)->redraw();
    Fl::repeat_timeout(.025,timer,d);
}

int main()
{

    Fl_Window win(1200,800,"line");

        #define max_letters 2
        desribe_visual(graph,0,0,1200,800,
        {
            time+=(vis_get(graph,t)-1)/100.;

            for(size_t i=0;i<size;i++)
                points[i]=sin(time+i/(vis_get(graph,w)+.001))
                *vis_get(graph,s)/100.
                +vis_get(graph,h)/100.;

            glBegin(GL_LINE_STRIP);
                for(size_t i=0;i<size;i++)
                    glVertex2f(float(i)/size,points[i]);
            glEnd();
        }
        ,h,s,w,t);
        
        Fl::add_timeout(.025,timer,&graph);
    
    win.end();
    win.show();
    win.resizable(graph);

    return Fl::run();
}