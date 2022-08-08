#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "visual.h"
#include <math.h>

template<size_t s>
class graphics
{
    float points[s]={0};
    float time;
    size_t cur=0;
    float wait;
public:
    static void timer(void*d)
    {
        ((visual<1,2>*)d)->redraw();
        Fl::repeat_timeout(.025,timer,d);
    }

    inline
    void start(const float w,void*d)
    {wait=w;Fl::add_timeout(.025,timer,d);}

    inline
    void next(const float t)
    {points[cur]=t;cur=(cur+1)%s;}

    void paint()
    {
        glBegin(GL_LINE_STRIP);
        
         const size_t temp=s-1;
        for(size_t i=1;i!=temp;i++)
            glVertex2f(float(i)/s,points[(i+cur)%temp]);

        glEnd();
    }
};

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
    g.start(.025,&graph);
    
    win.end();
    win.show();
    win.resizable(graph);

    return Fl::run();
}