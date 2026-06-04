#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class GrafoDependencias {
private:
    unordered_map<string, vector<string>> grafo;

    // DFS para mostrar orden de carga
    void DFS(string nodo, unordered_map<string, bool>& visitado) {
        visitado[nodo] = true;
        cout << nodo << " ";

        for (string vecino : grafo[nodo]) {
            if (!visitado[vecino]) {
                DFS(vecino, visitado);
            }
        }
    }

    // DFS para detectar ciclos
    bool detectarCicloDFS(string nodo,
                          unordered_map<string, bool>& visitado,
                          unordered_map<string, bool>& enRecursion) {

        visitado[nodo] = true;
        enRecursion[nodo] = true;

        for (string vecino : grafo[nodo]) {

            if (!visitado[vecino]) {

                if (detectarCicloDFS(vecino,
                                     visitado,
                                     enRecursion))
                    return true;
            }
            else if (enRecursion[vecino]) {
                return true;
            }
        }

        enRecursion[nodo] = false;
        return false;
    }

public:

    void insertarDependencia(string origen, string destino) {
        grafo[origen].push_back(destino);

        // Garantiza que el nodo destino exista
        if (grafo.find(destino) == grafo.end()) {
            grafo[destino] = {};
        }

        cout << "\nDependencia agregada: "
             << origen << " -> " << destino << endl;
    }

    void mostrarGrafo() {

        if (grafo.empty()) {
            cout << "\nNo hay dependencias registradas.\n";
            return;
        }

        cout << "\n=== DEPENDENCIAS DEL SISTEMA ===\n";

        for (auto& par : grafo) {

            cout << par.first << " -> ";

            if (par.second.empty()) {
                cout << "(sin dependencias)";
            }
            else {
                for (string vecino : par.second) {
                    cout << vecino << " ";
                }
            }

            cout << endl;
        }
    }

    void mostrarOrdenCarga(string inicio) {

        if (grafo.find(inicio) == grafo.end()) {
            cout << "\nEl modulo no existe.\n";
            return;
        }

        unordered_map<string, bool> visitado;

        cout << "\nOrden de carga (DFS): ";
        DFS(inicio, visitado);
        cout << endl;
    }

    bool tieneCiclos() {

        unordered_map<string, bool> visitado;
        unordered_map<string, bool> enRecursion;

        for (auto& par : grafo) {

            string nodo = par.first;

            if (!visitado[nodo]) {

                if (detectarCicloDFS(
                        nodo,
                        visitado,
                        enRecursion)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    GrafoDependencias sistema;

    int opcion;
    string origen, destino, inicio;

    do {

        cout << "\n====================================";
        cout << "\n   SISTEMA DE DEPENDENCIAS";
        cout << "\n====================================";
        cout << "\n1. Insertar dependencia";
        cout << "\n2. Mostrar dependencias";
        cout << "\n3. Mostrar orden de carga (DFS)";
        cout << "\n4. Detectar ciclos";
        cout << "\n5. Salir";
        cout << "\n\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:

            cout << "\nModulo origen: ";
            cin >> origen;

            cout << "Modulo destino: ";
            cin >> destino;

            sistema.insertarDependencia(origen, destino);
            break;

        case 2:

            sistema.mostrarGrafo();
            break;

        case 3:

            cout << "\nIngrese modulo inicial: ";
            cin >> inicio;

            sistema.mostrarOrdenCarga(inicio);
            break;

        case 4:

            if (sistema.tieneCiclos())
                cout << "\nExiste un ciclo de dependencias.\n";
            else
                cout << "\nNo existen ciclos.\n";

            break;

        case 5:

            cout << "\nPrograma finalizado.\n";
            break;

        default:

            cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}