# Advanced Algorithms and Data Structures Repository

This repository features a diverse collection of advanced algorithms and data structures, along with implementations for solving various computational problems. Each file demonstrates a specific approach or solution, providing insights into efficient algorithm design and usage.

## Contents

### Algorithms

1. **CPU Clock Simulation (`CPU_Clock.cpp`)**
   - Outputs the elapsed time of an algorithm.

2. **String Matching Algorithms**
   - **Rabin-Karp Algorithm (`RabinKarp.cpp`)**: Efficient string searching using hashing.
   - **Generic String Matching (`String Matching.cpp`)**: General implementation of string matching techniques using KMP.

3. **Primality Testing**
   - **Rabin-Miller Test (`RabinMiller.cpp`)**: A probabilistic algorithm to test if a number is prime.
   - **Fermat's Little Theorem (`FermaPrimeChecker.cpp`)**: Fastes way to check if a number is prime. Can be used even for N <= 10<sup>18
   - **Simple Sieve of Eratosthenes Algorithm (`Sieve.cpp`)**: An algorithm used to find all prime numbers up to a given limit.

4. **Subarray Divisibility (`Subarray_Divisibility.cpp`)**
   - CSES.fi problem that was implemented using red-black trees instead of a map.

5. **Hashing Techniques and fast exponentiation**
   - **Hash pairs for unordered_map (`HashPairs_ExponentialLOG.cpp`)**: Advanced hash function techniques for specific use cases.
   - **Fast exponentiation (`HashPairs_ExponentialLOG.cpp`)**: Fastes way to raise a number to a power.

### Data Structures

1. **Red-Black Tree Insertion (`RB_Insert.cpp`)**
   - Implements insertion in a Red-Black Tree, maintaining its balancing properties.

2. **Deque Parsing (`deque_Parse.cpp`)**
   - A parser that efficiently processes the input and adds it into a C++ STL Deque.

3. **Linked Lists (`liste.cpp`)**
   - A collection of linked list operations and utilities. See if you can find anything usefull :) .

### Specialized Implementations

1. **Coupling Algorithm (`Cuplaj.cpp`)**
   - Solves a coupling or pairing problem using graph theory principles.

2. **Matrix Filling (`Fill_mat_with_L.cpp`)**
   - Efficiently fills matrices based on specific rules or conditions.

3. **Custom Algorithms**
   - **Lee Algorithm (`lee.cpp`)**: Implements a breadth-first search algorithm for pathfinding.
   - **Normalization (`normalizare.cpp`)**: Applies data normalization techniques for specific datasets.

4. **Susan Problem (`susan.cpp`)**
   - 3 dimensional Lee's algorithm problem which can be found on pbinfo.ro.

## Usage

Each file is an independent implementation. The source code is written in C++ and can be compiled and executed as follows:

```bash
# Replace filename.cpp with the desired file
g++ -std=c++17 -o output filename.cpp
./output
```

## Contribution

Contributions are welcome! Feel free to submit pull requests with improvements, new algorithms, or additional documentation.

## License

This repository is open-sourced under the MIT License. Refer to the LICENSE file for more information.
