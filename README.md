# ⚡ Pure Sine Wave Inverter — PIC16F877A + IGBT

> A hardware power electronics project that generates a pure sine wave AC output from a DC source using Sinusoidal PWM (SPWM) — designed, simulated in Proteus, and built on a custom PCB.

---

## 🎯 Project Overview

This project implements a **Pure Sine Wave Power Inverter** capable of delivering close to **200W** of output power. The inverter converts DC input into a clean sinusoidal AC waveform using a **Sinusoidal Pulse Width Modulation (SPWM)** technique implemented on a **PIC16F877A microcontroller**.

The circuit was designed collaboratively as a 4th-year undergraduate electronics project at Tishreen University, covering everything from firmware to PCB layout.

---

## 🔬 How It Works

### Sinusoidal PWM (SPWM) — `SPWM.c`

The core of the inverter is a precomputed **32-sample sine wave lookup table**:

```c
short int sine[32] = {0,25,49,73,96,118,137,159,177,193,208,220,
                       231,239,245,249,250,249,245,239,231,220,208,
                       193,177,159,137,118,96,73,49,25};
```

A **Timer0 interrupt** fires at a fixed interval (TMR0 = 216), stepping through the sine table and alternately feeding each half-cycle to **PWM1** and **PWM2** outputs. This drives two complementary switching paths:

| Phase | PWM Active | Effect |
|-------|-----------|--------|
| Positive half-cycle | PWM1 | Drives first IGBT pair |
| Negative half-cycle | PWM2 | Drives second IGBT pair |

The result at the H-bridge output is a stepped approximation of a full sine wave at the desired AC frequency.

### Feedback Loop
- A **Full Bridge Rectifier** on the output converts AC → DC
- The rectified voltage is fed back into the ADC of the PIC to measure peak voltage (Vmax)
- This enables closed-loop regulation of output amplitude

---

## 📁 Repository Structure

```
├── src/
│   ├── SPWM.c                  # PIC16F877A firmware (MikroC)
│   ├── Inverter Simulation.pdsprj  # Proteus simulation project
│   └── SPWM2.mcppi             # MikroC project file
└── images/
    ├── Full Circuit.jpg         # Complete assembled circuit photo
    ├── PCB Schematic.png        # Eagle PCB schematic
    └── PCB Board/               # PCB layout files
```

---

## 🔧 Key Components

| Component | Role |
|-----------|------|
| PIC16F877A | Main microcontroller — generates SPWM signals |
| IGBT Transistors | High-power switching elements |
| Full Bridge Rectifier | Output voltage feedback |
| Eagle PCB | Custom PCB design for the circuit |
| Proteus | Full circuit simulation before hardware build |

---

## 🚀 Getting Started

### Simulation
1. Open `src/Inverter Simulation.pdsprj` in **Proteus**
2. Run the simulation to observe SPWM waveforms and output voltage

### Firmware
1. Open `src/SPWM2.mcppi` in **MikroC for PIC**
2. Compile and flash `SPWM.c` to a PIC16F877A via a PIC programmer

### PCB
- PCB schematic available in `images/PCB Schematic.png`
- Layout files in `images/PCB Board/` (designed in Eagle)

---

## ⚠️ Safety Note

This project operates with **mains-level voltages**. Do not attempt to build or test the hardware without proper electrical safety training and equipment.

---

## 🛠️ Tech Stack

![C](https://img.shields.io/badge/C-MikroC%20for%20PIC-blue?logo=c)
![Proteus](https://img.shields.io/badge/Proteus-Simulation-yellow)
![Eagle](https://img.shields.io/badge/Eagle-PCB%20Design-red)
![PIC](https://img.shields.io/badge/PIC16F877A-Microcontroller-green)

---

## 👤 Author

**Baher Kherbek** — Robotics Engineer & AI Systems Developer  
[github.com/Baher-Kherbek](https://github.com/Baher-Kherbek)
