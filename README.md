# Planet Puff

*"Size is just a suggestion."*

A whimsical 2D side-scrolling platformer built in **Unreal Engine 5.8** using **Paper2D**. Play as a small, cheerful space alien who can grow and shrink at will when reunited with his powerup to platform through levels and collect hidden treasures across Planet Puff.

---

## Overview

Planet Puff's core mechanic lets the player scale their character up and down in real time — shrinking to slip through tight gaps, or growing to add extra reach. The ability is granted mid-game via a collectible power-up rather than available from the start.

- **Genre:** 2D Platformer / Puzzle-Platformer
- **Engine:** Unreal Engine 5.8 (Paper2D)
- **Tone:** Whimsical, Cartoony
- **Platform:** Windows

---

## Features

- **Scale Ability** — hold shift to grow, hold ctrl to shrink, with smooth real-time interpolation and matching audio pitch feedback
- **Heart-based Health System** — takes damage, brief invulnerability window after a hit, animated HUD feedback and camera shake
- **Coins & Scoring** — collectible coins with a procedural sparkle effect, persistent score tracking across a playthrough
- **Challenge Stars** — 3 hidden collectible stars per level for completionists
- **Stage Timer** — sprite-based countdown display
- **Resolution-Independent HUD** — UI stays correctly framed within a locked 16:9 view regardless of the player's window size or aspect ratio
- **Scripted Death Sequence** — slow-motion impact, sprite flash, screen shake, explosion animation, and a Game Over menu with Retry/Main Menu options
- **Reactive Audio Design** — pitch-varied jump and footstep sounds, fall-distance-scaled landing impact, and a live pitch-modulated tone tied to the scale ability
- **Skippable/Animated Credits** — hold to fast-forward through the credits scroll and enjoy animated sprites accompanying the credits

---

## Controls

| Action | Input |
|---|---|
| Move Left/Right | `A` / `D` |
| Jump | `Space` |
| Scale Up / Down | Hold `Shift` (grow), Hold `Ctrl` (shrink) |
| Interact | `W` Context-sensitive (e.g., entering the level-end door) |

*(Bindings are set up via Unreal's Enhanced Input system and can be remapped in the project's Input Actions.)*

---

## Built With

- [Unreal Engine 5.8](https://www.unrealengine.com/)
- **Paper2D** — sprites, flipbook animation, tile maps
- **Gameplay Ability System (GAS)** — powers the Scale ability
- **UMG** — HUD and menu systems

---

## Running the Game

### Prerequisites
This game requires the **Microsoft Visual C++ 2015–2022 Redistributable (x64)** to run. If the game fails to launch:

1. Run `vc_redist.x64.exe` (found in the root folder), **or**
2. Download it directly from Microsoft: https://aka.ms/vs/17/release/vc_redist.x64.exe

### Playing
Download the latest release from https://rndi.itch.io/planet-puff, extract the full folder (not just the `.exe`) to any new folder, and run the game's executable.

---

## Development Notes

- Player health, scoring, and challenge-star collection are tracked via a custom `Game Instance`, and reset appropriately on level load/retry.
- The in-game camera is locked to a 16:9 aspect ratio with letterboxing to guarantee consistent world visibility for camera-bounds and gameplay tuning across all resolutions.
- Footstep timing is driven by a manual timer rather than animation notifies, since base Paper2D does not natively support Anim Notifies on Flipbooks.

---

## License

MIT

## Credits

Randy Kim\
Abstraction (https://abstractionmusic.com)\
Kenney (https://kenney.nl/)\
unTied Games (https://untiedgames.itch.io)\
Dream Mix (https://dreammixgames.itch.io)\
UkiyoMoji (https://www.1001fonts.com/users/UkiyoMoji/)\
Kronbits (https://kronbits.itch.io/)\