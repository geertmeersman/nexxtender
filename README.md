# ESPHome BLE Client for Powerdale Nexxtender EV Charger

This repository contains an ESPHome BLE client for interfacing with the Powerdale Nexxtender EV Charger. The client allows you to seamlessly integrate the Nexxtender charger with your ESPHome projects, enabling you to monitor and control the charger remotely via Bluetooth Low Energy (BLE). Additionally, it integrates smoothly with Home Assistant, providing a convenient interface for managing your Nexxtender charger within your home automation setup.

## Features

- **BLE Connectivity:** Establish a BLE connection between your ESPHome device and the Powerdale Nexxtender EV Charger for data exchange and control.

- **Real-time Monitoring:** Retrieve real-time data from the Nexxtender charger, including charging status, voltage, current, and power consumption.

- **Remote Control:** Control the Nexxtender charger remotely from your ESPHome device, enabling features such as starting, stopping, and scheduling charging sessions.

- **Home Assistant Integration:** Seamlessly integrate the ESPHome BLE client with Home Assistant, allowing you to monitor and control the Nexxtender charger through the Home Assistant interface.

## Getting Started

To integrate the ESPHome BLE client with your Powerdale Nexxtender EV Charger and Home Assistant, follow these steps:

1. **Install ESPHome:** If you haven't already, install ESPHome by following the instructions [here](https://esphome.io/guides/getting_started_command_line.html#installation-step).

2. **Clone Repository:** Clone this repository to your local machine:

   ```bash
   git clone https://github.com/geertmeersman/nexxtender.git
   ```

3. **Copy Secrets Template:** Navigate to the `config` folder and copy the `secrets_template.yaml` file to `secrets.yaml`. Fill in the actual values for your Wi-Fi credentials, ESPHome API key, Nexxtender MAC address, and passkey.

4. **Compile Firmware:** Compile the ESPHome firmware with the configured Nexxtender client. Run the following command in the `nexxtender` directory:

   ```bash
   esphome nexxtender.yaml compile
   ```

5. **Flash Firmware:** Flash the compiled firmware to your ESPHome device using the following command:

   ```bash
   esphome nexxtender.yaml upload
   ```

6. **Integrate with Home Assistant:** In your Home Assistant configuration, add the ESPHome device as a new integration. Follow the instructions provided by Home Assistant to discover and integrate the Nexxtender charger with your Home Assistant setup.

7. **Monitor Logs:** Monitor the ESPHome device logs to ensure that the BLE client establishes a connection with the Powerdale Nexxtender EV Charger successfully.

8. **Test Functionality:** Test the functionality of the ESPHome BLE client by monitoring real-time data from the Nexxtender charger and controlling its operation remotely from your ESPHome device or through the Home Assistant interface.

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
