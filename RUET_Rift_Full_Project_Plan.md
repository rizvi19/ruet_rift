# RUET Rift: The 10-Hour Distortion

## Full Codex-Ready Project Plan for C++ OpenGL / GLUT

**Project type:** 3D puzzle-adventure game / simulation

**Technology target:** C++ with OpenGL + GLUT / FreeGLUT

**Course boundary:** Computer Graphics / Computer Graphics Sessional level project

**Main constraint:** The project must look creative and impressive, but it must remain explainable using common course topics: primitives, transformations, viewing/camera, projection, clipping/boundaries, lighting, shading, color, animation, simple interaction, and simple collision. Avoid external game engines, advanced physics engines, complex shaders, imported 3D models, skeletal animation, real ray tracing, real-time shadow mapping, or anything that looks outside the scope of a normal OpenGL lab project.

---

## 1. Short Project Summary

**RUET Rift: The 10-Hour Distortion** is a 3D OpenGL puzzle-adventure game set in a simplified RUET-inspired campus map containing:

1. Sher-e-Bangla Hall
2. RUET Library
3. CSE Department
4. HPCL Lab inside CSE Department

A Computer Graphics program inside the **HPCL Lab** crashes and distorts reality. The world becomes affected by transformation errors, light anomalies, projection illusions, gravity distortions, and mathematical patterns. A huge countdown appears in the sky: **10 HOURS REMAINING**. The player is the hero and must complete 10 puzzle levels. Each level reduces the countdown by one hour. After completing all levels, the player restores the Reality Core inside HPCL Lab.

---

## 2. Story

Inside RUET CSE Department's **HPCL Lab — High Performance Computing Lab**, a graphics simulation named `RealityRenderer.cpp` was being tested. It was designed to simulate real-world geometry using transformations, projection, lighting, and rendering logic.

During execution, a corrupted transformation matrix escaped the simulation and affected the real campus. Buildings shifted, trees scaled strangely, roads rotated, black holes and white holes appeared, shadows became fixed, and hidden symbols started appearing around the campus.

The sky is frozen in daylight because the distortion locked the sun direction. A countdown appears above the campus:

```text
10 HOURS REMAINING
```

After 10 levels, the countdown reaches zero. If the player solves all puzzles, the HPCL Reality Core is restored. If not, the distorted reality becomes permanent.

---

## 3. Main Design Philosophy

The game must feel mysterious, clever, and puzzle-based, but the implementation should remain simple.

### The player should feel:

- The environment itself contains clues.
- Shadows, numbers, objects, lights, reflections, and camera views are meaningful.
- The puzzles are not random button pressing.
- The player is decoding a broken reality.

### The code should use:

- `glTranslatef()`
- `glRotatef()`
- `glScalef()`
- `glPushMatrix()` / `glPopMatrix()`
- `gluLookAt()`
- GLUT keyboard/mouse callbacks
- Basic lighting using OpenGL fixed pipeline
- Basic text drawing using bitmap text
- Basic collision using distance and AABB checks
- Basic animation using `sin()`, angle update, and timer

### The code should avoid:

- Full game engine
- Bullet/PhysX physics engine
- Imported complex 3D character models
- Skeletal animation
- Real-time ray tracing
- Real shadow maps
- Advanced GLSL-only rendering
- Complex AI/pathfinding
- Multiplayer
- Networking
- Huge accurate campus map

---

## 4. Course-Syllabus Justification

This project is intentionally bounded by normal Computer Graphics course contents:

| Course Topic | How Used in Project |
|---|---|
| Graphics primitives | Buildings, roads, trees, player, portals, pillars, lamps, objects |
| Transformation | Distorted roads, scaled trees, rotating platforms, moving gates |
| 3D transformation | Player/camera/world objects in 3D space |
| Viewing and camera | Third-person, first-person, top-view, projection puzzle |
| Projection | Anamorphic corridor and camera-based puzzle |
| Clipping/boundary | CSE clipping barrier and player boundary logic |
| Hidden surface / depth | `GL_DEPTH_TEST`, basic scene depth correctness |
| Illumination and shading | Sunlight, lamps, colored beams, diffuse/specular materials |
| Colored light / RGB | Prism lock and color-based final clues |
| Animation | Rotating fragments, oscillating platforms, black hole rings |
| Interaction | WASD movement, E interaction, puzzle switching |
| OpenGL pipeline | Window, rendering loop, camera, draw functions, update logic |

---

## 5. Full Map Design

The map does not need to be a perfect real RUET map. It should be a simplified symbolic version for gameplay convenience.

### Suggested Layout

```text
+----------------------------------------------------------------+
|                                                                |
|                         RUET LIBRARY                           |
|                       Levels 4, 5, 6                            |
|                                                                |
|             Garden / Prism / Pendulum / Light Path             |
|                                                                |
|  SHER-E-BANGLA HALL              CENTRAL ROAD / COURTYARD      |
|  Levels 1, 2                     Level 3                       |
|                                                                |
|                                                                |
|                                           CSE DEPARTMENT        |
|                                           Levels 7, 8, 9        |
|                                           HPCL LAB Level 10     |
|                                                                |
+----------------------------------------------------------------+
```

