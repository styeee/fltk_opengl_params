#pragma once

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