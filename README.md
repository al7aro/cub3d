# miniRT ⭕

## Map file

- name: `[map-name].rc`
- Available objects

	-	Ambient lighting `A`:
		- max: **1**
		- format: `A brightness color`
			- brightness: `[0.0-1.0]`
			- color: `[0-255], [0-255], [0-255]`
	- Camera `C`:
		- max: **1**
		- format: `C position look-at FOV`
			- position: `[x], [y], [z]`
			- look-at: `[x], [y], [z]` ➡ Normalized
			- FOV: `[0-180]`
	- Light `L`:
		- max: **1**
		- format: `L position brightness color`
			- position: `[x], [y], [z]`
			- brightness: `[0.0-1.0]`
			- color: `[0-255], [0-255], [0-255]`
	- Sphere `sp`:
		- max: **NO**
		- format: `sp position diameter color`
			- position: `[x], [y], [z]`
			- diameter: `[D]`
			- color: `[0-255], [0-255], [0-255]`
	- Plane `pl`:
		- max: **NO**
		- format: `pl position normal color`
			- position: `[x], [y], [z]`
			- normal: `[x], [y], [z]` ➡ Normalized
			- color: `[0-255], [0-255], [0-255]`
	- Cylinder `cy`:
		- max: **NO**
		- format: `cy position normal color`
			- position: `[x], [y], [z]`
			- normal: `[x], [y], [z]` ➡ Normalized
			- diameter: `[D]`
			- height: `[D]`
			- color: `[0-255], [0-255], [0-255]`
- map syntax error:
	- More arguments than required
	- Number out of range
	- Invalid keyword
	- comments start with `#`

✔ Example of correct map:

```
A 0.2 255,255,255
C -50,0,20 0,0,0 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
#Cylinder	<- comment
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```

❌ Example of incorrect map:

```
As 0.2 255,255,255	<- invalid keyword
C -50,0,20 0,0,0 70 |
C -50,0,20 0,0,0 70 |	<- more than one camera
L -40,0,30 0.7 255,255,255
tr 0,0,20 20 256,0,0	<- invalid keyword
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 256,0,0	<- number out of range
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```
TODO:

- TESTING

---
