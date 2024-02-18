echo "Started compilation"
echo "Please wait..."

# we don't want to compile the source files from the demos/ folder
g++ src/*.cpp     `
	src/glad.c    `
	-o bin/prog   `
	-I include    `
	-L lib        `
	-lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image

if($? -eq $True)
{
	echo "Compilation successful!"
	cd bin/
	echo "[INFO] Moved to bin/ folder"
}