for map in maps/invalid/*.ber; do
    echo "Testing $map"
    valgrind --leak-check=full --track-origins=yes ./so_long "$map"
done

for map in maps/valid/*.ber; do
    echo "Testing $map"
    valgrind --leak-check=full --track-origins=yes ./so_long "$map"
done