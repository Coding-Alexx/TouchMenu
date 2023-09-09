// #include "Color.h"

// Color::Color(const Color& other): 
//     red(other.red),
//     green(other.green),
//     blue(other.blue),
//     secondaryColor(other.secondaryColor),
//     textColor(other.textColor)
//     {}

// Color::Color(bool, const Color& primary): 
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue),
//     secondaryColor(nullptr),
//     textColor(nullptr)
//     {}

// Color::Color(const Color& primary, int secColor): 
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue)
//     {
//         secondaryColor = createSecondaryColor(secColor);
//         textColor = createTextColor();
//     }

// Color::Color(const Color& primary, const Color& text): 
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue),
//     secondaryColor(nullptr),
//     textColor(new Color(true, text))
//     {}

// Color::Color(const Color& primary, const Color& text, int secColor): 
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue),
//     textColor(new Color(true, text))
//     {
//         secondaryColor = createSecondaryColor(secColor);
//     }

// Color::Color(const Color& primary, const Color& text, int secColor, const Color& secText):
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue),
//     textColor(new Color(true, text))
//     {
//         secondaryColor = createSecondaryColor(secColor, secText);
//     }

// Color::Color(const Color& primary, bool, const Color& secondary): 
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue),
//     secondaryColor(new Color(secondary))
//     {
//         textColor = createTextColor();
//     }

// Color::Color(const Color& primary, const Color& text, const Color& secondary): 
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue),
//     secondaryColor(new Color(secondary)),
//     textColor(new Color(true, text))
//     {}

// Color::Color(const Color& primary, const Color& text, const Color& secondary, const Color& secText): 
//     red(primary.red),
//     green(primary.green),
//     blue(primary.blue),
//     secondaryColor(new Color(secondary, secText)),
//     textColor(new Color(true, text))
//     {}

// Color::Color (const uint8_t r, const uint8_t g, const uint8_t b):
//     red(r),
//     green(g),
//     blue(b)
//     {
//         secondaryColor = createSecondaryColor(0);
//         textColor = createTextColor();
//     }

// Color::Color (const uint8_t r, const uint8_t g, const uint8_t b, int secColor):
//     red(r),
//     green(g),
//     blue(b)
//     {
//         secondaryColor = createSecondaryColor(secColor);
//         textColor = createTextColor();
//     }

// Color::Color (const uint8_t r, const uint8_t g, const uint8_t b, const Color& secondary):
//     red(r),
//     green(g),
//     blue(b),
//     secondaryColor(new Color(secondary))
//     {
//         textColor = createTextColor();
//     }


// Color* Color::createTextColor() const {
//     if (red + green + blue < (120*3)) return new Color(true, COLOR_WHITE);
//     else return new Color(true, COLOR_BLACK);
// }

// Color* Color::createSecondaryColor(const int steps) const {
//     if (steps == 0) return nullptr;

//     const uint8_t r = min(0, red-steps);
//     const uint8_t g = min(0, green-steps);
//     const uint8_t b = min(0, blue-steps);

//     return new Color(r, g, b);
// }

// Color* Color::createSecondaryColor(const int steps, const Color& text) const {
//     const uint8_t r = min(0, red-steps);
//     const uint8_t g = min(0, green-steps);
//     const uint8_t b = min(0, blue-steps);

//     return new Color(r, g, b, text);
// }

// uint8_t Color::getRed   () const {return red;}
// uint8_t Color::getGreen () const {return green;}
// uint8_t Color::getBlue  () const {return blue;}


// Color::~Color() {
//     if (secondaryColor) delete secondaryColor;
//     if (textColor) delete textColor;
// }

// Color Color::operator!() const {
//     return Color(255-red, 255-green, 255-blue);
// }

// Color Color::operator+(const Color& secondary) const {
//     return setSecColor(secondary);
// }

// const Color Color::single(bool newTextColor) {
//     delete secondaryColor;
//     secondaryColor = nullptr;

//     if (newTextColor) return Color(*this, 0);
//     else return Color(*this, *this->textColor);
// }

// const Color Color::single(bool newTextColor) const {
//     if (newTextColor) return Color(*this, 0);
//     else return Color(*this, *this->textColor);
// }

// const Color Color::setPrimColor(const Color& color) const {
//     return Color(color, *textColor, *secondaryColor, secondaryColor->getText());
// }
// const Color Color::setPrimColor(const uint8_t r, const uint8_t g, const uint8_t b) const {
//     return Color(Color(r,g,b), *textColor, *secondaryColor, secondaryColor->getText());
// }

// const Color Color::setSecColor(const Color& secondary) const {
//     return Color(*this, true, secondary);
// }
// const Color Color::setSecColor(const uint8_t r, const uint8_t g, const uint8_t b) const {
//     return Color(*this, true, Color(r,g,b));
// }

// const Color Color::setText(const Color& text) const {
//     if (secondaryColor) return Color(*this, text, *secondaryColor, *secondaryColor->textColor);
//     else return Color(*this, text);
// }
// const Color Color::setText(const uint8_t r, const uint8_t g, const uint8_t b) const {
//     if (secondaryColor) return Color(*this, Color(r,g,b), *secondaryColor, *secondaryColor->textColor);
//     else return Color(*this, Color(r,g,b));
// }

// const Color Color::setSecText(const Color& text) const {
//     if (secondaryColor) return Color(*this, *textColor, *secondaryColor, text);
//     else return Color(*this, *textColor, *this, text);
// }
// const Color Color::setSecText(const uint8_t r, const uint8_t g, const uint8_t b) const {
//     if (secondaryColor) return Color(*this, *textColor, *secondaryColor, Color(r,g,b));
//     else return Color(*this, *textColor, *this, Color(r,g,b));
// }

// const bool Color::hasSecondaryColor() const {
//     return secondaryColor;
// }

// const Color Color::getSecColor() const {
//     if (secondaryColor) return *secondaryColor;
//     else *this;
// }

// const Color Color::getSecText() const {
//     if (secondaryColor) return *secondaryColor->textColor;
//     else return *textColor;
// }

// const Color Color::getText() const {
//     return *textColor;
// }

// String Color::toString() const {
//     String s = "none";
//     if (secondaryColor) s = secondaryColor->toString();
//     return "Color(r=" + String(red) + ", g=" + String(green) + ", b=" + String(blue) + "secColor=" + s + ")";
// }