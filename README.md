# File Fortress

File Fortress is a simple web-based file management system designed for storing, retrieving, and managing files on a server. This project provides a user-friendly web interface for interacting with the server, including uploading, downloading, requesting, and deleting files. Additionally, it offers a directory page that allows users to view and search for files stored on the server.

![Home page](https://github.com/atharvdange618/Gateway-Device/assets/103875845/f9979e75-aee9-4c06-b835-54fa4ed840ab)

## Features

- **Upload Files**: Users can easily upload files to the server through the web interface.

- **Download Files**: Download files stored on the server to your local machine.

- **Request Files**: Submit requests for specific files from the server.

- **Delete Files**: Delete files from the server through the web interface.

- **View Directory**: View a list of available files in the directory, including search functionality.

- **User-Friendly Interface**: The project features a user-friendly, responsive design for easy navigation.

## Project Structure

- `main.ino`: This is the Arduino sketch file containing the server-side logic. It handles file storage, requests, and deletion. Make sure to upload this sketch to your ESP32 board.

- `index.html`: The project's home page, providing links to other sections of the application.

- `upload.html`: The upload page for adding files to the server.

- `download.html`: Page for downloading files from the server.

- `request.html`: Page to submit requests for specific files.

- `delete.html`: Page for deleting files from the server.

- `directory.html`: The directory page that displays and allows searching for available files.

## Setup and Usage

1. Clone this repository to your local machine or upload the HTML files to a web server.

2. Ensure you have an ESP32 board set up and connected to your network.

3. Upload the `main.ino` sketch to your ESP32 board using the Arduino IDE.

4. Open the web interface on a device connected to the same network as your board.

5. Use the provided links in the navigation bar to access different features, such as uploading, downloading, and managing files.

6. On the directory page, you can search for specific files by name to view and download them.

7. Ensure you're familiar with the features and functionalities mentioned above to efficiently manage your files.

## Dependencies

- [Arduino IDE](https://www.arduino.cc/en/software) for uploading the server-side code to your ESP8266 or ESP32 board.

## Contributing

Contributions to this project are welcome. You can fork the repository, make improvements, and create a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The project utilizes the Arduino platform for server-side functionality.
- The web interface incorporates HTML, CSS, and JavaScript for user interaction.

## Contact

For any questions or support, please contact [Atharv Dange](mailto:atharvdange.scoe.entc@gmail.com).

---

Happy file management with File Fortress!
