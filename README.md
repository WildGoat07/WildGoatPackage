![img](https://github.com/WildGoat07/WildGoatPackage-Release/blob/master/logo%20x256.png)

# WildGoatPackage

A little project i'm working on. Provides some helpful user friendly classes.<br/>**Requires [SFML](https://www.sfml-dev.org/index.php) for the graphic classes**.<br/>**Works only on Windows at the moment**.

## Features

* `wp::AdvancedClock` : An extended version of `wp::Chrono` where a time factor is added.
* `wp::Animator` : An easy way to make simple animations (transformations only).
* `wp::Archive` : A class to create easily archives of multiple files.
* `wp::Bezier` : A class that can create and handle basic Bezier's curve (with *n* points).
* `wp::Browser` : A class to browse and find (a) file(s) using the Windows native window (**Windows only**).
* `wp::Chrono` : A `sf::Clock` which can be paused or set its actual time.
* `wp::Color` : A fast way to convert HSLA / CMYKA / RBGA colors.
* `wp::Cursor` : An easy interface to change the mouse cursor (**Windows only**).
* `wp::Data` : A class that can store referenced values (`int`, `double`, or `std::string`) and save/load them. **DEPRECATED**.
* `wp::Extractor` : A class used to extract archives done by `wp::Archive`.
* `wp::File` : A class to extract basic informations from a file path (name, extension, path, or absolute path for relative ones).
* `wp::FileManager` : A fast and easy way to explore files using C++.
* `wp::FolderBrowser` : Same as `wp::Browser` but for folders (**Windows only**).
* `wp::Function` : A basic interface to create (whatever you like) functions. Some basic functions are already added. *Not very useful at the moment, future features will maybe use this*.
* `wp::gui` : A module to create an user interface in SFML. Based on [SFGUI](https://github.com/TankOs/SFGUI).
* `wp::ImgSequence` : A class to load a sequence of image and animate it as a texture buffer.
* `wp::JSON` : A module to parse a JSON formatted string or generate one and do whatever you want with it.
* `wp::KeySet` : A class that handle key commands and compare them. Useful to create shortcuts like Ctrl + Z.
* `wp::light` : A module to create lights in SFML and generate shadows based on walls.
* `wp::Matrix` : Just a class to handle 2 dimensionnal matrix with basic operators(+, -, \*) and some functions to get the inverse, minor, adjugate, ...
* `wp::pf` : short for *path finding*, a module with a path finding algorithm based on nodes or a tilemap. The algorithm used is the A\* for optimal results and a high heuristic to always give the shortest path possible. 
* `wp::RichText` : A class that can display text (like `sf::Text`) but with different colors/style in only one object (which can't be made using only one `sf::Text`). Supports JSON.
* `wp::snd` : a namespace where you can manage mutiple sounds and musics using channels.
* `wp::StandardInputStream` : A class to link a standard `std::iostream` to a `sf::InputStream`. 
* `wp::Variable` : A dynamic variable that can have either a constant value (still variable though) or a reference to another one inside a list of parameters. *Same as `wp::Function`, it's useless at the moment*.
* `wp::Various` : A bunch of various functions, such as a int to string converter (and string to int), a crypter (and uncrypter), calculate a vector's angle, some interpolations and way more (**Windows only**).
* `wp::VertexAllocator` : An easy way to manage a `sf::VertexArray` to draw multiple elements like a tilemap. (Works only for quads).

## Added soon or future projects

* A wiki !! And some examples.

---

Developper : HANEN Nathan - aka WildGoat07

contact : hanen.nathan@gmail.com
