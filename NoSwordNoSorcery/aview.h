#ifndef AVIEW_H
#define AVIEW_H

class AView
{
public:
    AView();
    virtual void Render(void) = 0;
    virtual void Update(void);
protected:
};

#endif // AVIEW_H
