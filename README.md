Color Palette Bot for Discord Using C++

Overview:
This project showcases a unique Discord bot built using C++ that generates color palettes. Leveraging the power of the DPP Discord API and the OpenCV library, the bot brings a creative and interactive experience to Discord servers. Hosted locally using WSL (Windows Subsystem for Linux), it combines the functionality of Discord interactions with the visual flair of color theory.

Key Features:
    Interactive Discord Commands: Users can interact with the bot using slash commands, such as /ping for a quick response, /name for user recognition, and the main feature, !create, to generate a new color palette.
    Color Palette Generation: The bot employs a simple yet effective algorithm to create color palettes. It starts with a random base color, then calculates its complementary color by inverting the RGB values. Added              randomness ensures a unique palette every time, although future iterations could refine this process for more aesthetic combinations.
    Local Hosting: The bot runs on a local machine using WSL, offering a hands-on approach to bot deployment and management.

Technologies Used:
    DPP (Discord++): A C++ library for creating high-performance Discord bots (https://dpp.dev/).
    OpenCV: Used for backend processing, particularly in the color palette generation algorithm (installable via apt on WSL).
    WSL (Windows Subsystem for Linux): Enables running the bot in a Linux-like environment on Windows.

Getting Started:
    Prerequisites: Install both DPP and OpenCV.
    Environment Setup: This project is configured for WSL Linux. Ensure all dependencies are accessible and that you have Make installed with a MinGW compiler.
    Discord Bot API Key: Replace the placeholder in the code with your actual Discord bot API key/token, as provided by Discord (refer to the DPP website for a guide on bot connection).
    Running the Bot: Use slash commands like /ping for a simple interaction, /name for user identification, and !create to generate a color palette.

Current Limitations and Future Scope:
    The bot is not hosted online; it operates locally on the user's machine.
    The color generation algorithm, while functional, could be enhanced for more aesthetically pleasing results.

Project Status:
This bot represents the initial version, effectively combining basic Discord bot functionalities with a simple color theory application. Future updates may include algorithm improvements for better color selection and potential deployment solutions for continuous online presence.
