# Woler

A simple program that wakes systems up using WOL (currently Windows only).

# Build

## Prerequisites

- [git](https://git-scm.com/)
- [cmake](https://cmake.org/) (Minimum Version Required: **3.28.0**)

## Example

``` 
cmake -S path/to/Woler -B path/to/Woler/build
cmake --build path/to/Woler/build
```

# Usage

```
woler mac1 [mac2...]
```

# Dependencies

- [Sock](https://github.com/AutoPilot2004/Sock)