#-------------------------------------------------- 
# TARGET
#-------------------------------------------------- 

TARGET = stm32f1_minimal
BUILD_DIR = build/

DEBUG = -ggdb
OPT = -Og
DEBUG_PROBE = openocd
DEBUG_PROBE_TARGET = src/target_openocd.cfg
LDSCRIPT = src\linker_script.ld

C_SOURCES = \
external/CMSIS/Device/STM32F1/Source/Templates/system_stm32f1xx.c \
src/drv/drv_rcc.c \
src/drv/drv_gpio.c \
src/drv/drv_flash.c \
src/startup.c \
src/main.c 

C_INCLUDES = \
-Isrc/drv \
-Iexternal/CMSIS/CMSIS/Core/Include \
-Iexternal/CMSIS/Device/STM32F1/Include 
#-------------------------------------------------- 
# CFLAGS
#-------------------------------------------------- 
CFLAGS = $(C_INCLUDES)
CFLAGS += -Wall $(OPT) $(DEBUG)
CFLAGS += -mcpu=cortex-m3 -mthumb
#CFLAGS += -nostdlib
CFLAGS += --specs=nano.specs
CFLAGS += -DSTM32F103xB

#-------------------------------------------------- 
# LDFLAGS
#-------------------------------------------------- 
LDFLAGS = -T$(LDSCRIPT)

#--------------------------------------------------
# Build Tools
#--------------------------------------------------
PREFIX = arm-none-eabi-
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S


#--------------------------------------------------
# Rules
#--------------------------------------------------


all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

.PHONY: clean
clean:
	-rm -fR $(BUILD_DIR)

.PHONY: flash
flash:
	$(DEBUG_PROBE) -f $(DEBUG_PROBE_TARGET) -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"
debug:
	$(DEBUG_PROBE) -f $(DEBUG_PROBE_TARGET) 

gdb:
	gdb-multiarch $(BUILD_DIR)/$(TARGET).elf -ex "target extended-remote localhost:3333" 
# *** EOF ***