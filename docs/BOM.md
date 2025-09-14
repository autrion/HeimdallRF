# HeimdallRF – Bill of Materials (BOM)

This document lists the key components required for the HeimdallRF v0.1 prototype.  
Future revisions may optimize part selection for cost, size, and performance.

---

## 🔧 Core Components
| Qty | Part | Description | Example Part No. / Link |
|-----|------|-------------|--------------------------|
| 1 | **ESP32-S3 Module** | Main MCU, Wi-Fi + BLE, good RAM/USB support | ESP32-S3-WROOM-1-N8R8 |
| 1 | **SX1276 LoRa Module** | 868/915 MHz band detection (Crossfire, LRS) | HopeRF RFM95W-868S2 |
| 1 | **SX1280 LoRa Module** | 2.4 GHz band detection (ELRS) | Semtech SX1280IMLTRT |
| 1 | **AD8318 Log Detector** | RF power detection for 1–8 GHz (used for 5.8 GHz FPV video) | Analog Devices AD8318ACPZ |
| 1 | **5.8 GHz SAW Filter** | Bandpass filter for AD8318 front-end | Murata SAFEA1G58FA0F00R15 |

---

## 📟 User Interface
| Qty | Part | Description | Example Part No. |
|-----|------|-------------|------------------|
| 1 | **OLED Display** | 1.3" I²C, 128×64 px | SSD1306 or SH1106 module |
| 3 | **Tactile Buttons** | User input (menu, select, back) | Standard 6×6 mm tact switches |
| 1 | **Buzzer (Piezo)** | Audible alerts | 3.3 V passive buzzer |

---

## 🔋 Power
| Qty | Part | Description | Example Part No. |
|-----|------|-------------|------------------|
| 1 | **Li-ion Cell 18650** | Power source | Any protected 18650 cell |
| 1 | **TP4056 Charger** | Li-ion charging module, micro-USB or USB-C | TP4056 + DW01A |
| 1 | **Boost Converter** | 5V output from Li-ion | MT3608 |
| 1 | **LDO Regulator** | 3.3V clean supply for RF chips | AMS1117-3.3 or AP2112K |

---

## 📡 Antennas
| Qty | Part | Description | Example Part No. |
|-----|------|-------------|------------------|
| 1 | **868/915 MHz Antenna** | SMA whip, 2 dBi | Generic 868 MHz SMA whip |
| 1 | **2.4 GHz Antenna** | PCB or u.FL whip | ESP32 antenna or u.FL whip |
| 1 | **5.8 GHz Patch Antenna** | Directional FPV-style | 5.8 GHz RHCP patch antenna |

---

## ⚙️ Miscellaneous
| Qty | Part | Description |
|-----|------|-------------|
| – | **3D-printed enclosure** | Custom case for PCB + display + battery |
| – | **Connectors / headers** | SMA edge connectors, JST battery connector, pin headers |
| – | **Passive components** | Resistors, capacitors, inductors for matching networks |

---

## 💰 Estimated BOM Cost
- Small-batch (10–20 pcs): ~55–70 EUR per unit  
- Larger batch (50+ pcs): ~40–50 EUR per unit

---

**Note:** This BOM is for **prototype v0.1**. Final production BOM will be optimized for cost, size, and certification requirements.
