#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "visual.h"
#include <math.h>

int main()
{
    Fl_Window win(1200,800,"line");

        #define max_letters 3
        desribe_visual(line,0,0,600,400,
        {
            glLineWidth(vis_get(line,ll)>>3);

            glBegin(GL_LINE_STRIP);
                glVertex2f(vis_get(line,x1)/100.,vis_get(line,y1)/100.);
                glVertex2f(vis_get(line,x2)/100.,vis_get(line,y2)/100.);
            glEnd();
        }
        ,x1,y1,x2,y2,ll);
        
        #define max_letters 2
        desribe_visual(point,600,0,600,400,
        {
            glPointSize(vis_get(point,l));

            glBegin(0);
                glVertex2f(vis_get(point,x)/100.,vis_get(point,y)/100.);
            glEnd();
        }
        ,x,y,l);
        
        desribe_visual(round,0,400,600,400,
        {
            glBegin(GL_POLYGON);
            constexpr float ratio=600./400.;
            for(float i=0;i<6.2831;i+=(6.2831/vis_get(round,d)))
                glVertex2f(vis_get(round,x)/100.+cos(i)/vis_get(round,r)/ratio,vis_get(round,y)/100.+sin(i)/vis_get(round,r)*ratio);
            glEnd();
        }
        ,x,y,r,d);

        desribe_visual(tri,600,400,600,400,
        {
            glColor3f(vis_get(tri,r)/100.,vis_get(tri,g)/100.,vis_get(tri,b)/100.);
            glPushMatrix();
            
            glTranslatef(vis_get(tri,x)/100.,vis_get(tri,y)/100.,0);
            glRotatef(vis_get(tri,a),0,0,1);

            glBegin(GL_TRIANGLES);
                glVertex2f(0,0);
                glVertex2f(.25,.5);
                glVertex2f(.5,0);
            glEnd();

            glPopMatrix();
        }
        ,x,y,a,r,g,b);
        
    win.end();
    win.show();

    return Fl::run();
}