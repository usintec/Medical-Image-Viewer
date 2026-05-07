# Medical Image Viewer

A modern medical image viewing application built with C++ and OpenGL. This application provides a GPU-accelerated viewer for medical imaging data, with support for real-time image manipulation and visualization.

## Features

- **GPU-Accelerated Rendering**: Utilizes OpenGL for efficient image rendering
- **Shader-Based Processing**: Implement custom image processing via GLSL shaders
- **Grayscale Medical Images**: Optimized for displaying medical scan data (CT, MRI, X-ray)
- **Intensity Mapping**: Automatic intensity normalization for medical imaging
- **Cross-Platform**: Built with cross-platform graphics APIs (OpenGL 3.3+)

## Requirements

### System Requirements
- Windows 7 or later (Microsoft Visual C++ 2019 or later)
- GPU with OpenGL 3.3+ support
- Minimum 1GB RAM

### Build Requirements
- Visual Studio 2019 or later
- CMake 3.10 or later (optional, for advanced builds)

## Dependencies

The project uses the following external libraries:

- **GLAD** - OpenGL loader library
- **GLFW3** - Window management and input handling
- **STB Image** - Image loading library

All dependencies are expected to be installed in your system's include paths or linked appropriately during CMake configuration.

## Project Structure

```
Medical Image Viewer/
├── Medical Image Viewer.sln                 # Visual Studio solution file
├── Medical Image Viewer.vcxproj             # Visual Studio project file
├── Medical Image Viewer.vcxproj.filters     # Project filter definitions
├── Medical Image Viewer.vcxproj.user        # User-specific project settings
├── README.md                                # This file
├── src/
│   ├── main.cpp                             # Application entry point
│   ├── Shader.cpp                           # Shader loading and compilation
│   ├── Texture.cpp                          # Texture loading and binding
│   ├── Quad.cpp                             # Quad geometry rendering
│   ├── Headers/
│   │   ├── Shader.h                         # Shader class definition
│   │   ├── Texture.h                        # Texture class definition
│   │   └── Quad.h                           # Quad class definition
│   ├── shaders/
│   │   ├── image.vert                       # Vertex shader
│   │   └── image.frag                       # Fragment shader
│   └── assets/
│       └── brain_slice.png                  # Sample medical image (brain CT/MRI scan)
└── x64/Release/
    └── Medical Image Viewer.exe             # Compiled executable
```

## Building the Project

### Visual Studio (Recommended)

1. **Open the Solution**
   ```
   Open Medical Image Viewer.sln in Visual Studio
   ```

2. **Configure Dependencies**
   - Ensure GLAD, GLFW3, and STB Image are properly linked
   - Update include directories if necessary in project properties

3. **Build the Project**
   - Select `Release` configuration for optimized build
   - Press `Ctrl+Shift+B` or select Build → Build Solution
   - The executable will be generated in `x64/Release/`

4. **Run the Application**
   - Press `Ctrl+F5` to run with debugging
   - Or execute `x64/Release/Medical Image Viewer.exe` directly

## Usage

1. **Launch the Application**
   ```
   Medical Image Viewer.exe
   ```

2. **View Medical Images**
   - A window will open displaying the medical image viewer
   - The default sample image (`brain_slice.png`) will be loaded
   - Images are rendered with intensity mapping for optimal contrast

3. **Customization**
   - Replace `src/assets/brain_slice.png` with your own medical image
   - Modify shader files (`image.vert`, `image.frag`) to adjust rendering
   - Adjust window size in `main.cpp` (default: 800x600)

## Code Overview

### Main Components

#### Shader Class
- **File**: `src/Shader.cpp`, `src/Headers/Shader.h`
- **Purpose**: Loads, compiles, and manages GLSL shaders
- **Key Methods**:
  - `Shader(vertexPath, fragmentPath)` - Constructor loads and compiles shaders
  - `use()` - Activates the shader program
  - `setInt()` - Sets integer uniform variables
  - `setFloat()` - Sets float uniform variables

#### Texture Class
- **File**: `src/Texture.cpp`, `src/Headers/Texture.h`
- **Purpose**: Loads and manages texture data for GPU rendering
- **Key Methods**:
  - `Texture(path)` - Constructor loads image from file
  - `bind()` - Binds texture to active texture unit

#### Quad Class
- **File**: `src/Quad.cpp`, `src/Headers/Quad.h`
- **Purpose**: Manages 2D quad geometry for rendering
- **Key Methods**:
  - `Quad()` - Constructor initializes vertex arrays
  - `draw()` - Renders the quad to screen

### Shader Programs

#### Vertex Shader (`image.vert`)
- Input: 2D positions and texture coordinates
- Output: Transformed positions and texture coordinates to fragment shader

#### Fragment Shader (`image.frag`)
- Input: Texture coordinates from vertex shader
- Output: Pixel color with intensity mapping
- Features: Grayscale intensity extraction from red channel

## Extending the Viewer

### Adding Image Processing Effects
Modify `src/shaders/image.frag` to add custom effects:

```glsl
// Example: Increase contrast
float intensity = texture(u_image, TexCoord).r;
intensity = pow(intensity, 0.5);  // Adjust gamma
FragColor = vec4(vec3(intensity), 1.0);
```

### Loading Different Images
Update the image path in `src/main.cpp`:
```cpp
Texture image("path/to/your/medical/image.png");
```

### Window Configuration
Modify window size and title in `src/main.cpp`:
```cpp
GLFWwindow *window = glfwCreateWindow(width, height, "Your Title", NULL, NULL);
```

## Performance Considerations

- **GPU Rendering**: All image processing happens on the GPU for optimal performance
- **Texture Caching**: Textures remain bound in GPU memory during rendering
- **Shader Compilation**: Shaders are compiled at startup; consider caching for production

## Troubleshooting

### Application Crashes on Startup
- Ensure `src/assets/brain_slice.png` exists
- Verify shader files are in `src/shaders/` directory
- Check that all dependencies (GLAD, GLFW3) are properly linked

### Black Screen Rendering
- Verify shader compilation succeeded (check console output)
- Ensure texture loaded correctly
- Check OpenGL error messages in console

### Image Not Displaying
- Confirm image file format is PNG (JPG support may need additional configuration)
- Check image path relative to executable location
- Verify texture coordinates in quad geometry

## License

[Add your license information here]

## Contributing

Contributions are welcome! Please follow these guidelines:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request with detailed description

## Contact & Support

For issues, questions, or suggestions, please open an issue in the repository.

---

**Status**: Active Development  
**Last Updated**: May 2026  
**Version**: 1.0.0