### Required Areas

1. **Sher-e-Bangla Hall Area**
   - Starting area
   - Gate
   - Pillars
   - Garden
   - Trees

2. **Central Road Area**
   - Distorted road
   - Reflection/water area
   - Black-hole visual zone if needed

3. **Library Area**
   - Library building
   - Prism lock
   - Pendulum hall
   - Light corridor

4. **CSE Department Area**
   - CSE gate
   - Clock gate
   - Anamorphic corridor
   - Resonance bridge / rooftop

5. **HPCL Lab**
   - Final room
   - Reality Core
   - Final force-balance puzzle

---

## 6. Visual Style

### Normal campus elements

- Green grass
- Gray roads
- Cream/white/gray buildings
- Blue windows
- Brown tree trunks
- Green tree leaves
- Simple benches
- Simple lamp posts

### Distortion elements

- Purple/blue glowing fragments
- Black/dark sphere with rings for black hole
- White/blue sphere with outward particles for white hole
- Floating mathematical symbols
- Glowing clue text
- Rotating torus rings
- Oscillating platforms
- Transparent colored beams
- Frozen daylight sky

Use simple colors and primitives. The project should look creative because of layout, animation, and puzzle logic, not because of complex assets.

---

## 7. Player System

### Player character

Use a basic humanoid made from primitives:

- Sphere = head
- Cube = body
- Cubes/cylinders = arms
- Cubes/cylinders = legs

No complex animation is required. Optional: small arm/leg swing while moving.

### Player data

```cpp
struct Player {
    float x, y, z;
    float yaw;
    float speed;
    float radius;
    int health;
    bool isJumping;
    float jumpVelocity;
};
```

### Controls

| Key | Action |
|---|---|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| Left arrow | Turn left / camera yaw |
| Right arrow | Turn right / camera yaw |
| Up arrow | Camera pitch up |
| Down arrow | Camera pitch down |
| E | Interact with switch/object/clue |
| Space | Jump or activate pad |
| C | Change camera mode |
| M | Show/hide mini-map or objective panel |
| R | Restart current level |
| P | Pause |
| Enter | Start game from menu |
| Esc | Exit |

---

## 8. Camera System

Implement at least two camera modes. Three is better if possible.

### Camera modes

| Mode | Description | Purpose |
|---|---|---|
| 0 | Third-person | Main gameplay |
| 1 | Top view | Puzzle observation and map view |
| 2 | First-person | COD/Far Cry style exploration, optional |

### Third-person camera idea

```cpp
gluLookAt(
    player.x - sin(player.yaw) * cameraDistance,
    player.y + 6.0f,
    player.z + cos(player.yaw) * cameraDistance,
    player.x,
    player.y + 1.5f,
    player.z,
    0, 1, 0
);
```

### Top-view camera idea

```cpp
gluLookAt(
    player.x,
    45.0f,
    player.z + 1.0f,
    player.x,
    0.0f,
    player.z,
    0, 0, -1
);
```

---

## 9. HUD and Sky Timer

### HUD must show:

- Project title
- Current level
- Hours remaining
- Current objective
- Fragments collected
- Current camera mode
- Interaction hint
- Controls reminder

Example:

```text
RUET RIFT: THE 10-HOUR DISTORTION
Level: 4 / 10
Time Left: 7 Hours
Objective: Align the RGB beams to unlock the Library Prism
Fragments: 3 / 10
Camera: Third Person
Press E to interact
```

### Sky timer

A large text appears above the map:

```text
7 HOURS REMAINING
```

The timer is not real-time 10 hours. It decreases after completing each level.

```cpp
int hoursRemaining = 10;
int currentLevel = 1;
```

When a level is completed:

```cpp
currentLevel++;
hoursRemaining--;
```

---

## 10. Game State System

Use a simple enum:

```cpp
enum GameState {
    MENU,
    PLAYING,
    PAUSED,
    LEVEL_COMPLETE,
    GAME_OVER,
    GAME_WON
};

GameState gameState = MENU;
```

---

## 11. Level Manager

### Level data

```cpp
struct Level {
    int id;
    string name;
    string objective;
    bool completed;
};
```

### Global variables

```cpp
int currentLevel = 1;
int hoursRemaining = 10;
int fragmentsCollected = 0;
bool levelSolved[11];
```

### Core functions

```cpp
void loadLevel(int level);
void updateLevel();
void completeLevel();
void drawCurrentLevelObjects();
void checkCurrentLevelInteractions();
```

### Level completion behavior

When level is solved:

1. Play/trigger a simple visual animation.
2. Collect one Reality Fragment.
3. Reduce countdown by one hour.
4. Unlock next area.
5. Update objective text.

---

## 12. Basic Collision System

### Distance collision

Use for:

- Collectibles
- Switches
- Pillars
- Trees
- Black hole danger radius
- White hole push radius

```cpp
float distance2D(float x1, float z1, float x2, float z2) {
    float dx = x1 - x2;
    float dz = z1 - z2;
    return sqrt(dx * dx + dz * dz);
}
```

