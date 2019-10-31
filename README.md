# Wild and Smokey: Wildfire extinguishing game

**COEN 4830 - Intro to Computer Graphics**

**Fall 2019**

Wild and Smokey is a turn-based wildfire fighting game. Players are given various wildfire
fighting personnel and equipment which will aid them in the battle against the fire. Each turn the player
will have the option to move, deploy, or evacuate these assets as the fire rages on.

## Deliverables
Task | Deadline	| Done
---- | ---- | ----
Project proposal | `09/20` | :white_check_mark:
Project specifications | `10/11` | :white_check_mark:
Project report 1 | `11/01` | :x:
Project report 2 | `11/22` | :x:
Project presentations | `12/06` | :x:

## TODO
- [x] Create readme
- [ ] Create todo section
- [ ] Make level class (Russell)
- [ ] Make tile class (Paula)
- [ ] Make code to render a level (John)
  - [ ] 2D
  - [ ] 3D
- [ ] Level schema
- [ ] Code to read in level files

## Example file structure of the solution/repository
All projects can be contained in the same solution in order to easily switch between them.
All projects must be contained in a subfolder to stay organized.

    wildfire                  # repo folder
    ├── main                  # subfolder/category
    │   ├── Smokey            # project folder
    │   │   ├── Source.cpp    # project files
    │   ├── Wildfire
    │   │   ├── Source.cpp
    ├── demo
    │   ├── FireDemo1
    │   │   ├── Source.cpp
    │   ├── FireDemo2
    │   │   ├── Source.cpp
    │   └── TileDemo1
    │   │   ├── Source.cpp
    ├── test
    │   ├── FireTest1
    │   │   ├── Source.cpp
    │   ├── UnitTest1
    │   │   ├── Source.cpp
    └── ...

## Creating the solution for the first time
1. Clone this repository. The repository root folder will also be the Visual Studio solution root folder.
    1. `git clone https://github.com/hattas/wildfire`
1. Select File > Create new project from existing code.
1. Set the project file location to the location of the clone repository.
1. Set the project name to the main solution name, whatever you want (WildfireSolution).
1. Uncheck add files to the project...
1. Click finish.
1. Add existing projects as described [below](#Creating-a-new-project-from-existing-files-in-the-repository).

## Creating a new project from scratch
1. Create a new empty project (Ctrl+Shift+N).
1. Select "Add to solution".
1. Add the appropriate subfolder to the end of the Location, e.g. `\demo`.

## Creating a new project from existing files in the repository
This method sucks but it's the only way.
1. Change the name of the folder with the project you want to add.
1. Create a new project from scratch with the old folder name as the project name.
1. Copy the source files from the renamed folder into the new project.
1. Delete the renamed folder.

## Built With

* [C++](http://www.cplusplus.com/)
* [OpenGL](https://www.opengl.org/) - Graphics Library
* [freeglut](http://freeglut.sourceforge.net/) - Window management

## Authors

* **John Hattas** - [hattas](https://github.com/hattas)
* **Russell Reding** - [RussReding](https://github.com/RussReding)
* **Paula Van Camp** - [Paulavancamp](https://github.com/Paulavancamp)
