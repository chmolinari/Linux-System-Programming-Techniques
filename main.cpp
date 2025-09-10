#include <iostream>
#include <vector>

int main(int argc, char **argv) {
#if DEBUG
    std::cout << "*** Program Started ***\n";
#endif

    if (argc < 3) {
        std::cout << "I need at least two numbers to perform a sum!\n";
        return EXIT_FAILURE;
    }

    std::vector<int> inputs;
    int input_numbers = argc - 1;
    inputs.resize(input_numbers);
    for (int i = 0; i < input_numbers; i++) {
        try {
            inputs[i] = std::stoi(argv[i + 1]);
        } catch (std::invalid_argument &e) {
            std::cout << "Failed parsing argument " << argv[i + 1] << ". All arguments must be integer numbers!\n";
            return EXIT_FAILURE;
        } catch (std::out_of_range &e) {
            std::cout << "Argument " << argv[i + 1] << " is too big to be processed!\n";
            return EXIT_FAILURE;
        }
    }

    int result = 0;
    std::cout << "The sum of numbers ";
    for (int i = 0; i < input_numbers; i++) {
        result += inputs[i];
        std::cout << inputs[i] << (i < input_numbers - 1 ? ", " : " ");
    }
    std::cout << "is: " << result << ".\n";

#if DEBUG
    std::cout << "*** End of Program ***\n";
#endif

    return EXIT_SUCCESS;
}
