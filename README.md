# cub3d 🧊

## Map file

- name: `[map-name].cub`
- Available objects

	-	North Texture `NO`:
		- path: `./path/to/north_texture.cub`
	-	South Texture `SO`:
		- path: `./path/to/south_texture.cub`
	-	West Texture `WE`:
		- path: `./path/to/west_texture.cub`
	-	East Texture `EA`:
		- path: `./path/to/east_texture.cub`
	- Floor Color: `[0-255], [0-255], [0-255]`
	- Cielling Color: `[0-255], [0-255], [0-255]`
- map syntax error:
	- More arguments than required
	- Number out of range
	- Invalid keyword
	- comments start with `#`

✔ Example of correct map:

```
NO ./assets/textures/north_texture.xmp	# Texture of north-facing walls
SO ./assets/textures/south_texture.xmp	# Texture of south-facing walls
WE ./assets/textures/west_texture.xmp	# Texture of west-facing walls
EA ./assets/textures/east_texture.xmp	# Texture of east-facing walls

F 50,100,10		# Floor color
C 100,100,100	# Ceilling color

# Closed Map (Without #)

11111111111111111111111111111111
1N000000000000000000000000000001
10000000000011111111111000000001
10000000011111111111111111000001
10000000011100000001111111100001
10000000111000111111111111110001
10000000111001111100000000111101
10011111110001111110000011111101
10111111110001111111111111111101
10111001110000111111111111111101
10111001110000011111111111111001
10111001110000000000000000111001
10110001110000000000000000111001
10110001110000000000000000111001
10111001110000000000000000111001
10111101110000000000000000111001
10011111110000011101111101110001
10000000110000011101111001110001
10000000110000011101111001110001
10000000111111111101111111100001
10000000111111111000000000000001
10000000000000000000000000000001
11111111111111111111111111111111

```

❌ Example of incorrect map:

```
NO ./assets/textures/north_texture.xmp	# Texture of north-facing walls
SO ./assets/textures/south_texture.xmp	# Texture of south-facing walls
WE ./assets/textures/west_texture.xmp	# Texture of west-facing walls
E ./assets/textures/east_texture.xmp	# Texture of east-facing walls

F 50,100,300	# Floor color
C 100,100,100	# Ceilling color

# Closed Map (Without #)

11111111111111111111111111111111
1N000000000000000000000000000001
10000000000011111111111000000001
10000000011111111111111111000001
10000000011100000001111111100001
10000000111000111111111111110001
10000000111001111100000000111101
10011111110001111110000011111101
10111111110001111111111111111101
10111001110000111111111111111101
10111001110000011111111111111001
10111001110000000000000000111001
10110001110000000000000000111001
10110001110000000000000000111001
10111001110000000N00000000111001
10111101110000000000000000111001
10011111110000011101111101110001
10000000110000011101111001110001
10000000110000011101111001110001
10000000111111111101111111100001
10000000111111111000000000000001
10000000000000000000000000000001
11111111111111111111111111111111

```
# TODO

- Store player init rotation
  - Handle player rotation with keys
- Store player position
  - Handle player position with keys
- Raycast
- Sprite draw on wall functions

## Simple Bonus
- Sprite animation
- Minimap
