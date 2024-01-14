# DSTools - C++ Library for Data Structure and Algorithm

## About:

DSTools is a simple C++ library designed for educational purposes, providing a hands-on approach to understanding data structures and algorithms. The motivation behind this project stems from the complexity of the standard library, making it less accessible for learning purposes. While DSTools is not recommended for production use due to its incomplete nature, it serves as a tool for reinventing the wheel and gaining a deeper understanding of fundamental concepts. Contributions are highly encouraged, as we aim to collaboratively enhance and expand the library.

## Quick Start:

### i) Clone the Repository:
To get started, clone the DSTools repository to your local machine by clicking [here](https://github.com/syaheer-altaf/dstools-cpp) or using the following command:
```bash
git clone https://github.com/syaheer-altaf/dstools-cpp.git
```

### ii) Install Makefile:
Ensure that you have the necessary tools to build the library by installing the Makefile. This step is crucial for compiling the code seamlessly.

### iii) Build the Library:
Navigate to the [bin](./bin/) directory within the cloned repository and run the appropriate make command based on your operating system:
```bash
make lib_windows
# or
make lib_linux
# or
make lib_macos
```

### iv) Include the Shared Library:
After successfully building the library, make sure to include the generated shared library in your working directory or set it in your environment to facilitate seamless integration.

### v) Compile Examples:
Explore the library's capabilities by compiling the included Tic-Tac-Toe game in the [examples](./examples/) folder. Run the following command in the terminal:
```bash
make game
```

## License:

This repository is published under the MIT license. See the included [LICENSE](./LICENSE) file for more details. Feel free to fork, modify, and contribute to this project.