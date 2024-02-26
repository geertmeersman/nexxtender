[![maintainer](https://img.shields.io/badge/maintainer-Geert%20Meersman-green?style=for-the-badge&logo=github)](https://github.com/geertmeersman)
[![buyme_coffee](https://img.shields.io/badge/Buy%20me%20a%20Duvel-donate-yellow?style=for-the-badge&logo=buymeacoffee)](https://www.buymeacoffee.com/geertmeersman)
[![discord](https://img.shields.io/discord/1094331679327408320?style=for-the-badge&logo=discord)](https://discord.gg/PTpExQJsWA)

[![MIT License](https://img.shields.io/github/license/geertmeersman/nexxtender?style=flat-square)](https://github.com/geertmeersman/nexxtender/blob/master/LICENSE)
[![github last-commit](https://img.shields.io/github/last-commit/geertmeersman/nexxtender)](https://github.com/geertmeersman/nexxtender/commits)
[![github contributors](https://img.shields.io/github/contributors/geertmeersman/nexxtender)](https://github.com/geertmeersman/nexxtender/graphs/contributors)
[![github commit activity](https://img.shields.io/github/commit-activity/y/geertmeersman/nexxtender?logo=github)](https://github.com/geertmeersman/nexxtender/commits/main)

---

# ESPHome BLE Client for Powerdale Nexxtender EV Charger

This repository contains an ESPHome BLE client for interfacing with the Powerdale Nexxtender EV Charger. The client allows you to seamlessly integrate the Nexxtender charger with your ESPHome projects, enabling you to monitor and control the charger remotely via Bluetooth Low Energy (BLE). Additionally, it integrates smoothly with Home Assistant, providing a convenient interface for managing your Nexxtender charger within your home automation setup.

---


## Features

- **BLE Connectivity:** Establish a BLE connection between your ESPHome device and the Powerdale Nexxtender EV Charger for data exchange and control.

- **Real-time Monitoring:** Retrieve real-time data from the Nexxtender charger, including charging status, voltage, current, and power consumption.

- **Remote Control:** Control the Nexxtender charger remotely from your ESPHome device, enabling features such as starting, stopping, and scheduling charging sessions.

- **Home Assistant Integration:** Seamlessly integrate the ESPHome BLE client with Home Assistant, allowing you to monitor and control the Nexxtender charger through the Home Assistant interface.

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

### Installing & configuring ESPHome

1. **Install ESPHome:** If you haven't already, install ESPHome by following the instructions [here](https://esphome.io/guides/getting_started_command_line.html#installation-step).

2. **Clone Repository:** Clone this repository to your local machine:

   ```bash
   git clone https://github.com/geertmeersman/nexxtender.git
   ```

3. **Copy Secrets Template:** Navigate to the `config` folder and copy the `secrets.yaml.template` file to `secrets.yaml`. Fill in the actual values for your Wi-Fi credentials, ESPHome API key, Nexxtender MAC address, and passkey.

4. **Copy Esp Example:** Navigate to the `config/nexxtender_packages` folder and copy the `esp.yaml.example` file to `esp.yaml`. Modify it with your ESP board specifications if needed.

5. **Compile Firmware:** Compile the ESPHome firmware with the configured Nexxtender client. Run the following command in the `nexxtender` directory:

   ```bash
   esphome compile nexxtender.yaml
   ```

6. **Flash Firmware:** Flash the compiled firmware to your ESPHome device using the following command:

   ```bash
   esphome upload nexxtender.yaml
   ```

7. **Integrate with Home Assistant:** In your Home Assistant configuration, add the ESPHome device as a new integration. Follow the instructions provided by Home Assistant to discover and integrate the Nexxtender charger with your Home Assistant setup.

8. **Monitor Logs:** Monitor the ESPHome device logs to ensure that the BLE client establishes a connection with the Powerdale Nexxtender EV Charger successfully.

9. **Test Functionality:** Test the functionality of the ESPHome BLE client by monitoring real-time data from the Nexxtender charger and controlling its operation remotely from your ESPHome device or through the Home Assistant interface.

For detailed documentation and examples, please refer to the [ESPHome BLE Client Documentation](https://github.com/geertmeersman/nexxtender/wiki).

## Integrating ESPHome Devices with Home Assistant

To integrate ESPHome devices with Home Assistant, follow these steps:

1. **Prerequisites**: Ensure you have the ESPHome integration enabled in Home Assistant. You can do this by navigating to Configuration -> Integrations, clicking the "+" button to add an integration, searching for "ESPHome," and following the instructions to set it up.

2. **Discover ESPHome Devices**: After enabling the integration, Home Assistant will automatically discover ESPHome devices on your network. If your devices don't show up automatically, you can add them manually by providing their IP address and API key.

3. **Configuration YAML**: You can also configure ESPHome devices manually by adding them to your Home Assistant configuration YAML file. This allows for more advanced configuration options and customization.

4. **View Devices**: Once your ESPHome devices are discovered or added manually, you can view and manage them in the Home Assistant UI. This includes monitoring their status, viewing sensor data, and controlling their actions.

5. **Integrate with Automations**: You can use ESPHome devices in your Home Assistant automations to trigger actions based on sensor readings, device status changes, or other events.

6. **Customization**: Home Assistant allows for extensive customization of ESPHome devices, including renaming, grouping, and organizing them to fit your home automation setup.

7. **Updates and Maintenance**: Keep your ESPHome devices up to date by regularly checking for firmware updates and configuring automatic OTA updates if desired.


## Contributing

Contributions to the ESPHome BLE client for Powerdale Nexxtender EV Charger are welcome! Whether you want to report a bug, request a feature, or contribute code, your input is valuable to the community. Please refer to the [Contribution Guidelines](CONTRIBUTING.md) for more information.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Support

For support, questions, or feedback, please open an issue on the [GitHub repository](https://github.com/geertmeersman/nexxtender).
