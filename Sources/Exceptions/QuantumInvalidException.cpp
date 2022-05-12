#include "QuantumInvalidException.h"

QuantumInvalidException::QuantumInvalidException(const char* message) {
    this->message = message;
}

const char* QuantumInvalidException::what() const noexcept{
    return message;
}
