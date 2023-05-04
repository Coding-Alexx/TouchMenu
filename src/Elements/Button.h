#include <Arduino.h>
#include "../Element.h"

class Button: public Element {
private:
    typedef void (*button_func_ptr) ();
    typedef void (*switch_func_ptr) (bool);
    const button_func_ptr button_callback;
    const switch_func_ptr switch_callback;
    bool value;
    bool* externalValue; // man gibt einen Pointer an, wo man von außen den Wert anpassen önnte (z.B. wenn das Licht per Lichtschalter angeschalten wurde, dass sich der Wert aktualisieren kann)
    unsigned long timer = 0; // für eine kleine Animation
    
    void loop();

public:
    Button(const button_func_ptr button_callback);
    Button(const switch_func_ptr swich_callback);
    void setExternalValue(bool* value);
    bool select() override;
    //void loop(); // wird nicht überschrieben -> daher ist Klasse immernoch abstrakt
};