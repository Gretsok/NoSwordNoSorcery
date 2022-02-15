#ifndef ACONTROLLER_H
#define ACONTROLLER_H

#include "aview.h"
#include "amodel.h"
class AController
{
public:
    AController();
    virtual ~AController();

    virtual void UpdateGameStates(void);
    virtual void Render(void);
    virtual void OnViewSwitched() = 0;

    template <class T> T GetView()
    {
        return (T) this->View;
    }

    template <class T> T GetModel()
    {
        return (T) this->Model;
    }

protected:
    AView * View;
    AModel* Model;
};

#endif // ACONTROLLER_H
