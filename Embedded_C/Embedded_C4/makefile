#@copyRights : ENG Ahmed ELgazzar.

#tool chain#
CC = arm-none-eabi-

#microprocessor#
CFLAGS = -mcpu=cortex-m4 -mthumb -gdwarf-2

#includes#
INCS = -I .

#liberaries#
LIBS =

#any .c files get its .o#
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

#any .s files get its .o#
AS_SRC = $(wildcard *.s)
AS_OBJ = $(AS_SRC:.s=.o)

#project name#
project_name = learn-in-depth-cortex-m4

##################
#$< : dependense # 
#$@ : target     #
##################

all: $(project_name).bin
	@echo "*******build is done***************"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(project_name).elf: $(OBJ) $(AS_OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AS_OBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf
	
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
#***to test MakeFile***#
clean_all:
	rm *.o *.elf *.bin
	
#***to test linker_script***#
clean:
	rm *.elf *.bin
	
	
	