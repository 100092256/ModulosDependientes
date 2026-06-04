# Módulos Dependientes - Grafos Dirigidos en C++

## Descripción

Este proyecto implementa un sistema de gestión de módulos dependientes utilizando la estructura de datos **Grafo Dirigido** y el paradigma de **Programación Orientada a Objetos (OOP)** en C++.

Cada módulo del sistema se representa como un vértice y cada dependencia como una arista dirigida:

A → B

Lo que significa que el módulo **A depende del módulo B**.

El programa permite:

- Insertar dependencias entre módulos.
- Visualizar las dependencias registradas.
- Mostrar el orden de carga de los módulos mediante el algoritmo DFS (Depth First Search).
- Detectar ciclos de dependencia dentro del sistema.

---

## Objetivos

- Aplicar la estructura de datos Grafo.
- Implementar recorridos DFS.
- Detectar ciclos en grafos dirigidos.
- Analizar la complejidad algorítmica de las operaciones.
- Utilizar Programación Orientada a Objetos en C++.

---

## Funcionalidades

### 1. Insertar dependencia

Permite registrar una relación entre dos módulos.

Ejemplo:

A → B

Indica que A depende de B.

---

### 2. Mostrar dependencias

Visualiza todas las dependencias almacenadas en el sistema.

Ejemplo:

A -> B
B -> C
C -> D

---

### 3. Mostrar orden de carga (DFS)

Realiza un recorrido en profundidad (Depth First Search) a partir de un módulo seleccionado.

Ejemplo:

A → B → C → D

Salida:

A B C D

---

### 4. Detectar ciclos

Verifica si existen dependencias circulares.

Ejemplo:

A → B
B → C
C → A

Resultado:

Existe un ciclo de dependencias.

---

## Estructura del Proyecto