### AABB collision

Use for:

- Buildings
- Walls
- Gates
- Platforms
- Large boxes

```cpp
bool checkAABB(float px, float pz, float minX, float maxX, float minZ, float maxZ) {
    return px > minX && px < maxX && pz > minZ && pz < maxZ;
}
```

---

## 13. Interaction System

The player presses `E` near an interactive object.

```cpp
if (nearObject && key == 'e') {
    activateObject();
}
```

Each puzzle can use simple states:

```cpp
int currentStep;
float objectAngle;
bool switchActive;
bool puzzleSolved;
```

---

# 14. The 10 Puzzle Levels

The following are the final 10 puzzles with tricky mystery-style design, but each is implementable using simple OpenGL concepts.

---

## Level 1: The Frozen Sundial of Sher-e-Bangla Hall

### Location

Sher-e-Bangla Hall courtyard.

### Time remaining

10 hours.

### Concept

Light direction, shadow alignment, angle, rotation.

### Story

The sky is frozen in daylight. Three strange pillars appear in front of Sher-e-Bangla Hall. Their shadows point in wrong directions. The hall gate is locked.

A glowing clue on the ground says:

```text
When the sun refuses to move,
move the shadows.
Three shadows must meet where time began.
```

### What the player sees

- Three pillars.
- Each pillar has a shadow line on the ground.
- A circular mark lies at the center.
- The hall gate is locked.
- Pressing `E` near a pillar rotates its shadow by 30 degrees.

### Puzzle rule

The player must rotate the three shadows so they all point toward the same central stone mark.

### Correct solution

Example values:

```text
Pillar 1 angle = 30 degrees
Pillar 2 angle = 150 degrees
Pillar 3 angle = 270 degrees
```

The exact angles can be changed, but keep them multiples of 30 degrees.

### Implementation variables

```cpp
float pillarAngle[3] = {0, 60, 120};
float correctPillarAngle[3] = {30, 150, 270};
```

### Interaction logic

```cpp
if (nearPillar(i) && key == 'e') {
    pillarAngle[i] += 30;
    if (pillarAngle[i] >= 360) pillarAngle[i] -= 360;
}
```

### Solving condition

```cpp
if (pillarAngle[0] == 30 && pillarAngle[1] == 150 && pillarAngle[2] == 270) {
    completeLevel();
}
```

### Drawing plan

- Draw pillar using cylinder or cube.
- Draw shadow using a flat dark rectangle/line on ground.
- Rotate shadow with `glRotatef(pillarAngle[i], 0, 1, 0)`.
- Draw center mark using torus or flat circle.

### Course concept explanation

This level demonstrates rotation transformation and simple light/shadow representation using geometry. It does not need real shadow mapping.

---

## Level 2: The Fibonacci Garden

### Location

Sher-e-Bangla Hall garden.

### Time remaining

9 hours.

### Concept

Scaling transformation, Fibonacci sequence, natural growth pattern.

### Story

The garden trees are distorted. Some are tiny, some are huge. A stone tablet says:

```text
Nature does not count like men.
It grows: 1, 1, 2, 3, 5, 8.
Follow growth, not distance.
```

### What the player sees

Six special trees with different sizes:

```text
1, 1, 2, 3, 5, 8
```

But they are arranged randomly.

### Puzzle rule

The player must activate the trees in Fibonacci order:

```text
1 -> 1 -> 2 -> 3 -> 5 -> 8
```

If the player activates a wrong tree, the sequence resets.

### Implementation variables

```cpp
struct PuzzleTree {
    float x, z;
    int fibValue;
    bool activated;
};

int fibSequence[6] = {1, 1, 2, 3, 5, 8};
int currentFibStep = 0;
```

### Interaction logic

```cpp
if (nearTree(i) && key == 'e') {
    if (trees[i].fibValue == fibSequence[currentFibStep]) {
        trees[i].activated = true;
        currentFibStep++;
    } else {
        resetFibonacciPuzzle();
    }
}
```

### Solving condition

```cpp
if (currentFibStep == 6) {
    completeLevel();
}
```

### Drawing plan

Use `glScalef(scale, scale, scale)` for each tree.

```cpp
glPushMatrix();
glTranslatef(tree.x, 0, tree.z);
glScalef(tree.fibValue * 0.25f, tree.fibValue * 0.25f, tree.fibValue * 0.25f);
drawTree();
glPopMatrix();
```

### Course concept explanation

This level demonstrates scaling transformation and visual pattern recognition.

---

## Level 3: The Road That Rotates Only in Reflection

### Location

Central road between Hall and Library.

### Time remaining

8 hours.

### Concept

Reflection, rotation, symmetry, transformed duplicate geometry.

### Story

A road segment is rotated and disconnected. A reflective water surface beside the road shows a reversed clue. The ground says:

```text
The road lies.
The reflection tells the truth.
Do not rotate what you see.
Rotate what the mirror sees.
```

### What the player sees

