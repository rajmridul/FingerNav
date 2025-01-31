# FingerNav

## Overview

FingerNav is a Python-based virtual mouse that uses computer vision and AI to track hand gestures, enabling users to control their computer without a physical mouse. This innovative solution leverages OpenCV, MediaPipe, and PyAutoGUI for gesture recognition and interaction.

---

## Features

- **Hand Gesture Recognition**:
  - Control cursor movement using hand position.
  - Perform left-click, right-click, and double-click gestures.
  - Scroll horizontally and vertically with pinch gestures.
- **Brightness and Volume Control**:
  - Adjust system brightness and volume using pinch gestures.
- **Multi-Hand Support**:
  - Detects and distinguishes between left and right hands.
- **Customizable Gestures**:
  - Detects various gestures such as Fist, V-sign, Pinch, and more.

---

## How It Works

1. **Hand Detection**:
   The program uses MediaPipe to identify and track hand landmarks in real-time.

2. **Gesture Classification**:
   Custom algorithms classify gestures based on the relative position of hand landmarks.

3. **Action Mapping**:
   Recognized gestures are mapped to specific system actions, such as mouse clicks or scrolling.

4. **Fine Control**:
   Smooth cursor movements and fine-grained control of brightness and volume through pinch gestures.

---

## Prerequisites

- Python 3.7+
- Webcam

### Python Libraries

Install the required libraries using:

```bash
pip install -r requirements.txt
```

- OpenCV
- MediaPipe
- PyAutoGUI
- Pycaw
- Screen Brightness Control

---

## Usage

1. **Run the Application**:
   Start the program by running the `GestureController` class in the Python script.

   ```bash
   python fingernav.py
   ```

2. **Control Your System**:

   - Move your hand to control the cursor.
   - Use predefined gestures for specific actions.

3. **Exit**:
   Press the `Enter` key to close the application.

---

## Gesture Mappings

| Gesture            | Action                   |
| ------------------ | ------------------------ |
| V-Gesture          | Move Cursor              |
| Fist               | Drag (Hold Left Click)   |
| Index Finger       | Left Click               |
| Middle Finger      | Right Click              |
| Two Fingers Closed | Double Click             |
| Pinch Major        | Adjust Brightness/Volume |
| Pinch Minor        | Scroll                   |

---

## Implementation Details

### Gesture Recognition Classes

- **`Gest`**: Enumerates gestures like Fist, Index, Pinch, etc.
- **`HandRecog`**: Recognizes and classifies hand gestures based on landmark positions.

### Control Logic

- **`Controller`**: Maps gestures to system actions (e.g., mouse movement, scrolling).
- **`GestureController`**: Manages webcam input and integrates hand detection and gesture recognition.

---

## Future Improvements

- Add voice command integration.
- Enhance gesture recognition accuracy.
- Support additional system actions.

---

## Troubleshooting

- Ensure the webcam is functioning and positioned correctly.
- Adjust the environment for proper lighting to improve gesture recognition.
- If gestures are not recognized properly, ensure required libraries are installed and up to date.

---

## License

This project is open-source and available under the MIT License.

---

## Contributors

We welcome contributions! Feel free to submit issues or pull requests to enhance FingerNav.

