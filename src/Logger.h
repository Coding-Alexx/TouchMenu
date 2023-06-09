#include <Arduino.h>

#ifdef DEBUG

    #define LOGGER(param) LOGGER_VALUE(param)

    #define LOGGER_BEGIN(bound) Serial.begin(bound);
    #define LOGGER_VALUE(param) do { \
        __logger_print_head(__LINE__, __FILE__, __func__); \
        const char* p = #param;\
        if ((p[0] >= 'a' && p[0] <= 'z') || (p[0] >= 'A' && p[0] <= 'Z') || p[0] == '_' ) {Serial.print(p); Serial.print("=");}\
        Serial.println(param); \
    } while (0);

    #define LOGGER_PATTERN(str, ...) do { \
        __logger_print_head(__LINE__, __FILE__, __func__); \
        __logger_print_pattern(str, __VA_ARGS__); \
        Serial.println();\
    } while(0);
    
    #define LOGGER_ERROR(text) \
    do { \
        Serial.print("\x1b[31m"); \
        LOGGER_VALUE(text); \
        Serial.print("\x1b[0m"); \
    } while(0);

    inline void __logger_print_head(uint16_t line, const char* file, const char* func) {
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
    }

// Basisfall der rekursiven Variadic Template Function
inline void __logger_print_pattern(const char* str) {
//   while (*str != '\0') {
//     if (*str != '_')
//       Serial.print(*str);
//     str++;
//   }
  Serial.print(str);
}

// Rekursiver Fall der Variadic Template Function
template<typename T, typename... Args>
inline void __logger_print_pattern(const char* str, T arg, Args... args) {
  while (*str != '\0') {
    if (*str != '_')
        Serial.print(*str);
    else {
        Serial.print(arg);
        __logger_print_pattern(++str, args...);  // Aufruf der Funktion mit dem verbleibenden Teil des Parameter-Packs
        return;
    }
    str++;
  }
}

#else
    #define LOGGER(param)
    #define LOGGER_BEGIN(bound) 
    #define LOGGER_PATTERN(str, ...)
    #define LOGGER_BEGIN(bound)
#endif