- A broken road segment.
- A water/mirror plane.
- Three switches labeled 90, 180, 270.
- The direct road view suggests the wrong answer.
- The reflection gives the correct clue.

### Puzzle rule

The player must select the switch based on the reflected clue.

### Correct solution

Recommended:

```text
Correct switch = 270 degrees
```

### Implementation variables

```cpp
float roadAngle = 90;
int correctRoadSwitch = 270;
```

### Interaction logic

```cpp
if (nearSwitch90 && key == 'e') selectedAngle = 90;
if (nearSwitch180 && key == 'e') selectedAngle = 180;
if (nearSwitch270 && key == 'e') selectedAngle = 270;

if (selectedAngle == 270) {
    roadAngle = 0;
    completeLevel();
} else {
    roadAngle += 90; // punishment/visual confusion
}
```

### Drawing plan

- Draw road segment using a flat cuboid.
- Rotate it with `glRotatef(roadAngle, 0, 1, 0)`.
- Fake reflection by drawing a duplicate road/clue on the water side with inverted scale or darker transparent color.

```cpp
glPushMatrix();
glScalef(1, 1, -1);
drawReflectedRoadClue();
glPopMatrix();
```

### Course concept explanation

This level uses rotation transformation and a simple reflection illusion using duplicate transformed geometry.

---

## Level 4: The Library Prism Lock

### Location

RUET Library entrance.

### Time remaining

7 hours.

### Concept

RGB additive color, light beams, mirror alignment.

### Story

The Library door is sealed by a prism. Red, green, and blue beams are scattered. The clue says:

```text
Knowledge opens only under white truth.
But truth is born from three broken colors.
```

### What the player sees

- Red light source.
- Green light source.
- Blue light source.
- Three rotating mirrors.
- Central prism/sphere above the Library door.
- Door locked until prism becomes white.

### Puzzle rule

Rotate the mirrors so all three beams reach the central prism. When red, green, and blue beams hit the prism, it turns white and opens the door.

### Correct solution

Example:

```text
Red mirror angle = 45 degrees
Green mirror angle = 135 degrees
Blue mirror angle = 225 degrees
```

### Implementation variables

```cpp
float mirrorAngle[3] = {0, 0, 0};
float correctMirrorAngle[3] = {45, 135, 225};
bool beamAligned[3] = {false, false, false};
bool libraryDoorOpen = false;
```

### Interaction logic

```cpp
if (nearMirror(i) && key == 'e') {
    mirrorAngle[i] += 15;
    if (mirrorAngle[i] >= 360) mirrorAngle[i] -= 360;
}
```

### Solving condition

```cpp
if (mirrorAngle[0] == 45 && mirrorAngle[1] == 135 && mirrorAngle[2] == 225) {
    libraryDoorOpen = true;
    completeLevel();
}
```

### Drawing plan

- Draw colored beams as thin cylinders or flat rectangular strips.
- Draw prism as sphere/octahedron.
- Draw mirror as thin shiny rectangle.
- When solved, set prism color to white.

### Course concept explanation

This level uses RGB additive color and simple light visualization using colored primitives.

---

## Level 5: The Pendulum of False Gravity

### Location

Inside/behind Library.

### Time remaining

6 hours.

### Concept

Gravity direction, pendulum equilibrium, force direction.

### Story

A giant pendulum hangs in the Library hall, but it does not point straight down. Gravity has been distorted by nearby black-hole and white-hole generators.

The clue says:

```text
When down is no longer down,
trust the weight, not the floor.
```

### What the player sees

- A pendulum hanging from ceiling.
- Four gravity symbols on the floor: North, South, East, West.
- Black-hole/white-hole generators.
- Door opens only when the pendulum points toward the correct symbol.

### Puzzle rule

The player must activate the correct gravity generator so the pendulum points toward the hidden marked direction.

### Correct solution

Keep it simple:

```text
Activate North Black Hole generator.
```

or slightly harder:

```text
Activate North Black Hole + East White Hole.
```

Recommended for first implementation: use one correct generator.

### Implementation variables

```cpp
bool gravityGeneratorActive[4];
float pendulumAngle = 0;
float correctPendulumAngle = 45;
```

### Interaction logic

```cpp
if (nearGravityGenerator(i) && key == 'e') {
    gravityGeneratorActive[i] = !gravityGeneratorActive[i];
    updatePendulumAngle();
}
```

### Simple update logic

```cpp
if (northGeneratorActive && !southGeneratorActive && !eastGeneratorActive && !westGeneratorActive) {
    pendulumAngle = correctPendulumAngle;
} else {
    pendulumAngle = wrongAngle;
}
```

### Solving condition

```cpp
if (pendulumAngle == correctPendulumAngle) {
    completeLevel();
}
```

### Drawing plan

Draw pendulum rod using cylinder or thin cube. Rotate it using `glRotatef(pendulumAngle, 0, 0, 1)`.

### Course concept explanation

This level uses simple physics-inspired visual behavior and rotation transformation. It does not simulate real gravity; it visualizes force direction in an explainable way.

---

## Level 6: The Inverse-Square Lamp Corridor

### Location

