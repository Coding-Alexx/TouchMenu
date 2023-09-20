// Created by ChatGPT

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>

bool isOperator(char c) {
    return (c == '*' || c == '/' || c == '+' || c == '-');
}

int precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0; // Für Klammern
}

float applyOperator(float a, float b, char op) {
    switch (op) {
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                std::cerr << "Division durch Null ist nicht erlaubt." << std::endl;
                return 0; // Fehler bei Division durch Null
            }
        case '+':
            return a + b;
        case '-':
            return a - b;
        default:
            std::cerr << "Ungültiger Operator: " << op << std::endl;
            return 0; // Fehlerhafter Operator
    }
}

float evaluateFormula(const std::string& formula) {
    std::stack<char> operatorStack;
    std::stack<float> valueStack;

    for (size_t i = 0; i < formula.length(); ++i) {
        char c = formula[i];

        if (std::isdigit(c)) {
            // Verarbeitung von mehrstelligen Zahlen
            std::string number = "";
            while (i < formula.length() && (std::isdigit(c) || c == '.')) {
                number += c;
                ++i;
                if (i < formula.length()) {
                    c = formula[i];
                }
            }
            --i; // Zurückgehen, um das korrekte Zeichen für den nächsten Schleifendurchlauf zu verwenden
            float num = std::atof(number.c_str());
            valueStack.push(num);
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                char op = operatorStack.top();
                operatorStack.pop();
                float b = valueStack.top();
                valueStack.pop();
                float a = valueStack.top();
                valueStack.pop();
                float result = applyOperator(a, b, op);
                valueStack.push(result);
            }
            operatorStack.push(c);
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                char op = operatorStack.top();
                operatorStack.pop();
                float b = valueStack.top();
                valueStack.pop();
                float a = valueStack.top();
                valueStack.pop();
                float result = applyOperator(a, b, op);
                valueStack.push(result);
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop(); // Entferne die öffnende Klammer
            } else {
                std::cerr << "Ungültige Klammerausdrücke in der Formel." << std::endl;
                return 0; // Fehler bei den Klammern
            }
        }
    }

    while (!operatorStack.empty()) {
        char op = operatorStack.top();
        operatorStack.pop();
        float b = valueStack.top();
        valueStack.pop();
        float a = valueStack.top();
        valueStack.pop();
        float result = applyOperator(a, b, op);
        valueStack.push(result);
    }

    if (valueStack.size() == 1) {
        return valueStack.top();
    } else {
        std::cerr << "Ungültige Formel." << std::endl;
        return 0; // Fehler bei der Auswertung
    }
}