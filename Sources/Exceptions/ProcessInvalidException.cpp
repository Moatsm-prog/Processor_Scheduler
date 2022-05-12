#include "ProcessInvalidException.h"

ProcessInvalidException::ProcessInvalidException(const char* message) {
    this->message = message;
}

const char* ProcessInvalidException::what() const noexcept{
    return message;
}
