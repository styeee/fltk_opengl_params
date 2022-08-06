#pragma once

#include <GL/freeglut.h>
#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/gl.h>
#include <Fl/Fl_Scroll.H>
#include <Fl/Fl_Group.H>
#include <Fl/Fl_Box.H>

template<size_t count,size_t name_size=4>
class visual:public Fl_Group
{
    int params[count];

    class canvas:public Fl_Gl_Window
    {
        int*params;
        void(*repaint)(int*);
        
        void draw()
        {
            if(!valid())
            {
                glLoadIdentity();
                glViewport(0,0,w(),h());
                glOrtho(0,1,0,1,-1,1);
                glLineWidth(3);
                glPointSize(5);
            }

            glClearColor(0,0,0,1);
            glClear(GL_COLOR_BUFFER_BIT);

            repaint(params);
        }
    public:
        canvas(const int x,const int y,const int w,const int h,void(*f)(int*),int*p)
            :Fl_Gl_Window(x,y,w,h),repaint(f),params(p)
        {}
    };

    canvas*c;
    Fl_Scroll*s;
    Fl_Box*m;
    Fl_Slider*p[count];
public:

    visual(const int x,const int y,const int w,const int h,void(*f)(int*),const char*names=0)
        :Fl_Group(x,y,w,h)
    {
        const size_t slider_size=200;
        const size_t slider_pos=y+h-slider_size;

        const size_t slider_wide=w-50;
        
        const size_t slider_metric=20;
        const size_t slider_double=slider_metric<<1;

        const size_t slider_hax=slider_pos+slider_double;

        c=new canvas(x,y,w,slider_pos-y,f,params);

        s=new Fl_Scroll(x,slider_pos,w,slider_size);
            m=new Fl_Box(x+slider_metric,slider_pos,slider_wide,slider_metric);

            if(names)
            {
                for(size_t i=0,j=0;i<count;i++,j+=slider_double)
                    p[i]=new Fl_Slider(x+slider_metric,slider_hax+j,slider_wide,slider_metric,
                        names+i*name_size);
            }
            else
            {
                for(size_t i=0,j=0;i<count;i++,j+=slider_double)
                    p[i]=new Fl_Slider(x+slider_metric,slider_hax+j,slider_wide,slider_metric);
            }

            for(size_t i=0;i<count;i++)
            {
                p[i]->selection_color(i);
                p[i]->minimum(1);
                p[i]->maximum(100);
                p[i]->type(1);
                p[i]->align(FL_ALIGN_TOP);
                p[i]->callback([](Fl_Widget*self,void*d)
                {
                    ((visual*)d)->update(((Fl_Scroll*)self)->selection_color());
                },this);
            }
        s->end();

        end();
    }

    inline
    void update(const size_t id)
    {params[id]=p[id]->value();c->redraw();}

    inline void redraw(){c->redraw();}
};

const char*params_beauty(const char*text)
{
    char*buffer=new char[strlen(text)+1]{0};

    for(size_t i=0;text[i];i++)
    {
        if(text[i]==',')buffer[i]=0;
        else buffer[i]=text[i];
    }

    return buffer;
}

#define max_letters 4

#define desribe_visual(name,x,y,w,h,f,...) enum class name##_p{__VA_ARGS__,sys_last};\
visual<size_t(name##_p::sys_last),max_letters>name(x,y,w,h,[](int*param) f,params_beauty(#__VA_ARGS__));\

#define vis_get(name,id) param[size_t(name##_p::id)]