#pragma once

#include <Arduino.h>
#include <functional>
#include "../Element.h"

#define TML_goTo (tml, id) [](){tml.goTo(id);}
#define TML_goTo_without_History (tml, id) [](){tml.goTo(id, false);}
#define TML_back (tml) [](){tml.back();}
#define TML_empty_button [](){}
#define TML_empty_switch [](bool){}

#ifndef BUTTON_ON_TIME
    #define BUTTON_ON_TIME 400
#endif

#ifndef BUTTON_LONG_TIME
    #define BUTTON_LONG_TIME 500
#endif

class ExternalButtonValue {
    Item* itemOn = nullptr;
    Item* itemOff = nullptr;
    bool value = false;
    bool update = false;
    bool onlyOneItem = false;

public:
    // man gibt die Verantwortung über den Pointer ab!
    void setItemOn (Item* item) {
        delete itemOn;
        itemOn = item;
        update = true;
        onlyOneItem = false;
    }

    void setItem (const char* item) { setItem(Display::createItem(item)); }
    void setItemOn (const char* item) { setItemOn(Display::createItem(item)); }
    void setItemOff (const char* item) { setItemOff(Display::createItem(item)); }

    void setItemOff (Item* item) {
        delete itemOff;
        itemOff = item;
        update = true;
        onlyOneItem = false;
    }

    void setItem (Item* item) {
        delete itemOn;
        itemOn = item;
        delete itemOff;
        itemOff = nullptr;
        onlyOneItem = true;
        update = true;
    }

    void setValue (const bool _value) { 
        value = _value; 
        update = true;
    }

    bool  getValue () const { return value; }
    Item* getItemOn () const { return itemOn; }
    Item* getItemOff () const { return (onlyOneItem)? itemOn : itemOff; }

    bool hasItemOn () const { return itemOn != nullptr; }
    bool hasItemOff () const { return (onlyOneItem && hasItemOn()) || (!onlyOneItem && itemOff != nullptr); }
    bool hasUpdate () const { return update; }
    void resetUpdate () { update = false; }
};

class Button: public Element {
protected:
    // typedef void (*button_func_ptr) ();
    // typedef void (*switch_func_ptr) (bool);
    
    const std::function<void()> button_callback = [](){};
    const std::function<void(bool)> switch_callback = [](bool){};
    const std::function<void()> longpress_callback = [](){};
    ExternalButtonValue* externalValue = nullptr;
    const bool isButton;
    const bool hasLongPress = false;
    bool value = false;
    bool blocked = false;

    void setTouch(Inputs& input) override;

private:
    // TODO: Smartpointer nutzen
    unsigned long animationTimer = 0; // für eine kleine Animation
    unsigned long longPressTimer = 0; // für eine kleine Animation

    void loop(Inputs& input) override;
    // void loop() override;

public:
    bool getValue() const { return value; }
    Button(std::function<void()> button_callback, ExternalButtonValue* externalValue = nullptr);
    Button(std::function<void()> button_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue = nullptr);
    
    Button(std::function<void(bool)> swich_callback, ExternalButtonValue* externalValue = nullptr);
    Button(std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, ExternalButtonValue* externalValue = nullptr);
    
    Button(std::function<void()> button_callback, std::function<void(bool)> swich_callback, std::function<void()> longpress_callback, const bool isButton, const bool hasLongPress, ExternalButtonValue* externalValue = nullptr);
    virtual ~Button();
    bool select() override;
};