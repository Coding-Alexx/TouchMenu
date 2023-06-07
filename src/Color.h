#include <Arduino.h>

#pragma once


#ifdef DEBUG

    #define LOGGER_BEGIN(bound) Serial.begin(bound);
    #define LOGGER(param) do { \
        __logger_print_head(__LINE__, __FILE__, __func__, #param); \
        Serial.println(param); \
    } while (0);
    
    #define LOGGER_ERROR(text) \
    do { \
        Serial.print("\x1b[31m"); \
        LOGGER(text); \
        Serial.print("\x1b[0m"); \
    } while(0);

    inline void __logger_print_head(uint16_t line, const char* file, const char* func, const char* param) {
            const char* fileName = file;

        // Dateinamen extrahieren (nur den letzten Teil des Pfads)
        const char* separator = strrchr(file, '/');
        if (separator != nullptr) {
            fileName = separator + 1;
        } else {
            separator = strrchr(file, '\\');
            if (separator != nullptr) {
            fileName = separator + 1;
            }
        }

        Serial.print("[");
        Serial.print(fileName);
        Serial.print(":");
        Serial.print(line);
        Serial.print(" - ");
        Serial.print(func);
        Serial.print("] ");

        if ((param[0] >= 'a' && param[0] <= 'z') || (param[0] >= 'A' && param[0] <= 'Z') || param[0] == '_' ) {
            Serial.print(param);
            Serial.print("=");
        }
    }

#else
    #define LOGGER(param)
    #define LOGGER_BEGIN(bound) 
#endif

#define COLOR_RED       Color(255, 0,   0   )
#define COLOR_GREEN     Color(0,   255, 0   )
#define COLOR_BLUE      Color(0,   0,   255 )
#define COLOR_BLACK     Color(0,   0,   0   )
#define COLOR_WHITE     Color(255, 255, 255 )
#define COLOR_YELLOW    Color(255, 255, 0   )

class Color {
private:
    const uint8_t red;
    const uint8_t green;
    const uint8_t blue;

public:
    inline Color (const uint8_t r, const uint8_t g, const uint8_t b) : red(r), green(g), blue(b) {
        LOGGER(toString())
    };
    //inline Color () : red(0), green(0), blue(0) {};
    inline uint8_t getRed   () const {return red;}
    inline uint8_t getGreen () const {return green;}
    inline uint8_t getBlue  () const {return blue;}

    inline Color& operator= (const Color& other) {
        LOGGER("Kopiere Color mit =")
        LOGGER(toString())
        return *this = Color(other.red, other.green, other.blue);
    }

    inline Color(const Color& other) : 
        red(other.red),
        green(other.green),
        blue(other.blue) {
            LOGGER("Kopiere Color:")
            LOGGER(toString())
        }
    
    inline virtual ~Color() {}

    inline Color operator!() const {
        return Color(255-red, 255-green, 255-blue);
    }

    inline String toString() const {
        return "Color(r=" + String(red) + ", g=" + String(green) + ", b=" + String(blue) + ")";
    }
};