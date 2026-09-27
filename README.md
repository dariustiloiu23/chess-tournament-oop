# Chess Tournament Management System
This is a C++ project developed across three iterative phases to manage chess players, matches, and tournaments. The project tracks the evolution from basic OOP and manual dynamic memory to class hierarchies, design patterns, and modern STL components.

## Project Phases

### Phase 1: Core OOP & Manual Memory
- Built base domain entities: `Jucator`, `Arbitru`, `Partida`, and `Turneu`.
- Handled dynamic memory manually using `char*` buffers and dynamic arrays, following the Rule of Three (destructor, copy constructor, copy assignment operator).
- Overloaded essential operators (`<<`, `>>`, arithmetic `+`/`-`, increment `++`, relational `==`/`>`, and index `[]`).
- Interactive terminal menu with CRUD operations.

### Phase 2: Inheritance & Polymorphism
- Split code into modular headers (`.h`) and implementation files (`.cpp`).
- Created an abstract base class `Persoana` with pure virtual methods (`afiseazaTip()`, `printeaza()`, `citeste()`) and a virtual destructor.
- Multi-level inheritance: `Persoana` -> `Jucator` -> `JucatorPro`, alongside `Arbitru`.
- Object composition: `Turneu` embeds a custom `Data` object.
- Managed collections via an array of base pointers (`Persoana*`) and runtime type checking via `dynamic_cast`.

### Phase 3: Design Patterns, Templates & STL
- **Design Patterns:**
  - **Singleton (Meyers):** Centralized `Logger` instance for tracking system events.
  - **Abstract Factory:** `FabricaStandard` and `FabricaVIP` creating different reward tiers (`IPremiu`, `IDiploma`) within the `Festivitate` client.
- **Generic Programming:**
  - Class template `Depozitar<T, MAX_CAPACITY>` with non-type parameters and automatic resource cleanup.
  - Standalone template functions (`printeazaFiltrat`, `logheazaMesajGeneric`) with explicit string specialization.
- **Exception Safety:** Custom hierarchy (`SahException` -> `ValidareException`, `NotFoundException`) extending `std::runtime_error`.
- **Modern C++:** Migrated raw pointers and `char*` to `std::string`, `std::vector`, and `std::map`, leveraging algorithms (`std::sort`, `std::find_if`, `std::count_if`) with lambdas.

## How to Run
### Option 1: Using CLion 
1. Open CLion and select Open on any of the phase folders (`phase-1`, `phase-2`, or `phase-3`).
2. CLion will automatically load the project via `CMakeLists.txt`.
3. Click the Run button.

### Option 2: Using Terminal / GCC (C++20)

**Phase 1:**
cd phase-1
g++ -std=c++20 main.cpp -o app
./app

**Phase 2:**
cd phase-2
g++ -std=c++20 *.cpp -o app
./app

**Phase 3:**
cd phase-3
g++ -std=c++20 *.cpp -o app
./app


cd phase-1
g++ -std=c++20 main.cpp -o app
./app
