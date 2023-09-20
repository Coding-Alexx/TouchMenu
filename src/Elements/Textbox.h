#include <Arduino.h>
#include "../Element.h"

#pragma once

class ExternalTextboxValue {
    Item* item = nullptr;
    std::string value = "";
    bool update = false;
    bool isValueSet = false;

    uint8_t sizeX = 1;
    uint8_t sizeY = 1;
    uint8_t textsize = 0;
    Color color = Color(0,0,0);

public:
    // man gibt die Verantwortung über den Pointer ab!
    void setitem (Item* item) {
        delete item;
        item = item;
    }

    ~ExternalTextboxValue() {
        delete item;
        item = nullptr;
    }

    Item* getItem () const { return item; }
    const char*  getValue () const { return value.c_str(); }
    const Color&  getColor () const { return color; }

    uint8_t getSize() const { return textsize; }
    bool  hasValue () const { return (item != nullptr || isValueSet); }
    bool  hasUpdate () const { return update; }

    void  resetUpdate () { update = false; }

    void draw (const uint8_t x, const uint8_t y, Display* disp) const {
        LOGGER(value.c_str())
        if (item) item->draw(x, y, disp);
        else if (isValueSet && textsize == 0) Text(value, sizeX, sizeY).draw(x, y, disp);
        else if (isValueSet) Text(value, textsize).draw(x, y, disp);
    }

    void setItem (char* itemStr) { setItem(Display::createItem(itemStr)); }
    void setItem (char* itemStr, const Color& color) { setItem(Display::createItem(itemStr, color)); }
    void setItem (Item* _item) {
        delete item;
        item = _item;
        update = true;
    }

    void setValue (const char* _value) { 
        value = _value; 
        isValueSet = true; 
        delete item;
        item = nullptr; 
        update = true;
    }
    
    void delValue () { 
        value = ""; 
        isValueSet = false;
        update = true;
    }

    void setColor (const Color& _color) { 
        color = _color;
        update = true;
    }

    void setup(const uint8_t _sizeX, const uint8_t _sizeY) {
        sizeX = _sizeX;
        sizeY = _sizeY;
        textsize = 0;
        update = true;
    }

    void setup(const uint8_t _textsize) {
        sizeX = 0;
        sizeY = 0;
        textsize = _textsize;
        update = true;
    }

    ExternalTextboxValue& operator+=(const char* str) {
        value += str;
        update = true;
        return *this;
    }
};

class Textbox: public Element {
protected:
    Item* item = nullptr;
    ExternalTextboxValue* externalValue = nullptr;

private:
    virtual void loop(Inputs& input) override;
    // virtual void loop() override;
    virtual void setTouch(Inputs& input) override;

public:
    Textbox(Item* item, ExternalTextboxValue* value = nullptr);
    Textbox(Item* item, const uint8_t textsize, ExternalTextboxValue* value = nullptr);
    virtual bool checkSize(uint16_t sizeX, uint16_t sizeY, uint8_t rotation) override;
    virtual ~Textbox();
    bool select() override;
};