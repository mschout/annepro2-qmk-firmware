# NOTE: this Makefile assumes you have rev C15 of the AnnePro2.  If you have a
# different rev you might brick your keyboard.  Use at your own risk!
#
ANNEPRO_VERSION=15
TOOLS_RELEASE_DIR=AnnePro2-Tools/target/release

# where the sources will get copied to for the custom keymap
KEYMAP_SOURCE_DIR=qmk_firmware/keyboards/annepro2/keymaps/custom

.PHONY: all
all: build-tools build-shine build-firmware
	@echo
	@echo "Firmware files and tools have been built and are in $(TOOLS_RELEASE_DIR)"
	@echo
	@echo "To Flash, put board into IAP mode (hold ESC while plugging in) and run as root:"
	@echo
	@echo cd $(TOOLS_RELEASE_DIR)
	@echo ./annepro2_tools annepro2_c$(ANNEPRO_VERSION)_custom.bin
	@echo ./annepro2_tools --boot -t led annepro2-shine-C$(ANNEPRO_VERSION).bin

.PHONY: build-tools
build-tools:
	@cd AnnePro2-Tools && cargo clean && cargo build --release

.PHONY: build-shine
build-shine:
	@cd annepro2-shine && make clean C$(ANNEPRO_VERSION)
	@cp annepro2-shine/build/annepro2-shine-C$(ANNEPRO_VERSION).bin $(TOOLS_RELEASE_DIR)

.PHONY: build-firmware
build-firmware: install-keymap-sources
	@cd qmk_firmware && ALLOW_WARNINGS=yes make clean && make annepro2/c$(ANNEPRO_VERSION):custom
	@cp qmk_firmware/annepro2_c$(ANNEPRO_VERSION)_custom.bin $(TOOLS_RELEASE_DIR)
	@rm -rf $(KEYMAP_SOURCE_DIR)

.PHONY: install-keymap-sources
install-keymap-sources:
	@rm -rf $(KEYMAP_SOURCE_DIR)
	@mkdir -p $(KEYMAP_SOURCE_DIR)
	@cp keymap/* $(KEYMAP_SOURCE_DIR)
