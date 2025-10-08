# Control de un Robot
Proyecto académico enfocado en el **control de un brazo robótico** mediante un **microcontrolador ESP32**. El sistema puede operar en **modo manual** (con joysticks) o en **modo automático**, mediante parámetros enviados desde **Python**.

---

## 🧩 Resumen

El proyecto implementa un sistema de control para un **robot de acrílico con 4 servomotores SG90**, controlado por un **ESP32**.

* En **modo manual**, dos joysticks permiten manipular las articulaciones del brazo.
* En **modo automático**, el robot ejecuta movimientos preprogramados definidos desde Python.

Los principales objetivos incluyen el diseño electrónico, la programación del microcontrolador y la integración con Python para el control remoto.

---

## 🎯 Objetivos

### Objetivo General

Desarrollar un sistema de control para un brazo robótico de acrílico basado en ESP32, capaz de operar manual y automáticamente.

### Objetivos Específicos

* Definir entradas, salidas y materiales. 
* Diseñar la etapa de potencia.
* Programar el ESP32 para el modo manual.
* Conectar el microcontrolador con Python.
* Programar el modo automático en Python.

---

## 🛠️ Materiales

### Hardware

* ESP32 (puerto USB-C)
* Brazo robótico de acrílico (4 DOF)
* 4 Servomotores SG90 (9g, 2.5 kg·cm torque, 4.8 – 6.5 V)
* 2 Joysticks XY KY-023
* 4 Pilas AA de 1.2 - 1.5 Volts

### Software

* Arduino IDE
* Python 3

---

## 🧠 Introducción

El servomotor **SG90** opera con señal **PWM** para controlar su ángulo.
El brazo robótico de acrílico emplea 4 servos con rangos de movimiento distintos:

| Servomotor | Ángulo mínimo | Ángulo máximo |
| ---------- | ------------- | ------------- |
| 1          | 0°            | 180°          |
| 2          | 0°            | 120°          |
| 3          | 0°            | 100°          |
| 4          | 0°            | 180°          |


## 📂 Información adicional

Autor: **Sobrevilla Zarazúa Jorge Alejandro**
Proyecto: **Control de un Robot**
Licencia: MIT (opcional)
