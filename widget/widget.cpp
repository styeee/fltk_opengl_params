#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "visual.h"

int main()
{
    Fl_Window win(1200,800,"line");

        #define max_letters 3
        desribe_visual(TEST,0,0,1200,800,[](int*p)
        {
            glBegin(GL_LINE_STRIP);
                glVertex2f(p[x1]/100.,p[y1]/100.);
                glVertex2f(p[x2]/100.,p[y2]/100.);
            glEnd();
        }
        ,x1,y1,x2,y2);

    win.end();
    win.resizable(TEST);
    win.show();

    return Fl::run();
}