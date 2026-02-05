# so_long

_This project has been created as part of the 42 curriculum by g-alves-._

## Description

**so_long** is a small 2D game project developed using the **MiniLibX** graphical library.  
The objective is to create a simple top-down game where a player moves through a map, collects items, and reaches the exit using the minimum number of moves possible.

The project focuses on understanding **event-driven programming**, **basic game loops**, **memory management**, and **graphical rendering** using a low-level graphics API.

All maps are provided via a `.ber` file and must respect strict validation rules defined in the project specification.

## Game Rules

- The player must collect **all collectibles (`C`)** before exiting.
- The game ends successfully when the player reaches the exit (`E`) after collecting everything.
- The number of moves must be displayed in the terminal.
- The player can move using keyboard inputs (W/A/S/D or arrow keys).
- Pressing `ESC` or closing the window exits the game cleanly.

## Map Requirements

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

```bash
make
