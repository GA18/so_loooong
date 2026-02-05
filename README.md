# so_long

_This project has been created as part of the 42 curriculum by g-alves-._

## Description

**so_long** is a small 2D game project developed using the **MiniLibX** graphical library.  
The objective is to create a simple top-down game where a player moves through a map, collects items, and reaches the exit using the minimum number of moves possible.

The project focuses on understanding **event-driven programming**, **basic game loops**, **memory management**, and **graphical rendering** using a low-level graphics API.

All maps are provided via a `.ber` file and must respect strict validation rules defined in the project specification.

### Game Rules

- The player must collect **all collectibles (`C`)** before exiting.
- The game ends successfully when the player reaches the exit (`E`) after collecting everything.
- The number of moves must be displayed in the terminal.
- The player can move using keyboard inputs (W/A/S/D or arrow keys).
- Pressing `ESC` or closing the window exits the game cleanly.

### Map Requirements

The map is provided as a `.ber` file and must follow these rules:

- Must be **rectangular**
- Must be **surrounded by walls (`1`)**
- Must contain **exactly one player (`P`)**
- Must contain **at least one collectible (`C`)**
- Must contain **at least one exit (`E`)**
- Must contain only valid characters:
  - `0` : Empty space
  - `1` : Wall
  - `P` : Player
  - `C` : Collectible
  - `E` : Exit

Any invalid map must result in an error message and program termination.

## Instructions

### Compilation

To compile the project, run:

```
make
```
This will generate the executable so_long.

Execution
Run the game by passing a valid map file with the .ber extension:

```
./so_long maps/example.ber
```

### Customized Testing

You can use an automated test that I created myself during development:

Download the tester.sh file from my GitHub.

https://github.com/GA18/so_loooong/blob/master/tester.sh

 ⚠️ **Make sure to save it in the root of the so_looong folder** (do not put it in any other folder). It is available at the link below...

After that, simply run the project as follows:

```
./tester.sh
```

This script will run all the maps located in the maps/valid and maps/invalid folders one by one, starting with the invalid maps.

- When it reaches the valid maps, they will be opened one at a time so you can play and verify they are correct.

- Once you reach the exit, the next valid map will open automatically until all maps have been tested.

- If you do not wish to play a specific map, you can simply press ESC to close the game, but the tester will proceed to the next available map.

 ### WARNING ⚠️ ⚠️

Make sure the file has the necessary permissions to run

```
chmod +rx tester.sh
```
## Resources

Website for converting images to XPM:
- https://convertio.co/

AI was used to assist in the technical explanation of concepts such as flood_fill and, primarily, to accelerate learning regarding MiniLibX functions and generating maps valid and invalid for test.

- https://chatgpt.com
- https://gemini.google.com
