#include <iostresam>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Mesa {
private:
    int numero;
    int capacidad;
    bool ocupada;

public:
    Mesa(int num, int cap) : numero(num), capacidad(cap), ocupada(false) {}

    int getNumero() const { return numero; }
    int getCapacidad() const { return capacidad; }
    bool estaOcupada() const { return ocupada; }

    void ocupar() { ocupada = true; }
    void liberar() { ocupada = false; }

    void mostrarInfo() const {
        cout << "Mesa #" << numero 
             << " | Capacidad: " << capacidad << " comensales"
             << " | Estado: " << (ocupada ? "Ocupada" : "Libre") << endl;
    }
};

class Restaurante {
private:
    vector mesas;

public:
  
    void agregarMesa(const Mesa& mesa) {
        mesas.push_back(mesa);
    }

    
    bool reservarMesa(int comensales) {
        for (auto& mesa : mesas) {
            
            if (!mesa.estaOcupada() && mesa.getCapacidad() >= comensales) {
                mesa.ocupar();
                cout << "Mesa #" << mesa.getNumero() 
                     << " reservada con éxito para " << comensales << " personas.\n";
                return true;
            }
        }
        cout << "No hay mesas libres con capacidad suficiente para " << comensales << " personas.\n";
        return false;
    }

    
    bool liberarMesa(int numeroMesa) {
        for (auto& mesa : mesas) {
            if (mesa.getNumero() == numeroMesa) {
                if (mesa.estaOcupada()) {
                    mesa.liberar();
                    cout << "Mesa #" << numeroMesa << " liberada con éxito.\n";
                    return true;
                } else {
                    cout << "La mesa #" << numeroMesa << " ya estaba libre.\n";
                    return false;
                }
            }
        }
        cout << "La mesa #" << numeroMesa << " no existe en el restaurante.\n";
        return false;
    }

   
    int obtenerMesasLibres() const {
        int contador = 0;
        for (const auto& mesa : mesas) {
            if (!mesa.estaOcupada()) {
                contador++;
            }
        }
        return contador;
    }

    
    void mostrarEstado() const {
        cout << "\n--- ESTADO DEL RESTAURANTE ---\n";
        for (const auto& mesa : mesas) {
            mesa.mostrarInfo();
        }
        cout << "Total de mesas libres: " << obtenerMesasLibres() << "\n";
        cout << "------------------------------\n";
    }
};

int main() {
    Restaurante miRestaurante;

    
    miRestaurante.agregarMesa(Mesa(1, 2));
    miRestaurante.agregarMesa(Mesa(2, 4));
    miRestaurante.agregarMesa(Mesa(3, 4));
    miRestaurante.agregarMesa(Mesa(4, 6));

    
    miRestaurante.mostrarEstado();

    cout << "\n--- REALIZANDO RESERVAS ---\n";
    miRestaurante.reservarMesa(3); // Debería tomar la Mesa #2
    miRestaurante.reservarMesa(5); // Debería tomar la Mesa #4
    miRestaurante.reservarMesa(4); // Debería tomar la Mesa #3

   
    miRestaurante.mostrarEstado();

    
    miRestaurante.reservarMesa(4);

   
    cout << "\n--- LIBERANDO MESA ---\n";
    miRestaurante.liberarMesa(2);

   
    miRestaurante.mostrarEstado();

    return 0;
}