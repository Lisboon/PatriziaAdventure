<div align="center">

# 🗡️ Patrizia Adventure

### A Third-Person Action RPG Built with Unreal Engine 5.7

[![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-5.7-313131?style=for-the-badge&logo=unreal-engine&logoColor=white)](https://www.unrealengine.com/)
[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.cppreference.com/)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

*An immersive action-adventure game featuring dynamic combat, responsive character controls, and engaging enemy encounters.*

[Features](#-features) • [Technical Details](#-technical-details) • [Getting Started](#-getting-started) • [Roadmap](#-roadmap) • [About](#-about-the-developer)

---

</div>

## 🎮 Overview

**Patrizia Adventure** is a third-person action RPG that combines fluid character movement with engaging combat mechanics. Built from the ground up using C++ and Unreal Engine 5.7, this project showcases modern game development practices, including the Enhanced Input System, component-based architecture, and modular character design.

The game follows Patrizia, a brave warrior navigating through dangerous lands filled with menacing enemies like the Necromancer. Players will experience responsive controls, dynamic camera systems, and action-packed combat.

## ✨ Features

### 🎯 Core Gameplay
- **Third-Person Camera System** - Smooth spring arm camera with full rotation support
- **Responsive Movement** - Controller-relative movement with orientation to movement direction
- **Dynamic Crouch System** - Hold-to-crouch mechanics with visual feedback
- **Combat Ready** - Weapon socket system prepared for melee combat implementation

### 🕹️ Input System
- **Enhanced Input System** - Modern UE5 input mapping for precise controls
  - `WASD` / Left Stick - Movement
  - `Mouse` / Right Stick - Look/Aim
  - `Space` / Button A - Jump
  - `Shift` / Button B - Sprint
  - `Ctrl` / Button X - Crouch

### 👾 Characters
- **Patrizia (Player Character)** - Main protagonist with full movement capabilities
- **Necromancer (Enemy)** - Base enemy class ready for AI behavior implementation

### ⚙️ Technical Features
- **Modular Architecture** - Clean separation between character logic, input, and components
- **Blueprint Integration** - C++ base classes extended with Blueprints for rapid iteration
- **Niagara VFX Support** - Ready for particle effects integration
- **Skeletal Mesh Weapons** - Proper socket-based weapon attachment system

## 🔧 Technical Details

### Architecture

```
PatriziaAdventure/
├── Source/
│   └── PatriziaAdventure/
│       ├── Private/Character/
│       │   ├── PatriziaCharacter.cpp    # Player character implementation
│       │   └── PatriziaEnemy.cpp        # Enemy base class
│       └── Public/Character/
│           ├── PatriziaCharacter.h      # Player character interface
│           └── PatriziaEnemy.h          # Enemy interface
├── Content/_Game/
│   ├── Blueprints/Characters/           # Character Blueprints
│   │   ├── Patrizia/                    # Player BP & assets
│   │   └── Necromancer/                 # Enemy BP & animations
│   └── Input/                           # Input Actions & Mappings
│       ├── IA_Move.uasset
│       ├── IA_Look.uasset
│       ├── IA_Jump.uasset
│       ├── IA_Sprint.uasset
│       ├── IA_Crouch.uasset
│       └── IMC_Patrizia.uasset
└── Config/                              # Engine configuration
```

### Key Technologies

| Technology | Usage |
|------------|-------|
| **Unreal Engine 5.7** | Game Engine |
| **C++17** | Core gameplay logic |
| **Enhanced Input System** | Modern input handling |
| **Niagara** | Visual effects system |
| **Blueprints** | Rapid prototyping & iteration |

### Code Highlights

#### Character Movement System
```cpp
void APatriziaCharacter::Move(const FInputActionValue& InValue)
{
    FVector2D InputValue = InValue.Get<FVector2D>();
    FRotator ControlRot = GetControlRotation();
    ControlRot.Pitch = 0.0f;

    // Forward/Backward movement relative to camera
    AddMovementInput(ControlRot.Vector(), InputValue.X);
    
    // Strafe movement
    FVector RightDirection = ControlRot.RotateVector(FVector::RightVector);
    AddMovementInput(RightDirection, InputValue.Y);
}
```

#### Enhanced Input Binding
```cpp
void APatriziaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    
    EnhancedInput->BindAction(Input_Move, ETriggerEvent::Triggered, this, &APatriziaCharacter::Move);
    EnhancedInput->BindAction(Input_Look, ETriggerEvent::Triggered, this, &APatriziaCharacter::Look);
    EnhancedInput->BindAction(Input_Crouch, ETriggerEvent::Started, this, &APatriziaCharacter::HandleCrouch);
    EnhancedInput->BindAction(Input_Crouch, ETriggerEvent::Completed, this, &APatriziaCharacter::HandleUnCrouch);
}
```

## 🚀 Getting Started

### Prerequisites
- **Unreal Engine 5.7** (or later)
- **Visual Studio 2022** with C++ Game Development workload
- **Git** for version control

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/Lisboon/PatriziaAdventure.git
   ```

2. **Generate project files**
   - Right-click `PatriziaAdventure.uproject`
   - Select "Generate Visual Studio project files"

3. **Open in Unreal Engine**
   - Double-click `PatriziaAdventure.uproject`
   - Or open via Unreal Engine launcher

4. **Build and Play**
   - Press `Ctrl+Shift+B` to build
   - Press `Alt+P` to play in editor

## 🗺️ Roadmap

### Phase 1: Core Systems ✅
- [x] Character movement and camera system
- [x] Enhanced Input System integration
- [x] Crouch mechanics
- [x] Basic project structure

### Phase 2: Combat System 🔄
- [ ] Melee attack system
- [ ] Combo system
- [ ] Damage and health systems
- [ ] Hit reactions and animations

### Phase 3: Enemy AI 📋
- [ ] Necromancer AI behavior tree
- [ ] Enemy patrol and detection
- [ ] Combat AI states
- [ ] Boss mechanics

### Phase 4: World & Polish 📋
- [ ] Level design
- [ ] Environmental storytelling
- [ ] Sound design
- [ ] Visual effects polish

## 📸 Screenshots

<!-- Add your gameplay screenshots here -->
*Screenshots coming soon - Game development in progress!*

<!-- 
To add screenshots, use:
![Description](path/to/screenshot.png)
-->

## 👨‍💻 About the Developer

<div align="center">

**Wendel Lisboa**

*Junior Game Developer | Software Engineer | Aspiring AAA Developer*

</div>

I'm a passionate **26-year-old software developer** with a burning dream: to create unforgettable gaming experiences at **CD PROJEKT RED**. Games like *The Witcher 3* and *Cyberpunk 2077* didn't just entertain me—they inspired me to pursue game development as a career.

### 🎯 My Journey
- 💻 Building strong foundations in **C++** and **Unreal Engine**
- 🎮 Learning game development by creating projects from scratch
- 📚 Continuously studying game design patterns and best practices
- 🌟 Dreaming of contributing to the next legendary RPG

### 🔗 Connect With Me

[![GitHub](https://img.shields.io/badge/GitHub-Lisboon-181717?style=for-the-badge&logo=github)](https://github.com/Lisboon)
<!-- Add your LinkedIn profile URL below -->
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0A66C2?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/YOUR-PROFILE/)

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

<div align="center">

**Made with ❤️ and lots of ☕**

*"Bad decisions make good stories" - The Witcher 3*

⭐ Star this repo if you like it!

</div>