Road from Library toward CSE.

### Time remaining

5 hours.

### Concept

Light attenuation, inverse-square idea, distance-based logic.

### Story

Three gates block the corridor. Each gate opens only when a receiver gets the correct brightness from a lamp. A clue says:

```text
The lamp does not fade by steps.
It fades by squares.
Near is not twice bright.
Near is four times bright.
```

### What the player sees

- One bright lamp.
- Three receivers.
- Floor marks showing distance slots 1, 2, 3, 4.
- Receivers cycle through distance slots when interacted.

### Puzzle rule

The player must place each receiver at the correct distance.

### Correct solution

| Receiver | Required brightness | Correct distance |
|---|---:|---:|
| A | 1/4 | 2 |
| B | 1/9 | 3 |
| C | 1/16 | 4 |

### Implementation variables

```cpp
int receiverDistance[3] = {1, 1, 1};
int correctDistance[3] = {2, 3, 4};
```

### Interaction logic

```cpp
if (nearReceiver(i) && key == 'e') {
    receiverDistance[i]++;
    if (receiverDistance[i] > 4) receiverDistance[i] = 1;
}
```

### Solving condition

```cpp
if (receiverDistance[0] == 2 && receiverDistance[1] == 3 && receiverDistance[2] == 4) {
    completeLevel();
}
```

### Optional brightness calculation

```cpp
float brightness = 1.0f / (receiverDistance[i] * receiverDistance[i]);
```

Use brightness only for visual color intensity.

### Drawing plan

- Draw lamp as glowing sphere.
- Draw receivers as small boxes/spheres on distance marks.
- Draw light beams as transparent yellow strips.
- Change receiver brightness based on distance.

### Course concept explanation

This level uses light attenuation concept and distance-based visual brightness. The implementation remains simple.

---

## Level 7: The Prime Clock of the CSE Gate

### Location

CSE Department outer gate.

### Time remaining

4 hours.

### Concept

Prime numbers, circular layout, interaction sequence.

### Story

The CSE gate is locked by a circular clock with 12 glowing markers. A clue says:

```text
The composite hours lie.
Only indivisible time survives.
Begin where time has no factor.
```

### What the player sees

Clock numbers:

```text
1 2 3 4 5 6 7 8 9 10 11 12
```

### Puzzle rule

The player must activate only prime-numbered markers:

```text
2, 3, 5, 7, 11
```

The trick: `1` is not prime. If the player activates `1`, the puzzle resets.

### Correct solution

Recommended order:

```text
2 -> 3 -> 5 -> 7 -> 11
```

### Implementation variables

```cpp
int primeSequence[5] = {2, 3, 5, 7, 11};
int currentPrimeStep = 0;
```

### Interaction logic

```cpp
if (nearClockMarker(i) && key == 'e') {
    int number = marker[i].number;
    if (number == primeSequence[currentPrimeStep]) {
        marker[i].activated = true;
        currentPrimeStep++;
    } else {
        resetPrimePuzzle();
    }
}
```

### Solving condition

```cpp
if (currentPrimeStep == 5) {
    openCSEGate();
    completeLevel();
}
```

### Drawing plan

Place 12 small spheres in circle:

```cpp
x = centerX + radius * cos(angle);
z = centerZ + radius * sin(angle);
```

Draw number labels using bitmap text.

### Course concept explanation

This is a logic puzzle implemented using object placement, text rendering, and interaction. It remains within basic OpenGL.

---

## Level 8: The Anamorphic Projection Corridor

### Location

Inside CSE Department corridor.

### Time remaining

3 hours.

### Concept

Perspective projection, camera position, viewpoint-dependent hidden message.

### Story

The corridor contains floating broken symbols. From normal view, they look meaningless. A wall message says:

```text
Truth is not hidden.
You are standing in the wrong place.
```

### What the player sees

- Floating pieces/symbols in the corridor.
- A marked position on the floor: `STAND HERE`.
- From that viewpoint, the symbols align into a readable word.

Hidden word options:

```text
HPCL
CORE
314
```

Recommended hidden word:

```text
CORE
```

### Puzzle rule

The player must stand at the correct viewpoint and face the symbols. Then press `E` to reveal/confirm the hidden word.

### Implementation variables

```cpp
Vec3 projectionViewPoint = {x, y, z};
float requiredYaw = 90.0f;
bool hiddenMessageVisible = false;
```

### Interaction logic

```cpp
if (distance2D(playerPos, projectionViewPoint) < 1.0f && abs(playerYaw - requiredYaw) < 15.0f) {
    hiddenMessageVisible = true;
}

if (hiddenMessageVisible && key == 'e') {
    completeLevel();
}
```

### Drawing plan

Simple approach:

- Place floating letter pieces manually.
- They do not need to mathematically align perfectly, but from the marked position they should visually form `CORE`.
- When the player stands correctly, draw extra clear text `CORE` above/near the symbols.

### Course concept explanation

This level demonstrates viewing and perspective. The same 3D objects produce different perceived arrangements from different camera positions.

---

## Level 9: The Resonance Bridge

### Location

