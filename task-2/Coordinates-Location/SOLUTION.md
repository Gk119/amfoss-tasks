1. Used `mkdir Coordinates-Location` to make the Coordinates-Location directory and used `cd Coordinates-Location` to go into the directory.
2. Used `mkdir North` to make the North directory and used `cd North` to go into the directory.
	1. Used `touch NDegree.txt` to create NDegree.txt file and used `gedit NDegree.txt` to open NDegree.txt file in gedit editor to add the values to the it.
	2. Used `touch NMinutes.txt` to create NMinutes.txt file and used `gedit NMinutes.txt` to open NMinutes.txt file in gedit editor to add the values to the it.
	3.Used `touch NSeconds.txt` to create NSeconds.txt file and used `gedit NSeconds.txt` to open NSeconds.txt file in gedit editor to add the values to the it.
	4. Used `cat NDegree.txt NMinutes.txt NSeconds.txt > NorthCoordinate.txt` to make the file NorthCoordinate.txt from the combination of the above files and opened it with `gedit NorthCoordinate.txt` to manually remove the newline characters from it.
	5.
		1. Used `cp NorthCoordinate.txt ../NorthCoordinate.txt` to copy it to one directory above i.e Coordinate-Location directory.
		2. Used `rm NorthCoordinate.txt` to delete the NorthCoordinate.txt file from North directory.
		3. Navigated one directory up with `cd ..` and renamed NorthCoordinate.txt using `mv NorthCoordinate.txt North.txt`.
3. Used `mkdir East` to make the East directory and used `cd East` to go into the directory.
	1. Used `touch EDegree.txt` to create EDegree.txt file and used `gedit EDegree.txt` to open EDegree.txt file in gedit editor to add the values to the it.
	2. Used `touch EMinutes.txt` to create EMinutes.txt file and used `gedit EMinutes.txt` to open EMinutes.txt file in gedit editor to add the values to the it.
	3.Used `touch ESeconds.txt` to create ESeconds.txt file and used `gedit ESeconds.txt` to open ESeconds.txt file in gedit editor to add the values to the it.
	4. Used `cat EDegree.txt EMinutes.txt ESeconds.txt > EastCoordinate.txt` to make the file EastCoordinate.txt from the combination of the above files and opened it with `gedit EastCoordinate.txt` to manually remove the newline characters from it.
	5.
		1. Used `cp EastCoordinate.txt ../EastCoordinate.txt` to copy it to one directory above i.e Coordinate-Location directory.
		2. Used `rm EastCoordinate.txt` to delete the EastCoordinate.txt file from East directory.
		3. Navigated one directory up with `cd ..` and renamed EastCoordinate.txt using `mv EastCoordinate.txt East.txt`.
4. Used `cat North.txt East.txt > Location-Coordinate.txt` to create Location-Coordinate.txt file in Coordinates-Location directory.
5. 
!["Location Image"](Location.png?raw=true "Location Image")
6. 	1. Used `git clone https://github.com/Gk119/amfoss-tasks.git` to clone the GitHub repository to my laptop
	2. Created folder task-2 in the repository and copied the directory Coordinates-Location to it.
	3. Used `git add --all` and commited the changes using `git commit -m "Added task-2 files"`
	4. The repository was pushed back to GitHub using `git push origin main`.

