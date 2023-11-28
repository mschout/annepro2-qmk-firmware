# QMK Firmware And Keymap for the AnnePro2

This repository is just my AnnePro2 keymap, plus the necessary upstream tools and QMK firmware with a makefile to tie everything together.

## Building the Firmware

Init / Update Submodules:

```
git submodule init
git submodule update --recursive
```

Build everything

```
make
```

You need to have all of the required dependencies installed.  See upstream projects for more info.  It will error out if something is missing.

The makefile will print the flashing instructions at the end of the process.

## DISCLAIMER

This assumes you have Revsion C15 of the AnnePro2.  If you do not have this revision, or are unsure which version you have, DO NOT USE THIS!
