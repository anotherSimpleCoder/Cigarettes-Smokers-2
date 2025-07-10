#include "CS_Context.hh"

CS_Context newCSContext() {
    std::array<std::binary_semaphore, 3> smokers = {
        std::binary_semaphore{0},
        std::binary_semaphore{0},
        std::binary_semaphore{0}
    };

    std::binary_semaphore table{0};
    unsigned int chosenSmoker = -1;

    return {
        &table,
        &smokers,
        chosenSmoker
    };
}