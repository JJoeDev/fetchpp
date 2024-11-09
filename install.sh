#!/bin/sh

# Colors
RED="\033[1;31m"
YELLOW="\033[1;33m"
GREEN="\033[1;32m"
DEFAULT="\033[0m"

DIR=/usr/local/bin/

echo "$RED This install script requires root to uninstall old versions at /usr/local/bin/fetchpp $DEFAULT"

sudo rm -fv /usr/local/bin/fetchpp

echo ""

echo "$YELLOW ===== Getting compiler ready ===== $DEFAULT"
echo
cmake .

echo "$YELLOW ===== Compiling fetchpp ===== $DEFAULT"
echo
ninja

echo "$YELLOW ===== Moving fetchpp executable to $DIR ===== $DEFAULT"
echo
sudo mv bin/fetchpp $DIR

echo "$GREEN ===== fetchpp has moved to $DIR ===== $DEFAULT"
