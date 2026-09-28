#include <iostresam>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
class Vehiculo {
protected:
    string marca;
    string modelo;
    int anio;

public:
    Vehiculo(string m, string mod, int a) : marca(m), modelo(mod), anio(a) {}

    
    virtual ~Vehiculo() {}

    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getAnio() const { return anio; }

    virtual void mostrarInfo() const {
        cout << "Marca: " << marca << " | Modelo: " << modelo << " | Año: " << anio;
    }
};


class Coche : public Vehiculo {
private:
    int numPuertas;
    string tipoCombustible;

public:
    Coche(string m, string mod, int a, int puertas, string combustible)
        : Vehiculo(m, mod, a), numPuertas(puertas), tipoCombustible(combustible) {}

    int getNumPuertas() const { return numPuertas; }
    string getTipoCombustible() const { return tipoCombustible; }

    void mostrarInfo() const override {
        cout << "[COCHE] ";
        Vehiculo::mostrarInfo();
        cout << " | Puertas: " << numPuertas << " | Combustible: " << tipoCombustible << endl;
    }
};


class Motocicleta : public Vehiculo {
private:
    int cilindrada; 
    string tipoManillar;

public:
    Motocicleta(string m, string mod, int a, int cc, string manillar)
        : Vehiculo(m, mod, a), cilindrada(cc), tipoManillar(manillar) {}

    int getCilindrada() const { return cilindrada; }
    string getTipoManillar() const { return tipoManillar; }

    void mostrarInfo() const override {
        cout << "[MOTOCICLETA] ";
        Vehiculo::mostrarInfo();
        cout << " | Cilindrada: " << cilindrada << " cc | Manillar: " << tipoManillar << endl;
    }
};

class Camion : public Vehiculo {
private:
    double capacidadCarga; 
    int numEjes;

public:
    Camion(string m, string mod, int a, double carga, int ejes)
        : Vehiculo(m, mod, a), capacidadCarga(carga), numEjes(ejes) {}

    double getCapacidadCarga() const { return capacidadCarga; }
    int getNumEjes() const { return numEjes; }

    void mostrarInfo() const override {
        cout << "[CAMIÓN] ";
        Vehiculo::mostrarInfo();
        cout << " | Carga: " << capacidadCarga << " t | Ejes: " << numEjes << endl;
    }
};

int main() {
   
    vector garaje;

    garaje.push_back(new Coche("Toyota", "Corolla", 2022, 4, "Nafta"));
    garaje.push_back(new Motocicleta("Yamaha", "MT-07", 2023, 689, "Deportivo"));
    garaje.push_back(new Camion("Mercedes-Benz", "Actros", 2021, 18.5, 3));

    cout << "--- LISTADO DE VEHÍCULOS EN EL GARAJE ---\n\n";

    for (const auto& vehiculo : garaje) {
        vehiculo->mostrarInfo();
    }

    
    for (auto vehiculo : garaje) {
        delete vehiculo;
    }
    garaje.clear();

    return 0;
}