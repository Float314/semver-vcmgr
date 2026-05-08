# semver-vcmgr - Semantic Version control manager and Comparison Utility 

![GitHub License](https://img.shields.io/github/license/Float314/semver-vcmgr)
![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/Float314/semver-vcmgr/multi-platform.yml)
![GitHub commit activity](https://img.shields.io/github/commit-activity/t/Float314/semver-vcmgr)
![GitHub top language](https://img.shields.io/github/languages/top/Float314/semver-vcmgr)
![GitHub Tag](https://img.shields.io/github/v/tag/Float314/semver-vcmgr)

This library allows you to set a specific version for your program inside the
program, which allows you to not specify versions based on README.md documents
and probably git tags (idek)

# How to use? 

Easy! In your main.cpp (or any 'main' c++ file to compile), insert these lines 
in the beginning of code 

> Not necessary to be the main.cpp, but for code organisation :/ 

```cpp
// ... (header files)
#include <version_control.hpp>

// ... 
// Program beginning

#ifndef PROGRAM_VERSION
#define PROGRAM_VERSION "v1.0.3-beta-1"

program_version Version =  PROGRAM_VERSION; 

#endif

```

> Theoretically you can ignore `#define PROGRAM_VERSION` or just put it in a 
> different header file, but putting it in main.cpp (or at your choice, other
> file that contains main code). Won't affect anything except if other library
> uses the macro (it could btw, so maybe use `#define {PROGRAM_NAME}_VERSION` 
> for safery :/ )

This splits the version into - 
- Major                (v**1**.0.3-beta-1, the 1)
- Minor                (v1.**0**.3-beta-1, the 0)
- Subminor             (v1.0.**3**-beta-1, the 3)
- Release Type         (v1.0.3-**beta**-1, the beta)
- Release Type Version (v1.0.3-beta-**1**, the 1 after beta)

If your program has a "minimum required version" cause the previous version 
lacks many features, you can put an "if" statement like this - 

```cpp
if (someLibrarysVersion <= "v1.0.2-beta-2") {
    /* Error message like - 
        std::cerr << "Update the Library to use this feature"
    */
}

```

That's not all. You can even fetch major, minor versions like this -

```cpp

/*
    version.major();
    version.minor();
    version.subMinor();
    version.releaseType();
    version.RelTypeVersion(); 
*/

auto major = Version.major(); // returns an Int
auto ReleaseType = Version.releaseType(); // returns std::string 

// Implementation Example :/

if(ReleaseType == "alpha" || ReleaseType == "beta") {
    std::cout << "You are using the " << ReleaseType << " build of the Program. \n" 
    << "Things May break!" << std::endl; 
}

```

Uh, yeah, thats it apparantly :/ (use code for details, my comments are *well* 
documented and it is easy to read cause im just a C++ beginner lol)

See the "real" implementation in examples/ 

# License and Legal Stuff 

This license is licensed under the **GNU LGPL v3**. 

Copyright (c) 2026, Float314 (a.k.a. Cyphrixz) and all the Contributors
                    to this project (if any). 

This program is free software: you can redistribute it and/or modify
it under the terms of the **GNU Lesser General Public License** as 
published by the Free Software Foundation, either version 3 of the 
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but **WITHOUT ANY WARRANTY**; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

By using this program, you agree to the License. If you do not
agree to the License, you may cease the use of this software 
immediately.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

### Long live free software!

<img src="https://www.gnu.org/graphics/lgplv3-147x51.png" alt="Project Logo">
