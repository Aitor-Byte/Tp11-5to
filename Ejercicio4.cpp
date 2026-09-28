#include <iostresam>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;


class Figura {
protected:
    string color;
    double posX;
    double posY;

public:
    Figura(string c, double x, double y) : color(c), posX(x), posY(y) {}

   
    virtual ~Figura() {}

    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;

    string getColor() const { return color; }
    void getPosicion(double& x, double& y) const {
        x = posX;
        y = posY;
    }

    virtual void mostrarInfo() const {
        cout << "Color: " << color << " | Posición: (" << posX << ", " << posY << ")";
    }
};


class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(string c, double x, double y, double r) : Figura(c, x, y), radio(r) {}

    double calcularArea() const override {
        return M_PI * radio * radio;
    }

    double calcularPerimetro() const override {
        return 2 * M_PI * radio;
    }

    void mostrarInfo() const override {
        cout << "[CÍRCULO] ";
        Figura::mostrarInfo();
        cout << " | Radio: " << radio 
             << " | Área: " << calcularArea() 
             << " | Perímetro: " << calcularPerimetro() << endl;
    }
};


class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(string c, double x, double y, double b, double h) 
        : Figura(c, x, y), base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura;
    }

    double calcularPerimetro() const override {
        return 2 * (base + altura);
    }

    void mostrarInfo() const override {
        cout << "[RECTÁNGULO] ";
        Figura::mostrarInfo();
        cout << " | Base: " << base << " | Altura: " << altura 
             << " | Área: " << calcularArea() 
             << " | Perímetro: " << calcularPerimetro() << endl;
    }
};


class Triangulo : public Figura {
private:
    double ladoA;
    double ladoB;
    double ladoC;

public:
    Triangulo(string c, double x, double y, double a, double b, double cLado) 
        : Figura(c, x, y), ladoA(a), ladoB(b), ladoC(cLado) {}

    double calcularPerimetro() const override {
        return ladoA + ladoB + ladoC;
    }

    
    double calcularArea() const override {
        double s = calcularPerimetro() / 2.0;
        return sqrt(s * (s - ladoA) * (s - ladoB) * (s - ladoC));
    }

    void mostrarInfo() const override {
        cout << "[TRIÁNGULO] ";
        Figura::mostrarInfo();
        cout << " | Lados: (" << ladoA << ", " << ladoB << ", " << ladoC << ")"
             << " | Área: " << calcularArea() 
             << " | Perímetro: " << calcularPerimetro() << endl;
    }
};

int main() {
   
    vector figuras;

    figuras.push_back(new Circulo("Rojo", 0.0, 0.0, 5.0));
    figuras.push_back(new Rectangulo("Azul", 2.5, -1.0, 4.0, 6.0));
    figuras.push_back(new Triangulo("Verde", -3.0, 4.0, 3.0, 4.0, 5.0));

    cout << "--- FIGURAS GEOMÉTRICAS ---\n\n";

    for (const auto& figura : figuras) {
        figura->mostrarInfo();
    }

    
    for (auto figura : figuras) {
        delete figura;
    }
    figuras.clear();

    return 0;
}