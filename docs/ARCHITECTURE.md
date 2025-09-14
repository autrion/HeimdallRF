# HeimdallRF – System Architecture

```mermaid
flowchart TD

    subgraph PWR[Power System]
        BATT[18650 Li-ion]
        CHG[TP4056 Charger]
        BOOST[Boost Converter 5V]
        LDO[LDO Regulator 3.3V]
    end

    subgraph MCU[Main Control Unit]
        ESP[ESP32-S3 MCU]
        OLED[OLED Display 128x64]
        BTN[User Buttons]
        BUZZ[Buzzer]
        USB[USB-CDC Logging]
    end

    subgraph RF[RF Frontends]
        SX1276[SX1276 868/915 MHz LoRa]
        SX1280[SX1280 2.4 GHz LoRa]
        AD8318[AD8318 Log Detector 5.8 GHz]
        SAW[5.8 GHz SAW Filter]
    end

    subgraph ANT[Antennas]
        ANT868[868/915 MHz SMA Antenna]
        ANT24[2.4 GHz Antenna]
        ANT58[5.8 GHz Patch Antenna]
    end

    %% Connections
    BATT --> CHG --> BOOST --> LDO --> ESP
    ESP <--> OLED
    ESP <--> BTN
    ESP --> BUZZ
    ESP <--> USB

    ESP <--> SX1276
    ESP <--> SX1280
    ESP <--> AD8318
    AD8318 --> SAW

    SX1276 <--> ANT868
    SX1280 <--> ANT24
    AD8318 <--> ANT58
