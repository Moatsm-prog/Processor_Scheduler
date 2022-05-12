#ifndef QuanInvalidException_h
#define QuanInvalidException_h

#include <exception>

class QuantumInvalidException : public std::exception {
private:
    const char* message;
public:
    QuantumInvalidException(const char* message);
    const char* what() const noexcept override;
};

#endif
