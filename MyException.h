#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

// Exception class for invalid room-related errors
class InvalidRoomException : public std::exception {
public:
    // Overriding the what() function to return a specific error message
    const char* what() const noexcept override {
        return "Invalid Room";
    }
};

// Exception class for invalid value-related errors
class InvalidValueException : public std::exception {
public:
    // Overriding the what() function to return a specific error message
    const char* what() const noexcept override {
        return "Invalid Value";
    }
};

// Exception class for memory-related errors
class MemoryException : public std::exception {
public:
    // Overriding the what() function to return a specific error message
    const char* what() const noexcept override {
        return "Memory Problem";
    }
};

#endif // EXCEPTIONS_H
