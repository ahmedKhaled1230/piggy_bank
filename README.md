# Five_C_Practice_Projects

**Author:** Ahmed khaled mohamed youssri khaled elbohy  
**Email:** ahmed2006688@gmail.com  
**Module:** Microcontroller-Based Systems (90 Hours)  
**Scope:** Days 01-03, plain C only

## Project 1: My Piggy Bank

A command-line piggy bank application written in C99. It manages five coin
types, calculates the bank balance, displays coin piles, and checks toy
affordability.

## Requirements

- Use plain C only; no AVR, hardware, or extra libraries.
- Use one source file. The supplied brief calls it `main.c`; this project uses
	`piggy_bank.c`.
- Include only `<stdio.h>`, `<stdint.h>`, and `<string.h>`.
- Use an Any C99 compiler.
- Every function must be `static` and remain under 40 lines.
- `main()` must display a menu in a `do-while` loop and call functions; it must
	not access the bank data directly.
- Every function must be `static` and remain under 40 lines.
- Check every `scanf` return value. Invalid input must not crash, hang, or
	leave unread input in the buffer.

## Required Functions

- `seedBank()` initializes the starting coins and four toys with names and prices.
- `addCoins()` adds a selected coin quantity after validating the coin type.
- `takeCoins()` removes coins only when the bank has enough; counts must never become negative.
- `bankTotal()` returns the total bank value in piastres.
- `sumCoins()` recursively sums an array and uses no loop.
- `biggestPile()` returns the index of the largest coin pile; ties use the smallest index.
- `showBank()` displays each coin value, quantity, and a visual bar.
- `drawBar()` prints exactly `width` characters using `#` and `-`.
- `buyToy()` displays toys and reports whether the bank can afford the selected toy without removing coins.
- `bankReport()` displays the total value, total coin count, largest pile, and affordable toys.

## Menu

| Option | Action |
|---|---|
| 1 | Add coins |
| 2 | Take coins |
| 3 | Show the bank and coin bars |
| 4 | Check whether a toy is affordable |
| 5 | Display the bank report |
| 0 | Exit |

## Acceptance Checks

- Taking more coins than available changes nothing.
- `sumCoins()` contains no `for` or `while` loop.
- Entering `hello` at the menu prints one polite error message and does not loop endlessly.
- An empty bank reports a total of `0` and no affordable toys.
- The bank report states how many of the four toys are affordable.

## Notes

- Currency values are stored in piastres: 25, 50, 100, 200, and 500.
- Buying a toy is only a check; it does not remove coins from the bank.
- The largest pile uses the lowest index when piles are tied.
- `clearInput()` safely discards invalid input through the newline or `EOF`.

## Build and Run

Using GCC in PowerShell:

```powershell
gcc -std=c99 -Wall -Wextra "piggy_bank.c" -o "piggy_bank.exe"
& ".\piggy_bank.exe"
```

The quotes are required because the original filenames contain spaces when using the original project name. The current source and executable use underscores to make command-line use simpler.
