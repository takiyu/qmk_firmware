#!/bin/bash

# 1) Setup
# poetry run qmk setup

# 2) Create key map
# poetry run qmk new-keymap -kb clueboard/66/rev3

# 3) Compile
poetry run qmk compile -kb handwired/takiyu -km default
