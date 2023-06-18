#!/bin/bash

# 1) Setup
# qmk setup

# 2) Create key map
# qmk new-keymap -kb clueboard/66/rev3

# 3) Compile
qmk compile -kb handwired/takiyu -km default
