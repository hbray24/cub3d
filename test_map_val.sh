#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

EXEC=./Cub3D
TEST_DIR=./maps/invalid
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=42 --quiet"

total=0
pass=0
fail=0
leak=0

echo "=== Test des cartes invalides avec valgrind ==="
echo ""

for file in "$TEST_DIR"/*.cub
do
    total=$((total + 1))
    name=$(basename "$file")
    
    output=$($VALGRIND "$EXEC" "$file" 2>&1)
    code=$?
    
    if [ $code -eq 42 ]; then
        echo -e "${YELLOW}[LEAK]${NC} $name"
		echo "$output"
        leak=$((leak + 1))
    elif [ $code -ne 0 ]; then
        echo -e "${GREEN}[OK]${NC} $name → exit $code"
        pass=$((pass + 1))
    else
        echo -e "${RED}[KO]${NC} $name → exit 0 (devrait échouer)"
        fail=$((fail + 1))
    fi
done

echo ""
echo "=== Résultat : $pass OK / $fail KO / $leak avec leaks (sur $total) ==="