CSE rooftop / bridge toward HPCL.

### Time remaining

2 hours.

### Concept

Wave motion, sine function, phase synchronization, animation.

### Story

The bridge to HPCL is broken into floating platforms. The platforms move up and down like waves. A clue says:

```text
Do not jump when the bridge rises.
Jump when all waves agree.
```

### What the player sees

- Three or four floating platforms.
- Each platform oscillates vertically.
- Tuning pillars near the bridge.
- Pressing `E` near a tuning pillar changes the phase of one platform.

### Puzzle rule

The player must synchronize all platforms so they reach the same height together. When synchronized, the bridge stabilizes and becomes crossable.

### Correct solution

Simple version:

```text
All phases = 0
```

### Implementation variables

```cpp
float platformPhase[3] = {0, 1.57f, 3.14f};
float platformY[3];
float amplitude = 1.5f;
float baseY = 4.0f;
```

### Animation

```cpp
platformY[i] = baseY + amplitude * sin(globalTime + platformPhase[i]);
```

### Interaction logic

```cpp
if (nearTuningPillar(i) && key == 'e') {
    platformPhase[i] += PI / 2;
    if (platformPhase[i] >= 2 * PI) platformPhase[i] = 0;
}
```

### Solving condition

```cpp
if (platformPhase[0] == 0 && platformPhase[1] == 0 && platformPhase[2] == 0) {
    bridgeStable = true;
    completeLevel();
}
```

When stable:

```cpp
platformY[i] = baseY;
```

### Drawing plan

- Draw platforms as cuboids.
- Draw tuning pillars as cylinders.
- Draw glowing wave symbols near each platform.

### Course concept explanation

This level uses animation, sine function, and phase synchronization. It is implemented through simple periodic movement.

---

## Level 10: The Three-Body Reality Core

### Location

HPCL Lab final room.

### Time remaining

1 hour.

### Concept

Force balance, light reveal, final symbolic sequence, previous-level memory.

### Story

The player reaches HPCL Lab. The Reality Core is unstable. The room contains:

- Reality Core at the center
- One black-hole generator
- One white-hole generator
- Three mass cubes
- A light prism
- Five final switches

The wall says:

```text
The Core cannot be destroyed.
It can only be balanced.
Darkness pulls.
Light reveals.
Repulsion frees.
Order restores.
```

### Puzzle structure

This final level has three stages.

---

### Stage 1: Balance the forces

The player must place three mass cubes on three glowing floor marks around the Reality Core.

Layout:

```text
        Cube A Target

Cube B Target    Core    Cube C Target
```

### Stage 1 implementation variables

```cpp
bool cubeInTarget[3] = {false, false, false};
bool forceBalanced = false;
```

### Stage 1 solving condition

```cpp
if (cubeInTarget[0] && cubeInTarget[1] && cubeInTarget[2]) {
    forceBalanced = true;
}
```

Cubes can be activated simply by pressing `E` near each cube/target instead of physically pushing them, if pushing becomes difficult.

---

### Stage 2: Reveal the hidden sequence with light

After the forces are balanced, a white light beam turns on and reveals five symbols on the wall:

```text
Shadow -> Growth -> Light -> Gravity -> Projection
```

These symbols refer to earlier levels:

| Symbol | Earlier level |
|---|---|
| Shadow | Level 1 Sundial |
| Growth | Level 2 Fibonacci Garden |
| Light | Level 4 Prism Lock |
| Gravity | Level 5 Pendulum |
| Projection | Level 8 Anamorphic Corridor |

---

### Stage 3: Activate final switches

The player must activate five final switches in the revealed order:

```text
Shadow -> Growth -> Light -> Gravity -> Projection
```

### Stage 3 implementation variables

```cpp
enum FinalSymbol {
    SHADOW,
    GROWTH,
    LIGHT,
    GRAVITY,
    PROJECTION
};

int finalSequence[5] = {SHADOW, GROWTH, LIGHT, GRAVITY, PROJECTION};
int currentFinalStep = 0;
```

### Stage 3 interaction logic

```cpp
if (nearFinalSwitch(i) && key == 'e') {
    if (switchSymbol[i] == finalSequence[currentFinalStep]) {
        currentFinalStep++;
    } else {
        currentFinalStep = 0;
        shakeCoreMore();
    }
}
```

### Final solving condition

```cpp
if (currentFinalStep == 5) {
    gameWon = true;
}
```

### Reality Core animation

Before solved:

```cpp
coreX = baseX + sin(globalTime * 10.0f) * 0.2f;
coreY = baseY + sin(globalTime * 7.0f) * 0.2f;
```

After solved:

```cpp
coreX = baseX;
coreY = baseY;
```

### Final win screen

```text
REALITY RESTORED
RUET SAVED
```

### Course concept explanation

This final level combines transformation, lighting, animation, interaction, and puzzle state management. The force-balance is visual/symbolic, not a full physics simulation.

---

# 15. Level Summary Table

