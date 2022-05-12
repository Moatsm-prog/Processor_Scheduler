#ifndef ProcInvalidException_h
#define ProcInvalidException_h

#include <exception>

class ProcessInvalidException : public std::exception {
private:
    const char* message;
public:
    ProcessInvalidException(const char* message);
    const char* what() const noexcept override;
};

#endif
