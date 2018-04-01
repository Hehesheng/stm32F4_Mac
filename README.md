A customized development kit for stm32f4

### Usage
 - Step.1

 Add submodule in your project folder
 ```shell
 $ git submodule add  https://github.com/avem-labs/stm32F4_Mac.git
 $ touch makefile
 ```

 - Step.2

 Copy makefile contents from `make.config`
 ```makefile
  include stm32F4_Mac/make.config
  .PHONY: proj

  all: proj

  proj: $(PROJ_NAME).elf

  $(PROJ_NAME).elf: $(SRCS)
  	$(CC) $(CFLAGS) $^ -o $@
  	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
  	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

  clean:
  	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin

  # Flash the STM32F4
  dfu: proj
  	dfu-util -d 0483:df11 -c 1 -a 0 -s 0x08000000:leave -D $(PROJ_NAME).bin
 ```

