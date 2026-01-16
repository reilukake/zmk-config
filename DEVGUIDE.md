# ZMK Sofle Development Setup - Arch Linux

This guide covers the development setup for your ZMK Sofle keyboard firmware on your Arch Linux machine.

## ✅ Setup Complete

Your ZMK repository is now fully configured on your Arch machine with:

- ✅ Repository cloned from GitHub
- ✅ Git configured with your credentials
- ✅ SSH authentication configured for GitHub
- ✅ GitHub Actions workflow ready for automated builds
- ✅ Development helper script created

## 🚀 Quick Start

### Using the Development Helper Script

The `dev-helper.sh` script provides convenient commands for common tasks:

```bash
# Show repository status
./dev-helper.sh status

# Edit your keymap
./dev-helper.sh edit-keymap

# Edit hardware configuration
./dev-helper.sh edit-config

# Push changes and trigger build
./dev-helper.sh push

# Pull latest changes
./dev-helper.sh pull

# Create a backup branch
./dev-helper.sh backup

# Show help
./dev-helper.sh help
```

### Manual Git Workflow

```bash
# Make your changes to config files
nvim config/sofle.keymap

# Check what changed
git status
git diff

# Stage and commit changes
git add .
git commit -m "Update keymap: add new macro"

# Push to trigger GitHub Actions build
git push origin main
```

## 📁 Key Files to Edit

- **`config/sofle.keymap`** - Your key mappings and layers
- **`config/sofle.conf`** - Hardware configuration (RGB, OLED, etc.)
- **`build.yaml`** - Build matrix configuration

## 🔧 Development Workflow

1. **Edit Configuration**: Modify keymap or config files
2. **Test Locally**: Use the helper script or git commands
3. **Push Changes**: Commit and push to trigger GitHub Actions
4. **Download Firmware**: Get compiled firmware from Actions tab
5. **Flash Keyboard**: Use the downloaded .uf2 files

## 🌐 GitHub Actions Build

Your repository uses GitHub Actions for automated firmware compilation:

- **Trigger**: Automatic on push/pull request
- **Build Time**: ~5-10 minutes
- **Output**: Downloadable .uf2 firmware files
- **Monitor**: https://github.com/solotitan/zmk-sofle-wireless-config/actions

### Build Artifacts

After a successful build, download these files:
- `sofle_left-nice_nano_v2-zmk.uf2` - Left half firmware
- `sofle_right-nice_nano_v2-zmk.uf2` - Right half firmware
- `settings_reset-nice_nano_v2-zmk.uf2` - Settings reset firmware

## 🔄 Flashing Process

1. Put keyboard half in bootloader mode (double-tap reset)
2. Copy appropriate .uf2 file to the mounted drive
3. Keyboard will automatically reboot with new firmware
4. Repeat for other half if needed

## 🛠️ Troubleshooting

### Build Failures
- Check GitHub Actions logs for specific errors
- Verify keymap syntax in config/sofle.keymap
- Ensure all required files are present

### Git Issues
```bash
# Reset to last working state
git reset --hard HEAD

# Pull latest changes
git pull origin main

# Check remote connection
git remote -v
```

### Keymap Problems
- Refer to `docs/keymap-reference.md` for layer documentation
- Check ZMK documentation: https://zmk.dev/docs
- Validate keymap syntax before pushing

## 📚 Resources

- **ZMK Documentation**: https://zmk.dev/docs
- **Keymap Reference**: docs/keymap-reference.md
- **GitHub Actions**: https://github.com/solotitan/zmk-sofle-wireless-config/actions
- **Sofle Build Guide**: https://josefadamcik.github.io/SofleKeyboard/

## 🎯 Next Steps

1. **Test the workflow**: Make a small change and push it
2. **Customize your keymap**: Edit `config/sofle.keymap` to your preferences
3. **Explore features**: Try RGB effects, macros, or layer modifications
4. **Create backups**: Use `./dev-helper.sh backup` before major changes

---

**Happy coding! Your ZMK development environment is ready to go! ⌨️**