| Level | Name | Area | Concept | Puzzle Type | Implementation Difficulty |
|---|---|---|---|---|---|
| 1 | Frozen Sundial | Hall | Shadow + rotation | Align shadows | Easy |
| 2 | Fibonacci Garden | Hall garden | Scaling + sequence | Tree activation order | Easy |
| 3 | Road in Reflection | Central road | Reflection + rotation | Choose correct angle | Easy/Medium |
| 4 | Library Prism Lock | Library | RGB + light beams | Align mirrors | Medium |
| 5 | False Gravity Pendulum | Library | Gravity direction | Activate generator | Medium |
| 6 | Inverse-Square Lamp | Library-CSE path | Light attenuation | Set distances | Medium |
| 7 | Prime Clock Gate | CSE gate | Prime numbers | Activate prime markers | Medium |
| 8 | Anamorphic Projection | CSE corridor | Perspective/viewpoint | Stand at correct viewpoint | Medium/Hard |
| 9 | Resonance Bridge | CSE rooftop | Sine wave/phase | Synchronize platforms | Hard |
| 10 | Reality Core | HPCL lab | Force + light + sequence | Multi-stage final | Hard |

---

# 16. Required Drawing Functions

Codex should implement these drawing functions:

```cpp
void drawGround();
void drawRoads();
void drawSherEBanglaHall();
void drawLibrary();
void drawCSEDepartment();
void drawHPCLLab();
void drawTree(float x, float z, float scale);
void drawLamp(float x, float z);
void drawPlayer();
void drawHUD();
void drawSkyTimer();
void drawRealityFragment(float x, float y, float z);
void drawPortal(float x, float y, float z);
void drawBlackHole(float x, float y, float z);
void drawWhiteHole(float x, float y, float z);
```

Puzzle-specific functions:

```cpp
void drawLevel1Sundial();
void drawLevel2FibonacciGarden();
void drawLevel3ReflectionRoad();
void drawLevel4PrismLock();
void drawLevel5Pendulum();
void drawLevel6LampCorridor();
void drawLevel7PrimeClock();
void drawLevel8AnamorphicCorridor();
void drawLevel9ResonanceBridge();
void drawLevel10RealityCore();
```

---

# 17. Required Update Functions

```cpp
void updateGame(float dt);
void updatePlayer(float dt);
void updateCamera();
void updateAnimations(float dt);
void updateCurrentLevel(float dt);
void checkCollisions();
void checkInteractions();
void completeLevel();
void restartCurrentLevel();
void resetGame();
```

---

# 18. Suggested File Structure

If using multiple files:

```text
RUET_Rift/
│
├── main.cpp
├── player.h
├── player.cpp
├── world.h
├── world.cpp
├── levels.h
├── levels.cpp
├── collision.h
├── collision.cpp
├── ui.h
├── ui.cpp
└── README.md
```

If Codex has difficulty with multiple files, use one file first:

```text
main.cpp
```

Recommended for first working version: **single-file first**, then refactor.

---

# 19. Minimal Version First

Codex should first build the MVP before adding all polish.

## MVP must include:

1. OpenGL window
2. Ground and simple map
3. Hall, Library, CSE, HPCL areas
4. Player model
5. WASD movement
6. Third-person camera
7. Top-view camera
8. HUD
9. Level system
10. 10 puzzle states
11. One fragment per level
12. Final win state

## MVP puzzle implementation can be simplified:

- Level 1: pillar angle checks
- Level 2: tree sequence checks
- Level 3: switch angle check
- Level 4: mirror angle checks
- Level 5: generator state check
- Level 6: receiver distance checks
- Level 7: prime sequence checks
- Level 8: viewpoint position check
- Level 9: platform phase checks
- Level 10: cube target + final sequence checks

---

# 20. Polishing After MVP

After the full game works, add:

1. More trees and lamps
2. Floating particles around black/white holes
3. Better material colors
4. Better building shapes
5. More clue text
6. Camera smoothing
7. Simple sound if allowed, but not required
8. Start menu
9. Pause menu
10. Final cutscene animation

---

# 21. Build Commands

## Linux

```bash
g++ main.cpp -o ruet_rift -lGL -lGLU -lglut
./ruet_rift
```

If using FreeGLUT:

```bash
g++ main.cpp -o ruet_rift -lGL -lGLU -lglut
```

## Windows MinGW example

```bash
g++ main.cpp -o ruet_rift.exe -lfreeglut -lopengl32 -lglu32
ruet_rift.exe
```

---

# 22. Codex Master Prompt

Use this prompt in Codex:

