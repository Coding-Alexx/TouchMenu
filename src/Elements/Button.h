#include <Arduino.h>
#include "../Element.h"

#pragma once

class Button: public Element {
protected:
    typedef void (*button_func_ptr) ();
    typedef void (*switch_func_ptr) (bool);
    
    const button_func_ptr button_callback;
    const switch_func_ptr switch_callback;
    bool value;

    void loop();

private:
    // TODO: Smartpointer nutzen
    bool* externalValue; // man gibt einen Pointer an, wo man von außen den Wert anpassen önnte (z.B. wenn das Licht per Lichtschalter angeschalten wurde, dass sich der Wert aktualisieren kann)
    unsigned long timer = 0; // für eine kleine Animation

public:
    Button(button_func_ptr button_callback);
    Button(switch_func_ptr swich_callback);
    virtual ~Button();
    void setExternalValue(bool* value);
    bool select() override;
};