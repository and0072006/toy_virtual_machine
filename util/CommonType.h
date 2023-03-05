#pragma once

#include <string>
#include <vector>
#include <variant>
#include <optional>

enum class Command: uint8_t
{
    ADD = 0,
    SUB,
    MOV,
    MUL,
    DIV
};

enum class OperandType: uint8_t
{
    REG = 0,
    ADDRESS,
    CONSTANT
};

struct Operand
{
    OperandType type;
    std::variant<std::string> value;
};


struct Instruction
{
    Command command;
    std::optional<Operand> first_operand;
    std::optional<Operand> second_operand;
};

using Instructions = std::vector<Instruction>;