```text
Build a C++ OpenGL/GLUT project named "RUET Rift: The 10-Hour Distortion".

The project must be a complete 3D puzzle-adventure game using simple OpenGL/GLUT primitives and course-level Computer Graphics concepts. Do not use external game engines, external 3D models, advanced physics libraries, or advanced shader-only rendering. The project must remain explainable for a Computer Graphics lab evaluation.

Story:
Inside RUET CSE Department's HPCL Lab, a Computer Graphics program named RealityRenderer.cpp crashed and distorted the real campus. The distortion affected Sher-e-Bangla Hall, RUET Library, CSE Department, and HPCL Lab. The sky is frozen in daylight and a timer appears: 10 HOURS REMAINING. The player must solve 10 levels, each reducing the countdown by one hour, and restore the Reality Core in HPCL Lab.

Technology:
C++ with OpenGL and GLUT/FreeGLUT. Use simple primitives: cubes, spheres, cylinders, cones, torus, flat rectangles, bitmap text. Use fixed-function lighting if convenient. Use depth testing. Use simple collision checks.

Controls:
W/A/S/D = move
Arrow keys = rotate/look
E = interact
Space = jump or activate pad
C = change camera mode
R = restart level
P = pause
Enter = start game
Esc = exit

Camera:
Implement third-person and top-view camera. First-person is optional.

Map:
Create a simplified RUET-inspired map with Sher-e-Bangla Hall, RUET Library, CSE Department, roads, trees, lamps, and HPCL Lab final room.

Game systems:
- Player movement
- Simple humanoid player model
- Collision detection using distance and AABB checks
- HUD showing level, hours remaining, objective, fragments collected, and camera mode
- Sky timer text
- Level manager for 10 levels
- E-key interaction system
- Reality Fragments, one per level
- Game states: menu, playing, paused, game won

10 Levels:
1. Frozen Sundial of Sher-e-Bangla Hall: rotate three pillar shadows so all point to the center stone. Concept: shadow/rotation.
2. Fibonacci Garden: activate scaled trees in Fibonacci order 1,1,2,3,5,8. Concept: scaling/math pattern.
3. Road That Rotates Only in Reflection: choose correct rotation switch based on reflection clue. Concept: reflection/rotation.
4. Library Prism Lock: rotate RGB mirrors so red, green, blue beams hit the prism and make white light. Concept: RGB additive color/light.
5. Pendulum of False Gravity: activate correct gravity generator so pendulum points to correct direction. Concept: gravity direction/rotation.
6. Inverse-Square Lamp Corridor: set receivers at distances 2,3,4 for brightness 1/4,1/9,1/16. Concept: light attenuation.
7. Prime Clock of the CSE Gate: activate clock markers 2,3,5,7,11 in order; 1 is a trap. Concept: prime numbers/circular placement.
8. Anamorphic Projection Corridor: stand at the correct viewpoint and face symbols to reveal hidden word CORE. Concept: perspective/viewing.
9. Resonance Bridge: synchronize oscillating platforms by changing their phase until all phases become 0. Concept: sine wave animation/phase.
10. Three-Body Reality Core: final HPCL puzzle. Stage 1: place/activate three cubes on target marks to balance the core. Stage 2: light reveals sequence Shadow -> Growth -> Light -> Gravity -> Projection. Stage 3: activate final switches in that order to win.

Implementation requirements:
- Use clear functions: drawGround, drawRoads, drawHall, drawLibrary, drawCSEDepartment, drawHPCLLab, drawTree, drawLamp, drawPlayer, drawHUD, drawSkyTimer.
- Use separate draw functions for each level.
- Use separate update/check functions for each level.
- Use structs for Player, GameObject, Level, Fragment if useful.
- Use comments heavily so the project can be explained to a teacher.
- Keep code understandable and not over-engineered.

First create a working MVP in one main.cpp. After it compiles and runs, improve visuals and polish.
```

---

# 23. Viva Explanation Script

Use this explanation during evaluation:

```text
Sir, my project is a 3D OpenGL puzzle-adventure game. The story is that a Computer Graphics program inside the HPCL Lab crashed and distorted the RUET-inspired world. The player must solve 10 puzzle levels to restore reality.

Each level is based on a graphics, math, or physics concept. For example, the first level uses shadow rotation, the second uses scaling and Fibonacci pattern, the fourth uses RGB light combination, the eighth uses perspective projection, and the ninth uses sine-wave animation.

Technically, I used OpenGL primitives for buildings, trees, roads, player, lamps, portals, and puzzle objects. I used transformations such as translation, rotation, and scaling to create distorted objects. I used gluLookAt for camera control, depth testing for 3D visibility, lighting/materials for visual effect, and simple collision detection for interaction.

The project remains within Computer Graphics syllabus topics: primitives, transformations, viewing, projection, clipping/boundary, lighting, shading, color, animation, and interaction.
```

---

# 24. Final Submission Feature Checklist

Before final lab evaluation, confirm:

- [ ] Project compiles without error.
- [ ] Player can move using W/A/S/D.
- [ ] Camera works.
- [ ] HUD works.
- [ ] Level number updates.
- [ ] Countdown updates after each level.
- [ ] All 10 puzzles can be solved.
- [ ] Player can interact using E.
- [ ] Final win state appears.
- [ ] No puzzle becomes impossible.
- [ ] Controls are shown in HUD.
- [ ] The project has a clear story.
- [ ] You can explain all graphics concepts used.

---

# 25. Important Design Reminder

The project must look creative, but the code must look believable for a CSE 4201/CSE 4202 Computer Graphics lab project.

So the final rule is:

```text
Make the idea mysterious.
Make the implementation simple.
Make the explanation course-based.
```

