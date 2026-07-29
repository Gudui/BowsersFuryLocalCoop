# Bowser's Fury Co-op public release build configuration.
LOAD_KIND := Module
PROGRAM_ID := 010028600EBDA000
ELF_EXTRACT :=
PYTHON := python3
NPDM_JSON := qlaunch.json
C_FLAGS := -g0 -ffile-prefix-map=$(PWD)=/workspace/exlaunch -fdebug-prefix-map=$(PWD)=/workspace/exlaunch -fmacro-prefix-map=$(PWD)=/workspace/exlaunch
CXX_FLAGS :=
