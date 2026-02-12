# 🎮 Cub3D - Raycasting Game Engine

A 3D first-person game engine built from scratch in C using raycasting techniques, inspired by the legendary Wolfenstein 3D (1992).

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![42](https://img.shields.io/badge/42-Porto-black?style=flat)
![Raycasting](https://img.shields.io/badge/Raycasting-3D-red?style=flat)

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [How Raycasting Works](#how-raycasting-works)
- [What I Learned](#what-i-learned)

## 🎯 Overview

Cub3D is a project from the 42 School curriculum that introduces students to raycasting rendering techniques. The goal is to create a dynamic 3D graphical representation of a maze from a first-person perspective, similar to classic games like Wolfenstein 3D and early DOOM.

**Development Period:** February 2025 - April 2025  
**Graphics Library:** MiniLibX  
**Inspiration:** Wolfenstein 3D (id Software, 1992)

## ✨ Features

### Core Gameplay
- 🎮 First-person 3D navigation in real-time
- 🧱 Textured walls with different textures per direction (N/S/E/W)
- 🗺️ Interactive minimap with player position
- 🚶 Smooth player movement (WASD) and rotation (arrows)
- 🚫 Collision detection system
- 🎨 Floor and ceiling color customization

### Technical Features
- ⚡ Real-time raycasting rendering engine
- 🔒 **100% memory-safe** (zero leaks, validated with Valgrind)
- 🎯 Optimized rendering pipeline
- 📐 Accurate wall distance calculations (fisheye correction)
- 🖼️ Texture mapping with proper scaling

## 🚀 Installation
```bash
# Clone the repository
git clone https://github.com/leonardomaes/cub3d.git
cd cub3d

# Install dependencies (Linux)
sudo apt-get install libx11-dev libxext-dev libbsd-dev

# Compile
make

# Run with a map file
./cub3D maps/map.cub
```

### MacOS Installation
```bash
make
./cub3D maps/map.cub
```

## 💻 Usage
```bash
./cub3D <map_file.cub>

# Examples
./cub3D maps/basic.cub
./cub3D maps/maze.cub
./cub3D maps/complex.cub
```

### Map File Format (.cub)
```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**Config Parameters:**
- `NO/SO/WE/EA` - Texture paths for each wall direction
- `F` - Floor color (R,G,B)
- `C` - Ceiling color (R,G,B)
- `1` - Wall
- `0` - Empty space
- `N/S/E/W` - Player starting position and direction

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate camera left |
| `→` | Rotate camera right |
| `M` | Toggle minimap |
| `ESC` | Exit game |

## 🔍 How Raycasting Works

### The Core Concept

Raycasting creates a 3D perspective by casting rays from the player's position and calculating distances to walls:
```
Player Position (P)          Wall
      |                       |
      |  Ray →  →  →  →  →  | 
      |                       |
      
Distance = Used to calculate wall height on screen
```

### Step-by-Step Process

**1. For each vertical screen column:**
```c
for (int x = 0; x < screen_width; x++)
{
    // Calculate ray direction
    // Cast ray into the map
    // Find wall intersection
    // Calculate wall height
    // Draw vertical line
}
```

**2. DDA Algorithm (Digital Differential Analysis)**

Efficiently finds grid intersections:
```c
void    cast_ray(t_ray *ray)
{
    // Calculate step direction
    int step_x = ray->dir_x < 0 ? -1 : 1;
    int step_y = ray->dir_y < 0 ? -1 : 1;
    
    // Calculate distance to next grid line
    float delta_dist_x = fabs(1 / ray->dir_x);
    float delta_dist_y = fabs(1 / ray->dir_y);
    
    // Walk the grid until hitting a wall
    while (!hit_wall)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0; // Vertical wall
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1; // Horizontal wall
        }
        
        if (map[map_y][map_x] == '1')
            hit_wall = 1;
    }
}
```

**3. Wall Height Calculation**
```c
// Correct fisheye distortion
float perp_wall_dist = (side == 0) ? 
    (map_x - player_x + (1 - step_x) / 2) / ray->dir_x :
    (map_y - player_y + (1 - step_y) / 2) / ray->dir_y;

// Calculate wall height on screen
int wall_height = (int)(screen_height / perp_wall_dist);

// Calculate draw start/end positions
int draw_start = -wall_height / 2 + screen_height / 2;
int draw_end = wall_height / 2 + screen_height / 2;
```

**4. Texture Mapping**
```c
// Calculate exact wall hit position (0.0 to 1.0)
float wall_x = (side == 0) ? 
    player_y + perp_wall_dist * ray->dir_y :
    player_x + perp_wall_dist * ray->dir_x;
wall_x -= floor(wall_x);

// Get texture column
int tex_x = (int)(wall_x * texture_width);

// Draw vertical texture strip
for (int y = draw_start; y < draw_end; y++)
{
    int tex_y = ((y * 2 - screen_height + wall_height) * 
                 texture_height) / (wall_height * 2);
    
    int color = texture[tex_y][tex_x];
    put_pixel(x, y, color);
}
```

## 📚 What I Learned

### Technical Skills
- **Raycasting Algorithm:** Understanding the math behind pseudo-3D rendering
- **Graphics Programming:** Pixel manipulation, texture mapping, frame buffering
- **Game Development:** Game loop, input handling, real-time rendering
- **Optimization:** Profiling, lookup tables, efficient algorithms
- **Trigonometry:** Vector math, angle calculations, coordinate transformations

### Problem-Solving
1. **Fisheye Correction:** Fixed distortion by using perpendicular distance instead of Euclidean
2. **Texture Flickering:** Resolved by proper floating-point precision in texture coordinates
3. **Performance Issues:** Optimized from 30 FPS to 60+ FPS through algorithmic improvements

### Concepts
- How classic 3D games worked before GPU acceleration
- Trade-offs between realism and performance
- Event-driven programming patterns
- Map design and level layout considerations

## 🎯 Challenges Overcome

| Challenge | Solution |
|-----------|----------|
| Fisheye distortion | Use perpendicular wall distance instead of actual ray length |
| Texture stretching | Implement proper texture coordinate scaling based on wall height |
| Collision tunneling | Check multiple points around player instead of just center |
| Memory leaks | Strict cleanup protocol + Valgrind validation |
| Performance drops | Pre-calculations + integer math + image buffering |

## 🧪 Testing
```bash
# Memory leak check
valgrind --leak-check=full ./cub3D maps/test.cub

# Performance profiling
valgrind --tool=callgrind ./cub3D maps/large.cub
kcachegrind callgrind.out.<pid>
```

## 📖 Resources

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Excellent detailed explanation
- [Permadi's Raycasting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [Wolfenstein 3D Source Code](https://github.com/id-Software/wolf3d) - Original implementation
- [Game Engine Black Book: Wolfenstein 3D](https://fabiensanglard.net/gebbwolf3d/) - Deep dive into the original

## 🤝 Collaboration

This project was developed in collaboration with [Ricardo Mendes](https://github.com/rda-cunh) as part of the 42 Porto curriculum.

---

**42 Porto** | [Leonardo Maes](https://linkedin.com/in/leonardo-maes)
