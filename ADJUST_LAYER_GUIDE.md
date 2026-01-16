# Adjust Layer Guide

## Overview

The adjust layer has been successfully integrated into your ZMK Sofle keymap! This layer provides advanced RGB controls and system settings that are automatically activated when you hold both LOWER and RAISE keys simultaneously.

## How to Access the Adjust Layer

**Hold LOWER + RAISE together** - The adjust layer will automatically activate while both keys are held down.

## Adjust Layer Layout

```
┌─────┬─────┬─────┬─────┬─────┬─────┐                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
│BTCLR│ BT1 │ BT2 │ BT3 │ BT4 │ BT5 │                    │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
│EXTPW│RGB_H│RGB_H│RGB_S│RGB_S│RGB_E│                    │     │     │     │     │     │     │
│ TOG │ DWN │ UP  │ DWN │ UP  │ FF  │                    │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤                    ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │RGB_B│RGB_B│     │     │     │                    │     │     │     │     │     │     │
│     │ DWN │ UP  │     │     │     │                    │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┐        ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │RGB_T│        │     │     │     │     │     │     │     │
│     │     │     │     │     │     │ OG  │        │     │     │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┼─────┼─────┤        ├─────┼─────┼─────┼─────┴─────┴─────┴─────┘
                  │     │     │     │     │        │     │     │     │     │
                  └─────┴─────┴─────┼─────┤        ├─────┼─────┴─────┴─────┘
                                    │     │        │     │
                                    └─────┘        └─────┘
```

## Key Functions

### Bluetooth Controls (Top Row)
- **BTCLR**: Clear all Bluetooth pairings
- **BT1-BT5**: Select Bluetooth profile 1-5

### RGB Controls (Left Side)
- **EXTPW TOG**: Toggle external power (for RGB)
- **RGB_H DWN/UP**: Decrease/Increase RGB hue
- **RGB_S DWN/UP**: Decrease/Increase RGB saturation
- **RGB_EFF**: Cycle through RGB effects
- **RGB_B DWN/UP**: Decrease/Increase RGB brightness
- **RGB_TOG**: Toggle RGB on/off (rotary encoder position)

## Usage Examples

### Change RGB Color
1. Hold LOWER + RAISE
2. Press RGB_H UP/DWN to adjust hue
3. Press RGB_S UP/DWN to adjust saturation
4. Release LOWER + RAISE

### Switch Bluetooth Device
1. Hold LOWER + RAISE
2. Press BT1, BT2, BT3, BT4, or BT5 to switch profiles
3. Release LOWER + RAISE

### Reset Bluetooth
1. Hold LOWER + RAISE
2. Press BTCLR to clear all pairings
3. Release LOWER + RAISE

## Technical Details

- **Layer Number**: 3
- **Activation**: Conditional layer (automatically activated when layers 1 and 2 are both active)
- **Implementation**: Uses ZMK's conditional_layers feature
- **Compatibility**: Fully compatible with your existing keymap

## Benefits

1. **No Key Conflicts**: Doesn't interfere with your existing LOWER and RAISE layers
2. **Automatic Activation**: No need to remember a specific key combination
3. **Advanced Controls**: Access to all RGB and system settings in one place
4. **Clean Organization**: Keeps advanced features separate from daily-use keys

## Next Steps

1. **Test the Layer**: Try holding LOWER + RAISE to access the adjust layer
2. **Customize RGB**: Experiment with different RGB effects and colors
3. **Set Up Bluetooth**: Configure your Bluetooth profiles for different devices

The adjust layer is now ready to use! Push your changes to trigger a GitHub Actions build and flash the new firmware to test it out.