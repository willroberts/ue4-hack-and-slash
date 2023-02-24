# UE4 Hack & Slash

A third-person hack & slash game developed with Unreal Engine 4.

<img src="HackAndSlash.png" alt="UE4 Hack & Slash Screenshot" />

## Project Setup

In order to run this game, additional content is needed from the Unreal Marketplace:

- Paragon: Minions
- Paragon: Muriel
- Paragon: Revenant
- Soul: Cave
- Starter Content

These will be referenced by the game, and must be present in order to load the
project. They are present in `.gitignore` to reduce the overall repo size from
9GB to 400MB.

## On Git LFS and BuiltData

While the game's map is only 9MB, the built level data is 310MB. This is well
above Github's 100MB limit on files, so Git LFS is necessary for the upload.

Git LFS is currently disabled, so the file is temporarily ignored. It will be
uploaded once Git LFS is enabled on the repo again.