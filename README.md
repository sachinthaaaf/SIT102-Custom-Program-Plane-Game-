# Sky Game

Sky Game is a simple and engaging game where the player controls a plane to collect coins and avoid obstacles. The game is developed in C++ and demonstrates the use of various programming concepts such as data types, functions, procedures, vectors, and control structures.

## Table of Contents

- [Game Description](#game-description)
- [Features](#features)
- [File Structure](#file-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Game Description

In Sky Game, the player controls a plane using the keyboard's arrow keys:
- **Right Arrow Key**: Move the plane to the right
- **Left Arrow Key**: Move the plane to the left
- **Up Arrow Key**: Move the plane upwards
- **Down Arrow Key**: Move the plane downwards

The objective is to collect coins to increase the player's score while avoiding boxes that move across the screen. Colliding with a box resets the player's score.

## Features

- **Plane Movement**: Control the plane using the keyboard.
- **Coin Collection**: Collect coins to increase your score.
- **Obstacles**: Avoid moving boxes to prevent score reset.
- **Animations**: Smooth animations for plane, coins, and boxes.
- **Score Tracking**: Real-time score updates as coins are collected.

## File Structure

- **sky_play.h**: Header file containing enumerations, structures, function, and procedure declarations.
  - Enumerations: `plane_kind`, `box_kind`
  - Structures: `plane_data`, `coin_data`, `box_data`, `sky_game_data`
- **coin.cpp**: Handles coin-related operations and animations.
- **box.cpp**: Manages box-related functions and their movements.
- **plane.cpp**: Contains functions for plane control and input handling.
- **sky_game.cpp**: Implements the core game functions, including game updates and drawing.
- **program.cpp**: The main file that loads resources and runs the game.

## Installation

1. **Clone the repository**:
   ```sh
   git clone https://github.com/yourusername/sky-game.git
   ```

2. **Navigate to the project directory**:
   ```sh
   cd sky-game
   ```

3. **Install SplashKit**:
   Follow the installation instructions for SplashKit from the [official website](https://splashkit.io/).

4. **Compile the code**:
   ```sh
   g++ -o sky_game program.cpp sky_game.cpp plane.cpp box.cpp coin.cpp -lsplashkit
   ```

5. **Run the game**:
   ```sh
   ./sky_game
   ```

## Usage

- Use the arrow keys to control the plane's movements.
- Collect coins to increase your score.
- Avoid colliding with the boxes to keep your score intact.

## Created By
Sachintha Fernando 
