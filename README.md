# ESPHome BLE Client for Powerdale Nexxtender EV Charger

This repository contains an ESPHome BLE client for interfacing with the Powerdale Nexxtender EV Charger. The client allows you to seamlessly integrate the Nexxtender charger with your ESPHome projects, enabling you to monitor and control the charger remotely via Bluetooth Low Energy (BLE). Additionally, it integrates smoothly with Home Assistant, providing a convenient interface for managing your Nexxtender charger within your home automation setup.

[![maintainer](https://img.shields.io/badge/maintainer-Geert%20Meersman-green?style=for-the-badge&logo=github)](https://github.com/geertmeersman)
[![buyme_coffee](https://img.shields.io/badge/Buy%20me%20a%20Duvel-donate-yellow?style=for-the-badge&logo=buymeacoffee)](https://www.buymeacoffee.com/geertmeersman)
[![discord](https://img.shields.io/discord/1094331679327408320?style=for-the-badge&logo=discord)](https://discord.gg/PTpExQJsWA)

[![MIT License](https://img.shields.io/github/license/geertmeersman/nexxtender?style=flat-square)](https://github.com/geertmeersman/nexxtender/blob/master/LICENSE)
[![github last-commit](https://img.shields.io/github/last-commit/geertmeersman/nexxtender)](https://github.com/geertmeersman/nexxtender/commits)
[![github contributors](https://img.shields.io/github/contributors/geertmeersman/nexxtender)](https://github.com/geertmeersman/nexxtender/graphs/contributors)
[![github commit activity](https://img.shields.io/github/commit-activity/y/geertmeersman/nexxtender?logo=github)](https://github.com/geertmeersman/nexxtender/commits/main)

[![ESPHOME Build action](https://github.com/geertmeersman/nexxtender/actions/workflows/esphome_build.yaml/badge.svg)](https://github.com/geertmeersman/nexxtender/actions/workflows/esphome_build.yaml)

## Features

- **BLE Connectivity:** Establish a BLE connection between your ESPHome device and the Powerdale Nexxtender EV Charger for data exchange and control.

- **Real-time Monitoring:** Retrieve real-time data from the Nexxtender charger, including charging status, voltage, current, and power consumption.

- **Remote Control:** Control the Nexxtender charger remotely from your ESPHome device, enabling features such as starting, stopping, and scheduling charging sessions.

- **Home Assistant Integration:** Seamlessly integrate the ESPHome BLE client with Home Assistant, allowing you to monitor and control the Nexxtender charger through the Home Assistant interface.

## Screenshots

### Lovelace card

![lovelace](https://raw.githubusercontent.com/geertmeersman/nexxtender/main/images/lovelace.png)
![lovelace-aansluiten](https://raw.githubusercontent.com/geertmeersman/nexxtender/main/images/aansluiten.png)

### Controls

![bediening](https://raw.githubusercontent.com/geertmeersman/nexxtender/main/images/bediening.png)

### Sensors

![sensors_1](https://raw.githubusercontent.com/geertmeersman/nexxtender/main/images/sensors_1.png)
![sensors_2](https://raw.githubusercontent.com/geertmeersman/nexxtender/main/images/sensors_2.png)

### Diagnostics

![diagnose](https://raw.githubusercontent.com/geertmeersman/nexxtender/main/images/diagnose.png)

## Table of contents

- [ESPHome BLE Client for Powerdale Nexxtender EV Charger](#esphome-ble-client-for-powerdale-nexxtender-ev-charger)
  - [Features](#features)
  - [Screenshots](#screenshots)
    - [Lovelace card](#lovelace-card)
    - [Controls](#controls)
    - [Sensors](#sensors)
    - [Diagnostics](#diagnostics)
  - [Table of contents](#table-of-contents)
  - [Getting Started](#getting-started)
    - [Finding Nexxtender Bluetooth MAC Address with NRF Connect App](#finding-nexxtender-bluetooth-mac-address-with-nrf-connect-app)
    - [Installing \& Configuring ESPHome](#installing--configuring-esphome)
      - [Customizing ESP32 Configuration (Optional)](#customizing-esp32-configuration-optional)
  - [Integrating ESPHome Devices with Home Assistant](#integrating-esphome-devices-with-home-assistant)
  - [Contributing](#contributing)
  - [License](#license)
  - [Support](#support)

## Getting Started

To integrate the ESPHome BLE client with your Powerdale Nexxtender EV Charger and Home Assistant, follow these steps:

### Finding Nexxtender Bluetooth MAC Address with NRF Connect App

Before integrating your Nexxtender EV Charger with the ESPHome BLE client, you'll need to find its Bluetooth MAC address. You can do this using the NRF Connect app, available for both Android and iOS devices. Follow these steps:

1. **Download and Install NRF Connect**: Go to the Google Play Store (for Android) or the Apple App Store (for iOS) and search for "NRF Connect." Download and install the app on your mobile device.

2. **Open NRF Connect**: Launch the NRF Connect app on your mobile device.

3. **Scan for BLE Devices**: In the NRF Connect app, navigate to the "Scanner" tab and start scanning for nearby Bluetooth devices.

4. **Locate Nexxtender EV Charger ("HOME")**: The charger's Bluetooth module should broadcast its presence with the name "HOME," allowing NRF Connect to detect it.

5. **View Device Details**: Once NRF Connect detects the Nexxtender EV Charger, tap on it to view its details. Among the information displayed, you'll find the Bluetooth MAC address (also known as the BD_ADDR) of the charger.

6. **Note MAC Address**: Make a note of the Bluetooth MAC address of your Nexxtender EV Charger. You'll need this MAC address when configuring the ESPHome BLE client.

By following these steps, you can easily find the Bluetooth MAC address of your Nexxtender EV Charger named "HOME" using the NRF Connect app.

### Installing & Configuring ESPHome

1. **Install ESPHome:** If you haven't already, install ESPHome by following the instructions [here](https://esphome.io/guides/getting_started_command_line.html#installation-step).

2. **Create a new ESPHome Configuration:** Create a new file named `nexxtender.yaml` in your local directory. Copy and paste the contents of the provided `nexxtender.yaml` into this file (or copy/paste the below yaml).

   ```yaml
   packages:
      nexxtender: 
         url: https://github.com/geertmeersman/nexxtender
         file: config/nexxtender.yaml
         refresh: 1d
  
   substitutions:
      device_name: nexxtender
      friendly_name: Nexxtender
      update_interval: 60s
   ```

3. **Update the secrets.yaml:**

   Ensure that your `secrets.yaml` file contains the following entries:

   ```yaml
   esphome_admin_password: "YOUR_ESPHOME_ADMIN_PASSWORD"
   wifi_ssid: "YOUR_WIFI_SSID"
   wifi_password: "YOUR_WIFI_PASSWORD"
   esphome_api_key: "YOUR_ESPHOME_API_KEY"
   nexxtender_mac: "YOUR_NEXXTENDER_MAC_ADDRESS"
   nexxtender_passkey: "YOUR_NEXXTENDER_PASSKEY"
   ```

   Replace `"YOUR_ESPHOME_ADMIN_PASSWORD"`, `"YOUR_WIFI_SSID"`, `"YOUR_WIFI_PASSWORD"`, `"YOUR_ESPHOME_API_KEY"`, `"YOUR_NEXXTENDER_MAC_ADDRESS"`, and `"YOUR_NEXXTENDER_PASSKEY"` with your actual values.

   The `nexxtender_mac` is the bluetooth mac address you found in the previous step.

   The `nexxtender_passkey` is the PIN code you use to pair your Nexxtender. If you don't have the PIN code (or you have lost it), you can always reach out to me and I can calculate it if you provide me the serial number of the box. Format XXXXX-XX-XXXX-XXXXX-XX


   The `esphome_admin_password` is the password that is used for the wifi fallback hotspot and OTA.

   If you don't know how to define the `esphome_api_key`, you can obtain one as described [here](https://esphome.io/components/api.html) in the section Configuration variables > encryption > key.

4. **Compile Firmware:** Compile the ESPHome firmware using the `nexxtender.yaml` configuration file. Run the following command in your terminal, pointing to the location of your `nexxtender.yaml` file:

   ```bash
   esphome compile nexxtender.yaml
   ```

5. **Flash Firmware:** Flash the compiled firmware to your ESPHome device using the following command:

   ```bash
   esphome upload nexxtender.yaml
   ```

   Note: If you’re just seeing Connecting....____.... on the screen and the flashing fails, please double check the UART wires are connected correctly if flashing using a USB to UART bridge.

   For some devices you need to keep pressing the BOOT button until flashing has begun (ie. Geekcreit DOIT ESP32 DEVKIT V1).

   [Consult the FAQ part on esphome.io](https://esphome.io/guides/faq.html).

6. **Integrate with Home Assistant:** In your Home Assistant configuration, add the ESPHome device as a new integration. Follow the instructions provided by Home Assistant to discover and integrate the Nexxtender charger with your Home Assistant setup.

7. **Monitor Logs:** Monitor the ESPHome device logs to ensure that the BLE client establishes a connection with the Powerdale Nexxtender EV Charger successfully.

8. **Test Functionality:** Test the functionality of the ESPHome BLE client by monitoring real-time data from the Nexxtender charger and controlling its operation remotely from your ESPHome device or through the Home Assistant interface.

#### Customizing ESP32 Configuration (Optional)

If you want to customize the ESP32 section in your `nexxtender.yaml` file for your specific board type, you can add the following section at the end of the nexxtender.yaml:

```yaml
esp32:
  board: YOUR_ESP32_BOARD_TYPE
  framework:
    type: esp-idf
    version: recommended
```

Replace `YOUR_ESP32_BOARD_TYPE` with the specific board type you're using, such as `az-delivery-devkit-v4` or any other compatible board.

Example for the [ESP32-S3-N16R8](https://a.aliexpress.com/_EwvIgjF)

```yaml
esp32:
  board: esp32-s3-devkitc-1
  flash_size: 16MB
  framework:
    type: esp-idf
    version: recommended

esphome:
  name: ${device_name}
  friendly_name: ${friendly_name}
  platformio_options:
    board_build.flash_mode: dio  
  includes:
    - nexxtender_packages/nexxtender.h
```

This flexibility allows users to tailor the configuration to their hardware requirements while still benefiting from the overall structure and functionality provided in the `nexxtender.yaml` file.

## Integrating ESPHome Devices with Home Assistant

To integrate ESPHome devices with Home Assistant, follow these steps:

1. **Prerequisites**: Ensure you have the ESPHome integration enabled in Home Assistant. You can do this by navigating to Configuration -> Integrations, clicking the "+" button to add an integration, searching for "ESPHome," and following the instructions to set it up.

2. **Discover ESPHome Devices**: After enabling the integration, Home Assistant will automatically discover ESPHome devices on your network. If your devices don't show up automatically, you can add them manually by providing their IP address and API key.

3. **Configuration YAML**: You can also configure ESPHome devices manually by adding them to your Home Assistant configuration YAML file. This allows for more advanced configuration options and customization.

4. **View Devices**: Once your ESPHome devices are discovered or added manually, you can view and manage them in the Home Assistant UI. This includes monitoring their status, viewing sensor data, and controlling their actions.

5. **Integrate with Automations**: You can use ESPHome devices in your Home Assistant automations to trigger actions based on sensor readings, device status changes, or other events.

6. **Customization**: Home Assistant allows for extensive customization of ESPHome devices, including renaming, grouping, and organizing them to fit your home automation setup.

7. **Updates and Maintenance**: Keep your ESPHome devices up to date by regularly checking for firmware updates and configuring automatic OTA updates if desired.

8. **Lovelace dashboard card**:

   ![lovelace-card](https://raw.githubusercontent.com/geertmeersman/nexxtender/main/images/lovelace.png)

   <details><summary>Show markdown code</summary>

   The example uses the following custom lovelace cards:

   - [custom:button-card](https://github.com/custom-cards/button-card)
   - [card-mod](https://github.com/thomasloven/lovelace-card-mod)

   The images used are available in the images folder of this repository.

   In the example below they are located in your HA /config/www/images/auto/ folder.

   ```yaml
   type: vertical-stack
   cards:
   - type: picture-elements
      aspect_ratio: 2
      elements:
         - style:
            top: 180px
            left: 18%
         show_name: true
         name: |
            [[[ 
               if (entity.state > 0) return entity.state+" kWh"; 
               return "";
            ]]] 
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_basic_energy
         show_state: false
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
         - style:
            top: 200px
            left: 18%
         show_name: true
         name: |
            [[[ 
               if (entity.state > 0) return entity.state;
               return "";
            ]]] 
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_basic_seconds
         show_state: false
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
         - style:
            top: 220px
            left: 18%
         show_name: true
         name: |
            [[[ 
               if (entity.state > 0) return entity.state+" kW"; 
               return "";
            ]]] 
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_advanced_car_power
         show_state: false
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
         - style:
            top: 240px
            left: 18%
         show_name: true
         name: |
            [[[ 
               if (entity.state > 0) return entity.state+" fasen"; 
               return "";
            ]]] 
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_basic_phase_count
         show_state: false
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
         - style:
            top: 50px
            left: 73%
         show_name: false
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_connection_type
         show_state: true
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
               - color: black
         - style:
            top: 65px
            left: 73%
         show_name: true
         name: |
            [[[ return entity.state+" fasen"; ]]] 
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_phases
         show_state: false
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
               - color: black
         - style:
            top: 110px
            left: 70%
         show_name: true
         name: Pieklimiet
         layout: name_state
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_peak_consumption_limit
         show_state: true
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
               - color: black
         - style:
            top: 130px
            left: 70%
         show_name: true
         name: Beschikbaar
         layout: name_state
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_available_capacity
         show_state: true
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
               - color: black
         - style:
            top: 192px
            left: 70%
         show_name: false
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_mode
         show_state: true
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 12px
               - color: black
         - name: L1
         style:
            top: 220px
            left: 65%
         show_name: true
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_grid_l1
         show_state: true
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 10px
         - name: L2
         style:
            top: 220px
            left: 73%
         show_name: true
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_grid_l2
         show_state: true
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 10px
         - name: L3
         style:
            top: 220px
            left: 81%
         show_name: true
         show_icon: false
         type: custom:button-card
         entity: sensor.nexxtender_charging_grid_l3
         show_state: true
         styles:
            card:
               - background: none
               - border-radius: 0
               - border: 0
               - font-size: 10px
      image: /local/images/1x1.png
      card_mod:
         style: |
         ha-card {
            {%- set nexxtender_state = states["sensor.nexxtender_charging_basic_status"].state -%}
            {% if nexxtender_state == "unplugged" %}
               {% set image = 'unplugged' %}
            {% elif  nexxtender_state == "plugged" %}
               {% set image = 'plugged' %}
            {% elif  nexxtender_state == "charging" %}
               {% set image = 'charging' %}
            {% else %}
               {% set image = 'offline' %}
            {% endif %}
            background-size: 100% 100%;
            background-image: url(/local/images/auto/device_home_{{image}}.png);
            height: 300px !important;
         }
   - type: conditional
      conditions:
         - condition: state
         entity: sensor.nexxtender_charging_basic_status
         state: plugged
      card:
         show_name: true
         show_icon: false
         type: button
         tap_action:
         action: toggle
         entity: button.nexxtender_start_charge_max
         name: Start met laden
   - type: conditional
      conditions:
         - condition: state
         entity: sensor.nexxtender_charging_basic_status
         state: charging
      card:
         show_name: true
         show_icon: false
         type: button
         tap_action:
         action: toggle
         entity: button.nexxtender_start_charge_stop
         name: Stop met laden
   - type: conditional
      conditions:
         - condition: state
         entity: sensor.nexxtender_charging_basic_status
         state: unplugged
      card:
         type: markdown
         content: <center>Sluit de kabel aan om te kunnen starten met laden</center>

   ```

   </details>

## Contributing

Contributions to the ESPHome BLE client for Powerdale Nexxtender EV Charger are welcome! Whether you want to report a bug, request a feature, or contribute code, your input is valuable to the community. Please refer to the [Contribution Guidelines](CONTRIBUTING.md) for more information.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Support

For support, questions, or feedback, please open an issue on the [GitHub repository](https://github.com/geertmeersman/nexxtender/issues/new).
