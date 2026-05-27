#!/bin/bash

# Couleurs pour la lisibilité
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Chemin vers ton exécutable et le dossier de tests
EXEC=./cub3D
TEST_DIR=./maps/invalid

# Compteurs
total=0
pass=0
fail=0

echo "=== Test des cartes invalides ==="
echo "(toutes doivent échouer avec un code de retour != 0)"
echo ""

for file in "$TEST_DIR"/*.cub
do
    total=$((total + 1))
    name=$(basename "$file")
    
    # Lance le programme, capture sortie + code de retour
    output=$("$EXEC" "$file" 2>&1)
    code=$?
    
    # On veut que le programme échoue (code != 0)
    if [ $code -ne 0 ]; then
        echo -e "${GREEN}[OK]${NC} $name → exit $code"
        pass=$((pass + 1))
    else
        echo -e "${RED}[KO]${NC} $name → exit 0 (devrait échouer !)"
        fail=$((fail + 1))
    fi
done

echo ""
echo "=== Résultat : $pass/$total OK ==="