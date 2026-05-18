# SentientAgents

An advanced AI-focused Unreal Engine team project where you have to collaborate to build intelligent NPC agents with dynamic behaviors, perception systems, combat logic, interaction mechanics, and modular gameplay architecture.

---

# Overview

**SentientAgents** is a collaborative Unreal Engine project designed to simulate the development workflow of a real gameplay/AI team.

The goal is to create multiple AI agents capable of reacting differently depending on:

- What they **see**
- What they **hear**
- Their internal **state**
- Their current **goals**
- Their **health**
- Player interactions
- Environmental stimuli

The project emphasizes:

- Modular gameplay architecture
- Parallel team development
- Communication systems between gameplay modules
- AI programming best practices
- Unreal Engine gameplay framework usage

The implementation must follow the provided **Game Design Document (GDD)**.

---

# Core Features

## AI Perception System

Agents must react dynamically using Unreal's AI Perception framework.

### Required Perception Types

- Sight
- Hearing
- Damage (optional bonus)

### Expected Behaviors

Examples:

- Patrol while idle
- Chase player when spotted
- Investigate sounds
- Return to patrol after losing target
- Alert nearby allies
- Flee when low on health
- Become aggressive or defensive depending on archetype

---

## Behavior Trees & Blackboards

Each AI archetype must use:

- Behavior Trees
- Blackboard keys
- Tasks
- Services
- Decorators

### Example Blackboard Data

- Current Target
- Last Known Location
- Is Alerted
- Has Weapon
- Health State
- Current Patrol Point

### Goal

Create reusable and scalable AI logic.

---

## Health Component

Implement a modular `HealthComponent` that can be attached to:

- AI agents
- Players
- Destructible actors

### Required Features

- Damage handling
- Healing
- Death events
- Event broadcasting
- UI updates
- Optional armor/resistance system

### Architecture Requirement

The component must communicate using:

- Delegates
- Event Dispatchers
- Interfaces where appropriate

---

## Interaction System

Create a flexible interaction framework.

### Examples

- Pick up items
- Open doors
- Activate switches
- Loot containers
- Talk to NPCs

### Requirements

- Use Interfaces for interactable actors
- Reusable interaction traces
- Context-sensitive prompts
- Multiplayer-safe architecture preferred

---

## Inventory System

Design a modular inventory system.

### Suggested Features

- Add/remove items
- Stackable items
- Equipment slots
- Consumables
- Weapons
- Inventory UI

### Bonus

- DataTables
- Save/Load support
- Drag & Drop UI

---

## Animation System

Create believable character behaviors through animation.

### Required Features

- Animation Blueprints
- State Machines
- Blendspaces
- Montages
- Hit reactions
- Death animations

### AI Animation Examples

- Idle
- Walk
- Run
- Attack
- Alert
- Investigate
- Flee

---

# Team Collaboration Requirements

This project is intentionally structured for **parallel development**.

You are expected to divide responsibilities into specialized gameplay areas.

---

# Suggested Team Roles

## AI Programmer

Responsible for:

- Behavior Trees
- Blackboard logic
- AI Controllers
- Perception systems
- Decision making

---

## Gameplay Programmer

Responsible for:

- Health system
- Interaction framework
- Inventory system
- Weapons/items
- Gameplay architecture

---

## Animation Programmer / Technical Animator

Responsible for:

- Animation Blueprints
- State Machines
- Montages
- Animation integration
- IK systems (optional)

---

## UI Programmer

Responsible for:

- HUD
- Inventory UI
- Health bars
- Interaction prompts
- Debug interfaces

---

## Level Designer

Responsible for:

- Patrol areas
- AI encounter spaces
- Environmental storytelling
- Gameplay testing spaces

---

# Technical Requirements

## Mandatory Unreal Systems

You must must use:

- Components
- Interfaces
- Event Dispatchers
- Delegates
- Blueprint communication
- Gameplay Framework classes
- AI Perception
- Navigation System
- Behavior Trees
- Blackboards

---

# Architecture Guidelines

## Modularity

Systems must be reusable and decoupled.

Avoid hard references whenever possible.

Preferred communication methods:

- Interfaces
- Delegates
- Event Dispatchers

---

## Scalability

Design systems that support:

- Multiple AI archetypes
- Future gameplay expansion
- Additional weapons/items
- New interaction types

---

## Clean Code

Expected practices:

- Clear naming conventions
- Organized Blueprints
- Commented logic
- Reusable functions
- Separation of responsibilities

---

# Example AI Archetypes

## Guard

- Patrols predefined points
- Chases intruders
- Calls allies when alerted

---

## Scout

- Fast movement
- Large vision range
- Weak combat abilities

---

## Berserker

- Aggressive melee attacker
- Ignores low-level threats
- Enters rage mode at low HP

---

## Civilian

- Non-combatant
- Runs away from danger
- Can trigger alarms

---

# Development Goals

By the end of the project, you should demonstrate:

- Advanced Unreal Engine architecture knowledge
- Team collaboration workflow
- AI gameplay programming
- Event-driven systems
- Modular gameplay design
- Debugging and optimization skills

---

# Suggested Folder Structure

```text
Content/
│
├── AI/
│   ├── BehaviorTrees/
│   ├── Blackboards/
│   ├── Controllers/
│   ├── Tasks/
│   ├── Services/
│   └── Decorators/
│
├── Characters/
│   ├── Player/
│   └── Enemies/
│
├── Components/
│   ├── Health/
│   ├── Inventory/
│   └── Interaction/
│
├── Interfaces/
│
├── UI/
│
├── Animations/
│
├── Weapons/
│
└── Levels/
```

---

# Recommended Workflow

## Git Workflow

- Use branches
- Create pull requests
- Avoid committing directly to main
- Write meaningful commit messages

Example:

```bash
feature/ai-perception
feature/inventory-system
feature/interaction-framework
```

---

# Deliverables

## Minimum Requirements

- At least 3 unique AI archetypes
- Fully functional perception system
- Behavior Trees + Blackboards
- Health system
- Interaction system
- Inventory system
- Animation integration
- Team collaboration evidence

---

# Bonus Features

Optional advanced systems:

- Squad AI
- Dynamic cover system
- EQS
- Save system
- Multiplayer support
- Procedural patrols
- Advanced combat AI
- Dialogue system
- Faction relationships

---

# Final Goal

The objective is not only to create intelligent NPCs, but also to simulate a real-world gameplay programming pipeline where multiple developers work simultaneously on interconnected systems using scalable and maintainable architecture.
