#pragma once

#define Write_register_field(reg, field, value) {\
    reg &= ~(field); \
    reg |= (value << field##_Pos); \
}
#define Read_register_field(reg, field) (reg & field) >> field##_Pos;
#define Set_register_bit(reg, bit) reg |= bit;
#define Clear_register_bit(reg, bit) reg &= ~bit;